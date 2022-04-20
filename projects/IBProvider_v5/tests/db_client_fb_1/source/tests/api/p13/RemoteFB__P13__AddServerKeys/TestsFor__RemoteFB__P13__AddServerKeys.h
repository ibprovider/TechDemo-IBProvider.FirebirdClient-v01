////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 03.09.2016
#ifndef _TestsFor__RemoteFB__P13__AddServerKeys_H_
#define _TestsFor__RemoteFB__P13__AddServerKeys_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__AddServerKeys

class TestsFor__RemoteFB__P13__AddServerKeys
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__RemoteFB__P13__AddServerKeys

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
