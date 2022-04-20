////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests.
//                                                Kovalenko Dmitry. 21.05.2015.
#ifndef _TestsFor__RemoteFB__P12__XSQLDA_Utilities___Build_XSQLDA_MSG_DATA_DESCRS_H_
#define _TestsFor__RemoteFB__P12__XSQLDA_Utilities___Build_XSQLDA_MSG_DATA_DESCRS_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P12__XSQLDA_Utilities___Build_XSQLDA_MSG_DATA_DESCRS

class TestsFor__RemoteFB__P12__XSQLDA_Utilities___Build_XSQLDA_MSG_DATA_DESCRS
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__RemoteFB__P12__XSQLDA_Utilities___Build_XSQLDA_MSG_DATA_DESCRS

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
