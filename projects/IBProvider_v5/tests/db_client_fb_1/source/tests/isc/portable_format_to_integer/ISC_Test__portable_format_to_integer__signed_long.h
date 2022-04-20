////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests.
//                                              Kovalenko Dmitry. 25.04.2015.
#ifndef _ISC_Test__portable_format_to_integer__signed_long_H_
#define _ISC_Test__portable_format_to_integer__signed_long_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class ISC_Test__portable_format_to_integer__signed_long

class ISC_Test__portable_format_to_integer__signed_long
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class ISC_Test__portable_format_to_integer__signed_long

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
