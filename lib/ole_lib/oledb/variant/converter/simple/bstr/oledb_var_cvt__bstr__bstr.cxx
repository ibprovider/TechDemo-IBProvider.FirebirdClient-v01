////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->bstr implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const DEBUG_CODE(pConvCtx),
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const size_t bstrLen=(dbvar.bstrVal?LCPI_OS__SysStringLen(dbvar.bstrVal):0);

 return DBVARIANT_CVT_UTILS::WStrToBStr
         (result,
          dbvar.bstrVal,
          bstrLen);
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,bstr)

////////////////////////////////////////////////////////////////////////////////
