////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 05.09.2023
#ifndef _WORK_StmtFetch__Types__time_with_tz_001_H_
#define _WORK_StmtFetch__Types__time_with_tz_001_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch__Types__time_with_tz_001

class WORK_StmtFetch__Types__time_with_tz_001
{
 private:
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch__Types__time_with_tz_001

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
