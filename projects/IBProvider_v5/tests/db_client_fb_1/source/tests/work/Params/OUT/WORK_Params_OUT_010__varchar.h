////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 19.05.2015
#ifndef _WORK_Params_OUT_010__varchar_H_
#define _WORK_Params_OUT_010__varchar_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_010__varchar

class WORK_Params_OUT_010__varchar
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Params_OUT_010__varchar

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
