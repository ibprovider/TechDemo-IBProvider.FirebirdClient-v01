////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_025__ReadBlob.h"
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
//class WORK_Test_025__ReadBlob::tag_impl

class WORK_Test_025__ReadBlob::tag_impl
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

  static void test_002
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__empty
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 #ifdef NDEBUG
  static void test_100__bug_check__closed_blob_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_101__bug_check__zero_blob_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_102__bug_check__bad_owner_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_103__err__read_from_new_blob
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

  static void test_200__err__hack_close_blob
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_read_blob_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_read_blob_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_025__ReadBlob::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_025__ReadBlob::tag_impl::test_001
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
   "execute block returns (x blob) as begin x=x'FFEEDD'; suspend; end;");

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
 unsigned char Buffer[3]={};

 size_t cbReaded=0;

 bool readResult=svc::RemoteFB_Connector__ReadBlob
                                           (tracer,
                                            spConnector,
                                            &hBlob,
                                            sizeof(Buffer),
                                            Buffer,
                                            &cbReaded);
 _TSO_CHECK(hBlob);

 _TSO_CHECK(cbReaded==3);

 _TSO_CHECK(Buffer[0]==0xFF);
 _TSO_CHECK(Buffer[1]==0xEE);
 _TSO_CHECK(Buffer[2]==0xDD);

 _TSO_CHECK(!readResult);

 //-----------------------------------------
 readResult=svc::RemoteFB_Connector__ReadBlob
                                      (tracer,
                                       spConnector,
                                       &hBlob,
                                       sizeof(Buffer),
                                       Buffer,
                                       &cbReaded);
 _TSO_CHECK(hBlob);

 _TSO_CHECK(cbReaded==0);

 _TSO_CHECK(Buffer[0]==0xFF);
 _TSO_CHECK(Buffer[1]==0xEE);
 _TSO_CHECK(Buffer[2]==0xDD);

 _TSO_CHECK(!readResult);

 //-----------------------------------------
 _TSO_CHECK(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hBlob->m_ID.is_null());
 _TSO_CHECK(hBlob->m_pParentTr==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_025__ReadBlob::tag_impl::test_002
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
   "execute block returns (x blob) as begin x=x'FFEEDD'; suspend; end;");

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
 const unsigned char TestData[3]={0xFF,0xEE,0xDD};

 for(size_t i=0;i!=_DIM_(TestData);++i)
 {
  unsigned char Buffer[1]={};

  size_t cbReaded=0;

  const bool readResult=svc::RemoteFB_Connector__ReadBlob
                                           (tracer,
                                            spConnector,
                                            &hBlob,
                                            sizeof(Buffer),
                                            Buffer,
                                            &cbReaded);
  _TSO_CHECK(hBlob);

  _TSO_CHECK(cbReaded==1);

  _TSO_CHECK(Buffer[0]==TestData[i]);

  if(i==(_DIM_(TestData)-1))
  {
   _TSO_CHECK(!readResult); //EOF
  }
  else
  {
   _TSO_CHECK(readResult);
  }
 }//for i

 //-----------------------------------------
 unsigned char Buffer[1]={0xEF};

 size_t cbReaded=0;

 const bool readResult=svc::RemoteFB_Connector__ReadBlob
                                           (tracer,
                                            spConnector,
                                            &hBlob,
                                            sizeof(Buffer),
                                            Buffer,
                                            &cbReaded);
 _TSO_CHECK(hBlob);

 _TSO_CHECK(cbReaded==0);

 _TSO_CHECK(Buffer[0]==0xEF);

 _TSO_CHECK(!readResult);

 //-----------------------------------------
 _TSO_CHECK(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hBlob->m_ID.is_null());
 _TSO_CHECK(hBlob->m_pParentTr==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void WORK_Test_025__ReadBlob::tag_impl::test_003__empty
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
   "execute block returns (x blob) as begin x=x''; suspend; end;");

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
 unsigned char Buffer[1]={0xEF};

 size_t cbReaded=0;

 const bool readResult=svc::RemoteFB_Connector__ReadBlob
                                           (tracer,
                                            spConnector,
                                            &hBlob,
                                            sizeof(Buffer),
                                            Buffer,
                                            &cbReaded);
 _TSO_CHECK(hBlob);

 _TSO_CHECK(cbReaded==0);

 _TSO_CHECK(Buffer[0]==0xEF);

 _TSO_CHECK(!readResult);

 //-----------------------------------------
 _TSO_CHECK(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hBlob->m_ID.is_null());
 _TSO_CHECK(hBlob->m_pParentTr==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_003__empty

////////////////////////////////////////////////////////////////////////////////
//TEST 100

#ifdef NDEBUG

void WORK_Test_025__ReadBlob::tag_impl::test_100__bug_check__closed_blob_handle
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
   "execute block returns (x blob) as begin x=x''; suspend; end;");

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

 _TSO_CHECK(hBlob->m_BlobMode==hBlob->BlobMode__Open);

 //-----------------------------------------
 {
  svc::remote_fb_blob_handle_type hBlobCopy(hBlob);

  svc::RemoteFB_Connector__CloseBlob(tracer,
                                     spConnector,
                                     &hBlobCopy);
 }//local

 _TSO_CHECK(!hBlob->m_ID.has_value());

 //� ������ lazy_send �����, ���� ���������� ���� � ������ ����������
 //_TSO_CHECK(hBlob->m_pParentTr==nullptr);

 {
  char tmp[100];

  size_t cbActualReaded=0;

  for(;;)
  {
   try
   {
    svc::RemoteFB_Connector__ReadBlob(tracer,
                                      spConnector,
                                      &hBlob,
                                      sizeof(tmp),
                                      tmp,
                                      &cbActualReaded);
   }
   catch(const ibp::t_ibp_error& exc)
   {
    typedef TestCheckErrors errSvc;

    errSvc::print_exception_ok(tracer,exc);

    errSvc::check_err_count(exc,1);

    _TSO_CHECK(exc.get_record(0))

    errSvc::check_err_rec__blob_err__read_from_closed_blob
     (tracer,
      exc.get_record(0),
      helper__get_read_blob_subsystem_id(spConnector));

    break;
   }//catch

   tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
   break;
  }//for[ever]
 }//local

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hBlob->m_ID.is_null());
 _TSO_CHECK(hBlob->m_pParentTr==nullptr);
 _TSO_CHECK(hBlob->m_pOwnerCnNClosedBlobList==nullptr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_100__bug_check__closed_blob_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 101

#ifdef NDEBUG

void WORK_Test_025__ReadBlob::tag_impl::test_101__bug_check__zero_blob_handle
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
 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 {
  char tmp[100];

  size_t cbActualReaded=0;

  for(;;)
  {
   try
   {
    svc::RemoteFB_Connector__ReadBlob(tracer,
                                      spConnector,
                                      &hBlob,
                                      sizeof(tmp),
                                      tmp,
                                      &cbActualReaded);
   }
   catch(const ibp::t_ibp_error& exc)
   {
    typedef TestCheckErrors errSvc;

    errSvc::print_exception_ok(tracer,exc);

    errSvc::check_err_count(exc,1);

    _TSO_CHECK(exc.get_record(0))

    errSvc::check_err_rec__blob_err__bug_check__bad_blob_handle
     (tracer,
      exc.get_record(0),
      helper__get_read_blob_bugcheck_src(spConnector),
      L"#001");

    break;
   }//catch

   tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
   break;
  }//for[ever]
 }//local

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_101__bug_check__zero_blob_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 102

#ifdef NDEBUG

void WORK_Test_025__ReadBlob::tag_impl::test_102__bug_check__bad_owner_cn
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
   "execute block returns (x blob) as begin x=x''; suspend; end;");

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

 _TSO_CHECK(hBlob->m_BlobMode==hBlob->BlobMode__Open);

 //-----------------------------------------
 {
  char tmp[100];

  size_t cbActualReaded=0;

  for(;;)
  {
   try
   {
    svc::RemoteFB_Connector__ReadBlob(tracer,
                                      spConnector2,
                                      &hBlob,
                                      sizeof(tmp),
                                      tmp,
                                      &cbActualReaded);
   }
   catch(const ibp::t_ibp_error& exc)
   {
    typedef TestCheckErrors errSvc;

    errSvc::print_exception_ok(tracer,exc);

    errSvc::check_err_count(exc,1);

    _TSO_CHECK(exc.get_record(0))

    errSvc::check_err_rec__blob_err__bug_check__bad_blob_handle
     (tracer,
      exc.get_record(0),
      helper__get_read_blob_bugcheck_src(spConnector),
      L"#003");

    break;
   }//catch

   tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
   break;
  }//for[ever]
 }//local

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
}//test_102__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 103

#ifdef NDEBUG

void WORK_Test_025__ReadBlob::tag_impl::test_103__err__read_from_new_blob
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
 {
  char tmp[100];

  size_t cbActualReaded=0;

  for(;;)
  {

   try
   {
    svc::RemoteFB_Connector__ReadBlob(tracer,
                                      spConnector,
                                      &hBlob,
                                      sizeof(tmp),
                                      tmp,
                                      &cbActualReaded);
   }
   catch(const ibp::t_ibp_error& exc)
   {
    typedef TestCheckErrors errSvc;

    errSvc::print_exception_ok(tracer,exc);

    errSvc::check_err_count(exc,1);

    _TSO_CHECK(exc.get_record(0))

    errSvc::check_err_rec__blob_err__bug_check__wrong_blob_handle_mode
     (tracer,
      exc.get_record(0),
      helper__get_read_blob_bugcheck_src(spConnector),
      L"#004",
      2);

    //------
    break;
   }//catch

   tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
   break;
  }//for[ever]
 }//local

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_103__err__read_from_new_blob

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 200

void WORK_Test_025__ReadBlob::tag_impl::test_200__err__hack_close_blob
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
   "execute block returns (x blob) as begin x=x''; suspend; end;");

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

 _TSO_CHECK(hBlob->m_BlobMode==hBlob->BlobMode__Open);

 //-----------------------------------------
 svc::HACK__CloseBlob(tracer,
                      spConnector,
                      &hBlob);

 {
  char tmp[100];

  size_t cbActualReaded=0;

  for(size_t pass=0;pass!=3;)
  {
   ++pass;

   tracer<<L"------------------------------- pass: "<<pass<<send;

   try
   {
    svc::RemoteFB_Connector__ReadBlob(tracer,
                                      spConnector,
                                      &hBlob,
                                      sizeof(tmp),
                                      tmp,
                                      &cbActualReaded);
   }
   catch(const ibp::t_ibp_error& exc)
   {
    typedef TestCheckErrors errSvc;

    errSvc::print_exception_ok(tracer,exc);

    errSvc::check_err_count(exc,1);

    _TSO_CHECK(exc.get_record(0))

    errSvc::check_err_rec__srv_err__invalid_blob_handle
     (tracer,
      spConnector->GetData()->m_DBMS_Name,
      exc.get_record(0));

    //------
    _TSO_CHECK(hBlob);

    _TSO_CHECK(hBlob->m_ReadMode__State==hBlob->ReadState__Failed);

    continue;
   }//catch

   tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
   break;
  }//for pass
 }//local

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_200__err__hack_close_blob

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_025__ReadBlob::tag_impl::helper__get_read_blob_bugcheck_src
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
  {
   if(pConnector->GetPort()->TestPortFlag__rpc())
    return L"RemoteFB__API_P12_RPC__ReadBlob::exec";

   return L"RemoteFB__API_P12__ReadBlob::exec";
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__ReadBlob::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_read_blob_bugcheck_src

//------------------------------------------------------------------------
const wchar_t* WORK_Test_025__ReadBlob::tag_impl::helper__get_read_blob_subsystem_id
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
}//helper__get_read_blob_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_025__ReadBlob::tag_descr

struct WORK_Test_025__ReadBlob::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;

  bool        allow__ptype_rpc;
};//class WORK_Test_025__ReadBlob::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,                                   \
                       func,                                   \
                       allow__ptype_rpc)                       \
 {sign,                                                        \
  WORK_Test_025__ReadBlob::tag_impl::func,            \
  allow__ptype_rpc},

const WORK_Test_025__ReadBlob::tag_descr
 WORK_Test_025__ReadBlob::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test_001,
   false)

 DEF_TEST_DESCR
  ("002",
   test_002,
   false)

 DEF_TEST_DESCR
  ("003.empty",
   test_003__empty,
   false)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("100.bug_check.closed_blob_handle",
   test_100__bug_check__closed_blob_handle,
   true)

 DEF_TEST_DESCR
  ("101.bug_check.zero_blob_handle",
   test_101__bug_check__zero_blob_handle,
   true)

 DEF_TEST_DESCR
  ("102.bug_check.bad_owner_cn",
   test_102__bug_check__bad_owner_cn,
   true)

 DEF_TEST_DESCR
  ("103.bug_check.read_from_new_blob",
   test_103__err__read_from_new_blob,
   true)
#endif

 DEF_TEST_DESCR
  ("200.err.hack_close_blob",
   test_200__err__hack_close_blob,
   true)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_025__ReadBlob

void WORK_Test_025__ReadBlob::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.025.ReadBlob.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes));

  //----------------------------------------
  const auto& TestDescr=sm_Tests[it[iTest]];

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes[it[iPType]];

  //----------------------------------------
  if(Data.m_RemoteFB__ProtocolType.value()==ibprovider::ibp_propval__remote__ptype__rpc)
  {
   if(!TestDescr.allow__ptype_rpc)
    continue;
  }//if

  //----------------------------------------
  ftestID
   <<structure::flush
   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
   <<TestDescr.pTestSign;

  const TTSO_TestPtr spTest
   (structure::not_null_ptr
     (new TTSO_TestFunc_v2
       (pParams,
        ftestID.c_str(),
        TestDescr.Func,
        Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
