////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                Kovalenko Dmitry. 04.05.2016.
#ifndef _INET_PortFactory_Test_004__Analyze_v3__inet6_H_
#define _INET_PortFactory_Test_004__Analyze_v3__inet6_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class INET_PortFactory_Test_004__Analyze_v3__inet6

class INET_PortFactory_Test_004__Analyze_v3__inet6
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class INET_PortFactory_Test_004__Analyze_v3__inet6

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
