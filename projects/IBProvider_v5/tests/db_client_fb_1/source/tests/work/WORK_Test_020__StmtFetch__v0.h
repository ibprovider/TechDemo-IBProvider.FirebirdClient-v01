////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 19.04.2023
#ifndef _WORK_Test_020__StmtFetch__v0_H_
#define _WORK_Test_020__StmtFetch__v0_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_020__StmtFetch__v0

class WORK_Test_020__StmtFetch__v0
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_020__StmtFetch__v0

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
