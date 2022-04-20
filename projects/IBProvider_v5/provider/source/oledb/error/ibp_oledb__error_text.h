////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_text.h
//! \brief   Реализация интерфейса IBP_IText для err-сообщения без параметров
//! \author  Kovalenko Dmitry
//! \date    01.02.2011
#ifndef _ibp_oledb__error_text_H_
#define _ibp_oledb__error_text_H_

#include "source/error_services/ibp_error_codes.h"
#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorText

/// <summary>
///  Реализация интерфейса IBP_IText для err-сообщения без параметров
/// </summary>
class IBP_OLEDB__ErrorText LCPI_CPP_CFG__CLASS__FINAL
 :public ibprovider::IBP_IText
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__ErrorText                                   self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler   inherited;

  IBP_OLEDB__ErrorText(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef ibp_msg_code_type                             mce_code_type;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] mce_code_0
  explicit IBP_OLEDB__ErrorText(mce_code_type mce_code_0);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~IBP_OLEDB__ErrorText();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] mce_code_0
  //!  Код сообщения без параметров
  //! \return
  //!  Полностью инициализированная компонента
  static ole_lib::IUnknownPtr Create(mce_code_type mce_code_0);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IBP_IText interface --------------------------------------------------
  virtual HRESULT __stdcall GetText(LCID  lcid,
                                    BSTR* pbstrText) COMP_W000004_OVERRIDE_FINAL;

 private:
  ///Код сообщения об ошибке
  mce_code_type const m_mce_code_0;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorText)
};//class IBP_OLEDB__ErrorText

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
