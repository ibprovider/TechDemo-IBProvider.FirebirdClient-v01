////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                Kovalenko Dmitry. 04.02.2015.
#ifndef _test_func_H_
#define _test_func_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestFunc

class TTSO_TestFunc
 :public lib::structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  using self_type=TTSO_TestFunc;

  TTSO_TestFunc(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~TTSO_TestFunc();

 public: //typedefs ------------------------------------------------------
  using TTestFunc
    =void (*)
       (TTSO_GlobalContext* pParams,
        context_type*       pCtx);

 public:
  TTSO_TestFunc(TTSO_GlobalContext* pParams,
                const char*         pTestID,
                TTestFunc           Func,
                const char*         pExecRules=nullptr);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTestFunc const m_Func;

  std::string const m_ExecRules;
};//class TTSO_TestFunc

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
