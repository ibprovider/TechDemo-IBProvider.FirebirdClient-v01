////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DATE->dbtime2 implementation.
//                                                Kovalenko Dmitry. 08.09.2010.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(date,dbtime2)::internal__convert_value_to_dbtime2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!date_to_dbtime2(dbvar.dateVal,&result->set_not_null().value()))
  return DB_E_CANTCONVERTVALUE;

 return S_OK;
}//internal__convert_value_to_dbtime2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(date,dbtime2)

////////////////////////////////////////////////////////////////////////////////
