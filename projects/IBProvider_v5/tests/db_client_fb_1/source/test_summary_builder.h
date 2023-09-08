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

class TTSO_SummaryBuilder:public TTSO_SmartMemoryObject
{
 private:
  typedef TTSO_SummaryBuilder                             self_type;

  TTSO_SummaryBuilder(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>        self_ptr;

  typedef structure::t_str_parameter<wchar_t>             wstr_param_type;

 public:
  TTSO_Tracer m_Tracer;

  template<class TRootLog>
  TTSO_SummaryBuilder(TRootLog* pRootLog);

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
                   size_t          nError,
                   size_t          nWarning);

 public:
  void print_summary_ex(TTSO_Tracer&    tracer,
                        wstr_param_type header,
                        bool            print_total_from_log);

  template<class TTracer>
  static void print_total_ex(TTracer&        tracer,
                             wstr_param_type header,
                             size_t          nError,
                             size_t          nWarning);

  template<class TTracer>
  static void print_total_ex(TTracer&        tracer,
                             wstr_param_type header,
                             size_t          nError,
                             size_t          nWarning,
                             unsigned long   nFullPass,
                             unsigned long   nTotalTests);

 public:
  static void print_summary_process_state(TSYS_Tracer& tracer);

 private:
  size_t   m_nLogErrors;
  size_t   m_nLogWarnings;

  size_t   m_nTest;

  size_t   m_nTestWithErrors;
  size_t   m_nTestWithWarnings;
  size_t   m_nTestSucceeded;

  size_t   m_nTestErrors;
  size_t   m_nTestWarnings;

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
 :m_Tracer            (pLog,L"summary"),
  m_nLogErrors        (pLog->get_error_count()),
  m_nLogWarnings      (pLog->get_warning_count()),
  m_nTest             (0),
  m_nTestWithErrors   (0),
  m_nTestWithWarnings (0),
  m_nTestSucceeded    (0),
  m_nTestErrors       (0),
  m_nTestWarnings     (0),
  m_Time_Real         (0),
  m_Time_User         (0),
  m_Time_Kernel       (0)
{;}

//------------------------------------------------------------------------
template<class TTracer>
void TTSO_SummaryBuilder::print_total_ex(TTracer&              tracer,
                                         wstr_param_type const header,
                                         size_t          const nError,
                                         size_t          const nWarning)
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
                                         size_t          const nError,
                                         size_t          const nWarning,
                                         unsigned long   const nFullPass,
                                         unsigned long   const nTotalTests)
{
 self_type::print_total_ex(tracer,header,nError,nWarning);

 tracer<<L"FULL PASSES   : "<<nFullPass<<send;
 tracer<<L"TOTAL TESTS   : "<<nTotalTests<<send;
}//print_total_ex

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
