////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 06.09.2023
#ifndef _WORK_Test_034__StmtExecute_M__v4__IN_OUT_H_
#define _WORK_Test_034__StmtExecute_M__v4__IN_OUT_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_034__StmtExecute_M__v4__IN_OUT

class WORK_Test_034__StmtExecute_M__v4__IN_OUT
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_034__StmtExecute_M__v4__IN_OUT

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
