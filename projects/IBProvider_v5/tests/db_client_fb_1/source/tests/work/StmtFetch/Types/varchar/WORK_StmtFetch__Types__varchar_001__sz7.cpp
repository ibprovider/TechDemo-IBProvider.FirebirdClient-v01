////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/StmtFetch/Types/varchar/WORK_StmtFetch__Types__varchar_001__sz7.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch__Types__varchar_001__sz7::tag_impl

class WORK_StmtFetch__Types__varchar_001__sz7::tag_impl LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef tag_impl                                     self_type;

  tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

 public:
  tag_impl(TTSO_GlobalContext*  pParams,
           const char*             pTestID,
           const TTSO_TestData_v2& Data);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;
};//class WORK_StmtFetch__Types__varchar_001__sz7::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch__Types__varchar_001__sz7::tag_impl

WORK_StmtFetch__Types__varchar_001__sz7::tag_impl::tag_impl(TTSO_GlobalContext* const pParams,
                                                  const char*         const pTestID,
                                                  const TTSO_TestData_v2&   Data)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Data(Data)
{
 assert(m_spParams);
}//tag_impl

//------------------------------------------------------------------------
WORK_StmtFetch__Types__varchar_001__sz7::tag_impl::~tag_impl()
{
}

//test interface ---------------------------------------------------------
std::string WORK_StmtFetch__Types__varchar_001__sz7::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_StmtFetch__Types__varchar_001__sz7::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_StmtFetch__Types__varchar_001__sz7::tag_impl::run(context_type* const pCtx)const
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
 params.set_dbprop_init__ctype(L"ASCII");

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
 const size_t c_VarcharLength=7;

 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 structure::t_typed_simple_buffer<char,TTSO_MemoryAllocator>
  columnValueBuf(sizeof(isc_api::isc_varchar_size_type)+c_VarcharLength);

 short     columnInd=0;

 xsqlda->sqlvar[0].sqllen     =c_VarcharLength;
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =columnValueBuf.buffer();
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 //----------------------------------------
 const char* const c_SQL_templ
  ="execute block\n"
   "returns(X VARCHAR(%1)CHARACTER SET NONE)\n"
   "as\n"
   "begin\n"
        //1234567
     " X='      7';      suspend;\n"    // 0
     " X=NULL;           suspend;\n"    // 1
     " X='1';            suspend;\n"    // 2
     " X=NULL;           suspend;\n"    // 3
     " X='  3';          suspend;\n"    // 4
     " X=NULL;           suspend;\n"    // 5
     " X='';             suspend;\n"    // 6
     " X=NULL;           suspend;\n"    // 7
     " X='1234567';      suspend;\n"    // 8
     " X=NULL;           suspend;\n"    // 9
    "end;";

 structure::str_formatter fSQL(c_SQL_templ);

 fSQL<<c_VarcharLength;

 //-----------------------------------------
 struct tag_result
 {
  short sqlInd;
  short sqlValueLen;
  char  sqlValue[c_VarcharLength];
 }
  const results[]=
 {
  { 0, 7 ,{' ',' ',' ',' ',' ',' ','7'}},// 0
  {-1, 0 ,{ 0 , 0 , 0 , 0 , 0 , 0 , 0 }},// 1
  { 0, 1 ,{'1', 0 , 0 , 0 , 0 , 0 , 0 }},// 2
  {-1, 0 ,{ 0 , 0 , 0 , 0 , 0 , 0 , 0 }},// 3
  { 0, 3 ,{' ',' ','3', 0 , 0 , 0 , 0 }},// 4
  {-1, 0 ,{ 0 , 0 , 0 , 0 , 0 , 0 , 0 }},// 5
  { 0, 0 ,{ 0 , 0 , 0 , 0 , 0 , 0 , 0 }},// 6
  {-1, 0 ,{ 0 , 0 , 0 , 0 , 0 , 0 , 0 }},// 7
  { 0, 7 ,{'1','2','3','4','5','6','7'}},// 8
  {-1, 0 ,{ 0 , 0 , 0 , 0 , 0 , 0 , 0 }},// 9
 };//results

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   fSQL.str());

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 for(size_t iRec=0,_cRecs=_DIM_(results);iRec!=_cRecs;++iRec)
 {
  tracer<<L"-------------------------------- "<<iRec<<send;

  svc::RemoteFB_Connector__StmtFetch_ToRow
   (spConnector,
    OpCtx,
    &hStmt,
    /*pOutXSQLDA*/xsqlda);

  const isc_api::isc_varchar_size_type varchar_length
   =*reinterpret_cast<const isc_api::isc_varchar_size_type*>(columnValueBuf.buffer());

  if(varchar_length!=results[iRec].sqlValueLen)
  {
   tracer(tso_msg_error,-1)
    <<L"Incorrect vacrhar length: "<<varchar_length<<L". Expected: "<<results[iRec].sqlValueLen<<send;

   continue;
  }//if

  svc::checkValue__TEXT
   (tracer,
    columnInd,
    structure::t_const_str_box(columnValueBuf.ptr_at(sizeof(isc_api::isc_varchar_size_type)),c_VarcharLength),
    results[iRec].sqlInd,
    structure::t_const_str_box(results[iRec].sqlValue,_DIM_(results[iRec].sqlValue)));
 }//for iRec

 svc::RemoteFB_Connector__StmtFetch_ToEOF
  (spConnector,
   OpCtx,
   &hStmt,
   /*pOutXSQLDA*/xsqlda);

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
//class WORK_StmtFetch__Types__varchar_001__sz7

void WORK_StmtFetch__Types__varchar_001__sz7::create
                             (TTSO_PushTest*      const pTestPusher,
                              TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 //-----------------------------------------
 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    // 0

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.StmtFetch.Types.varchar.001.sz7.ptype__%1");

 TTSO_TestData_v2 Data;

 //-----------------------------------------
 for(;it;++it)
 {
  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[0]];

  ftestID<<structure::flush
         <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value());

  const tag_impl::self_ptr
   spTest
    (structure::not_null_ptr
      (new tag_impl
        (pParams,
         ftestID.c_str(),
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
