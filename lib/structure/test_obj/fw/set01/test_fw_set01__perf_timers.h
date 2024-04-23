////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__perf_timers_H_
#define _test_fw_set01__perf_timers_H_

#include <structure/test_obj/fw/set01/test_fw_set01__utilities.h>

#include <chrono>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__PerfTimers

class TestFW__PerfTimers LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TestFW__PerfTimers;

  TestFW__PerfTimers(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using TICK_VALUE
   =std::int64_t;

  using tick_type=std::ratio<1,10*1000*1000>; // Windows tick

  using duration_type=std::chrono::duration<TICK_VALUE,tick_type>;

 public:
  TestFW__PerfTimers();

 ~TestFW__PerfTimers();

  //----------------------------------------------------------------------
  void Start();

  void Stop();

  template<class TTracer>
  void StopAndPrint(TTracer& tracer);

  //----------------------------------------------------------------------
  duration_type UserTime()const;

  duration_type KernelTime()const;

  duration_type RealTime()const;

  //----------------------------------------------------------------------
  template<class TTracer>
  void Print(TTracer& tracer);

 private:
  using timer_type=std::chrono::steady_clock;

  using time_point_type=std::chrono::time_point<timer_type>;

 private:
  static void Helper__GetTimes
               (time_point_type* pRealTime,
                time_point_type* pKernelTime,
                time_point_type* pUserTime);

  static void Helper__SafeAdd
                (duration_type* pSum,
                 duration_type  value);

 private:
  time_point_type m_Start_RealTime;
  time_point_type m_Start_KernelTime;
  time_point_type m_Start_UserTime;

 private:
  duration_type m_Sum_RealTime;
  duration_type m_Sum_KernelTime;
  duration_type m_Sum_UserTime;
};//class TestFW__PerfTimers

////////////////////////////////////////////////////////////////////////////////
//class TestFW__PerfTimers

template<class TTracer>
void TestFW__PerfTimers::StopAndPrint(TTracer& tracer)
{
 this->Stop();
 this->Print(tracer);
}//StopAndPrint

//------------------------------------------------------------------------
template<class TTracer>
void TestFW__PerfTimers::Print(TTracer& tracer)
{
 tracer<<L"* REAL   TIME:"<<TestFW__TimeToStrEx(this->RealTime())<<tso_obj::send;
 tracer<<L"* USER   TIME:"<<TestFW__TimeToStrEx(this->UserTime())<<tso_obj::send;
 tracer<<L"* KERNEL TIME:"<<TestFW__TimeToStrEx(this->KernelTime())<<tso_obj::send;
 tracer<<L"* TOTAL  TIME:"<<TestFW__TimeToStrEx(this->UserTime()+this->KernelTime())<<tso_obj::send;
}//Print

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
