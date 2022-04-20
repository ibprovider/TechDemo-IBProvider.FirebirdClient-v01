////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_CY->ui4 implementation.
//                                                     Roman Piminov, 05.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(cy,ui4)::internal__convert_value_to_ui4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_CY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 unsigned __int64 ui64=0;

 const HRESULT hr=DBVARIANT_CVT_UTILS::CYToInt(dbvar.valCY,ui64);

 if(FAILED(hr))
  return hr;

 if(!structure::can_numeric_cast<result_value_type>(ui64))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(ui64);

 return hr;
}//internal__convert_value_to_ui4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(cy,ui4)

////////////////////////////////////////////////////////////////////////////////
