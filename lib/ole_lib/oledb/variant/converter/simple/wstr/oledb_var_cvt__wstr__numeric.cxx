////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->numeric implementation.
//                                                     Roman Piminov, 20.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,numeric)::internal__convert_value_to_numeric
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::WStrToNumeric(dbvar.wstrVal.ptr,
                                           dbvar.wstrVal.length(),
                                           &result->set_not_null().value());
}//internal__convert_value_to_numeric

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,numeric)

////////////////////////////////////////////////////////////////////////////////
