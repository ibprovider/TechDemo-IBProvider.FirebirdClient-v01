////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__api_p11__db__attach.h
//! \brief   Подключение к базе данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#ifndef _remote_fb__api_p11__db__attach_H_
#define _remote_fb__api_p11__db__attach_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p11
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P11__AttachToDatabase

/// <summary>
///  Подключение к базе данных.
/// </summary>
class RemoteFB__API_P11__AttachToDatabase LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__API_P11__AttachToDatabase;

 public: //typedefs ------------------------------------------------------
  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  /// <summary>
  ///  Подключение к базе данных.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //!  Расположение или имя базы данных.
  //! \param[in] clientConnectBlock
  //!  Контекст операции подключения к базе данных.
  static void exec(RemoteFB__Port*                   pPort,
                   wstr_box_type                     ucs2_database_name,
                   RemoteFB__ClientConnectBlock_v1&  clientConnectBlock);
};//class RemoteFB__API_P11__AttachToDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
