////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/push_test__exec_mt.h"
#include "source/test_state2.h"
//#include "source/ibp_tso_test_context_impl.h"
#include "source/test_log_stream.h"
#include "source/test_summary_builder.h"
#include "source/test_perf_timers.h"
#include "source/test_utilities.h"

#include <structure/t_numeric_cast.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestQueueMT::tag_test_data

TTSO_TestQueueMT::tag_test_data::tag_test_data(const test_type* const test)
 :m_exec_count(0)
 ,m_test(test)
{
 assert(m_test);
}

//------------------------------------------------------------------------
TTSO_TestQueueMT::tag_test_data::tag_test_data(const self_type& x)
 :m_exec_count(x.m_exec_count)
 ,m_test(x.m_test)
{
}

//------------------------------------------------------------------------
TTSO_TestQueueMT::tag_test_data&
 TTSO_TestQueueMT::tag_test_data::operator = (const self_type& x)
{
 m_exec_count =x.m_exec_count;
 m_test       =x.m_test;

 return *this;
}//operator =

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestQueueMT

TTSO_TestQueueMT::TTSO_TestQueueMT(log_ex_type* const pLog,
                                   unsigned     const ExecMultplicator)
 :m_ExecMultiplicator(ExecMultplicator)
 ,m_TestQueue_NoNewTest(0)
 ,m_spLog(pLog)
 ,m_test_num_gen(0)
{
 assert(m_ExecMultiplicator>0);
 assert(m_spLog);

 if(!m_TestQueue_PushEvent.Create(NULL,/*manual reset*/true,/*init state*/false,NULL))
  win32lib::t_win32_error::throw_error(::GetLastError(),"TTSO_TestQueueMT::m_TestQueue_PushEvent");

 if(!m_TestQueue_PopEvent.Create(NULL,/*manual reset*/false,/*init state*/false,NULL))
  win32lib::t_win32_error::throw_error(::GetLastError(),"TTSO_TestQueueMT::m_TestQueue_PopEvent");
}//TTSO_TestQueueMT

//------------------------------------------------------------------------
TTSO_TestQueueMT::~TTSO_TestQueueMT()
{
}

//------------------------------------------------------------------------
TTSO_TestQueueMT::size_type TTSO_TestQueueMT::size()const
{
 const lock_guard_type __lock(m_TestQueueGuard);

 return m_TestQueue.size();
}//size

//------------------------------------------------------------------------
void TTSO_TestQueueMT::push_test(const test_type* const pTest)
{
 const lock_guard_type __lock(m_TestQueueGuard);

 m_TestQueue.push_back(pTest);

 if(!m_TestQueue_PushEvent.Set())
  throw std::runtime_error("Can't SetUp Push-Event State");
}//push_test

//------------------------------------------------------------------------
void TTSO_TestQueueMT::no_new_test__no_throw(bool const clear)
{
 if(clear)
 {
  const lock_guard_type __lock(m_TestQueueGuard);

  m_TestQueue.clear();
 }//if

 ::InterlockedIncrement(&m_TestQueue_NoNewTest);

 _VERIFY(m_TestQueue_PushEvent.Set());
}//no_new_test__no_throw

//------------------------------------------------------------------------
TTSO_TestQueueMT::test_cptr TTSO_TestQueueMT::pop_test
                                           (const wchar_t* const ThreadName,
                                            HANDLE         const hCancelEvent)
{
 const test_cptr spTest(this->pop_test_impl(hCancelEvent));

 if(spTest)
 {
  //Add log message
  TTSO_Tracer tracer(m_spLog,ThreadName);

  const lock_guard_type __lock(m_test_num_guard);

  ++m_test_num_gen;

  tracer<<L"[START  ] "<<spTest->get_id()
        <<L" [#"<<m_test_num_gen<<L"]"
        <<send;
 }//if spTest

 return spTest;
}//pop_test

//------------------------------------------------------------------------
TTSO_TestQueueMT::test_cptr TTSO_TestQueueMT::pop_test_impl
                                           (HANDLE         const hCancelEvent)
{
 for(;;)
 {
  {
   const lock_guard_type __lock(m_TestQueueGuard);

   if(!m_TestQueue.empty())
   {
    test_cptr spReturnTest;

    {
     tag_test_data& TestData(m_TestQueue.front());

     assert(TestData.m_test);
     assert(TestData.m_exec_count<m_ExecMultiplicator);
     assert(m_ExecMultiplicator>0);

     spReturnTest=TestData.m_test;
    }//local

    assert(spReturnTest);

    m_TestQueue.pop_front();

    if(!m_TestQueue_PopEvent.Set())
     throw std::runtime_error("Can't SetUp Pop-Event State");

    return spReturnTest;
   }//if

   if(m_TestQueue_NoNewTest)
    return nullptr;

   if(!m_TestQueue_PushEvent.Reset())
    throw std::runtime_error("Can't Reset Push-Event State");
  }//local - lock m_Guard

  const HANDLE hWaitHandles[]={hCancelEvent,m_TestQueue_PushEvent};

  switch(::WaitForMultipleObjects(_DIM_(hWaitHandles),hWaitHandles,FALSE,INFINITE))
  {
   case WAIT_OBJECT_0+0: //Cancel event
    return nullptr;
  }//switch
 }//for[ever]
}//pop_test_impl

//------------------------------------------------------------------------
DWORD TTSO_TestQueueMT::wait_pop_event(DWORD const dwMilliSeconds)
{
 return m_TestQueue_PopEvent.Wait(dwMilliSeconds);
}//wait_pop_event

//------------------------------------------------------------------------
void TTSO_TestQueueMT::add_result(const wchar_t*   const ThreadName,
                                  const TTSO_TestState2& TestResult)
{
 assert(ThreadName);

 {
  const lock_guard_type __lock(m_ResultGuard);

  m_Results.append(TestResult); //throw
 }//local

 //-----------------------------------------
 m_spLog->add_other_error_count   (TestResult.err_count);
 m_spLog->add_other_warning_count (TestResult.warning_count);

 //-----------------------------------------
 TTSO_Tracer tracer(m_spLog,ThreadName);

 if(TestResult.err_count)
  tracer<<L"[FAILED ] ";
 else
 if(TestResult.warning_count)
  tracer<<L"[WARNING] ";
 else
  tracer<<L"[STOP   ] ";

 tracer<<TestResult.get_test_id()<<send;
}//add_result

//------------------------------------------------------------------------
long TTSO_TestQueueMT::build_summary(const runners_type& runners)const
{
 const char* const c_bugcheck_src
  ="TTSO_TestQueueMT::build_summary";

 typedef structure::t_smart_vector<TTSO_SummaryBuilder,allocator_type> builders_type;

 const lock_guard_type __lock(m_ResultGuard);

 //Summary
 //1. Tests with errors
 //2. Tests with warnings
 //3. Runners statistics
 //4. Main thread errors count
 //5. Total informations

 //----------------------------------------- prepare summary builders
 size_t nTotalError   (m_spLog->get_error_count());
 size_t nTotalWarning (m_spLog->get_warning_count());

 const TTSO_SummaryBuilder::self_ptr
  spRootBuilder(structure::not_null_ptr(new TTSO_SummaryBuilder(m_spLog.ptr())));

 builders_type ThreadBuilders;

 for(size_t i=0;i!=runners.size();++i)
 {
  assert(runners[i]);

  const TTSO_RootLog::self_ptr spThreadLog(runners[i]->thread_log());

  nTotalError    +=spThreadLog->get_error_count();
  nTotalWarning  +=spThreadLog->get_warning_count();

  const TTSO_SummaryBuilder::self_ptr
   spRootBuilder(structure::not_null_ptr(new TTSO_SummaryBuilder(spThreadLog.ptr())));

  ThreadBuilders.push_back(spRootBuilder);
 }//for i

 assert(ThreadBuilders.size()==runners.size());

 //----------------------------------------- build total info
 typedef test_results_type::count_type      result_count_type;

 result_count_type   const    cResults=m_Results.get_count();
 test_results_type::item_type Result;

 for(result_count_type i=0;i!=cResults;++i)
 {
  m_Results.read(i,&Result);

  if(!(Result.thread_idx<runners.size()))
  {
   structure::str_formatter
    fmsg("[BUG CHECK][%1][#001]\n"
         "wrong thread_idx [%2] in test state [%3].");

   fmsg<<c_bugcheck_src<<Result.thread_idx<<i;

   throw std::runtime_error(fmsg.str());
  }//if

  assert(Result.thread_idx<runners.size());

  spRootBuilder->process_result(Result);

  ThreadBuilders[Result.thread_idx]->process_result(Result);
 }//for i

 //----------------------------------------- Print tests with errors
 for(result_count_type i=0;i!=cResults;++i)
 {
  m_Results.read(i,&Result);

  if(!(Result.thread_idx<runners.size()))
  {
   structure::str_formatter
    fmsg("[BUG CHECK][%1][#002]\n"
         "wrong thread_idx [%2] in test state [%3].");

   fmsg<<c_bugcheck_src<<Result.thread_idx<<i;

   throw std::runtime_error(fmsg.str());
  }//if

  assert(Result.thread_idx<runners.size());

  if(Result.err_count==0)
   continue;

  spRootBuilder->print_test_with_error
   (Result,runners[Result.thread_idx]->thread_name());

  ThreadBuilders[Result.thread_idx]->print_test_with_error
   (Result,L"");
 }//for i

 //----------------------------------------- Print tests with warnings
 for(result_count_type i=0;i!=cResults;++i)
 {
  m_Results.read(i,&Result);

  if(!(Result.thread_idx<runners.size()))
  {
   structure::str_formatter
    fmsg("[BUG CHECK][%1][#003]\n"
         "wrong thread_idx [%2] in test state [%3].");

   fmsg<<c_bugcheck_src<<Result.thread_idx<<i;

   throw std::runtime_error(fmsg.str());
  }//if

  assert(Result.thread_idx<runners.size());

  if(Result.warning_count==0)
   continue;

  spRootBuilder->print_test_with_warning
   (Result,runners[(Result).thread_idx]->thread_name());

  ThreadBuilders[Result.thread_idx]->print_test_with_warning
   (Result,L"");
 }//for i

 //----------------------------------------- Print total infromation
 for(size_t i(0);i!=runners.size();++i)
 {
  assert(ThreadBuilders[i]);

  ThreadBuilders[i]->print_summary(L"",true);

  ThreadBuilders[i]->print_summary_ex(spRootBuilder->m_Tracer,
                                      runners[i]->thread_name(),
                                      true);
 }//for i

 spRootBuilder->print_total(L"ROOT THREAD",
                            m_spLog->get_error_count(),
                            m_spLog->get_warning_count());

 //-------------
 spRootBuilder->print_summary(L"SUMMARY INFORMATION",false);

 //-------------
 assert(nTotalError   ==m_spLog->get_total_error_count());
 assert(nTotalWarning ==m_spLog->get_total_warning_count());

 //-------------
 long result;
 structure::verified_length_cast(&result,nTotalError,"TTSO_TestQueueMT::build_summary");

 return result;
}//build_summary

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestRunnerMT

TTSO_TestRunnerMT::TTSO_TestRunnerMT(const TTSO_GlobalContext* const pSD,
                                     size_t                    const thread_idx,
                                     const std::wstring&             thread_name,
                                     TTSO_TestQueueMT*         const pTestQueue,
                                     log_ex_type*              const pLog)
 :m_spSD(pSD)
 ,m_thread_idx(thread_idx)
 ,m_thread_name(thread_name)
 ,m_test_queue(pTestQueue)
 ,m_log(pLog)
{
 assert(m_spSD);
 assert(m_test_queue);
 assert(m_log);
}//TTSO_TestRunnerMT

//------------------------------------------------------------------------
TTSO_TestRunnerMT::~TTSO_TestRunnerMT()
{;}

//------------------------------------------------------------------------
TTSO_TestRunnerMT::self_ptr TTSO_TestRunnerMT::create
                                  (const TTSO_GlobalContext* const pSD,
                                   size_t                    const ThreadIdx,
                                   TTSO_TestQueueMT*         const pTestQueue,
                                   const std::string&              BaseLogFilePath)
{
 assert(pSD);
 assert(pTestQueue);

 //---------
 structure::str_formatter fLogFileName("%1_%2.log");

 fLogFileName<<BaseLogFilePath<<(ThreadIdx+1);

 const TTSO_LogStream::self_ptr
  spThreadLogStream(structure::not_null_ptr(new TTSO_LogStream_ToFile(fLogFileName.str())));

 assert(spThreadLogStream);

 //---------
 const TTSO_RootLog::self_ptr
  spThreadLog(structure::not_null_ptr(new TTSO_RootLog(spThreadLogStream)));

 assert(spThreadLog);

 spThreadLog->print_ts=true;

 spThreadLog->print_thread_id=true;

 //---------
 structure::wstr_formatter fThreadName(L"Thread #%1");

 fThreadName<<(ThreadIdx+1);

 //---------
 return structure::not_null_ptr(new TTSO_TestRunnerMT(pSD,
                                                      ThreadIdx,
                                                      fThreadName.str(),
                                                      pTestQueue,
                                                      spThreadLog));
}//create

//------------------------------------------------------------------------
const wchar_t* TTSO_TestRunnerMT::thread_name_impl()const
{
 return m_thread_name.c_str();
}//thread_name_impl

//------------------------------------------------------------------------
void TTSO_TestRunnerMT::thread_worker_impl()
{
 const TTSO_RunContext::self_ptr
  spCtx(structure::not_null_ptr(new TTSO_RunContext(m_log)));

 TTSO_Tracer thread_tracer(m_log);

 thread_tracer<<L"Thread Name: "<<this->thread_name()<<send;
 thread_tracer<<L"Thread ID  : "<<::GetCurrentThreadId()<<send;
 thread_tracer<<send;

 //--------------
 //m_spSD->LogDataSourceInfo(m_log);

 //--------------
 std::string test_id;

 for(;;)
 {
  if(this->get_stop_signal()!=0)
  {
   thread_tracer<<L"Exit. Detect SetUp of Stop Signal."<<send;
   return;
  }

  const TTSO_TestCPtr spTest(m_test_queue->pop_test(this->thread_name(),
                                                    this->get_stop_event()));
  if(!spTest)
  {
   thread_tracer<<L"Exit. Tests queue do not return next test."<<send;
   return;
  }

  //---------
  spCtx->m_test_info.reset();

  spCtx->m_test_info.thread_idx=m_thread_idx;

  //---------
  test_id=spTest->get_id();

  spCtx->m_test_info.set_test_id(test_id);

  //----------------------------------------
  TTSO_Tracer test_tracer(spCtx,test_id);

  test_tracer(tso_obj::tso_msg_start_test,0)<<send;

  {
   //thread_tracer<<"* RUN"<<send;

   TTSO_PerfTimers timer;

   try
   {
    spTest->run(spCtx);
   }
   catch(...)
   {
    TTSO_ExceptionRouter::route(test_tracer);
   }//catch

   timer.Stop();

   spCtx->m_test_info.real_time   =timer.RealTime();
   spCtx->m_test_info.user_time   =timer.UserTime();
   spCtx->m_test_info.kernel_time =timer.KernelTime();

   //---------
   thread_tracer<<L"*"<<send;

   thread_tracer<<L"* REAL   TIME:"<<TSO_TimeToStrEx(spCtx->m_test_info.real_time)<<send;
   thread_tracer<<L"* USER   TIME:"<<TSO_TimeToStrEx(spCtx->m_test_info.user_time)<<send;
   thread_tracer<<L"* KERNEL TIME:"<<TSO_TimeToStrEx(spCtx->m_test_info.kernel_time)<<send;
   thread_tracer<<L"* TOTAL  TIME:"<<TSO_TimeToStrEx(spCtx->m_test_info.kernel_time+
                                                     spCtx->m_test_info.user_time)<<send;

   thread_tracer<<L"*"<<send;
  }//local

  //---------
  test_tracer(tso_obj::tso_msg_stop_test,0)<<send;

  //---------
  m_test_queue->add_result(this->thread_name(),spCtx->m_test_info);
 }//for[ever]
}//thread_worker_impl

////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest__ExecutorMT

TTSO_PushTest__ExecutorMT::TTSO_PushTest__ExecutorMT
                            (const TTSO_GlobalContext* const pSD,
                             const std::string&              BaseLogFilePath,
                             log_ex_type*              const pLog,
                             size_t                    const nThread)
 :m_spSD            (pSD)
 ,m_BaseLogFilePath (BaseLogFilePath)
 ,m_spLog           (pLog)
 ,m_nThread         (nThread)
 ,m_spTestQueue     (structure::not_null_ptr(new test_queue_type(pLog,1)))
{
 assert(m_spSD);
 assert(m_spLog);
 assert(m_nThread>=1);

#ifndef NDEBUG
 m_debug__IsStopped=0;
#endif
}//TTSO_PushTest__ExecutorMT

//------------------------------------------------------------------------
TTSO_PushTest__ExecutorMT::~TTSO_PushTest__ExecutorMT()
{;}

//------------------------------------------------------------------------
TTSO_PushTest__ExecutorMT::self_ptr TTSO_PushTest__ExecutorMT::create
                        (const TTSO_GlobalContext* const pSD,
                         const std::string&              BaseLogFilePath,
                         log_ex_type*              const pRootLog)
{
 assert(pSD);
 assert(pRootLog);

 //-----------
 size_t thread_count=0;

 if(pSD->args().has(c_prog_arg__thread_count))
 {
  std::string tmp;

  structure::tstr_to_tstr(&tmp,pSD->args().get(c_prog_arg__thread_count)->m_value);

  thread_count=strtol(tmp.c_str(),NULL,0);
 }
 else
 {
  SYSTEM_INFO si={0};

  ::GetSystemInfo(&si);

  thread_count=si.dwNumberOfProcessors;
 }//else

 if(thread_count<=0)
  thread_count=1;

 //-----------
 return structure::not_null_ptr(new self_type(pSD,
                                              BaseLogFilePath,
                                              pRootLog,
                                              thread_count));
}//create

//TTSO_PushTest interface ------------------------------------------------
void TTSO_PushTest__ExecutorMT::PushTest(const TTSO_Test* const pTest)
{
 assert(pTest);
 assert(m_spSD);
 assert(m_spLog);
 assert(m_nThread>=1);
 assert(m_spTestQueue);

 //-----------------------------------------
 TTSO_Tracer tracer(m_spLog);

 //-----------------------------------------
 if(m_TestRunners.empty())
 {
  //First call.
  tracer<<L"Creation "<<m_nThread<<L" thread(s)..."<<send;

  //---------------------------------------- Create Thread Workers
  runners_type TestRunners;

  for(size_t i=0;i!=m_nThread;++i)
  {
   TestRunners.push_back(runner_type::create(m_spSD,
                                             i,
                                             m_spTestQueue,
                                             m_BaseLogFilePath));
  }//for

  //---------------------------------------- Run Thread Workers
  for(runners_type::const_iterator i(TestRunners.begin()),_e(TestRunners.end());
      i!=_e;
      ++i)
  {
   assert((*i));

   tracer<<L"Start "<<(*i)->thread_name()<<send;

   (*i)->start_thread();//throw
  }//for

  //---------------------------------------- Install Thread Workers
  m_TestRunners.swap(TestRunners);
 }//if first call

 //Add new test to workers queue
 for(;;)
 {
  if(m_spTestQueue->size()<4*m_nThread)
  {
   m_spTestQueue->push_test(pTest);

   return;
  }//local

  for(;;)
  {
   //tests status verification
   size_t nActiveRunners=0;

   for(size_t i=0;i!=m_TestRunners.size();++i)
   {
    assert(m_TestRunners[i]);

    if(m_TestRunners[i]->thread_is_active())
     ++nActiveRunners;
   }//for i

   if(nActiveRunners==0)
   {
    throw std::runtime_error("No Active Runners' Threads");
   }//if

   //Wait 1 sec.
   if(m_spTestQueue->wait_pop_event(1*1000)!=WAIT_TIMEOUT)
    break; //test queue was changed

  }//for[ever] - check threads and wait pop-event
 }//for[ever] - check queue size
}//PushTest

//------------------------------------------------------------------------
void TTSO_PushTest__ExecutorMT::cancel()
{
 TTSO_Tracer tracer(m_spLog);

 tracer<<L"Cancel. Clear test queue..."<<send;

 m_spTestQueue->no_new_test__no_throw(true);
}//cancel

//------------------------------------------------------------------------
void TTSO_PushTest__ExecutorMT::stop__no_throw()
{
 TTSO_Tracer tracer(m_spLog);

 try
 {
  tracer<<L"Wait Runners' Threads..."<<send;
 }
 catch(...)
 {
  m_spLog->add_other_error_count(1);
 }//catch

 //-----------------------------------------
 m_spTestQueue->no_new_test__no_throw(false);

 //Wait runners' threads
 for(size_t i(0);i!=m_TestRunners.size();++i)
 {
  assert(m_TestRunners[i]);

  try
  {
   tracer<<L"Wait "<<m_TestRunners[i]->thread_name()<<send;
  }
  catch(...)
  {
   m_spLog->add_other_error_count(1);
  }//catch

  try
  {
   m_TestRunners[i]->wait_exit();  //no throw

   m_TestRunners[i]->rethrow_thread_error();
  }
  catch(...)
  {
   try
   {
    tracer<<L"Thread ["<<m_TestRunners[i]->thread_name()
          <<L"] was finished with errors"
          <<send;

    //--- Print thread errors into thread log
    TTSO_Tracer thread_tracer(m_TestRunners[i]->thread_log());

    TTSO_ExceptionRouter::route(thread_tracer);
   }
   catch(...)
   {
    m_spLog->add_other_error_count(1);
   }
  }//catch
 }//for i

 if(size_t const n=m_spTestQueue->size())
 {
  try
  {
   tracer(tso_msg_error,-1)<<L"Test queue has ["<<n<<L"] elements"<<send;
  }
  catch(...)
  {
   m_spLog->add_other_error_count(1);
  }
 }//if

 //-----------------------------------------
#ifndef NDEBUG
 ::InterlockedExchange(&m_debug__IsStopped,1);
#endif
}//stop__no_throw

//------------------------------------------------------------------------
long TTSO_PushTest__ExecutorMT::build_summary()
{
 assert(m_debug__IsStopped!=0);
 //this->stop();

 return m_spTestQueue->build_summary(m_TestRunners);
}//print_summary

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
