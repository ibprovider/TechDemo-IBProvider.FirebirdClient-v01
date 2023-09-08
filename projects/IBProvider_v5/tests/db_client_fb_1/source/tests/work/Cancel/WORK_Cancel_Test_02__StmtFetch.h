////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 25.10.2015
#ifndef _WORK_Cancel_Test_02__StmtFetch_H_
#define _WORK_Cancel_Test_02__StmtFetch_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_02__StmtFetch

class WORK_Cancel_Test_02__StmtFetch
{
 private:
  class tag_thread;
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_Cancel_Test_02__StmtFetch

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif