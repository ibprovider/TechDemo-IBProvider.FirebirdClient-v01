////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. Test Operation Context.
//                                                Kovalenko Dmitry. 23.10.2015.
#ifndef _test_operation_context_H_
#define _test_operation_context_H_

#include "source/db_obj/db_operation_context.h"
#include "source/db_obj/db_operation.h"
#include "source/db_obj/db_charset_manager_v2.h"

#include "source/test_services.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestOperationContext

class TestOperationContext LCPI_CPP_CFG__CLASS__FINAL:public db_obj::t_db_operation_context
{
 private:
  typedef TestOperationContext              self_type;

  TestOperationContext(const self_type&);
  self_type& operator = (const self_type&);

 public:
  explicit TestOperationContext(const TestCnParams& cnParams);

 ~TestOperationContext();

  //own interface --------------------------------------------------------
  void cancel();

  //ctx interface --------------------------------------------------------
  virtual db_obj::t_db_object_ptr get_service(REFCLSID svcID) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool is_cancelled()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void push_operation(db_obj::t_db_operation* op) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void pop_operation(db_obj::t_db_operation* op) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef structure::t_multi_thread_traits               thread_traits;
  typedef thread_traits::guard_type                      guard_type;
  typedef thread_traits::lock_guard_type                 lock_guard_type;

 private:
  thread_traits::int_type m_is_cancelled;

  guard_type m_current_operation_guard;

  db_obj::t_db_operation_ptr m_current_operation;

 private:
  LCPI_IBP_NMS::db_obj::t_db_charset_manager_v2_ptr m_spCsMng;
};//class TestOperationContext

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
