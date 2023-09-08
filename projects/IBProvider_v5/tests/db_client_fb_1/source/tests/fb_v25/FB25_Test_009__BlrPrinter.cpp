////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/fb_v25/FB25_Test_009__BlrPrinter.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/test_func.h"
#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__blr_printer.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class FB25_Test_009__BlrPrinter::tag_impl

class FB25_Test_009__BlrPrinter::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__sp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002__trigger
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003__view
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  static void helper__exec
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx,
                const char*         SysTableName,
                const char*         SysColWithNAME,
                const char*         SysColWithBLR);

 private:
  class tag_printer_data
  {
   private:
    typedef tag_printer_data     self_type;

    tag_printer_data(const self_type&);
    self_type& operator = (const self_type&);

   public:
    TTSO_Tracer& m_tracer;
    std::string  m_str;

    tag_printer_data(TTSO_Tracer& tracer)
     :m_tracer(tracer)
    {;}
  };//class tag_printer_data

  static void blr_printer(void*       arg,
                          size_t      offset,
                          const char* line);
};//class FB25_Test_009__BlrPrinter::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void FB25_Test_009__BlrPrinter::tag_impl::test_001__sp
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper__exec(pParams,
              pCtx,
              "RDB$PROCEDURES",
              "RDB$PROCEDURE_NAME",
              "RDB$PROCEDURE_BLR");
}//test_001__sp

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void FB25_Test_009__BlrPrinter::tag_impl::test_002__trigger
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper__exec(pParams,
              pCtx,
              "RDB$TRIGGERS",
              "RDB$TRIGGER_NAME",
              "RDB$TRIGGER_BLR");
}//test_002__trigger

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void FB25_Test_009__BlrPrinter::tag_impl::test_003__view
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper__exec(pParams,
              pCtx,
              "RDB$RELATIONS",
              "RDB$RELATION_NAME",
              "RDB$VIEW_BLR");
}//test_003__view

////////////////////////////////////////////////////////////////////////////////

void FB25_Test_009__BlrPrinter::tag_impl::helper__exec
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const char*         const SysTableName,
                                            const char*         const SysColWithNAME,
                                            const char*         const SysColWithBLR)
{
 assert(pParams);
 assert(pCtx);
 assert(SysTableName);

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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 structure::str_formatter fsql("select %2 as n, %3 as x from %1 where %3 is not null;");

 fsql<<SysTableName<<SysColWithNAME<<SysColWithBLR;

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (remote_fb::protocol::P_USHORT)cns.db_dialect_Ex.value(),
   fsql.str());

 //-----------------------------------------
 char objectName[128];

 db_obj::DB_IBBLOBID blobID;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen   =sizeof(objectName);
 xsqlda->sqlvar[0].sqldata  =objectName;
 xsqlda->sqlvar[0].sqlind   =nullptr;

 xsqlda->sqlvar[1].sqltype  =isc_api::ibp_isc_sql_blob;
 xsqlda->sqlvar[1].sqllen   =sizeof(blobID);
 xsqlda->sqlvar[1].sqldata  =reinterpret_cast<char*>(&blobID);
 xsqlda->sqlvar[1].sqlind   =nullptr;

 xsqlda->sqld=2;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 for(size_t n=0;spConnector->StmtFetch(OpCtx,&hStmt,xsqlda);)
 {
  ++n;

  std::string Name(objectName,_END_(objectName));

  structure::self_trimr(Name);

  tracer<<L"-------------------------------- "<<n<<". "<<Name<<send;

  svc::remote_fb_blob_handle_type hBlob(nullptr);

  spConnector->OpenBlob(&hTr,
                        &hBlob,
                        blobID);

  //----------------------------------------
  std::vector<unsigned char> blr;

  structure::t_typed_simple_buffer<unsigned char,TTSO_MemoryAllocator> block(8192);

  for(;;)
  {
   size_t cbActualReaded=0;

   const bool r=spConnector->ReadBlob(&hBlob,
                                      block.size(),
                                      block.buffer(),
                                      &cbActualReaded);

   _TSO_CHECK(cbActualReaded<=block.size());

   blr.insert(blr.end(),
              block.buffer(),
              block.buffer()+cbActualReaded);

   if(!r)
    break;
  }//for[ever]

  //----------------------------------------
  spConnector->CloseBlob(&hBlob);

  //----------------------------------------
  tracer<<"blr size: "<<blr.size()<<send;

  tracer<<send;

  tracer<<L"process BLR code ..."<<send;

  tracer<<send;

  tag_printer_data pdata(tracer);

  try
  {
   ibp::db_obj::dbms_fb::v02_5_0::fb_v02_5_0__blr_printer::exec
    (blr.data(),
     blr.size(),
     self_type::blr_printer,
     &pdata,
     /*language*/0);
  }
  catch(...)
  {
   TTSO_ExceptionRouter::route(tracer);
  }//

  tracer<<send;

  tracer<<"\n\n"<<pdata.m_str<<"\n"<<send;
 }//for

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//helper__exec

//------------------------------------------------------------------------
void FB25_Test_009__BlrPrinter::tag_impl::blr_printer(void*       const arg,
                                                      size_t      const offset,
                                                      const char* const line)
{
 assert(arg);
 assert(line);

 tag_printer_data* const pData(reinterpret_cast<tag_printer_data*>(arg));

 pData->m_tracer<<line<<send;

 if(!pData->m_str.empty())
  pData->m_str+="\n";

 pData->m_str+=line;
}//blr_printer

////////////////////////////////////////////////////////////////////////////////
//struct FB25_Test_009__BlrPrinter::tag_descr

struct FB25_Test_009__BlrPrinter::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class FB25_Test_009__BlrPrinter::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,FB25_Test_009__BlrPrinter::tag_impl::func},

const FB25_Test_009__BlrPrinter::tag_descr
 FB25_Test_009__BlrPrinter::sm_Tests[]=
{
 DEF_TEST_DESCR("001.sp",
                test_001__sp)

 DEF_TEST_DESCR("002.trigger",
                test_002__trigger)

 DEF_TEST_DESCR("003.view",
                test_003__view)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class FB25_Test_009__BlrPrinter

void FB25_Test_009__BlrPrinter::create(TTSO_PushTest*      const pTestPusher,
                                           TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("FB25.Test_009.BlrPrinter.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr
   spTest(structure::not_null_ptr
           (new TTSO_TestFunc(pParams,
                              ftestID.c_str(),
                              d.Func,
                              "SRV<FB-3")));

  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
