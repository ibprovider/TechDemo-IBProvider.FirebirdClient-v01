////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 18.02.2015
#ifndef _WORK_Test_007__RollbackRetaining_H_
#define _WORK_Test_007__RollbackRetaining_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_007__RollbackRetaining

class WORK_Test_007__RollbackRetaining
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_007__RollbackRetaining

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
