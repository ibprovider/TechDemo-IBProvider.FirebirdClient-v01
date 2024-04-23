////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_collection.h
//! \brief   ����� ��� �������� ��������� ������
//! \author  Kovalenko Dmitry
//! \date    18.02.2003
#ifndef _ibp_error_collection_H_
#define _ibp_error_collection_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error_adapter.h"
#include "source/error_services/ibp_error_elements.h"
#include "source/error_services/ibp_error_records_r.h"
#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class t_ibp_error_collection;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_collection

/// <summary>
///  ����� ��� �������� ��������� ������
/// </summary>
class t_ibp_error_collection LCPI_CPP_CFG__CLASS__FINAL
 :public t_ibp_error_adapter
 ,public t_ibp_error_records_r
{
 private:
  using self_type=t_ibp_error_collection;

  t_ibp_error_collection(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  /// <summary>
  ///  ����������� ��-���������
  /// </summary>
  t_ibp_error_collection();

  /// <summary>
  ///  ����������
  /// </summary>
 ~t_ibp_error_collection();

  //container interface --------------------------------------------------

  bool empty()const;

  //t_err_records_r interface --------------------------------------------

  /// <summary>
  ///  ��������� ���������� ������
  /// </summary>
  virtual size_t get_record_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL; //abstract

  /// <summary>
  ///  ��������� �������� ��������� ������
  /// </summary>
  //! \param[in] record_num
  virtual structure::t_err_record::self_ptr get_record(size_t record_num)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL; //abstract

  //t_ibp_error_records_r interface --------------------------------------

  /// <summary>
  ///  ��������� ������� ������� ������
  /// </summary>
  virtual size_type_N get_primary_err_idx()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual void push_error(base_error_record_type* pError) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;//abstract

 private:
  t_ibp_error_elements m_items;

  ///������ ������� ������, ������� ����� ��������� ����� ��������� IErrorInfo
  size_type_N m_primary_err_idx;
};//class t_ibp_error_collection

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_collection

inline bool t_ibp_error_collection::empty()const
{
 return m_items.empty();
}//empty

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
