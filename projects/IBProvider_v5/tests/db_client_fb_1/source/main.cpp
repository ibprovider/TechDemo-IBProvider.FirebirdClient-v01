////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests.h"
#include "source/test_log_stream.h"
#include "source/push_test__filter.h"
#include "source/push_test__exec_mt.h"
#include "source/test_summary_builder.h"

#include "source/ibp_global_objects_data__dlls.h"

#include <ole_lib/oledb/oledb_memory.h>

#include <win32lib/win32_error.h>

#include <structure/test_obj/t_tso_user.h>

#include <conio.h>

////////////////////////////////////////////////////////////////////////////////
using namespace lcpi::ibp_tests;
////////////////////////////////////////////////////////////////////////////////
//Print Help

static std::string BuildHStr(const TCHAR* arg,const char* comment)
{
 std::ostringstream s;

 s<<std::left<<std::setw(20)<<structure::tstr_to_str(arg)<<comment<<std::endl;

 return s.str();
}//BuildHStr

//------------------------------------------------------------------------
static void PrintHelp()
{
 std::cout<<std::endl;

 std::cout<<BuildHStr(c_prog_arg__thread_count,
                      "[optional] Number of test threads");

 std::cout<<BuildHStr(c_prog_arg__auto,
                      "[optional] Disable \"press any key\" at exit");

 std::cout<<BuildHStr(c_prog_arg__log_dir,
                      "[optional] Directory for log files");

 std::cout<<BuildHStr(c_prog_arg__log_file_prefix,
                      "[optional] Log files prefix");

 std::cout<<BuildHStr(c_prog_arg__test,
                      "Test mask");

 std::cout<<BuildHStr(c_prog_arg__inet_host,
                      "INET host name");

 std::cout<<BuildHStr(c_prog_arg__ignore_rules,
                      "[optional] ignore test rules (execute all tests)");

 std::cout<<BuildHStr(c_prog_arg__db,
                      "database name");

 std::cout<<BuildHStr(c_prog_arg__db_user,
                      "database user login");

 std::cout<<BuildHStr(c_prog_arg__db_password,
                      "database user password");

 std::cout<<BuildHStr(c_prog_arg__new_db_dir,
                      "new database dir on the server");

 std::cout<<BuildHStr(c_prog_arg__isc_api_library,
                      "ISC API library (gds32.dll/fbclient.dll)");

 std::cout<<BuildHStr(c_prog_arg__dbms,
                      "DBMS Name (format: <sign>-<version>)");

 std::cout<<BuildHStr(c_prog_arg__ods,
                 "ODS Version");

 std::cout<<BuildHStr(c_prog_arg__dialect,
                      "Database Dialect");

 std::cout<<BuildHStr(c_prog_arg__cn_str,
                      "[optional] Connection string with subset of IBProvider properties");
}//PrintHelp

////////////////////////////////////////////////////////////////////////////////
//class TTestListProcessor

class TTestListProcessor
{
 private:
  typedef TTestListProcessor                     self_type;

  TTestListProcessor(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef TTSO_PushTest__Filter::test_count_type test_count_type;

 public:
  TTestListProcessor(TTSO_PushTest*      const pTestPush,
                     TTSO_GlobalContext* const pSD,
                     TSYS_RootLog*       const pSysRootLog);

 ~TTestListProcessor();

  bool run()const;

 private:
  const TTSO_PushTest__Filter::self_ptr m_spFilter;
  const TTSO_GlobalContext::self_ptr    m_spSD;
  const TSYS_RootLog::self_ptr          m_spSysRootLog;
};//class TTestListProcessor

////////////////////////////////////////////////////////////////////////////////
//class TTestListProcessor

TTestListProcessor::TTestListProcessor(TTSO_PushTest*      const pTestPush,
                                       TTSO_GlobalContext* const pSD,
                                       TSYS_RootLog*       const pSysRootLog)
 :m_spFilter     (lcpi::lib::structure::not_null_ptr(new TTSO_PushTest__Filter(pSD,pSysRootLog,pTestPush)))
 ,m_spSD         (lcpi::lib::structure::not_null_ptr(pSD))
 ,m_spSysRootLog (lcpi::lib::structure::not_null_ptr(pSysRootLog))
{
 assert(m_spFilter);
 assert(m_spSD);
 assert(m_spSysRootLog);
}//TTestListProcessor

//------------------------------------------------------------------------
TTestListProcessor::~TTestListProcessor()
{;}

//------------------------------------------------------------------------
bool TTestListProcessor::run()const
{
 assert(m_spFilter);
 assert(m_spSD);

 //-----------------------------------------------------------------------
 bool result=true;

 try
 {
  for(const TTestCreatorDescr * pTestDescr(g_Tests);pTestDescr->TestCreator!=nullptr;++pTestDescr)
  {
   pTestDescr->TestCreator(m_spFilter,m_spSD);
  }//for

  m_spSysRootLog->inc_pass_count();
 }
 catch(const TTSO_PushTest__Filter::tag_cancel_exc&)
 {
  result=false;
 }

 return result;
}//run

////////////////////////////////////////////////////////////////////////////////

static int ExecuteTests(const TSYS_CommandLine* const pSysCL)
{
 assert(pSysCL!=nullptr);

 //-----------------------------------------------------------------------
 TSYS_RootLog::self_ptr spRootLog;

 if(pSysCL->RootLogFilePath().empty())
 {
  spRootLog
    =lcpi::lib::structure::not_null_ptr
      (new TSYS_RootLog(CP_OEMCP));
 }
 else
 {
  const TSYS_LogStream::self_ptr
   spRootLogStream
    (lcpi::lib::structure::not_null_ptr
      (new TSYS_LogStream
        (CP_OEMCP,
         pSysCL->RootLogFilePath())));

  assert(spRootLogStream);

  spRootLog
    =lcpi::lib::structure::not_null_ptr
      (new TSYS_RootLog
        (spRootLogStream));
 }//if

 //-----------------------------------------------------------------------
 spRootLog->print_ts=true;

 //-----------------------------------------------------------------------
 TTSO_Tracer RootTracer(spRootLog);

 if(pSysCL->args().has(c_prog_arg__stop))
 {
  RootTracer<<L"Press any key for begin execution ..."<<send;

  _GCRT_getch();
 }

 //-----------------------------------------------------------------------
 const TTSO_GlobalContext::self_ptr
  spParams
   (lcpi::lib::structure::not_null_ptr
     (new TTSO_GlobalContext(pSysCL)));

 const TTSO_PushTest__ExecutorMT::self_ptr
  spExecutor
   (TTSO_PushTest__ExecutorMT::create
     (spParams,
      pSysCL->BaseLogFilePath(),
      spRootLog));

 //-----------------------------------------------------------------------
 RootTracer<<L"CommandLine:\n\n"
           <<::GetCommandLine()
           <<L"\n"
           <<send;

 RootTracer<<L"Run!"<<send;
 RootTracer<<send;
 RootTracer<<L"Enter [cancel] for interrupt execution"<<send;
 RootTracer<<send;

 //-----------------------------------------------------------------------
 auto const cInitialAllocBlocks=_Module.TestCode__GetAllocBlockCount();

 {
  ibp::IBP_GlobalObjectsData__DLLs::tagTestInitializer __InitializerForDlls;

  try
  {
   TTestListProcessor processor(spExecutor,spParams,spRootLog);

   if(!processor.run())
   {
    spExecutor->cancel();
   }
  }
  catch(...)
  {
   TTSO_ExceptionRouter::route(RootTracer);
  }

  //---------------------------------------- stop executors
  try
  {
   spExecutor->stop__no_throw();
  }
  catch(...)
  {
   assert(false);

   spRootLog->add_other_error_count(1);
  }//catch
 }

 //-----------------------------------------
 auto const cFinishlAllocBlocks=_Module.TestCode__GetAllocBlockCount();

 if(cFinishlAllocBlocks!=cInitialAllocBlocks)
 {
  RootTracer(tso_msg_error,-1)
   <<L"cFinishlAllocBlocks: "<<cFinishlAllocBlocks<<L".  cFinishlAllocBlocks: "<<cFinishlAllocBlocks<<"."
   <<send;
 }//if

 //----
 RootTracer(L"")<<send;

 spExecutor->build_summary();

 //-----------------------------------------
 {
  RootTracer(L"summary")<<send;

  TTSO_SummaryBuilder::print_summary_process_state(RootTracer);

  RootTracer<<send;

  TTSO_SummaryBuilder::print_total_ex
   (RootTracer,
    L"",
    spRootLog->get_total_error_count(),
    spRootLog->get_total_warning_count(),
    spRootLog->get_pass_count(),
    spRootLog->get_total_test_count());
 }//if PrintSummaryErrors

 //----------------------------------------- EXIT

 if(!pSysCL->RootLogFilePath().empty())
 {
  std::cout<<std::endl;

  std::cout<<"ROOT LOG FILE: \""<<pSysCL->RootLogFilePath()<<'\"'<<std::endl;
 }//if

 return (int)min(spRootLog->get_total_error_count(),INT_MAX);
}//ExecuteTests

////////////////////////////////////////////////////////////////////////////////

int main()
{
 int err_count=0;

 bool wait_press_any_key_on_exit=false;

 _TSO_TRY_
 {
  _VERIFY(_Module.Init(::GetModuleHandle(NULL)));

  const TSYS_CommandLine::self_cptr
   spSysCL(new TSYS_CommandLine());

  //--------------
  if(spSysCL->args().empty())
  {
   PrintHelp();

   err_count=-1;
  }//if - print help string
  else
  {
   wait_press_any_key_on_exit=spSysCL->WaitPressAnyKeyOnExit();

   err_count+=ExecuteTests(spSysCL);
  }
 }
 _TSO_CATCHES_("main",err_count)

 _Module.Term();

 //-----------------------------------------
 if(wait_press_any_key_on_exit)
 {
  //clear keyboard buffer
  while(_GCRT_kbhit()!=0)
  {
   _GCRT_getch();
  }//while

  std::cout<<std::endl<<"DONE [press any key]."<<std::endl;

  _GCRT_getch();
 }//if

 return err_count;
}//main

////////////////////////////////////////////////////////////////////////////////
