////////////////////////////////////////////////////////////////////////////////
//Charset: UTF8 without BOM!
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/inet/Socket/INET_Socket_Test_004__inet6.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class INET_Socket_Test_004__inet6::tag_impl

class INET_Socket_Test_004__inet6::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_11__connect2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_11__connect2__ip4
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_12__connect2_to_localhost
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_12__connect2_to_localhost_with_port
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_13__connect2__fail__unk_host
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_14__clone_connection
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_15__connect2__bad_ports
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_16__connect2__failed_to_connect
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_17__connect2__failed_to_connect__ip4
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_18__connect2__failed_to_connect__ip6
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  struct tag_data_02;
  struct tag_data_02wp;

 private:
  static const tag_data_02   sm_data_12[];
  static const tag_data_02wp sm_data_12wp[];
  static const tag_data_02wp sm_data_15[];
};//class INET_Socket_Test_004__inet6::tag_impl

////////////////////////////////////////////////////////////////////////////////
//struct INET_Socket_Test_004__inet6::tag_impl::tag_data_02

struct INET_Socket_Test_004__inet6::tag_impl::tag_data_02
{
 public:
  const wchar_t* host;
};//struct INET_Socket_Test_004__inet6::tag_data_02

////////////////////////////////////////////////////////////////////////////////

struct INET_Socket_Test_004__inet6::tag_impl::tag_data_02wp
{
 public:
  const wchar_t* host;
  const wchar_t* port;
};//struct INET_Socket_Test_004__inet6::tag_data_02wp

////////////////////////////////////////////////////////////////////////////////
//TEST 11

void INET_Socket_Test_004__inet6::tag_impl::test_11__connect2
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 const structure::t_string
  hostName(pParams->args().get(c_prog_arg__inet_host)->m_value);

 svc::remote_fb_inet_socket_ptr spSocket
  =svc::RemoteFB_INET_Socket__Connect2
    (tracer,
     spProvider,
     ibp::os::win32::winsock::API::WinSock__AF_INET6,
     structure::tstr_to_wstr(hostName).c_str(),
     nullptr);

 _TSO_CHECK(spSocket!=nullptr);

 //-----------------------------------------
 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spSocket.Release())
 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_11__connect2

////////////////////////////////////////////////////////////////////////////////
//TEST 11

void INET_Socket_Test_004__inet6::tag_impl::test_11__connect2__ip4
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 const structure::t_string
  hostName(pParams->args().get(c_prog_arg__inet_host)->m_value);

 try
 {
  svc::remote_fb_inet_socket_ptr spSocket
   =svc::RemoteFB_INET_Socket__Connect2
     (tracer,
      spProvider,
      ibp::os::win32::winsock::API::WinSock__AF_INET6,
      L"127.0.0.1",
      nullptr);
 }
 catch(const ibp::t_ibp_error& e)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,e);

  errSvc::check_err_count(e,1);

  errSvc::check_err_rec__winsock__cant_detect_host_address
   (tracer,
    e.get_record(0),
    WSAHOST_NOT_FOUND,
    L"127.0.0.1",
    /*default*/L"3050");

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_11__connect2__ip6

////////////////////////////////////////////////////////////////////////////////

#define DEF_DATA(host) {host},

const INET_Socket_Test_004__inet6::tag_impl::tag_data_02
 INET_Socket_Test_004__inet6::tag_impl::sm_data_12[]=
{
 DEF_DATA(L"localhost")
 DEF_DATA(L"::1")
 DEF_DATA(L"")
};//sm_data_12

#undef DEF_DATA

//------------------------------------------------------------------------
void INET_Socket_Test_004__inet6::tag_impl::test_12__connect2_to_localhost
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 size_t n=0;

 for(const tag_data_02& data : sm_data_12)
 {
  ++n;

  tracer<<L"----------------------------- "<<n<<L"."<<send;

  svc::remote_fb_inet_socket_ptr spSocket
   =svc::RemoteFB_INET_Socket__Connect2
     (tracer,
      spProvider,
      ibp::os::win32::winsock::API::WinSock__AF_INET6,
      data.host,
      nullptr);

  //-----------------------------------------
  _TSO_EXEC_TRACER(tracer,spSocket.Release())
 }//for data

 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_12__connect2_to_localhost

////////////////////////////////////////////////////////////////////////////////

#define DEF_DATA(host,port) {host,port},

const INET_Socket_Test_004__inet6::tag_impl::tag_data_02wp
 INET_Socket_Test_004__inet6::tag_impl::sm_data_12wp[]=
{
 DEF_DATA(L"localhost",L"3050")
 DEF_DATA(L"::1",L"3050")
 DEF_DATA(L"",L"3050")
 DEF_DATA(L"localhost",L"gds_db")
 DEF_DATA(L"::1",L"gds_db")
 DEF_DATA(L"",L"gds_db")
};//sm_data_12wp

#undef DEF_DATA

//------------------------------------------------------------------------
void INET_Socket_Test_004__inet6::tag_impl::test_12__connect2_to_localhost_with_port
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 size_t n=0;

 for(const tag_data_02wp& data : sm_data_12wp)
 {
  ++n;

  tracer<<L"----------------------------- "<<n<<L"."<<send;

  svc::remote_fb_inet_socket_ptr spSocket
   =svc::RemoteFB_INET_Socket__Connect2
     (tracer,
      spProvider,
      ibp::os::win32::winsock::API::WinSock__AF_INET6,
      data.host,
      data.port);

  //-----------------------------------------
  _TSO_EXEC_TRACER(tracer,spSocket.Release())
 }//for data

 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_12__connect2_to_localhost_with_port

////////////////////////////////////////////////////////////////////////////////

void INET_Socket_Test_004__inet6::tag_impl::test_13__connect2__fail__unk_host
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 const wchar_t* const c_UNK_HOST_NAME=L"BADHOST4321";

 for(;;)
 {
  try
  {
   svc::RemoteFB_INET_Socket__Connect2
    (tracer,
     spProvider,
     ibp::os::win32::winsock::API::WinSock__AF_INET6,
     c_UNK_HOST_NAME,
     nullptr); //throw !!!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   errSvc::print_exception_ok(tracer,exc);

   _TSO_CHECK(exc.get_record_count()==1);

   const structure::t_err_record::self_cptr spErrRec(exc.get_record(0));

   _TSO_CHECK(spErrRec);

   errSvc::check_err_rec__winsock__cant_detect_host_address
    (tracer,
     spErrRec,
     WSAHOST_NOT_FOUND,
     c_UNK_HOST_NAME,
     L"3050");

   break;
  }//catch

  throw std::runtime_error("We wait the exception!");
 }//for[ever]

 //-----------------------------------------
 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_13__connect2__fail__unk_host

////////////////////////////////////////////////////////////////////////////////
//TEST 14

void INET_Socket_Test_004__inet6::tag_impl::test_14__clone_connection
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 const structure::t_string
  hostName(pParams->args().get(c_prog_arg__inet_host)->m_value);

 svc::remote_fb_inet_socket_ptr spSocket
  =svc::RemoteFB_INET_Socket__Connect2
    (tracer,
     spProvider,
     ibp::os::win32::winsock::API::WinSock__AF_INET6,
     structure::tstr_to_wstr(hostName).c_str(),
     nullptr);

 _TSO_CHECK(spSocket!=nullptr);

 //-----------------------------------------
 svc::remote_fb_inet_socket_ptr spSocket2
  =spSocket->CloneConnection();

 _TSO_CHECK(spSocket2);
 _TSO_CHECK(spSocket2!=spSocket);

 //-----------------------------------------
 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spSocket.Release())
 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_14__clone_connection

////////////////////////////////////////////////////////////////////////////////
//struct INET_Socket_Test_004__inet6::tag_data_15

#define DEF_DATA(host,port_name) {host,port_name},

const INET_Socket_Test_004__inet6::tag_impl::tag_data_02wp
 INET_Socket_Test_004__inet6::tag_impl::sm_data_15[]=
{
 DEF_DATA(L"localhost",
          L"yyyy")
 DEF_DATA(L"localhost",
          L"rrrr")
 DEF_DATA(L"::1",
          L"xxx")
};//sm_data_15

#undef DEF_DATA

//------------------------------------------------------------------------
void INET_Socket_Test_004__inet6::tag_impl::test_15__connect2__bad_ports
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 size_t n=0;

 for(const tag_data_02wp& data: sm_data_15)
 {
  ++n;

  tracer<<L"-------------------------- "<<n<<L"."<<send;

  try
  {
   svc::RemoteFB_INET_Socket__Connect2
    (tracer,
     spProvider,
     ibp::os::win32::winsock::API::WinSock__AF_INET6,
     data.host,
     data.port);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   errSvc::print_exception_ok(tracer,exc);

   _TSO_CHECK(exc.get_record_count()==1);

   const structure::t_err_record::self_cptr spErrRec(exc.get_record(0));

   _TSO_CHECK(spErrRec);

   errSvc::check_err_rec__winsock__cant_detect_host_address
    (tracer,
     spErrRec,
     WSATYPE_NOT_FOUND,
     data.host,
     data.port);

   continue;
  }//catch

  throw std::runtime_error("We wait the exception!");
 }//for[ever]

 //-----------------------------------------
 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_15__connect2__bad_ports

//------------------------------------------------------------------------
void INET_Socket_Test_004__inet6::tag_impl::test_16__connect2__failed_to_connect
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 const wchar_t* const c_host=L"localhost";
 const wchar_t* const c_port=L"65525";

 for(;;)
 {
  try
  {
   svc::RemoteFB_INET_Socket__Connect2
    (tracer,
     spProvider,
     ibp::os::win32::winsock::API::WinSock__AF_INET6,
     c_host,
     c_port);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   errSvc::print_exception_ok(tracer,exc);

   _TSO_CHECK(exc.get_record_count()==1);

   errSvc::check_err_rec__winsock__failed_to_connect_to_server
    (tracer,
     exc.get_record(0),
     WSAECONNREFUSED,
     c_host,
     c_port,
     L"[::1]:65525",
     AF_INET6,
     SOCK_STREAM,
     IPPROTO_TCP);

   break;
  }//catch

  throw std::runtime_error("We wait the exception!");
 }//for[ever]

 //-----------------------------------------
 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_16__connect2__failed_to_connect

//------------------------------------------------------------------------
void INET_Socket_Test_004__inet6::tag_impl::test_17__connect2__failed_to_connect__ip4
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 const wchar_t* const c_host=L"127.0.0.1";
 const wchar_t* const c_port=L"65525";

 for(;;)
 {
  try
  {
   svc::RemoteFB_INET_Socket__Connect2
    (tracer,
     spProvider,
     ibp::os::win32::winsock::API::WinSock__AF_INET6,
     c_host,
     c_port);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   errSvc::print_exception_ok(tracer,exc);

   _TSO_CHECK(exc.get_record_count()==1);

   errSvc::check_err_rec__winsock__cant_detect_host_address
    (tracer,
     exc.get_record(0),
     WSAHOST_NOT_FOUND,
     c_host,
     c_port);

   break;
  }//catch

  throw std::runtime_error("We wait the exception!");
 }//for[ever]

 //-----------------------------------------
 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_17__connect2__failed_to_connect__ip4

//------------------------------------------------------------------------
void INET_Socket_Test_004__inet6::tag_impl::test_18__connect2__failed_to_connect__ip6
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::winsock_provider_ptr spProvider
  =svc::WinSock__CreateProvider__STD(tracer);

 //-----------------------------------------
 const wchar_t* const c_host=L"::1";
 const wchar_t* const c_port=L"65525";

 for(;;)
 {
  try
  {
   svc::RemoteFB_INET_Socket__Connect2
    (tracer,
     spProvider,
     ibp::os::win32::winsock::API::WinSock__AF_INET6,
     c_host,
     c_port);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   errSvc::print_exception_ok(tracer,exc);

   _TSO_CHECK(exc.get_record_count()==1);

   errSvc::check_err_rec__winsock__failed_to_connect_to_server
    (tracer,
     exc.get_record(0),
     WSAECONNREFUSED,
     c_host,
     c_port,
     L"[::1]:65525",
     AF_INET6,
     SOCK_STREAM,
     IPPROTO_TCP);

   break;
  }//catch

  throw std::runtime_error("We wait the exception!");
 }//for[ever]

 //-----------------------------------------
 tracer<<send;

 _TSO_EXEC_TRACER(tracer,spProvider.Release())
}//test_18__connect2__failed_to_connect__ip6

////////////////////////////////////////////////////////////////////////////////
//struct INET_Socket_Test_004__inet6::tag_descr

struct INET_Socket_Test_004__inet6::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class INET_Socket_Test_004__inet6::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,INET_Socket_Test_004__inet6::tag_impl::func},

const INET_Socket_Test_004__inet6::tag_descr
 INET_Socket_Test_004__inet6::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("11.connect2",
   test_11__connect2)

 DEF_TEST_DESCR
  ("11.connect2.ip4",
   test_11__connect2__ip4)

 DEF_TEST_DESCR
  ("12.connect2_to_localhost",
   test_12__connect2_to_localhost)

 DEF_TEST_DESCR
  ("12.connect2_to_localhost.with_port",
   test_12__connect2_to_localhost_with_port)

 DEF_TEST_DESCR
  ("13.connect2.fail.unk_host",
   test_13__connect2__fail__unk_host)

 DEF_TEST_DESCR
  ("14.clone_connection",
   test_14__clone_connection)

 DEF_TEST_DESCR
  ("15.connect2.bad_ports",
   test_15__connect2__bad_ports)

 DEF_TEST_DESCR
  ("16.connect2.failed_to_connect",
   test_16__connect2__failed_to_connect)

 DEF_TEST_DESCR
  ("17.connect2.failed_to_connect.ip4",
   test_17__connect2__failed_to_connect__ip4)

 DEF_TEST_DESCR
  ("18.connect2.failed_to_connect.ip6",
   test_18__connect2__failed_to_connect__ip6)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class INET_Socket_Test_004__inet6

void INET_Socket_Test_004__inet6::create(TTSO_PushTest*      const pTestPusher,
                                         TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.INET.Socket.004.inet6.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr spTest(new TTSO_TestFunc(pParams,
                                              ftestID.c_str(),
                                              d.Func,
                                              "SRV>=FB-3"));
  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
