////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__op__encoder.h
//! \brief   Набор утилит для упаковки операций
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__transmission__pset02__p13__op__encoder_H_
#define _remote_fb__transmission__pset02__p13__op__encoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02__p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__OpEncoder

/// <summary>
///  Набор утилит для упаковки операций.
/// </summary>
class RemoteFB__PSET02__P13__OpEncoder LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using op_ctx_type=RemoteFB__PortOperationContext;

 public:
  //асимметричная версия
  static void encode__op_execute__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set02::PACKET_V02&  packet);

  //асимметричная версия
  static void encode__op_execute2__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set02::PACKET_V02&  packet);

  //асимметричная версия
  static void encode__op_put_slice__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set02::PACKET_V02&  packet);

  //асимметричная версия
  static void encode__op_exec_immediate2__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set02::PACKET_V02&  packet);
};//class RemoteFB__PSET02__P13__OpEncoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
