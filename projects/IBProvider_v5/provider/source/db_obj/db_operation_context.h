////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_operation_context.h
//! \brief   ��������� ��������� �������� � ����� ������
//! \author  Kovalenko Dmitry
//! \date    29.10.2007
#ifndef _db_operation_context_H_
#define _db_operation_context_H_

#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_db_operation_context

/// <summary>
///  ��������� ��������� �������� � ����� ������.
/// </summary>
//! ����� �� ������������ ��� ������������ ��������
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_db_operation_context
{
 public:
  /// <summary>
  ///  ��������� ���������� �������
  /// </summary>
  //! \param[in] rguidService
  //! \return
  //!  NULL, ���� ������ � ����� ��������������� ����������
  virtual t_db_object_ptr get_service(REFGUID rguidService)=0;

  /// <summary>
  ///  ������������ ����� ������ ��������
  /// </summary>
  virtual bool is_cancelled()const=0;

  /// <summary>
  ///  ����������� ������� �������� � �����. [THROW].
  /// </summary>
  //! \param[in] op
  //!  Not NULL.
  //!
  //! ���� �������� ���� ������ ��������, �� ����� �������������
  //! ���������� "�������� ��������".
  //!
  //! \note
  //!  ������ �����, ���� �������� ��������� ������ �� ���� �������� ��������.
  virtual void push_operation(t_db_operation* op)=0;

  /// <summary>
  ///  �������� �������� �� �����. [THROW].
  /// </summary>
  //! \param[in] op
  //!  Not NULL.
  virtual void pop_operation(t_db_operation* op)=0;
};//class t_db_operation_context

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
