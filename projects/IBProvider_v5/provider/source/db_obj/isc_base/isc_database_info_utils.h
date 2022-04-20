////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_database_info_utils.h
//! \brief   Утилиты для обработки информационных свойств базы данных
//! \author  Kovalenko Dmitry
//! \date    04.01.2016
#ifndef _isc_database_info_utils_H_
#define _isc_database_info_utils_H_

#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class isc_database_info_utils

/// <summary>
///  Утилиты для обработки информационных свойств базы данных
/// </summary>
class isc_database_info_utils
{
 private:
  typedef isc_database_info_utils           self_type;

 public:
  typedef t_isc_connection_settings         cns_type;

 public:
  /// <summary>
  ///  Обработка сведений о реализации стека доступа к базе данных.
  /// </summary>
  //! \param[in]     szData
  //! \param[in]     pData
  //! \param[in,out] cns
  //!  Настройки подключения к базе данных.
  //!
  //! Обработанные данные будут сохранены в cns.db_impl_stack
  static void read_info__isc_implementations
               (size_t                szData,
                const unsigned char*  pData,
                cns_type&             cns);

  static void read_info__db_id
               (size_t                szData,
                const unsigned char*  pData,
                cns_type&             cns);

  static void read_info__server_version
               (size_t                szData,
                const unsigned char*  pData,
                cns_type&             cns);

  static void read_info__db_creation_data
               (size_t                szData,
                const unsigned char*  pData,
                cns_type&             cns);
};//class isc_database_info_utils

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
