////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI2->decimal implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui2,decimal)::internal__convert_value_to_decimal
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI2);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::IntToDecimal(dbvar.valUI2,
                                          &result->set_not_null().value());
}//internal__convert_value_to_decimal

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui2,decimal)

////////////////////////////////////////////////////////////////////////////////
