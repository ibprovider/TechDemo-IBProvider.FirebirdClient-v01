////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BYTES->wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bytes,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BYTES);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.bytesVal.length()==0)
 {
  result->set_not_null().value().erase();
  return S_OK;
 }

 if(dbvar.bytesVal.len%sizeof(wchar_t))
  return DB_E_CANTCONVERTVALUE;

 std::wstring tmp(reinterpret_cast<const wchar_t*>(dbvar.bytesVal.ptr),
                  dbvar.bytesVal.len/sizeof(wchar_t));

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bytes,wstr)

////////////////////////////////////////////////////////////////////////////////
