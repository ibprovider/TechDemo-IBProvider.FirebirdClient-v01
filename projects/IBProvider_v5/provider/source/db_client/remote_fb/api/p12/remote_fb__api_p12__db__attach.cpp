////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__db__attach.cpp
//! \brief   ����������� � ���� ������.
//! \author  Kovalenko Dmitry
//! \date    22.11.2014
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__attach.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__connect_helper.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__AttachToDatabase

void RemoteFB__API_P12__AttachToDatabase::exec
      (RemoteFB__Port*            const pPort,
       wstr_box_type              const ucs2_database_name,
       RemoteFB__ClientConnectBlock_v1& clientConnectBlock)
{
 assert(pPort!=nullptr);

 assert(pPort->m_ID.is_null());

 //-----------------------------------------
 return RemoteFB__P12__ConnectHelper::exec
         (pPort,
          ucs2_database_name,
          clientConnectBlock,
          protocol::set01::op_attach);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
