////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_operation_context.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/db_obj/isc_base/isc_initialize_utils.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestOperationContext

TestOperationContext::TestOperationContext(const TestCnParams& cnParams)
 :m_is_cancelled(0)
{
 const wchar_t* pCsName__ODS=nullptr;

 if(cnParams.GlobalCtx()->calc_expression("NE__ODS_CS__IS_UNICODE_FSS"))
 {
  pCsName__ODS=L"UNICODE_FSS";
 }
 else
 if(cnParams.GlobalCtx()->calc_expression("NE__ODS_CS__IS_UTF8"))
 {
  pCsName__ODS=L"UTF8";
 }
 else
 {
  throw std::runtime_error("[BUG CHECK] Can't detect ODS charset.");
 }//else

 assert(pCsName__ODS);

 m_spCsMng
  =LCPI_IBP_NMS::isc_base::isc_create_charset_manager_v2
    (cnParams,
     pCsName__ODS);

 assert(m_spCsMng);
}//TestOperationContext

//------------------------------------------------------------------------
TestOperationContext::~TestOperationContext()
{;}

//interface --------------------------------------------------------------
void TestOperationContext::cancel()
{
 const lock_guard_type __lock_cur_op(m_current_operation_guard);

 thread_traits::exchange(&m_is_cancelled,1);

 if(m_current_operation)
  m_current_operation->cancel();
}//cancel

//ctx interface ----------------------------------------------------------
db_obj::t_db_object_ptr TestOperationContext::get_service(REFCLSID svcID)
{
 if(svcID==LCPI_IBP_NMS::db_obj::__db_guid<LCPI_IBP_NMS::db_obj::t_db_charset_manager_v2>())
  return m_spCsMng;

 return nullptr;
}//get_service

//------------------------------------------------------------------------
bool TestOperationContext::is_cancelled()const
{
 return m_is_cancelled!=0;
}//is_cancelled

//------------------------------------------------------------------------
void TestOperationContext::push_operation(db_obj::t_db_operation* const op)
{
 assert(op);

 const lock_guard_type __lock_cur_op(m_current_operation_guard);

 if(m_is_cancelled)
  ibp::IBP_ThrowOperationWasCancelled();

 if(m_current_operation)
  throw std::runtime_error("context operation already registered");

 m_current_operation=structure::not_null_ptr(op);
}//push_operation

//------------------------------------------------------------------------
void TestOperationContext::pop_operation(db_obj::t_db_operation* const op)
{
 assert(op);

 const lock_guard_type __lock_cur_op(m_current_operation_guard);

 if(!m_current_operation)
  throw std::runtime_error("No current context operation!");

 if(m_current_operation!=op)
  throw std::runtime_error("Unexpected context operation!");

 m_current_operation.Release();
}//pop_operation

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
