////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 30.09.2016
#ifndef _WORK_StmtFetch_Test_002__nulls_H_
#define _WORK_StmtFetch_Test_002__nulls_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_002__nulls

class WORK_StmtFetch_Test_002__nulls
{
 private:
  class tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_002__nulls

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
