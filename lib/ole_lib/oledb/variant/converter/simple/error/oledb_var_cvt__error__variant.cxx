////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_ERROR->variant implementation.
//                                                     Roman Piminov, 09.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(error,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_ERROR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //----------------------------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 //----------------------------------
 result->vt    =VT_ERROR;
 result->scode =dbvar.scodeVal;

 //----------------------------------
 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(error,variant)

////////////////////////////////////////////////////////////////////////////////
