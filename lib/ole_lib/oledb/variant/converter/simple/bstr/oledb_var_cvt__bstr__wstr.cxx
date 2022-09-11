////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.bstrVal==NULL)
 {
  result->set_not_null().value().erase();

  return S_OK;
 }

 std::wstring tmp(dbvar.bstrVal,LCPI_OS__SysStringLen(dbvar.bstrVal));

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,wstr)

////////////////////////////////////////////////////////////////////////////////
