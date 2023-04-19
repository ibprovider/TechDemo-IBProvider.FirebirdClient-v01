////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 17.04.2023
#ifndef _WORK_StmtFetch_M__103__MARS_H_
#define _WORK_StmtFetch_M__103__MARS_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__103__MARS

class WORK_StmtFetch_M__103__MARS
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_M__103__MARS

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
