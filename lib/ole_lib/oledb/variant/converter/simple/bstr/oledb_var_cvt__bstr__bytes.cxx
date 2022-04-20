////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->bytes implementation.
//                                                     Roman Piminov, 29.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,bytes)::internal__convert_value_to_bytes
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const size_t bstrLen=dbvar.bstrVal?::SysStringByteLen(dbvar.bstrVal):0;

 CHECK_READ_PTR(dbvar.bstrVal,bstrLen);

 result->write(dbvar.bstrVal,bstrLen);

 return S_OK;
}//internal__convert_value_to_bytes

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,bytes)

////////////////////////////////////////////////////////////////////////////////
