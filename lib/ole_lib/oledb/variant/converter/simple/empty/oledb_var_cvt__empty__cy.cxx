////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->cy implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,cy)::internal__convert_value_to_cy
                                            (LPCCONVCONTEXT const UNUSED_ARG(pConvCtx),
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const DEBUG_CODE(result))const
{
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_cy

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(empty,cy)

////////////////////////////////////////////////////////////////////////////////
