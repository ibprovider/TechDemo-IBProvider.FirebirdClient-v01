////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__flags.h
//! \brief   ��������������� ����� ��� ���������� �������.
//! \author  Kovalenko Dmitry
//! \date    22.04.2015.
#ifndef _remote_fb__flags_H_
#define _remote_fb__flags_H_

#include "source/structure/ibp_flags.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Flags

/// <summary>
///  ��������������� ����� ��� ���������� �������.
/// </summary>
template<typename T>
using RemoteFB__Flags=IBP_Flags<T>;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
