////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_pset02
//! \file    remote_fb__pset02__error_utilities.h
//! \brief   Утилиты для обработки ошибок протокола SET02.
//! \author  Kovalenko Dmitry
//! \date    13.08.2016
#ifndef _remote_fb__pset02__error_utilities_H_
#define _remote_fb__pset02__error_utilities_H_

#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/error_services/ibp_error_element.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_pset02
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__ErrorUtilites

/// <summary>
///  Утилиты для обработки ошибок
/// </summary>
///  Основное назначение этого класса - избавить вызывающий код от обращения
///  к внутренним данным protocol::set02::P_OP_RESP.
class RemoteFB__PSET02__ErrorUtilites
{
 private:
  typedef RemoteFB__PSET02__ErrorUtilites        self_type;

 public:
  /// <summary>
  ///  Определение основного кода завершения операции
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //! \param[in] _p_resp
  static isc_api::t_ibp_isc_status
   GetResultCode
    (RemoteFB__ConnectorData*          _pData,
     protocol::set02::P_OP             _op_id,
     const protocol::set02::P_OP_RESP& _p_resp);

  /// <summary>
  ///  Формирование объекта с описанием серверной ошибки
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _p_resp
  //! \param[in] _hr
  //! \return
  //!  Not null.
  static t_ibp_error_element::self_ptr
   BuildServerErrorRecord
    (RemoteFB__ConnectorData*          _pData,
     protocol::set02::P_OP             _op_id,
     const protocol::set02::P_OP_RESP& _p_resp,
     HRESULT                           _hr);

  /// <summary>
  ///  Стандартная обработка RESPONSE-пакета
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _p_resp
  //! \param[in] _hr
  static void
   ProcessServerResult
    (RemoteFB__ConnectorData*          _pData,
     protocol::set02::P_OP             _op_id,
     const protocol::set02::P_OP_RESP& _p_resp,
     HRESULT                           _hr);

 public:
  /// <summary>
  ///  Стандартная обработка RESPONSE-пакета
  /// </summary>
  //! \param[in] _pPort
  //!  Not null.
  //! \param[in] _op_id
  //!  Идентификатор операции. Используется в BUG-CHECK сообщениях.
  //! \param[in] _p_resp
  //! \param[in] _hr
  static void
   ProcessServerResult2
    (RemoteFB__Port*                   _pPort,
     protocol::set02::P_OP             _op_id,
     const protocol::set02::P_OP_RESP& _p_resp,
     HRESULT                           _hr);
};//class RemoteFB__PSET02__ErrorUtilites

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
