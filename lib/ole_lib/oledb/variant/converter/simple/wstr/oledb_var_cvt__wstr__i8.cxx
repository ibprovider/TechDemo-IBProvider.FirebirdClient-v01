////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->i8 implementation.
//                                                     Roman Piminov, 01.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,i8)::internal__convert_value_to_i8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.byte_count());

 DB_NUMERIC dbnum;

 const HRESULT hr1=DBVARIANT_CVT_UTILS::WStrToNumeric(dbvar.wstrVal.ptr,
                                                      dbvar.wstrVal.length(),
                                                      &dbnum);
 if(FAILED(hr1))
  return hr1;

 const HRESULT hr2=DBVARIANT_CVT_UTILS::NumericToInt(dbnum,
                                                     &result->set_not_null().value());

 if(FAILED(hr2))
  return hr2;

 return (hr1==S_OK?hr2:hr1);
}//internal__convert_value_to_i8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,i8)

////////////////////////////////////////////////////////////////////////////////
