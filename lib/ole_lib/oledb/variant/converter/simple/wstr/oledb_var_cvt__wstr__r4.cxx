////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->r4 implementation.
//                                                     Roman Piminov, 02.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,r4)::internal__convert_value_to_r4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_TYPED_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.length());

 double tmp(0);

 HRESULT const hr=DBVARIANT_CVT_UTILS::WStrToR8(dbvar.wstrVal.ptr,
                                                dbvar.wstrVal.length(),
                                                &tmp);
 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 if(tmp<structure::t_numeric_limits<result_value_type>::min_value() ||
    tmp>structure::t_numeric_limits<result_value_type>::max_value())
 {
  return TDBTypeConverterCode::numeric_overflow;
 }

 (*result)=static_cast<result_value_type>(tmp);

 return S_OK;
}//internal__convert_value_to_r4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,r4)

////////////////////////////////////////////////////////////////////////////////
