////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests.
//                                                 Kovalenko Dmitry. 05.09.2015.
#ifndef _TestsFor__RemoteFB__P12__XSQLDA_Utilities___Calc_XSQLDA_MAX_XDR_SIZE_H_
#define _TestsFor__RemoteFB__P12__XSQLDA_Utilities___Calc_XSQLDA_MAX_XDR_SIZE_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P12__XSQLDA_Utilities___Calc_XSQLDA_MAX_XDR_SIZE

class TestsFor__RemoteFB__P12__XSQLDA_Utilities___Calc_XSQLDA_MAX_XDR_SIZE
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__RemoteFB__P12__XSQLDA_Utilities___Calc_XSQLDA_MAX_XDR_SIZE

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
