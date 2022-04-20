////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY_UI1->UI4 implementation.
//                                                 Kovalenko Dmitry. 16.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_ui1,ui4)::internal__convert_value_to_ui4
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==(DBTYPE_ARRAY|DBTYPE_UI1));
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::TCvtAdapter_Array adapter;

 const HRESULT unpack_hr=adapter.Unpack_VectorUI1_To_Bytes(dbvar);

 if(FAILED(unpack_hr))
  return unpack_hr;

 assert(unpack_hr==S_OK);

 return DBVariant__to_UI4_ex(pConvCtx,adapter.dbvar(),result);
}//internal__convert_value_to_ui4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(array_ui1,ui4)

////////////////////////////////////////////////////////////////////////////////
