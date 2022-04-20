////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->r4 implementation.
//                                                     Roman Piminov, 02.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,r4)::internal__convert_value_to_r4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result_value_type r4;

 const HRESULT hr=DBVARIANT_CVT_UTILS::DecimalToR4(dbvar.decVal,&r4);

 if(FAILED(hr))
  return hr;

 (*result)=r4;

 return hr;
}//internal__convert_value_to_r4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,r4)

////////////////////////////////////////////////////////////////////////////////
