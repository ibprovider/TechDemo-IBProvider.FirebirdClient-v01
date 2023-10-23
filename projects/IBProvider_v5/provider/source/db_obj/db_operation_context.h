////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_operation_context.h
//! \brief   Интерфейс контекста операции с базой данных
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
///  Интерфейс контекста операции с базой данных.
/// </summary>
//! Класс не предназначен для динамических объектов
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_db_operation_context
{
 public:
  /// <summary>
  ///  Получение сервисного объекта
  /// </summary>
  //! \param[in] rguidService
  //! \return
  //!  NULL, если сервис с таким идентификатором недоступен
  virtual t_db_object_ptr get_service(REFGUID rguidService)=0;

  /// <summary>
  ///  Тестирование флага отмены операции
  /// </summary>
  virtual bool is_cancelled()const=0;

  /// <summary>
  ///  Регистрация текущей операции в стеке. [THROW].
  /// </summary>
  //! \param[in] op
  //!  Not NULL.
  //!
  //! Если возведен флаг отмены операции, то будет сгенерировано
  //! исключение "операция отменена".
  //!
  //! \note
  //!  Скорее всего, стек операций рассчитан только на одну активную операцию.
  virtual void push_operation(t_db_operation* op)=0;

  /// <summary>
  ///  Удаление операции из стека. [THROW].
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
