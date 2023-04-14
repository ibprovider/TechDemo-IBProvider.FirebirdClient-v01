////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 12.04.2023
#ifndef _WORK_Test_019__StmtExecute__v3_H_
#define _WORK_Test_019__StmtExecute__v3_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_019__StmtExecute__v3

class WORK_Test_019__StmtExecute__v3
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_019__StmtExecute__v3

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
