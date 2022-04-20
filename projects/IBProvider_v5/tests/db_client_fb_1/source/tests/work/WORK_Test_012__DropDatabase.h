////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 20.02.2015
#ifndef _WORK_Test_012__DropDatabase_H_
#define _WORK_Test_012__DropDatabase_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_012__DropDatabase

class WORK_Test_012__DropDatabase
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class WORK_Test_012__DropDatabase

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
