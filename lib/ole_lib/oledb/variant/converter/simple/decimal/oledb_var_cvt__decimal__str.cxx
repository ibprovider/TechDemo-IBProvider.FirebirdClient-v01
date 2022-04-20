////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->str implementation.
//                                                     Roman Piminov, 15.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result_value_type str;

 const HRESULT hr=DBVARIANT_CVT_UTILS::DecimalToStr(dbvar.decVal,&str);

 if(FAILED(hr))
  return hr;

 result->set_not_null().value().swap(str);

 return hr;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,str)

////////////////////////////////////////////////////////////////////////////////