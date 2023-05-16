////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 13.05.2023
#ifndef _WORK_Params_OUT_014__int128_H_
#define _WORK_Params_OUT_014__int128_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_014__int128

class WORK_Params_OUT_014__int128
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Params_OUT_014__int128

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
