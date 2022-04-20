////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_CY->i1 implementation.
//                                                     Roman Piminov, 26.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(cy,i1)::internal__convert_value_to_i1
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_CY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 signed __int64 i64=0;

 const HRESULT hr=DBVARIANT_CVT_UTILS::CYToInt(dbvar.valCY,i64);

 if(FAILED(hr))
  return hr;

 if(!structure::can_numeric_cast<result_value_type>(i64))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(i64);

 return hr;
}//internal__convert_value_to_i1

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(cy,i1)

////////////////////////////////////////////////////////////////////////////////
