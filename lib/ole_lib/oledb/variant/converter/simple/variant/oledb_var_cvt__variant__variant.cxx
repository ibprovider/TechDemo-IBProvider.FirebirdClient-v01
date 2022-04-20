////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_VARIANT->variant implementation.
//                                                     Roman Piminov, 09.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(variant,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_VARIANT);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const HRESULT copy_hr=ole_lib::Variant_Copy(/*pDest*/result,&dbvar.varVal);

 if(FAILED(copy_hr))
  return E_FAIL;

 assert(copy_hr==S_OK);

 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(variant,variant)

////////////////////////////////////////////////////////////////////////////////
