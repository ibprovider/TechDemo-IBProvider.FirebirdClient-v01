////////////////////////////////////////////////////////////////////////////////
#ifndef _test_perf_timers_H_
#define _test_perf_timers_H_

#include "source/test_base.h"
#include <structure/test_obj/t_tso_timer.h>
#include <win32lib/win32_time.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_PerfTimers

class TTSO_PerfTimers
{
 private:
  typedef TTSO_PerfTimers               self_type;

  TTSO_PerfTimers(const self_type&);
  self_type& operator = (const self_type&);

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
}//namespace ibp_test
#endif
