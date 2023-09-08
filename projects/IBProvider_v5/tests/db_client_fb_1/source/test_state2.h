////////////////////////////////////////////////////////////////////////////////
//IBProvider tests. Test state
//                                                 Kovalenko Dmitry. 02.03.2009
#ifndef _test_state2_H_
#define _test_state2_H_

#include <structure/t_const_str_box.h>
#include <algorithm>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//struct TTSO_TestState2 [POD]

struct TTSO_TestState2
{
 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_str_box           str_box_type;

 public:
  size_t     thread_idx;

  long       err_count;
  long       warning_count;

  __int64    real_time;
  __int64    user_time;
  __int64    kernel_time;

 private:
  char       m_test_id[512];

 public: //--------------------------------- interface
  TTSO_TestState2()
  {
   this->reset();
  }

  void reset()
  {
   memset(this,0,sizeof(*this));
  }

  //selectors ------------------------------
  str_box_type get_test_id()const;

  void set_test_id(str_box_type test_id);
};//struct TTSO_TestState2

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
