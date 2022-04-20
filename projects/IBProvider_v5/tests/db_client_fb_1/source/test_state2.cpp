////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_state2.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestState2

TTSO_TestState2::str_box_type TTSO_TestState2::get_test_id()const
{
 return str_box_type(m_test_id,
                     std::find(m_test_id,_END_(m_test_id),0)-m_test_id);
}//get_test_id

//------------------------------------------------------------------------
void TTSO_TestState2::set_test_id(str_box_type const test_id)
{
 typedef std::pair<str_box_type::iterator,char*> copy_result_type;

 const copy_result_type
  copy_result(structure::copy(test_id.begin(),
                              test_id.end(),
                              m_test_id,
                              _END_(m_test_id)));

 assert(copy_result.second>=m_test_id);
 assert(copy_result.second<=_END_(m_test_id));

 std::fill(copy_result.second,_END_(m_test_id),0);
}//set_test_id

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
