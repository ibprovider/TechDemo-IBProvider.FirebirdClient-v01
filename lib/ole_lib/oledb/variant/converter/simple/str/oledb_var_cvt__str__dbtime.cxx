////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->dbtime implementation.
//                                                 Kovalenko Dmitry. 05.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,dbtime)::internal__convert_value_to_dbtime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBTIME x;

 if(!oledb_lib::str_to_dbtime(&x,dbvar.strVal.ptr,dbvar.strVal.length()))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,dbtime)

////////////////////////////////////////////////////////////////////////////////
