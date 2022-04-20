////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 18.05.2015
#ifndef _WORK_Params_OUT_006__type_time_H_
#define _WORK_Params_OUT_006__type_time_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_006__type_time

class WORK_Params_OUT_006__type_time
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Params_OUT_006__type_time

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
