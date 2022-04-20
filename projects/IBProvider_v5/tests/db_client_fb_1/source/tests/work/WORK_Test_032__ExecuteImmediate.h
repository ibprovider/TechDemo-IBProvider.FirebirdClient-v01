////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 06.11.2015
#ifndef _WORK_Test_032__ExecuteImmediate_H_
#define _WORK_Test_032__ExecuteImmediate_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_032__ExecuteImmediate

class WORK_Test_032__ExecuteImmediate
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_032__ExecuteImmediate

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
