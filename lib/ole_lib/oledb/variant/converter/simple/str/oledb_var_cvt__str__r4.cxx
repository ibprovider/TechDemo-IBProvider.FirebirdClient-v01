////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->r4 implementation.
//                                                     Roman Piminov, 02.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,r4)::internal__convert_value_to_r4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_TYPED_PTR(dbvar.strVal.ptr,dbvar.strVal.length());

 double tmp(0);

 HRESULT const hr=DBVARIANT_CVT_UTILS::StrToR8(dbvar.strVal.ptr,
                                               dbvar.strVal.length(),
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
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,r4)

////////////////////////////////////////////////////////////////////////////////
