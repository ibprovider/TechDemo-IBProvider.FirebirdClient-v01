////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__db__attach.cpp
//! \brief   Подключение к базе данных.
//! \author  Kovalenko Dmitry
//! \date    17.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__db__attach.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__connect_helper.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__AttachToDatabase

void RemoteFB__API_P13__AttachToDatabase::exec(ports::base_v01::RemoteFB__Port_BASE_v01* const pPort,
                                               wstr_box_type                             const ucs2_database_name,
                                               RemoteFB__ClientConnectBlock_v2&                clientConnectBlock)
{
 assert(pPort!=nullptr);

 assert(pPort->m_ID.is_null());

 //-----------------------------------------
 return RemoteFB__P13__ConnectHelper::exec
         (pPort,
          ucs2_database_name,
          clientConnectBlock,
          protocol::set02::op_attach);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
