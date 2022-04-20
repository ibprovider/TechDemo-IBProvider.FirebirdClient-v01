////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->dbdate implementation.
//                                                 Kovalenko Dmitry. 06.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,dbdate)::internal__convert_value_to_dbdate
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBDATE x;

 if(!oledb_lib::str_to_dbdate(&x,dbvar.wstrVal.ptr,dbvar.wstrVal.length()))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbdate

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,dbdate)

////////////////////////////////////////////////////////////////////////////////
