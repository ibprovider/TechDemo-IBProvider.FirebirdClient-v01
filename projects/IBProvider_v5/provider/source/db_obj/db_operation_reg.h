////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_operation_reg.h
//! \brief   ��������������� ����� ��� ����������� ��������
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
///  ����� ��� ��������� �������� � � ����������� � ���������
/// </summary>
class t_db_operation_reg
{
 private:
  typedef t_db_operation_reg                self_type;

  t_db_operation_reg(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  t_db_operation_reg(t_db_operation_context& op_ctx,t_db_operation* op);

  /// <summary>
  ///  ����������
  /// </summary>
 ~t_db_operation_reg();

 private:
  ///������ �� �������� ��������
  t_db_operation_context& m_op_ctx;

  ///��������
  t_db_operation_ptr const m_op;
};//class t_db_operation_reg

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
