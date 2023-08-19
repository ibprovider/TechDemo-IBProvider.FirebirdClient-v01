////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_026__CreateBlob__v1_no_lazy.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl

class WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
 #ifdef NDEBUG
  static void test_001__bug_check__bad_owner_cn_of_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__bug_check__bad_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__bug_check__no_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__bug_check__not_zero_blob_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

  static void test_004__empty_blob
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__err__bad_trans_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_create_blob_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::test_001__bug_check__bad_owner_cn_of_tr
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

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
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CreateBlob
    (tracer,
     spConnector2,
     &hTr,
     &hBlob,
     &blobId);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_create_blob_bugcheck_src(spConnector),
     L"#004");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector2);
}//test_001__bug_check__bad_owner_cn_of_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::test_002__bug_check__bad_tr
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
 remote_fb::handles::RemoteFB__TrHandle hTr_copy(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr_copy);

 _TSO_CHECK(!hTr_copy);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CreateBlob
    (tracer,
     spConnector,
     &hTr,
     &hBlob,
     &blobId);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_create_blob_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__bug_check__bad_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::test_003__bug_check__no_tr
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

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CreateBlob
    (tracer,
     spConnector,
     &hTr,
     &hBlob,
     &blobId);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_create_blob_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_003__bug_check__no_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

#ifdef NDEBUG

void WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::test_004__bug_check__not_zero_blob_handle
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
 remote_fb::handles::RemoteFB__BlobHandle
  hBlob(remote_fb::handles::RemoteFB__HandleData_Blob::Create(remote_fb::handles::RemoteFB__HandleData_Blob::BlobMode__Create));

 db_obj::DB_IBBLOBID blobId={};

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CreateBlob
    (tracer,
     spConnector,
     &hTr,
     &hBlob,
     &blobId);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__blob_err__bug_check__blob_handle_not_zero
    (tracer,
     exc.get_record(0),
     helper__get_create_blob_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__bug_check__not_zero_blob_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::test_004__empty_blob
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
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 //-----------------------------------------
 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobId);

 _TSO_CHECK(hBlob);

 _TSO_CHECK(hBlob->m_pParentTr==hTr.ptr());

 _TSO_CHECK(hBlob->m_ID.has_value());

 _TSO_CHECK(hTr);

 tracer<<L"blobID: ["<<blobId.high<<L":"<<blobId.low<<L"]"<<send;

 //-----------------------------------------
 svc::RemoteFB_Connector__CloseBlob
  (tracer,
   spConnector,
   &hBlob);

 _TSO_CHECK(!hBlob);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<short>(cns.db_dialect_Ex.value()),
   "insert into BIN_BLOB_TABLE (BIN_DATA) values (?) returning BIN_DATA;");

 //-----------------------------------------
 XSQLDA_V1_Wrapper inXSQLDA(1);

 inXSQLDA->sqlvar[0].sqltype   =isc_api::ibp_isc_sql_blob;
 inXSQLDA->sqlvar[0].sqlsubtype=0;
 inXSQLDA->sqlvar[0].sqllen    =sizeof(blobId);
 inXSQLDA->sqlvar[0].sqldata   =reinterpret_cast<char*>(&blobId);
 inXSQLDA->sqlvar[0].sqlind    =nullptr;

 inXSQLDA->sqld=1;

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobId2={};

 XSQLDA_V1_Wrapper outXSQLDA(1);

 outXSQLDA->sqlvar[0].sqltype   =isc_api::ibp_isc_sql_blob;
 outXSQLDA->sqlvar[0].sqlsubtype=0;
 outXSQLDA->sqlvar[0].sqllen    =sizeof(blobId2);
 outXSQLDA->sqlvar[0].sqldata   =reinterpret_cast<char*>(&blobId2);
 outXSQLDA->sqlvar[0].sqlind    =nullptr;

 outXSQLDA->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   inXSQLDA,
   outXSQLDA);

 tracer<<L"blobID2: ["<<blobId2.high<<L":"<<blobId2.low<<L"]"<<send;

 //-----------------------------------------
 _TSO_CHECK(!hBlob);

 svc::RemoteFB_Connector__OpenBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   blobId2);

 //-----------------------------------------
 {
  char tmp[100]={};

  size_t cbActualReaded=0;

  const bool readResult
   =svc::RemoteFB_Connector__ReadBlob
     (tracer,
      spConnector,
      &hBlob,
      sizeof(tmp),
      tmp,
      &cbActualReaded);

  _TSO_CHECK(!readResult);

  _TSO_CHECK(cbActualReaded==0);
 }//local

 //-----------------------------------------
 {
  remote_fb::RemoteFB__InfoBuffer infoBuf;

  const unsigned char tagIDs[]={isc_api::ibp_isc_info_blob_total_length};

  svc::RemoteFB_Connector__GetBlobInfo
   (tracer,
    spConnector,
    &hBlob,
    sizeof(tagIDs),
    tagIDs,
    infoBuf);

  _TSO_CHECK(infoBuf.size()>0);

  {
   unsigned char*             p =infoBuf.buffer();
   const unsigned char* const pe=infoBuf.buffer_end();

   _TSO_CHECK((*p)==isc_api::ibp_isc_info_blob_total_length);

   ++p;

   _TSO_CHECK(p<pe);

   size_t cluster_len=0;

   assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(cluster_len));

   _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
               (isc_api::ibp_isc__info_tag__data_length__byte_count,
                p,
                &cluster_len));

   p+=isc_api::ibp_isc__info_tag__data_length__byte_count; //skeep cluster len

   _TSO_CHECK(!(size_t(pe-p)<cluster_len))

   size_t blob_length=0;

   _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r(cluster_len,p,&blob_length));

   p+=cluster_len;

   _TSO_CHECK(p<pe);

   _TSO_CHECK((*p)==isc_api::ibp_isc_info_end);

   _TSO_CHECK(blob_length==0);
  }//local
 }//local

 //-----------------------------------------
 svc::RemoteFB_Connector__CloseBlob
  (tracer,
   spConnector,
   &hBlob);

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
}//test_004__empty_blob

////////////////////////////////////////////////////////////////////////////////

void WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::test_005__err__bad_trans_handle
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
 remote_fb::handles::RemoteFB__BlobHandle  hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 //-----------------------------------------
 svc::HACK__CommitTr
  (tracer,
   spConnector,
   &hTr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CreateBlob
    (tracer,
     spConnector,
     &hTr,
     &hBlob,
     &blobId);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__bad_tr_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   _TSO_CHECK(!hBlob);

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005__err__bad_trans_handle

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::helper__get_create_blob_bugcheck_src
                                           (remote_fb::RemoteFB__Connector* pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
   return L"RemoteFB__API_P12__CreateBlob::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__CreateBlob::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_create_blob_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_026__CreateBlob__v1_no_lazy::tag_descr

struct WORK_Test_026__CreateBlob__v1_no_lazy::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Test_026__CreateBlob__v1_no_lazy::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Test_026__CreateBlob__v1_no_lazy::tag_impl::func},

const WORK_Test_026__CreateBlob__v1_no_lazy::tag_descr
 WORK_Test_026__CreateBlob__v1_no_lazy::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.bad_owner_cn_of_tr",
   test_001__bug_check__bad_owner_cn_of_tr)

 DEF_TEST_DESCR
  ("002.bug_check.bad_tr",
   test_002__bug_check__bad_tr)

 DEF_TEST_DESCR
  ("003.bug_check.no_tr",
   test_003__bug_check__no_tr)

 DEF_TEST_DESCR
  ("004.bug_check.not_zero_blob_handle",
   test_004__bug_check__not_zero_blob_handle)
#endif

 DEF_TEST_DESCR
  ("004.empty_blob",
   test_004__empty_blob)

 DEF_TEST_DESCR
  ("005.err.bad_trans_handle",
   test_005__err__bad_trans_handle)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_026__CreateBlob__v1_no_lazy

void WORK_Test_026__CreateBlob__v1_no_lazy::create
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
 structure::str_formatter ftestID("RemoteFB.WORK.026.CreateBlob.v1.ptype__%1.%2");

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
    (structure::not_null_ptr
      (new TTSO_TestFunc_v2
        (pParams,
         ftestID.c_str(),
         sm_Tests[it[iTest]].Func,
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
