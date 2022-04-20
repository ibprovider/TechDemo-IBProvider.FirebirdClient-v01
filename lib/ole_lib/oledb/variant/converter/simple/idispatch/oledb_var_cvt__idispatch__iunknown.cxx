////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IDISPATCH->iunknown implementation.
//                                                  Kovalenko Dmitry, 26.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(idispatch,iunknown)::internal__convert_value_to_iunknown
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             REFIID               result_iid,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_IDISPATCH);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.dispVal.ptr==NULL)
 {
  result->set_not_null().value().Release();

  return S_OK;
 }//if

 ole_lib::IPtr2<IUnknown> spUnk;

 const HRESULT hr=dbvar.dispVal.ptr->QueryInterface(result_iid,
                                                    reinterpret_cast<void**>(&spUnk.ref_ptr()));

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 if(!spUnk)
  return E_UNEXPECTED;

 result->set_not_null().value().swap(spUnk);

 return S_OK;
}//internal__convert_value_to_iunknown

//------------------------------------------------------------------------
bool OLEDB_TYPE_CONVERTER_NAME(idispatch,iunknown)::CanConvertTo
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBBINDING&     DEBUG_CODE(Bind))const
{
 assert(OLEDB_EXTRACT_DBTYPE(Bind.wType)==DBTYPE_IUNKNOWN);

 return true;
}//CanConvertTo

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(idispatch,iunknown)

////////////////////////////////////////////////////////////////////////////////
