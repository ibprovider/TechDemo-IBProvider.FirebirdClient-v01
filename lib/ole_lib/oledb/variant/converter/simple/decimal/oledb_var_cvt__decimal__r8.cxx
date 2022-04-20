////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result_value_type r8;

 const HRESULT hr=DBVARIANT_CVT_UTILS::DecimalToR8(dbvar.decVal,&r8);

 if(FAILED(hr))
  return hr;

 (*result)=r8;

 return hr;
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,r8)

////////////////////////////////////////////////////////////////////////////////
