////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_VARIANT->dbtime2 implementation.
//                                                 Kovalenko Dmitry. 08.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(variant,dbtime2)::internal__convert_value_to_dbtime2
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

 return DBVariant__to_DBTIME2_ex(pConvCtx,adapter.dbvar(),result);
}//internal__convert_value_to_dbtime2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(variant,dbtime2)

////////////////////////////////////////////////////////////////////////////////
