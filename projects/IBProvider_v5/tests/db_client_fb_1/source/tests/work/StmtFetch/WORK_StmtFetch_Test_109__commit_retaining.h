////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 08.09.2015
#ifndef _WORK_StmtFetch_Test_109__commit_retaining_H_
#define _WORK_StmtFetch_Test_109__commit_retaining_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_109__commit_retaining

class WORK_StmtFetch_Test_109__commit_retaining
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_109__commit_retaining

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
