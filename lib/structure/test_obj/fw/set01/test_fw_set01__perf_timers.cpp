////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__perf_timers.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__PerfTimers

TestFW__PerfTimers::TestFW__PerfTimers()
{
 this->Start();
}

//------------------------------------------------------------------------
TestFW__PerfTimers::~TestFW__PerfTimers()
{;}

//------------------------------------------------------------------------
void TestFW__PerfTimers::Start()
{
 m_RealTimer.start();
 m_ThreadTimer.Start(true);
}//Start

//------------------------------------------------------------------------
void TestFW__PerfTimers::Stop()
{
 m_ThreadTimer.Stop();
 m_RealTimer.stop();
}//Stop

//------------------------------------------------------------------------
std::int64_t TestFW__PerfTimers::UserTime()const
{
 return m_ThreadTimer.UserTime();
}//UserTime

//------------------------------------------------------------------------
std::int64_t TestFW__PerfTimers::KernelTime()const
{
 return m_ThreadTimer.KernelTime();
}//KernelTime

//------------------------------------------------------------------------
std::int64_t TestFW__PerfTimers::RealTime()const
{
 return m_RealTimer.value();
}//RealTime

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
