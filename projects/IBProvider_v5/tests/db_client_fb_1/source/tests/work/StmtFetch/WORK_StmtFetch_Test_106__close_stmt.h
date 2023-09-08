////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 08.09.2015
#ifndef _WORK_StmtFetch_Test_106__close_stmt_H_
#define _WORK_StmtFetch_Test_106__close_stmt_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_106__close_stmt

class WORK_StmtFetch_Test_106__close_stmt
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_106__close_stmt

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
