////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB. Проверка функционирования класса RemoteFB__INET_Socket
//                                              Kovalenko Dmitry. 12.11.2014
#ifndef _INET_Socket_Test_002__unspec_H_
#define _INET_Socket_Test_002__unspec_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class INET_Socket_Test_002__unspec

class INET_Socket_Test_002__unspec
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class INET_Socket_Test_002__unspec

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif