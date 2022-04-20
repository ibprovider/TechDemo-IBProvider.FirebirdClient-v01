////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 23.10.2016
#ifndef _TestsFor__P10__001_Mix_H_
#define _TestsFor__P10__001_Mix_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P10__001_Mix

class TestsFor__P10__001_Mix
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__P10__001_Mix

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
