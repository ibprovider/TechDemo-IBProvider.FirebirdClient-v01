////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                Kovalenko Dmitry. 09.10.2015.
#ifndef _test_func_v2_H_
#define _test_func_v2_H_

#include "source/test_cn_params.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//ѕеречисление допустимых типов протокола, используемых при тестировании.

extern const ibp::t_ibp_char* const g_TestCfg__RemoteFB__ProtocolTypes[4];

extern const ibp::t_ibp_char* const g_TestCfg__RemoteFB__ProtocolTypes__no_lazy[3];

extern const ibp::t_ibp_char* const g_TestCfg__RemoteFB__ProtocolTypes__lazy_send[1];

const ibp::t_ibp_string& TSO_RemoteFB_GetProtocolTypeSign(const ibp::t_ibp_string& ptype);

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestData_v2

/// <summary>
///  —труктура с параметрами конфигурации подключени€ (протокола).
/// </summary>
class TTSO_TestData_v2
{
 public: //typedefs ------------------------------------------------------

 public:
  structure::t_value_with_null<ibp::t_ibp_string> m_RemoteFB__ProtocolType;

 public:
  TTSO_TestData_v2();

  bool can_exec(const TTSO_GlobalContext* pParams)const;

  void SetParams(TestCnParams& params)const;
};//class TTSO_TestData_v2

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestFunc_v2

class TTSO_TestFunc_v2
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef TTSO_TestFunc_v2                     self_type;

  TTSO_TestFunc_v2(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TTSO_TestFunc_v2();

 public: //typedefs ------------------------------------------------------
  typedef void (*TTestFunc)(TTSO_GlobalContext*     pParams,
                            context_type*           pCtx,
                            const TTSO_TestData_v2& Data);

 public:
  TTSO_TestFunc_v2(TTSO_GlobalContext*     pParams,
                   const char*             pTestID,
                   TTestFunc               Func,
                   const TTSO_TestData_v2& Data,
                   const char*             pExecRules=nullptr);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTestFunc const m_Func;

  TTSO_TestData_v2 const m_Data;

  std::string const m_ExecRules;
};//class TTSO_TestFunc_v2

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
