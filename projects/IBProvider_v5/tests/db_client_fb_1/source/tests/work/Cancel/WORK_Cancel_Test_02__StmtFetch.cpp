////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Cancel/WORK_Cancel_Test_02__StmtFetch.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/mt/t_mt_thread_controller__win32.h>
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>
#include <win32lib/win32_error.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
using namespace win32lib;
////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_02__StmtFetch::tag_thread

class WORK_Cancel_Test_02__StmtFetch::tag_thread
 :public structure::t_basic_thread_controller__win32<TTSO_SmartMemoryObject>
{
 private:
  typedef tag_thread                                         self_type;
  typedef structure::t_basic_thread_controller__win32
           <TTSO_SmartMemoryObject>                          inherited;

  tag_thread(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>           self_ptr;

  typedef structure::tso_obj::t_simple_log                   log_type;
  typedef log_type::self_ptr                                 log_ptr;

  typedef remote_fb::handles::RemoteFB__TrHandle             tr_handle_type;
  typedef remote_fb::handles::RemoteFB__StmtHandle           stmt_handle_type;

 public:
  win32lib::TEvent     m_StartEvent;
  ibp::t_ibp_error     m_Exc;
  bool                 m_HasExc;

  TestOperationContext m_OpCtx;

 public:
  using inherited::get_thread_handle;

  tag_thread(log_type*                        pLog,
             const TestCnParams&              cnParams,
             remote_fb::RemoteFB__Connector*  pConnector,
             const tr_handle_type&            hTr,
             const stmt_handle_type&          hStmt);

  virtual ~tag_thread();

 private:
  virtual const wchar_t* thread_name_impl()const COMP_W000004_OVERRIDE_FINAL;

  virtual void thread_worker_impl() COMP_W000004_OVERRIDE_FINAL;

 private:
  log_ptr                                  const m_spLog;
  remote_fb::RemoteFB__Connector::self_ptr const m_spConnector;
  tr_handle_type                                 m_hTr;
  stmt_handle_type                               m_hStmt;
};//class WORK_Cancel_Test_02__StmtFetch::tag_thread

////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_02__StmtFetch::tag_thread

WORK_Cancel_Test_02__StmtFetch::tag_thread::tag_thread
                                           (log_type* const                  pLog,
                                            const TestCnParams&              cnParams,
                                            remote_fb::RemoteFB__Connector*  pConnector,
                                            const tr_handle_type&            hTr,
                                            const stmt_handle_type&          hStmt)
 :m_Exc         (S_OK)
 ,m_HasExc      (false)
 ,m_OpCtx       (cnParams)
 ,m_spLog       (structure::not_null_ptr(pLog))
 ,m_spConnector (structure::not_null_ptr(pConnector))
 ,m_hTr         (hTr)
 ,m_hStmt       (hStmt)
{
 assert(m_spLog);
 assert(m_spConnector);
 assert(m_hTr);
 assert(m_hStmt);

 if(!m_StartEvent.Create(NULL,/*manual reset*/false,false,NULL))
  t_win32_error::throw_error(::GetLastError(),"Failed to create the tag_thread::m_StartEvent");
}//tag_thread

//------------------------------------------------------------------------
WORK_Cancel_Test_02__StmtFetch::tag_thread::~tag_thread()
{;}

//thread interface -------------------------------------------------------
const wchar_t* WORK_Cancel_Test_02__StmtFetch::tag_thread::thread_name_impl()const
{
 return L"thread";
}//thread_name_impl

//------------------------------------------------------------------------
void WORK_Cancel_Test_02__StmtFetch::tag_thread::thread_worker_impl()
{
 TTSO_Tracer tracer(m_spLog,this->thread_name());

 //-------------
 XSQLDA_V1_Wrapper xsqlda(1);

 db_obj::t_dbvalue__i4 fieldValue=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen =sizeof(fieldValue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&fieldValue);
 xsqlda->sqlvar[0].sqlind =nullptr;

 xsqlda->sqld=1;

 //-------------
 tracer<<L"Begin fetch from cursor"<<send;

 if(!m_StartEvent.Set())
  t_win32_error::throw_error(::GetLastError(),"Set Start Event");

 typedef TestServices svc;

 try
 {
  for(;;)
  {
   tracer<<L"FETCH"<<send;

   const bool fetchResult=m_spConnector->StmtFetch(m_OpCtx,
                                                   &m_hStmt,
                                                   xsqlda);

   if(!fetchResult)
    break;
  }//for[ever]
 }
 catch(const ibp::t_ibp_error& exc)
 {
  m_Exc=exc;

  m_HasExc=true;
 }//catch
}//thread_worker_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_02__StmtFetch::tag_impl

class WORK_Cancel_Test_02__StmtFetch::tag_impl
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
           const TTSO_TestData_v2& Data);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;
};//class WORK_Cancel_Test_02__StmtFetch::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_02__StmtFetch::tag_impl

WORK_Cancel_Test_02__StmtFetch::tag_impl::tag_impl(TTSO_GlobalContext*     pParams,
                                                     const char*             pTestID,
                                                     const TTSO_TestData_v2& Data)
 :m_spParams(pParams)
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Data(Data)
{
 assert(m_spParams);
}//WORK_Cancel_Test_02__StmtFetch::tag_impl

//------------------------------------------------------------------------
WORK_Cancel_Test_02__StmtFetch::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_Cancel_Test_02__StmtFetch::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_Cancel_Test_02__StmtFetch::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_Cancel_Test_02__StmtFetch::tag_impl::run(context_type* const pCtx)const
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
    "select ID from SP_PAUSE_FETCH(1000,100*1000*1000);");

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //---------------
 const tag_thread::self_ptr
  spThread(structure::not_null_ptr(new tag_thread(pCtx,
                                                  params,
                                                  spConnector,
                                                  hTr,
                                                  hStmt)));
 assert(spThread);

 tracer<<L"Run thread"<<send;

 spThread->start_thread();

 //--------------- Wait Thread Signals
 const HANDLE hSignals[]=
 {
  spThread->m_StartEvent.handle,
  spThread->get_thread_handle()
 };//hSignals

 switch(DWORD const dwWaitRes=::WaitForMultipleObjects(_DIM_(hSignals),
                                                       hSignals,
                                                       FALSE,
                                                       INFINITE))
 {
  case WAIT_OBJECT_0+0: //Start Event
   break;

  case WAIT_OBJECT_0+1: //Thread Stop
   spThread->rethrow_thread_error();

   throw std::runtime_error("Thread was stopped by unexpected reason");
   break;

  default:
   tracer(tso_msg_error,-1)<<L"Unknown wait result code:"<<dwWaitRes<<send;
   return;
 }//switch

 //---------------
 tracer<<L"Wait 2 sec"<<send;

 ::Sleep(2*1000);

 //---------------
 tracer<<L"Cancel"<<send;

 spThread->m_OpCtx.cancel();

 //---------------
 tracer<<L"Wait Thread"<<send;

 spThread->wait_exit();

 //---------------
 tracer<<L"Thread was stopped"<<send;

 spThread->rethrow_thread_error();

 //---------------
 if(!spThread->m_HasExc)
 {
  tracer(tso_msg_error,-1)<<L"We wait the cancel exception!"<<send;
 }
 else
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,
                             spThread->m_Exc);

  errSvc::check_err_count(spThread->m_Exc,1);

  errSvc::check_err_code(spThread->m_Exc.com_code(),
                         DB_E_CANCELED);

  _TSO_CHECK(spThread->m_Exc.get_record(0));

  errSvc::check_err_rec__srv_err__op_was_cancelled
   (tracer,
    spConnector->GetData()->m_DBMS_Name,
    spThread->m_Exc.get_record(0));
 }//else

 //-----------------------------------------
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
}//run

////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_02__StmtFetch

void WORK_Cancel_Test_02__StmtFetch::create(TTSO_PushTest*      const pTestPusher,
                                              TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);     //0

 //-----------------------------------------
 enum
 {
  iPType  =0,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.Cancel.02.StmtFetch.ptype__%1");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes[it[iPType]];

  ftestID<<structure::flush
         <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value());

  const TTSO_TestPtr spTest(new tag_impl(pParams,
                                         ftestID.c_str(),
                                         Data));
  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
