////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_perf_timers.h"
#include "source/test_utilities.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_PerfTimers

TTSO_PerfTimers::TTSO_PerfTimers()
{
 this->Start();
}

//------------------------------------------------------------------------
TTSO_PerfTimers::~TTSO_PerfTimers()
{;}

//------------------------------------------------------------------------
void TTSO_PerfTimers::Start()
{
 m_RealTimer.start();
 m_ThreadTimer.Start(true);
}//Start

//------------------------------------------------------------------------
void TTSO_PerfTimers::Stop()
{
 m_ThreadTimer.Stop();
 m_RealTimer.stop();
}//Stop

//------------------------------------------------------------------------
void TTSO_PerfTimers::StopAndPrint(TTSO_Tracer& tracer)
{
 this->Stop();
 this->Print(tracer);
}//StopAndPrint

//------------------------------------------------------------------------
__int64 TTSO_PerfTimers::UserTime()const
{
 return m_ThreadTimer.UserTime();
}//UserTime

//------------------------------------------------------------------------
__int64 TTSO_PerfTimers::KernelTime()const
{
 return m_ThreadTimer.KernelTime();
}//KernelTime

//------------------------------------------------------------------------
__int64 TTSO_PerfTimers::RealTime()const
{
 return m_RealTimer.value();
}//RealTime

//------------------------------------------------------------------------
void TTSO_PerfTimers::Print(TTSO_Tracer& tracer)
{
 tracer<<L"* REAL   TIME:"<<TSO_TimeToStrEx(this->RealTime())<<send;
 tracer<<L"* USER   TIME:"<<TSO_TimeToStrEx(this->UserTime())<<send;
 tracer<<L"* KERNEL TIME:"<<TSO_TimeToStrEx(this->KernelTime())<<send;
 tracer<<L"* TOTAL  TIME:"<<TSO_TimeToStrEx(this->UserTime()+this->KernelTime())<<send;
}//Print

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
