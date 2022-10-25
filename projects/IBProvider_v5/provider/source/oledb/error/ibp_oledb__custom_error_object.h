////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__custom_error_object.h
//! \brief   Стандартная реализация OLEDB CustomErrorObject.
//! \author  Kovalenko Dmitry
//! \date    03.08.2015
#ifndef _ibp_oledb__custom_error_object_H_
#define _ibp_oledb__custom_error_object_H_

#include "source/ibp_sqlncli.h"
#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__CustomErrorObject

/// <summary>
///  Стандартная реализация OLEDB CustomErrorObject.
/// </summary>
//!  Класс предоставляет стандартную реализацию интерфейса ISQLServerErrorInfo,
//!  который является ОБЯЗАТЕЛЬНЫМ, поскольку запрашивается и используется
//!  MSSQL-ем при обработке ошибок Linked Server.
class IBP_OLEDB__CustomErrorObject LCPI_CPP_CFG__CLASS__FINAL
 :public sqlncli::ISQLServerErrorInfo
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__CustomErrorObject                self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler   inherited;

  IBP_OLEDB__CustomErrorObject(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~IBP_OLEDB__CustomErrorObject();

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pUnkOuter
  //!  Указатель на контролирующий COM-объект. Can be NULL.
  //! \param[in] pErrRecord
  //!  Not NULL.
  IBP_OLEDB__CustomErrorObject(IUnknown*                      pUnkOuter,
                               const structure::t_err_record* pErrRecord);

  virtual HRESULT Init() COMP_W000004_OVERRIDE_FINAL;

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //ISQLServerErrorInfo interface ----------------------------------------
  virtual HRESULT __stdcall GetErrorInfo
                             (/*[out]*/ sqlncli::SSERRORINFO** ppErrorInfo,
                              /*[out]*/ OLECHAR**              ppStringsBuffer) COMP_W000004_OVERRIDE_FINAL;

 private:
  bool BaseUnknown__IsSupportedInterface(REFIID riid)const;

 private:
  /// Объект с описанием ошибки. Not NULL.
  const structure::t_err_record::self_cptr m_spErrRecord;

  /// Агрегированный оригинальный CustomErrorObject. Can be NULL.
  ole_lib::IUnknownPtr m_spOriginalCEO;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__CustomErrorObject)
};//class IBP_OLEDB__CustomErrorObject

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
