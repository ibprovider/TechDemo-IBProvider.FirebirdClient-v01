////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_service_provider.h
//! \brief   Интерфейс для создания дочерних объектов и дополнительных сервисов.
//! \author  Kovalenko Dmitry
//! \date    26.07.2006
#ifndef _db_service_provider_H_
#define _db_service_provider_H_

#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_db_service_provider

//! \ingroup db_obj
/// <summary>
///  Интерфейс для получения сервисных объектов компоненты
/// </summary>
///  Используется для расширения объектов connection, transaction.
class COMP_CONF_DECLSPEC_NOVTABLE t_db_service_provider:public t_db_smart_interface
{
 public:

  //interface ------------------------------------------------------------

  /// <summary>
  /// Запрос сервисного объекта
  /// </summary>
  //! \param[in] rguidService
  //!   Идентификатор сервиса
  //! \return
  //!   Возвращает указатель на сервисный объект. Если запрашиваемый
  //!   сервис не поддерживается, то возвращается NULL
  virtual t_db_object_ptr query_service(REFGUID rguidService)=0; //throw
};//class t_db_service_provider

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
