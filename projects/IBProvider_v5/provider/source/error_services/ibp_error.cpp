////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error.cpp
//! \brief   Класс исключения для обработки OLEDB-ошибок
//! \author  Kovalenko Dmitry
//! \date    03.02.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_utils.h"
#include "structure/t_numeric_cast.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error:tag_error_adapter_with_limit

t_ibp_error::tag_error_adapter_with_limit::tag_error_adapter_with_limit(const self_type& x)
 :m_pOwner(x.m_pOwner)
{
 assert(m_pOwner);
}//tag_error_adapter_with_limit

//------------------------------------------------------------------------
t_ibp_error::tag_error_adapter_with_limit::tag_error_adapter_with_limit(t_ibp_error* const pOwner)
 :m_pOwner(pOwner)
{
 assert(m_pOwner);
}//tag_error_adapter_with_limit

//------------------------------------------------------------------------
t_ibp_error::tag_error_adapter_with_limit::~tag_error_adapter_with_limit()
{
 assert(m_pOwner);

 m_pOwner=nullptr;
}//~tag_error_adapter_with_limit

//------------------------------------------------------------------------
void t_ibp_error::tag_error_adapter_with_limit::push_error(structure::t_err_record* const err_record)
{
 assert(err_record);
 assert(m_pOwner);

 if(m_pOwner->m_errors.size()<ibp_limc_MaxErrorCountInBulkOperation)
  return m_pOwner->push_error(err_record); //throw

 //добавляем сигнальное сообщение о превышении лимита на количество сообщений
 return m_pOwner->add_limit_event();
}//push_error

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error

t_ibp_error::t_ibp_error(self_type& x,const tag_ctr__swap&)
 :base_error_type(S_OK)
{
 this->swap(x);
}//t_ibp_error

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(const self_type& exc)
 :base_error_type   (exc)
 ,m_errors          (exc.m_errors)
 ,m_cur_error       (exc.m_cur_error)
 ,m_primary_err_idx (exc.m_primary_err_idx)
{;}

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(HRESULT const err_code)
 :base_error_type(err_code)
{
}//t_ibp_error

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(HRESULT const err_code,
                         mc_type const msg_code)
 :base_error_type(err_code)
{
 this->add_error(err_code,
                 msg_code);
}//t_ibp_error

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(HRESULT                 const err_code,
                         mc_type                 const msg_code,
                         ibprovider::IBP_IClone* const pCErr)
 :base_error_type(err_code)
{
 this->add_error(err_code,
                 msg_code,
                 pCErr);
}//t_ibp_error

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(HRESULT        const err_code,
                         subsys_id_type const subsys_id,
                         mc_type        const msg_code)
 :base_error_type(err_code)
{
 this->add_error(err_code,
                 subsys_id,
                 msg_code);
}//t_ibp_error

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(HRESULT                 const err_code,
                         subsys_id_type          const subsys_id,
                         mc_type                 const msg_code,
                         ibprovider::IBP_IClone* const pCErr)
 :base_error_type(err_code)
{
 this->add_error(err_code,
                 subsys_id,
                 msg_code,
                 pCErr);
}//t_ibp_error

//------------------------------------------------------------------------
//
// [2019-01-15] Замещена версией для t_ibp_error_records_r
//
//t_ibp_error::t_ibp_error(HRESULT              const err_code,
//                         const base_records_r_type& records)
// :base_error_type(err_code)
//{
// for(size_t i(0),n(records.get_record_count());i!=n;++i)
// {
//  assert(records.get_record(i));
//
//  this->add_error(records.get_record(i));
// }//for i
//}//t_ibp_error

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(HRESULT                const err_code,
                         const t_ibp_error_records_r& records)
 :base_error_type(err_code)
{
 for(size_t i(0),n(records.get_record_count());i!=n;++i)
 {
  assert(records.get_record(i));

  this->add_error(records.get_record(i));
 }//for i

#ifndef NDEBUG
 if(!records.get_primary_err_idx().null())
  assert(records.get_primary_err_idx().value()<m_errors.size());
#endif

 m_primary_err_idx=records.get_primary_err_idx();
}//t_ibp_error - t_ibp_error_records_r

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(const std::exception& exc)
 :base_error_type(IBP_MapExceptionToHRESULT(&exc))
{
 this->add(exc);

 if(const self_type* const x=dynamic_cast<const self_type*>(&exc))
 {
  m_primary_err_idx=x->m_primary_err_idx;
 }
}//t_ibp_error - exc

//------------------------------------------------------------------------
t_ibp_error::t_ibp_error(error_record_type* const pError)
 :base_error_type(pError->m_err_code)
{
 this->add_error(pError);
}//t_ibp_error

//------------------------------------------------------------------------
t_ibp_error::~t_ibp_error() __STL_EXCEPTION_DCR_THROW_SPEC
{;}

//assign operators -------------------------------------------------------
t_ibp_error& t_ibp_error::operator = (const self_type& exc)
{
 self_type tmp(exc);

 this->swap(tmp);

 return *this;
}//operator =

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::operator = (const std::exception& exc)
{
 self_type tmp(exc);

 this->swap(tmp);

 return *this;
}//operator =

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::operator = (HRESULT const err_code)
{
 m_code=err_code;

 return *this;
}//operator = HRESULT

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::clear_state(HRESULT const err_code)
{
 self_type(err_code).swap(*this);

 return *this;
}//clear_state

//swap -------------------------------------------------------------------
void t_ibp_error::swap(self_type& x)
{
 ole_lib::t_base_com_error::swap(x);

 std::swap(m_errors          ,x.m_errors);
 std::swap(m_cur_error       ,x.m_cur_error);
 std::swap(m_primary_err_idx ,x.m_primary_err_idx);
}//swap

//exception interface ----------------------------------------------------
const char* t_ibp_error::what()const __STL_EXCEPTION_WHAT_THROW_SPEC
{
 return "IBProvider Exception";
}//what

//------------------------------------------------------------------------
t_ibp_error::tag_error_adapter_with_limit t_ibp_error::adapter_with_limit()
{
 return tag_error_adapter_with_limit(this);
}//adapter_with_limit

//------------------------------------------------------------------------
void t_ibp_error::add_limit_event()
{
 assert(!m_errors.empty());

 return m_errors.add_limit_event();
}//add_limit_event

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::add_error(HRESULT const err_code,
                                    mc_type const msg_code)
{
 error_record_ptr
  x(structure::not_null_ptr(new error_record_type(err_code,
                                                  msg_code)));
 assert(x);

 m_errors.push_back(x);

 assert(x);

 m_cur_error.swap(x);

 assert(m_cur_error);

 return *this;
}//add new error

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::add_error(HRESULT                 const err_code,
                                    mc_type                 const msg_code,
                                    ibprovider::IBP_IClone* const pCErr)
{
 error_record_ptr
  x(structure::not_null_ptr(new error_record_type(err_code,
                                                  msg_code,
                                                  pCErr)));
 assert(x);

 m_errors.push_back(x);

 assert(x);

 m_cur_error.swap(x);

 assert(m_cur_error);

 return *this;
}//add new error

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::add_error(HRESULT        const err_code,
                                    subsys_id_type const subsys_id,
                                    mc_type        const msg_code)
{
 error_record_ptr
  x(structure::not_null_ptr(new error_record_type(err_code,
                                                  subsys_id,
                                                  msg_code)));
 assert(x);

 m_errors.push_back(x);

 assert(x);

 m_cur_error.swap(x);

 assert(m_cur_error);

 return *this;
}//add new error

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::add_error(HRESULT                 const err_code,
                                    subsys_id_type          const subsys_id,
                                    mc_type                 const msg_code,
                                    ibprovider::IBP_IClone* const pCErr)
{
 error_record_ptr
  x(structure::not_null_ptr(new error_record_type(err_code,
                                                  subsys_id,
                                                  msg_code,
                                                  pCErr)));
 assert(x);

 m_errors.push_back(x);

 assert(x);

 m_cur_error.swap(x);

 assert(m_cur_error);

 return *this;
}//add new error

//------------------------------------------------------------------------
t_ibp_error::self_type& t_ibp_error::add_error(base_error_record_type* const pError)
{
 assert(pError);

 m_errors.push_back(pError);

 m_cur_error.Release();

 return *this;
}//add_error

//------------------------------------------------------------------------
t_ibp_error& t_ibp_error::add_error__no_throw(HRESULT const err_code,
                                              mc_type const msg_code__0)
{
 try
 {
  this->add_error(err_code,msg_code__0); //throw
 }
 catch(...)
 {;}

 return *this;
}//add_error__no_throw

//------------------------------------------------------------------------
size_t t_ibp_error::get_record_count()const
{
 return m_errors.size();
}//get_record_count

//------------------------------------------------------------------------
structure::t_err_record::self_ptr t_ibp_error::get_record(size_t i)const
{
 assert(i<m_errors.size());

 return m_errors[i];
}//get_record

//------------------------------------------------------------------------
t_ibp_error::size_type_N t_ibp_error::get_primary_err_idx()const
{
 return m_primary_err_idx;
}//get_primary_err_idx

//------------------------------------------------------------------------
void t_ibp_error::raise()const
{
 throw *this;
}//raise

//------------------------------------------------------------------------
void t_ibp_error::raise_me()
{
 throw t_ibp_error(*this,tag_ctr__swap());
}//raise_me

//вспомогательные методы -------------------------------------------------
t_ibp_error& t_ibp_error::add_arg(const base_variant_type& x)
{
 assert(m_cur_error);

 m_cur_error->add_arg(x);

 return *this;
}//add_arg

//------------------------------------------------------------------------
void t_ibp_error::push_error(base_error_record_type* const pError)
{
 assert(pError);

 m_errors.push_back(pError);
}//push_error

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
