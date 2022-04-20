////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_winsock__api.h
//! \brief   Описание Windows Socket API
//! \author  Kovalenko Dmitry
//! \date    10.11.2014
#ifndef _ibp_os_win32_winsock__api_H_
#define _ibp_os_win32_winsock__api_H_

#include <winsock2.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace winsock{namespace API{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//Base types

typedef SOCKET                              WinSock__SOCKET;

typedef WSAData                             WinSock__WSAData;

typedef LPWSADATA                           WinSock__LPWSADATA;

typedef u_short                             WinSock__u_short;

typedef u_long                              WinSock__u_long;

typedef struct sockaddr                     WinSock__sockaddr;

typedef struct in_addr                      WinSock__in_addr;

typedef struct hostent                      WinSock__hostent;

typedef struct servent                      WinSock__servent;

typedef struct addrinfo                     WinSock__addrinfo;

////////////////////////////////////////////////////////////////////////////////

static WinSock__SOCKET WinSock__INVALID_SOCKET=INVALID_SOCKET;

////////////////////////////////////////////////////////////////////////////////
//Error codes

static const int WinSock__SOCKET_ERROR=SOCKET_ERROR;

static const int WinSock__WSATYPE_NOT_FOUND=WSATYPE_NOT_FOUND;

////////////////////////////////////////////////////////////////////////////////

static const WinSock__u_long WinSock__INADDR_ANY       =INADDR_ANY       ;
static const WinSock__u_long WinSock__INADDR_LOOPBACK  =INADDR_LOOPBACK  ;
static const WinSock__u_long WinSock__INADDR_BROADCAST =INADDR_BROADCAST ;
static const WinSock__u_long WinSock__INADDR_NONE      =INADDR_NONE      ;

////////////////////////////////////////////////////////////////////////////////
//Socket Types

static const int WinSock__SOCK_STREAM    = SOCK_STREAM    ; /* stream socket */
static const int WinSock__SOCK_DGRAM     = SOCK_DGRAM     ; /* datagram socket */
static const int WinSock__SOCK_RAW       = SOCK_RAW       ; /* raw-protocol interface */
static const int WinSock__SOCK_RDM       = SOCK_RDM       ; /* reliably-delivered message */
static const int WinSock__SOCK_SEQPACKET = SOCK_SEQPACKET ; /* sequenced packet stream */

////////////////////////////////////////////////////////////////////////////////
//Address families.

static const int WinSock__AF_UNSPEC    = AF_UNSPEC    ; /* unspecified */
static const int WinSock__AF_UNIX      = AF_UNIX      ; /* local to host (pipes, portals) */
static const int WinSock__AF_INET      = AF_INET      ; /* internetwork: UDP, TCP, etc. */
static const int WinSock__AF_IMPLINK   = AF_IMPLINK   ; /* arpanet imp addresses */
static const int WinSock__AF_PUP       = AF_PUP       ; /* pup protocols: e.g. BSP */
static const int WinSock__AF_CHAOS     = AF_CHAOS     ; /* mit CHAOS protocols */
static const int WinSock__AF_IPX       = AF_IPX       ; /* IPX and SPX */
static const int WinSock__AF_NS        = AF_NS        ; /* XEROX NS protocols */
static const int WinSock__AF_ISO       = AF_ISO       ; /* ISO protocols */
static const int WinSock__AF_OSI       = AF_OSI       ; /* OSI is ISO */
static const int WinSock__AF_ECMA      = AF_ECMA      ; /* european computer manufacturers */
static const int WinSock__AF_DATAKIT   = AF_DATAKIT   ; /* datakit protocols */
static const int WinSock__AF_CCITT     = AF_CCITT     ; /* CCITT protocols, X.25 etc */
static const int WinSock__AF_SNA       = AF_SNA       ; /* IBM SNA */
static const int WinSock__AF_DECnet    = AF_DECnet    ; /* DECnet */
static const int WinSock__AF_DLI       = AF_DLI       ; /* Direct data link interface */
static const int WinSock__AF_LAT       = AF_LAT       ; /* LAT */
static const int WinSock__AF_HYLINK    = AF_HYLINK    ; /* NSC Hyperchannel */
static const int WinSock__AF_APPLETALK = AF_APPLETALK ; /* AppleTalk */
static const int WinSock__AF_NETBIOS   = AF_NETBIOS   ; /* NetBios-style addresses */
static const int WinSock__AF_VOICEVIEW = AF_VOICEVIEW ; /* VoiceView */
static const int WinSock__AF_FIREFOX   = AF_FIREFOX   ; /* FireFox */
static const int WinSock__AF_UNKNOWN1  = AF_UNKNOWN1  ; /* Somebody is using this! */
static const int WinSock__AF_BAN       = AF_BAN       ; /* Banyan */
static const int WinSock__AF_ATM       = AF_ATM       ; // Native ATM Services
static const int WinSock__AF_INET6     = AF_INET6     ; // Internetwork Version 6
static const int WinSock__AF_CLUSTER   = AF_CLUSTER   ; // Microsoft Wolfpack
static const int WinSock__AF_12844     = AF_12844     ; // IEEE 1284.4 WG AF
static const int WinSock__AF_IRDA      = AF_IRDA      ; // IrDA
static const int WinSock__AF_NETDES    = AF_NETDES    ; // Network Designers OSI & gateway

////////////////////////////////////////////////////////////////////////////////
//Protocols. The IPv6 defines are specified in RFC 2292.

static const int WinSock__IPPROTO_TCP       = IPPROTO_TCP;

////////////////////////////////////////////////////////////////////////////////

static const int WinSock__AI_ADDRCONFIG     = AI_ADDRCONFIG;


////////////////////////////////////////////////////////////////////////////////
//Function prototypes

typedef int (PASCAL FAR WinSock__fn__WSAStartup)
         (/*_In_*/  WORD               wVersionRequired,
          /*_Out_*/ WinSock__LPWSADATA lpWSAData);

typedef int (PASCAL FAR WinSock__fn__WSACleanup)
         (void);

typedef int (PASCAL FAR WinSock__fn__WSAGetLastError)
         (void);

typedef int (PASCAL FAR WinSock__fn__WSAAddressToStringA)
         (/*_In_reads_bytes_(dwAddressLength)*/ LPSOCKADDR          lpsaAddress,
          /*_In_*/                              DWORD               dwAddressLength,
          /*_In_opt_*/                          LPWSAPROTOCOL_INFOA lpProtocolInfo,
          /*_Out_writes_to_(*lpdwAddressStringLength,*lpdwAddressStringLength)*/ LPSTR lpszAddressString,
          /*_Inout_*/                           LPDWORD             lpdwAddressStringLength);

typedef WinSock__SOCKET (PASCAL FAR WinSock__fn__socket)
         (/*_In_*/ int af,
          /*_In_*/ int type,
          /*_In_*/ int protocol);

typedef int (PASCAL FAR WinSock__fn__closesocket)
         (/*_In_*/ WinSock__SOCKET s);

typedef int (PASCAL FAR WinSock__fn__setsockopt)
         (/*_In_*/ WinSock__SOCKET s,
          /*_In_*/ int             level,
          /*_In_*/ int             optname,
          /*_In_reads_bytes_opt_(optlen)*/ const char FAR *optval,
          /*_In_*/ int             optlen);

typedef int (PASCAL FAR WinSock__fn__connect)
         (/*_In_*/ WinSock__SOCKET s,
          /*_In_reads_bytes_(namelen)*/ const WinSock__sockaddr FAR *name,
          /*_In_*/ int             namelen);

typedef int (PASCAL FAR WinSock__fn__send)
         (/*_In_*/ WinSock__SOCKET s,
          /*_In_reads_bytes_(len)*/ const char FAR *buf,
          /*_In_*/ int             len,
          /*_In_*/ int             flags);

typedef int (PASCAL FAR WinSock__fn__recv)
         (/*_In_*/ WinSock__SOCKET s,
          /*_Out_writes_bytes_to_(len, return) __out_data_source(NETWORK)*/ char FAR * buf,
          /*_In_*/ int             len,
          /*_In_*/ int             flags);

typedef WinSock__u_short (PASCAL FAR WinSock__fn__ntohs)
         (/*_In_*/ WinSock__u_short netshort);

typedef WinSock__u_long (PASCAL FAR WinSock__fn__ntohl)
         (/*_In_*/ WinSock__u_long netlong);

typedef WinSock__u_short (PASCAL FAR WinSock__fn__htons)
         (/*_In_*/ WinSock__u_short hostshort);

typedef WinSock__u_long (PASCAL FAR WinSock__fn__htonl)
         (/*_In_*/ WinSock__u_long hostlong);

typedef unsigned long (PASCAL FAR WinSock__fn__inet_addr)
         (/*_In_z_*/ const char FAR *cp);

typedef WinSock__hostent FAR* (PASCAL FAR WinSock__fn__gethostbyname)
         (/*_In_z_*/ const char FAR *name);

typedef int (PASCAL FAR WinSock__fn__gethostname)
         (/*_Out_writes_bytes_to_(namelen, return)*/ char FAR *name,
          /*_In_*/ int                                         namelen);

typedef WinSock__servent FAR* (PASCAL FAR WinSock__fn__getservbyname)
         (/*_In_z_*/ const char FAR *name,
          /*_In_z_*/ const char FAR *proto);

typedef void (PASCAL FAR WinSock__fn__freeaddrinfo)
         (/*IN*/ WinSock__addrinfo* ai);

typedef int (PASCAL FAR WinSock__fn__getaddrinfo)
         (/*__in */ const char*               nodename,
          /*__in */ const char*               servname,
          /*__in */ const WinSock__addrinfo*  hints,
          /*__out*/ WinSock__addrinfo**       res);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms API*/}/*nms winsock*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif