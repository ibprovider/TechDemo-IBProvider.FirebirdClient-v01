////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->ui1 implementation.
//                                                     Roman Piminov, 04.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,ui1)::internal__convert_value_to_ui1
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

 unsigned __int64 ui64=0;

 const HRESULT hr2=DBVARIANT_CVT_UTILS::NumericToInt(dbnum,&ui64);

 if(FAILED(hr2))
  return hr2;

 if(!structure::can_numeric_cast<result_value_type>(ui64))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(ui64);

 return (hr1==S_OK?hr2:hr1);
}//internal__convert_value_to_ui1

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,ui1)

////////////////////////////////////////////////////////////////////////////////
