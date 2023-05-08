////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__srv_error_utils_v1.h
//! \brief   Утилиты для обработки ошибок сервера.
//! \author  Kovalenko Dmitry
//! \date    12.08.2016
#ifndef _remote_fb__srv_error_utils_v1_H_
#define _remote_fb__srv_error_utils_v1_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/db_base.h"
#include "source/error_services/ibp_error_element.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SrvErrorUtils_v1

/// <summary>
///  Утилиты для обработки ошибок
/// </summary>
class RemoteFB__SrvErrorUtils_v1
{
 private:
  typedef RemoteFB__SrvErrorUtils_v1        self_type;

 public: //typedefs ------------------------------------------------------

  /// Тип для представления идентификатора операции с сервером
  typedef int                               p_operation_id_type;

 public:
  /// <summary>
  ///  Определение основного кода завершения операции
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //! \param[in] _status_vector
  static isc_api::t_ibp_isc_status
   GetResultCode
    (RemoteFB__ConnectorData*             _pData,
     p_operation_id_type                  _op_id,
     const protocol::P_ISC_STATUS_VECTOR& _status_vector);

  /// <summary>
  ///  Формирование объекта с описанием серверной ошибки
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _status_vector
  //! \param[in] _hr
  //! \return
  //!  Not null.
  static t_ibp_error_element::self_ptr
   BuildServerErrorRecord
    (RemoteFB__ConnectorData*             _pData,
     p_operation_id_type                  _op_id,
     const protocol::P_ISC_STATUS_VECTOR& _status_vector,
     HRESULT                              _hr);

  /// <summary>
  ///  Стандартная обработка статус вектора
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _status_vector
  //! \param[in] _hr
  static void ProcessServerResult
   (RemoteFB__ConnectorData*             _pData,
    p_operation_id_type                  _op_id,
    const protocol::P_ISC_STATUS_VECTOR& _status_vector,
    HRESULT                              _hr);

 public:
  /// <summary>
  ///  Формирование объекта с описанием серверной ошибки
  /// </summary>
  //! \param[in] _pPort
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _status_vector
  //! \param[in] _hr
  //! \return
  //!  Not null.
  static t_ibp_error_element::self_ptr
   BuildServerErrorRecord2
    (RemoteFB__Port*                      _pPort,
     p_operation_id_type                  _op_id,
     const protocol::P_ISC_STATUS_VECTOR& _status_vector,
     HRESULT                              _hr);

  /// <summary>
  ///  Стандартная обработка статус вектора
  /// </summary>
  //! \param[in] _pPort
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _status_vector
  //! \param[in] _hr
  static void ProcessServerResult2
   (RemoteFB__Port*                      _pPort,
    p_operation_id_type                  _op_id,
    const protocol::P_ISC_STATUS_VECTOR& _status_vector,
    HRESULT                              _hr);

 private:
  /// <summary>
  ///  Формирование объекта с описанием серверной ошибки
  /// </summary>
  //! \param[in] _pSvcProvider
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _status_vector
  //! \param[in] _hr
  //! \return
  //!  Can be null.
  static t_ibp_error_element::self_ptr
   Helper__BuildServerErrorRecord
    (db_obj::t_db_service_provider*       _pSvcProvider,
     p_operation_id_type                  _op_id,
     const protocol::P_ISC_STATUS_VECTOR& _status_vector,
     HRESULT                              _hr);
};//class RemoteFB__SrvErrorUtils_v1

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
