////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DATE->dbtime implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(date,dbtime)::internal__convert_value_to_dbtime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!date_to_dbtime(dbvar.dateVal,result->set_not_null().value()))
  return DB_E_CANTCONVERTVALUE;

 return S_OK;
}//internal__convert_value_to_dbtime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(date,dbtime)

////////////////////////////////////////////////////////////////////////////////
