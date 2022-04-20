////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.wstrVal.length()==0)
 {
  result->set_not_null().value().erase();

  return S_OK;
 }

 CHECK_READ_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.byte_count());

 std::wstring tmp(dbvar.wstrVal.ptr,dbvar.wstrVal.len);

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,wstr)

////////////////////////////////////////////////////////////////////////////////
