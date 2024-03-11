////////////////////////////////////////////////////////////////////////////////
#ifndef _test_perf_timers_H_
#define _test_perf_timers_H_

#include "source/test_base.h"
#include <structure/test_obj/t_tso_timer.h>
#include <win32lib/win32_time.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_PerfTimers

class TTSO_PerfTimers LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TTSO_PerfTimers;

  TTSO_PerfTimers(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  TTSO_PerfTimers();

 ~TTSO_PerfTimers();

  //----------------------------------------------------------------------
  void Start();

  void Stop();

  void StopAndPrint(TTSO_Tracer& tracer);

  //----------------------------------------------------------------------
  __int64 UserTime()const;

  __int64 KernelTime()const;

  __int64 RealTime()const;

  //----------------------------------------------------------------------
  void Print(TTSO_Tracer& tracer);

 private:
  structure::tso_obj::t_tso_real_timer      m_RealTimer;
  win32lib::TThreadTime                     m_ThreadTimer;
};//class TTSO_PerfTimers

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
