////////////////////////////////////////////////////////////////////////////////
//Default type converter to wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(common,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::value_cpp_str_n_type str;

 const HRESULT hr=DBVariant__to_STR_ex(pConvCtx,dbvar,&str);

 if(FAILED(hr))
  return hr;

 if(str.null())
 {
  result->reset();

  return hr;
 }//if

 bool error=false;

 std::wstring tmp;

 structure::ansi_to_unicode(&tmp,str.value(),&error);

 if(error)
  return DB_E_CANTCONVERTVALUE;

 result->set_not_null().value().swap(tmp);

 return hr;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(common,wstr)

////////////////////////////////////////////////////////////////////////////////
