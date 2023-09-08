////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v04_0_0
//! \file    db_obj__dbms_fb__v04_0_0__xsqlda_v1_svc__msg_data.h
//! \brief   XSQLDA_V1 service for working with message data.
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#ifndef _db_obj__dbms_fb__v04_0_0__xsqlda_v1_svc__msg_data_H_
#define _db_obj__dbms_fb__v04_0_0__xsqlda_v1_svc__msg_data_H_

#include "source/db_obj/isc_base/isc_xsqlda_v1_svc__msg_data.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v04_0_0{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__v04_0_0
//! @{
////////////////////////////////////////////////////////////////////////////////
//class fb_v04_0_0__xsqlda_v1_svc__msg_data

/// <summary>
///  Service for the support of XDR-operations with XSQLDA_V1.
/// </summary>
class fb_v04_0_0__xsqlda_v1_svc__msg_data LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_STATIC(isc_base::t_isc_xsqlda_v1_svc__msg_data)
{
 private:
  using self_type=fb_v04_0_0__xsqlda_v1_svc__msg_data;

  fb_v04_0_0__xsqlda_v1_svc__msg_data(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  fb_v04_0_0__xsqlda_v1_svc__msg_data();

 ~fb_v04_0_0__xsqlda_v1_svc__msg_data();

 public:
  static db_obj::t_db_object_ptr create();

  //interface ------------------------------------------------------------
  virtual void Build_XSQLDA_MSG_DATA
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_buffer_type&     DataBuffer) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void Parse_XSQLDA_MSG_DATA
                             (const msg_data_descrs_type& MsgDescrs,
                              size_t                      cbMsgData,
                              const void*                 pMsgData,
                              const isc_api::XSQLDA_V1*   pXSQLDA) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static size_t Helper__Build_XSQLDA_MSG_DATA__CalcBufSize
                             (const isc_api::XSQLDA_V1* pXSQLDA);

  static size_t Helper__Build_XSQLDA_MSG_DATA__CalcBufSize
                             (const isc_api::XSQLVAR_V1* pXSQLVAR,
                              size_t                     szMsg);

  static void Helper__Build_XSQLDA_MSG_DATA__FillBuf
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_buffer_type&     DataBuffer);

  static size_t Helper__Build_XSQLDA_MSG_DATA__FillBuf
                             (const isc_api::XSQLVAR_V1* pXSQLVAR,
                              msg_data_buffer_type&      DataBuffer,
                              size_t                     offset);

 private:
  using msg_data_descr_type=msg_data_descrs_type::value_type;

  static void Helper__Parse_XSQLDA_MSG_DATA
                             (const msg_data_descr_type& MsgDescr,
                              size_t                     cbMsgData,
                              const void*                pvMsgData,
                              const isc_api::XSQLVAR_V1* pXSQLVAR);
 private:
  static self_type sm_Instance;
};//class fb_v04_0_0__xsqlda_v1_svc__msg_data

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v04_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
