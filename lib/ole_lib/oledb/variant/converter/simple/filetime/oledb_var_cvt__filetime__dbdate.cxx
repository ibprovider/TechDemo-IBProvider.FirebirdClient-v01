////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_FILETIME->dbdate implementation.
//                                                  Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(filetime,dbdate)::internal__convert_value_to_dbdate
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_FILETIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //--------
 DBDATE x;

 if(!oledb_lib::filetime_to_dbdate(dbvar.filetimeVal,&x))
  return DB_E_CANTCONVERTVALUE;

 //--------
 (*result)=x;

 //--------
 return S_OK;
}//internal__convert_value_to_dbdate

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(filetime,dbdate)

////////////////////////////////////////////////////////////////////////////////
