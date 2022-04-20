////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY|TYPE->ARRAY|EQUAL_TYPE
//                                                 Kovalenko Dmitry. 27.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_common,array_copy)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wFromType)==DBTYPE_ARRAY);
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wToType)==DBTYPE_ARRAY);
 assert(m_wFromType==m_wToType);
 assert(dbvar.wType==m_wFromType);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=NULL;

 if(dbvar.arrayVal2.ptr==NULL)
  return S_OK;

 SAFEARRAY* sa_tmp=NULL;

 if(FAILED(ole_lib::SafeArray_Copy(dbvar.arrayVal2.ptr,&sa_tmp)))
  return E_FAIL;

 if(sa_tmp==NULL)
  return E_FAIL;

 (*result)=sa_tmp;

 return S_OK;
}//internal__convert_value_to_array

////////////////////////////////////////////////////////////////////////////////
