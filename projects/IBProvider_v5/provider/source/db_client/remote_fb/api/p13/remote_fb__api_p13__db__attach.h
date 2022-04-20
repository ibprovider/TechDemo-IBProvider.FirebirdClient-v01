////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__db__attach.h
//! \brief   Подключение к базе данных.
//! \author  Kovalenko Dmitry
//! \date    17.08.2016
#ifndef _remote_fb__api_p13__db__attach_H_
#define _remote_fb__api_p13__db__attach_H_

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"
#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__AttachToDatabase

/// <summary>
///  Подключение к базе данных.
/// </summary>
class RemoteFB__API_P13__AttachToDatabase LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__API_P13__AttachToDatabase     self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstr_box             wstr_box_type;

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
  static void exec(ports::base_v01::RemoteFB__Port_BASE_v01* pPort,
                   wstr_box_type                             ucs2_database_name,
                   RemoteFB__ClientConnectBlock_v2&          clientConnectBlock);
};//class RemoteFB__API_P13__AttachToDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
