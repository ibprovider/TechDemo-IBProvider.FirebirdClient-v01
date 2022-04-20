////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->str implementation.
//                                                     Roman Piminov, 12.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_str(result);
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,str)

////////////////////////////////////////////////////////////////////////////////
