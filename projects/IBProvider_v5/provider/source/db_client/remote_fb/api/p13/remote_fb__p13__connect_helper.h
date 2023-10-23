////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__connect_helper.h
//! \brief   Вспомогательный класс с унифицированным кодом подключения/создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    17.08.2016
#ifndef _remote_fb__p13__connect_helper_H_
#define _remote_fb__p13__connect_helper_H_

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"
#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__ConnectHelper

/// <summary>
///  Вспомогательный класс с унифицированным кодом подключения/создания базы данных.
/// </summary>
class RemoteFB__P13__ConnectHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__P13__ConnectHelper;

 public: //typedefs ------------------------------------------------------
  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  /// <summary>
  ///  Подключение/создание базы данных.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //!  Расположение или имя базы данных.
  //! \param[in] clientConnectBlock
  //!  Контекст операции подключения к базе данных.
  //! \param[in] operationID
  static void exec(ports::base_v01::RemoteFB__Port_BASE_v01* pPort,
                   wstr_box_type                             ucs2_database_name,
                   RemoteFB__ClientConnectBlock_v2&          clientConnectBlock,
                   protocol::set02::P_OP                     operationID);

  /// <summary>
  ///  Формирование и отправка пакета op_cont_auth
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] clientConnectBlock
  //!  Контекст операции подключения к базе данных.
  static void send__cont_auth
                  (ports::base_v01::RemoteFB__Port_BASE_v01* pPort,
                   RemoteFB__ClientConnectBlock_v2&          clientConnectBlock);
};//class RemoteFB__P13__ConnectHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
