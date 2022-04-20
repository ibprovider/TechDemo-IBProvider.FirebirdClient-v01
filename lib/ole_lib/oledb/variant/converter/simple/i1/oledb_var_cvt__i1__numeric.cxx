////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I1->numeric implementation.
//                                                     Roman Piminov, 20.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i1,numeric)::internal__convert_value_to_numeric
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I1);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::IntToNumeric(short(dbvar.valI1),
                                          &result->set_not_null().value());
}//internal__convert_value_to_numeric

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i1,numeric)

////////////////////////////////////////////////////////////////////////////////
