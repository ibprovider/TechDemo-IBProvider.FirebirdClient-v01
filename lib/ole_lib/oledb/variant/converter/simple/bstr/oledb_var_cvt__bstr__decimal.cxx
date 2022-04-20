////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->decimal implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,decimal)::internal__convert_value_to_decimal
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT& dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const size_t bstrLen=(dbvar.bstrVal?::SysStringLen(dbvar.bstrVal):0);

 result_value_type tmp;

 const HRESULT hr=DBVARIANT_CVT_UTILS::WStrToDecimal(dbvar.bstrVal,
                                                     bstrLen,
                                                     &tmp);
 if(SUCCEEDED(hr))
 {
  (*result)=tmp;
 }

 return hr;
}//internal__convert_value_to_decimal

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,decimal)

////////////////////////////////////////////////////////////////////////////////
