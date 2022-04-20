////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY|TYPE->ARRAY|WSTR
//                                                 Kovalenko Dmitry. 30.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_common,array_wstr)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wFromType)==DBTYPE_ARRAY);
 assert(m_wToType==(DBTYPE_ARRAY|DBTYPE_WSTR));
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
 typedef structure::t_stl_vector<SAFEARRAYBOUND,TOLEDBMemoryAllocator> sa_bounds_type;

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
 typedef DBVARIANT::value_cpp_wstr_n_type                           string_n_type;
 typedef string_n_type::value_type                                  string_type;
 typedef structure::t_stl_vector<string_type,TOLEDBMemoryAllocator> string_vec_type;

 DBVARIANT UnpackSourceElement;

 string_n_type   tmp_str;
 string_vec_type str_elements;

 string_type::size_type str_max_size=1;

 str_elements.reserve(n);

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

  tmp_str.reset();

  const HRESULT cvt_hr=DBVariant__to_WSTR_ex(pConvCtx,UnpackSourceElement,&tmp_str);

  if(FAILED(cvt_hr))
   return cvt_hr;

  assert(cvt_hr==S_OK);

  if(tmp_str.null())
   return DB_E_CANTCONVERTVALUE;

  if(str_max_size<tmp_str.value().length())
   str_max_size=tmp_str.value().length();

  str_elements.push_back(__STL_MOVE_VALUE(tmp_str.value()));

  pSourceData+=SourceElementSize;
 }//for x

 assert(str_elements.size()==n);

 //------------ Create target SAFEARRAY
 ole_lib::TBaseSafeArray sa;

 const HRESULT create_sa_hr=oledb_lib::DBVariant_CreateArray
                                        (DBTYPE_WSTR,
                                         str_max_size,
                                         cDim,
                                         bound_vector.data(),
                                         &sa.ref_sa());

 if(FAILED(create_sa_hr))
  return E_FAIL;

 if(sa.sa()==NULL)
  return E_FAIL;

 const UINT TargetElementSize=::SafeArrayGetElemsize(sa);

 assert(str_max_size*sizeof(string_type::value_type)<=TargetElementSize);

 //---------
 ole_lib::TSafeArrayAccessor dest_accessor(sa,false);

 if(!dest_accessor)
  return E_FAIL;

 //---------
 char* pTargetData=reinterpret_cast<char*>(dest_accessor.Data());

 //------------ Install created strings
 for(size_t x=0;x!=n;++x)
 {
  if(pTargetData==NULL)
   return E_FAIL;

  const size_t cb_string=sizeof(*str_elements[x].c_str())*str_elements[x].size();

  assert(str_elements[x].size()<=str_max_size);
  assert(cb_string<=TargetElementSize);

  memcpy(pTargetData,str_elements[x].c_str(),cb_string);

  std::fill(pTargetData+cb_string,pTargetData+TargetElementSize,structure::zero);

  pTargetData+=TargetElementSize;
 }//for x

 (*result)=sa.Release();

 return S_OK;
}//internal__convert_value_to_array

////////////////////////////////////////////////////////////////////////////////
