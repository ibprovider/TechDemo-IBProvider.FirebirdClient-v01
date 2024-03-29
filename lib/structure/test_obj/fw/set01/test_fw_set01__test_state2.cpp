////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__test_state2.h>
#include <structure/t_zero.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestState2

TestFW__TestState2::str_box_type
 TestFW__TestState2::get_test_id()const
{
 const size_t test_id_length=std::find(m_test_id,_END_(m_test_id),0)-m_test_id;

 return str_box_type(m_test_id,test_id_length);
}//get_test_id

//------------------------------------------------------------------------
void TestFW__TestState2::set_test_id(str_box_type const test_id)
{
 const auto
  copy_result
   (structure::copy
     (test_id.begin(),
      test_id.end(),
      m_test_id,
      _END_(m_test_id)));

 assert(copy_result.second>=m_test_id);
 assert(copy_result.second<=_END_(m_test_id));

 std::fill(copy_result.second,_END_(m_test_id),structure::zero);
}//set_test_id

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
