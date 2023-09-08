////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                Kovalenko Dmitry. 14.02.2015.
#ifndef _INET_PortFactory_Test_002__Analyze_v3_H_
#define _INET_PortFactory_Test_002__Analyze_v3_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class INET_PortFactory_Test_002__Analyze_v3

class INET_PortFactory_Test_002__Analyze_v3
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class INET_PortFactory_Test_002__Analyze_v3

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
