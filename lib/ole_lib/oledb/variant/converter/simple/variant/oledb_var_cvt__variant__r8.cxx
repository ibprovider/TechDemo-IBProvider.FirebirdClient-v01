////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_VARIANT->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(variant,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_VARIANT);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::TCvtAdapter adapter;

 const HRESULT hr=adapter.Unpack_Variant(dbvar);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return DBVariant__to_R8_ex(pConvCtx,adapter.dbvar(),result);
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(variant,r8)

////////////////////////////////////////////////////////////////////////////////
