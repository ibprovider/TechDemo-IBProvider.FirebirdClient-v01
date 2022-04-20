////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB. Проверка функционирования класса RemoteFB__INET_Port
//                                                 Kovalenko Dmitry. 21.11.2014
#ifndef _INET_Test_002__RemotePort_H_
#define _INET_Test_002__RemotePort_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class INET_Test_002__RemotePort

class INET_Test_002__RemotePort
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class INET_Test_002__RemotePort

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
