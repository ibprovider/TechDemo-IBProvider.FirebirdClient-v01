////////////////////////////////////////////////////////////////////////////////
//IBProvider tests. Test Pusher With Filter
//                                                 Kovalenko Dmitry. 05.03.2009
#ifndef _push_test__filter_H_
#define _push_test__filter_H_

#include "source/test_base.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest__Filter

class TTSO_PushTest__Filter
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_PushTest,TTSO_MemoryAllocator>
{
 private:
  typedef TTSO_PushTest__Filter                        self_type;

  TTSO_PushTest__Filter(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

  class tag_cancel_exc;

  typedef unsigned __int64                             test_count_type;

 public:
  TTSO_PushTest__Filter(const TTSO_GlobalContext* pSD,
                        TSYS_RootLog*             pSysRootLog,
                        TTSO_PushTest*            pWorker);

  virtual ~TTSO_PushTest__Filter();

  //TTSO_PushTest interface ----------------------------------------------
  virtual void PushTest(const TTSO_Test* pTest)COMP_W000004_OVERRIDE_FINAL;

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

class TTSO_PushTest__Filter::tag_cancel_exc:public std::exception
{
 public:
  tag_cancel_exc(){;}

  virtual const char* what()const;
};//class TTSO_PushTest__Filter::tag_cancel_exc

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_tso
#endif
