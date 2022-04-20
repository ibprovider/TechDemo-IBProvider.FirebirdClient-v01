////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 08.09.2015
#ifndef _WORK_StmtFetch_Test_04__MARS_Failed_H_
#define _WORK_StmtFetch_Test_04__MARS_Failed_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_04__MARS_Failed

class WORK_StmtFetch_Test_04__MARS_Failed
{
 private:
  struct tag_rs_descr;
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
};//class WORK_StmtFetch_Test_04__MARS_Failed

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
