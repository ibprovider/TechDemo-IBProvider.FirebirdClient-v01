////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__summary_builder_H_
#define _test_fw_set01__summary_builder_H_

#include <structure/test_obj/fw/set01/test_fw_set01__base.h>
#include <structure/test_obj/fw/set01/test_fw_set01__utilities.h>
#include <structure/test_obj/fw/set01/test_fw_set01__tracer_utils.h>
#include <structure/t_str_parameter.h>

#if _WIN32
#include <psapi.h>
#endif

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__SummaryBuilder

class TestFW__SummaryBuilder:public TestFW__SysSmartMemoryObject
{
 private:
  using self_type=TestFW__SummaryBuilder;

  TestFW__SummaryBuilder(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~TestFW__SummaryBuilder();

 public: //typedefs ------------------------------------------------------
  using self_ptr=structure::t_smart_object_ptr<self_type>;

  using str_param_type=structure::t_str_parameter<char>;

  using allocator_type=TestFW__StdMemoryAllocator;

  using tracer_type=TestFW__SysTracer;

  using count_type=std::uint64_t;

 public:
  tracer_type m_Tracer;

  template<class TRootLog>
  TestFW__SummaryBuilder(TRootLog* pRootLog);

  //----------------------------------------------------------------------
  template<class TTestState>
  void process_result
       (const TTestState& test_status);

  template<class TTestState>
  void print_test_with_error
       (const TTestState& test_status,
        str_param_type    ext_info);

  template<class TTestState>
  void print_test_with_warning
       (const TTestState& test_status,
        str_param_type    ext_info);

  void print_summary
        (str_param_type header,
         bool           print_total_from_log);

  void print_total
        (str_param_type header,
         count_type     nError,
         count_type     nWarning);

 public:
  template<class TTracer>
  void print_summary_ex
        (TTracer&       tracer,
         str_param_type header,
         bool           print_total_from_log);

 public:
  template<class TTracer>
  static void print_total_ex
               (TTracer&       tracer,
                str_param_type header,
                count_type     nError,
                count_type     nWarning);

  template<class TTracer>
  static void print_total_ex
               (TTracer&       tracer,
                str_param_type header,
                count_type     nError,
                count_type     nWarning,
                count_type     nFullPass,
                count_type     nTotalTests);

 public:
  template<class TTracer>
  static void print_summary_process_state(TTracer& tracer);

 private:
  using tick_type
   =std::ratio<1,10*1000*1000>;

  using duration_type
   =std::chrono::duration<std::int64_t,tick_type>;

 private:
  count_type m_nLogErrors;
  count_type m_nLogWarnings;

  count_type m_nTest;

  count_type m_nTestWithErrors;
  count_type m_nTestWithWarnings;
  count_type m_nTestSucceeded;

  count_type m_nTestErrors;
  count_type m_nTestWarnings;

  duration_type m_Time_Real;
  duration_type m_Time_User;
  duration_type m_Time_Kernel;

 private:
  static const wchar_t* const sm_line1;

  static const wchar_t* const sm_line2;
};//class TestFW__SummaryBuilder

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/test_obj/fw/set01/test_fw_set01__summary_builder.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
