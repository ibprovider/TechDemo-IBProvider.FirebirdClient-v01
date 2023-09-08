////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 19.09.2015
#ifndef _WORK_Blob_Test_01__WriteAndReadBinData__v1_no_lazy_H_
#define _WORK_Blob_Test_01__WriteAndReadBinData__v1_no_lazy_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//forward declarations

class TTSO_TestData_v2;

////////////////////////////////////////////////////////////////////////////////
//class WORK_Blob_Test_01__WriteAndReadBinData__v1_no_lazy

class WORK_Blob_Test_01__WriteAndReadBinData__v1_no_lazy
{
 private:
  class  tag_impl;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);

 private:
  static void helper__create(TTSO_PushTest*            pTestPusher,
                             TTSO_GlobalContext*       pParams,
                             structure::str_formatter& ftestID,
                             const TTSO_TestData_v2&   Data,
                             bool                      forceFlush);

  static void helper__create(TTSO_PushTest*            pTestPusher,
                             TTSO_GlobalContext*       pParams,
                             structure::str_formatter& ftestID,
                             const TTSO_TestData_v2&   Data,
                             bool                      forceFlush,
                             size_t&                   nTest,
                             size_t                    szBegin,
                             size_t                    szEnd);

  static void helper__create_test(TTSO_PushTest*            pTestPusher,
                                  TTSO_GlobalContext*       pParams,
                                  structure::str_formatter& ftestID,
                                  const TTSO_TestData_v2&   Data,
                                  bool                      forceFlush,
                                  size_t&                   nTest,
                                  size_t                    szBlob,
                                  size_t                    szBlock);
};//class WORK_Blob_Test_01__WriteAndReadBinData__v1_no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
