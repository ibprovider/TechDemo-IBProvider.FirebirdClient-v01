////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY_UI1->IUnknown implementation.
//                                                 Kovalenko Dmitry. 16.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_ui1,iunknown)::internal__convert_value_to_iunknown
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             REFIID               result_iid,
                                             result_type*   const result)const
{
 assert(dbvar.wType==(DBTYPE_ARRAY|DBTYPE_UI1));
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBVARIANT::TCvtAdapter_Array adapter;

 {
  const HRESULT hr=adapter.Unpack_VectorUI1_To_Bytes(dbvar);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 assert(adapter.dbvar().wType==DBTYPE_BYTES);

 return DBVariant__to_IUNKNOWN_ex(pConvCtx,adapter.dbvar(),result_iid,result);
}//internal__convert_value_to_iunknown

//------------------------------------------------------------------------
bool OLEDB_TYPE_CONVERTER_NAME(array_ui1,iunknown)::CanConvertTo
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBBINDING&     Bind)const
{
 assert(OLEDB_EXTRACT_DBTYPE(Bind.wType)==DBTYPE_IUNKNOWN);

 if(Bind.pObject==NULL)
  return true;

 const DBVARIANT::LPCTYPECONVERTER
  pConv=pConvCtx->GetTypeConverter(DBTYPE_BYTES,DBTYPE_IUNKNOWN);

 if(!pConv)
  return false;

 const DBVARIANT::LPCTYPECONVERTER_DBBINDING_TEST
  pConv_DbBindingTest=dynamic_cast<DBVARIANT::LPCTYPECONVERTER_DBBINDING_TEST>(pConv);

 if(pConv_DbBindingTest!=NULL)
  return pConv_DbBindingTest->CanConvertTo(pConvCtx,Bind);

 return true;
}//CanConvertTo

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(array_ui1,iunknown)

////////////////////////////////////////////////////////////////////////////////
