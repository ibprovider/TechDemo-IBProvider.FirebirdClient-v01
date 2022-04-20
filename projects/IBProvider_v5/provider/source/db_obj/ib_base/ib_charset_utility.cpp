////////////////////////////////////////////////////////////////////////////////
//! \ingroup ib_base
//! \file    ib_charset_utility.h
//! \brief   Утилиты для работы с кодовыми страницами
//! \author  Kovalenko Dmitry
//! \date    12.01.2009
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/ib_base/ib_charset_utility.h"
#include "source/db_obj/db_service_utils.h"

namespace lcpi{namespace ibp{namespace ib_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ib_base
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Получение кодовой страницы для конвертирования метаданных
/// </summary>
//! \param[in] pCsMng
//!  Not NULL
db_obj::t_db_charset_const_ptr ib_get_metadata_charset(db_obj::t_db_charset_manager_v2* const pCsMng)
{
 assert(pCsMng);

 db_obj::t_db_charset_const_ptr spCnCharset(pCsMng->get_cn_charset());

 assert(spCnCharset);

 if(!spCnCharset->get_info().is_none())
  return /*move*/ spCnCharset;

 return pCsMng->get_ods_charset();
}//ib_get_metadata_charset

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ib_base*/}/*nms ibp*/}/*nms lcpi*/
