////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector__init_fb_03_00.cpp
//! \brief   The initialization of connection for Firebird 3.0 server.
//! \author  Kovalenko Dmitry
//! \date    01.05.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector.h"
#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__factories.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

void RemoteFB__Connector::Helper__FinalInitialize__FB_03_00(const cns_type& /*cns*/)
{
 assert(m_spData);
 assert(m_spData->GetPort());

 // 01.00. Overriding the error service ----------------------------------

 m_spData->RegService
  (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
   db_obj::dbms_fb::v03_0_0::create_svc__status_vector_utils());

 // 02.00. t_isc_xsqlda_v1_svc__blr01_builder service --------------------

 m_spData->RegService
  (db_obj::__db_guid<isc_base::t_isc_xsqlda_v1_svc__msg_blr01_builder>(),
   db_obj::dbms_fb::v03_0_0::create_xsqlda_v1_svc__msg01_blr01_builder());

 // 03.00. t_isc_xsqlda_v1_svc__msg_data_descrs_builder service ----------

 m_spData->RegService
  (db_obj::__db_guid<isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder>(),
   db_obj::dbms_fb::v03_0_0::create_xsqlda_v1_svc__msg01_data_descrs_builder());

 // 04.00. t_isc_xsqlda_v1_svc__msg_data service -------------------------

 m_spData->RegService
  (db_obj::__db_guid<isc_base::t_isc_xsqlda_v1_svc__msg_data>(),
   db_obj::dbms_fb::v03_0_0::create_xsqlda_v1_svc__msg_data());
}//Helper__FinalInitialize__FB_03_00

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
