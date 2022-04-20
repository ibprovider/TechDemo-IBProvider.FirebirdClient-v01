////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->deciamal implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,decimal)::internal__convert_value_to_decimal
                                            (LPCCONVCONTEXT const UNUSED_ARG(pConvCtx),
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const DEBUG_CODE(result))const
{
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_decimal

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(empty,decimal)

////////////////////////////////////////////////////////////////////////////////
