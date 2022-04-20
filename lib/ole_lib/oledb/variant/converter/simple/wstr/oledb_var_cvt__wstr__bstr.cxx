////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->bstr implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const DEBUG_CODE(pConvCtx),
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_TYPED_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.len);

 return DBVARIANT_CVT_UTILS::WStrToBStr
         (result,
          dbvar.wstrVal.ptr,
          dbvar.wstrVal.len);
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,bstr)

////////////////////////////////////////////////////////////////////////////////
