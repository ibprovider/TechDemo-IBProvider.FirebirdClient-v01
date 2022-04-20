////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->r4 implementation.
//                                                     Roman Piminov, 02.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,r4)::internal__convert_value_to_r4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_r4(result);
}//internal__convert_value_to_r4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,r4)

////////////////////////////////////////////////////////////////////////////////
