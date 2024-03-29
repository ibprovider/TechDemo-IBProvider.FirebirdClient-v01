////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__perf_timers_H_
#define _test_fw_set01__perf_timers_H_

#include <structure/test_obj/fw/set01/test_fw_set01__utilities.h>
#include <structure/test_obj/t_tso_timer.h>
#include <win32lib/win32_time.h>

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
  TestFW__PerfTimers();

 ~TestFW__PerfTimers();

  //----------------------------------------------------------------------
  void Start();

  void Stop();

  template<class TTracer>
  void StopAndPrint(TTracer& tracer);

  //----------------------------------------------------------------------
  std::int64_t UserTime()const;

  std::int64_t KernelTime()const;

  std::int64_t RealTime()const;

  //----------------------------------------------------------------------
  template<class TTracer>
  void Print(TTracer& tracer);

 private:
  structure::tso_obj::t_tso_real_timer      m_RealTimer;
  win32lib::TThreadTime                     m_ThreadTimer;
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
