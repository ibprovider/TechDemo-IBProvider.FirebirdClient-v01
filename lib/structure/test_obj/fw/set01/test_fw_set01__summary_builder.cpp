////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
//#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__summary_builder.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__SummaryBuilder - static data

const wchar_t* const TestFW__SummaryBuilder::sm_line1
 =L"-------------------------------------------";

//------------------------------------------------------------------------
const wchar_t* const TestFW__SummaryBuilder::sm_line2
 =L"- - - - - - - - - - - - - - - - - - - - - -";

////////////////////////////////////////////////////////////////////////////////
//class TestFW__SummaryBuilder

TestFW__SummaryBuilder::~TestFW__SummaryBuilder()
{;}

//------------------------------------------------------------------------
void TestFW__SummaryBuilder::print_summary
                                      (str_param_type header,
                                       bool  const    print_total_from_log)
{
 this->print_summary_ex
  (m_Tracer,
   header,
   print_total_from_log);
}//print_summary

//------------------------------------------------------------------------
void TestFW__SummaryBuilder::print_total
                                      (str_param_type const header,
                                       count_type     const nError,
                                       count_type     const nWarning)
{
 self_type::print_total_ex
  (m_Tracer,
   header,
   nError,
   nWarning);
}//print_total

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
