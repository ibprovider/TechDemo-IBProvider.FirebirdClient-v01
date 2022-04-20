////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->str implementation.
//                                                     Roman Piminov, 14.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,str)::internal__convert_value_to_str
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

 std::string tmp(dbvar.strVal.ptr,dbvar.strVal.len);

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,str)

////////////////////////////////////////////////////////////////////////////////
