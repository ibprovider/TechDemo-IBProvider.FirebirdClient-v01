////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_003__Connector.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_003__Connector::tag_impl

class WORK_Test_003__Connector::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__connect_to_db__v1
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_001__connect_to_db__v2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_001__connect_to_db__v3
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_001__connect_to_db__v3_inet4
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_001__connect_to_db__v3_inet6
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002__err_unk_cn_type
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003__err_no_data_source
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_004__auth__legacy
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_005__auth__win_sspi
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_005__auth__win_sspi__and__integ_sec
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_006__auth__srp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class WORK_Test_003__Connector::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001 [v1]

void WORK_Test_003__Connector::tag_impl::test_001__connect_to_db__v1
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

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_001__connect_to_db__v1

////////////////////////////////////////////////////////////////////////////////
//TEST 001 [v2]

void WORK_Test_003__Connector::tag_impl::test_001__connect_to_db__v2
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
 structure::wstr_formatter dbLocation(L"[%1]:%2"); // <-------- v2

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_001__connect_to_db__v2

////////////////////////////////////////////////////////////////////////////////
//TEST 001 [v3]

void WORK_Test_003__Connector::tag_impl::test_001__connect_to_db__v3
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
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2"); // <-------- v3

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_001__connect_to_db__v3

////////////////////////////////////////////////////////////////////////////////
//TEST 001 [v3][inet4]

void WORK_Test_003__Connector::tag_impl::test_001__connect_to_db__v3_inet4
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
 structure::wstr_formatter dbLocation(L"inet4://[%1]/%2"); // <-------- v3

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_001__connect_to_db__v3_inet4

////////////////////////////////////////////////////////////////////////////////
//TEST 001 [v3][inet6]

void WORK_Test_003__Connector::tag_impl::test_001__connect_to_db__v3_inet6
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
 structure::wstr_formatter dbLocation(L"inet6://[%1]/%2"); // <-------- v3

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));
}//test_001__connect_to_db__v3_inet6

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_003__Connector::tag_impl::test_002__err_unk_cn_type
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
 //используем односимвольный идентификатор INET-хоста
 structure::wstr_formatter dbLocation(L"d:BLABLABLA");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,
                          1);

  errSvc::check_err_rec__cn_err__cant_detect_cn_type
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb);

  return;
 }//catch

 tracer(tso_msg_warning,-1)<<L"We wait the error"<<send;
}//test_002__err_unk_cn_type

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void WORK_Test_003__Connector::tag_impl::test_003__err_no_data_source
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
 svc::dbprops_type params(pParams);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,
                          1);

  errSvc::check_err_rec__cn_err__not_defined_req_init_prop
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb,
    L"Location");

  return;
 }//catch

 tracer(tso_msg_error,-1)<<L"We wait the error"<<send;
}//test_003__err_no_data_source

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_003__Connector::tag_impl::test_004__auth__legacy
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
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__auth(L"legacy_auth");

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 
 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user)->m_value));
 
 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password)->m_value));

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__auth__legacy

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_003__Connector::tag_impl::test_005__auth__win_sspi
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
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__auth(L"win_sspi");

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005__auth__win_sspi

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_003__Connector::tag_impl::test_005__auth__win_sspi__and__integ_sec
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
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__auth(L"win_sspi");

 params.set_dbprop_init__integrated_auth(L"SSPI");

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005__auth__win_sspi

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_003__Connector::tag_impl::test_006__auth__srp
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
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__auth(L"srp");

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 
 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user)->m_value));
 
 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password)->m_value));

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_006__auth__srp

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_003__Connector::tag_descr

struct WORK_Test_003__Connector::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_003__Connector::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_003__Connector::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_003__Connector::tag_descr
 WORK_Test_003__Connector::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.connect_to_db.v1",
   test_001__connect_to_db__v1)

 DEF_TEST_DESCR
  ("001.connect_to_db.v2",
   test_001__connect_to_db__v2)

 DEF_TEST_DESCR
  ("001.connect_to_db.v3",
   test_001__connect_to_db__v3)

 DEF_TEST_DESCR
  ("001.connect_to_db.v3_inet4",
   test_001__connect_to_db__v3_inet4)

 DEF_TEST_DESCR2
  ("001.connect_to_db.v3_inet6",
   test_001__connect_to_db__v3_inet6,
   "SRV>=FB-3")

 DEF_TEST_DESCR
  ("002.err.unk_cn_type",
   test_002__err_unk_cn_type)

 DEF_TEST_DESCR
  ("003.err.no_data_source",
   test_003__err_no_data_source)

 DEF_TEST_DESCR
  ("004.auth.legacy",
   test_004__auth__legacy)

 DEF_TEST_DESCR2
  ("005.auth.win_sspi",
   test_005__auth__win_sspi,
   "NE__AUTH__WIN_SSPI")

 DEF_TEST_DESCR2
  ("005.auth.win_sspi__and__integ_sec",
   test_005__auth__win_sspi__and__integ_sec,
   "NE__AUTH__WIN_SSPI")

 DEF_TEST_DESCR2
  ("006.auth.srp",
   test_006__auth__srp,
   "NE__AUTH__SRP")
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_003__Connector

void WORK_Test_003__Connector::create(TTSO_PushTest*      const pTestPusher,
                                      TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.WORK.003.Connector.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID
   <<structure::flush
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
