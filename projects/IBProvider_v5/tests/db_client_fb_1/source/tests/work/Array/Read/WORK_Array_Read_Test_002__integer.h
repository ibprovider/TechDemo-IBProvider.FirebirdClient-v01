////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 06.10.2015
#ifndef _WORK_Array_Read_Test_002__integer_H_
#define _WORK_Array_Read_Test_002__integer_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Array_Read_Test_002__integer

class WORK_Array_Read_Test_002__integer
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Array_Read_Test_002__integer

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
