////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DECIMAL->ui8 implementation.
//                                                     Roman Piminov, 05.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(decimal,ui8)::internal__convert_value_to_ui8
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

 (*result)=ui64;

 return hr;
}//internal__convert_value_to_ui8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(decimal,ui8)

////////////////////////////////////////////////////////////////////////////////
