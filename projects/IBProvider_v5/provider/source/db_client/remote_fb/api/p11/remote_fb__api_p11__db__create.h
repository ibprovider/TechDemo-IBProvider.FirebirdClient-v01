////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__api_p11__db__create.h
//! \brief   Создание базы данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#ifndef _remote_fb__api_p11__db__create_H_
#define _remote_fb__api_p11__db__create_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P11__CreateDatabase

/// <summary>
///  Создание базы данных.
/// </summary>
class RemoteFB__API_P11__CreateDatabase LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__API_P11__CreateDatabase        self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstr_box              wstr_box_type;

 public:
  /// <summary>
  ///  Создание базы данных.
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
};//class RemoteFB__API_P11__CreateDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
