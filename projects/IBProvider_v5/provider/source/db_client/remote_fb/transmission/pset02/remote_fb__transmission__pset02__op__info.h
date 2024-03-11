////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__op__info.h
//! \brief   Информационные утилиты для работы с сетевыми пакетами.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#ifndef _remote_fb__transmission__pset02__op__info_H_
#define _remote_fb__transmission__pset02__op__info_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__OpInfo

/// <summary>
///  Информационные утилиты для работы с сетевыми пакетами.
/// </summary>
class RemoteFB__PSET02__OpInfo LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static size_t get_size__op_fetch_response(size_t szMsg);
};//class RemoteFB__PSET02__OpInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
