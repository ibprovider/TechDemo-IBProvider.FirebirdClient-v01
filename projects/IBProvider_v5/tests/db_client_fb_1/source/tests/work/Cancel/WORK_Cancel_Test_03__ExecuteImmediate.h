////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 06.11.2015
#ifndef _WORK_Cancel_Test_03__ExecuteImmediate_H_
#define _WORK_Cancel_Test_03__ExecuteImmediate_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_03__ExecuteImmediate

class WORK_Cancel_Test_03__ExecuteImmediate
{
 private:
  class tag_thread;
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_Cancel_Test_03__ExecuteImmediate

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif