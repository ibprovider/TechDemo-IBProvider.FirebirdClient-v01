////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__op__info.h
//! \brief   Информационные утилиты для работы с сетевыми пакетами.
//! \author  Kovalenko Dmitry
//! \date    05.09.2015.
#ifndef _remote_fb__transmission__pset01__op__info_H_
#define _remote_fb__transmission__pset01__op__info_H_

#include <structure/t_common.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__OpInfo

/// <summary>
///  Информационные утилиты для работы с сетевыми пакетами.
/// </summary>
class RemoteFB__PSET01__OpInfo
{
 public:
  static size_t  get_size__op_fetch_response(size_t szMsg);
};//class RemoteFB__PSET01__OpInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
