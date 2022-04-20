////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 05.10.2015
#ifndef _WORK_Test_031__GetArraySlice_H_
#define _WORK_Test_031__GetArraySlice_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_031__GetArraySlice

class WORK_Test_031__GetArraySlice
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_031__GetArraySlice

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
