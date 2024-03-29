////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__test_state2_H_
#define _test_fw_set01__test_state2_H_

#include <structure/t_const_str_box.h>
#include <algorithm>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//struct TestFW__TestState2 [POD]

struct TestFW__TestState2 LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using str_box_type=structure::t_const_str_box;

 public:
  size_t        thread_idx;

  std::uint64_t err_count;
  std::uint64_t warning_count;

  std::int64_t  real_time;
  std::int64_t  user_time;
  std::int64_t  kernel_time;

 private:
  char m_test_id[512];

 public: //--------------------------------- interface
  TestFW__TestState2()
  {
   this->reset();
  }

  void reset()
  {
   memset(this,0,sizeof(*this));
  }//reset

  //selectors ------------------------------
  str_box_type get_test_id()const;

  void set_test_id(str_box_type test_id);
};//struct TestFW__TestState2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
