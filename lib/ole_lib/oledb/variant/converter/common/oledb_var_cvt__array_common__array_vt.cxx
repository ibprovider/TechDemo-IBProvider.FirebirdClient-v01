////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY|TYPE->ARRAY|VAR_TYPE
//                                                 Kovalenko Dmitry. 28.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_common,array_vt)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             REFIID               result_iid,
                                             result_type*   const result)const
{
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wFromType)==DBTYPE_ARRAY);
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wToType)==DBTYPE_ARRAY);
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
 const UINT SourceElementSize=LCPI_OS__SafeArrayGetElemsize(dbvar.arrayVal2.ptr);

 if((SourceElementSize==0) ||
    (lpSourceElementTypeInfo->FixedLen() && SourceElementSize!=lpSourceElementTypeInfo->Size))
 {
  return E_FAIL;
 }

 //----------------------
 DBTYPE
  const TargetElementType=DBTYPE(m_wToType&DBTYPE(~DBTYPE_ARRAY));

 assert(TargetElementType!=DBTYPE_EMPTY && TargetElementType!=DBTYPE_NULL);

 DBVARIANT::LPCTYPEINFO
  const lpTargetElementTypeInfo=DBVARIANT::GetInfo(TargetElementType);

 assert(lpTargetElementTypeInfo!=NULL);
 assert(lpTargetElementTypeInfo->pTypeService!=NULL);

 //----------------------
 size_t TargetElementSize=lpTargetElementTypeInfo->Size;

 if(SourceElementType==DBTYPE_BYTES && TargetElementType==DBTYPE_STR)
  TargetElementSize=SourceElementSize/sizeof(char);
 else
 if(SourceElementType==DBTYPE_BYTES && TargetElementType==DBTYPE_WSTR)
  TargetElementSize=SourceElementSize/sizeof(wchar_t);
 else
 if(TargetElementType==DBTYPE_STR || TargetElementType==DBTYPE_WSTR)
  TargetElementSize=lpSourceElementTypeInfo->StringPresentation;
 else
 if(TargetElementType==DBTYPE_BYTES)
  TargetElementSize=SourceElementSize;

 if(TargetElementSize==0)
  return DB_E_CANTCONVERTVALUE;

 //----------------------
 typedef structure::t_stl_vector<SAFEARRAYBOUND,TOLEDBMemoryAllocator> sa_bounds_type;

 ole_lib::TBaseSafeArray sa;

 const UINT cDim=LCPI_OS__SafeArrayGetDim(dbvar.arrayVal2.ptr);

 size_t n=cDim?1:0;

 sa_bounds_type bound_vector;

 bound_vector.reserve(cDim);

 for(UINT x=0;x!=cDim;++x)
 {
  n*=dbvar.arrayVal2.ptr->rgsabound[cDim-x-1].cElements;

  bound_vector.push_back(dbvar.arrayVal2.ptr->rgsabound[cDim-x-1]);
 }//if

 const HRESULT create_sa_hr
  =oledb_lib::DBVariant_CreateArray
    (TargetElementType,
     TargetElementSize,
     cDim,
     bound_vector.data(),
     &sa.ref_sa());

 if(FAILED(create_sa_hr))
  return E_FAIL;

 if(sa.sa()==NULL)
  return E_FAIL;

 TargetElementSize=LCPI_OS__SafeArrayGetElemsize(sa);

 //---------
 ole_lib::TSafeArrayAccessor dest_accessor(sa,false);

 if(!dest_accessor)
  return E_FAIL;

 ole_lib::TSafeArrayAccessor source_accessor(dbvar.arrayVal2.ptr,false);

 if(!source_accessor)
  return E_FAIL;

 //---------
 const char* pSourceData=reinterpret_cast<const char*>(source_accessor.Data());

 char*       pTargetData=reinterpret_cast<char*>(dest_accessor.Data());

 //---------
 DBVARIANT UnpackSourceElement;
 DBSTATUS  BindingStatus=DBSTATUS_S_OK;
 HRESULT   set_hr;

 for(;n!=0;--n)
 {
  if(pSourceData==NULL || pTargetData==NULL)
   return E_FAIL;

  if(lpSourceElementTypeInfo->pTypeService->get_element(&UnpackSourceElement,
                                                        dbvar.arrayVal2.element_iid,
                                                        SourceElementSize,
                                                        pSourceData)!=S_OK)
  {
   return E_FAIL;
  }

  //-----
  assert(BindingStatus==DBSTATUS_S_OK);

  set_hr=lpTargetElementTypeInfo->pTypeService->set_element(pConvCtx,
                                                            UnpackSourceElement,
                                                            result_iid,
                                                            TargetElementSize,
                                                            pTargetData,
                                                            &BindingStatus);
  if(FAILED(set_hr))
   return set_hr;

  if(set_hr!=S_OK)
   return DB_E_CANTCONVERTVALUE;

  if(BindingStatus!=DBSTATUS_S_OK/* && BindingStatus!=DBSTATUS_S_ISNULL*/)
   return DB_E_CANTCONVERTVALUE;

  pTargetData+=lpTargetElementTypeInfo->Size;
  pSourceData+=SourceElementSize;
 }//for n

 (*result)=sa.Release();

 return S_OK;
}//internal__convert_value_to_array

//------------------------------------------------------------------------
bool OLEDB_TYPE_CONVERTER_NAME(array_common,array_vt)::CanConvertTo
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBBINDING&     Bind)const
{
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wFromType)==DBTYPE_ARRAY);
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wToType)==DBTYPE_ARRAY);

 assert(OLEDB_EXTRACT_DBTYPE(Bind.wType)==m_wToType);

 const DBTYPE wElementFromType=DBTYPE(m_wFromType&~DBTYPE_ARRAY);
 const DBTYPE wElementToType  =DBTYPE(m_wToType&~DBTYPE_ARRAY);

 const DBVARIANT::LPCTYPECONVERTER
  pElementCvt=pConvCtx->GetTypeConverter(wElementFromType,wElementToType);

 if(pElementCvt==NULL)
  return false;

 const DBVARIANT::LPCTYPECONVERTER_DBBINDING_TEST
  pElementCvtBindingTest=dynamic_cast<DBVARIANT::LPCTYPECONVERTER_DBBINDING_TEST>(pElementCvt);

 if(pElementCvtBindingTest==NULL)
  return true;

 DBBINDING ElementBind={};

 ElementBind.wType   =wElementToType;
 ElementBind.pObject =Bind.pObject;

 return pElementCvtBindingTest->CanConvertTo(pConvCtx,ElementBind);
}//CanConvertTo

////////////////////////////////////////////////////////////////////////////////
