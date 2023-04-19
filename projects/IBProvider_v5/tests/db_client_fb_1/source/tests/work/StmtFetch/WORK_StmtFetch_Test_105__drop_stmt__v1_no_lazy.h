////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 08.09.2015
#ifndef _WORK_StmtFetch_Test_105__drop_stmt__v1_no_lazy_H_
#define _WORK_StmtFetch_Test_105__drop_stmt__v1_no_lazy_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_105__drop_stmt__v1_no_lazy

class WORK_StmtFetch_Test_105__drop_stmt__v1_no_lazy
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_105__drop_stmt__v1_no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
