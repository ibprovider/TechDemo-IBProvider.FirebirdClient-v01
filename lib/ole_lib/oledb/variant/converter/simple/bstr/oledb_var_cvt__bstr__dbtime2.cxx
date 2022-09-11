////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->dbtime2 implementation.
//                                                 Kovalenko Dmitry. 09.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,dbtime2)::internal__convert_value_to_dbtime2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 t_oledb_value__DBTIME2 x;

 const size_t bstrLen=dbvar.bstrVal?LCPI_OS__SysStringLen(dbvar.bstrVal):0;

 if(!oledb_lib::str_to_dbtime2(&x,dbvar.bstrVal,bstrLen))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtime2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,dbtime2)

////////////////////////////////////////////////////////////////////////////////
