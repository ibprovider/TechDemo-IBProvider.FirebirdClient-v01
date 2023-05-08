////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector__init_fb_02_05.cpp
//! \brief   The initialization of connection for Firebird 2.5 server.
//! \author  Kovalenko Dmitry
//! \date    01.05.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector.h"
#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__factories.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

void RemoteFB__Connector::Helper__FinalInitialize__FB_02_05(const cns_type& /*cns*/)
{
 assert(m_spData);
 assert(m_spData->GetPort());

 // 01.00. Overriding the error service ----------------------------------

 m_spData->RegService
  (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
   db_obj::dbms_fb::v02_5_0::create_svc__status_vector_utils());
}//Helper__FinalInitialize__FB_02_05

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
