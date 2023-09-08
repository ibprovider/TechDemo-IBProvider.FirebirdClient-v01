////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 20.02.2015
#ifndef _WORK_Test_010__DetachDatabase_H_
#define _WORK_Test_010__DetachDatabase_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_010__DetachDatabase

class WORK_Test_010__DetachDatabase
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_010__DetachDatabase

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
