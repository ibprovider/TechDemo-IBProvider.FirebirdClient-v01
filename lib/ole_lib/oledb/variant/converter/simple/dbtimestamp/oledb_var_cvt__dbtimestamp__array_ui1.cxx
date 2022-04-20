////////////////////////////////////////////////////////////////////////////////
//OLEDB Type converter: DBTIMESTAMP to ARRAY_UI1
//                                                Kovalenko Dmitry. 20.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtimestamp,array_ui1)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIMESTAMP);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::BytesToArrayUI1(&dbvar.dbstampVal,
                                             sizeof(dbvar.dbstampVal),
                                             result);
}//internal__convert_value_to_array

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtimestamp,array_ui1)

////////////////////////////////////////////////////////////////////////////////
