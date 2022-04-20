////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__streams__inet__types.h
//! \brief   Типы данных для работы с TCP/IP соединением.
//! \author  Kovalenko Dmitry
//! \date    30.10.2014.
#ifndef _remote_fb__ports__streams__inet__types_H_
#define _remote_fb__ports__streams__inet__types_H_

#include <structure/t_common.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__inet
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__INET_Types

/// <summary>
///  Типы данных для работы с TCP/IP соединением.
/// </summary>
class RemoteFB__INET_Types
{
 public:
  //! \brief
  //!  Тип для представления номера порта
  typedef unsigned short                    port_number_type;
};//class RemoteFB__INET_Types

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
