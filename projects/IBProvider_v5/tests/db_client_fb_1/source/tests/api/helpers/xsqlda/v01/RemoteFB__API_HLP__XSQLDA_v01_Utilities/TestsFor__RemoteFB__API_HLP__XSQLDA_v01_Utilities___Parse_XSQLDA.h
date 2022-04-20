////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests.
//                                                Kovalenko Dmitry. 01.05.2015.
#ifndef _TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA_H_
#define _TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA

class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
