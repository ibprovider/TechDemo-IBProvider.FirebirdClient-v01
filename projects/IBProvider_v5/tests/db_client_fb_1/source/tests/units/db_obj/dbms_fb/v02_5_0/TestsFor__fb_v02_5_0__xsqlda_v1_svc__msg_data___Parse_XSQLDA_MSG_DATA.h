////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests.
//                                                Kovalenko Dmitry. 27.09.2016
#ifndef _TestsFor__fb_v02_5_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA_H_
#define _TestsFor__fb_v02_5_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__fb_v02_5_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA

class TestsFor__fb_v02_5_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__fb_v02_5_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
