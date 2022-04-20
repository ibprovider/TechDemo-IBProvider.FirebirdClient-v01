////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->guid implementation.
//                                                 Kovalenko Dmitry, 27.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,guid)::internal__convert_value_to_guid
                                            (LPCCONVCONTEXT const UNUSED_ARG(pConvCtx),
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const DEBUG_CODE(result))const
{
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_guid

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(empty,guid)

////////////////////////////////////////////////////////////////////////////////
