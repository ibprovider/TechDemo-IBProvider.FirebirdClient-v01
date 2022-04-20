////////////////////////////////////////////////////////////////////////////////
//Default type converter to variant implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(common,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.TestDataStatus__IsOK());
 assert(result);

 //----------------------------------------- convert data to bstr
 DBVARIANT::value_cpp_bstr_n_type bstrTmp;

 const HRESULT cvt_hr=DBVariant__to_BSTR_ex(pConvCtx,dbvar,&bstrTmp);

 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 //-----------------------------------------
 if(bstrTmp.null())
  return this->helper__convert_null_to_variant(result);

 //-----------------------------------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 //-----------------------------------------
 result->bstrVal =bstrTmp.value().Release();
 result->vt      =VT_BSTR;

 //-----------------------------------------
 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(common,variant)

////////////////////////////////////////////////////////////////////////////////
