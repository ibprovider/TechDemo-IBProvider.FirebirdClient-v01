////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__streams__inet__static_cfg.cpp
//! \brief   Настройки для TCP/IP соединения с сервером.
//! \author  Kovalenko Dmitry
//! \date    30.10.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__static_cfg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__INET_StaticCfg

const t_ibp_char* const RemoteFB__INET_StaticCfg::c_WinSockDllName
 =IBP_T("Ws2_32.dll");

const char* const RemoteFB__INET_StaticCfg::c_FB_SERVICE_NAME
 ="gds_db";

const RemoteFB__INET_StaticCfg::port_number_type RemoteFB__INET_StaticCfg::c_FB_SERVICE_PORT
 =3050;

////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
