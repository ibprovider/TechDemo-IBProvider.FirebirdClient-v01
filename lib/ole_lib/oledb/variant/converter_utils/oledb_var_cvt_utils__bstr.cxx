//////////////////////////////////////////////////////////////////////////////////
//DBVARIANT_CVT_UTILS Implementation. BSTR Utilities
//                                                Kovalenko Dmitry 03.05.2008

//////////////////////////////////////////////////////////////////////////////////

HRESULT DBVARIANT_CVT_UTILS::EmptyBStr(value_cpp_bstr_n_type* const result)
{
 assert(result);

 BSTR bstrTmp=LCPI_OS__SysAllocStringLen(L"",0);

 if(bstrTmp==NULL)
  return E_OUTOFMEMORY;

 result->set_not_null().value().AssignBStr(bstrTmp); //no throw

 assert(bstrTmp==NULL);

 return S_OK;
}//EmptyBStr

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::StrToBStr(value_cpp_bstr_n_type* const result,
                                       const char*            const str,
                                       size_type              const length)
{
 assert(result);

 CHECK_READ_TYPED_PTR(str,length);

 BSTR bstrTmp=NULL;

 const HRESULT hr=ole_lib::StringToBStr(&bstrTmp,
                                        str,
                                        length,
                                        /*create empty*/true);
 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 result->set_not_null().value().AssignBStr(bstrTmp); //no throw

 assert(bstrTmp==NULL);

 return S_OK;
}//StrToBStr

//-------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::WStrToBStr(value_cpp_bstr_n_type* const result,
                                        const wchar_t*         const str,
                                        size_type              const length)
{
 assert(result);

 CHECK_READ_TYPED_PTR(str,length);

 BSTR bstrTmp=NULL;

 const HRESULT hr=ole_lib::WStrToBStr(&bstrTmp,
                                      str,
                                      length,
                                      /*create_empty*/true);
 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 result->set_not_null().value().AssignBStr(bstrTmp); //no throw

 assert(bstrTmp==NULL);

 return S_OK;
}//WStrToBStr

///////////////////////////////////////////////////////////////////////////////
