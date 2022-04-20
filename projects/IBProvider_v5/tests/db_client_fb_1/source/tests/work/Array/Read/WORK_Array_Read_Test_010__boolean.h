////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 10.10.2016
#ifndef _WORK_Array_Read_Test_010__boolean_H_
#define _WORK_Array_Read_Test_010__boolean_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Array_Read_Test_010__boolean

class WORK_Array_Read_Test_010__boolean
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Array_Read_Test_010__boolean

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
