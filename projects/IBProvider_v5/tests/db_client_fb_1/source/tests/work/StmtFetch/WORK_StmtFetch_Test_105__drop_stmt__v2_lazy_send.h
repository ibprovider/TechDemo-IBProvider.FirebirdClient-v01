////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 03.11.2015
#ifndef _WORK_StmtFetch_Test_105__drop_stmt__v2_lazy_send_H_
#define _WORK_StmtFetch_Test_105__drop_stmt__v2_lazy_send_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_105__drop_stmt__v2_lazy_send

class WORK_StmtFetch_Test_105__drop_stmt__v2_lazy_send
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_105__drop_stmt__v2_lazy_send

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
