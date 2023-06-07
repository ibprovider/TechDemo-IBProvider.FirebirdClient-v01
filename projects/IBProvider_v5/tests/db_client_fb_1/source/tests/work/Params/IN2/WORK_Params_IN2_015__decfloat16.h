////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 05.06.2023
#ifndef _WORK_Params_IN2_015__decfloat16_H_
#define _WORK_Params_IN2_015__decfloat16_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_IN2_015__decfloat16

class WORK_Params_IN2_015__decfloat16
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Params_IN2_015__decfloat16

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
