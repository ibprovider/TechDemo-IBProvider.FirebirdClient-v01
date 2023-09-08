////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v02_5_0
//! \file    db_obj__dbms_fb__v02_5_0__xsqlda_v1_svc__msg_data.cpp
//! \brief   XSQLDA_V1 service for working with message data.
//! \author  Kovalenko Dmitry
//! \date    23.08.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__xsqlda_v1_svc__msg_data.h"
#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__factories.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v02_5_0{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_object_ptr create_xsqlda_v1_svc__msg_data()
{
 return fb_v02_5_0__xsqlda_v1_svc__msg_data::create();
}//create_xsqlda_v1_svc__msg_data

////////////////////////////////////////////////////////////////////////////////
//class fb_v02_5_0__xsqlda_v1_svc__msg_data

fb_v02_5_0__xsqlda_v1_svc__msg_data
 fb_v02_5_0__xsqlda_v1_svc__msg_data::sm_Instance;

//------------------------------------------------------------------------
fb_v02_5_0__xsqlda_v1_svc__msg_data::fb_v02_5_0__xsqlda_v1_svc__msg_data()
{
}//fb_v02_5_0__xsqlda_v1_svc__msg_data

//------------------------------------------------------------------------
fb_v02_5_0__xsqlda_v1_svc__msg_data::~fb_v02_5_0__xsqlda_v1_svc__msg_data()
{
}//~fb_v02_5_0__xsqlda_v1_svc__msg_data

//------------------------------------------------------------------------
db_obj::t_db_object_ptr fb_v02_5_0__xsqlda_v1_svc__msg_data::create()
{
 return lib::structure::not_null_ptr(&sm_Instance);
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms v02_5_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
