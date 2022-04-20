////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->error implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,error)::internal__convert_value_to_error
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_error(result);
}//internal__convert_value_to_error

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,error)

////////////////////////////////////////////////////////////////////////////////
