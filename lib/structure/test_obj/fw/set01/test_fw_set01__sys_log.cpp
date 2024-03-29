////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__sys_log.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__SysLog

TestFW__SysLog::TestFW__SysLog(unsigned const CodePage)
 :inherited(CodePage)
 ,m_other_error_count   (0)
 ,m_other_warning_count (0)
 ,m_pass_count          (0)
 ,m_total_test_count    (0)
{
}

//------------------------------------------------------------------------
TestFW__SysLog::TestFW__SysLog(tso_obj::t_log_stream* const pOutputStream)
 :inherited(pOutputStream)
 ,m_other_error_count   (0)
 ,m_other_warning_count (0)
 ,m_pass_count          (0)
 ,m_total_test_count    (0)
{
}

//------------------------------------------------------------------------
TestFW__SysLog::~TestFW__SysLog()
{
}

//interface --------------------------------------------------------------
void TestFW__SysLog::add_other_error_count(count_type const x)
{
 structure::mt::interlocked::add(&m_other_error_count,x);
}//add_other_error_count

//------------------------------------------------------------------------
void TestFW__SysLog::add_other_warning_count(count_type const x)
{
 structure::mt::interlocked::add(&m_other_warning_count,x);
}//add_other_warning_count

//------------------------------------------------------------------------
void TestFW__SysLog::inc_pass_count()
{
 structure::mt::interlocked::increment(&m_pass_count);
}//inc_pass_count

//------------------------------------------------------------------------
void TestFW__SysLog::inc_total_test_count()
{
 structure::mt::interlocked::increment(&m_total_test_count);
}//inc_total_test_count

//selectors --------------------------------------------------------------
TestFW__SysLog::count_type
 TestFW__SysLog::get_total_error_count()const
{
 return m_other_error_count+inherited::get_error_count();
}//get_total_error_count

//------------------------------------------------------------------------
TestFW__SysLog::count_type
 TestFW__SysLog::get_total_warning_count()const
{
 return m_other_warning_count+inherited::get_warning_count();
}//get_total_warning_count

//------------------------------------------------------------------------
TestFW__SysLog::count_type
 TestFW__SysLog::get_pass_count()const
{
 return m_pass_count;
}//get_pass_count

//------------------------------------------------------------------------
TestFW__SysLog::count_type
 TestFW__SysLog::get_total_test_count()const
{
 return m_total_test_count;
}//get_total_test_count

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
