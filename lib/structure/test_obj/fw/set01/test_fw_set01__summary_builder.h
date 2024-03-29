////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__summary_builder_H_
#define _test_fw_set01__summary_builder_H_

#include <structure/test_obj/fw/set01/test_fw_set01__base.h>
#include <structure/test_obj/fw/set01/test_fw_set01__utilities.h>
#include <structure/test_obj/fw/set01/test_fw_set01__tracer_utils.h>
#include <structure/t_str_parameter.h>
#include <psapi.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__SummaryBuilder

class TestFW__SummaryBuilder:public TestFW__SysSmartMemoryObject
{
 private:
  typedef TestFW__SummaryBuilder                          self_type;

  TestFW__SummaryBuilder(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TestFW__SummaryBuilder();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>        self_ptr;

  typedef structure::t_str_parameter<wchar_t>             wstr_param_type;

  typedef TestFW__StdMemoryAllocator                      allocator_type;

  typedef TestFW__SysTracer                               tracer_type;

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
        wstr_param_type   ext_info);

  template<class TTestState>
  void print_test_with_warning
       (const TTestState& test_status,
        wstr_param_type   ext_info);

  void print_summary
        (wstr_param_type header,
         bool            print_total_from_log);

  void print_total
        (wstr_param_type header,
         count_type      nError,
         count_type      nWarning);

 public:
  template<class TTracer>
  void print_summary_ex
        (TTracer&        tracer,
         wstr_param_type header,
         bool            print_total_from_log);

 public:
  template<class TTracer>
  static void print_total_ex
               (TTracer&        tracer,
                wstr_param_type header,
                count_type      nError,
                count_type      nWarning);

  template<class TTracer>
  static void print_total_ex
               (TTracer&        tracer,
                wstr_param_type header,
                count_type      nError,
                count_type      nWarning,
                count_type      nFullPass,
                count_type      nTotalTests);

 public:
  template<class TTracer>
  static void print_summary_process_state(TTracer& tracer);

 private:
  count_type m_nLogErrors;
  count_type m_nLogWarnings;

  count_type m_nTest;

  count_type m_nTestWithErrors;
  count_type m_nTestWithWarnings;
  count_type m_nTestSucceeded;

  count_type m_nTestErrors;
  count_type m_nTestWarnings;

  __int64  m_Time_Real;
  __int64  m_Time_User;
  __int64  m_Time_Kernel;

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
