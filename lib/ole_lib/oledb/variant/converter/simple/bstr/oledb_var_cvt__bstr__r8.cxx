////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const size_t bstrLen=(dbvar.bstrVal?LCPI_OS__SysStringLen(dbvar.bstrVal):0);

 CHECK_READ_TYPED_PTR(dbvar.bstrVal,bstrLen);

 result_value_type tmp(0);

 HRESULT const hr=DBVARIANT_CVT_UTILS::WStrToR8(dbvar.bstrVal,
                                                bstrLen,
                                                &tmp);
 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 (*result)=tmp;

 return S_OK;
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,r8)

////////////////////////////////////////////////////////////////////////////////
