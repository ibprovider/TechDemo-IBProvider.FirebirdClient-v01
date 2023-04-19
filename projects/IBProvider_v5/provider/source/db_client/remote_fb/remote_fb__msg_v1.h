////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__msg_v1.h
//! \brief   The low-level presentation of row data.
//! \author  Kovalenko Dmitry
//! \date    29.03.2023
#ifndef _remote_fb__msg_v1_H_
#define _remote_fb__msg_v1_H_

#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
#include "source/structure/ibp_buffer_view.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__InMsg_v1

class RemoteFB__InMsg_v1
{
 public: //typedefs ------------------------------------------------------
  using byte_type=unsigned char;

  using descr_type=RemoteFB__MsgDataElementDescr;

 public:
  IBP_BufferView<const byte_type>  blr;
  IBP_BufferView<const descr_type> descrs;
  IBP_BufferView<const byte_type>  data;

  size_t data_align;

 public:
  RemoteFB__InMsg_v1()
   :data_align(1)
  {
  }
};//class RemoteFB__InMsg_v1

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__OutMsg_v1

class RemoteFB__OutMsg_v1
{
 public: //typedefs ------------------------------------------------------
  using byte_type=unsigned char;

  using descr_type=RemoteFB__MsgDataElementDescr;

 public:
  IBP_BufferView<const byte_type>  blr;
  IBP_BufferView<const descr_type> descrs;
  IBP_BufferView<byte_type>        data;

  size_t data_align;

 public:
  RemoteFB__OutMsg_v1()
   :data_align(1)
  {
  }
};//class RemoteFB__OutMsg_v1

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
