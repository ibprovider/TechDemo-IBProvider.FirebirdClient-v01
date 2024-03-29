////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__sys_log_H_
#define _test_fw_set01__sys_log_H_

#include <structure/test_obj/fw/set01/test_fw_set01__base.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__SysLog

class TestFW__SysLog LCPI_CPP_CFG__CLASS__FINAL
 :public tso_obj::t_basic_root_log<TestFW__SysMemoryAllocator>
{
 private:
  using self_type=TestFW__SysLog;
  using inherited=tso_obj::t_basic_root_log<TestFW__SysMemoryAllocator>;

  TestFW__SysLog(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~TestFW__SysLog();

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =structure::t_smart_object_ptr<self_type>;

  using thread_traits
   =inherited::thread_traits;

  using count_type
   =inherited::count_type;

 public:
  explicit TestFW__SysLog(unsigned CodePage);

  explicit TestFW__SysLog(tso_obj::t_log_stream* pOutputStream);

  //interface ------------------------------------------------------------
  void add_other_error_count(count_type x);

  void add_other_warning_count(count_type x);

  void inc_pass_count();

  void inc_total_test_count();

  //selectors ------------------------------------------------------------
  count_type get_total_error_count()const;

  count_type get_total_warning_count()const;

  count_type get_pass_count()const;

  count_type get_total_test_count()const;

 public:
  count_type m_other_error_count;
  count_type m_other_warning_count;
  count_type m_pass_count;
  count_type m_total_test_count;
};//class TestFW__SysLog

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
