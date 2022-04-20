////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 09.09.2015
#ifndef _WORK_Fields__timestamp_001_H_
#define _WORK_Fields__timestamp_001_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Fields__timestamp_001

class WORK_Fields__timestamp_001
{
 private:
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_Fields__timestamp_001

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
