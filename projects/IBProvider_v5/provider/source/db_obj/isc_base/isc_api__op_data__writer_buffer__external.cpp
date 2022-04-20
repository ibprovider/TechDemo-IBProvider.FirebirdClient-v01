////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api__op_data__writer_buffer__external.cpp
//! \brief   InterBase.  ласс буфера дл€ записи управл€ющих данных
//! \author  Kovalenko Dmitry
//! \date    26.07.2011
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_api__op_data__writer_buffer__external.h"
#include "source/error_services/ibp_error_utils.h"
#include <structure/t_str_formatter.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_api__op_data__writer_buffer__external

void t_isc_api__op_data__writer_buffer__external::put_bytes(const char*     p,
                                                            size_type const n)
{
 CHECK_READ_TYPED_PTR(p,n);

 assert(m_used_size<=m_buffer_size);

 if((m_buffer_size-m_used_size)<n)
 {
  this->helper__throw_bug_check__overflow
   (L"t_isc_api__op_data__writer_buffer__external::put_bytes",
    L"#001",
    m_used_size+n);
 }//if

 const char* const e=p+n;

 byte_type* dest=reinterpret_cast<byte_type*>(m_buffer)+m_used_size;

 for(;p!=e;++p,++dest)
  (*dest)=(*p);

 m_used_size+=n;

 assert(m_used_size<=m_buffer_size);
}//put_bytes

//------------------------------------------------------------------------
void t_isc_api__op_data__writer_buffer__external::helper__throw_bug_check__overflow
                                           (const wchar_t* const source,
                                            const wchar_t* const point,
                                            size_type      const req_size)const
{
 assert(source);
 assert(point);
 assert(req_size<=this->get_capacity());

 //! \todo
 //!  ”брать отсюда шаблон сообщени€ об ошибке

 structure::wstr_formatter
  freason(L"buffer is small: %1. required size: %2");

 freason<<this->get_capacity()<<req_size;

 IBP_BUG_CHECK__DEBUG
  (source,
   point,
   freason.c_str());
}//helper__throw_bug_check__overflow

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
