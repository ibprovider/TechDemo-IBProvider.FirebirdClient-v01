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
#include "source/db_obj/isc_base/isc_initialize_utils.h"
#include "source/db_obj/ib_base/ib_sys_data.h"

#include "source/external/icu/ibp_external__icu__loader_factory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

void RemoteFB__Connector::Helper__FinalInitialize__FB_02_05
                             (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
                              const cns_type&                                    /*cns*/)
{
 assert(pDsPropValues);
 assert(m_spData);
 assert(m_spData->GetPort());

 // 00.01 ----------------------------------------------------------------
 const external::icu::ICU__Loader::self_ptr
  spIcuLoader
   (external::icu::create_icu_loader
     (pDsPropValues));

 assert(spIcuLoader);

 // 00.02 ----------------------------------------------------------------
 const db_obj::t_db_charset_manager_v2_ptr
  spCsMng
   (isc_base::isc_create_charset_manager_v2
     (pDsPropValues,
      spIcuLoader,
      ib_base::g_ods_cs__ib04_0_0));

 assert(spCsMng);

 // 01.00. Overriding the error service ----------------------------------

 m_spData->RegService
  (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
   db_obj::dbms_fb::v02_5_0::create_svc__status_vector_utils(spCsMng));

 // 02.00. t_isc_xsqlda_v1_svc__blr01_builder service --------------------

 m_spData->RegService
  (db_obj::__db_guid<isc_base::t_isc_xsqlda_v1_svc__msg_blr01_builder>(),
   db_obj::dbms_fb::v02_5_0::create_xsqlda_v1_svc__msg01_blr01_builder());

 // 03.00. t_isc_xsqlda_v1_svc__msg_data_descrs_builder service ----------

 m_spData->RegService
  (db_obj::__db_guid<isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder>(),
   db_obj::dbms_fb::v02_5_0::create_xsqlda_v1_svc__msg01_data_descrs_builder());

 // 04.00. t_isc_xsqlda_v1_svc__msg_data service -------------------------

 m_spData->RegService
  (db_obj::__db_guid<isc_base::t_isc_xsqlda_v1_svc__msg_data>(),
   db_obj::dbms_fb::v02_5_0::create_xsqlda_v1_svc__msg_data());
}//Helper__FinalInitialize__FB_02_05

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
