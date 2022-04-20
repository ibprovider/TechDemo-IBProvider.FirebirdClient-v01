////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME->dbtimestamp implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime,dbtimestamp)::internal__convert_value_to_dbtimestamp
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //---------
 DBTIMESTAMP x;

 x.year     =__zero_dbdate__.year;
 x.month    =__zero_dbdate__.month;
 x.day      =__zero_dbdate__.day;

 x.hour     =dbvar.dbtimeVal.hour;
 x.minute   =dbvar.dbtimeVal.minute;
 x.second   =dbvar.dbtimeVal.second;

 x.fraction =0;

 //---------
 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtimestamp

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime,dbtimestamp)

////////////////////////////////////////////////////////////////////////////////
