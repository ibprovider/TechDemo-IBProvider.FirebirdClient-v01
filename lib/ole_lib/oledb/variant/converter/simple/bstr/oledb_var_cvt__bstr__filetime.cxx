////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->filetime implementation.
//                                                 Kovalenko Dmitry. 06.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,filetime)::internal__convert_value_to_filetime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 FILETIME x;

 const size_t bstrLen=dbvar.bstrVal?LCPI_OS__SysStringLen(dbvar.bstrVal):0;

 if(!oledb_lib::str_to_filetime(&x,dbvar.bstrVal,bstrLen))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_filetime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,filetime)

////////////////////////////////////////////////////////////////////////////////
