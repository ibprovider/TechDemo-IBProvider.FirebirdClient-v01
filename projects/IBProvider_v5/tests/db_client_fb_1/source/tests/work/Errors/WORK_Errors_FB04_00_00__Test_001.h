////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 17.08.2023
#ifndef _WORK_Errors_FB04_00_00__Test_001_H_
#define _WORK_Errors_FB04_00_00__Test_001_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Errors_FB04_00_00__Test_001

class WORK_Errors_FB04_00_00__Test_001
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Errors_FB04_00_00__Test_001

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
