////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME2->dbtimestamp implementation.
//                                                 Kovalenko Dmitry. 09.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime2,dbtimestamp)::internal__convert_value_to_dbtimestamp
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==oledb_lib::oledb_typeid__DBTIME2);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //---------
 DBTIMESTAMP x;

 x.year     =__zero_dbdate__.year;
 x.month    =__zero_dbdate__.month;
 x.day      =__zero_dbdate__.day;

 x.hour     =dbvar.dbtime2Val.hour;
 x.minute   =dbvar.dbtime2Val.minute;
 x.second   =dbvar.dbtime2Val.second;
 x.fraction =dbvar.dbtime2Val.fraction;

 //---------
 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtimestamp

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime2,dbtimestamp)

////////////////////////////////////////////////////////////////////////////////
