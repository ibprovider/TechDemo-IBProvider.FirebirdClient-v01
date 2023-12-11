////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//Test COM-interface methods call. In case of FAIL - throw t_ole_error

HRESULT CheckOleCall(HRESULT hr,const std::string& verb);
HRESULT CheckOleCall(HRESULT hr);

////////////////////////////////////////////////////////////////////////////////

HRESULT BuildExcepInfo(HRESULT hr,EXCEPINFO* pExcepInfo);

////////////////////////////////////////////////////////////////////////////////
//Utility for processing of C++ exception in implementation of COM-objects

#ifndef OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER
# error "OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER is not defined!"
#endif

#if(OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER!=0)

// Router of exceptions. Called from catch(...) block
// Idea of 0xDEADBEEF [RSDN Member]. Thanks.
HRESULT OLE_CurrentExceptionHandler__DefaultImpl(REFCLSID ComponentID,
                                                 REFIID   InterfaceID,
                                                 bool     CreateErrInfo);

#endif //OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER!=0

////////////////////////////////////////////////////////////////////////////////

HRESULT OLE_MapExceptionToHRESULT(const std::exception* exc);

HRESULT OLE_MapErrorRecordToHRESULT(const structure::t_err_record* err_record);

HRESULT OLE_MapCurrentExceptionToHRESULT();

////////////////////////////////////////////////////////////////////////////////
