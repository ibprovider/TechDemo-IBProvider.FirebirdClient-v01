////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_limits
//! \file    ibp_cfg_structure.h
//! \brief   Определение конфигурационных параметров IBProvider-а
//! \author  Kovalenko Dmitry
//! \date    10.11.2005.
#ifndef _ibp_cfg_structure_H_
#define _ibp_cfg_structure_H_

#include "source/ibp_cfg_compile.h"

namespace lcpi{namespace ibp{namespace cfg{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_limits
//! @{
////////////////////////////////////////////////////////////////////////////////
//check defines

#ifndef IBP_ENGINE_BMK_SIZE
# error "IBP_ENGINE_BMK_SIZE is not defined"
#endif

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Определение максимальный размера собственной закладки, используемой провайдером.
/// </summary>
const DBLENGTH ibp_self_bookmark_max_size=IBP_ENGINE_BMK_SIZE;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Максимальный размер символьных имен метаданных.
/// </summary>
const DBLENGTH ibp_meta_obj_name_max_len=128;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Максимальный размер пути к файлу с EXTERNAL TABLE. Используется в метаданных.
/// </summary>
const DBLENGTH ibp_meta_external_file_path_max_len=512;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Максимальная длина сигнатуры запроса. Используется при обработке ошибок.
/// </summary>
const size_t ibp_cfg__max_stmt_sign_length=30;

////////////////////////////////////////////////////////////////////////////////
//class ibp_sql_pobj_cache

class ibp_sql_pobj_cache LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// <summary>
  ///  Максимальное количество сбоев запуска GC_TASK из RC_TASK.
  /// </summary>
  static const unsigned max_failure_in_rc_task=10;
};//class ibp_sql_pobj_cache

////////////////////////////////////////////////////////////////////////////////
//class ibp_sql_pobj_cache_manager

class ibp_sql_pobj_cache_manager LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// <summary>
  ///  Максимальное количество сбоев запуска GC_TASK из RC_TASK.
  /// </summary>
  static const unsigned max_failure_in_rc_task=10;

  /// <summary>
  ///  Пороговое значение количества элементов в ibp_sql_parser__common__pobj_cache_manager,
  ///  после которого get_pobj_cache начинает обновлять историю использования (m_cache_list).
  /// </summary>
  ///
  /// Значение взято от балды.
  ///
  /// Ситуация такая.
  /// - Перемещение в m_сache_list создает блокировку доступа.
  ///
  /// - Эта блокировка мешает работе RC_TASK - он прекращает работу, чтобы пропустить
  ///   waiter-ов. Или не может захватить эту блокировку.
  ///
  /// - Для небольшого количества элементов это скорее всего бесмысленная работа.
  ///
  /// - Поэтому, пока общее количество элементов меньше указанного, мы не будем
  ///   менять порядок элементов в m_cache_list, чтобы "помочь" RC_TASK побыстрее
  ///   обнаружить мусор.
  ///
  static const size_t treshold_count_for_update_usage_history=128;
};//class ibp_sql_pobj_cache_manager

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms cfg*/}/*nms ibp*/}/*nms lcpi*/
#endif
