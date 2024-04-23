////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
//#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__perf_timers.h>

#include <lcpi/infrastructure/os/lcpi.infrastructure.os.mt-thread_api.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////

using lcpi::infrastructure::os::mt::LCPI_OS__ThreadApi;

////////////////////////////////////////////////////////////////////////////////
//class TestFW__PerfTimers

TestFW__PerfTimers::TestFW__PerfTimers()
 :m_Start_RealTime()
 ,m_Start_KernelTime()
 ,m_Start_UserTime()
 ,m_Sum_RealTime()
 ,m_Sum_KernelTime()
 ,m_Sum_UserTime()
{
 this->Start();
}

//------------------------------------------------------------------------
TestFW__PerfTimers::~TestFW__PerfTimers()
{
}//~TestFW__PerfTimers

//------------------------------------------------------------------------
void TestFW__PerfTimers::Start()
{
 //Stop and start must be called in one thread :)

 this->Helper__GetTimes
  (&m_Start_RealTime,
   &m_Start_KernelTime,
   &m_Start_UserTime);
}//Start

//------------------------------------------------------------------------
void TestFW__PerfTimers::Stop()
{
 //Stop and start must be called in one thread :)

 time_point_type realTime  =time_point_type();
 time_point_type kernelTime=time_point_type();
 time_point_type userTime  =time_point_type();

 this->Helper__GetTimes
  (&realTime,
   &kernelTime,
   &userTime);

 //correction
 realTime    =(std::max)(realTime   ,m_Start_RealTime);
 kernelTime  =(std::max)(kernelTime ,m_Start_KernelTime);
 userTime    =(std::max)(userTime   ,m_Start_UserTime);

 const auto duration__realTime   =std::chrono::duration_cast<duration_type>(realTime-m_Start_RealTime);
 const auto duration__kernelTime =std::chrono::duration_cast<duration_type>(kernelTime-m_Start_KernelTime);
 const auto duration__userTime   =std::chrono::duration_cast<duration_type>(userTime-m_Start_UserTime);

 //---------------------------
 self_type::Helper__SafeAdd
  (&m_Sum_RealTime,
   duration__realTime);

 self_type::Helper__SafeAdd
  (&m_Sum_KernelTime,
   duration__kernelTime);

 self_type::Helper__SafeAdd
  (&m_Sum_UserTime,
   duration__userTime);

 //---------------------------
 m_Start_RealTime   =realTime;
 m_Start_KernelTime =kernelTime;
 m_Start_UserTime   =userTime;
}//Stop

//------------------------------------------------------------------------
TestFW__PerfTimers::duration_type TestFW__PerfTimers::UserTime()const
{
 return m_Sum_UserTime;
}//UserTime

//------------------------------------------------------------------------
TestFW__PerfTimers::duration_type TestFW__PerfTimers::KernelTime()const
{
 return m_Sum_KernelTime;
}//KernelTime

//------------------------------------------------------------------------
TestFW__PerfTimers::duration_type TestFW__PerfTimers::RealTime()const
{
 return m_Sum_RealTime;
}//RealTime

//Helper methods ---------------------------------------------------------
void TestFW__PerfTimers::Helper__GetTimes
                        (time_point_type* const pRealTime,
                         time_point_type* const pKernelTime,
                         time_point_type* const pUserTime)
{
 assert(pRealTime!=nullptr);
 assert(pKernelTime!=nullptr);
 assert(pUserTime!=nullptr);

 //--------------------------- REAL TIME

 // STL of VS2013 can't assign simple 'timer_type::now()';

 (*pRealTime)=time_point_type(timer_type::now().time_since_epoch());

 //--------------------------- THREAD TIME
 using OS_TIME_DURATION
  =LCPI_OS__ThreadApi::TIME_DURATION;

 OS_TIME_DURATION
  kernelTime
   =OS_TIME_DURATION();

 OS_TIME_DURATION
  userTime
   =OS_TIME_DURATION();

 LCPI_OS__ThreadApi::GetCurrentThreadUsageTimes
  (&kernelTime,
   &userTime); //throw

 (*pKernelTime) =time_point_type()+kernelTime;
 (*pUserTime)   =time_point_type()+userTime;
}//Helper__GetTimes

//------------------------------------------------------------------------
void TestFW__PerfTimers::Helper__SafeAdd
                        (duration_type* const pSum,
                         duration_type  const value)
{
 LCPI__assert(pSum!=nullptr);

 LCPI__assert((*pSum)>=duration_type());
 LCPI__assert(value>=duration_type());

 const auto c_MAX=(duration_type::max)();

 LCPI__assert((*pSum)<=c_MAX);
 LCPI__assert(value<=c_MAX);

 if((c_MAX-(*pSum))<value)
   (*pSum)=c_MAX;
 else
  (*pSum)+=value;
}//Helper__SafeAdd

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
