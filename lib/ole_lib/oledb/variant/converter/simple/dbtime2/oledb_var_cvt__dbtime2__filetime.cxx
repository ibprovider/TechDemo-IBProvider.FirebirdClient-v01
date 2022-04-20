////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME2->filetime implementation.
//                                                 Kovalenko Dmitry. 09.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime2,filetime)::internal__convert_value_to_filetime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==oledb_lib::oledb_typeid__DBTIME2);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 FILETIME ft;

 if(!oledb_lib::dbtime2_to_filetime(dbvar.dbtime2Val,&ft))
  return DB_E_CANTCONVERTVALUE;

 (*result)=ft;

 return S_OK;
}//internal__convert_value_to_filetime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime2,filetime)

////////////////////////////////////////////////////////////////////////////////
