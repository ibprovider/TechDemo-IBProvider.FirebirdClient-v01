////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. Проверка класса fb_v25::t_fb_v25_blr_printer
//                                                Kovalenko Dmitry. 21.11.2015.
#ifndef _FB25_Test_010__CheckBlrPrinter_H_
#define _FB25_Test_010__CheckBlrPrinter_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class FB25_Test_010__CheckBlrPrinter

class FB25_Test_010__CheckBlrPrinter
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class FB25_Test_010__CheckBlrPrinter

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
