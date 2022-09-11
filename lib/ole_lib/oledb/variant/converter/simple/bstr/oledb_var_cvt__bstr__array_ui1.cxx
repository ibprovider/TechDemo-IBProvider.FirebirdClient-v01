////////////////////////////////////////////////////////////////////////////////
//OLEDB Type converter: BSTR to ARRAY_UI1
//                                                Kovalenko Dmitry. 20.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,array_ui1)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const size_t bstrLen=(dbvar.bstrVal?LCPI_OS__SysStringByteLen(dbvar.bstrVal):0);

 return DBVARIANT_CVT_UTILS::BytesToArrayUI1
         (dbvar.bstrVal,
          bstrLen,
          result);
}//internal__convert_value_to_array

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,array_ui1)

////////////////////////////////////////////////////////////////////////////////
