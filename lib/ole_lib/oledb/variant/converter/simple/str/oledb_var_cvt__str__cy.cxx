////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->cy implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,cy)::internal__convert_value_to_cy
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::StrToCY(dbvar.strVal.ptr,
                                     dbvar.strVal.length(),
                                     &result->set_not_null().value());
}//internal__convert_value_to_cy

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,cy)

////////////////////////////////////////////////////////////////////////////////
