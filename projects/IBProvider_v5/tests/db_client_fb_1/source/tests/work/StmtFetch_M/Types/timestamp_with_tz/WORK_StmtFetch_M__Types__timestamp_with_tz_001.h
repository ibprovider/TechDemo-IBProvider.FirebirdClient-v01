////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 19.07.2023
#ifndef _WORK_StmtFetch_M__Types__timestamp_with_tz_001_H_
#define _WORK_StmtFetch_M__Types__timestamp_with_tz_001_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__Types__timestamp_with_tz_001

class WORK_StmtFetch_M__Types__timestamp_with_tz_001
{
 private:
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_M__Types__timestamp_with_tz_001

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
