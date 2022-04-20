////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->bool implementation.
//                                                     Roman Piminov, 12.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,bool)::internal__convert_value_to_bool
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result_value_type b;

 const HRESULT hr=DBVARIANT_CVT_UTILS::DecimalToBool(dbvar.decVal,&b);

 if(FAILED(hr))
  return hr;

 (*result)=b;

 return hr;
}//internal__convert_value_to_bool

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,bool)

////////////////////////////////////////////////////////////////////////////////
