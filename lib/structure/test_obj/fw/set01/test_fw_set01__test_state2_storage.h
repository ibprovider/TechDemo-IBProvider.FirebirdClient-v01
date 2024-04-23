////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__test_state2_storage_H_
#define _test_fw_set01__test_state2_storage_H_

#include <structure/test_obj/fw/set01/test_fw_set01__test_state2.h>
#include <structure/mt/t_guard.h>
#include <structure/mt/t_lock_guard.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestState2_Storage

class TestFW__TestState2_Storage LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TestFW__TestState2_Storage;

  TestFW__TestState2_Storage(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using count_type
   =std::uint64_t;

  using item_type
   =TestFW__TestState2;

 public:
  TestFW__TestState2_Storage();
 ~TestFW__TestState2_Storage();

  //interface ------------------------------------------------------------
  count_type get_count();

  void append(const item_type& item);

  void restart();

  void fetch(item_type* item);

 private:
  using guard_type
   =structure::t_guard;

  using lock_guard_type
   =structure::t_lock_guard<guard_type>;

 private:
  guard_type m_guard;

  count_type m_count;

  FILE* m_file;
};//class TestFW__TestState2_Storage

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
