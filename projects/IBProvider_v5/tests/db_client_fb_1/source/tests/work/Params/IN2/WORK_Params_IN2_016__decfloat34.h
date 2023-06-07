////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 05.06.2023
#ifndef _WORK_Params_IN2_016__decfloat34_H_
#define _WORK_Params_IN2_016__decfloat34_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_IN2_016__decfloat34

class WORK_Params_IN2_016__decfloat34
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Params_IN2_016__decfloat34

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
