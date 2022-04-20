////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                Kovalenko Dmitry. 14.02.2015.
#ifndef _INET_PortFactory_Test_001__Analyze_v2_H_
#define _INET_PortFactory_Test_001__Analyze_v2_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class INET_PortFactory_Test_001__Analyze_v2

class INET_PortFactory_Test_001__Analyze_v2
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class INET_PortFactory_Test_001__Analyze_v2

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
