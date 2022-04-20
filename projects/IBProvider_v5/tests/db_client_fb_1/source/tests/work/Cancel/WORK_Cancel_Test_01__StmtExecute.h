////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 23.10.2015
#ifndef _WORK_Cancel_Test_01__StmtExecute_H_
#define _WORK_Cancel_Test_01__StmtExecute_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Cancel_Test_01__StmtExecute

class WORK_Cancel_Test_01__StmtExecute
{
 private:
  class tag_thread;
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_Cancel_Test_01__StmtExecute

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif