////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__api_p10__db__attach.cpp
//! \brief   Подключение к базе данных.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p10/remote_fb__api_p10__db__attach.h"
#include "source/db_client/remote_fb/api/p10/remote_fb__p10__connect_helper.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P10__AttachToDatabase

void RemoteFB__API_P10__AttachToDatabase::exec
      (RemoteFB__Port*            const pPort,
       wstr_box_type              const ucs2_database_name,
       RemoteFB__ClientConnectBlock_v1& clientConnectBlock)
{
 assert(pPort!=nullptr);
 assert(pPort->get_protocol_version()==protocol::FB_PROTOCOL_VERSION10);

 assert(pPort->m_ID.is_null());

 //-----------------------------------------
 return RemoteFB__P10__ConnectHelper::exec
         (pPort,
          ucs2_database_name,
          clientConnectBlock,
          protocol::set01::op_attach);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
