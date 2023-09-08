////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_xsqlda_v1_svc__msg_data.h
//! \brief   XSQLDA_V1 service for working with message data.
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#ifndef _isc_xsqlda_v1_svc__msg_data_
#define _isc_xsqlda_v1_svc__msg_data_

#include "source/db_obj/isc_base/isc_msg_data_element_descrs.h"
#include "source/db_obj/isc_base/isc_msg_data_buffer.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_xsqlda_v1_svc__msg_data

/// <summary>
///  XSQLDA_V1 service for working with message data.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_isc_xsqlda_v1_svc__msg_data
 :public db_obj::t_db_smart_interface
{
 public:
  using msg_data_descrs_type
   =t_isc_msg_data_element_descrs;

  using msg_data_buffer_type
   =t_isc_msg_data_buffer;

 public:
  /// <summary>
  ///  Building the MSG-buffer with the data of XSQLDA structure.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] DataBuffer
  virtual void Build_XSQLDA_MSG_DATA
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_buffer_type&     DataBuffer)=0;

  /// <summary>
  ///  Loading the data of MSG-buffer into XSQLDA structure.
  /// </summary>
  //! \param[in]     MsgDescrs
  //! \param[in]     cbMsgData
  //! \param[in]     pMsgData
  //! \param[in,out] pXSQLDA
  //!  It is the pointer of correct structure for getting data. It may be NULL or empty.
  //!
  //!  The pXSQLDA is not changed. There are changing only the pointed data of XSQLVAR-elements.
  //!
  //! \attention
  //!  The structure of MSG-buffer must be consistent with pXSQLDA.
  virtual void Parse_XSQLDA_MSG_DATA
                             (const msg_data_descrs_type& MsgDescrs,
                              size_t                      cbMsgData,
                              const void*                 pMsgData,
                              const isc_api::XSQLDA_V1*   pXSQLDA)=0;
};//class t_isc_xsqlda_v1_svc__msg_data

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
