////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->dbtime2 implementation.
//                                                Kovalenko Dmitry. 08.09.2010.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,dbtime2)::internal__convert_value_to_dbtime2
                                            (LPCCONVCONTEXT const UNUSED_ARG(pConvCtx),
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const DEBUG_CODE(result))const
{
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_dbtime2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(empty,dbtime2)

////////////////////////////////////////////////////////////////////////////////
