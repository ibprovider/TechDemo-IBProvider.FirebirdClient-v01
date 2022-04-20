////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIMESTAMP->dbtimestamp implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtimestamp,dbtimestamp)::internal__convert_value_to_dbtimestamp
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIMESTAMP);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=dbvar.dbstampVal;

 return S_OK;
}//internal__convert_value_to_dbtimestamp

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtimestamp,dbtimestamp)

////////////////////////////////////////////////////////////////////////////////
