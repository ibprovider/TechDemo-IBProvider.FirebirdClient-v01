////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 25.03.2023
#ifndef _WORK_Test_017__GetStatementInfo__bind_H_
#define _WORK_Test_017__GetStatementInfo__bind_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_017__GetStatementInfo__bind

class WORK_Test_017__GetStatementInfo__bind
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_017__GetStatementInfo__bind

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
