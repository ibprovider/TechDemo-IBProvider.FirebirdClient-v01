////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg01_blr01_builder.h
//! \brief   XSQLDA_V1 service for building MSG BLR01 [V01].
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#ifndef _db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg01_blr01_builder_H_
#define _db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg01_blr01_builder_H_

#include "source/db_obj/isc_base/isc_xsqlda_v1_svc__msg_blr01_builder.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__v03_0_0
//! @{
////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder

/// <summary>
///  XSQLDA_V1 service for building MSG BLR01 [V01].
/// </summary>
//!  This MSG BLR builder [v01] uses the following types:
//!  - VARYING: ibp_isc_blr_dtype__varying
//!  - TEXT   : ibp_isc_blr_dtype__text  
//!  - BLOB   : ibp_isc_blr_dtype__quad
class fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_STATIC(isc_base::t_isc_xsqlda_v1_svc__msg_blr01_builder)
{
 private:
  using self_type=fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder;

  fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder();

 ~fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder();

 public:
  static db_obj::t_db_object_ptr create();

  //interface ------------------------------------------------------------
  virtual void Build_XSQLDA_MSG_BLR
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_blr_buffer_type&      BlrBuffer) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static size_t Helper__Build_XSQLDA_MSG_BLR__CalcBufSize
                             (const isc_api::XSQLDA_V1* pXSQLDA);

  static void Helper__Build_XSQLDA_MSG_BLR__FillBuf
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_blr_buffer_type&      MsgBlrBuffer);

 private:
  static self_type sm_Instance;
};//class fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
