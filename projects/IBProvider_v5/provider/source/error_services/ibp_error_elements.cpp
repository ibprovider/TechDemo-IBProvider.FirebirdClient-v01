////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_elements.h
//! \brief   Контейнер для хранения описания ошибок
//! \author  Kovalenko Dmitry
//! \date    12.04.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_elements.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_elements

t_ibp_error_elements::t_ibp_error_elements()
{
}

//------------------------------------------------------------------------
t_ibp_error_elements::t_ibp_error_elements(const self_type& x)
 :m_items(x.m_items)
{
}

//------------------------------------------------------------------------
t_ibp_error_elements::t_ibp_error_elements(self_type&& x)
 :m_items(LCPI_STL_MOVE_VALUE(x.m_items))
{
}

//------------------------------------------------------------------------
t_ibp_error_elements::~t_ibp_error_elements()
{
}

//------------------------------------------------------------------------
t_ibp_error_elements& t_ibp_error_elements::operator = (const self_type& x)
{
 m_items=x.m_items;

 return *this;
}//operator copy

//------------------------------------------------------------------------
t_ibp_error_elements& t_ibp_error_elements::operator = (self_type&& x)
{
 m_items=LCPI_STL_MOVE_VALUE(x.m_items);

 return *this;
}//operator move

//------------------------------------------------------------------------
size_t t_ibp_error_elements::size()const
{
 return m_items.size();
}//size

//------------------------------------------------------------------------
bool t_ibp_error_elements::empty()const
{
 return m_items.empty();
}//empty

//------------------------------------------------------------------------
const t_ibp_error_elements::error_record_ptr& t_ibp_error_elements::back()const
{
 assert(!m_items.empty());

 return m_items.back();
}//back

//------------------------------------------------------------------------
const t_ibp_error_elements::error_record_ptr& t_ibp_error_elements::operator [] (size_t const index)const
{
 assert(index<m_items.size());

 return m_items[index];
}//operator []

//------------------------------------------------------------------------
void t_ibp_error_elements::push_back(error_record_type* const error_record)
{
 assert(error_record);

 m_items.emplace_back(error_record);

 assert(!m_items.empty());
}//push_back

//------------------------------------------------------------------------
void t_ibp_error_elements::add_limit_event()
{
 //мы не должны добалять уведомление о достижения ограничений при пустом контейнере
 assert(!m_items.empty());

 if(const auto* const r=dynamic_cast<t_ibp_error_element*>(m_items.back().ptr()))
 {
  if(r->m_msg_code==ibp_mce_common__err_count_limit_was_reached_0)
  {
   //игнорируем повторное сигнальное сообщение.
   assert(r->m_err_code==S_FALSE);

   return;
  }//if
 }//if r

 //-----------------------------------------
 error_record_ptr
  spLimitRec
   (lib::structure::not_null_ptr
    (new t_ibp_error_element
      (S_FALSE,
       ibp_mce_common__err_count_limit_was_reached_0)));

 assert(spLimitRec);

 m_items.push_back(LCPI_STL_MOVE_VALUE(spLimitRec));

 assert(!m_items.empty());
}//add_limit_event

//------------------------------------------------------------------------
void t_ibp_error_elements::swap(self_type& x)
{
 m_items.swap(x.m_items);
}//swap

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
