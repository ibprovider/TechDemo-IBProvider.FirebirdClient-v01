////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/StmtFetch_M/WORK_StmtFetch_M__103__MARS.h"
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
//struct WORK_StmtFetch_M__103__MARS::tag_rs_descr

struct WORK_StmtFetch_M__103__MARS::tag_rs_descr
{
 size_t cBlocks;
 int    cRows;
};//WORK_StmtFetch_M__103__MARS::tag_rs_descr

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__103__MARS::tag_impl

class WORK_StmtFetch_M__103__MARS::tag_impl
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef tag_impl                                     self_type;

  tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

  typedef TTSO_MemoryAllocator                         allocator_type;
  typedef structure::t_stl_vector
           <tag_rs_descr,
            allocator_type>                            rs_descrs_type;

 public:
  rs_descrs_type m_ResultSets;

 public:
  tag_impl(TTSO_GlobalContext*     pParams,
           const char*             pTestID,
           const TTSO_TestData_v2& Data);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  class tag_cursor_data
  {
   public:
    typedef remote_fb::handles::RemoteFB__StmtHandle stmt_handle_type;

   public:
    stmt_handle_type  hStmt;
    size_t            beginV;
    size_t            endV;

   public:
    tag_cursor_data()
     :hStmt(nullptr)
     ,beginV(0)
     ,endV(0)
    {;}
  };//class tag_cursor_data

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  const TTSO_TestData_v2 m_Data;
};//class WORK_StmtFetch_M__103__MARS::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__103__MARS::tag_impl

WORK_StmtFetch_M__103__MARS::tag_impl::tag_impl
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const TTSO_TestData_v2&   Data)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Data(Data)
{
 assert(m_spParams);
}//tag_impl

//------------------------------------------------------------------------
WORK_StmtFetch_M__103__MARS::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_StmtFetch_M__103__MARS::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_StmtFetch_M__103__MARS::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_StmtFetch_M__103__MARS::tag_impl::run(context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);
 assert(m_ResultSets.size()>0);

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
 structure::t_stl_vector<tag_cursor_data,allocator_type>
  Cursors(m_ResultSets.size());

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
 {
  svc::remote_fb_stmt_handle_type hTempStmt(nullptr);

  svc::RemoteFB_Connector__StmtAllocate
   (tracer,
    spConnector,
    &hTempStmt);

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hTempStmt,
    static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block returns (X integer) as begin X=987654321;SUSPEND; END;");

  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hTempStmt,
    /*in*/nullptr,
    /*out*/nullptr);

  //-----------------------------------------
  bool fetchResult
   =svc::RemoteFB_Connector__StmtFetch_M
     (tracer,
      spConnector,
      OpCtx,
      &hTempStmt,
      &OutMsg);

  _TSO_CHECK(hTempStmt);

  _TSO_CHECK(fetchResult);

  //----------------------------------------
  assert_s(sizeof(columnValue)==4);

  memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

  //---------
  assert_s(sizeof(columnInd)==2);

  memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

  //---------
  _TSO_CHECK_MSG(columnValue==987654321,"columnValue="<<columnValue);

  _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);

   //----------------------------------------
  _TSO_CHECK(hTempStmt->m_spFetchResult);

  const size_t blockSize=hTempStmt->m_spFetchResult->m_RequestedFetchCount;

  tracer<<L"BLOCK SIZE: "<<blockSize<<send;

  _TSO_CHECK(blockSize>0);

  //----------------------------------------
  const char* const c_sql_templ
   ="execute block\n"
    "returns(X INTEGER)\n"
    "as\n"
    "begin\n"
      " X=%1;\n"
      " while(X<%2)do begin suspend; X=X+1; end\n"
     "end;";

  structure::str_formatter fSQL(c_sql_templ);

  //----------------------------------------
  size_t V=0;

  for(size_t x=0;x!=Cursors.size();++x)
  {
   tracer<<send;
   tracer<<L"Creation of cursor ["<<(x+1)<<L"]"<<send;

   //--------
   size_t nGenRows=m_ResultSets[x].cBlocks*blockSize;

   _TSO_CHECK(m_ResultSets[x].cRows>=0 || size_t(-m_ResultSets[x].cRows)<=nGenRows);

   nGenRows+=m_ResultSets[x].cRows;

   Cursors[x].beginV=V;

   Cursors[x].endV=V+nGenRows;

   V+=/*rnd*/587+nGenRows;

   tracer<<L"Values range: ["<<Cursors[x].beginV<<L":"<<Cursors[x].endV<<L") - "<<nGenRows<<L" row(s)"<<send;

   _TSO_CHECK(Cursors[x].beginV<=Cursors[x].endV);

   //--------
   svc::RemoteFB_Connector__StmtAllocate
    (tracer,
     spConnector,
     &Cursors[x].hStmt);

   //--------
   fSQL<<structure::flush
       <<Cursors[x].beginV
       <<Cursors[x].endV;

   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &Cursors[x].hStmt,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     fSQL.str());

   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &Cursors[x].hStmt,
     /*in*/nullptr,
     /*out*/nullptr);
  }//for each Cursors

  tracer<<send;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtDrop
   (tracer,
    spConnector,
    &hTempStmt);

  tracer<<send;
 }//local

 tracer<<L"Start fetch from cursors ..."<<send;

 //-----------------------------------------
 for(size_t cActiveCursors=Cursors.size(),iRow=0;cActiveCursors>0;++iRow)
 {
  for(size_t iCursor=0;iCursor!=Cursors.size();++iCursor)
  {
   if(!Cursors[iCursor].hStmt)
    continue;

   try
   {
    if((Cursors[iCursor].beginV+iRow)==Cursors[iCursor].endV)
    {
     svc::RemoteFB_Connector__StmtFetch_M_ToEOF
      (spConnector,
       OpCtx,
       &Cursors[iCursor].hStmt,
       &OutMsg);

     _TSO_CHECK(Cursors[iCursor].hStmt);

     svc::RemoteFB_Connector__StmtDrop
      (tracer,
       spConnector,
       &Cursors[iCursor].hStmt,
       structure::wstr_formatter(L"[%1]")<<(iCursor+1)<<structure::c_str);

     _TSO_CHECK(!Cursors[iCursor].hStmt);

     --cActiveCursors;

     continue;
    }//if

    svc::RemoteFB_Connector__StmtFetch_M_ToRow
     (spConnector,
      OpCtx,
      &Cursors[iCursor].hStmt,
      &OutMsg);

    //----------------------------------------
    assert_s(sizeof(columnValue)==4);

    memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

    //---------
    assert_s(sizeof(columnInd)==2);

    memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

    //---------
    if(columnInd!=0)
    {
     structure::str_formatter fmsg("incorrect columnInd: %1.");

     fmsg<<columnInd;

     throw std::runtime_error(fmsg.str());
    }//if

    const size_t expectedValue=Cursors[iCursor].beginV+iRow;

    if(columnValue!=expectedValue)
    {
     structure::str_formatter fmsg("incorrect value: %1. expected: %2.");

     fmsg<<columnValue<<expectedValue;

     throw std::runtime_error(fmsg.str());
    }//if
   }
   catch(...)
   {
    tracer<<L"Failed info:"<<send;
    tracer<<L"iRow:"<<iRow<<send;
    tracer<<L"iCursor:"<<iCursor<<send;

    throw;
   }
  }//for iCursor
 }//for cActiveCursors

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
//class WORK_StmtFetch_M__103__MARS

void WORK_StmtFetch_M__103__MARS::create(TTSO_PushTest*      const pTestPusher,
                                         TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 const tag_rs_descr dataS[]=
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

 const size_t dataCursorCount[]=
 {
  1,
  2,
  3,
  //4,
 };//dataCursorCount

 //-----------------------------------------
 typedef structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it_type;

 //-----------------------------------------
 it_type it;

 it.add(0,_DIM_(dataCursorCount)-1);                     //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);  //1

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.StmtFetch_M.103.MARS.ptype__%1.CursorCount_%2.%3");

 TTSO_TestData_v2 Data;

 size_t testNum=0;

 for(;it;++it)
 {
  const auto& cCursors=dataCursorCount[it[0]];

  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[1]];

  it_type it2;

  for(size_t x=0;x!=cCursors;++x)
   it2.add(0,_DIM_(dataS)-1);

  for(it2.restart();it2;++it2)
  {
   ++testNum;

   ftestID
    <<structure::flush
    <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
    <<cCursors
    <<testNum;

   const tag_impl::self_ptr
    spTest
     (structure::not_null_ptr
       (new tag_impl
         (pParams,
          ftestID.c_str(),
          Data)));

   for(size_t x=0;x!=cCursors;++x)
    spTest->m_ResultSets.push_back(dataS[it2[x]]);

   pTestPusher->PushTest(spTest);
  }//for it2
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
