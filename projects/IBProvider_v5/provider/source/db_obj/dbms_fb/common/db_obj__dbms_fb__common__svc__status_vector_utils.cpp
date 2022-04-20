////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common
//! \file    db_obj__dbms_fb__common__svc__status_vector_utils.cpp
//! \brief   Интерфейс для работы со статус вектором.
//! \author  Kovalenko Dmitry
//! \date    07.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common__svc__status_vector_utils.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{
////////////////////////////////////////////////////////////////////////////////
//struct fb_common__svc__status_vector_utils::gresult_data_type

fb_common__svc__status_vector_utils::gresult_data_type::gresult_data_type()
 :code(gresult__ok)
 ,check_place(nullptr)
 ,check_point(nullptr)
{;}

//------------------------------------------------------------------------
fb_common__svc__status_vector_utils::gresult_data_type::gresult_data_type
                                           (gresult_code_type const _code,
                                            const wchar_t*    const _check_place,
                                            const wchar_t*    const _check_point)
 :code(_code)
 ,check_place(_check_place)
 ,check_point(_check_point)
{;}

//------------------------------------------------------------------------
fb_common__svc__status_vector_utils::gresult_data_type
 fb_common__svc__status_vector_utils::gresult_data_type::create_ok()
{
 return self_type();
}//create_ok

//------------------------------------------------------------------------
fb_common__svc__status_vector_utils::gresult_data_type
 fb_common__svc__status_vector_utils::gresult_data_type::create_bad_sv
                                           (const wchar_t* const _check_place,
                                            const wchar_t* const _check_point)
{
 assert(_check_place!=nullptr);
 assert(_check_point!=nullptr);

 return self_type(gresult__bad_sv,
                  _check_place,
                  _check_point);
}//create_bad_sv

//------------------------------------------------------------------------
bool fb_common__svc__status_vector_utils::gresult_data_type::operator == (gresult_code_type const _code)const
{
 return this->code==_code;
}//operator ==

//------------------------------------------------------------------------
bool fb_common__svc__status_vector_utils::gresult_data_type::operator != (gresult_code_type const _code)const
{
 return this->code!=_code;
}//operator !=

////////////////////////////////////////////////////////////////////////////////
}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
