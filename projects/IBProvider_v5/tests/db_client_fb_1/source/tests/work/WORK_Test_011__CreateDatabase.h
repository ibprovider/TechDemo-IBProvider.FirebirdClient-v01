////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 20.02.2015
#ifndef _WORK_Test_011__CreateDatabase_H_
#define _WORK_Test_011__CreateDatabase_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_011__CreateDatabase

class WORK_Test_011__CreateDatabase
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_011__CreateDatabase

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
