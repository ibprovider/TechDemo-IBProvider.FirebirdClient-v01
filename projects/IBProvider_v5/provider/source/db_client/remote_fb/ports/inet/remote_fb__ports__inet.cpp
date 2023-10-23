////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__inet.cpp
//! \brief   Реализация удаленного порта для работы через TCP/IP.
//! \author  Kovalenko Dmitry
//! \date    28.10.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/inet/remote_fb__ports__inet.h"
#include "source/db_client/remote_fb/transmission/pset01/p_init/remote_fb__transmission__pset01__p_init__packet_stream.h"
#include "source/db_client/remote_fb/transmission/pset02/p13_init/remote_fb__transmission__pset02__p13_init__packet_stream.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_INET

RemoteFB__Port_INET::RemoteFB__Port_INET(streams::inet::RemoteFB__INET_Socket* const pSocket,
                                         transmission::RemoteFB__PacketStream* const pPacketStream)
 :inherited(pSocket,
            pPacketStream)
 ,m_spProvider(pSocket->m_spProvider.not_null_ptr())
{
 assert(m_spProvider);

 //! \todo
 //!  Set PortFlag__dummy_pckt_set flag?
}//RemoteFB__Port_INET

//------------------------------------------------------------------------
RemoteFB__Port_INET::~RemoteFB__Port_INET()
{
}//~RemoteFB__Port_INET

//------------------------------------------------------------------------
RemoteFB__Port_INET::self_ptr RemoteFB__Port_INET::Create_PSET01
                                           (streams::inet::RemoteFB__INET_Socket* const pSocket)
{
 assert(pSocket!=nullptr);

 return lib::structure::not_null_ptr
         (new self_type
           (pSocket,
            &transmission::pset01::p_init::RemoteFB__PSET01__P_INIT__PacketStream::Instance));
}//Create_PSET01

//------------------------------------------------------------------------
RemoteFB__Port_INET::self_ptr RemoteFB__Port_INET::Create_PSET02
                                           (streams::inet::RemoteFB__INET_Socket* const pSocket)
{
 assert(pSocket!=nullptr);

 return lib::structure::not_null_ptr
         (new self_type
           (pSocket,
            &transmission::pset02::p13_init::RemoteFB__PSET02__P13_INIT__PacketStream::Instance));
}//Create_PSET02

//internal services ------------------------------------------------------
protocol::P_LONG RemoteFB__Port_INET::internal__htonl(const protocol::P_LONG* const pv)const
{
 assert(pv);
 assert(m_spProvider);

 using ibp::os::win32::winsock::API::WinSock__u_long;

 assert(pv!=nullptr);
 assert_s(sizeof(WinSock__u_long)==sizeof(*pv));

 const WinSock__u_long
  x=m_spProvider->m_htonl.point()(*reinterpret_cast<const WinSock__u_long*>(pv));

 return x;
}//internal__htonl

//------------------------------------------------------------------------
protocol::P_LONG RemoteFB__Port_INET::internal__ntohl(const protocol::P_LONG* const pv)const
{
 assert(pv);
 assert(m_spProvider);

 using ibp::os::win32::winsock::API::WinSock__u_long;

 assert(pv!=nullptr);
 assert_s(sizeof(*pv)==sizeof(WinSock__u_long));

 const WinSock__u_long
  x=m_spProvider->m_ntohl.point()(*reinterpret_cast<const WinSock__u_long*>(pv));

 return x;
}//internal__ntohl

////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
