////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY|TYPE->ARRAY|BYTES
//                                                 Kovalenko Dmitry. 30.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_common,array_bytes)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wFromType)==DBTYPE_ARRAY);
 assert(m_wToType==(DBTYPE_ARRAY|DBTYPE_BYTES));
 assert(dbvar.wType==m_wFromType);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=NULL;

 if(dbvar.arrayVal2.ptr==NULL)
  return S_OK;

 //----------------------
 DBTYPE
  const SourceElementType=DBTYPE(dbvar.wType&DBTYPE(~DBTYPE_ARRAY));

 if(SourceElementType==DBTYPE_EMPTY || SourceElementType==DBTYPE_NULL)
  return DB_E_CANTCONVERTVALUE;

 DBVARIANT::LPCTYPEINFO
  const lpSourceElementTypeInfo=DBVARIANT::GetInfo(SourceElementType);

 if(lpSourceElementTypeInfo==NULL)
  return DB_E_CANTCONVERTVALUE;

 assert(lpSourceElementTypeInfo->pTypeService!=NULL);

 if(lpSourceElementTypeInfo->pTypeService==NULL)
  return E_FAIL;

 //---------
 const UINT SourceElementSize=::SafeArrayGetElemsize(dbvar.arrayVal2.ptr);

 if((SourceElementSize==0) ||
    (lpSourceElementTypeInfo->FixedLen() && SourceElementSize!=lpSourceElementTypeInfo->Size))
 {
  return E_FAIL;
 }

 //----------------------
 typedef structure::t_stl_vector <SAFEARRAYBOUND,TOLEDBMemoryAllocator> sa_bounds_type;

 const UINT cDim=::SafeArrayGetDim(dbvar.arrayVal2.ptr);

 size_t n=cDim?1:0;

 sa_bounds_type bound_vector;

 bound_vector.reserve(cDim);

 for(UINT x=0;x!=cDim;++x)
 {
  n*=dbvar.arrayVal2.ptr->rgsabound[cDim-x-1].cElements;

  bound_vector.push_back(dbvar.arrayVal2.ptr->rgsabound[cDim-x-1]);
 }//if

 //----------------------
 ole_lib::TSafeArrayAccessor source_accessor(dbvar.arrayVal2.ptr,false);

 if(!source_accessor)
  return E_FAIL;

 //---------
 const char* pSourceData=reinterpret_cast<const char*>(source_accessor.Data());

 //--------- Copy target strings into temporary list
 typedef structure::t_stl_vector<size_t,TOLEDBMemoryAllocator> size_vec_type;

 DBVARIANT UnpackSourceElement;

 TDBVariantBytesWriter bytes;
 size_vec_type         bytes_sizes;
 size_t                bytes_max_size=1;

 bytes_sizes.reserve(n);

 for(size_t x=0;x!=n;++x)
 {
  if(pSourceData==NULL)
   return E_FAIL;

  if(lpSourceElementTypeInfo->pTypeService->get_element(&UnpackSourceElement,
                                                        dbvar.arrayVal2.element_iid,
                                                        SourceElementSize,
                                                        pSourceData)!=S_OK)
  {
   return E_FAIL;
  }

  const size_t cur_byte_count=bytes.m_buffer.size();

  const HRESULT cvt_hr=DBVariant__to_BYTES_ex(pConvCtx,UnpackSourceElement,&bytes);

  if(FAILED(cvt_hr))
   return cvt_hr;

  if(cvt_hr==S_FALSE) //element cantains NULL
   return DB_E_CANTCONVERTVALUE;

  assert(cvt_hr==S_OK);

  bytes_sizes.push_back(bytes.m_buffer.size()-cur_byte_count);

  bytes_max_size=max(bytes_max_size,bytes_sizes.back());

  pSourceData+=SourceElementSize;
 }//for x

 //------------ Create target SAFEARRAY
 ole_lib::TBaseSafeArray sa;

 const HRESULT create_sa_hr=oledb_lib::DBVariant_CreateArray
                                        (DBTYPE_BYTES,
                                         bytes_max_size,
                                         cDim,
                                         bound_vector.data(),
                                         &sa.ref_sa());

 if(FAILED(create_sa_hr))
  return E_FAIL;

 if(sa.sa()==NULL)
  return E_FAIL;

 const UINT TargetElementSize=::SafeArrayGetElemsize(sa);

 assert(bytes_max_size<=TargetElementSize);

 //---------
 ole_lib::TSafeArrayAccessor dest_accessor(sa,false);

 if(!dest_accessor)
  return E_FAIL;

 //---------
 char* pTargetData=reinterpret_cast<char*>(dest_accessor.Data());

 //------------ Install bytes
 {
  const auto* seg=bytes.m_buffer.head();

  size_t seg_cb=0;

  for(size_t x=0;x!=n;++x)
  {
   if(pTargetData==NULL)
    return E_FAIL;

   char*       i_byte=pTargetData;
   char* const e_byte=pTargetData+bytes_sizes[x];

   while(i_byte!=e_byte)
   {
    assert(i_byte<e_byte);

    assert(seg);
    assert(seg->size!=0);
    assert(seg->used<=seg->size);
    assert(seg_cb<=seg->used);

    if(seg_cb==seg->used)
    {
     seg_cb=0;

     seg=seg->next;

     continue;
    }//if

    size_t const cb=min(size_t(e_byte-i_byte),size_t(seg->used-seg_cb));

    memcpy(i_byte,seg->data(),cb);

    i_byte+=cb;
    seg_cb+=cb;
   }//while i_byte!=e_byte

   std::fill(e_byte,pTargetData+TargetElementSize,structure::zero);

   pTargetData+=TargetElementSize;
  }//for x

  assert(seg==NULL || (seg_cb==seg->used && seg->next==NULL));
 }//local

 (*result)=sa.Release();

 return S_OK;
}//internal__convert_value_to_array

////////////////////////////////////////////////////////////////////////////////
