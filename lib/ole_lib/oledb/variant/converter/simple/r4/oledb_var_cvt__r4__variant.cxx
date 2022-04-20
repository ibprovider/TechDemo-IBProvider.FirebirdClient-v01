////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R4->variant implementation.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r4,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //----------------------------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 //----------------------------------
 result->vt     =VT_R4;
 result->fltVal =dbvar.valR4;

 //----------------------------------
 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r4,variant)

////////////////////////////////////////////////////////////////////////////////
