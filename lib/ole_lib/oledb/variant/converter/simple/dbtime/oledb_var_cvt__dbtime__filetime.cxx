////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME->filetime implementation.
//                                                     Roman Piminov, 24.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime,filetime)::internal__convert_value_to_filetime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //---------
 if(dbvar.dbtimeVal.hour>23)
  return DB_E_CANTCONVERTVALUE;

 if(dbvar.dbtimeVal.minute>59)
  return DB_E_CANTCONVERTVALUE;

 if(dbvar.dbtimeVal.second>59)
  return DB_E_CANTCONVERTVALUE;

 //---------
 SYSTEMTIME sys_time;

 if(!dbtime_to_systime(dbvar.dbtimeVal,&sys_time))
  return DB_E_CANTCONVERTVALUE;

 FILETIME tmp_ft;

 if(!::SystemTimeToFileTime(&sys_time,&tmp_ft))
  return DB_E_CANTCONVERTVALUE;

 //---------
 (*result)=tmp_ft;

 //---------
 return S_OK;
}//internal__convert_value_to_filetime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime,filetime)

////////////////////////////////////////////////////////////////////////////////
