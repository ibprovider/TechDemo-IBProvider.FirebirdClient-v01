////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 14.10.2016
#ifndef _WORK_Params_IN2_009__char_H_
#define _WORK_Params_IN2_009__char_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_IN2_009__char

class WORK_Params_IN2_009__char
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Params_IN2_009__char

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
