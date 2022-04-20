////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->cy implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,cy)::internal__convert_value_to_cy
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_cy(result);
}//internal__convert_value_to_cy

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,cy)

////////////////////////////////////////////////////////////////////////////////
