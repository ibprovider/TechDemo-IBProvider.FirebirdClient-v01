////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 30.09.2016
#ifndef _WORK_Params__001__nulls_H_
#define _WORK_Params__001__nulls_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params__001__nulls

class WORK_Params__001__nulls
{
 private:
  class tag_null_it;
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_Params__001__nulls

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
