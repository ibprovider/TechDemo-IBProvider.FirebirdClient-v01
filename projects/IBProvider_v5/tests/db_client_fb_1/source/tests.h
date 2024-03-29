////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 13.11.2014.
#ifndef _tests_H_
#define _tests_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//struct TTestCreatorDescr

struct TTestCreatorDescr LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using TTestCreator
    =void (*)
      (TTSO_PushTest*      pTestPusher,
       TTSO_GlobalContext* pParams);

 public:
  TTestCreator TestCreator;
};//struct TTestCreatorDescr

////////////////////////////////////////////////////////////////////////////////

extern const TTestCreatorDescr g_Tests[];

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
