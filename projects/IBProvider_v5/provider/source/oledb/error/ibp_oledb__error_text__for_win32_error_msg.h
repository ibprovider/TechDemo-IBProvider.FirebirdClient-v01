////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_text__for_win32_error_msg.h
//! \brief   Реализация интерфейса IBP_IText для формирование сообщения WIN32-ошибки.
//! \author  Kovalenko Dmitry
//! \date    17.03.2018
#ifndef _ibp_oledb__error_text__for_win32_error_msg_H_
#define _ibp_oledb__error_text__for_win32_error_msg_H_

#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorText__ForWin32ErrorMsg

/// <summary>
///  Реализация интерфейса IBP_IText для формирование сообщения WIN32-ошибки.
/// </summary>
class IBP_OLEDB__ErrorText__ForWin32ErrorMsg LCPI_CPP_CFG__CLASS__FINAL
 :public ibprovider::IBP_IText
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__ErrorText__ForWin32ErrorMsg           self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler   inherited;

  IBP_OLEDB__ErrorText__ForWin32ErrorMsg(const self_type&);
  self_type& operator = (const self_type&);

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] errorCode
  explicit IBP_OLEDB__ErrorText__ForWin32ErrorMsg(DWORD errorCode);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~IBP_OLEDB__ErrorText__ForWin32ErrorMsg();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] errorCode
  //! \return
  //!  Полностью инициализированная компонента
  static ole_lib::IUnknownPtr Create(DWORD errorCode);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IBP_IText interface --------------------------------------------------
  virtual HRESULT __stdcall GetText(LCID  lcid,
                                    BSTR* pbstrText) COMP_W000004_OVERRIDE_FINAL;

 private:
  ///Код ошибки
  DWORD const m_errorCode;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorText__ForWin32ErrorMsg)
};//class IBP_OLEDB__ErrorText__ForWin32ErrorMsg

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
