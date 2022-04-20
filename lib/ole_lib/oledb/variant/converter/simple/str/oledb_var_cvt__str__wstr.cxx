////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.strVal.length()==0)
 {
  result->set_not_null().value().erase();

  return S_OK;
 }

 CHECK_READ_PTR(dbvar.strVal.ptr,dbvar.strVal.byte_count());

 bool error=false;

 std::wstring tmp;

 structure::ansi_to_unicode(&tmp,
                            dbvar.strVal.ptr,
                            dbvar.strVal.len,
                            &error);

 if(error)
  return DB_E_CANTCONVERTVALUE;

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,wstr)

////////////////////////////////////////////////////////////////////////////////
