////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__db__get_info.h
//! \brief   ѕолучение сведений о сервере и базе данных.
//! \author  Kovalenko Dmitry
//! \date    16.02.2015
#ifndef _remote_fb__api__db__get_info_H_
#define _remote_fb__api__db__get_info_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_client/remote_fb/remote_fb__info_buffer.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__GetDatabaseInfo

/// <summary>
///  ѕолучение сведений о сервере и базе данных.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__GetDatabaseInfo:public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  ѕолучение сведений о сервере и база данных.
  /// </summary>
  //! \param[in]  pData
  //!  Not null.
  //! \param[in]  Incornation
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  virtual void exec(RemoteFB__ConnectorData* pData,
                    unsigned short           Incornation,
                    protocol::P_USHORT       cItems,
                    const protocol::P_UCHAR* pItems,
                    RemoteFB__InfoBuffer&    ResultBuffer)=0;
};//class RemoteFB__API__GetDatabaseInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
