////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__factories.h
//! \brief   Объявление фабрик сервисов подключения.
//! \author  Kovalenko Dmitry
//! \date    11.08.2016
#ifndef _db_obj__dbms_fb__v03_0_0__factories_H_
#define _db_obj__dbms_fb__v03_0_0__factories_H_

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_object_ptr
 create_svc__status_vector_utils();

////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif