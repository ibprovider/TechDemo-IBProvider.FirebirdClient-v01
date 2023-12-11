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
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_api__op_data__writer_buffer__external

void t_isc_api__op_data__writer_buffer__external::put_bytes(const char*     p,
                                                            size_type const n)
{
 CHECK_READ_TYPED_PTR(p,n);

 const wchar_t* const c_bugcheck_src
  =L"t_isc_api__op_data__writer_buffer__external::put_bytes";

 assert(m_used_size<=m_buffer_size);

 if((m_buffer_size-m_used_size)<n)
 {
  this->helper__throw_bug_check__overflow
   (c_bugcheck_src,
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

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (source,
   point,
   me_bug_check__buffer_is_small_2,
   this->get_capacity(),
   req_size);
}//helper__throw_bug_check__overflow

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
