////////////////////////////////////////////////////////////////////////////////
//! \ingroup  isc_base
//! \file     isc_info_buffer_v1_utilities.h
//! \brief    Utilities for work with information buffer (v1).
//! \author   Kovalenko Dmitry
//! \date     26.03.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_info_buffer_v1_utilities.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_info_buffer_v1_utilities

const isc_info_buffer_v1_utilities::byte_type*
 isc_info_buffer_v1_utilities::skip_element_data
                                           (const byte_type* const beg,
                                            const byte_type* const end,
                                            long             const tagID)
{
 assert(beg<=end);

 CHECK_READ_TYPED_PTR(beg,end-beg);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"isc_info_buffer_v1_utilities::skip_element_data";

 const auto* ptr=beg;

 //читаем длину блока
 if(size_t(end-ptr)<isc_api::ibp_isc__info_tag__data_length__byte_count)
 {
  //ERROR - [BUG CHECK] некорректный формат элемента.

  IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
   (c_bugcheck_src,
    L"#001",
    tagID);
 }//if

 size_t item_length=0;

 assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(item_length));

 _VERIFY(isc_base::isc_portable_format_to_integer::exec_r
          (isc_api::ibp_isc__info_tag__data_length__byte_count,
           ptr,
           &item_length));

 ptr+=isc_api::ibp_isc__info_tag__data_length__byte_count;

 assert(ptr<=end);

 //пропускаем данные блока
 if(size_t(end-ptr)<item_length)
 {
  //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

  IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
   (c_bugcheck_src,
    L"#002",
    tagID,
    item_length,
    size_t(end-ptr));
 }//if

 ptr+=item_length;

 assert(ptr>beg);
 assert(ptr<=end);

 return ptr;
}//skip_element_data

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
