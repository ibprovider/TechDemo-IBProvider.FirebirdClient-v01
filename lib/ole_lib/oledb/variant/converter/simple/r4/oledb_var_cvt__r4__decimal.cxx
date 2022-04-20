////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R4->decimal implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r4,decimal)::internal__convert_value_to_decimal
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 tagDEC tmp;

 const HRESULT hr=DBVARIANT_CVT_UTILS::R4ToDecimal(dbvar.valR4,&tmp);

 if(SUCCEEDED(hr))
 {
  (*result)=tmp;
 }

 return hr;
}//internal__convert_value_to_decimal

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r4,decimal)

////////////////////////////////////////////////////////////////////////////////
