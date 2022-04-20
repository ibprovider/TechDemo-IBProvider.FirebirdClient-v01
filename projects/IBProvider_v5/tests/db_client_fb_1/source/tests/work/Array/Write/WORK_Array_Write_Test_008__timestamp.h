////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 27.09.2015
#ifndef _WORK_Array_Write_Test_008__timestamp_H_
#define _WORK_Array_Write_Test_008__timestamp_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Array_Write_Test_008__timestamp

class WORK_Array_Write_Test_008__timestamp
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Array_Write_Test_008__timestamp

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
