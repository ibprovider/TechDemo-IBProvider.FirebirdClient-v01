////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_operation_reg.h
//! \brief   Вспомогательный класс для регистрации операции
//! \author  Kovalenko Dmitry
//! \date    19.12.2010
#ifndef _db_operation_reg_H_
#define _db_operation_reg_H_

#include "source/db_obj/db_operation.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_db_operation_reg

/// <summary>
///  Класс для осоздания операции и её регистрации в контексте
/// </summary>
class t_db_operation_reg
{
 private:
  typedef t_db_operation_reg                self_type;

  t_db_operation_reg(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  t_db_operation_reg(t_db_operation_context& op_ctx,t_db_operation* op);

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~t_db_operation_reg();

 private:
  ///Ссылка на контекст операции
  t_db_operation_context& m_op_ctx;

  ///Операция
  t_db_operation_ptr const m_op;
};//class t_db_operation_reg

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
