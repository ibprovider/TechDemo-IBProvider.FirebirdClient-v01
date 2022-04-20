////////////////////////////////////////////////////////////////////////////////
#ifndef _test_state2__storage_H_
#define _test_state2__storage_H_

#include <win32lib/win32_file_lib.h>
#include <structure/t_threads.h>

namespace ibp_test{
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
  typedef TTSO_TestState2_Storage                      self_type;

  typedef TTSO_TestState2_Storage(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef unsigned __int64                             count_type;

  typedef TTSO_TestState2                              item_type;

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

  typedef win32lib::TTemporaryFile64_ST                file_type;

 private:
  mutable guard_type m_guard;

  count_type m_count;

  mutable file_type m_file;
};//class TTSO_TestState2_Storage

////////////////////////////////////////////////////////////////////////////////
}//namspace ibp_test
#endif
