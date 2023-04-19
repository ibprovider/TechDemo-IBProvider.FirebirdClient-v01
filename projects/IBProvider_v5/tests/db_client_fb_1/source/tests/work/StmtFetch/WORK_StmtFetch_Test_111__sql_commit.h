////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 08.09.2015
#ifndef _WORK_StmtFetch_Test_111__sql_commit_H_
#define _WORK_StmtFetch_Test_111__sql_commit_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_111__sql_commit

class WORK_StmtFetch_Test_111__sql_commit
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_111__sql_commit

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
