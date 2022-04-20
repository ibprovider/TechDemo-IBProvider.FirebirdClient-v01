////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->idispatch implementation.
//                                                     Roman Piminov, 21.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,idispatch)::internal__convert_value_to_idispatch
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_IUNKNOWN);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.unkVal.ptr==NULL)
 {
  result->set_not_null().value().Release();

  return S_OK;
 }//if

 ole_lib::IPtr2<IDispatch> spDisp;

 const HRESULT hr=dbvar.unkVal.ptr->QueryInterface
                   (IID_IDispatch,
                    reinterpret_cast<void**>(&spDisp.ref_ptr()));

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 if(!spDisp)
  return E_UNEXPECTED;

 result->set_not_null().value().swap(spDisp);

 return S_OK;
}//internal__convert_value_to_idispatch

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,idispatch)

////////////////////////////////////////////////////////////////////////////////
