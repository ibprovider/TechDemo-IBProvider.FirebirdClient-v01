////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->guid implementation.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,guid)::internal__convert_value_to_guid
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::StrToGUID(dbvar.strVal.ptr,
                                       dbvar.strVal.length(),
                                       &result->set_not_null().value());
}//internal__convert_value_to_guid

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,guid)

////////////////////////////////////////////////////////////////////////////////
