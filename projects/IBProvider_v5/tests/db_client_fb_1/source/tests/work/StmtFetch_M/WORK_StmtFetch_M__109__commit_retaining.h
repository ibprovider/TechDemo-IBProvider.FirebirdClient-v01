////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 17.04.2023
#ifndef _WORK_StmtFetch_M__109__commit_retaining_H_
#define _WORK_StmtFetch_M__109__commit_retaining_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__109__commit_retaining

class WORK_StmtFetch_M__109__commit_retaining
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_M__109__commit_retaining

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
