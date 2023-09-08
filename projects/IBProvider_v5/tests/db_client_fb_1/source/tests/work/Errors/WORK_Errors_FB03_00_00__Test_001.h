////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 18.08.2023
#ifndef _WORK_Errors_FB03_00_00__Test_001_H_
#define _WORK_Errors_FB03_00_00__Test_001_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Errors_FB03_00_00__Test_001

class WORK_Errors_FB03_00_00__Test_001
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Errors_FB03_00_00__Test_001

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
