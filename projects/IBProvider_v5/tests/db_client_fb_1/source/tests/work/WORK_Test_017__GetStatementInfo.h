////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 05.05.2015
#ifndef _WORK_Test_017__GetStatementInfo_H_
#define _WORK_Test_017__GetStatementInfo_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_017__GetStatementInfo

class WORK_Test_017__GetStatementInfo
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_017__GetStatementInfo

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
