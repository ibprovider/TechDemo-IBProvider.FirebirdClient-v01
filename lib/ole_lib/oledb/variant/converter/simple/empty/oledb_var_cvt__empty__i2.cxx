////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->i2 implementation.
//                                                     Roman Piminov, 29.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,i2)::internal__convert_value_to_i2
                                            (LPCCONVCONTEXT const UNUSED_ARG(pConvCtx),
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const DEBUG_CODE(result))const
{
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_i2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(empty,i2)

////////////////////////////////////////////////////////////////////////////////
