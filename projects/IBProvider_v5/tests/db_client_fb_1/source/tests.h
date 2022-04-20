////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 13.11.2014.
#ifndef _tests_H_
#define _tests_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//struct TTestCreatorDescr

struct TTestCreatorDescr
{
 public:
  typedef void (*TTestCreator)(TTSO_PushTest*      pTestPusher,
                               TTSO_GlobalContext* pParams);
 public:
  TTestCreator TestCreator;
};//struct TTestCreatorDescr

////////////////////////////////////////////////////////////////////////////////

extern const TTestCreatorDescr g_Tests[];

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
