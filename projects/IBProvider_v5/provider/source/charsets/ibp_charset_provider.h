////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_charset_provider.h
//! \brief   Определение интерфейса внешнего провайдера кодовых страниц
//! \author  Kovalenko Dmitry
//! \date    21.07.2017
#ifndef _ibp_charset_provider_H_
#define _ibp_charset_provider_H_

#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_charset_provider

/// <summary>
///  Определение интерфейса внешнего провайдера кодовых страниц
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE t_ibp_charset_provider:public db_obj::t_db_smart_interface
{
 public: //typedefs ------------------------------------------------------
  using cs_name_box_type
   =structure::t_basic_const_str_box<db_obj::t_db_charset_info::charset_name_type::value_type>;

 public:
  /// <summary>
  ///  Получение управляющего объекта кодовой страницы
  /// </summary>
  //! \return
  //!  Null, если кодовая страница не поддерживается
  virtual db_obj::t_db_charset_const_ptr
   load_cs(const cs_name_box_type& cs_name)=0;
};//class t_ibp_charset_provider

typedef structure::t_smart_object_ptr<t_ibp_charset_provider> t_ibp_charset_provider_ptr;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
