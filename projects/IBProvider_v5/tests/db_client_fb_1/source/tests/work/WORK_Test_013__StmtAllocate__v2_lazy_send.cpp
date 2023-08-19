////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_013__StmtAllocate__v2_lazy_send.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/test_operation_context.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl

class WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

#ifdef NDEBUG
 public:
  static void test_001__bug_check__not_zero_stmt_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__bug_check__bad_cn_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
#endif

 public:
  static void test_010
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_011__check_release_of_dropped_stmts
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StmtAlloc_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl::test_001__bug_check__not_zero_stmt_handle
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 const remote_fb::handles::RemoteFB__StmtHandle hStmt2(hStmt);

 _TSO_CHECK(hStmt==hStmt2);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtAllocate
    (tracer,
     spConnector,
     &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__stmt_handle_not_zero
    (tracer,
     exc.get_record(0),
     helper__get_StmtAlloc_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //дескриптор не должен измениться!
 _TSO_CHECK(hStmt==hStmt2);
}//test_001__bug_check__not_zero_stmt_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl::test_002__bug_check__bad_cn_handle
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtAllocate
    (tracer,
     spConnector,
     &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__cn_err__bug_check__bad_cn_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtAlloc_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //дескриптор не должен измениться!
 _TSO_CHECK(hStmt==nullptr);
}//test_002__bug_check__bad_cn_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 010

void WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl::test_010
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_ID.is_defer());

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 _TSO_CHECK(hStmt);

 _TSO_CHECK(hStmt->m_pParentPort==nullptr);
}//test_010

////////////////////////////////////////////////////////////////////////////////
//TEST 011

void WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl::test_011__check_release_of_dropped_stmts
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //----------------------------------------- Вычисляем сколько запросов мы можем создать
 size_t nMaxStatements=0;

 {
  isc_base::t_isc_connection_settings cns;

  const svc::remote_fb_connector_ptr
   spConnector
    (svc::RemoteFB_Connector__ConnectToDatabase
      (tracer,
       params,
       cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

  //-----------------------------------------
  svc::remote_fb_tr_handle_type hTr(nullptr);

  svc::RemoteFB_Connector__StartTransaction
   (tracer,
    spConnector,
    &hTr);

  //-----------------------------------------
  typedef structure::t_stl_map
   <unsigned,
    svc::remote_fb_stmt_handle_type,
    std::less<unsigned>,
    TTSO_MemoryAllocator>     stmts_type;

  stmts_type stmts;

  //-----------------------------------------
  tracer<<L"Allocate statements ..."<<send;

  for(;;++nMaxStatements)
  {
   remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

   spConnector->StmtAllocate(&hStmt);

   _TSO_CHECK(hStmt);
   _TSO_CHECK(hStmt->m_ID.is_defer());
   _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

   //-----------
   try
   {
    unsigned long iscStmtTypeID=0;

    spConnector->StmtPrepare
     (OpCtx,
      &hTr,
      &hStmt,
      static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
      "select ID from DUAL",
      &iscStmtTypeID);
   }
   catch(const ibp::t_ibp_error& exc)
   {
    //скорее всего порт будет переведен в заблокированное состояние

    typedef TestCheckErrors errSvc;

    errSvc::print_exception_ok(tracer,exc);

    break;
   }//if

   _TSO_CHECK(hStmt->m_ID.has_value());

   //-----------
   if(!stmts.insert(stmts_type::value_type(hStmt->m_ID.get_value(),hStmt)).second)
   {
    structure::str_formatter fmsg("Duplication of stmt id [%1]");

    fmsg<<hStmt->m_ID.get_value();

    throw std::runtime_error(fmsg.str());
   }//if
  }//for[ever]

  tracer<<L"nMaxStatements: "<<nMaxStatements<<send;

  _TSO_CHECK(nMaxStatements>1);
 }//local

 //----------------------------------------- Заново создаем запросы
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 typedef structure::t_stl_map
  <unsigned,
   svc::remote_fb_stmt_handle_type,
   std::less<unsigned>,
   TTSO_MemoryAllocator>     stmts_type;

 stmts_type stmts;

 //-----------------------------------------
 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  tracer<<L"Allocate statements ..."<<send;

  for(size_t n=0;n!=nMaxStatements;++n)
  {
   remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

   try
   {
    spConnector->StmtAllocate(&hStmt);

    _TSO_CHECK(hStmt);
    _TSO_CHECK(hStmt->m_ID.is_defer());
    _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

    //-----------
    unsigned long iscStmtTypeID=0;

    spConnector->StmtPrepare
     (OpCtx,
      &hTr,
      &hStmt,
      static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
      "select ID from DUAL",
      &iscStmtTypeID);

    _TSO_CHECK(hStmt);
    _TSO_CHECK(hStmt->m_ID.has_value());
   }
   catch(...)
   {
    tracer<<L"Allocated: "<<n<<send;

    throw;
   }//if

   //-----------
   if(!stmts.insert(stmts_type::value_type(hStmt->m_ID.get_value(),hStmt)).second)
   {
    structure::str_formatter fmsg("Duplication of stmt id [%1]");

    fmsg<<hStmt->m_ID.get_value();

    throw std::runtime_error(fmsg.str());
   }//if

   //-----------
   if(n==0)
   {
    tracer<<L"----"<<send;
   }//if n==0
  }//for n

  tracer<<L"Drop statements ..."<<send;

  for(;!stmts.empty();stmts.erase(stmts.begin()))
  {
   spConnector->StmtDrop(&(*stmts.begin()).second);

   _TSO_CHECK(!(*stmts.begin()).second);
  }//for stmts

  _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==nMaxStatements);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_011__check_release_of_dropped_stmts

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl::helper__get_StmtAlloc_bugcheck_src
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
   return L"RemoteFB__API_P12_LAZY_SEND__AllocateStatement::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13_LAZY_SEND__AllocateStatement::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtAlloc_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_013__StmtAllocate__v2_lazy_send::tag_descr

struct WORK_Test_013__StmtAllocate__v2_lazy_send::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_013__StmtAllocate__v2_lazy_send::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_013__StmtAllocate__v2_lazy_send::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_013__StmtAllocate__v2_lazy_send::tag_descr
 WORK_Test_013__StmtAllocate__v2_lazy_send::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.not_zero_stmt_handle",
   test_001__bug_check__not_zero_stmt_handle)

 DEF_TEST_DESCR
  ("002.bug_check.bad_cn_handle",
   test_002__bug_check__bad_cn_handle)
#endif

 DEF_TEST_DESCR
  ("010",
   test_010)

 DEF_TEST_DESCR
  ("011.check_release_of_dropped_stmts",
   test_011__check_release_of_dropped_stmts)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_013__StmtAllocate__v2_lazy_send

void WORK_Test_013__StmtAllocate__v2_lazy_send::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                       //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send)-1);  //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.013.StmtAllocate.v2.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes__lazy_send[it[iPType]];

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
}//namespace ibp_test
