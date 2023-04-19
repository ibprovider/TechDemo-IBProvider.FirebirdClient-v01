////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Fields/integer/WORK_Fields__integer_002__check_align.h"
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
//class WORK_Fields__integer_002__check_align::tag_impl

class WORK_Fields__integer_002__check_align::tag_impl
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
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;
};//class WORK_Fields__integer_002__check_align::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_Fields__integer_002__check_align::tag_impl

WORK_Fields__integer_002__check_align::tag_impl::tag_impl
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
WORK_Fields__integer_002__check_align::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_Fields__integer_002__check_align::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_Fields__integer_002__check_align::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_Fields__integer_002__check_align::tag_impl::run(context_type* const pCtx)const
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
 XSQLDA_V1_Wrapper xsqlda(/*n*/3);

 db_obj::t_dbvalue__i4   columnValue=0;
 short                   columnInd=0;

 char   columnValue_A1[3]={};
 short  columnInd_A1=0;
 char   columnValue_A2[5]={};
 short  columnInd_A2=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue_A1);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =columnValue_A1;
 xsqlda->sqlvar[0].sqlind     =&columnInd_A1;

 xsqlda->sqlvar[1].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[1].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[1].sqlsubtype =0;
 xsqlda->sqlvar[1].sqlscale   =0;
 xsqlda->sqlvar[1].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[1].sqlind     =&columnInd;

 xsqlda->sqlvar[2].sqllen     =sizeof(columnValue_A2);
 xsqlda->sqlvar[2].sqltype    =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[2].sqlsubtype =0;
 xsqlda->sqlvar[2].sqlscale   =0;
 xsqlda->sqlvar[2].sqldata    =columnValue_A2;
 xsqlda->sqlvar[2].sqlind     =&columnInd_A2;

 xsqlda->sqld=3;

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 //----------------------------------------
 const char* const c_SQL
  ="execute block\n"
   "returns(A1 CHAR(3) CHARACTER SET NONE, X INTEGER, A2 CHAR(5) CHARACTER SET NONE)\n"
   "as\n"
   "begin\n"
     " A1='SD3';  X=-2147483648;  A2='zXCxc';   suspend;\n"    // 0
     " A1='D14';  X=NULL;         A2='dSAsa';   suspend;\n"    // 1
     " A1='125';  X=-32576;       A2='1A0a0';   suspend;\n"    // 2
     " A1='236';  X=NULL;         A2='2B9b9';   suspend;\n"    // 3
     " A1='347';  X=-1;           A2='3C8c8';   suspend;\n"    // 4
     " A1='458';  X=NULL;         A2='4D7d7';   suspend;\n"    // 5
     " A1='569';  X=0;            A2='5E6e6';   suspend;\n"    // 6
     " A1='670';  X=NULL;         A2='6F5f5';   suspend;\n"    // 7
     " A1='78X';  X=1;            A2='7G4g4';   suspend;\n"    // 8
     " A1='89-';  X=NULL;         A2='8H3h3';   suspend;\n"    // 9
     " A1='90W';  X=32575;        A2='9I3i3';   suspend;\n"    // 10
     " A1='0XE';  X=NULL;         A2='0J1j1';   suspend;\n"    // 11
     " A1='X-R';  X=2147483647;   A2='eWQwq';   suspend;\n"    // 12
    "end;";

 //-----------------------------------------
 struct tag_result
 {
  short                       sqlInd;
  db_obj::t_dbvalue__i4       sqlValue;

  structure::t_const_str_box  a1;
  structure::t_const_str_box  a2;
 }
  const results[]=
 {
  { 0,LONG_MIN ,"SD3", "zXCxc"}, // 0
  {-1,0        ,"D14", "dSAsa"}, // 1
  { 0,-32576   ,"125", "1A0a0"}, // 2
  {-1,0        ,"236", "2B9b9"}, // 3
  { 0,-1       ,"347", "3C8c8"}, // 4
  {-1,0        ,"458", "4D7d7"}, // 5
  { 0,0        ,"569", "5E6e6"}, // 6
  {-1,0        ,"670", "6F5f5"}, // 7
  { 0,1        ,"78X", "7G4g4"}, // 8
  {-1,0        ,"89-", "8H3h3"}, // 9
  { 0,32575    ,"90W", "9I3i3"}, // 10
  {-1,0        ,"0XE", "0J1j1"}, // 11
  { 0,LONG_MAX ,"X-R", "eWQwq"}, // 12
 };//results

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   c_SQL);

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

  svc::checkValue__I4
   (tracer,
    columnInd,
    columnValue,
    results[iRec].sqlInd,
    results[iRec].sqlValue);

  svc::checkValue__TEXT
   (tracer,
    columnInd_A1,
    structure::t_const_str_box(columnValue_A1,_DIM_(columnValue_A1)),
    0,
    results[iRec].a1);

  svc::checkValue__TEXT
   (tracer,
    columnInd_A2,
    structure::t_const_str_box(columnValue_A2,_DIM_(columnValue_A2)),
    0,
    results[iRec].a2);
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
//class WORK_Fields__integer_002__check_align

void WORK_Fields__integer_002__check_align::create(TTSO_PushTest*      const pTestPusher,
                                                   TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 //-----------------------------------------
 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    // 0

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.Fields.integer.002.check_align.ptype__%1");

 TTSO_TestData_v2 Data;

 //-----------------------------------------
 for(;it;++it)
 {
  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[0]];

  ftestID
   <<structure::flush
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
