////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_VARIANT->ARRAY implementation.
//                                                Kovalenko Dmitry, 02.06.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(variant,array)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             REFIID               result_iid,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_VARIANT);
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wToType)==DBTYPE_ARRAY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::TCvtAdapter adapter;

 const HRESULT hr=adapter.Unpack_Variant(dbvar);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return DBVariant__to_ARRAY_ex(pConvCtx,
                               adapter.dbvar(),
                               m_wToType,
                               result_iid,
                               result);
}//internal__convert_value_to_array

////////////////////////////////////////////////////////////////////////////////
