////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 17.02.2015
#ifndef _WORK_Test_004__StartTransaction__v1_H_
#define _WORK_Test_004__StartTransaction__v1_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_004__StartTransaction__v1

class WORK_Test_004__StartTransaction__v1
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_004__StartTransaction__v1

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
