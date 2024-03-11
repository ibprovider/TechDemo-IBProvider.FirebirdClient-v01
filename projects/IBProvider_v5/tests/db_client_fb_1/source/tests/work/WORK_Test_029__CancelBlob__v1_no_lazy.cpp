////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_029__CancelBlob__v1_no_lazy.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl

class WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
 #ifdef NDEBUG
  static void test_001__bug_check__zero_blob_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__bug_check__null_blob_id
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__bug_check__bad_owner_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__bug_check__cancel_open_blob
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

  static void test_005
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_006__err
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_cancel_blob_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_cancel_blob_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::test_001__bug_check__zero_blob_handle
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

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
 remote_fb::handles::RemoteFB__BlobHandle
  hBlob(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CancelBlob
    (tracer,
     spConnector,
     &hBlob);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__blob_err__bug_check__bad_blob_handle
    (tracer,
     exc.get_record(0),
     helper__get_cancel_blob_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001__bug_check__zero_blob_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::test_002__bug_check__null_blob_id
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

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
 remote_fb::handles::RemoteFB__BlobHandle
  hBlob(remote_fb::handles::RemoteFB__HandleData_Blob::Create(remote_fb::handles::RemoteFB__HandleData_Blob::BlobMode__Create));

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CancelBlob
    (tracer,
     spConnector,
     &hBlob);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__blob_err__cancel_closed_blob
    (tracer,
     exc.get_record(0),
     helper__get_cancel_blob_subsystem_id(spConnector));

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__bug_check__null_blob_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::test_003__bug_check__bad_owner_cn
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobID={};

 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobID);

 _TSO_CHECK(hBlob);

 _TSO_CHECK(hBlob->m_ID.has_value());

 _TSO_CHECK(hBlob->m_pParentTr==hTr);

 _TSO_CHECK(hBlob->m_BlobMode==hBlob->BlobMode__Create);

 //-----------------------------------------

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CancelBlob
    (tracer,
     spConnector2,
     &hBlob);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__blob_err__bug_check__bad_blob_handle
    (tracer,
     exc.get_record(0),
     helper__get_cancel_blob_bugcheck_src(spConnector),
     L"#004");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 _TSO_CHECK(hBlob)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(!hBlob->m_pParentTr);
 _TSO_CHECK(hBlob->m_ID.is_null());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector2);
}//test_003__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

#ifdef NDEBUG

void WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::test_004__bug_check__cancel_open_blob
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

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
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<short>(cns.db_dialect_Ex.value()),
   "execute block returns (x blob) as begin x=x'FF'; suspend; end;");

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   nullptr,
   nullptr);

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobID={};

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_blob;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqllen     =sizeof(blobID);
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&blobID);
 xsqlda->sqlvar[0].sqlind     =nullptr;

 xsqlda->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtFetch_ToRow
  (spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 svc::RemoteFB_Connector__OpenBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   blobID);

 _TSO_CHECK(hBlob);

 _TSO_CHECK(hBlob->m_ID.has_value());

 _TSO_CHECK(hBlob->m_pParentTr==hTr);

 //-----------------------------------------

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CancelBlob
    (tracer,
     spConnector,
     &hBlob);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__blob_err__bug_check__wrong_blob_handle_mode
    (tracer,
     exc.get_record(0),
     helper__get_cancel_blob_bugcheck_src(spConnector),
     L"#005",
     1);

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 _TSO_CHECK(hBlob)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(!hStmt->m_spFetchResult);

 _TSO_CHECK(!hBlob->m_pParentTr);
 _TSO_CHECK(hBlob->m_ID.is_null());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__bug_check__cancel_open_blob

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::test_005
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobID={};

 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobID);

 _TSO_CHECK(hBlob);

 _TSO_CHECK(hBlob->m_ID.has_value());

 _TSO_CHECK(hBlob->m_pParentTr==hTr);

 _TSO_CHECK(hBlob->m_BlobMode==hBlob->BlobMode__Create);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle hCopyBlob(hBlob);

 _TSO_CHECK(hCopyBlob);

 svc::RemoteFB_Connector__CancelBlob
  (tracer,
   spConnector,
   &hBlob);

 _TSO_CHECK(!hBlob);

 _TSO_CHECK(hCopyBlob->m_ID.is_null());

 _TSO_CHECK(hCopyBlob->m_pParentTr==nullptr);

 //-----------------------------------------
 _TSO_CHECK(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::test_006__err
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobID={};

 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobID);

 _TSO_CHECK(hBlob);

 _TSO_CHECK(hBlob->m_ID.has_value());

 _TSO_CHECK(hBlob->m_pParentTr==hTr);

 _TSO_CHECK(hBlob->m_BlobMode==hBlob->BlobMode__Create);

 //-----------------------------------------
 svc::HACK__CommitTr
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CancelBlob
    (tracer,
     spConnector,
     &hBlob);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__srv_err__invalid_blob_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_006__err

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::helper__get_cancel_blob_bugcheck_src
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
   return L"RemoteFB__API_P12__CancelBlob::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__CancelBlob::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_cancel_blob_bugcheck_src

//------------------------------------------------------------------------
const wchar_t* WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::helper__get_cancel_blob_subsystem_id
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
   return errSvc::sm_subsysID__remote_fb_p12;

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return errSvc::sm_subsysID__remote_fb_p13;

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_cancel_blob_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_029__CancelBlob__v1_no_lazy::tag_descr

struct WORK_Test_029__CancelBlob__v1_no_lazy::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Test_029__CancelBlob__v1_no_lazy::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Test_029__CancelBlob__v1_no_lazy::tag_impl::func},

const WORK_Test_029__CancelBlob__v1_no_lazy::tag_descr
 WORK_Test_029__CancelBlob__v1_no_lazy::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.zero_blob_handle",
   test_001__bug_check__zero_blob_handle)

 DEF_TEST_DESCR
  ("002.bug_check.null_blob_id",
   test_002__bug_check__null_blob_id)

 DEF_TEST_DESCR
  ("003.bug_check.bad_owner_cn",
   test_003__bug_check__bad_owner_cn)

 DEF_TEST_DESCR
  ("004.bug_check.cancel_open_blob",
   test_004__bug_check__cancel_open_blob)
#endif

 DEF_TEST_DESCR
  ("005",
   test_005)

 DEF_TEST_DESCR
  ("006.err",
   test_006__err)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_029__CancelBlob__v1_no_lazy

void WORK_Test_029__CancelBlob__v1_no_lazy::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                       //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.029.CancelBlob.v1.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes__no_lazy[it[iPType]];

  ftestID
   <<structure::flush
   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
   <<sm_Tests[it[iTest]].pTestSign;

  const TTSO_TestPtr
   spTest
    (lib::structure::not_null_ptr
      (new TTSO_TestFunc_v2
        (pParams,
         ftestID.c_str(),
         sm_Tests[it[iTest]].Func,
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
