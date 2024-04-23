////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__test_state2_H_
#define _test_fw_set01__test_state2_H_

#include <structure/t_const_str_box.h>
#include <chrono>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//struct TestFW__TestState2 [POD]

struct TestFW__TestState2 LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using str_box_type=structure::t_const_str_box;

 public:
  using tick_type=std::ratio<1,10*1000*1000>; //10 microseconds

  using duration_type=std::chrono::duration<std::int64_t,tick_type>;
 
 public:
  size_t        thread_idx;

  std::uint64_t err_count;
  std::uint64_t warning_count;

  duration_type real_time;
  duration_type user_time;
  duration_type kernel_time;

 private:
  char m_test_id[512];

 public: //--------------------------------- interface
  TestFW__TestState2()
  {
   LCPI__assert_s(std::is_trivial<duration_type>::value);

   this->reset();
  }

  void reset()
  {
   this->thread_idx    = 0;
   this->err_count     = 0;
   this->warning_count = 0;
   this->real_time     = duration_type();
   this->user_time     = duration_type();
   this->kernel_time   = duration_type();

   m_test_id[0] = 0;
  }//reset

  //selectors ------------------------------
  str_box_type get_test_id()const;

  void set_test_id(str_box_type test_id);
};//struct TestFW__TestState2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
