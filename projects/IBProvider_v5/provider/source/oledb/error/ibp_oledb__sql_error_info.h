////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__sql_error_info.h
//! \brief   Компонента с интерфейсом ISQLErrorInfo
//! \author  Kovalenko Dmitry
//! \date    09.04.2010
#ifndef _ibp_oledb__sql_error_info_H_
#define _ibp_oledb__sql_error_info_H_

#include <ole_lib/ole_lib.h>

#include <structure/t_str_parameter.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__SQLErrorInfo

/// <summary>
///  Компонента с интерфейсом ISQLErrorInfo
/// </summary>
class IBP_OLEDB__SQLErrorInfo LCPI_CPP_CFG__CLASS__FINAL
 :public ibprovider::IBP_IClone
 ,public ISQLErrorInfo
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__SQLErrorInfo                            self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler     inherited;

  IBP_OLEDB__SQLErrorInfo(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::str_parameter                           str_arg_type;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pUnkOuter
  //! \param[in] strSQLState
  //! \param[in] lNativeError
  IBP_OLEDB__SQLErrorInfo(IUnknown*    pUnkOuter,
                          str_arg_type strSQLState,
                          LONG         lNativeError);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~IBP_OLEDB__SQLErrorInfo();

 public:
  /// <summary>
  ///  Конструирование COM-объекта
  /// </summary>
  //! \param[in] strSQLState
  //! \param[in] lNativeError
  //! \return
  //!  Полностью инициализированный COM-объект
  static ole_lib::IPtr2<ibprovider::IBP_IClone> Create(str_arg_type strSQLState,
                                                       LONG         lNativeError);

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //IBP_IClone interface -------------------------------------------------
  virtual HRESULT __stdcall Clone(IUnknown*  pUnkOuter,
                                  IUnknown** ppClone) COMP_W000004_OVERRIDE_FINAL;

  //ISQLErrorInfo interface ----------------------------------------------
  virtual HRESULT __stdcall GetSQLInfo(BSTR* pbstrSQLState,
                                       LONG* plNativeError) COMP_W000004_OVERRIDE_FINAL;

 private:
  ///Текст с кодом SQLSTATE
  const std::string m_strSQLState;

  ///Код ошибки сервера
  const LONG        m_lNativeError;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__SQLErrorInfo)
};//class IBP_OLEDB__SQLErrorInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
