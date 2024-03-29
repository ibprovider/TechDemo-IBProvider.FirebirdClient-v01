////////////////////////////////////////////////////////////////////////////////
#ifndef _test_fw_set01__summary_builder_CC_
#define _test_fw_set01__summary_builder_CC_

#include <win32lib/win32_error.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__SummaryBuilder

template<class TRootLog>
TestFW__SummaryBuilder::TestFW__SummaryBuilder(TRootLog* const pLog)
 :m_Tracer            (pLog,L"summary")
 ,m_nLogErrors        (pLog->get_error_count())
 ,m_nLogWarnings      (pLog->get_warning_count())
 ,m_nTest             (0)
 ,m_nTestWithErrors   (0)
 ,m_nTestWithWarnings (0)
 ,m_nTestSucceeded    (0)
 ,m_nTestErrors       (0)
 ,m_nTestWarnings     (0)
 ,m_Time_Real         (0)
 ,m_Time_User         (0)
 ,m_Time_Kernel       (0)
{;}

//------------------------------------------------------------------------
template<class TTestState>
void TestFW__SummaryBuilder::process_result
                                      (const TTestState& test_status)
{
 ++m_nTest;

 m_Time_Real   +=test_status.real_time;
 m_Time_User   +=test_status.user_time;
 m_Time_Kernel +=test_status.kernel_time;

 if(test_status.err_count==0 && test_status.warning_count==0)
  ++m_nTestSucceeded;
}//process_result

//------------------------------------------------------------------------
template<class TTestState>
void TestFW__SummaryBuilder::print_test_with_error
                                      (const TTestState& test_status,
                                       wstr_param_type   ext_info)
{
 if(m_nTestWithErrors==0)
 {
  m_Tracer<<tso_obj::send;
  m_Tracer<<sm_line2<<tso_obj::send;
  m_Tracer<<L"[Tests with errors]"<<tso_obj::send;
 }

 ++m_nTestWithErrors;

 m_nTestErrors+=test_status.err_count;

 m_Tracer<<m_nTestWithErrors<<L". "
         <<test_status.get_test_id()
         <<L" - "<<test_status.err_count<<L" error(s)";

 if(!ext_info.empty())
 {
  m_Tracer<<L" ["<<ext_info.str()<<L"]";
 }

 m_Tracer<<tso_obj::send;
}//print_test_with_error

//------------------------------------------------------------------------
template<class TTestState>
void TestFW__SummaryBuilder::print_test_with_warning
                                      (const TTestState& test_status,
                                       wstr_param_type   ext_info)
{
 if(m_nTestWithWarnings==0)
 {
  m_Tracer<<tso_obj::send;
  m_Tracer<<sm_line2<<tso_obj::send;
  m_Tracer<<L"[Tests with warnings]"<<tso_obj::send;
 }

 ++m_nTestWithWarnings;

 m_nTestWarnings+=test_status.warning_count;

 m_Tracer<<m_nTestWithWarnings<<L". "
         <<test_status.get_test_id()<<L" - "
         <<test_status.warning_count<<L" warning(s)";

 if(!ext_info.empty())
 {
  m_Tracer<<L" ["<<ext_info.str()<<L"]";
 }

 m_Tracer<<tso_obj::send;
}//print_test_with_warning

//------------------------------------------------------------------------
template<class TTracer>
void TestFW__SummaryBuilder::print_summary_ex
                                      (TTracer&        tracer,
                                       wstr_param_type header,
                                       bool  const     print_total_from_log)
{
 assert(m_nTestWithErrors   <=m_nTest);
 assert(m_nTestWithWarnings <=m_nTest);
 assert(m_nTestSucceeded    <=m_nTest);

 assert(m_nTestSucceeded<=m_nTest-m_nTestWithErrors);
 assert(m_nTestSucceeded<=m_nTest-m_nTestWithWarnings);

 //-----------
 tracer<<tso_obj::send;

 if(header.empty())
 {
  tracer<<sm_line2<<tso_obj::send;
 }
 else
 {
  tracer<<sm_line1<<L" ["<<header.str()<<L"]"<<tso_obj::send;
 }//else

 tracer<<L"[TESTS]"<<tso_obj::send;

 tracer<<L"EXECUTED      : "<<m_nTest<<tso_obj::send;
 tracer<<L"SUCCEEDED     : "<<m_nTestSucceeded<<tso_obj::send;

 //-----
 tracer<<L"FAILED        : "<<m_nTestWithErrors;

 if(m_nTestErrors)
  tracer<<L" [ "<<m_nTestErrors<<L" error(s) ]";

 tracer<<tso_obj::send;

 //-----
 tracer<<L"WITH WARNINGS : "<<m_nTestWithWarnings;

 if(m_nTestWarnings)
  tracer<<L" [ "<<m_nTestWarnings<<L" warning(s) ]";

 tracer<<tso_obj::send;

 //-----
 tracer<<tso_obj::send;
 tracer<<sm_line2<<tso_obj::send;
 tracer<<L"[TEST TIMES]"<<tso_obj::send;
 tracer<<L"REAL          : "<<TestFW__TimeToStrEx(m_Time_Real)<<tso_obj::send;
 tracer<<L"USER          : "<<TestFW__TimeToStrEx(m_Time_User)<<tso_obj::send;
 tracer<<L"KERNEL        : "<<TestFW__TimeToStrEx(m_Time_Kernel)<<tso_obj::send;
 tracer<<L"TOTAL         : "<<TestFW__TimeToStrEx(m_Time_Kernel+m_Time_User)<<tso_obj::send;

 //-----
 if(print_total_from_log)
 {
  tracer<<tso_obj::send;

  self_type::print_total_ex
   (tracer,
    L"",
    m_nLogErrors,
    m_nLogWarnings);
 }//if
}//print_summary_ex

//------------------------------------------------------------------------
template<class TTracer>
void TestFW__SummaryBuilder::print_total_ex
                                      (TTracer&              tracer,
                                       wstr_param_type const header,
                                       count_type      const nError,
                                       count_type      const nWarning)
{
 if(header.empty())
 {
  tracer<<sm_line2<<tso_obj::send;
 }
 else
 {
  tracer<<sm_line1<<L" ["<<header.str()<<L"]"<<tso_obj::send;
 }

 tracer<<L"TOTAL ERRORS  : "<<nError<<tso_obj::send;
 tracer<<L"TOTAL WARNINGS: "<<nWarning<<tso_obj::send;
}//print_total_ex

//------------------------------------------------------------------------
template<class TTracer>
void TestFW__SummaryBuilder::print_total_ex
                                      (TTracer&              tracer,
                                       wstr_param_type const header,
                                       count_type      const nError,
                                       count_type      const nWarning,
                                       count_type      const nFullPass,
                                       count_type      const nTotalTests)
{
 self_type::print_total_ex(tracer,header,nError,nWarning);

 tracer<<L"FULL PASSES   : "<<nFullPass<<tso_obj::send;
 tracer<<L"TOTAL TESTS   : "<<nTotalTests<<tso_obj::send;
}//print_total_ex

//------------------------------------------------------------------------
template<class TTracer>
void TestFW__SummaryBuilder::print_summary_process_state
                                      (TTracer& tracer)
{
 tracer<<sm_line1<<L" [PROCESS INFORMATION]"<<tso_obj::send;

 HANDLE const hCurrentProcess=::GetCurrentProcess();

 {
  tracer<<L"[VIRTUAL MEMORY]"<<tso_obj::send;
  tracer<<tso_obj::send;

  PROCESS_MEMORY_COUNTERS info={0};

  info.cb=sizeof(info);

  const bool info_ok
    =::GetProcessMemoryInfo
      (hCurrentProcess,
       &info,
       sizeof(info))!=FALSE;

  if(!info_ok)
  {
   DWORD const dwLastError=::GetLastError();

   assert(dwLastError!=0);

   tracer(tso_obj::tso_msg_error,-1)
    <<L"Can't get process memory info.\n"
    <<win32lib::GetErrorMsg(dwLastError,true)
    <<tso_obj::send;

   tracer<<tso_obj::send;
  }//if !info_ok

  //----------------------------------------
  MEMORYSTATUSEX status={0};

  status.dwLength=sizeof(status);

  const bool status_ok=::GlobalMemoryStatusEx(&status)!=FALSE;

  //----------------------------------------
  tracer
   <<L"PRIVATE BYTES      : "
   <<TestFW__MemSizeToStrEx2_KB(info_ok,info.PagefileUsage)
   <<tso_obj::send;

  tracer<<L"PEAK PRIVATE BYTES : "
   <<TestFW__MemSizeToStrEx2_KB(info_ok,info.PeakPagefileUsage)
   <<tso_obj::send;

  tracer<<L"VIRTUAL SIZE       : "
   <<TestFW__MemSizeToStrEx2_KB(status_ok,status.ullTotalVirtual-status.ullAvailVirtual)
   <<tso_obj::send;

  tracer
   <<L"PAGE FAULT COUNT   : "
   <<TestFW_TraceDataOrNA(info_ok,info.PageFaultCount)
   <<tso_obj::send;
 }//local - virtual memory

 tracer<<tso_obj::send;
 tracer<<sm_line2<<tso_obj::send;

 {
  tracer<<L"[HANDLES]"<<tso_obj::send;
  tracer<<tso_obj::send;

  DWORD handle_count=0;

  bool handle_count_ok
   =::GetProcessHandleCount(hCurrentProcess,&handle_count)!=FALSE;

  if(!handle_count_ok)
  {
   DWORD const dwLastError=::GetLastError();

   assert(dwLastError!=0);

   tracer(tso_obj::tso_msg_error,-1)
    <<L"Can't get process handle count.\n"
    <<win32lib::GetErrorMsg(dwLastError)
    <<tso_obj::send;

   tracer<<tso_obj::send;
  }//if

  tracer
   <<L"HANDLES            : "
   <<TestFW_TraceDataOrNA(handle_count_ok,handle_count)
   <<tso_obj::send;
 }//local - handles
}//print_summary_process_state

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
