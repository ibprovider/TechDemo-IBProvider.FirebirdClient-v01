////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_call_context.cpp
//! \brief   Контекст вызова
//! \author  Kovalenko Dmitry
//! \date    04.04.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_call_context.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_CallContext:tag_error_adapter

IBP_CallContext::tag_error_adapter::tag_error_adapter(const self_type& x)
 :m_pCallContext(x.m_pCallContext)
{
 assert(m_pCallContext);
}//tag_error_adapter

//------------------------------------------------------------------------
IBP_CallContext::tag_error_adapter::tag_error_adapter(IBP_CallContext* const pCallContext)
 :m_pCallContext(pCallContext)
{
 assert(m_pCallContext);
}//tag_error_adapter

//------------------------------------------------------------------------
IBP_CallContext::tag_error_adapter::~tag_error_adapter()
{
 assert(m_pCallContext);

 m_pCallContext=nullptr;
}//~tag_error_adapter

//------------------------------------------------------------------------
void IBP_CallContext::tag_error_adapter::add_summary_error
                                           (mc_type     const mc_id_2,
                                            uint64_type const cErrors,
                                            uint64_type const cTotal,
                                            HRESULT     const err_code)
{
 assert(m_pCallContext);

 const t_ibp_error_element::self_ptr
  spErrRec
   (lib::structure::not_null_ptr
     (new t_ibp_error_element
       (err_code,
        mc_id_2)));

 assert(spErrRec);

 (*spErrRec)
   <<cErrors
   <<cTotal;

 m_pCallContext->Helper__AddErrRecord(spErrRec);

 m_pCallContext->Helper__SetLastErrorAsPrimary();
}//add_summary_error

//------------------------------------------------------------------------
void IBP_CallContext::tag_error_adapter::push_error(structure::t_err_record* const err_record)
{
 assert(err_record);
 assert(m_pCallContext);

 return m_pCallContext->Helper__AddErrRecord(err_record);
}//push_error

////////////////////////////////////////////////////////////////////////////////
//class IBP_CallContext:tag_error_adapter_with_limit

IBP_CallContext::tag_error_adapter_with_limit::tag_error_adapter_with_limit(const self_type& x)
 :m_pCallContext(x.m_pCallContext)
{
 assert(m_pCallContext);
}//tag_error_adapter_with_limit

//------------------------------------------------------------------------
IBP_CallContext::tag_error_adapter_with_limit::tag_error_adapter_with_limit(IBP_CallContext* const pCallContext)
 :m_pCallContext(pCallContext)
{
 assert(m_pCallContext);
}//tag_error_adapter_with_limit

//------------------------------------------------------------------------
IBP_CallContext::tag_error_adapter_with_limit::~tag_error_adapter_with_limit()
{
 assert(m_pCallContext);

 m_pCallContext=nullptr;
}//~tag_error_adapter_with_limit

//------------------------------------------------------------------------
void IBP_CallContext::tag_error_adapter_with_limit::push_error(structure::t_err_record* const err_record)
{
 assert(err_record);
 assert(m_pCallContext);

 if(m_pCallContext->m_errors.size()<IBP_CallContext::c_max_error_count)
  return m_pCallContext->Helper__AddErrRecord(err_record); //throw

 //добавляем сигнальное сообщение о превышении лимита на количество сообщений
 return m_pCallContext->Helper__AddErrLimit();
}//push_error

////////////////////////////////////////////////////////////////////////////////
//class IBP_CallContext

IBP_CallContext::IBP_CallContext(ole_lib::TBaseUnknown2* const pCallEntryObject)
 :m_pCallEntryObject(pCallEntryObject)
{
#ifdef IBP_BUILD_TESTCODE
 //В модульных тестах допускается NULL.
#else
 assert(m_pCallEntryObject);
#endif
}//IBP_CallContext

//------------------------------------------------------------------------
IBP_CallContext::~IBP_CallContext()
{
}//~IBP_CallContext

//interface --------------------------------------------------------------
ole_lib::TBaseUnknown2* IBP_CallContext::GetCallEntryObject()const
{
#ifdef IBP_BUILD_TESTCODE
 //В модульных тестах допускается NULL.
#else
 assert(m_pCallEntryObject);
#endif

 return m_pCallEntryObject;
}//GetCallEntryObject

//------------------------------------------------------------------------
IBP_CallContext::tag_error_adapter IBP_CallContext::Errors()
{
 return tag_error_adapter(this);
}//Errors

//------------------------------------------------------------------------
IBP_CallContext::tag_error_adapter_with_limit IBP_CallContext::ErrorsWithLimit()
{
 return tag_error_adapter_with_limit(this);
}//ErrorsWithLimit

//------------------------------------------------------------------------
HRESULT IBP_CallContext::ProcessCurrentException_NoThrow()
{
 HRESULT hr;

 try
 {
  throw;
 }
 catch(const std::exception& e)
 {
  hr=this->Helper__ProcessCurrentException_NoThrow(&e);
 }
 catch(...)
 {
  hr=this->Helper__ProcessCurrentException_NoThrow(nullptr);
 }//catch

 return hr;
}//ProcessCurrentException_NoThrow

//helper methods ---------------------------------------------------------
void IBP_CallContext::Helper__AddErrRecord(error_record_type* const record)
{
 assert(record);

 m_errors.push_back(record);
}//Helper__AddErrRecord

//------------------------------------------------------------------------
void IBP_CallContext::Helper__AddErrLimit()
{
 m_errors.add_limit_event();
}//Helper__AddErrLimit

//------------------------------------------------------------------------
void IBP_CallContext::Helper__SetLastErrorAsPrimary()
{
 assert(!m_errors.empty());

 if(m_errors.empty())
  return;

 m_primary_err_idx=(m_errors.size()-1);
}//Helper__SetLastErrorAsPrimary

//------------------------------------------------------------------------
HRESULT IBP_CallContext::Helper__ProcessCurrentException_NoThrow
                                           (const std::exception* const pExc)
{
 const HRESULT hr=IBP_MapExceptionToHRESULT(pExc); //no throw

 try
 {
  this->Helper__ProcessCurrentException(pExc); //throw
 }
 catch(...)
 {
  //гасим все ошибки
 }//catch

 return hr;
}//Helper__ProcessCurrentException_NoThrow

//------------------------------------------------------------------------
void IBP_CallContext::Helper__ProcessCurrentException
                                           (const std::exception* const pExc)
{
 tag_error_adapter error_adapter(this);

 if(!pExc)
 {
  error_adapter.add(E_UNEXPECTED); //throw

  return;
 }//if

 assert(pExc);

 size_t const _c=m_errors.size();

 error_adapter.add(*pExc); //throw

 if(const auto* const r=dynamic_cast<const t_ibp_error_records_r*>(pExc))
 {
  const auto r_idx=r->get_primary_err_idx();

  if(!r_idx.null())
  {
   assert(r_idx.value()<r->get_record_count());

   assert((_c+r_idx.value())<m_errors.size());

   m_primary_err_idx=_c+r_idx.value();

   //основная ошибка в коллекциях должна быть одним и тем же объектом
   assert(m_errors[m_primary_err_idx.value()]==r->get_record(r_idx.value()));
  }//if
 }//if r
}//Helper__ProcessCurrentException

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
