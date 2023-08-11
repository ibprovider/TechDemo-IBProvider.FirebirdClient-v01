////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 19.07.2023
#ifndef _WORK_Params_OUT_017__timestamp_with_tz_H_
#define _WORK_Params_OUT_017__timestamp_with_tz_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_017__timestamp_with_tz

class WORK_Params_OUT_017__timestamp_with_tz
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Params_OUT_017__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
