////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_summary_builder.h"
#include "source/test_utilities.h"
#include "source/test_tracer_utils.h"
#include <win32lib/win32_error.h>
#include <psapi.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_SummaryBuilder

const wchar_t* const TTSO_SummaryBuilder::sm_line1
 =L"-------------------------------------------";

//------------------------------------------------------------------------
const wchar_t* const TTSO_SummaryBuilder::sm_line2
 =L"- - - - - - - - - - - - - - - - - - - - - -";

//------------------------------------------------------------------------
TTSO_SummaryBuilder::~TTSO_SummaryBuilder()
{;}

//------------------------------------------------------------------------
void TTSO_SummaryBuilder::process_result(const TTSO_TestState2& test_status)
{
 ++m_nTest;

 m_Time_Real   +=test_status.real_time;
 m_Time_User   +=test_status.user_time;
 m_Time_Kernel +=test_status.kernel_time;

 if(test_status.err_count==0 && test_status.warning_count==0)
  ++m_nTestSucceeded;
}//process_result

//------------------------------------------------------------------------
void TTSO_SummaryBuilder::print_test_with_error
                                           (const TTSO_TestState2& test_status,
                                            wstr_param_type        ext_info)
{
 if(m_nTestWithErrors==0)
 {
  m_Tracer<<send;
  m_Tracer<<sm_line2<<send;
  m_Tracer<<L"[Tests with errors]"<<send;
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

 m_Tracer<<send;
}//print_test_with_error

//------------------------------------------------------------------------
void TTSO_SummaryBuilder::print_test_with_warning
                                           (const TTSO_TestState2& test_status,
                                            wstr_param_type        ext_info)
{
 if(m_nTestWithWarnings==0)
 {
  m_Tracer<<send;
  m_Tracer<<sm_line2<<send;
  m_Tracer<<L"[Tests with warnings]"<<send;
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

 m_Tracer<<send;
}//print_test_with_warning

//------------------------------------------------------------------------
void TTSO_SummaryBuilder::print_summary(wstr_param_type header,
                                        bool  const     print_total_from_log)
{
 this->print_summary_ex(m_Tracer,header,print_total_from_log);
}//print_summary

//------------------------------------------------------------------------
void TTSO_SummaryBuilder::print_total(wstr_param_type const header,
                                      size_t          const nError,
                                      size_t          const nWarning)
{
 this->print_total_ex(m_Tracer,header,nError,nWarning);
}//print_total

//------------------------------------------------------------------------
void TTSO_SummaryBuilder::print_summary_ex(TTSO_Tracer&    tracer,
                                           wstr_param_type header,
                                           bool  const     print_total_from_log)
{
 assert(m_nTestWithErrors   <=m_nTest);
 assert(m_nTestWithWarnings <=m_nTest);
 assert(m_nTestSucceeded    <=m_nTest);

 assert(m_nTestSucceeded<=m_nTest-m_nTestWithErrors);
 assert(m_nTestSucceeded<=m_nTest-m_nTestWithWarnings);

 //-----------
 tracer<<send;

 if(header.empty())
 {
  tracer<<sm_line2<<send;
 }
 else
 {
  tracer<<sm_line1<<L" ["<<header.str()<<L"]"<<send;
 }

 tracer<<L"[TESTS]"<<send;

 tracer<<L"EXECUTED      : "<<m_nTest<<send;
 tracer<<L"SUCCEEDED     : "<<m_nTestSucceeded<<send;

 //-----
 tracer<<L"FAILED        : "<<m_nTestWithErrors;

 if(m_nTestErrors)
  tracer<<L" [ "<<m_nTestErrors<<L" error(s) ]";

 tracer<<send;

 //-----
 tracer<<L"WITH WARNINGS : "<<m_nTestWithWarnings;

 if(m_nTestWarnings)
  tracer<<L" [ "<<m_nTestWarnings<<L" warning(s) ]";

 tracer<<send;

 //-----
 tracer<<send;
 tracer<<sm_line2<<send;
 tracer<<L"[TEST TIMES]"<<send;
 tracer<<L"REAL          : "<<TSO_TimeToStrEx(m_Time_Real)<<send;
 tracer<<L"USER          : "<<TSO_TimeToStrEx(m_Time_User)<<send;
 tracer<<L"KERNEL        : "<<TSO_TimeToStrEx(m_Time_Kernel)<<send;
 tracer<<L"TOTAL         : "<<TSO_TimeToStrEx(m_Time_Kernel+m_Time_User)<<send;

 //-----
 if(print_total_from_log)
 {
  tracer<<send;

  this->print_total_ex(tracer,
                       L"",
                       m_nLogErrors,
                       m_nLogWarnings);
 }
}//print_summary_ex

//------------------------------------------------------------------------
void TTSO_SummaryBuilder::print_summary_process_state(TSYS_Tracer& tracer)
{
 tracer<<sm_line1<<L" [PROCESS INFORMATION]"<<send;

 HANDLE const hCurrentProcess=::GetCurrentProcess();

 {
  tracer<<L"[VIRTUAL MEMORY]"<<send;
  tracer<<send;

  PROCESS_MEMORY_COUNTERS info={0};

  info.cb=sizeof(info);

  const bool info_ok=::GetProcessMemoryInfo(hCurrentProcess,
                                            &info,
                                            sizeof(info))!=FALSE;

  if(!info_ok)
  {
   DWORD const dwLastError=::GetLastError();

   assert(dwLastError!=0);

   tracer(tso_msg_error,-1)
    <<L"Can't get process memory info.\n"
    <<win32lib::GetErrorMsg(dwLastError,true)
    <<send;

   tracer<<send;
  }//if !info_ok

  //----------------------------------------
  MEMORYSTATUSEX status={0};

  status.dwLength=sizeof(status);

  const bool status_ok=::GlobalMemoryStatusEx(&status)!=FALSE;

  //----------------------------------------
  tracer<<L"PRIVATE BYTES      : "<<TSO_MemSizeToStrEx2_KB
                                     (info_ok,
                                      info.PagefileUsage)
                                  <<send;

  tracer<<L"PEAK PRIVATE BYTES : "<<TSO_MemSizeToStrEx2_KB
                                     (info_ok,
                                      info.PeakPagefileUsage)
                                  <<send;

  tracer<<L"VIRTUAL SIZE       : "<<TSO_MemSizeToStrEx2_KB
                                     (status_ok,
                                      status.ullTotalVirtual-status.ullAvailVirtual)
                                  <<send;

  tracer<<L"PAGE FAULT COUNT   : "
        <<ibp_tso_trace_data_or_na(info_ok,info.PageFaultCount)
        <<send;
 }//local - virtual memory

 tracer<<send;
 tracer<<sm_line2<<send;

 {
  tracer<<L"[HANDLES]"<<send;
  tracer<<send;

  DWORD handle_count=0;

  bool handle_count_ok
   =::GetProcessHandleCount(hCurrentProcess,&handle_count)!=FALSE;

  if(!handle_count_ok)
  {
   DWORD const dwLastError=::GetLastError();

   assert(dwLastError!=0);

   tracer(tso_msg_error,-1)
    <<L"Can't get process handle count.\n"
    <<win32lib::GetErrorMsg(dwLastError)
    <<send;

   tracer<<send;
  }//if

  tracer<<L"HANDLES            : "
        <<ibp_tso_trace_data_or_na(handle_count_ok,handle_count)
        <<send;
 }//local - handles
}//print_summary_process_state

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
