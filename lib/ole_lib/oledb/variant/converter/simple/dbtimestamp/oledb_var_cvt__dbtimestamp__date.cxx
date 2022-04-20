////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIMESTAMP->date implementation.
//                                                     Roman Piminov, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtimestamp,date)::internal__convert_value_to_date
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIMESTAMP);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!dbstamp_to_date(dbvar.dbstampVal,result->set_not_null().value()))
  return DB_E_CANTCONVERTVALUE;

 return S_OK;
}//internal__convert_value_to_date

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtimestamp,date)

////////////////////////////////////////////////////////////////////////////////
