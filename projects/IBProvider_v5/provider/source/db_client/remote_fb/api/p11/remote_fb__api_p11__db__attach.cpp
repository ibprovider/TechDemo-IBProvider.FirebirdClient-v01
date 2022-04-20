////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__api_p11__db__attach.cpp
//! \brief   Подключение к базе данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p11/remote_fb__api_p11__db__attach.h"
#include "source/db_client/remote_fb/api/p11/remote_fb__p11__connect_helper.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P11__AttachToDatabase

void RemoteFB__API_P11__AttachToDatabase::exec
      (RemoteFB__Port*            const pPort,
       wstr_box_type              const ucs2_database_name,
       RemoteFB__ClientConnectBlock_v1& clientConnectBlock)
{
 assert(pPort!=nullptr);

 assert(pPort->m_ID.is_null());

 //-----------------------------------------
 return RemoteFB__P11__ConnectHelper::exec
         (pPort,
          ucs2_database_name,
          clientConnectBlock,
          protocol::set01::op_attach);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
