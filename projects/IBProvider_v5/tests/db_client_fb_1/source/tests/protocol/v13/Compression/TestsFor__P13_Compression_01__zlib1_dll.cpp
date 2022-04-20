////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/protocol/v13/Compression/TestsFor__P13_Compression_01__zlib1_dll.h"
#include "source/test_services.h"
#include "source/test_func.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P13_Compression_01__zlib1_dll::tag_impl

class TestsFor__P13_Compression_01__zlib1_dll::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
  static void test_003_win64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
  static void test_004_win32
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif
};//class TestsFor__P13_Compression_01__zlib1_dll::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__P13_Compression_01__zlib1_dll::tag_impl::test_001
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"%1:%2"); // <-------- v1

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol
  (ibprovider::ibp_propval__remote__protocol__13);

 params.set_dbprop_init__location
  (dbLocation.str());

 params.set_dbprop_init__user_id
  (L"SYSDBA");

 params.set_dbprop_init__password
  (L"masterkey");

 params.set_dbprop_init__remote__wire_compression
  (ibprovider::ibp_propval__remote__wire_compression__required);

 params.set_dbprop_init__remote__wire_compression_type
  (ibprovider::ibp_propval__remote__wire_compression_type__zlib1_dll);

 params.reset_dbprop_init__remote__wire_compression_library
  ();

 params.reset_dbprop_init__remote__wire_compression_library_64
  ();

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__P13_Compression_01__zlib1_dll::tag_impl::test_002
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"%1:%2"); // <-------- v1

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol
  (ibprovider::ibp_propval__remote__protocol__13);

 params.set_dbprop_init__location
  (dbLocation.str());

 params.set_dbprop_init__user_id
  (L"SYSDBA");

 params.set_dbprop_init__password
  (L"masterkey");

 params.set_dbprop_init__remote__wire_compression
  (ibprovider::ibp_propval__remote__wire_compression__required);

 params.set_dbprop_init__remote__wire_compression_type
  (ibprovider::ibp_propval__remote__wire_compression_type__zlib1_dll);

 params.set_dbprop_init__remote__wire_compression_library
  (L"zlib1.dll");

 params.reset_dbprop_init__remote__wire_compression_library_64
  ();

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_002

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)

void TestsFor__P13_Compression_01__zlib1_dll::tag_impl::test_003_win64
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"%1:%2"); // <-------- v1

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol
  (ibprovider::ibp_propval__remote__protocol__13);

 params.set_dbprop_init__location
  (dbLocation.str());

 params.set_dbprop_init__user_id
  (L"SYSDBA");

 params.set_dbprop_init__password
  (L"masterkey");

 params.set_dbprop_init__remote__wire_compression
  (ibprovider::ibp_propval__remote__wire_compression__required);

 params.set_dbprop_init__remote__wire_compression_type
  (ibprovider::ibp_propval__remote__wire_compression_type__zlib1_dll);

 //ignored
 params.set_dbprop_init__remote__wire_compression_library
  (L"zlib1-BLABLA-BLABLA.dll");

 params.set_dbprop_init__remote__wire_compression_library_64
  (L"zlib1.dll");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_003_win64

#endif //IBP_PLATFORM_ID__WINNT_AMD64

////////////////////////////////////////////////////////////////////////////////
//TEST 004

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)

void TestsFor__P13_Compression_01__zlib1_dll::tag_impl::test_004_win32
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"%1:%2"); // <-------- v1

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol
  (ibprovider::ibp_propval__remote__protocol__13);

 params.set_dbprop_init__location
  (dbLocation.str());

 params.set_dbprop_init__user_id
  (L"SYSDBA");

 params.set_dbprop_init__password
  (L"masterkey");

 params.set_dbprop_init__remote__wire_compression
  (ibprovider::ibp_propval__remote__wire_compression__required);

 params.set_dbprop_init__remote__wire_compression_type
  (ibprovider::ibp_propval__remote__wire_compression_type__zlib1_dll);

 params.set_dbprop_init__remote__wire_compression_library
  (L"zlib1.dll");

 //ignored
 params.set_dbprop_init__remote__wire_compression_library_64
  (L"zlib1-BLABLA-BLABLA.dll");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_004_win32

#endif //IBP_PLATFORM_ID__WINNT_X86

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__P13_Compression_01__zlib1_dll::tag_descr

struct TestsFor__P13_Compression_01__zlib1_dll::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class TestsFor__P13_Compression_01__zlib1_dll::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,TestsFor__P13_Compression_01__zlib1_dll::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const TestsFor__P13_Compression_01__zlib1_dll::tag_descr
 TestsFor__P13_Compression_01__zlib1_dll::sm_Tests[]=
{
 DEF_TEST_DESCR2
  ("001",
   test_001,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("002",
   test_002,
   "SRV>=FB-3")

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
 DEF_TEST_DESCR2
  ("003.win64",
   test_003_win64,
   "SRV>=FB-3")
#endif

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
 DEF_TEST_DESCR2
  ("004.win32",
   test_004_win32,
   "SRV>=FB-3")
#endif
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P13_Compression_01__zlib1_dll

void TestsFor__P13_Compression_01__zlib1_dll::create(TTSO_PushTest*      const pTestPusher,
                                                     TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.protocol.v13.Compressor.01.zlib1_dll.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr
   spTest
    (structure::not_null_ptr
      (new TTSO_TestFunc
        (pParams,
         ftestID.c_str(),
         d.Func,
         d.pExecRules)));

  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
