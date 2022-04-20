////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__p11__connect_helper.h
//! \brief   Вспомогательный класс с унифицированным кодом подключения/создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#ifndef _remote_fb__p11__connect_helper_H_
#define _remote_fb__p11__connect_helper_H_

#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p11
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P11__ConnectHelper

/// <summary>
///  Вспомогательный класс с унифицированным кодом подключения/создания базы данных.
/// </summary>
class RemoteFB__P11__ConnectHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P11__ConnectHelper             self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstr_box              wstr_box_type;

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
  static void exec(RemoteFB__Port*                  pPort,
                   wstr_box_type                    ucs2_database_name,
                   RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                   protocol::set01::P_OP            operationID);
};//class RemoteFB__P11__ConnectHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
