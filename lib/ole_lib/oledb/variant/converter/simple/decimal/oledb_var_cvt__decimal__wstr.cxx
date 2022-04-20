////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result_value_type wstr;

 const HRESULT hr=DBVARIANT_CVT_UTILS::DecimalToWStr(dbvar.decVal,&wstr);

 if(FAILED(hr))
  return hr;

 result->set_not_null().value().swap(wstr);

 return hr;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,wstr)

////////////////////////////////////////////////////////////////////////////////
