////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 15.04.2023
#ifndef _WORK_Test_036__StmtFetch_M__v2_lazy_send_H_
#define _WORK_Test_036__StmtFetch_M__v2_lazy_send_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_036__StmtFetch_M__v2_lazy_send

class WORK_Test_036__StmtFetch_M__v2_lazy_send
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_036__StmtFetch_M__v2_lazy_send

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
