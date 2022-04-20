////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBDATE->filetime implementation.
//                                                     Roman Piminov, 24.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbdate,filetime)::internal__convert_value_to_filetime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBDATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 FILETIME x;

 if(!oledb_lib::dbdate_to_filetime(dbvar.dbdateVal,&x))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_filetime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbdate,filetime)

////////////////////////////////////////////////////////////////////////////////
