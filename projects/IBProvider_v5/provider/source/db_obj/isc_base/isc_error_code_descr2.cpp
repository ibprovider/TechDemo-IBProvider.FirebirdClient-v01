////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_error_code_descr2.cpp
//! \brief   Конструкция для расширенного описания кода isc-ошибки
//! \author  Kovalenko Dmitry
//! \date    29.12.2014
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_error_code_descr2.h"

#include <structure/utilities/string/string_length.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

void debug__check_isc_error_code_descr2_array
                    (const char*                    const pArrayName,
                     size_t                         const cErrDescrs,
                     const t_isc_error_code_descr2* const rgErrDescrs)
{
 assert(pArrayName!=nullptr);

 CHECK_READ_TYPED_PTR(rgErrDescrs,cErrDescrs);

 for(size_t i(0);i!=cErrDescrs;++i)
 {
  assert_msg(rgErrDescrs[i].sqlstate!=nullptr,
             pArrayName<<"["<<i<<"]");

  assert_msg(structure::string_length(rgErrDescrs[i].sqlstate)==5,
             pArrayName<<"["<<i<<"]");

  if(i==0)
   continue;

  assert_msg(rgErrDescrs[i-1].isc_code<rgErrDescrs[i].isc_code,
             pArrayName<<"["<<i<<"]");
 }//for i
}//debug__check_isc_error_code_descr2_array

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
