////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const UNUSED_ARG(pConvCtx),
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const DEBUG_CODE(result))const
{
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(empty,r8)

////////////////////////////////////////////////////////////////////////////////
