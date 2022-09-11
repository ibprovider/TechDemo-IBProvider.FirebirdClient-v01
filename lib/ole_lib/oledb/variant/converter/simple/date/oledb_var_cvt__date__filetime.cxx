////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DATE->filetime implementation.
//                                                     Roman Piminov, 24.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(date,filetime)::internal__convert_value_to_filetime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 SYSTEMTIME systime;

 if(LCPI_OS__VariantTimeToSystemTime(dbvar.dateVal,&systime)==FALSE)
  return DB_E_CANTCONVERTVALUE;

 if(!::SystemTimeToFileTime(&systime,&result->set_not_null().value()))
  return DB_E_CANTCONVERTVALUE;

 return S_OK;
}//internal__convert_value_to_filetime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(date,filetime)

////////////////////////////////////////////////////////////////////////////////
