////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R8->decimal implementation.
//                                                     Roman Piminov, 19.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r8,decimal)::internal__convert_value_to_decimal
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 tagDEC tmp;

 const HRESULT hr=DBVARIANT_CVT_UTILS::R8ToDecimal(dbvar.valR8,&tmp);

 if(SUCCEEDED(hr))
 {
  (*result)=tmp;
 }

 return hr;
}//internal__convert_value_to_decimal

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r8,decimal)

////////////////////////////////////////////////////////////////////////////////
