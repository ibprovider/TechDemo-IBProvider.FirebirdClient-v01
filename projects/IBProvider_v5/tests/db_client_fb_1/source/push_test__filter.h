////////////////////////////////////////////////////////////////////////////////
//IBProvider tests. Test Pusher With Filter
//                                                 Kovalenko Dmitry. 05.03.2009
#ifndef _push_test__filter_H_
#define _push_test__filter_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest__Filter

class TTSO_PushTest__Filter LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_PushTest,TTSO_MemoryAllocator>
{
 private:
  using self_type=TTSO_PushTest__Filter;

  TTSO_PushTest__Filter(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using self_ptr
   =lib::structure::t_smart_object_ptr<self_type>;

  class tag_cancel_exc;

 public:
  TTSO_PushTest__Filter(const TTSO_GlobalContext* pSD,
                        TSYS_RootLog*             pSysRootLog,
                        TTSO_PushTest*            pWorker);

  virtual ~TTSO_PushTest__Filter();

  //TTSO_PushTest interface ----------------------------------------------
  virtual void PushTest(const TTSO_Test_base* pTest)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  void test_cancel_signal();

 private:
  const TTSO_GlobalContext::self_cptr m_spSD;
  const TSYS_RootLog::self_ptr        m_spSysRootLog;
  const TTSO_PushTestPtr              m_spWorker;

  const bool m_ignore_rules;

 private:
  std::string m_kb_cmd;
};//class TTSO_PushTest__Filter

////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest__Filter::tag_cancel_exc

class TTSO_PushTest__Filter::tag_cancel_exc LCPI_CPP_CFG__CLASS__FINAL
 :public std::exception
{
 public:
  tag_cancel_exc(){;}

  virtual const char* what()const;
};//class TTSO_PushTest__Filter::tag_cancel_exc

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
