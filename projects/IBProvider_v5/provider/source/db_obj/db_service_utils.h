////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_service_utils.h
//! \brief   Утилиты для получения сервисов через t_db_service_provider
//! \author  Kovalenko Dmitry
//! \date    27.07.2006
#ifndef _db_service_utils_H_
#define _db_service_utils_H_

#include "source/db_obj/db_service_provider.h"
#include "source/db_obj/db_operation_context.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//Запрос сервиса через интерфейс t_db_service_provider

t_db_object_ptr
 query_db_service(t_db_object* service_provider_obj,
                  REFGUID      rguidService,
                  const char*  ServiceName=NULL);//throw

//------------------------------------------------------------------------
template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_object*          service_provider_obj,
                  const t_db_svc_descr& svcDescr);//throw

//------------------------------------------------------------------------
template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_object* service_provider_obj);//throw

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service(t_db_object*                      service_provider_obj,
                      structure::t_smart_object_ptr<T>* service); //throw

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service(t_db_service_provider*            service_provider_obj,
                      structure::t_smart_object_ptr<T>* service); //throw

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__no_throw(t_db_object* service_provider_obj);

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service__no_throw(t_db_object*                      service_provider_obj,
                                structure::t_smart_object_ptr<T>* service);

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service__no_throw(t_db_service_provider*            service_provider_obj,
                                structure::t_smart_object_ptr<T>* service);

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__if_it_exists(t_db_operation_context& op_ctx,
                                REFGUID                 rguidService);

//------------------------------------------------------------------------
template<class T>
void query_db_service__if_it_exists(t_db_operation_context&           op_ctx,
                                    REFGUID                           rguidService,
                                    structure::t_smart_object_ptr<T>* service);

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__if_it_exists(t_db_operation_context& op_ctx);

//------------------------------------------------------------------------
template<class T>
void query_db_service__if_it_exists(t_db_operation_context&           op_ctx,
                                    structure::t_smart_object_ptr<T>* service);

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__if_it_exists(t_db_object* service_provider_obj);

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service__if_it_exists(t_db_object*                      service_provider_obj,
                                    structure::t_smart_object_ptr<T>* service);

////////////////////////////////////////////////////////////////////////////////
//Получение сервиса через t_db_operation_context

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_operation_context& op_ctx);//throw

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service(t_db_operation_context&           op_ctx,
                      structure::t_smart_object_ptr<T>* service);//throw

//------------------------------------------------------------------------
template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_operation_context& op_ctx,
                  const t_db_svc_descr&   svc_descr);//throw

//------------------------------------------------------------------------
#ifndef NDEBUG

template<class T>
bool debug__has_db_service(t_db_operation_context& op_ctx);

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_obj/db_service_utils.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
