////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__op_svc__stmt_execute_data_v2.h
//! \brief   The block with a statement execution data (v2).
//! \author  Kovalenko Dmitry
//! \date    30.03.2023
#ifndef _remote_fb__op_svc__stmt_execute_data_v2_H_
#define _remote_fb__op_svc__stmt_execute_data_v2_H_

#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/structure/ibp_buffer_view.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__OpSvc__StmtExecuteData_v2

/// <summary>
///  The block with a statement execution data (v2).
/// </summary>
class RemoteFB__OpSvc__StmtExecuteData_v2 LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__SmartInterface)
{
 private:
  using self_type=RemoteFB__OpSvc__StmtExecuteData_v2;

  RemoteFB__OpSvc__StmtExecuteData_v2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using byte_type=unsigned char;

 public:
  /// <summary>
  ///  The identifier of service.
  /// </summary>
  static const GUID svcID;

 public:
  IBP_BufferView<const byte_type>                     InMsg_BLR;
  IBP_BufferView<const RemoteFB__MsgDataElementDescr> InMsg_DATA_DESCRS;
  IBP_BufferView<const byte_type>                     InMsg_DATA;
  IBP_BufferView<const byte_type>                     InMsg_NULLS;

  IBP_BufferView<const byte_type>                     OutMsg_BLR;
  IBP_BufferView<const RemoteFB__MsgDataElementDescr> OutMsg_DATA_DESCRS;
  IBP_BufferView<byte_type>                           OutMsg_DATA;
  IBP_BufferView<byte_type>                           OutMsg_NULLS;

 public:
  RemoteFB__OpSvc__StmtExecuteData_v2();

 ~RemoteFB__OpSvc__StmtExecuteData_v2();
};//class RemoteFB__OpSvc__StmtExecuteData_v2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
