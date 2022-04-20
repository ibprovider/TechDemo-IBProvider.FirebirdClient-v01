////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->idispatch implementation.
//                                                     Roman Piminov, 21.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,idispatch)::internal__convert_value_to_idispatch
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_idispatch(result);
}//internal__convert_value_to_idispatch

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,idispatch)

////////////////////////////////////////////////////////////////////////////////
