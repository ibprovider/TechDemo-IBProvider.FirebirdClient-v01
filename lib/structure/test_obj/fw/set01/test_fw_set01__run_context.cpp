////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
//#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__run_context.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__RunContext

TestFW__RunContext::TestFW__RunContext(log_type* const pLog)
 :m_spLog(structure::not_null_ptr(pLog))
{
 assert(m_spLog);
}//TestFW__RunContext

//------------------------------------------------------------------------
TestFW__RunContext::~TestFW__RunContext()
{
}

//log interface ----------------------------------------------------------
void TestFW__RunContext::trace(message_type* const message)
{
 assert(message);

 switch(message->get_msg_kind())
 {
  case tso_obj::tso_msg_error:
  {
   structure::interlocked::increment(&m_test_info.err_count);
   break;
  }//case - error

  case tso_obj::tso_msg_warning:
  {
   structure::interlocked::increment(&m_test_info.warning_count);
   break;
  }//case - warning

  default:
  {
   break;
  }//default
 }//switch

 assert(m_spLog);

 return m_spLog->trace(message);
}//trace

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
