////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_011__CreateDatabase.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_011__CreateDatabase::tag_impl

class WORK_Test_011__CreateDatabase::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__page_size__4096
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__page_size__8192
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
};//class WORK_Test_011__CreateDatabase

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_011__CreateDatabase::tag_impl::test_001
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
           <<ibp_test::TSO_GenerateNewDatabaseFileName();

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 {
  isc_base::t_isc_connection_settings cns;

  const svc::remote_fb_connector_ptr
   spConnector
    (svc::RemoteFB_Connector__CreateDatabase
      (tracer,
       params,
       cns));

  svc::RemoteFB_Connector__DetachDatabase
   (tracer,
    spConnector);
 }//local

 //-----------------------------------------
 {
  isc_base::t_isc_connection_settings cns;

  const svc::remote_fb_connector_ptr
   spConnector
    (svc::RemoteFB_Connector__ConnectToDatabase
      (tracer,
       params,
       cns));

  svc::RemoteFB_Connector__DropDatabase
   (tracer,
    spConnector);
 }//local

}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_011__CreateDatabase::tag_impl::test_002__page_size__4096
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 const long c_page_size=4*1024;

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
           <<ibp_test::TSO_GenerateNewDatabaseFileName();

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 // [2015] #$@
 // [2019-02-17] :-)
 params.set_dbprop_newdb__page_size(c_page_size);

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
 _TSO_CHECK(!cns.db_page_size_Ex.null());
 _TSO_CHECK(cns.db_page_size_Ex.value()==c_page_size);

 //-----------------------------------------
 svc::RemoteFB_Connector__DropDatabase
  (tracer,
   spConnector);
}//test_002__page_size__4096

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void WORK_Test_011__CreateDatabase::tag_impl::test_003__page_size__8192
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 const long c_page_size=8*1024;

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
           <<ibp_test::TSO_GenerateNewDatabaseFileName();

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_newdb__page_size(c_page_size);

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
 _TSO_CHECK(!cns.db_page_size_Ex.null());
 _TSO_CHECK(cns.db_page_size_Ex.value()==c_page_size);

 //-----------------------------------------
 svc::RemoteFB_Connector__DropDatabase
  (tracer,
   spConnector);
}//test_003__page_size__8192

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_011__CreateDatabase::tag_descr

struct WORK_Test_011__CreateDatabase::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_011__CreateDatabase::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_011__CreateDatabase::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_011__CreateDatabase::tag_descr
 WORK_Test_011__CreateDatabase::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test_001)

 DEF_TEST_DESCR
  ("002.page_size.4096",
   test_002__page_size__4096)

 DEF_TEST_DESCR
  ("003.page_size.8192",
   test_003__page_size__8192)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_011__CreateDatabase

void WORK_Test_011__CreateDatabase::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter
  ftestID("RemoteFB.WORK.011.CreateDatabase.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes[it[iPType]];

  ftestID<<structure::flush
         <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
         <<sm_Tests[it[iTest]].pTestSign;

  const TTSO_TestPtr spTest(new TTSO_TestFunc_v2(pParams,
                                                 ftestID.c_str(),
                                                 sm_Tests[it[iTest]].Func,
                                                 Data,
                                                 sm_Tests[it[iTest]].pExecRules));
  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
