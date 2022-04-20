////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 08.09.2015
#ifndef _WORK_StmtFetch_Test_07__commit_H_
#define _WORK_StmtFetch_Test_07__commit_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_07__commit

class WORK_StmtFetch_Test_07__commit
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_07__commit

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
