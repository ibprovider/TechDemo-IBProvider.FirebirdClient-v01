////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_service_utils.cpp
//! \brief   Утилиты для получения сервисов через t_db_service_provider
//! \author  Kovalenko Dmitry
//! \date    27.07.2006
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/db_service_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//Запрос сервиса через интерфейс t_db_service_provider

t_db_object_ptr query_db_service(t_db_object* const service_provider_obj,
                                 REFGUID            rguidService,
                                 const char*  const ServiceName)
{
 assert(service_provider_obj);

 const t_db_service_provider_ptr
  service_provider
   (dynamic_cast<t_db_service_provider*>(service_provider_obj));

 if(!service_provider)
 {
  //DONE 5: error - объект не поддерживает интерфейс t_db_service_provider
  IBP_ThrowBugCheck_BadObject
   (L"query_db_service",
    L"#001",
    L"service_provider");
 }//if

 t_db_object_ptr /*const*/ 
  service_obj
   (service_provider->query_service
     (rguidService));

 if(!service_obj)
 {
  //DONE 5: error - сервисный объект с идентификатором rguidService не поддерживается.
  // Возможные причины. Не установлено подключение к БД
  // Сервис не поддерживается текущим соединением

  t_ibp_error exc(E_FAIL,ibp_mce_dbobj_ie_svc_not_supported_1);

  if(ServiceName==NULL || (*ServiceName)==0)
  {
   exc<<ole_lib::guid_to_wstring(rguidService);
  }
  else
  {
   exc<<ServiceName;
  }

  exc.raise_me();
 }//if !service_obj

 assert(service_obj);

 return /*move_value*/service_obj;
}//query_db_service

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
