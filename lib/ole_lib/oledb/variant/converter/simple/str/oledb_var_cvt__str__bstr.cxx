////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->bstr implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const DEBUG_CODE(pConvCtx),
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //[2018-01-12]
 CHECK_READ_TYPED_PTR(dbvar.strVal.ptr,dbvar.strVal.len);

 return DBVARIANT_CVT_UTILS::StrToBStr
         (result,
          dbvar.strVal.ptr,
          dbvar.strVal.len);
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,bstr)

////////////////////////////////////////////////////////////////////////////////
