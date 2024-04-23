////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v04_0_0
//! \file    db_obj__dbms_fb__v04_0_0__factories.h
//! \brief   Объявление фабрик сервисов подключения.
//! \author  Kovalenko Dmitry
//! \date    22.03.2023
#ifndef _db_obj__dbms_fb__v04_0_0__factories_H_
#define _db_obj__dbms_fb__v04_0_0__factories_H_

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v04_0_0{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_object_ptr
 create_svc__status_vector_utils(db_obj::t_db_charset_manager_v2* const pCsMng);

//------------------------------------------------------------------------

db_obj::t_db_object_ptr
 create_svc__fb040_ts_with_tz_services();

//------------------------------------------------------------------------

db_obj::t_db_object_ptr
 create_svc__fb040_tz_names();

//------------------------------------------------------------------------

db_obj::t_db_object_ptr
 create_svc__timezone_services();

//------------------------------------------------------------------------

db_obj::t_db_object_ptr
 create_xsqlda_v1_svc__msg01_blr01_builder();

//------------------------------------------------------------------------

db_obj::t_db_object_ptr
 create_xsqlda_v1_svc__msg01_data_descrs_builder();

//------------------------------------------------------------------------

db_obj::t_db_object_ptr
 create_xsqlda_v1_svc__msg_data();

////////////////////////////////////////////////////////////////////////////////
}/*nms v04_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif