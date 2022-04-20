////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R4->numeric implementation.
//                                                     Roman Piminov, 20.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r4,numeric)::internal__convert_value_to_numeric
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::R4ToNumeric(dbvar.valR4,
                                         &result->set_not_null().value());
}//internal__convert_value_to_numeric

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r4,numeric)

////////////////////////////////////////////////////////////////////////////////
