////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->str implementation.
//                                                     Roman Piminov, 14.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,str)::internal__convert_value_to_str
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

 bool error=false;

 std::string tmp;

 structure::unicode_to_ansi
  (&tmp,
   dbvar.wstrVal.ptr,
   dbvar.wstrVal.len,
   &error);

 if(error)
  return DB_E_CANTCONVERTVALUE;

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,str)

////////////////////////////////////////////////////////////////////////////////
