////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__op__encoder.h
//! \brief   Набор утилит для упаковки операций
//! \author  Kovalenko Dmitry
//! \date    10.05.2015.
#ifndef _remote_fb__transmission__pset01__p12__op__encoder_H_
#define _remote_fb__transmission__pset01__p12__op__encoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01__p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__OpEncoder

/// <summary>
///  Набор утилит для упаковки операций.
/// </summary>
class RemoteFB__PSET01__P12__OpEncoder
{
 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__PortOperationContext    op_ctx_type;

 public:
  //асимметричная версия
  static void encode__op_execute__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set01::PACKET_V01&  packet);

  //асимметричная версия
  static void encode__op_execute2__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set01::PACKET_V01&  packet);

  //асимметричная версия
  static void encode__op_put_slice__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set01::PACKET_V01&  packet);

  //асимметричная версия
  static void encode__op_exec_immediate2__a
                (op_ctx_type&                        op_ctx,
                 const protocol::set01::PACKET_V01&  packet);
};//class RemoteFB__PSET01__P12__OpEncoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
