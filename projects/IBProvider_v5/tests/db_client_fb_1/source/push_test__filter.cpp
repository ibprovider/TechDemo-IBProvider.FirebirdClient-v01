////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/push_test__filter.h"
#include <conio.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest__Filter

TTSO_PushTest__Filter::TTSO_PushTest__Filter(const TTSO_GlobalContext* const pSD,
                                             TSYS_RootLog*             const pSysRootLog,
                                             TTSO_PushTest*            const pWorker)
 :m_spSD(lib::structure::not_null_ptr(pSD))
 ,m_spSysRootLog(lib::structure::not_null_ptr(pSysRootLog))
 ,m_spWorker(lib::structure::not_null_ptr(pWorker))
 ,m_ignore_rules(pSD->args().has(c_prog_arg__ignore_rules))
{
 assert(m_spSD);
 assert(m_spSysRootLog);
 assert(m_spWorker);
}//TTSO_PushTest__Filter

//------------------------------------------------------------------------
TTSO_PushTest__Filter::~TTSO_PushTest__Filter()
{
}

//TTSO_PushTest interface ------------------------------------------------
void TTSO_PushTest__Filter::PushTest(const TTSO_Test_base* const pTest)
{
 assert(pTest);
 assert(dynamic_cast<const TTSO_Test*>(pTest));

 this->test_cancel_signal();

 m_spSysRootLog->inc_total_test_count();

 if(!m_spSD->can_exec(pTest->get_id()))
  return;

 if(!m_ignore_rules && !dynamic_cast<const TTSO_Test*>(pTest)->can_exec())
  return;

 return m_spWorker->PushTest(pTest);
}//PushTest

//------------------------------------------------------------------------
void TTSO_PushTest__Filter::test_cancel_signal()
{
 const size_t c_max_cmd_len=6;

 const char* const cm_exit="cancel";

 while(LCPI_GCRT_kbhit()!=0)
 {
  m_kb_cmd+=static_cast<char>(LCPI_GCRT_getch());

  if(m_kb_cmd.rfind(cm_exit)!=m_kb_cmd.npos)
   throw tag_cancel_exc();

  while(m_kb_cmd.size()>c_max_cmd_len)
   m_kb_cmd.erase(m_kb_cmd.begin());
 }//while
}//test_cancel_signal

////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest__Filter::tag_cancel_exc

const char* TTSO_PushTest__Filter::tag_cancel_exc::what()const
{
 return "IBP TSO CANCEL";
}//what

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
