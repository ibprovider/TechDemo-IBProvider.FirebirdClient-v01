////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__op__encoder.h
//! \brief   Набор утилит для упаковки операций
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__op__encoder_H_
#define _remote_fb__transmission__pset02__op__encoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__OpEncoder

/// <summary>
///  Набор утилит для упаковки операций
/// </summary>
class RemoteFB__PSET02__OpEncoder
{
 public:
  static void encode__op_connect
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_cont_auth
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_crypt
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_attach
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_create
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_detach
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_drop_database
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_info_database
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_transaction
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_rollback
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_rollback_retaining
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_commit
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_commit_retaining
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_prepare2
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_allocate_statement
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_free_statement
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_prepare_statement
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_info_sql
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  //симметричная версия
  static void encode__op_execute__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  //симметричная версия
  static void encode__op_execute2__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_fetch
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_open_blob2
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_create_blob2
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_close_blob
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_cancel_blob
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_info_blob
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_get_segment
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_put_segment
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_put_slice__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_get_slice
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_cancel
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_exec_immediate
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);

  static void encode__op_exec_immediate2__s
                (RemoteFB__PortOperationContext&    op_ctx,
                 const protocol::set02::PACKET_V02& packet);
};//class RemoteFB__PSET02__OpEncoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
