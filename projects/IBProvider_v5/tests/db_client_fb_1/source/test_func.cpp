////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_func.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestFunc

TTSO_TestFunc::TTSO_TestFunc(TTSO_GlobalContext* const pParams,
                             const char*         const pTestID,
                             TTestFunc           const Func,
                             const char*         const pExecRules)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Func(structure::not_null_ptr(Func))
 ,m_ExecRules(pExecRules?pExecRules:"")
{
 assert(m_spParams);
 assert(!m_TestID.empty());
 assert(m_Func);
}//TTSO_TestFunc

//------------------------------------------------------------------------
TTSO_TestFunc::~TTSO_TestFunc()
{;}

//test interface ---------------------------------------------------------
std::string TTSO_TestFunc::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool TTSO_TestFunc::can_exec()const
{
 assert(m_spParams);

 return m_spParams->calc_expression(m_ExecRules);
}//can_exec

//------------------------------------------------------------------------
void TTSO_TestFunc::run(context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);
 assert(m_Func);

 return m_Func(m_spParams,pCtx);
}//run

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
