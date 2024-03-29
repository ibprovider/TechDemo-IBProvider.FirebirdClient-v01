////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//Test COM-interface methods call. In case of FAIL - throw t_ole_error

HRESULT CheckOleCall(HRESULT hr,const std::string& verb)
{
 if(FAILED(hr))
  t_ole_error::throw_disp_error(hr,verb);

 return hr;
}//CheckOleCall

//------------------------------------------------------------------------
HRESULT CheckOleCall(HRESULT hr)
{
 if(FAILED(hr))
  t_ole_error::throw_disp_error(hr);

 return hr;
}//CheckOleCall

//------------------------------------------------------------------------
HRESULT BuildExcepInfo(HRESULT hr,EXCEPINFO* const pExcepInfo)
{
 if(pExcepInfo==NULL)
  return hr;

 if(hr==DISP_E_EXCEPTION)
  return hr;

 if(SUCCEEDED(hr))
  return hr;

 OLE_LIB__DECLARE_IPTR_TYPE(IErrorInfo);

 try
 {
  memset(pExcepInfo,0,sizeof(*pExcepInfo));

  IErrorInfoPtr spEI;

  if(SUCCEEDED(LCPI_OS__GetErrorInfo(0,&spEI.ref_ptr())) && spEI)
  {
   TBSTR tmpSource;
   TBSTR tmpDescription;
   TBSTR tmpHelpFile;
   DWORD tmpHelpContext=0;

   spEI->GetSource(&tmpSource.ref_bstr());

   spEI->GetDescription(&tmpDescription.ref_bstr());

   spEI->GetHelpFile(&tmpHelpFile.ref_bstr());

   spEI->GetHelpContext(&tmpHelpContext);

   //------
   pExcepInfo->scode=hr;

   pExcepInfo->bstrSource=tmpSource.Release();

   pExcepInfo->bstrDescription=tmpDescription.Release();

   pExcepInfo->bstrHelpFile=tmpHelpFile.Release();

   pExcepInfo->dwHelpContext=tmpHelpContext;

   //------
   hr=DISP_E_EXCEPTION;
  }//if
 }
 catch(...)
 {
  hr=E_FAIL;
 }//catch

 return hr;
}//BuildExcepInfo

////////////////////////////////////////////////////////////////////////////////
//Utility for processing of C++ exception at implementation of COM-objects

#ifndef OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER
# error "OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER is not defined!"
#endif

#if(OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER!=0)

#if(OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO==0)

static HRESULT OLE_ProcessErrorException__impl
                   (REFCLSID                    UNUSED_ARG(ComponentID),
                    REFIID                      UNUSED_ARG(InterfaceID),
                    const std::exception* const pExc,
                    bool                  const DEBUG_CODE(CreateErrInfo)) //can throw
{
 //[2016-11-28] ѕо идее, такого происходить не должно.
 assert(!CreateErrInfo);

 return OLE_MapExceptionToHRESULT(pExc);
}//OLE_ProcessErrorException__impl

#else

static HRESULT OLE_ProcessErrorException__impl
                   (REFCLSID                    UNUSED_ARG(ComponentID),
                    REFIID                      InterfaceID,
                    const std::exception* const pExc,
                    bool                  const CreateErrInfo) //can throw
{
 const HRESULT hr=OLE_MapExceptionToHRESULT(pExc);

 if(CreateErrInfo)
 {
  try
  {
   if(!pExc)
   {
    assert(hr==E_UNEXPECTED);
   }
   else
   if(const t_base_com_error* const pComExc=dynamic_cast<const t_base_com_error*>(pExc))
   {
    assert(pComExc->com_code()==hr);

    pComExc->set_error_info(InterfaceID); //ignoring result code
   }//if
   else
   if(dynamic_cast<const std::bad_alloc*>(pExc)!=nullptr)
   {
    assert(hr==E_OUTOFMEMORY);

    //no error info
   }//if
   else
   {
    assert(pExc);

    const char* const what=pExc->what();

    if(what!=nullptr && (*what)!=0)
    {
     t_base_ole_error(hr,what).set_error_info(InterfaceID); //ignoring result code
    }
   }//if pExc
  }
  catch(...)
  {;}
 }//if CreateErrInfo

 return hr;
}//OLE_ProcessErrorException__impl

#endif // else - OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!=0

//------------------------------------------------------------------------
HRESULT OLE_CurrentExceptionHandler__DefaultImpl(REFCLSID ComponentID,
                                                 REFIID   InterfaceID,
                                                 bool     CreateErrInfo)
{
 OLE_LIB__DECLARE_HR(E_FAIL)

 try
 {
  try
  {
   throw;
  }
  catch(const std::exception& exc)
  {
   hr=OLE_ProcessErrorException__impl(ComponentID,
                                      InterfaceID,
                                      &exc,
                                      CreateErrInfo);
  }
#ifdef _USE_VCL_
  catch(const Exception& Exc)
  {
#error "Feature is not implemented!"
  }
#endif
  catch(...)
  {
   hr=OLE_ProcessErrorException__impl(ComponentID,
                                      InterfaceID,
                                      nullptr,
                                      CreateErrInfo);
  }//catch
 }
 catch(...)
 {
  //[2015-01-08] формально, у нас не должно быть каких-либо исключений.
  assert(false);

  assert(hr==E_FAIL);
 }//catch

 return hr;
}//OLE_CurrentExceptionHandler__DefaultImpl

#endif // OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER!=0

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Map the exception to HRESULT error code
/// </summary>
//! \param[in] exc
//!  Pointer to exception. Can be NULL
//! \return
//!  Error code
HRESULT OLE_MapExceptionToHRESULT(const std::exception* const exc)
{
 ///The NULL pointer will be map to E_UNEXPECTED error code
 if(exc==NULL)
  return E_UNEXPECTED;

 ///Processing the std::bad_alloc
 if(dynamic_cast<const std::bad_alloc*>(exc))
  return E_OUTOFMEMORY;

 ///Processing the win32lib::t_base_win32_error
 if(const win32lib::t_base_win32_error* const x=dynamic_cast<const win32lib::t_base_win32_error*>(exc))
  return HRESULT_FROM_WIN32(x->win32_code());

 ///Processing the ole_lib::t_base_com_error
 if(const t_base_com_error* const x=dynamic_cast<const t_base_com_error*>(exc))
  return x->com_code();

 ///The unknown exception class will be mapped to E_FAIL error code
 return E_FAIL;
}//OLE_MapExceptionToHRESULT

////////////////////////////////////////////////////////////////////////////////

HRESULT OLE_MapErrorRecordToHRESULT(const structure::t_err_record* const err_record)
{
 if(err_record==NULL)
  return E_UNEXPECTED;

 switch(err_record->get_system_id())
 {
  case structure::t_err_record::system_com:
   return err_record->get_error_code();

  case structure::t_err_record::system_win32:
   return HRESULT_FROM_WIN32(err_record->get_error_code());
 }//switch

 return E_FAIL;
}//OLE_MapErrorRecordToHRESULT

////////////////////////////////////////////////////////////////////////////////

HRESULT OLE_MapCurrentExceptionToHRESULT()
{
#ifndef OLE_LIB__CURRENT_EXCEPTION_HANDLER
# error "OLE_LIB__CURRENT_EXCEPTION_HANDLER is not defined!"
#endif

 return OLE_LIB__CURRENT_EXCEPTION_HANDLER
         (static_cast<IUnknown*>(nullptr),
          CLSID_NULL,
          IID_NULL,
          /*CreateErrInfo*/false);
}//OLE_MapCurrentExceptionToHRESULT

////////////////////////////////////////////////////////////////////////////////
