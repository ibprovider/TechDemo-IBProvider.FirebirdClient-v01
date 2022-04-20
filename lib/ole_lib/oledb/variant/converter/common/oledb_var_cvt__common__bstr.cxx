////////////////////////////////////////////////////////////////////////////////
//Default type converter to bstr implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(common,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx!=NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::value_cpp_wstr_n_type wstr;

 const HRESULT hr1=DBVariant__to_WSTR_ex(pConvCtx,dbvar,&wstr);

 if(FAILED(hr1))
  return hr1;

 if(wstr.null())
 {
  result->reset();

  return hr1;
 }

 const HRESULT hr2=DBVARIANT_CVT_UTILS::WStrToBStr
                    (result,
                     wstr.value().c_str(),
                     wstr.value().size());
 if(FAILED(hr2))
  return hr2;

 return ((hr1==S_OK)?hr2:hr1);
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(common,bstr)

////////////////////////////////////////////////////////////////////////////////
