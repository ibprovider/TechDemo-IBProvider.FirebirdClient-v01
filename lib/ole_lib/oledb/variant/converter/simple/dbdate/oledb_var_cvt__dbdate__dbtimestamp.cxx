////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBDATE->dbtimestamp implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbdate,dbtimestamp)::internal__convert_value_to_dbtimestamp
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBDATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //--------
 DBTIMESTAMP x=__null_dbtimestamp__;

 x.year  =dbvar.dbdateVal.year;
 x.month =dbvar.dbdateVal.month;
 x.day   =dbvar.dbdateVal.day;

 //--------
 (*result)=x;

 //--------
 return S_OK;
}//internal__convert_value_to_dbtimestamp

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbdate,dbtimestamp)

////////////////////////////////////////////////////////////////////////////////
