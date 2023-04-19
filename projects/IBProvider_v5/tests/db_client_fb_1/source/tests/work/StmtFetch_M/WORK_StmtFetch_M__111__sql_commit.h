////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 17.04.2023
#ifndef _WORK_StmtFetch_M__111__sql_commit_H_
#define _WORK_StmtFetch_M__111__sql_commit_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__111__sql_commit

class WORK_StmtFetch_M__111__sql_commit
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_M__111__sql_commit

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
