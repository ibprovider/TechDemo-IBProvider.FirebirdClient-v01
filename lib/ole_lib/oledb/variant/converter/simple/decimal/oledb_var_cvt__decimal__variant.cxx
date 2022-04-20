////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->variant implementation.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::DecimalToVariant(dbvar.decVal,result);
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,variant)

////////////////////////////////////////////////////////////////////////////////
