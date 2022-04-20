////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/db_operation_reg.h"
#include "source/db_obj/db_operation_context.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_db_operation_reg

t_db_operation_reg::t_db_operation_reg(t_db_operation_context& op_ctx,
                                       t_db_operation*   const op)
 :m_op_ctx(op_ctx)
 ,m_op(op)
{
 assert(m_op);

 m_op_ctx.push_operation(op); //throw
}//t_db_operation_reg

//------------------------------------------------------------------------
t_db_operation_reg::~t_db_operation_reg()
{
 assert(m_op);

 try
 {
  m_op_ctx.pop_operation(m_op); //throw?
 }
 catch(...)
 {
  //формально, если мы зарегистрировали операцию, то разрегистрация должна
  //выполняться без проблем
  assert(false);
 }//catch
}//~t_db_operation_reg

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
