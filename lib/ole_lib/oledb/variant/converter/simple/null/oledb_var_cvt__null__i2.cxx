////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->i2 implementation.
//                                                     Roman Piminov, 29.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,i2)::internal__convert_value_to_i2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_i2(result);
}//internal__convert_value_to_i2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,i2)

////////////////////////////////////////////////////////////////////////////////
