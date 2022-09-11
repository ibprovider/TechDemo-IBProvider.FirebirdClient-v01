////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->dbtime implementation.
//                                                 Kovalenko Dmitry. 06.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,dbtime)::internal__convert_value_to_dbtime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBTIME x;

 const size_t bstrLen=dbvar.bstrVal?LCPI_OS__SysStringLen(dbvar.bstrVal):0;

 if(!oledb_lib::str_to_dbtime(&x,dbvar.bstrVal,bstrLen))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,dbtime)

////////////////////////////////////////////////////////////////////////////////
