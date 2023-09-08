////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_xsqlda_v1_svc__msg_blr01_builder.h
//! \brief   XSQLDA_V1 service for building BLR01.
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#ifndef _isc_xsqlda_v1_svc__msg_blr01_builder_
#define _isc_xsqlda_v1_svc__msg_blr01_builder_

#include "source/db_obj/isc_base/isc_msg_blr01_buffer.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_xsqlda_v1_svc__msg_blr01_builder

/// <summary>
///  XSQLDA_V1 service for building BLR01.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_isc_xsqlda_v1_svc__msg_blr01_builder
 :public db_obj::t_db_smart_interface
{
 public:
  using msg_blr_buffer_type
   =t_isc_msg_blr01_buffer;

 public:
  virtual void Build_XSQLDA_MSG_BLR
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_blr_buffer_type&      BlrBuffer)=0;
};//class t_isc_xsqlda_v1_svc__msg_blr01_builder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
