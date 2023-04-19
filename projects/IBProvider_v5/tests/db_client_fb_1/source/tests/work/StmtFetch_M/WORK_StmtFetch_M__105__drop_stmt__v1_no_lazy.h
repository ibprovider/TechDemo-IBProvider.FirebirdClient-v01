////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 17.04.2023
#ifndef _WORK_StmtFetch_M__105__drop_stmt__v1_no_lazy_H_
#define _WORK_StmtFetch_M__105__drop_stmt__v1_no_lazy_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__105__drop_stmt__v1_no_lazy

class WORK_StmtFetch_M__105__drop_stmt__v1_no_lazy
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_M__105__drop_stmt__v1_no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
