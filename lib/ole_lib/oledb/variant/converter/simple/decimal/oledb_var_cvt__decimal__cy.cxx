////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->cy implementation.
//                                                  Dmitry Kovalenko, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,cy)::internal__convert_value_to_cy
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result_value_type cy;

 const HRESULT hr=DBVARIANT_CVT_UTILS::DecimalToCY(dbvar.decVal,&cy);

 if(FAILED(hr))
  return hr;

 (*result)=cy;

 return hr;
}//internal__convert_value_to_cy

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,cy)

////////////////////////////////////////////////////////////////////////////////
