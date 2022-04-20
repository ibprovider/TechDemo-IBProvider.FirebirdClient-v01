////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BYTES->str implementation.
//                                                     Roman Piminov, 14.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bytes,str)::internal__convert_value_to_str
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

 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.byte_count());

 std::string tmp(reinterpret_cast<const char*>(dbvar.bytesVal.ptr),
                 dbvar.bytesVal.len);

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bytes,str)

////////////////////////////////////////////////////////////////////////////////
