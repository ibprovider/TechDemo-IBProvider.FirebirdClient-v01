////////////////////////////////////////////////////////////////////////////////
#ifndef _db_services_utility_CC_
#define _db_services_utility_CC_

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//?????? ??????? ????? ????????? t_db_service_provider

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_object*          service_provider_obj,
                  const t_db_svc_descr& svcDescr)//throw
{
 assert(service_provider_obj);

 const t_db_object_ptr service_obj(query_db_service(service_provider_obj,
                                                    svcDescr.guid,
                                                    svcDescr.name)); //throw

 assert(service_obj);

 T* const pSvc(dynamic_cast<T*>(service_obj.ptr()));

 if(!pSvc)
 {
  //DONE 5:error - ????????? ?????? ? ??????????????? __db_guid<T>()
  // ?? ???????????? ??????????? ?????????

  t_ibp_error exc(E_FAIL,ibp_mce_dbobj_ie_svc_not_support_req_interface_2);

  exc<<svcDescr.name<<typeid(T).name();

  exc.raise_me();
 }//if !pSvc

 assert(pSvc);

 return structure::not_null_ptr(pSvc);
}//query_db_service

//------------------------------------------------------------------------
template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_object* const service_provider_obj)//throw
{
 assert(service_provider_obj);

 const t_db_object_ptr service_obj(query_db_service(service_provider_obj,
                                                    __db_guid<T>(),
                                                    typeid(T).name()));

 assert(service_obj);

 T* const pSvc(dynamic_cast<T*>(service_obj.ptr()));

 if(!pSvc)
 {
  //DONE 5:error - ????????? ?????? ? ??????????????? __db_guid<T>()
  // ?? ???????????? ??????????? ?????????

  t_ibp_error exc(E_FAIL,ibp_mce_dbobj_ie_svc_not_support_req_interface_2);

  exc<<__db_guid<T>()<<typeid(T).name();

  exc.raise_me();
 }//if !pSvc

 assert(pSvc);

 return structure::not_null_ptr(pSvc);
}//query_db_service

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service(t_db_object*                      const service_provider_obj,
                      structure::t_smart_object_ptr<T>* const service)
{
 assert(service_provider_obj);
 assert(service);

 query_db_service<T>(service_provider_obj).swap(*service);
}//query_db_service

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service(t_db_service_provider*            const service_provider_obj,
                      structure::t_smart_object_ptr<T>* const service)
{
 assert(service_provider_obj);
 assert(service);

 query_db_service<T>(service_provider_obj).swap(*service);
}//query_db_service

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__no_throw(t_db_object* const service_provider_obj)
{
 assert(service_provider_obj);

 t_db_service_provider* const service_provider
  (dynamic_cast<t_db_service_provider*>(service_provider_obj));

 if(!service_provider)
  return nullptr;

 const t_db_object_ptr service_obj
  (service_provider->query_service(__db_guid<T>()));

 return dynamic_cast<T*>(service_obj.ptr());
}//query_db_service__no_throw

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service__no_throw(t_db_object*                      const service_provider_obj,
                                structure::t_smart_object_ptr<T>* const service)
{
 assert(service_provider_obj);
 assert(service);

 query_db_service__no_throw<T>(service_provider_obj).swap(*service);
}//query_db_service__no_throw

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service__no_throw(t_db_service_provider*            const service_provider_obj,
                                structure::t_smart_object_ptr<T>* const service)
{
 assert(service_provider_obj);
 assert(service);

 query_db_service__no_throw<T>(service_provider_obj).swap(*service);
}//query_db_service__no_throw

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__if_it_exists(t_db_operation_context& op_ctx,
                                REFGUID                 rguidService)
{
 const t_db_object_ptr service_obj
  (op_ctx.get_service(rguidService));

 if(!service_obj)
  return nullptr;

 T* const pSvc(dynamic_cast<T*>(service_obj.ptr()));

 if(!pSvc)
 {
  t_ibp_error exc(E_FAIL,ibp_mce_dbobj_ie_svc_not_support_req_interface_2);

  exc<<rguidService<<typeid(T).name();

  exc.raise_me();
 }//if

 assert(pSvc);

 return structure::not_null_ptr(pSvc);
}//query_db_service__if_it_exists

//------------------------------------------------------------------------
template<class T>
void query_db_service__if_it_exists(t_db_operation_context&                 op_ctx,
                                    REFGUID                                 rguidService,
                                    structure::t_smart_object_ptr<T>* const service)
{
 assert(service);

 (*service)=query_db_service__if_it_exists<T>(op_ctx,rguidService);
}//query_db_service__if_it_exists

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__if_it_exists(t_db_operation_context& op_ctx)
{
 return query_db_service__if_it_exists<T>(op_ctx,__db_guid<T>());
}//query_db_service__if_it_exists

//------------------------------------------------------------------------
template<class T>
void query_db_service__if_it_exists(t_db_operation_context&                 op_ctx,
                                    structure::t_smart_object_ptr<T>* const service)
{
 assert(service);

 (*service)=query_db_service__if_it_exists<T>(op_ctx,__db_guid<T>());
}//query_db_service__if_it_exists

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service__if_it_exists(t_db_object* const service_provider_obj)
{
 assert(service_provider_obj);

 t_db_service_provider* const service_provider
  (dynamic_cast<t_db_service_provider*>(service_provider_obj));

 if(!service_provider)
  return nullptr;

 const t_db_object_ptr service_obj
  (service_provider->query_service(__db_guid<T>()));

 if(!service_obj)
  return nullptr;

 T* const pSvc
  (dynamic_cast<T*>(service_obj.ptr()));

 if(!pSvc)
 {
  t_ibp_error exc(E_FAIL,ibp_mce_dbobj_ie_svc_not_support_req_interface_2);

  exc<<__db_guid<T>()<<typeid(T).name();

  exc.raise_me();
 }//if

 assert(pSvc);

 return structure::not_null_ptr(pSvc);
}//query_db_service__if_it_exists

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service__if_it_exists
               (t_db_object*                      const service_provider_obj,
                structure::t_smart_object_ptr<T>* const service)
{
 assert(service_provider_obj);
 assert(service);

 query_db_service__if_it_exists<T>(service_provider_obj).swap(*service);
}//query_db_service__if_it_exists

////////////////////////////////////////////////////////////////////////////////
//????????? ??????? ????? t_db_operation_context

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_operation_context& op_ctx)//throw
{
 typedef T svc_type;

 const t_db_object_ptr
  spSvcObj(op_ctx.get_service(__db_guid<svc_type>()));

 if(!spSvcObj)
 {
  t_ibp_error exc(DB_E_NOTSUPPORTED,ibp_mce_dbobj_ie_svc_not_supported_1);

  exc<<typeid(svc_type).name();

  exc.raise_me();
 }//if

 assert(spSvcObj);

 //-----------------------------------------------------------------------
 svc_type* const
  pSvc(dynamic_cast<svc_type*>(spSvcObj.ptr()));

 if(!pSvc)
 {
  t_ibp_error exc(E_FAIL,ibp_mce_dbobj_ie_svc_not_support_req_interface_2);

  exc<<__db_guid<svc_type>()<<typeid(svc_type).name();

  exc.raise_me();
 }//if

 assert(pSvc);

 return structure::not_null_ptr(pSvc);
}//query_db_service

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
void query_db_service(t_db_operation_context&                 op_ctx,
                      structure::t_smart_object_ptr<T>* const service)//throw
{
 assert(service);

 query_db_service<T>(op_ctx).swap(*service);
}//query_db_service

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 query_db_service(t_db_operation_context& op_ctx,
                  const t_db_svc_descr&   svc_descr)
{
 assert(svc_descr.name!=nullptr);
 assert(structure::string_length(svc_descr.name)>0);

 typedef T svc_type;

 const t_db_object_ptr
  spSvcObj(op_ctx.get_service(svc_descr.guid));

 if(!spSvcObj)
 {
  t_ibp_error exc(DB_E_NOTSUPPORTED,ibp_mce_dbobj_ie_svc_not_supported_1);

  exc<<svc_descr.name;

  exc.raise_me();
 }//if

 assert(spSvcObj);

 //-----------------------------------------------------------------------
 svc_type* const
  pSvc(dynamic_cast<svc_type*>(spSvcObj.ptr()));

 if(!pSvc)
 {
  t_ibp_error exc(E_FAIL,ibp_mce_dbobj_ie_svc_not_support_req_interface_2);

  exc<<svc_descr.name<<typeid(svc_type).name();

  exc.raise_me();
 }//if

 assert(pSvc);

 return structure::not_null_ptr(pSvc);
}//query_db_service

//------------------------------------------------------------------------
#ifndef NDEBUG

template<class T>
bool debug__has_db_service(t_db_operation_context& op_ctx)
{
 const t_db_object_ptr
  spSvcObj(op_ctx.get_service(__db_guid<T>()));

 if(!spSvcObj)
  return false;

 if(!dynamic_cast<T*>(spSvcObj.ptr()))
  return false;

 return true;
}//debug__has_db_service

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
