////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->i8 implementation.
//                                                     Roman Piminov, 01.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,i8)::internal__convert_value_to_i8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 const size_t bstrLen=(dbvar.bstrVal?LCPI_OS__SysStringLen(dbvar.bstrVal):0);

 DB_NUMERIC dbnum;

 const HRESULT hr1=DBVARIANT_CVT_UTILS::WStrToNumeric(dbvar.bstrVal,bstrLen,&dbnum);

 if(FAILED(hr1))
  return hr1;

 const HRESULT hr2=DBVARIANT_CVT_UTILS::NumericToInt(dbnum,&result->set_not_null().value());

 if(FAILED(hr2))
  return hr2;

 return (hr1==S_OK?hr2:hr1);
}//internal__convert_value_to_i8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,i8)

////////////////////////////////////////////////////////////////////////////////
