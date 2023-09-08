////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_xsqlda_v1_svc__msg_data_descrs_builder.h
//! \brief   Service for the support of input/output operations with XSQLDA_V1.
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#ifndef _isc_xsqlda_v1_svc__msg_data_descrs_builder_
#define _isc_xsqlda_v1_svc__msg_data_descrs_builder_

#include "source/db_obj/isc_base/isc_msg_data_element_descrs.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_xsqlda_v1_svc__msg_data_descrs_builder

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_isc_xsqlda_v1_svc__msg_data_descrs_builder
 :public db_obj::t_db_smart_interface
{
 public:
  using msg_data_descrs_type
   =t_isc_msg_data_element_descrs;

 public:
  virtual void Build_XSQLDA_MSG_DATA_DESCRS
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_descrs_type&     MsgDescrs,
                              size_t*                   pResult_DataSize,
                              size_t*                   pResult_DataAlign)=0;
};//class t_isc_xsqlda_v1_svc__msg_data_descrs_builder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
