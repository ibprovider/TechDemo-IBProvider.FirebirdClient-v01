////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 21.01.2020
#ifndef _TestsFor__PSET01__002__unk_auth_H_
#define _TestsFor__PSET01__002__unk_auth_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__PSET01__002__unk_auth

class TestsFor__PSET01__002__unk_auth
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef TestsFor__PSET01__002__unk_auth              self_type;

  TestsFor__PSET01__002__unk_auth(const self_type&);
  self_type& operator = (const self_type&);

 private:
  TestsFor__PSET01__002__unk_auth(TTSO_GlobalContext* pParams,
                                   const char*         pTestID,
                                   const wchar_t*      pAuthName);

  virtual ~TestsFor__PSET01__002__unk_auth();

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);

  //Test interface -------------------------------------------------------
  virtual std::string get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  const TTSO_GlobalContext::self_cptr m_spParams;
  const std::string                   m_testID;
  const std::wstring                  m_authName;

 private:
  static const wchar_t* const sm_params__authNames[];
};//class TestsFor__PSET01__002__unk_auth

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
