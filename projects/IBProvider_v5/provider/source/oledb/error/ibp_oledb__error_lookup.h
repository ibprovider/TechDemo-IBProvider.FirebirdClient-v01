////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_lookup.h
//! \brief   Сервис ошибок OLEDB провайдера
//! \author  Kovalenko Dmitry
//! \date    02.02.2003
#ifndef _ibp_oledb__error_lookup_H_
#define _ibp_oledb__error_lookup_H_

#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//containings

class IBP_OLEDB__ErrorLookup;

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorLookup

class IBP_OLEDB__ErrorLookup LCPI_CPP_CFG__CLASS__FINAL
 :public IErrorLookup
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__ErrorLookup                         self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler inherited;

  IBP_OLEDB__ErrorLookup(const self_type&);
  self_type& operator = (const self_type&);

 private:
  virtual ~IBP_OLEDB__ErrorLookup();

 public:
  IBP_OLEDB__ErrorLookup(IUnknown* pUnkOuter);

  static HRESULT Create(IUnknown*                pUnkOuter,
                        ole_lib::TBaseUnknown2** ppObject);

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //IErrorLookup interface -----------------------------------------------
  virtual HRESULT __stdcall GetErrorDescription
                             (HRESULT     hrError,
                              DWORD       dwLookupID,
                              DISPPARAMS* pdispparams,
                              LCID        lcid,
                              BSTR*       pbstrSource,
                              BSTR*       pbstrDescription) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetHelpInfo
                             (HRESULT     hrError,
                              DWORD       dwLookupID,
                              LCID        lcid,
                              BSTR*       pbstrHelpFile,
                              DWORD*      pdwHelpContext) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall ReleaseErrors
                             (const DWORD dwDynamicErrorID) COMP_W000004_OVERRIDE_FINAL;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorLookup)
};//class IBP_OLEDB__ErrorLookup

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
