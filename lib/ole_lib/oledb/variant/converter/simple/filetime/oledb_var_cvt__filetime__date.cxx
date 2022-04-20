////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_FILETIME->date implementation.
//                                                  Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(filetime,date)::internal__convert_value_to_date
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

 if(!::SystemTimeToVariantTime(&st,&result->set_not_null().value()))
  return DB_E_CANTCONVERTVALUE;

 return S_OK;
}//internal__convert_value_to_date

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(filetime,date)

////////////////////////////////////////////////////////////////////////////////
