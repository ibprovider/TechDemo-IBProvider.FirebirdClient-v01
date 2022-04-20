////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->cy implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,cy)::internal__convert_value_to_cy
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const size_t bstrLen=(dbvar.bstrVal?::SysStringLen(dbvar.bstrVal):0);

 return DBVARIANT_CVT_UTILS::WStrToCY(dbvar.bstrVal,
                                      bstrLen,
                                      &result->set_not_null().value());
}//internal__convert_value_to_cy

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,cy)

////////////////////////////////////////////////////////////////////////////////
