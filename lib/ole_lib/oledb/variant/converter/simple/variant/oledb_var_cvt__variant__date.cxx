////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_VARIANT->date implementation.
//                                                     Roman Piminov, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(variant,date)::internal__convert_value_to_date
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_VARIANT);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::TCvtAdapter adapter;

 const HRESULT hr=adapter.Unpack_Variant(dbvar);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return DBVariant__to_DATE_ex(pConvCtx,adapter.dbvar(),result);
}//internal__convert_value_to_date

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(variant,date)

////////////////////////////////////////////////////////////////////////////////
