////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__streams__inet__socket.cpp
//! \brief   Управляющий объект для сокета TCP/IP-соединения.
//! \author  Kovalenko Dmitry
//! \date    07.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__socket.h"
#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__static_cfg.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_fix_stream.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__INET_Socket::tag_addrinfo_sptr

/// <summary>
///  Класс автоматизации освобождения структуры addrinfo
/// </summary>
class RemoteFB__INET_Socket::tag_addrinfo_sptr
{
 private:
  typedef tag_addrinfo_sptr                 self_type;

  tag_addrinfo_sptr(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pProvider
  //!  Not null.
  tag_addrinfo_sptr(winsock::t_winsock__provider* pProvider);

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~tag_addrinfo_sptr();

  //----------------------------------------------------------------------

  /// <summary>
  ///  Получение указателя на m_ptr.
  /// </summary>
  ///  Используется для установки значения m_ptr
  winsock::API::WinSock__addrinfo** pptr();

  /// <summary>
  ///  Получение значения m_ptr
  /// </summary>
  const winsock::API::WinSock__addrinfo* ptr()const;

 private:
  /// Провайдер WinSock. Not null.
  const winsock::t_winsock__provider::self_ptr m_spProvider;

  /// Указатель на описатель адреса
  winsock::API::WinSock__addrinfo* m_ptr;
};//class RemoteFB__INET_Socket::tag_addrinfo_sptr

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__INET_Socket::tag_addrinfo_sptr

RemoteFB__INET_Socket::tag_addrinfo_sptr::tag_addrinfo_sptr(winsock::t_winsock__provider* const pProvider)
 :m_spProvider(structure::not_null_ptr(pProvider))
 ,m_ptr(nullptr)
{
 assert(m_spProvider);

 m_spProvider->m_freeaddrinfo.point(); //throw
}//tag_addrinfo_sptr

//------------------------------------------------------------------------
RemoteFB__INET_Socket::tag_addrinfo_sptr::~tag_addrinfo_sptr()
{
 assert(m_spProvider);

 //Освобождение указателя m_ptr

 if(m_ptr)
 {
  winsock::API::WinSock__addrinfo* const tmp=m_ptr;

  m_ptr=nullptr;

  m_spProvider->m_freeaddrinfo.point()(tmp);
 }//if m_ptr
}//~tag_addrinfo_sptr

//------------------------------------------------------------------------
winsock::API::WinSock__addrinfo**
 RemoteFB__INET_Socket::tag_addrinfo_sptr::pptr()
{
 //! \attention
 //!  Допускаем только однократную установку указателя
 assert(m_ptr==nullptr);

 return &m_ptr;
}//pptr

//------------------------------------------------------------------------
const winsock::API::WinSock__addrinfo*
 RemoteFB__INET_Socket::tag_addrinfo_sptr::ptr()const
{
 return m_ptr;
}//ptr

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__INET_Socket

RemoteFB__INET_Socket::RemoteFB__INET_Socket(winsock::t_winsock__provider* const pProvider,
                                             size_t                        const cbReadBuf,
                                             byte_type*                    const pReadBuf,
                                             void*                         const pWriteBufBeg,
                                             const void*                   const pWriteBufEnd)
 :m_spProvider(structure::not_null_ptr(pProvider))
 ,m_hSocket(winsock::API::WinSock__INVALID_SOCKET)
 ,m_SocketFamily(structure::negative_one)
 ,m_SocketType(structure::negative_one)
 ,m_SocketProtocol(structure::negative_one)
 ,m_read_buf      (pReadBuf)
 ,m_read_buf_size (cbReadBuf)
 ,m_read_avail    (0)
 ,m_read_next     (pReadBuf)
 ,m_write_buf_beg (reinterpret_cast<byte_type*>(pWriteBufBeg))
 ,m_write_buf_cur (reinterpret_cast<byte_type*>(pWriteBufBeg))
 ,m_write_buf_end (reinterpret_cast<const byte_type*>(pWriteBufEnd))
{
 assert(m_spProvider);
 assert(m_read_buf_size>0);
}//RemoteFB__INET_Socket

//------------------------------------------------------------------------
RemoteFB__INET_Socket::~RemoteFB__INET_Socket()
{
 if(m_hSocket!=winsock::API::WinSock__INVALID_SOCKET)
 {
  try
  {
   _VERIFY_EQ(m_spProvider->m_closesocket.point()(m_hSocket),0);
  }
  catch(...)
  {
   assert(false);
  }

  m_hSocket=winsock::API::WinSock__INVALID_SOCKET;
 }//if
}//~RemoteFB__INET_Socket

//------------------------------------------------------------------------
RemoteFB__INET_Socket::self_ptr
 RemoteFB__INET_Socket::Create(winsock::t_winsock__provider* const pProvider)
{
 assert(pProvider);

 //-----------------------------------------
 size_t total_sz=sizeof(self_type);

 //-----------------------------------------
 const size_t offset_read_buf=total_sz;

 if(!structure::append_memory_size(total_sz,RemoteFB__INET_StaticCfg::c_FB_PACKET_SIZE))
  throw std::bad_alloc();

 //-----------------------------------------
 const size_t offset_write_buf=total_sz;

 if(!structure::append_memory_size(total_sz,RemoteFB__INET_StaticCfg::c_FB_PACKET_SIZE))
  throw std::bad_alloc();

 //-----------------------------------------
 void* const pv=raw_allocator_type::instance.allocate(total_sz);

 assert(pv!=nullptr);

 byte_type* const read_buf  =reinterpret_cast<byte_type*>(pv)+offset_read_buf;
 byte_type* const write_buf =reinterpret_cast<byte_type*>(pv)+offset_write_buf;

 try
 {
  new(pv)self_type(pProvider,
                   RemoteFB__INET_StaticCfg::c_FB_PACKET_SIZE,
                   read_buf,
                   write_buf,
                   write_buf+RemoteFB__INET_StaticCfg::c_FB_PACKET_SIZE);
 }
 catch(...)
 {
  raw_allocator_type::instance.deallocate(pv,total_sz);

  throw;
 }//catch

 assert(pv);

 return structure::not_null_ptr(reinterpret_cast<self_type*>(pv));
}//Create

//------------------------------------------------------------------------
RemoteFB__INET_Socket::self_ptr RemoteFB__INET_Socket::Connect_v2
                                           (winsock::t_winsock__provider* const pProvider,
                                            int                           const socketFamily,
                                            wstr_box_type                 const ucs2_host,
                                            wstr_box_type                 const ucs2_port)
{
 assert(pProvider!=nullptr);
 assert(socketFamily==winsock::API::WinSock__AF_UNSPEC ||
        socketFamily==winsock::API::WinSock__AF_INET   ||
        socketFamily==winsock::API::WinSock__AF_INET6);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__INET_Socket::Connect_v2";

 //-----------------------------------------
 std::string host;

 {
  bool err=false;

  structure::tstr_to_tstr(&host,ucs2_host.ptr,ucs2_host.len,&err);

  if(err)
  {
   //ERROR - ошибка конвертирования имени хоста в системную кодовую страницу

   IBP_ThrowSimpleError
    (E_FAIL,
     ibp_subsystem__remote_fb__inet,
     ibp_mce_common__failed_to_convert_dbms_host_name_to_system_codepage_0);
  }//if err
 }//local

 //-----------------------------------------
 std::string port;

 {
  bool err=false;

  structure::tstr_to_tstr(&port,ucs2_port.ptr,ucs2_port.len,&err);

  if(err)
  {
   //ERROR - ошибка конвертирования имени порта хоста в системную кодовую страницу

   IBP_ThrowSimpleError
    (E_FAIL,
     ibp_subsystem__remote_fb__inet,
     ibp_mce_common__failed_to_convert_dbms_host_port_name_to_system_codepage_0);
  }//if err
 }//local

 if(port.empty())
 {
  port=Helper__GetDefaultPortNumberAsString();
 }//if port.empty()

 assert(!port.empty());

 //-----------------------------------------
 winsock::API::WinSock__addrinfo gai_hints={};

 gai_hints.ai_family=socketFamily;

 gai_hints.ai_socktype=winsock::API::WinSock__SOCK_STREAM;

 gai_hints.ai_protocol=winsock::API::WinSock__IPPROTO_TCP;

 gai_hints.ai_flags=winsock::API::WinSock__AI_ADDRCONFIG;

 //-----------------------------------------
 tag_addrinfo_sptr gai_result(pProvider);

 //-----------------------------------------
 {
  t_ibp_error gai_err(E_FAIL);

  for(;;)
  {
   //getaddrinfo
   // - returns
   //    Success returns zero. Failure returns a nonzero Windows Sockets error code,
   //    as found in the Windows Sockets Error Codes.

   const int gai_err_code=pProvider->m_getaddrinfo.point()
                             (host.c_str(),
                              port.c_str(),
                              &gai_hints,
                              gai_result.pptr());

   if(gai_err_code==0)
    break;

   gai_err.add_error(E_FAIL,
                     ibp_mce_winsock__getaddrinfo_failed_3,
                     IBP_CreateCustomErrorFor_CnFailed());

   gai_err<<gai_err_code
          <<host
          <<port;

   if(gai_err_code==winsock::API::WinSock__WSATYPE_NOT_FOUND)
   {
    if(port==RemoteFB__INET_StaticCfg::c_FB_SERVICE_NAME)
    {
     port=Helper__GetDefaultPortNumberAsString();

     assert(port!=RemoteFB__INET_StaticCfg::c_FB_SERVICE_NAME);

     continue;
    }//if
   }//if gai_err_code==WSATYPE_NOT_FOUND

   //ERROR - getaddrinfo returns the error!
   gai_err.raise_me();
  }//for[ever]
 }//local

 if(gai_result.ptr())
 {
  /// - Конструирование объекта.

  self_ptr spSocket(self_type::Create(pProvider));

  t_ibp_error exc(E_FAIL);

  for(const winsock::API::WinSock__addrinfo* pai=gai_result.ptr();pai;pai=pai->ai_next)
  {
   assert(spSocket->m_hSocket==winsock::API::WinSock__INVALID_SOCKET);

   /// - Инициализация сокета.

   spSocket->Helper__Socket_Init(pai->ai_family,
                                 pai->ai_socktype,
                                 pai->ai_protocol); //throw

   assert(spSocket->m_hSocket!=winsock::API::WinSock__INVALID_SOCKET);
   assert(spSocket->m_SocketFamily  ==pai->ai_family);
   assert(spSocket->m_SocketType    ==pai->ai_socktype);
   assert(spSocket->m_SocketProtocol==pai->ai_protocol);

   //---------------------------------------
   if(!structure::can_numeric_cast<int>(pai->ai_addrlen))
   {
    //ERROR - [BUG CHECK] too large address length!

    structure::wstr_formatter
     freason(me_bug_check__too_large_length_of_network_address_1);

    freason<<pai->ai_addrlen;

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#001",
      freason.c_str());
   }//if

   //---------------------------------------
   const int cnErr=pProvider->m_connect.point()
                   (spSocket->m_hSocket,
                    pai->ai_addr,
                    static_cast<int>(pai->ai_addrlen));

   if(cnErr!=winsock::API::WinSock__SOCKET_ERROR)
   {
    //запоминаем данные для переподключения

    spSocket->Helper__SaveData
     (ucs2_host,
      ucs2_port,
      pai->ai_addrlen,
      pai->ai_addr); //throw

    return spSocket;
   }//if - ok

   //---------------------------------------
   const int winsockError=pProvider->m_WSAGetLastError.point()();

   // Firebird
   //  isc_net_connect_err [IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE]

   //Append the SQLSTATE code

   exc.add_error
    (E_FAIL,
     ibp_mce_winsock__failed_to_connect_to_srv_7,
     IBP_CreateCustomErrorFor_CnFailed());

   exc<<winsockError
      <<host
      <<port;

   //----------
   std::string strAddr;

   if(pProvider->address_to_string(pai->ai_addrlen,
                                   pai->ai_addr,
                                   &strAddr))
   {
    //[2016-04-18] По идее, сформированная строка с адресом не может быть пустой
    assert(!strAddr.empty());

    exc<<strAddr;
   }
   else
   {
    exc<<"???";
   }//else

   //----------
   exc<<pai->ai_family
      <<pai->ai_socktype
      <<pai->ai_protocol;

   //---------------------------------------
   spSocket->Helper__Socket_Close(); //throw

   assert(spSocket->m_hSocket==winsock::API::WinSock__INVALID_SOCKET);
  }//for pai

  assert(exc.get_record_count()>0);

  exc.raise_me();
 }//if gai_result.ptr()

 assert(!gai_result.ptr());

 //ERROR - can't connect to server

 t_ibp_error exc(E_FAIL,
                 ibp_mce_winsock__cant_detect_addr_of_host_1,
                 IBP_CreateCustomErrorFor_CnFailed());

 exc<<host;

 exc.raise_me();

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//Connect_v2

//------------------------------------------------------------------------
RemoteFB__INET_Socket::self_ptr RemoteFB__INET_Socket::CloneConnection()const
{
 self_ptr spSocket(self_type::Create(m_spProvider));

 assert(spSocket);

 //-----------------------------------------
 spSocket->Helper__Socket_Init
  (m_SocketFamily,
   m_SocketType,
   m_SocketProtocol); //throw

 assert(spSocket->m_hSocket!=winsock::API::WinSock__INVALID_SOCKET);

 //-----------------------------------------
 assert(structure::can_numeric_cast<int>(m_SocketAddress.size()));

 const int cnErr=m_spProvider->m_connect.point()
                    (spSocket->m_hSocket,
                     reinterpret_cast<const winsock::API::WinSock__sockaddr*>(m_SocketAddress.buffer()),
                     static_cast<int>(m_SocketAddress.size()));

 if(cnErr!=winsock::API::WinSock__SOCKET_ERROR)
 {
  //запоминаем данные для переподключения

  spSocket->Helper__SaveData
   (m_wstrHost,
    m_wstrPort,
    m_SocketAddress.size(),
    m_SocketAddress.buffer()); //throw

  return spSocket;
 }//if - ok

 //---------------------------------------
 const int winsockError=m_spProvider->m_WSAGetLastError.point()();

 // Firebird
 //  isc_net_connect_err [IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE]

 //Append the SQLSTATE code

 t_ibp_error exc(E_FAIL,
                 ibp_mce_winsock__failed_to_connect_to_srv_7,
                 IBP_CreateCustomErrorFor_CnFailed());

 exc<<winsockError
    <<m_wstrHost
    <<m_wstrPort;

 //----------
 std::string strAddr;

 if(m_spProvider->address_to_string
     (m_SocketAddress.size(),
      reinterpret_cast<const winsock::API::WinSock__sockaddr*>(m_SocketAddress.buffer()),
      &strAddr))
 {
  //[2016-04-18] По идее, сформированная строка с адресом не может быть пустой
  assert(!strAddr.empty());

  exc<<strAddr;
 }
 else
 {
  exc<<"???";
 }//else

 //----------
 exc<<m_SocketFamily
    <<m_SocketType
    <<m_SocketProtocol;

 exc.raise_me();
}//CloneConnection

//port stream interface --------------------------------------------------
RemoteFB__INET_Socket::tag_stream_class
 RemoteFB__INET_Socket::GetStreamClass()const
{
 return self_type::stream_class__transport;
}//GetStreamClass

//------------------------------------------------------------------------
RemoteFB__PortStream* RemoteFB__INET_Socket::GetParentStream()const
{
 return nullptr;
}//GetParentStream

//------------------------------------------------------------------------
void RemoteFB__INET_Socket::SetParentStream(RemoteFB__PortStream* const UNUSED_ARG(pParentStream))
{
 RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
  (L"RemoteFB__INET_Socket::SetParentStream",
   L"#001",
   me_bug_check__incorrect_usage_of_method_0);
}//SetParentStream

//------------------------------------------------------------------------
size_t RemoteFB__INET_Socket::GetWriteBufSize()const
{
 assert(m_write_buf_beg<m_write_buf_end);

 return static_cast<size_t>(m_write_buf_end-m_write_buf_beg);
}//GetWriteBufSize

//------------------------------------------------------------------------
void RemoteFB__INET_Socket::Write(size_t      cb,
                                  const void* pv)
{
 for(;;)
 {
  assert(m_write_buf_beg<=m_write_buf_cur);
  assert(m_write_buf_cur<=m_write_buf_end);

  const size_t tail=static_cast<size_t>(m_write_buf_end-m_write_buf_cur);

  if(cb<=tail)
  {
   memcpy(m_write_buf_cur,pv,cb);

   m_write_buf_cur+=cb;

   return;
  }//if

  assert(tail<cb);

  memcpy(m_write_buf_cur,pv,tail);

  m_write_buf_cur+=tail;

  pv =reinterpret_cast<const byte_type*>(pv)+tail;
  cb-=tail;

  assert(cb>0);

  this->FlushWriteBuf();

  assert(m_write_buf_cur==m_write_buf_beg);
 }//for[ever]
}//Write

//------------------------------------------------------------------------
void RemoteFB__INET_Socket::FlushWriteBuf()
{
 assert(m_write_buf_beg<=m_write_buf_cur);
 assert(m_write_buf_cur<=m_write_buf_end);

 this->Helper__Socket_Send
  (size_t(m_write_buf_cur-m_write_buf_beg),
   m_write_buf_beg);

 m_write_buf_cur=m_write_buf_beg;
}//FlushWriteBuf

//------------------------------------------------------------------------
size_t RemoteFB__INET_Socket::Read2(size_t       cb,
                                    void*  const pv)
{
 assert(cb>0);

 assert(m_read_avail<=m_read_buf_size);
 assert(m_read_buf<=m_read_next);
 assert((m_read_next+m_read_avail)<=(m_read_buf+m_read_buf_size));

 if(m_read_avail!=0)
 {
  assert(m_read_avail>0);

  if(m_read_avail<cb)
   cb=m_read_avail;

  memcpy(pv,m_read_next,cb);

  m_read_avail-=cb;
  m_read_next +=cb;

  return cb;
 }//if

 assert(m_read_avail==0);

 if(m_read_buf_size<=cb)
 {
  //читаем напрямую в буфер получателя

  const size_t n
    =this->Helper__Socket_Recv
      (cb,
       pv); //throw

  assert(n>0);
  assert(n<=cb);

  return n;
 }//if m_read_buf_size<=cb

 assert(cb<m_read_buf_size);

 //читаем в собственный буфер

 m_read_next=m_read_buf;

 assert(m_read_buf_size>0);

 m_read_avail
   =this->Helper__Socket_Recv
     (m_read_buf_size,
      m_read_next); //throw

 assert(m_read_avail>0);
 assert(m_read_avail<=m_read_buf_size);

 //перегружаем часть данных в исходящий буфер

 assert(cb>0); //again

 if(m_read_avail<cb)
  cb=m_read_avail;

 assert(cb>0);

 memcpy(pv,m_read_next,cb);

 m_read_avail-=cb;
 m_read_next +=cb;

 assert(cb>0);

 return cb;
}//Read2

//Helper methods ---------------------------------------------------------
void RemoteFB__INET_Socket::Helper__Socket_Send(size_t      cb,
                                                const void* pv)
{
 CHECK_READ_PTR(pv,cb);

 assert(structure::can_numeric_cast<int>(cb));

 assert(static_cast<int>(cb)!=SOCKET_ERROR);

 size_t num_of_dymmy_send_op=0;

 while(cb!=0)
 {
  const int n=m_spProvider->m_send.point()
               (m_hSocket,
                reinterpret_cast<const char*>(pv),
                static_cast<int>(cb),
                RemoteFB__INET_StaticCfg::c_FB_SEND_FLAGS);

  if(n==winsock::API::WinSock__SOCKET_ERROR)
  {
   const int winsockErr=m_spProvider->m_WSAGetLastError.point()();

   //! \todo
   //!  Process interupt error?

   //ERROR - failed to write in INET port
   t_ibp_error exc(E_FAIL,
                   ibp_mce_winsock__failed_to_write_to_port_1,
                   IBP_CreateCustomErrorFor_CnFailed());

   exc<<winsockErr;

   exc.raise_me();
  }//if

  if(n<0)
  {
   //ERROR - [BUG CHECK] unexpected result code from send operation

   const int winsockErr=m_spProvider->m_WSAGetLastError.point()();

   t_ibp_error exc(E_FAIL,
                   ibp_mce_winsock__bug_check__unexpected_result_code_from_send_operation_2,
                   IBP_CreateCustomErrorFor_CnFailed());

   exc<<n
      <<winsockErr;

   exc.raise_me();
  }//if

  if(n==0)
  {
   assert(RemoteFB__INET_StaticCfg::c_MAX_DUMMY_SEND_OP>0);

   if(num_of_dymmy_send_op==RemoteFB__INET_StaticCfg::c_MAX_DUMMY_SEND_OP)
   {
    //ERROR - [BUG CHECK] обнаружено зацикливание операции отсылки данных

    IBP_ThrowSimpleError
     (E_FAIL,
      ibp_mce_winsock__bug_check__detected_loop_of_send_0,
      IBP_CreateCustomErrorFor_CnFailed());
   }//if

   ++num_of_dymmy_send_op;

   continue;
  }//if

  if(n>static_cast<int>(cb))
  {
   //ERROR - [BUG CHECK] send записала больше чем ожидалось

   t_ibp_error exc(E_FAIL,
                   ibp_mce_winsock__bug_check__send_write_more_than_expected_2,
                   IBP_CreateCustomErrorFor_CnFailed());

   exc<<n<<cb;

   exc.raise_me();
  }//if

  //сбрасываем счетчик пустых операций
  num_of_dymmy_send_op=0;

  assert(n>0);
  assert(n<=static_cast<int>(cb));

  cb-=static_cast<size_t>(n);

  pv=reinterpret_cast<const char*>(pv)+n;
 }//while cb!=0
}//Helper__Socket_Send

//------------------------------------------------------------------------
size_t RemoteFB__INET_Socket::Helper__Socket_Recv(size_t const cb,
                                                  void*  const pv)
{
 assert(cb>0);
 assert(pv!=nullptr);

 CHECK_WRITE_PTR(pv,cb);

 const int icb=structure::can_numeric_cast<int>(cb)
                 ?static_cast<int>(cb)
                 :structure::t_numeric_limits<int>::max_value();

 assert(icb>0);
 assert(size_t(icb)<=cb);

 const int n=m_spProvider->m_recv.point()
              (m_hSocket,
               reinterpret_cast<char*>(pv),
               icb,
               RemoteFB__INET_StaticCfg::c_FB_RECV_FLAGS);

 if(n==SOCKET_ERROR)
 {
  const int winsockErr=m_spProvider->m_WSAGetLastError.point()();

  //! \todo
  //!  Process interupt error?

  // ERROR - failed to read from INET port
  t_ibp_error exc(E_FAIL,
                  ibp_mce_winsock__failed_to_read_from_port_1,
                  IBP_CreateCustomErrorFor_CnFailed());

  exc<<winsockErr;

  exc.raise_me();
 }//if n==SOCKET_ERROR

 if(n==0)
 {
  const int winsockErr=m_spProvider->m_WSAGetLastError.point()();

  // ERROR - [BUG CHECK] read from closed socket?

  t_ibp_error exc(E_FAIL,
                  ibp_mce_winsock__bug_check__read_from_closed_port_1,
                  IBP_CreateCustomErrorFor_CnFailed());

  exc<<winsockErr;

  exc.raise_me();
 }//if

 if(n<0)
 {
  // ERROR - unexpected result value from recv

  const int winsockErr=m_spProvider->m_WSAGetLastError.point()();

  t_ibp_error exc(E_FAIL,
                  ibp_mce_winsock__bug_check__unexpected_result_code_from_recv_operation_2,
                  IBP_CreateCustomErrorFor_CnFailed());

  exc<<n<<winsockErr;

  exc.raise_me();
 }//if n<0

 if(n>icb)
 {
  // ERROR - [BUG CHECK] read incorrect number of bytes

  t_ibp_error exc(E_FAIL,
                  ibp_mce_winsock__bug_check__recv_read_more_than_expected_2,
                  IBP_CreateCustomErrorFor_CnFailed());

  exc<<n<<icb;

  exc.raise_me();
 }//if

 return static_cast<size_t>(n);
}//Helper__Socket_Recv

//------------------------------------------------------------------------
void RemoteFB__INET_Socket::Helper__Socket_Init(int const socket__family,
                                                int const socket__type,
                                                int const socket__protocol)
{
 assert(m_spProvider);
 assert(m_hSocket==winsock::API::WinSock__INVALID_SOCKET);

 /// Инициализация сокета.

 m_hSocket=m_spProvider->m_socket.point()
                       (socket__family,
                        socket__type,
                        socket__protocol);

 if(m_hSocket==winsock::API::WinSock__INVALID_SOCKET)
 {
  //ERROR - can't allocate socket

  const int wsaError=m_spProvider->m_WSAGetLastError.point()();

  assert(wsaError!=0);

  t_ibp_error exc(E_FAIL,
                  ibp_mce_winsock__failed_to_init_the_socket_4,
                  IBP_CreateCustomErrorFor_CnFailed());

  exc<<wsaError
     <<socket__family
     <<socket__type
     <<socket__protocol;

  exc.raise_me();
 }//if ошибка инициализации

 assert(m_hSocket!=winsock::API::WinSock__INVALID_SOCKET);

 //----------------------------------------
 m_SocketFamily   =socket__family;
 m_SocketType     =socket__type;
 m_SocketProtocol =socket__protocol;

 //----------------------------------------
 /// Конфигурирование сокета: \b SO_KEEPALIVE.

 {
  DWORD optval = 1;

  const int setErr=m_spProvider->m_setsockopt.point()
                    (m_hSocket,
                     SOL_SOCKET,
                     SO_KEEPALIVE,
                     reinterpret_cast<const char*>(&optval),
                     sizeof(optval));

  if(setErr==winsock::API::WinSock__SOCKET_ERROR)
  {
   //! \todo
   //!  Notify about this problem
  }//if
 }//local

 //----------------------------------------
 //! \todo
 //!  Set NoNagle options
}//Helper__Socket_Init

//------------------------------------------------------------------------
void RemoteFB__INET_Socket::Helper__Socket_Close()
{
 assert(m_spProvider);
 assert(m_hSocket!=winsock::API::WinSock__INVALID_SOCKET);

 if(DEBUG_CODE(const int closeCode=)m_spProvider->m_closesocket.point()(m_hSocket))
 {
  assert(closeCode==winsock::API::WinSock__SOCKET_ERROR);

  const int wsaError=m_spProvider->m_WSAGetLastError.point()();

  assert(wsaError!=0);

  t_ibp_error exc(E_FAIL,
                  ibp_mce_winsock__failed_to_close_the_socket_1,
                  IBP_CreateCustomErrorFor_CnFailed());

  exc<<wsaError;

  exc.raise_me();
 }//if

 m_hSocket=winsock::API::WinSock__INVALID_SOCKET;

 m_SocketFamily   =structure::negative_one;
 m_SocketType     =structure::negative_one;
 m_SocketProtocol =structure::negative_one;
}//Helper__Socket_Close

//------------------------------------------------------------------------
void RemoteFB__INET_Socket::Helper__SaveData(wstr_box_type const ucs2Host,
                                             wstr_box_type const ucs2Port,
                                             size_t        const cbAddress,
                                             const void*   const pvAddress)
{
 CHECK_READ_PTR(pvAddress,cbAddress);

 m_wstrHost=ucs2Host.make_str();
 m_wstrPort=ucs2Port.make_str();

 m_SocketAddress.alloc(cbAddress);

 assert(m_SocketAddress.size()==cbAddress);

 memcpy(m_SocketAddress.buffer(),
        pvAddress,
        cbAddress);
}//Helper__SaveData

//------------------------------------------------------------------------
std::string RemoteFB__INET_Socket::Helper__GetDefaultPortNumberAsString()
{
 char buf[128];

 structure::fix_ostream s(buf,_DIM_(buf));

 s<<RemoteFB__INET_StaticCfg::c_FB_SERVICE_PORT;

 assert(s.good());
 assert(s.writed()>0);
 assert(s.writed()<=_DIM_(buf));

 return std::string(buf,s.writed());
}//Helper__GetDefaultPortNumberAsString

////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
