////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests.
//                                              Kovalenko Dmitry. 25.04.2015.
#ifndef _TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory_H_
#define _TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory

class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
