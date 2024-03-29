////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__run_context_H_
#define _test_fw_set01__run_context_H_

#include <structure/test_obj/fw/set01/test_fw_set01__test_state2.h>
#include <structure/test_obj/fw/set01/test_fw_set01__base.h>
#include <structure/test_obj/t_tso_lib.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__RunContext

class TestFW__RunContext LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic
   <structure::tso_obj::t_simple_log,TestFW__StdMemoryAllocator>
{
 private:
  using self_type=TestFW__RunContext;

  TestFW__RunContext(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~TestFW__RunContext();

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =structure::t_smart_object_ptr<self_type>;

  using log_type      = tso_obj::t_simple_log;
  using log_ptr       = log_type::self_ptr;
  using message_type  = log_type::message_type;

 public:
  TestFW__TestState2 m_test_info;

 public:
  explicit TestFW__RunContext(log_type* pLog);

  //log interface --------------------------------------------------------
  virtual void trace(message_type* msg) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  const log_ptr m_spLog;
};//class TestFW__RunContext

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
