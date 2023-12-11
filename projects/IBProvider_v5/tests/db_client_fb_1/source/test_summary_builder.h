////////////////////////////////////////////////////////////////////////////////
//IBProvider tests. Summary builder
//                                                  Kovalenko Dmitry. 04.03.2009
#ifndef _test_summary_builder_H_
#define _test_summary_builder_H_

#include "source/test_base.h"
#include "source/test_state2.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_SummaryBuilder

class TTSO_SummaryBuilder LCPI_CPP_CFG__CLASS__FINAL
 :public TTSO_SmartMemoryObject
{
 private:
  using self_type=TTSO_SummaryBuilder;

  TTSO_SummaryBuilder(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using wstr_param_type=structure::t_str_parameter<wchar_t>;

  using count_type=unsigned __int64;

 public:
  TTSO_Tracer m_Tracer;

  template<class TRootLog>
  explicit TTSO_SummaryBuilder(TRootLog* pRootLog);

  virtual ~TTSO_SummaryBuilder();

  //----------------------------------------------------------------------
  void process_result(const TTSO_TestState2& test_status);

  void print_test_with_error(const TTSO_TestState2& test_status,
                             wstr_param_type        ext_info);

  void print_test_with_warning(const TTSO_TestState2& test_status,
                               wstr_param_type        ext_info);

  void print_summary(wstr_param_type header,
                     bool            print_total_from_log);

  void print_total(wstr_param_type header,
                   count_type      nError,
                   count_type      nWarning);

 public:
  void print_summary_ex(TTSO_Tracer&    tracer,
                        wstr_param_type header,
                        bool            print_total_from_log);

  template<class TTracer>
  static void print_total_ex(TTracer&        tracer,
                             wstr_param_type header,
                             count_type      nError,
                             count_type      nWarning);

  template<class TTracer>
  static void print_total_ex(TTracer&        tracer,
                             wstr_param_type header,
                             count_type      nError,
                             count_type      nWarning,
                             count_type      nFullPass,
                             count_type      nTotalTests);

 public:
  static void print_summary_process_state(TSYS_Tracer& tracer);

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
};//class TTSO_SummaryBuilder

////////////////////////////////////////////////////////////////////////////////
//class TTSO_SummaryBuilder

template<class TRootLog>
TTSO_SummaryBuilder::TTSO_SummaryBuilder(TRootLog* const pLog)
 :m_Tracer            (pLog,L"summary")
 ,m_nLogErrors        (pLog->get_error_count())
 ,m_nLogWarnings      (pLog->get_warning_count())
 ,m_nTest             (0)
 ,m_nTestWithErrors   (0)
 ,m_nTestWithWarnings (0)
 ,m_nTestSucceeded    (0)
 ,m_nTestErrors       (0)
 ,m_nTestWarnings     (0)
 ,m_Time_Real         (0)
 ,m_Time_User         (0)
 ,m_Time_Kernel       (0)
{
}

//------------------------------------------------------------------------
template<class TTracer>
void TTSO_SummaryBuilder::print_total_ex(TTracer&              tracer,
                                         wstr_param_type const header,
                                         count_type      const nError,
                                         count_type      const nWarning)
{
 if(header.empty())
 {
  tracer<<sm_line2<<send;
 }
 else
 {
  tracer<<sm_line1<<L" ["<<header.str()<<L"]"<<send;
 }

 tracer<<L"TOTAL ERRORS  : "<<nError<<send;
 tracer<<L"TOTAL WARNINGS: "<<nWarning<<send;
}//print_total_ex

//------------------------------------------------------------------------
template<class TTracer>
void TTSO_SummaryBuilder::print_total_ex(TTracer&              tracer,
                                         wstr_param_type const header,
                                         count_type      const nError,
                                         count_type      const nWarning,
                                         count_type      const nFullPass,
                                         count_type      const nTotalTests)
{
 self_type::print_total_ex(tracer,header,nError,nWarning);

 tracer<<L"FULL PASSES   : "<<nFullPass<<send;
 tracer<<L"TOTAL TESTS   : "<<nTotalTests<<send;
}//print_total_ex

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
