////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__op__encoder.h
//! \brief   ����� ������ ��� �������� ��������
//! \author  Kovalenko Dmitry
//! \date    26.11.2014.
#ifndef _remote_fb__transmission__pset01__op__encoder_H_
#define _remote_fb__transmission__pset01__op__encoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__OpEncoder

/// <summary>
///  ����� ������ ��� �������� ��������
/// </summary>
class RemoteFB__PSET01__OpEncoder
{
 public:
  static void encode__op_connect
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_attach
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_create
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_detach
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_drop_database
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_trusted_auth
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_info_database
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_transaction
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_rollback
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_rollback_retaining
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_commit
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_commit_retaining
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_prepare2
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_allocate_statement
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_free_statement
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_prepare_statement
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_info_sql
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  //������������ ������
  static void encode__op_execute__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  //������������ ������
  static void encode__op_execute2__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_fetch
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_open_blob2
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_create_blob2
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_close_blob
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_cancel_blob
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_info_blob
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_get_segment
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_put_segment
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_put_slice__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_get_slice
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_cancel
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_exec_immediate
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);

  static void encode__op_exec_immediate2__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set01::PACKET_V01& packet);
};//class RemoteFB__PSET01__OpEncoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
