////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__info_buffer.h
//! \brief   Определение конструкции информационного буфера.
//! \author  Kovalenko Dmitry
//! \date    29.04.2015.
#ifndef _remote_fb__info_buffer_H_
#define _remote_fb__info_buffer_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"
#include <structure/t_simple_buffer.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////

using RemoteFB__InfoBuffer
 =structure::t_typed_simple_buffer<unsigned char,RemoteFB__MemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
