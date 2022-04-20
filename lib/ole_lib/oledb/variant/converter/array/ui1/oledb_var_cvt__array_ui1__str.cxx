////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY_UI1->str implementation.
//                                                 Kovalenko Dmitry. 16.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_ui1,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==(DBTYPE_ARRAY|DBTYPE_UI1));
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::TCvtAdapter_Array adapter;

 const HRESULT hr=adapter.Unpack_VectorUI1_To_Bytes(dbvar);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return DBVariant__to_STR_ex(pConvCtx,adapter.dbvar(),result);
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(array_ui1,str)

////////////////////////////////////////////////////////////////////////////////
