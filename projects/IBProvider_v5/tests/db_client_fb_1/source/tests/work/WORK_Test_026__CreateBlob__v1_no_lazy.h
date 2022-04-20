////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 18.09.2015
#ifndef _WORK_Test_026__CreateBlob__v1_no_lazy_H_
#define _WORK_Test_026__CreateBlob__v1_no_lazy_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_026__CreateBlob__v1_no_lazy

class WORK_Test_026__CreateBlob__v1_no_lazy
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_026__CreateBlob__v1_no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
