////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_limits
//! \file    ibp_cfg_structure.h
//! \brief   ����������� ���������������� ���������� IBProvider-�
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
///  ����������� ������������ ������� ����������� ��������, ������������ �����������.
/// </summary>
const DBLENGTH ibp_self_bookmark_max_size=IBP_ENGINE_BMK_SIZE;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������ ���������� ���� ����������.
/// </summary>
const DBLENGTH ibp_meta_obj_name_max_len=128;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������ ���� � ����� � EXTERNAL TABLE. ������������ � ����������.
/// </summary>
const DBLENGTH ibp_meta_external_file_path_max_len=512;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ����� ��������� �������. ������������ ��� ��������� ������.
/// </summary>
const size_t ibp_cfg__max_stmt_sign_length=30;

////////////////////////////////////////////////////////////////////////////////
//class ibp_sql_pobj_cache

class ibp_sql_pobj_cache LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// <summary>
  ///  ������������ ���������� ����� ������� GC_TASK �� RC_TASK.
  /// </summary>
  static const unsigned max_failure_in_rc_task=10;
};//class ibp_sql_pobj_cache

////////////////////////////////////////////////////////////////////////////////
//class ibp_sql_pobj_cache_manager

class ibp_sql_pobj_cache_manager LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// <summary>
  ///  ������������ ���������� ����� ������� GC_TASK �� RC_TASK.
  /// </summary>
  static const unsigned max_failure_in_rc_task=10;

  /// <summary>
  ///  ��������� �������� ���������� ��������� � ibp_sql_parser__common__pobj_cache_manager,
  ///  ����� �������� get_pobj_cache �������� ��������� ������� ������������� (m_cache_list).
  /// </summary>
  ///
  /// �������� ����� �� �����.
  ///
  /// �������� �����.
  /// - ����������� � m_�ache_list ������� ���������� �������.
  ///
  /// - ��� ���������� ������ ������ RC_TASK - �� ���������� ������, ����� ����������
  ///   waiter-��. ��� �� ����� ��������� ��� ����������.
  ///
  /// - ��� ���������� ���������� ��������� ��� ������ ����� ������������ ������.
  ///
  /// - �������, ���� ����� ���������� ��������� ������ ����������, �� �� �����
  ///   ������ ������� ��������� � m_cache_list, ����� "������" RC_TASK ���������
  ///   ���������� �����.
  ///
  static const size_t treshold_count_for_update_usage_history=128;
};//class ibp_sql_pobj_cache_manager

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms cfg*/}/*nms ibp*/}/*nms lcpi*/
#endif
