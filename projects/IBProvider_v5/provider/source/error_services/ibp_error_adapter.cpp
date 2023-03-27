////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_adapter.cpp
//! \brief   Класс для трансформации ошибок
//! \author  Kovalenko Dmitry
//! \date    03.06.2010
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_adapter.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_bind_data.h"
#include "source/error_services/ibp_error_utils.h"

#include <win32lib/win32_error.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_adapter

t_ibp_error_adapter::t_ibp_error_adapter()
{;}

//------------------------------------------------------------------------
t_ibp_error_adapter::~t_ibp_error_adapter()
{;}

//------------------------------------------------------------------------
void t_ibp_error_adapter::add(const std::exception& exc)
{
 using structure::t_err_records_r;

 if(const t_err_records_r* const x=dynamic_cast<const t_err_records_r*>(&exc))
 {
  //добавляем список ошибок
  for(size_t i(0),_count(x->get_record_count());i!=_count;++i)
   this->add(x->get_record(i));

  return;
 }//if t_err_records_r

 //--------------------------------------------------------
 if(const ole_lib::t_base_ole_error* const x=dynamic_cast<const ole_lib::t_base_ole_error*>(&exc))
  return this->add(x->com_code(),x->text());

 //--------------------------------------------------------
 if(const ole_lib::t_base_com_error* const x=dynamic_cast<const ole_lib::t_base_com_error*>(&exc))
  return this->add(x->com_code());

 //--------------------------------------------------------
 if(const win32lib::t_win32_error* const x=dynamic_cast<const win32lib::t_win32_error*>(&exc))
 {
  assert(x->win32_code()!=0);
  assert(FAILED(HRESULT_FROM_WIN32(x->win32_code())));

  return this->add(HRESULT_FROM_WIN32(x->win32_code()),x->msg());
 }//if - t_win32_error

 //--------------------------------------------------------
 if(const win32lib::t_base_win32_error* const x=dynamic_cast<const win32lib::t_base_win32_error*>(&exc))
 {
  assert(x->win32_code()!=0);
  assert(FAILED(HRESULT_FROM_WIN32(x->win32_code())));

  return this->add(HRESULT_FROM_WIN32(x->win32_code()));
 }//if - t_base_win32_error

 //--------------------------------------------------------
 if(dynamic_cast<const std::bad_alloc*>(&exc)!=NULL)
  return this->add(E_OUTOFMEMORY);

 //--------------------------------------------------------
 return this->add(E_FAIL,exc.what());
}//add - exc

//------------------------------------------------------------------------
void t_ibp_error_adapter::add(HRESULT const err_code)
{
 const t_ibp_error_element::self_ptr
  spError
   (structure::not_null_ptr
     (new t_ibp_error_element
           (err_code,
            ibp_mce_standart_error)));

 this->push_error(spError);
}//add - err_code

//------------------------------------------------------------------------
void t_ibp_error_adapter::add(HRESULT      const err_code,
                              str_arg_type const msg)
{
 if(msg.empty())
  return this->add(err_code);

 const t_ibp_error_element::self_ptr
  spError
   (structure::not_null_ptr
     (new t_ibp_error_element
           (err_code,
            ibp_mce_unknown_error_1)));

 (*spError)<<msg;

 this->push_error(spError);
}//add - err_code+msg

//------------------------------------------------------------------------
void t_ibp_error_adapter::add(base_error_record_type* const pErrorRecord)
{
 assert(pErrorRecord);

 this->push_error(pErrorRecord);
}//add

//------------------------------------------------------------------------
void t_ibp_error_adapter::add__no_throw(const std::exception& exc)
{
 try
 {
  this->add(exc);
 }
 catch(...)
 {;}
}//add__no_throw - exception

//------------------------------------------------------------------------
void t_ibp_error_adapter::add(mc_type     const     mc_id_2,
                              uint64_type const     num,
                              const std::exception& exc)
{
 if(base_error_records_r_cptr const x=dynamic_cast<base_error_records_r_cptr>(&exc))
  return this->push_ibp_error_ex(mc_id_2,num,x);

 //--------------------------------------------------------
 if(const ole_lib::t_base_ole_error* const x=dynamic_cast<const ole_lib::t_base_ole_error*>(&exc))
  return this->add(mc_id_2,num,x->com_code(),x->text());

 //--------------------------------------------------------
 if(const ole_lib::t_base_com_error* const x=dynamic_cast<const ole_lib::t_base_com_error*>(&exc))
  return this->add(mc_id_2,num,x->com_code());

 //--------------------------------------------------------
 if(const win32lib::t_win32_error* const x=dynamic_cast<const win32lib::t_win32_error*>(&exc))
 {
  assert(x->win32_code()!=0);
  assert(FAILED(HRESULT_FROM_WIN32(x->win32_code())));

  return this->add(mc_id_2,num,HRESULT_FROM_WIN32(x->win32_code()),x->msg());
 }//if - t_win32_error

 //--------------------------------------------------------
 if(const win32lib::t_base_win32_error* const x=dynamic_cast<const win32lib::t_base_win32_error*>(&exc))
 {
  assert(x->win32_code()!=0);
  assert(FAILED(HRESULT_FROM_WIN32(x->win32_code())));

  return this->add(mc_id_2,num,HRESULT_FROM_WIN32(x->win32_code()));
 }//if

 //--------------------------------------------------------
 if(dynamic_cast<const std::bad_alloc*>(&exc)!=NULL)
  return this->add(mc_id_2,num,E_OUTOFMEMORY);

 //--------------------------------------------------------
 return this->add(mc_id_2,num,E_FAIL,exc.what());
}//add - mc_id_2,num,exc

//------------------------------------------------------------------------
void t_ibp_error_adapter::add(mc_type     const mc_id_2,
                              uint64_type const num,
                              HRESULT     const err_code)
{
 const t_ibp_error_element::self_ptr
  spError
   (structure::not_null_ptr
     (new t_ibp_error_element
       (err_code,
        mc_id_2)));

 const IBP_BindErrorDataPtr
  spBindError
   (structure::not_null_ptr
      (new IBP_BindErrorData
        (0,
         err_code,
         ibp_mce_standart_error)));

 //номер ошибки
 (*spError)<<num<<spBindError.ptr();

 this->push_error(spError);
}//add - mc_id_2,num,err_code

//------------------------------------------------------------------------
void t_ibp_error_adapter::add(mc_type      const mc_id_2,
                              uint64_type  const num,
                              HRESULT      const err_code,
                              str_arg_type const msg)
{
 if(msg.empty())
  return this->add(mc_id_2,num,err_code);

 const t_ibp_error_element::self_ptr
  spError
   (structure::not_null_ptr
     (new t_ibp_error_element
       (err_code,
        mc_id_2)));

 (*spError)<<num<<msg;

 this->push_error(spError);
}//add - mc_id_2,num,err_code,msg

//------------------------------------------------------------------------
void t_ibp_error_adapter::catch_row_error(mc_type     const mc_id_3,
                                          uint64_type const num,
                                          DBROWSTATUS const RowStatus)
{
 try
 {
  throw;
 }
 catch(const std::exception& exc)
 {
  this->add_row_error(mc_id_3,num,RowStatus,exc);
 }
 catch(...)
 {
  this->add_row_error(mc_id_3,num,RowStatus,E_UNEXPECTED);
 }
}//catch_row_error

//------------------------------------------------------------------------
void t_ibp_error_adapter::add_row_error(mc_type          const mc_id_3,
                                        uint64_type      const num,
                                        DBROWSTATUS      const RowStatus,
                                        const std::exception&  exc)
{
 if(base_error_records_r_cptr const x=dynamic_cast<base_error_records_r_cptr>(&exc))
  return this->push_row_ibp_error_ex(mc_id_3,num,RowStatus,x);

 //--------------------------------------------------------
 if(const ole_lib::t_base_ole_error* const x=dynamic_cast<const ole_lib::t_base_ole_error*>(&exc))
  return this->add_row_error(mc_id_3,num,RowStatus,x->com_code(),x->text());

 //--------------------------------------------------------
 if(const ole_lib::t_base_com_error* const x=dynamic_cast<const ole_lib::t_base_com_error*>(&exc))
  return this->add_row_error(mc_id_3,num,RowStatus,x->com_code());

 //--------------------------------------------------------
 if(const win32lib::t_win32_error* const x=dynamic_cast<const win32lib::t_win32_error*>(&exc))
 {
  assert(x->win32_code()!=0);
  assert(FAILED(HRESULT_FROM_WIN32(x->win32_code())));

  return this->add_row_error(mc_id_3,num,RowStatus,HRESULT_FROM_WIN32(x->win32_code()),x->msg());
 }//if - t_win32_error

 //--------------------------------------------------------
 if(const win32lib::t_base_win32_error* const x=dynamic_cast<const win32lib::t_base_win32_error*>(&exc))
 {
  assert(x->win32_code()!=0);
  assert(FAILED(HRESULT_FROM_WIN32(x->win32_code())));

  return this->add_row_error(mc_id_3,num,RowStatus,HRESULT_FROM_WIN32(x->win32_code()));
 }//if - t_base_win32_error

 //--------------------------------------------------------
 if(dynamic_cast<const std::bad_alloc*>(&exc))
  return this->add_row_error(mc_id_3,num,RowStatus,E_OUTOFMEMORY);

 //--------------------------------------------------------
 return this->add_row_error(mc_id_3,num,RowStatus,E_FAIL,exc.what());
}//add_row_error - mc_id_3,num,RowStatus,exc

//------------------------------------------------------------------------
void t_ibp_error_adapter::add_row_error(mc_type     const mc_id_3,
                                        uint64_type const num,
                                        DBROWSTATUS const RowStatus,
                                        HRESULT     const err_code)
{
 const t_ibp_error_element::self_ptr
  spError
   (structure::not_null_ptr
     (new t_ibp_error_element
       (err_code,
        mc_id_3)));

 const IBP_BindErrorDataPtr
  spBindError
   (structure::not_null_ptr
     (new IBP_BindErrorData
       (0,
        err_code,
        ibp_mce_standart_error)));

 (*spError)<<num<<oledb_lib::GetDBRowStatusName(RowStatus)<<spBindError.ptr();

 this->push_error(spError);
}//add_row_error - mc_id_3,num,RowStatus,err_code

//------------------------------------------------------------------------
void t_ibp_error_adapter::add_row_error(mc_type      const mc_id_3,
                                        uint64_type  const num,
                                        DBROWSTATUS  const RowStatus,
                                        HRESULT      const err_code,
                                        str_arg_type const msg)
{
 if(msg.empty())
  return this->add_row_error(mc_id_3,num,RowStatus,err_code);

 const t_ibp_error_element::self_ptr
  spError
   (structure::not_null_ptr
     (new t_ibp_error_element
       (err_code,
        mc_id_3)));

 (*spError)<<num<<oledb_lib::GetDBRowStatusName(RowStatus)<<msg;

 this->push_error(spError);
}//add_row_error

//вспомогательные методы -------------------------------------------------
void t_ibp_error_adapter::push_ibp_error_ex(mc_type                   const mc_id_2,
                                            uint64_type               const num,
                                            base_error_records_r_cptr const recs)
{
 assert(recs);

 //добавляем элементы recs, обернутые в врапперы

 for(size_t i(0),_c(recs->get_record_count());
     i!=_c;
     ++i)
 {
  const HRESULT com_code
   =IBP_MapErrorRecordToHRESULT(recs->get_record(i));

  const t_ibp_error_element::self_ptr
   spNewErrorRecord
    =structure::not_null_ptr
      (new t_ibp_error_element
        (com_code,
         mc_id_2));

  assert(spNewErrorRecord);

  //------
  (*spNewErrorRecord)<<num;

  //------
  const structure::t_err_record::self_ptr
   spErrorRecord
    =recs->get_record(i);

  assert(spErrorRecord);

  (*spNewErrorRecord)<<spErrorRecord;

  //------ регистрируем Custom-ошибку в новой записи
  if(const auto* const pX=dynamic_cast<const t_ibp_error_element*>(spErrorRecord.ptr()))
   spNewErrorRecord->m_spGetCustomError=pX->m_spGetCustomError;

  //------
  this->push_error(spNewErrorRecord);
 }//for i

}//push_ibp_error_ex - mc_id_2,num,recs

//вспомогательные методы -------------------------------------------------
void t_ibp_error_adapter::push_row_ibp_error_ex
                                           (mc_type                   const mc_id_3,
                                            uint64_type               const num,
                                            DBROWSTATUS               const RowStatus,
                                            base_error_records_r_cptr const recs)
{
 assert(recs);

 //добавляем элементы recs, обернутые во врапперы

 for(size_t i(0),_c(recs->get_record_count());
     i!=_c;
     ++i)
 {
  const HRESULT com_code
   =IBP_MapErrorRecordToHRESULT(recs->get_record(i));

  const t_ibp_error_element::self_ptr
   spNewErrorRecord
    =structure::not_null_ptr
      (new t_ibp_error_element
        (com_code,
         mc_id_3));

  assert(spNewErrorRecord);

  //------
  (*spNewErrorRecord)<<num<<oledb_lib::GetDBRowStatusName(RowStatus);

  //------
  const structure::t_err_record::self_ptr
   spErrorRecord
    =recs->get_record(i);

  assert(spErrorRecord);

  (*spNewErrorRecord)<<spErrorRecord;

  //------ регистрируем Custom-ошибку в новой записи
  if(const auto* const pX=dynamic_cast<const t_ibp_error_element*>(spErrorRecord.ptr()))
   spNewErrorRecord->m_spGetCustomError=pX->m_spGetCustomError;

  //------
  this->push_error(spNewErrorRecord);
 }//for i
}//push_row_ibp_error_ex - mc_id_3,num,RowStatus,recs

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
