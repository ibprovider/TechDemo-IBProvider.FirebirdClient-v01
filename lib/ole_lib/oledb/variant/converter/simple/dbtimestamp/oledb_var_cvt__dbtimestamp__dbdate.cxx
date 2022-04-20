////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIMESTAMP->dbdate implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtimestamp,dbdate)::internal__convert_value_to_dbdate
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIMESTAMP);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBDATE x;

 x.year  =dbvar.dbstampVal.year;
 x.month =dbvar.dbstampVal.month;
 x.day   =dbvar.dbstampVal.day;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbdate

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtimestamp,dbdate)

////////////////////////////////////////////////////////////////////////////////
