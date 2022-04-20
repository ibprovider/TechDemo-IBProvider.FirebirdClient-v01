////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_dbms_info.h
//! \brief   —труктура дл€ хранени€ описани€ ISC-сервера, ISC-клиента
//! \author  Kovalenko Dmitry
//! \date    24.06.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_dbms_info.h"
#include <structure/utilities/string/del_space.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_dbms_info

////////////////////////////////////////////////////////////////////////////////
//class t_isc_dbms_info

t_isc_dbms_info::t_isc_dbms_info()
 :id(isc_dbms_id_Unknown)
 ,name(g_dbms_name_Unknown)
{}

//------------------------------------------------------------------------
t_isc_dbms_info::t_isc_dbms_info(const self_type& x)
 :descr_Ex (x.descr_Ex)
 ,id       (x.id)
 ,name     (x.name)
 ,version  (x.version)
{;}

//------------------------------------------------------------------------
t_isc_dbms_info& t_isc_dbms_info::operator = (const self_type& x)
{
 self_type tmp(x);

 return this->swap(tmp);
}//operator =

//------------------------------------------------------------------------
t_isc_dbms_info& t_isc_dbms_info::reset()
{
 return (*this)=self_type();
}//reset

//------------------------------------------------------------------------
t_isc_dbms_info& t_isc_dbms_info::swap(self_type& x)
{
 std::swap(this->descr_Ex  ,x.descr_Ex);
 std::swap(this->id        ,x.id);
 std::swap(this->name      ,x.name);
 std::swap(this->version   ,x.version);

 return *this;
}//swap

//------------------------------------------------------------------------
t_isc_dbms_info::string_type t_isc_dbms_info::get_title()const
{
 string_type x(this->name);

 x+=' ';

 x+=this->version;

 return __STL_MOVE_VALUE(structure::self_del_space(x));
}//get_title

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
