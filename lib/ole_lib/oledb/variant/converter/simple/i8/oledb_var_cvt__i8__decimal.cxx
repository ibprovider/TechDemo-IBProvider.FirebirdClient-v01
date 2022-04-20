////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I8->decimal implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i8,decimal)::internal__convert_value_to_decimal
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::IntToDecimal(dbvar.valI8.QuadPart,
                                          &result->set_not_null().value());
}//internal__convert_value_to_decimal

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i8,decimal)

////////////////////////////////////////////////////////////////////////////////
