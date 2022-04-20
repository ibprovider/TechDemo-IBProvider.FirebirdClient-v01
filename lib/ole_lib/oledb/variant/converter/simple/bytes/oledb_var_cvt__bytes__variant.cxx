////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BYTES->variant implementation.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bytes,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BYTES);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //--------------------------------- Pack the bytes into SAFEARRAY(UI1)
 ole_lib::TBaseSafeArray sa;

 const HRESULT cvt_hr
  =DBVARIANT_CVT_UTILS::BytesToArrayUI1(dbvar.bytesVal.ptr,
                                        dbvar.bytesVal.byte_count(),
                                        &sa.ref_sa());
 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 //-----------------------------------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 //-----------------------------------------
 result->vt     =VARTYPE(VT_UI1|VT_ARRAY);
 result->parray =sa.Release();

 //-----------------------------------------
 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bytes,variant)

////////////////////////////////////////////////////////////////////////////////
