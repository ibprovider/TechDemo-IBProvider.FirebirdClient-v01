////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. Проверка класса fb_v25::t_fb_v25_blr_printer
//                                                Kovalenko Dmitry. 21.11.2015.
#ifndef _FB25_Test_009__BlrPrinter_H_
#define _FB25_Test_009__BlrPrinter_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class FB25_Test_009__BlrPrinter

class FB25_Test_009__BlrPrinter
{
 private:
  class  tag_impl;
  struct tag_descr;

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);
 private:
  static const tag_descr sm_Tests[];
};//class FB25_Test_009__BlrPrinter

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
