////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_012__DropDatabase.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_012__DropDatabase::tag_impl

class WORK_Test_012__DropDatabase::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__err__bad_cn_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

#ifdef NDEBUG
 public:
  static void test_003__bug_check__bad_cn_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
#endif

 public:
  static void test_004__err__has_active_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_DropDb_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_012__DropDatabase

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_012__DropDatabase::tag_impl::test_001__err__bad_cn_handle
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2%3");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__new_db_dir)->m_value
           <<TSO_GenerateNewDatabaseFileName();

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__CreateDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestServices::HACK__DropDb
  (tracer,
   spConnector);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__DropDatabase
   (tracer,
    spConnector);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,
                          1);

  errSvc::check_err_rec__srv_err__bad_cn_handle
   (tracer,
    spConnector->GetData()->m_DBMS_Name,
    exc.get_record(0));

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_001__err__bad_cn_handle

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_012__DropDatabase::tag_impl::test_003__bug_check__bad_cn_handle
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2%3");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__new_db_dir)->m_value
           <<TSO_GenerateNewDatabaseFileName();

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__CreateDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 svc::RemoteFB_Connector__DropDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__DropDatabase
   (tracer,
    spConnector);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,
                           1);

  errSvc::check_err_rec__cn_err__bug_check__bad_cn_handle
   (tracer,
    exc.get_record(0),
    helper__get_DropDb_bugcheck_src(spConnector),
    L"#001");

  return;
 }//catch
}//test_003__bug_check__bad_cn_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_012__DropDatabase::tag_impl::test_004__err__has_active_tr
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2%3");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__new_db_dir)->m_value
           <<TSO_GenerateNewDatabaseFileName();

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__CreateDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle1(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &tr_handle1);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle2(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &tr_handle2);

 //-----------------------------------------
 svc::RemoteFB_Connector__DropDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 //транзакция отключена
 _TSO_CHECK(tr_handle1->m_pParentPort==nullptr);

 //идентификатор не сбрасывается.
 _TSO_CHECK(tr_handle1->m_ID.has_value());

 //-----------------------------------------
 //транзакция отключена
 _TSO_CHECK(tr_handle2->m_pParentPort==nullptr);

 //идентификатор не сбрасывается.
 _TSO_CHECK(tr_handle2->m_ID.has_value());
}//test_004__err__has_active_tr

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_012__DropDatabase::tag_impl::helper__get_DropDb_bugcheck_src
                                           (remote_fb::RemoteFB__Connector* const pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
   return L"RemoteFB__API_P12__DropDatabase::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__DropDatabase::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_DropDb_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_012__DropDatabase::tag_descr

struct WORK_Test_012__DropDatabase::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_012__DropDatabase::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_012__DropDatabase::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_012__DropDatabase::tag_descr
 WORK_Test_012__DropDatabase::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.err.bad_cn_handle",
   test_001__err__bad_cn_handle)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("003.bug_check.bad_cn_handle",
   test_003__bug_check__bad_cn_handle)
#endif

 DEF_TEST_DESCR
  ("004.err.has_active_tr",
   test_004__err__has_active_tr)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_012__DropDatabase

void WORK_Test_012__DropDatabase::create(TTSO_PushTest*      const pTestPusher,
                                         TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                               //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);     //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.012.DropDatabase.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes[it[iPType]];

  ftestID
   <<structure::flush
   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
   <<sm_Tests[it[iTest]].pTestSign;

  const TTSO_TestPtr
   spTest
     (structure::not_null_ptr
       (new TTSO_TestFunc_v2
         (pParams,
          ftestID.c_str(),
          sm_Tests[it[iTest]].Func,
          Data,
          sm_Tests[it[iTest]].pExecRules)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
