////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->iunknown implementation.
//                                                 Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,iunknown)::internal__convert_value_to_iunknown
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             REFIID               result_iid,
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

 ole_lib::IPtr2<IUnknown> spResultInterface;

 const HRESULT hr=dbvar.unkVal.ptr->QueryInterface
                  (result_iid,
                   reinterpret_cast<void**>(&spResultInterface.ref_ptr()));

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 if(!spResultInterface)
  return E_UNEXPECTED;

 spResultInterface.swap(result->set_not_null().value());

 return S_OK;
}//internal__convert_value_to_iunknown

//------------------------------------------------------------------------
bool OLEDB_TYPE_CONVERTER_NAME(iunknown,iunknown)::CanConvertTo
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBBINDING&     DEBUG_CODE(Bind))const
{
 assert(OLEDB_EXTRACT_DBTYPE(Bind.wType)==DBTYPE_IUNKNOWN);

 return true;
}//CanConvertTo

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,iunknown)

////////////////////////////////////////////////////////////////////////////////
