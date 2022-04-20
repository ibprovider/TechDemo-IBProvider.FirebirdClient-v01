////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                Kovalenko Dmitry. 04.05.2016.
#ifndef _INET_PortFactory_Test_003__Analyze_v3__inet4_H_
#define _INET_PortFactory_Test_003__Analyze_v3__inet4_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class INET_PortFactory_Test_003__Analyze_v3__inet4

class INET_PortFactory_Test_003__Analyze_v3__inet4
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class INET_PortFactory_Test_003__Analyze_v3__inet4

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
