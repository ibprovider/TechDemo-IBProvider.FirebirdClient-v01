////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 28.09.2016
#ifndef _WORK_StmtFetch_Test_001__nulls_H_
#define _WORK_StmtFetch_Test_001__nulls_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_001__nulls

class WORK_StmtFetch_Test_001__nulls
{
 private:
  class tag_null_it;
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_001__nulls

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
