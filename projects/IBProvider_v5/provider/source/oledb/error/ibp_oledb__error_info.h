////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_info.h
//! \brief   Реализация интерфейса IErrorInfo для получения сведений об ошибке
//! \author  Kovalenko Dmitry
//! \date    19.10.2008 00:03
#ifndef _ibp_oledb__error_info_H_
#define _ibp_oledb__error_info_H_

#include "source/ibp_memory.h"
#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorInfo

/// <summary>
///  Реализация интерфейса IErrorInfo
/// </summary>
class IBP_OLEDB__ErrorInfo LCPI_CPP_CFG__CLASS__FINAL
 :public IErrorInfo
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__ErrorInfo                                self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler      inherited;

  IBP_OLEDB__ErrorInfo(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedef -------------------------------------------------------
  ///Smart pointer
  typedef ole_lib::IPtr2<self_type>                           self_ptr;

 public:
  std::wstring   m_wstrSource;
  std::wstring   m_wstrDescription;
  GUID           m_guid;
  DWORD          m_dwHelpContext;
  std::wstring   m_wstrHelpFile;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pUnkOuter
  IBP_OLEDB__ErrorInfo(IUnknown* pUnkOuter);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~IBP_OLEDB__ErrorInfo();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] pUnkOuter
  static self_ptr CreateInstance(IUnknown* pUnkOuter);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IErrorInfo interface -------------------------------------------------
  virtual HRESULT __stdcall GetSource(BSTR* pbstrSource) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetDescription(BSTR* pbstrDescription) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetGUID(GUID* pguid) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetHelpContext(DWORD* pdwHelpContext) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetHelpFile(BSTR* pbstrHelpFile) COMP_W000004_OVERRIDE_FINAL;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorInfo)
};//class IBP_OLEDB__ErrorInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
