////////////////////////////////////////////////////////////////////////////////
#ifndef _test_state2__storage_H_
#define _test_state2__storage_H_

#include <win32lib/win32_file_lib.h>
#include <structure/t_threads.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//containings

class TTSO_TestState2_Storage;

////////////////////////////////////////////////////////////////////////////////
//forward declarations

struct TTSO_TestState2;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestState2_Storage

class TTSO_TestState2_Storage
{
 private:
  using self_type=TTSO_TestState2_Storage;

  TTSO_TestState2_Storage(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using count_type=unsigned __int64;

  using item_type=TTSO_TestState2;

 public:
  TTSO_TestState2_Storage();
 ~TTSO_TestState2_Storage();

  //interface ------------------------------------------------------------
  count_type get_count()const;

  void append(const item_type& item);

  void read(count_type index,item_type* item)const;

 private:
  typedef structure::t_multi_thread_traits             thread_traits;
  typedef thread_traits::guard_type                    guard_type;
  typedef thread_traits::lock_guard_type               lock_guard_type;

  using file_type=win32lib::TTemporaryFile64_ST;

 private:
  mutable guard_type m_guard;

  count_type m_count;

  mutable file_type m_file;
};//class TTSO_TestState2_Storage

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
