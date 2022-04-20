////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_TYPED_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.length());

 result_value_type tmp(0);

 HRESULT const hr=DBVARIANT_CVT_UTILS::WStrToR8(dbvar.wstrVal.ptr,
                                                dbvar.wstrVal.length(),
                                                &tmp);
 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 (*result)=tmp;

 return S_OK;
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,r8)

////////////////////////////////////////////////////////////////////////////////
