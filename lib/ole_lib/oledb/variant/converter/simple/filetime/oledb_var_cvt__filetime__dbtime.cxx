////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_FILETIME->dbtime implementation.
//                                                  Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(filetime,dbtime)::internal__convert_value_to_dbtime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_FILETIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 SYSTEMTIME st;

 if(!::FileTimeToSystemTime(&dbvar.filetimeVal,&st))
  return DB_E_CANTCONVERTVALUE;

 //------
 DBTIME x;

 x.hour   = st.wHour;
 x.minute = st.wMinute;
 x.second = st.wSecond;

 //------
 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(filetime,dbtime)

////////////////////////////////////////////////////////////////////////////////
