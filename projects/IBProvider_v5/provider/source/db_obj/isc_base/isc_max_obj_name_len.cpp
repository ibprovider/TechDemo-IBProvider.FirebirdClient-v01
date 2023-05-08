////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_max_obj_name_len.cpp
//! \brief   The information about max database object name length
//! \author  Kovalenko Dmitry
//! \date    10.03.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_max_obj_name_len.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_max_obj_name_len

t_isc_max_obj_name_len::t_isc_max_obj_name_len()
 :m_value(0)
 ,m_kind(kind_type::not_defined)
{
}

//------------------------------------------------------------------------
void t_isc_max_obj_name_len::reset()
{
 m_kind =kind_type::not_defined;

 m_value=0;
}//reset

//------------------------------------------------------------------------
void t_isc_max_obj_name_len::set_in_fss_bytes(size_t const value)
{
 m_kind=kind_type::in_fss_bytes;

 m_value=value;
}//set_in_fss_bytes

//------------------------------------------------------------------------
void t_isc_max_obj_name_len::set_in_utf8_symbols(size_t const value)
{
 m_kind=kind_type::in_utf8_symbols;

 m_value=value;
}//set_in_utf8_symbols

//------------------------------------------------------------------------
size_t t_isc_max_obj_name_len::get_value()const
{
 return m_value;
}//get_value

//------------------------------------------------------------------------
t_isc_max_obj_name_len::kind_type t_isc_max_obj_name_len::get_kind()const
{
 return m_kind;
}//get_kind

//------------------------------------------------------------------------
bool t_isc_max_obj_name_len::is_not_defined()const
{
 return m_kind==kind_type::not_defined;
}//is_not_defined

//------------------------------------------------------------------------
bool t_isc_max_obj_name_len::is_in_fss_bytes()const
{
 return m_kind==kind_type::in_fss_bytes;
}//is_in_fss_bytes

//------------------------------------------------------------------------
bool t_isc_max_obj_name_len::is_in_utf8_symbols()const
{
 return m_kind==kind_type::in_utf8_symbols;
}//is_in_utf8_symbols

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
