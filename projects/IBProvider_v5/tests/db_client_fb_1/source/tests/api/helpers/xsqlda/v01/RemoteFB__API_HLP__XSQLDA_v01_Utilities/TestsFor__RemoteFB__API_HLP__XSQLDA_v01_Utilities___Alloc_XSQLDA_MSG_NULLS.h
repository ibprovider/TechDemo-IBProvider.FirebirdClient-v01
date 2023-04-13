////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests.
//                                                Kovalenko Dmitry. 27.09.2016
#ifndef _TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Alloc_XSQLDA_MSG_NULLS_H_
#define _TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Alloc_XSQLDA_MSG_NULLS_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Alloc_XSQLDA_MSG_NULLS

class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Alloc_XSQLDA_MSG_NULLS
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Alloc_XSQLDA_MSG_NULLS

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
