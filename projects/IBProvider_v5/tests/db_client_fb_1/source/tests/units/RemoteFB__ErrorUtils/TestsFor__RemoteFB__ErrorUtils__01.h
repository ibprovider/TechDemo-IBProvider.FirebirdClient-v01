////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 13.01.2020
#ifndef _TestsFor__RemoteFB__ErrorUtils__01_H_
#define _TestsFor__RemoteFB__ErrorUtils__01_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ErrorUtils__01

class TestsFor__RemoteFB__ErrorUtils__01
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__RemoteFB__ErrorUtils__01

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
