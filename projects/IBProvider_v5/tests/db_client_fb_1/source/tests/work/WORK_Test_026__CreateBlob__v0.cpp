////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_026__CreateBlob__v0.h"
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
#include <structure/t_dynamic_array.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_026__CreateBlob__v0::tag_impl

class WORK_Test_026__CreateBlob__v0::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__err__too_long_bpb
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__no_params
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__create_segmented_blob
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__create_streamed_blob
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static void helper_003
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data,
                unsigned char           blobType);
};//class WORK_Test_026__CreateBlob__v0::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_026__CreateBlob__v0::tag_impl::test_001__err__too_long_bpb
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle  hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 //-----------------------------------------
 typedef structure::t_dynamic_array
  <remote_fb::protocol::P_UCHAR,TTSO_MemoryAllocator>      bpb_type;

 bpb_type BPB(size_t(USHRT_MAX)+1);

 std::fill(BPB.begin(),BPB.end(),0);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CreateBlob(tracer,
                                       spConnector,
                                       &hTr,
                                       &hBlob,
                                       &blobId,
                                       BPB.size(),
                                       BPB.data());
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__common_err__formed_buf_is_too_large
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb_p12,
     L"BPB",
     size_t(USHRT_MAX)+1,
     USHRT_MAX);

   _TSO_CHECK(!hBlob);

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
}//test_001__err__too_long_bpb

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_026__CreateBlob__v0::tag_impl::test_002__no_params
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 const remote_fb::protocol::P_UCHAR BPB[]=
 {
  isc_api::ibp_isc_bpb_version1,
 };//BPB

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 svc::RemoteFB_Connector__CreateBlob(tracer,
                                     spConnector,
                                     &hTr,
                                     &hBlob,
                                     &blobId,
                                     _DIM_(BPB),
                                     BPB);

 //-----------------------------------------
 const char c_testData[]={1,2,3};

 svc::RemoteFB_Connector__WriteBlob(tracer,
                                    spConnector,
                                    &hBlob,
                                    sizeof(c_testData),
                                    c_testData);

 //-----------------------------------------
 svc::RemoteFB_Connector__CloseBlob(tracer,
                                    spConnector,
                                    &hBlob);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

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
   static_cast<unsigned short>(cns.db_dialect_Ex.value()),
   "insert into BIN_BLOB_TABLE (BIN_DATA) values (?) returning BIN_DATA;");

 //-----------------------------------------
 XSQLDA_V1_Wrapper inXSQLDA(1);

 inXSQLDA->sqlvar[0].sqltype   =isc_api::ibp_isc_sql_blob;
 inXSQLDA->sqlvar[0].sqllen    =sizeof(blobId);
 inXSQLDA->sqlvar[0].sqldata   =reinterpret_cast<char*>(&blobId);

 inXSQLDA->sqld=1;

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobId2={};

 XSQLDA_V1_Wrapper outXSQLDA(1);

 outXSQLDA->sqlvar[0].sqltype   =isc_api::ibp_isc_sql_blob;
 outXSQLDA->sqlvar[0].sqllen    =sizeof(blobId2);
 outXSQLDA->sqlvar[0].sqldata   =reinterpret_cast<char*>(&blobId2);

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

 //-----------------------------------------
 svc::RemoteFB_Connector__OpenBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   blobId2);

 //-----------------------------------------
 const remote_fb::protocol::P_UCHAR queryIDs[]=
 {
  isc_api::ibp_isc_info_blob_type,
 };//queryIDs

 remote_fb::RemoteFB__InfoBuffer infoBuf;

 svc::RemoteFB_Connector__GetBlobInfo
  (tracer,
   spConnector,
   &hBlob,
   _DIM_(queryIDs),
   queryIDs,
   infoBuf);

 //-----------------------------------------
 _TSO_CHECK(infoBuf.size()==5);

 _TSO_CHECK(infoBuf[0]==isc_api::ibp_isc_info_blob_type);
 _TSO_CHECK(infoBuf[1]==1);
 _TSO_CHECK(infoBuf[2]==0);
 _TSO_CHECK(infoBuf[3]==isc_api::ibp_isc_bpb_type_segmented);
 _TSO_CHECK(infoBuf[4]==isc_api::ibp_isc_info_end);

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

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__no_params

////////////////////////////////////////////////////////////////////////////////
//TEST 003 - segmented blob

void WORK_Test_026__CreateBlob__v0::tag_impl::test_003__create_segmented_blob
                                           (TTSO_GlobalContext*     pParams,
                                            context_type*           pCtx,
                                            const TTSO_TestData_v2& Data)
{
 return helper_003(pParams,
                   pCtx,
                   Data,
                   isc_api::ibp_isc_bpb_type_segmented);
}//test_003__create_segmented_blob

////////////////////////////////////////////////////////////////////////////////
//TEST 003 - streamed blob

void WORK_Test_026__CreateBlob__v0::tag_impl::test_003__create_streamed_blob
                                           (TTSO_GlobalContext*     pParams,
                                            context_type*           pCtx,
                                            const TTSO_TestData_v2& Data)
{
 return helper_003(pParams,
                   pCtx,
                   Data,
                   isc_api::ibp_isc_bpb_type_stream);
}//test_003__create_streamed_blob

////////////////////////////////////////////////////////////////////////////////
//TEST 003 - impl

void WORK_Test_026__CreateBlob__v0::tag_impl::helper_003
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data,
                                            unsigned char       const blobType)
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 const remote_fb::protocol::P_UCHAR BPB[]=
 {
  isc_api::ibp_isc_bpb_version1,
  isc_api::ibp_isc_bpb_type,
  /*length*/1,
  blobType,
 };//BPB

 //-----------------------------------------
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 db_obj::DB_IBBLOBID blobId={};

 svc::RemoteFB_Connector__CreateBlob(tracer,
                                     spConnector,
                                     &hTr,
                                     &hBlob,
                                     &blobId,
                                     _DIM_(BPB),
                                     BPB);

 //-----------------------------------------
 const char c_testData[]={1,2,3};

 svc::RemoteFB_Connector__WriteBlob(tracer,
                                    spConnector,
                                    &hBlob,
                                    sizeof(c_testData),
                                    c_testData);

 //-----------------------------------------
 svc::RemoteFB_Connector__CloseBlob(tracer,
                                    spConnector,
                                    &hBlob);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

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
   static_cast<unsigned short>(cns.db_dialect_Ex.value()),
   "insert into BIN_BLOB_TABLE (BIN_DATA) values (?) returning BIN_DATA;");

 //-----------------------------------------
 XSQLDA_V1_Wrapper inXSQLDA(1);

 inXSQLDA->sqlvar[0].sqltype   =isc_api::ibp_isc_sql_blob;
 inXSQLDA->sqlvar[0].sqllen    =sizeof(blobId);
 inXSQLDA->sqlvar[0].sqldata   =reinterpret_cast<char*>(&blobId);

 inXSQLDA->sqld=1;

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobId2={};

 XSQLDA_V1_Wrapper outXSQLDA(1);

 outXSQLDA->sqlvar[0].sqltype   =isc_api::ibp_isc_sql_blob;
 outXSQLDA->sqlvar[0].sqllen    =sizeof(blobId2);
 outXSQLDA->sqlvar[0].sqldata   =reinterpret_cast<char*>(&blobId2);

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

 //-----------------------------------------
 svc::RemoteFB_Connector__OpenBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   blobId2);

 //-----------------------------------------
 const remote_fb::protocol::P_UCHAR queryIDs[]=
 {
  isc_api::ibp_isc_info_blob_type,
 };//queryIDs

 remote_fb::RemoteFB__InfoBuffer infoBuf;

 svc::RemoteFB_Connector__GetBlobInfo
  (tracer,
   spConnector,
   &hBlob,
   _DIM_(queryIDs),
   queryIDs,
   infoBuf);

 //-----------------------------------------
 _TSO_CHECK(infoBuf.size()==5);

 _TSO_CHECK(infoBuf[0]==isc_api::ibp_isc_info_blob_type);
 _TSO_CHECK(infoBuf[1]==1);
 _TSO_CHECK(infoBuf[2]==0);
 _TSO_CHECK(infoBuf[3]==blobType);
 _TSO_CHECK(infoBuf[4]==isc_api::ibp_isc_info_end);

 //-----------------------------------------
 unsigned char blobData[4]={0xFD,0xFD,0xFD,0xFD};

 size_t cbActualReaded=0;

 const bool readResult=svc::RemoteFB_Connector__ReadBlob
                        (tracer,
                         spConnector,
                         &hBlob,
                         sizeof(blobData),
                         blobData,
                         &cbActualReaded);

 _TSO_CHECK(!readResult);

 _TSO_CHECK(cbActualReaded==3)

 _TSO_CHECK(blobData[0]==1);
 _TSO_CHECK(blobData[1]==2);
 _TSO_CHECK(blobData[2]==3);
 _TSO_CHECK(blobData[3]==0xFD);

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

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__no_params

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_026__CreateBlob__v0::tag_descr

struct WORK_Test_026__CreateBlob__v0::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_026__CreateBlob__v0::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_026__CreateBlob__v0::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_026__CreateBlob__v0::tag_descr
 WORK_Test_026__CreateBlob__v0::sm_Tests[]=
{
 DEF_TEST_DESCR2
  ("001.err.too_long_bpb",
   test_001__err__too_long_bpb,
   "!NE__PSET02")

 DEF_TEST_DESCR
  ("002.no_params",
   test_002__no_params)

 DEF_TEST_DESCR
  ("003.segmented",
   test_003__create_segmented_blob)

 DEF_TEST_DESCR
  ("003.streamed",
   test_003__create_streamed_blob)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_026__CreateBlob__v0

void WORK_Test_026__CreateBlob__v0::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                              //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.026.CreateBlob.v0.ptype__%1.%2");

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
}//namespace ibp_test
