////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__db__drop.h
//! \brief   Удаление базы данных.
//! \author  Kovalenko Dmitry
//! \date    21.02.2015
#ifndef _remote_fb__api__db__drop_H_
#define _remote_fb__api__db__drop_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__DropDatabase

/// <summary>
///  Отключение от базы данных.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__DropDatabase:public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  Откат транзакции.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)=0;
};//class RemoteFB__API__DropDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
