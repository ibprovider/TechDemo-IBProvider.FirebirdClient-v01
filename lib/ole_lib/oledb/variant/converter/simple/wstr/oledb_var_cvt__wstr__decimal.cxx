////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->decimal implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,decimal)::internal__convert_value_to_decimal
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result_value_type tmp;

 const HRESULT hr=DBVARIANT_CVT_UTILS::WStrToDecimal(dbvar.wstrVal.ptr,
                                                     dbvar.wstrVal.length(),
                                                     &tmp);
 if(SUCCEEDED(hr))
 {
  (*result)=tmp;
 }

 return hr;
}//internal__convert_value_to_decimal

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,decimal)

////////////////////////////////////////////////////////////////////////////////
