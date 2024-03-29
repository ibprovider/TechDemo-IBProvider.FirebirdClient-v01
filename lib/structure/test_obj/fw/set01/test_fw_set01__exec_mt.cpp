////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__exec_mt.h>
#include <structure/test_obj/fw/set01/test_fw_set01__summary_builder.h>
#include <structure/test_obj/fw/set01/test_fw_set01__perf_timers.h>
#include <structure/test_obj/fw/set01/test_fw_set01__utilities.h>
#include <structure/test_obj/fw/set01/test_fw_set01__run_context.h>

#include <structure/t_numeric_cast.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestQueueMT::tag_test_data

TestFW__TestQueueMT::tag_test_data::tag_test_data(const TestFW__Test* const test)
 :m_exec_count(0)
 ,m_test(structure::not_null_ptr(test))
{
 assert(m_test);
}

//------------------------------------------------------------------------
TestFW__TestQueueMT::tag_test_data::tag_test_data(const self_type& x)
 :m_exec_count(x.m_exec_count)
 ,m_test(x.m_test)
{
}

//------------------------------------------------------------------------
TestFW__TestQueueMT::tag_test_data&
 TestFW__TestQueueMT::tag_test_data::operator = (const self_type& x)
{
 m_exec_count =x.m_exec_count;
 m_test       =x.m_test;

 return *this;
}//operator =

////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestQueueMT

TestFW__TestQueueMT::TestFW__TestQueueMT(log_ex_type* const pLog,
                                         unsigned     const ExecMultplicator)
 :m_ExecMultiplicator   (ExecMultplicator)
 ,m_TestQueue_NoNewTest (0)
 ,m_spLog               (structure::not_null_ptr(pLog))
 ,m_test_num_gen        (0)
{
 assert(m_ExecMultiplicator>0);
 assert(m_spLog);

 if(!m_TestQueue_PushEvent.Create(NULL,/*manual reset*/true,/*init state*/false,NULL))
  win32lib::t_win32_error::throw_error(::GetLastError(),"TestFW__TestQueueMT::m_TestQueue_PushEvent");

 if(!m_TestQueue_PopEvent.Create(NULL,/*manual reset*/false,/*init state*/false,NULL))
  win32lib::t_win32_error::throw_error(::GetLastError(),"TestFW__TestQueueMT::m_TestQueue_PopEvent");
}//TestFW__TestQueueMT

//------------------------------------------------------------------------
TestFW__TestQueueMT::~TestFW__TestQueueMT()
{
}

//------------------------------------------------------------------------
TestFW__TestQueueMT::size_type TestFW__TestQueueMT::size()const
{
 const lock_guard_type __lock(m_TestQueueGuard);

 return m_TestQueue.size();
}//size

//------------------------------------------------------------------------
void TestFW__TestQueueMT::push_test(const TestFW__Test* const pTest)
{
 const lock_guard_type __lock(m_TestQueueGuard);

 m_TestQueue.push_back(pTest);

 if(!m_TestQueue_PushEvent.Set())
  throw std::runtime_error("Can't SetUp Push-Event State");
}//push_test

//------------------------------------------------------------------------
void TestFW__TestQueueMT::clear()
{
 const lock_guard_type __lock(m_TestQueueGuard);

 m_TestQueue.clear();
}//clear

//------------------------------------------------------------------------
void TestFW__TestQueueMT::no_new_test__no_throw(bool const clear)
{
 if(clear)
 {
  this->clear();
 }//if

 structure::interlocked::exchange(&m_TestQueue_NoNewTest,1);

 assert(m_TestQueue_NoNewTest==1);

 _VERIFY(m_TestQueue_PushEvent.Set());
}//no_new_test__no_throw

//------------------------------------------------------------------------
TestFW__TestCPtr TestFW__TestQueueMT::pop_test(const wchar_t* const ThreadName,
                                               HANDLE         const hCancelEvent)
{
 const TestFW__TestCPtr spTest(this->pop_test_impl(hCancelEvent));

 if(spTest)
 {
  //Add log message
  TestFW__SysTracer tracer(m_spLog,ThreadName);

  const lock_guard_type __lock(m_test_num_guard);

  ++m_test_num_gen;

  tracer<<L"[START  ] "<<spTest->get_id()
        <<L" [#"<<m_test_num_gen<<L"]"
        <<tso_obj::send;
 }//if spTest

 return spTest;
}//pop_test

//------------------------------------------------------------------------
TestFW__TestCPtr TestFW__TestQueueMT::pop_test_impl(HANDLE const hCancelEvent)
{
 for(;;)
 {
  {
   const lock_guard_type __lock(m_TestQueueGuard);

   if(!m_TestQueue.empty())
   {
    TestFW__TestCPtr spReturnTest;

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
DWORD TestFW__TestQueueMT::wait_pop_event(DWORD const dwMilliSeconds)
{
 return m_TestQueue_PopEvent.Wait(dwMilliSeconds);
}//wait_pop_event

//------------------------------------------------------------------------
void TestFW__TestQueueMT::add_result(const wchar_t*      const ThreadName,
                                     const TestFW__TestState2& TestResult)
{
 assert(ThreadName);

 {
  const lock_guard_type __lock(m_ResultGuard);

  m_Results.append(TestResult); //throw
 }//local

 //-----------------------------------------
 //m_spLog->add_other_error_count   (TestResult.err_count);
 //m_spLog->add_other_warning_count (TestResult.warning_count);

 //-----------------------------------------
 TestFW__SysTracer tracer(m_spLog,ThreadName);

 if(TestResult.err_count)
  tracer<<L"[FAILED ] ";
 else
 if(TestResult.warning_count)
  tracer<<L"[WARNING] ";
 else
  tracer<<L"[STOP   ] ";

 tracer<<TestResult.get_test_id()<<tso_obj::send;
}//add_result

////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestRunnerMT

TestFW__TestRunnerMT::TestFW__TestRunnerMT(TestFW__ExecutorMT* const pExecutor,
                                           size_t              const thread_idx,
                                           const std::wstring&       thread_name,
                                           log_ex_type*        const pLog)
 :m_pExecutor(structure::not_null_ptr(pExecutor))
 ,m_thread_idx(thread_idx)
 ,m_thread_name(thread_name)
 ,m_log(structure::not_null_ptr(pLog))
{
 assert(m_pExecutor);
 assert(m_log);
}//TestFW__TestRunnerMT

//------------------------------------------------------------------------
TestFW__TestRunnerMT::~TestFW__TestRunnerMT()
{
}

//------------------------------------------------------------------------
TestFW__TestRunnerMT::self_ptr TestFW__TestRunnerMT::create
                                  (TestFW__ExecutorMT* const pExecutor,
                                   size_t              const ThreadIdx,
                                   const std::string&        BaseLogFilePath)
{
 assert(pExecutor);

 //---------
 structure::str_formatter fLogFileName("%1_%2.log");

 fLogFileName<<BaseLogFilePath<<(ThreadIdx+1);

 const TestFW__SysLogStream::self_ptr
  spThreadLogStream
   (structure::not_null_ptr
     (new TestFW__SysLogStream_ToFile
       (fLogFileName.str())));

 assert(spThreadLogStream);

 //---------
 const TestFW__WorkerLog::self_ptr
  spThreadLog
   (structure::not_null_ptr
     (new TestFW__WorkerLog
       (spThreadLogStream)));

 assert(spThreadLog);

 spThreadLog->print_ts=true;

 spThreadLog->print_thread_id=true;

 //---------
 structure::wstr_formatter fThreadName(L"Thread #%1");

 fThreadName<<(ThreadIdx+1);

 //---------
 return structure::not_null_ptr
         (new TestFW__TestRunnerMT
           (pExecutor,
            ThreadIdx,
            fThreadName.str(),
            spThreadLog));
}//create

//------------------------------------------------------------------------
const wchar_t* TestFW__TestRunnerMT::thread_name_impl()const
{
 return m_thread_name.c_str();
}//thread_name_impl

//------------------------------------------------------------------------
void TestFW__TestRunnerMT::thread_worker_impl()
{
 assert(m_pExecutor);

 m_pExecutor->Internal__ThreadWorker(this);
}//thread_worker_impl

////////////////////////////////////////////////////////////////////////////////
//class TestFW__ExecutorMT

TestFW__ExecutorMT::TestFW__ExecutorMT
                            (const std::string& BaseLogFilePath,
                             log_ex_type* const pLog,
                             size_t       const nThreads)
 :m_BaseLogFilePath (BaseLogFilePath)
 ,m_spLog           (structure::not_null_ptr(pLog))
 ,m_nThreads        (nThreads)
 ,m_spTestQueue     (structure::not_null_ptr(new test_queue_type(pLog,1)))
{
 assert(m_spLog);
 assert(m_nThreads>0);

#ifndef NDEBUG
 m_debug__IsStopped=0;
#endif
}//TestFW__ExecutorMT

//------------------------------------------------------------------------
TestFW__ExecutorMT::~TestFW__ExecutorMT()
{
}

//------------------------------------------------------------------------
void TestFW__ExecutorMT::final_release()
{
 m_TestRunners.clear();

 inherited::final_release();
}//final_release

//TestFW__PushTest interface ---------------------------------------------
void TestFW__ExecutorMT::PushTest(const test_type* const pTest)
{
 assert(pTest);
 assert(m_spLog);
 assert(m_nThreads>0);
 assert(m_spTestQueue);

 //-----------------------------------------
 TestFW__SysTracer tracer(m_spLog);

 //-----------------------------------------
 if(m_TestRunners.empty())
 {
  //First call.
  tracer<<L"Creation "<<m_nThreads<<L" thread(s)..."<<tso_obj::send;

  //---------------------------------------- Create Thread Workers
  runners_type TestRunners;

  for(size_t i=0;i!=m_nThreads;++i)
  {
   TestRunners.push_back
    (runner_type::create
      (this,
       i,
       m_BaseLogFilePath));
  }//for

  //---------------------------------------- Run Thread Workers
  for(runners_type::const_iterator i(TestRunners.begin()),_e(TestRunners.end());
      i!=_e;
      ++i)
  {
   assert((*i));

   tracer<<L"Start "<<(*i)->thread_name()<<tso_obj::send;

   (*i)->start_thread();//throw
  }//for

  //---------------------------------------- Install Thread Workers
  m_TestRunners.swap(TestRunners);
 }//if first call

 //Add new test to workers queue
 for(;;)
 {
  if(m_spTestQueue->size()<4*m_nThreads)
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
void TestFW__ExecutorMT::cancel()
{
 TestFW__SysTracer tracer(m_spLog);

 tracer<<L"Cancel. Clear test queue..."<<tso_obj::send;

 m_spTestQueue->no_new_test__no_throw(true);
}//cancel

//------------------------------------------------------------------------
void TestFW__ExecutorMT::stop__no_throw()
{
 TestFW__SysTracer tracer(m_spLog);

 try
 {
  tracer<<L"Wait Runners' Threads..."<<tso_obj::send;
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
   tracer<<L"Wait "<<m_TestRunners[i]->thread_name()<<tso_obj::send;
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
          <<tso_obj::send;

    //--- Print thread errors into thread log
    TestFW__SysTracer thread_tracer(m_TestRunners[i]->thread_log());

    TestFW__ExceptionRouter::route(thread_tracer);
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
   tracer(tso_obj::tso_msg_error,-1)<<L"Test queue has ["<<n<<L"] elements"<<tso_obj::send;
  }
  catch(...)
  {
   m_spLog->add_other_error_count(1);
  }

  m_spTestQueue->clear();
 }//if

 //-----------------------------------------
 DEBUG_CODE(structure::interlocked::exchange(&m_debug__IsStopped,1));
}//stop__no_throw

//------------------------------------------------------------------------
TestFW__ExecutorMT::tag_summary_result TestFW__ExecutorMT::build_summary2()
{
 assert(m_debug__IsStopped!=0);
 //this->stop();

 //return m_spTestQueue->build_summary(m_TestRunners);

 assert(m_spTestQueue);

 const char* const c_bugcheck_src
  ="TestFW__TestQueueMT::build_summary";

 using summary_builder_type
  =TestFW__SummaryBuilder;

 using builders_type
  =structure::t_smart_vector<summary_builder_type,TestFW__SysMemoryAllocator>;

 const TestFW__TestQueueMT::lock_guard_type __lock(m_spTestQueue->m_ResultGuard);

 //Summary
 //1. Tests with errors
 //2. Tests with warnings
 //3. Runners statistics
 //4. Main thread errors count
 //5. Total informations

 //----------------------------------------- prepare summary builders
 tag_summary_result result;

 result.nTotalErrors   = m_spLog->get_total_error_count();
 result.nTotalWarnings = m_spLog->get_total_warning_count();

 const summary_builder_type::self_ptr
  spRootBuilder
   (structure::not_null_ptr
     (new summary_builder_type
       (m_spLog.ptr())));

 builders_type ThreadBuilders;

 for(size_t i=0;i!=m_TestRunners.size();++i)
 {
  assert(m_TestRunners[i]);

  const TestFW__WorkerLog::self_ptr spThreadLog(m_TestRunners[i]->thread_log());

  assert(spThreadLog);

  result.nTotalErrors    +=spThreadLog->get_error_count();
  result.nTotalWarnings  +=spThreadLog->get_warning_count();

  const summary_builder_type::self_ptr
   spThreadSummaryBuilder
    (structure::not_null_ptr
      (new summary_builder_type
        (spThreadLog.ptr())));

  ThreadBuilders.push_back(spThreadSummaryBuilder);
 }//for i

 assert(ThreadBuilders.size()==m_TestRunners.size());

 //----------------------------------------- build total info
 using test_results_type=TestFW__TestQueueMT::test_results_type;
 using result_count_type=test_results_type::count_type;

 result_count_type const cResults=m_spTestQueue->m_Results.get_count();

 test_results_type::item_type Result;

 m_spTestQueue->m_Results.restart();

 for(result_count_type i=0;i!=cResults;++i)
 {
  m_spTestQueue->m_Results.fetch(&Result);

  if(!(Result.thread_idx<m_TestRunners.size()))
  {
   structure::str_formatter
    fmsg("[BUG CHECK][%1][#001]\n"
         "wrong thread_idx [%2] in test state [%3].");

   fmsg<<c_bugcheck_src<<Result.thread_idx<<i;

   throw std::runtime_error(fmsg.str());
  }//if

  assert(Result.thread_idx<m_TestRunners.size());

  spRootBuilder->process_result(Result);

  ThreadBuilders[Result.thread_idx]->process_result(Result);
 }//for i

 //----------------------------------------- Print tests with errors
 m_spTestQueue->m_Results.restart();

 for(result_count_type i=0;i!=cResults;++i)
 {
  m_spTestQueue->m_Results.fetch(&Result);

  if(!(Result.thread_idx<m_TestRunners.size()))
  {
   structure::str_formatter
    fmsg("[BUG CHECK][%1][#002]\n"
         "wrong thread_idx [%2] in test state [%3].");

   fmsg<<c_bugcheck_src<<Result.thread_idx<<i;

   throw std::runtime_error(fmsg.str());
  }//if

  assert(Result.thread_idx<m_TestRunners.size());

  if(Result.err_count==0)
   continue;

  spRootBuilder->print_test_with_error
   (Result,
    m_TestRunners[Result.thread_idx]->thread_name());

  ThreadBuilders[Result.thread_idx]->print_test_with_error
   (Result,
    L"");
 }//for i

 //----------------------------------------- Print tests with warnings
 m_spTestQueue->m_Results.restart();

 for(result_count_type i=0;i!=cResults;++i)
 {
  m_spTestQueue->m_Results.fetch(&Result);

  if(!(Result.thread_idx<m_TestRunners.size()))
  {
   structure::str_formatter
    fmsg("[BUG CHECK][%1][#003]\n"
         "wrong thread_idx [%2] in test state [%3].");

   fmsg<<c_bugcheck_src<<Result.thread_idx<<i;

   throw std::runtime_error(fmsg.str());
  }//if

  assert(Result.thread_idx<m_TestRunners.size());

  if(Result.warning_count==0)
   continue;

  spRootBuilder->print_test_with_warning
   (Result,m_TestRunners[(Result).thread_idx]->thread_name());

  ThreadBuilders[Result.thread_idx]->print_test_with_warning
   (Result,L"");
 }//for i

 //----------------------------------------- Print total infromation
 for(size_t i(0);i!=m_TestRunners.size();++i)
 {
  assert(ThreadBuilders[i]);

  ThreadBuilders[i]->print_summary
   (L"",
    true);

  ThreadBuilders[i]->print_summary_ex
   (spRootBuilder->m_Tracer,
    m_TestRunners[i]->thread_name(),
    true);
 }//for i

 spRootBuilder->print_total
  (L"ROOT THREAD",
   m_spLog->get_error_count(),
   m_spLog->get_warning_count());

 //-------------
 spRootBuilder->print_summary
  (L"SUMMARY INFORMATION",false);

 //-------------
 return result;
}//build_summary2

//------------------------------------------------------------------------
void TestFW__ExecutorMT::Internal__ThreadWorker(const runner_type* const pRunner)const
{
 assert(pRunner);

 using run_context_type
  =structure::test_fw::set01::TestFW__RunContext;

 const run_context_type::self_ptr
  spCtx
   (structure::not_null_ptr
     (new run_context_type
       (pRunner->thread_log())));

 TestFW__SysTracer
  thread_tracer(pRunner->thread_log());

 thread_tracer<<L"Thread Name: "<<pRunner->thread_name()<<tso_obj::send;
 thread_tracer<<L"Thread ID  : "<<::GetCurrentThreadId()<<tso_obj::send;
 thread_tracer<<tso_obj::send;

 //--------------
 //m_spSD->LogDataSourceInfo(m_log);

 //--------------
 std::string test_id;

 for(;;)
 {
  if(pRunner->get_stop_signal()!=0)
  {
   thread_tracer<<L"Exit. Detect SetUp of Stop Signal."<<tso_obj::send;
   return;
  }

  const TestFW__TestCPtr
   spTest
    (m_spTestQueue->pop_test
      (pRunner->thread_name(),
       pRunner->get_stop_event()));

  if(!spTest)
  {
   thread_tracer<<L"Exit. Tests queue do not return next test."<<tso_obj::send;
   return;
  }

  //---------
  spCtx->m_test_info.reset();

  spCtx->m_test_info.thread_idx=pRunner->thread_idx();

  //---------
  test_id=spTest->get_id();

  spCtx->m_test_info.set_test_id(test_id);

  //----------------------------------------
  TestFW__SysTracer test_tracer(spCtx,structure::tstr_to_wstr(test_id));

  test_tracer(tso_obj::tso_msg_start_test,0)<<tso_obj::send;

  {
   //thread_tracer<<"* RUN"<<tso_obj::send;

   TestFW__PerfTimers timer;

   try
   {
    spTest->run(spCtx);
   }
   catch(...)
   {
    TestFW__ExceptionRouter::route(test_tracer);
   }//catch

   timer.Stop();

   spCtx->m_test_info.real_time   =timer.RealTime();
   spCtx->m_test_info.user_time   =timer.UserTime();
   spCtx->m_test_info.kernel_time =timer.KernelTime();

   //---------
   thread_tracer<<L"*"<<tso_obj::send;

   thread_tracer<<L"* REAL   TIME:"<<TestFW__TimeToStrEx(spCtx->m_test_info.real_time)<<tso_obj::send;
   thread_tracer<<L"* USER   TIME:"<<TestFW__TimeToStrEx(spCtx->m_test_info.user_time)<<tso_obj::send;
   thread_tracer<<L"* KERNEL TIME:"<<TestFW__TimeToStrEx(spCtx->m_test_info.kernel_time)<<tso_obj::send;
   thread_tracer<<L"* TOTAL  TIME:"<<TestFW__TimeToStrEx(spCtx->m_test_info.kernel_time+
                                                         spCtx->m_test_info.user_time)<<tso_obj::send;

   thread_tracer<<L"*"<<tso_obj::send;
  }//local

  //---------
  test_tracer(tso_obj::tso_msg_stop_test,0)<<tso_obj::send;

  //---------
  m_spTestQueue->add_result(pRunner->thread_name(),spCtx->m_test_info);
 }//for[ever]
}//Internal__ThreadWorker

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
