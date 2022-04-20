////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->ui1 implementation.
//                                                     Roman Piminov, 04.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,ui1)::internal__convert_value_to_ui1
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DECIMAL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 unsigned __int64 ui64;

 const HRESULT hr=DBVARIANT_CVT_UTILS::DecimalToInt(dbvar.decVal,&ui64);

 if(FAILED(hr))
  return hr;

 if(!structure::can_numeric_cast<result_value_type>(ui64))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(ui64);

 return hr;
}//internal__convert_value_to_ui1

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,ui1)

////////////////////////////////////////////////////////////////////////////////
