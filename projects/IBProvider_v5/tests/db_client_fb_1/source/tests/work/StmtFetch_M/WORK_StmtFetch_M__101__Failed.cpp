////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/StmtFetch_M/WORK_StmtFetch_M__101__Failed.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

#include <array>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__101__Failed::tag_impl

class WORK_StmtFetch_M__101__Failed::tag_impl LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef tag_impl                          self_type;

  tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public:
  tag_impl(TTSO_GlobalContext*     pParams,
           const char*             pTestID,
           const TTSO_TestData_v2& Data,
           size_t                  cBlocks,
           int                     cRows,
           size_t                  cPass);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

 private:
  const TTSO_TestData_v2 m_Data;
  const size_t           m_cBlocks;
  const int              m_cRows;
  const size_t           m_cPass;
};//class WORK_StmtFetch_M__101__Failed::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__101__Failed::tag_impl

WORK_StmtFetch_M__101__Failed::tag_impl::tag_impl
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const TTSO_TestData_v2&   Data,
                                            size_t              const cBlocks,
                                            int                 const cRows,
                                            size_t              const cPass)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Data(Data)
 ,m_cBlocks(cBlocks)
 ,m_cRows(cRows)
 ,m_cPass(cPass)
{
 assert(m_spParams);
 assert(cPass>0);
}//tag_impl

//------------------------------------------------------------------------
WORK_StmtFetch_M__101__Failed::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_StmtFetch_M__101__Failed::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_StmtFetch_M__101__Failed::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_StmtFetch_M__101__Failed::tag_impl::run(context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(m_spParams);

 params.set_dbprop_init__location(svc::BuildLocationString(m_spParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 m_Data.SetParams(params);

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

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block\n"
    "returns(X INTEGER)\n"
    "AS\n"
    "BEGIN\n"
    " X=-1234; SUSPEND;\n"
    "END;");

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=0;
 short                   columnInd=0;

 // xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 // xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqlsubtype =0;
 // xsqlda->sqlvar[0].sqlscale   =0;
 // xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 // xsqlda->sqlvar[0].sqlind     =&columnInd;
 //
 // xsqlda->sqld=1;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,12> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
  //---- value [long]
  0xAF,
  0xAF,
  0xAF,
  0xAF,
  //---- indicator [short]
  0xFE,
  0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 const bool fetchResult
  =svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);

 _TSO_CHECK(fetchResult)

  //----------------------------------------
  assert_s(sizeof(columnValue)==4);

  memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

  //---------
  assert_s(sizeof(columnInd)==2);

  memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

  //---------
 _TSO_CHECK(columnValue==-1234);
 _TSO_CHECK(columnInd==0);

 //-----------------------------------------
 _TSO_CHECK(hStmt->m_spFetchResult);

 const size_t blockSize=hStmt->m_spFetchResult->m_RequestedFetchCount;

 tracer<<L"BLOCK SIZE: "<<blockSize<<send;

 _TSO_CHECK(blockSize>0);

 size_t nGenRows=m_cBlocks*blockSize;

 _TSO_CHECK(m_cRows>=0 || size_t(-m_cRows)<=nGenRows);

 nGenRows+=m_cRows;

 tracer<<L"Gen rows count:"<<nGenRows<<send;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 structure::str_formatter
  fsql("execute block\n"
       "returns(X INTEGER)\n"
       "AS\n"
       "BEGIN\n"
       " X=%1;\n"
       " while(X>0)do BEGIN SUSPEND; X=X-1; END\n"
       " EXCEPTION EXC__SP_PAUSE_FETCH_ERR;\n"
       "END;");

 fsql<<nGenRows;

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   fsql.c_str());

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 tracer<<L"Fetch test rows"<<send;

 for(size_t v=nGenRows;v>0;--v)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M_ToRow
    (spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);
  }
  catch(...)
  {
   tracer(tso_msg_error,-1)<<L"We wait the row with ["<<v<<"] value"<<send;

   throw;
  }//catch

  _TSO_CHECK(hStmt);

  //--------------------------
  assert_s(sizeof(columnValue)==4);

  memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

  //---------
  assert_s(sizeof(columnInd)==2);

  memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

  //---------
  _TSO_CHECK_MSG(columnValue==v,"columnValue="<<columnValue);

  _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);
 }//for v [back]

 //-----------------------------------------
 for(size_t pass=0;pass!=m_cPass;)
 {
  ++pass;

  tracer<<L"-------------------------------- "<<pass<<send;

  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_code(exc.com_code(),E_FAIL);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(0),
     spConnector->GetData()->m_DBMS_Name,
     L"SP_PAUSE_FETCH_ERR");

   continue;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_spFetchResult->m_State==hStmt->m_spFetchResult->state__failed);

 _TSO_CHECK(hStmt->m_spFetchResult->m_spFetchExc); 

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

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
}//run

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__101__Failed

void WORK_StmtFetch_M__101__Failed::create(TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 struct tagS
 {
  size_t cBlocks;
  int    cRows;
 }
  const dataS[]=
 {
  {0,0},
  {0,1},
  {1,-1},
  {1,0},
  {1,1},
  {2,-1},
  {2,0},
  {2,1},
  {3,0},
  {100,17},
 };//dataS

 const size_t dataPass[]=
 {
  1,
  2,
  3,
 };//dataPass

 //-----------------------------------------
 typedef structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it_type;

 it_type it;

 it.add(0,_DIM_(dataPass)-1);
 it.add(0,_DIM_(dataS)-1);
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.StmtFetch_M.101.ptype__%1.cBlocks_%2.cRows_%3.cPass_%4");

 TTSO_TestData_v2 Data;

 for(it.restart();it;++it)
 {
  const auto& P=dataPass[it[0]];
  const auto& S=dataS[it[1]];

  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[2]];

  ftestID
   <<structure::flush
   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
   <<S.cBlocks
   <<S.cRows
   <<P;

  const TTSO_TestPtr
   spTest
    (structure::not_null_ptr
      (new tag_impl
        (pParams,
         ftestID.c_str(),
         Data,
         S.cBlocks,
         S.cRows,
         P)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
