////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 17.01.2020
#ifndef _TestsFor__P13_Compression_01__zlib1_dll_H_
#define _TestsFor__P13_Compression_01__zlib1_dll_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P13_Compression_01__zlib1_dll

class TestsFor__P13_Compression_01__zlib1_dll
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class TestsFor__P13_Compression_01__zlib1_dll

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
