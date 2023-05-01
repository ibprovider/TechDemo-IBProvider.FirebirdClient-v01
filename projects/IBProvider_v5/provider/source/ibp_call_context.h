////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_call_context.h
//! \brief   Контекст вызова
//! \author  Kovalenko Dmitry
//! \date    04.04.2018
#ifndef _ibp_call_context_H_
#define _ibp_call_context_H_

#include "source/error_services/ibp_error_adapter.h"
#include "source/error_services/ibp_error_elements.h"
#include "source/ibp_limits.h"
#include "source/ibp_forward.h"

#include <ole_lib/ole_lib__base_unknown2.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//!  @{
////////////////////////////////////////////////////////////////////////////////
//Contains

class IBP_CallContext;

////////////////////////////////////////////////////////////////////////////////
//class IBP_CallContext

/// <summary>
///  Контекст вызова.
/// </summary>
class IBP_CallContext LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef IBP_CallContext                   self_type;

  IBP_CallContext(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_err_record           error_record_type;
  typedef error_record_type::self_ptr       error_record_ptr;

  typedef t_ibp_error_adapter               errors_type;

#ifdef IBP_BUILD_TESTCODE
 public:
#else
 private:
#endif
  class tag_error_adapter;
  class tag_error_adapter_with_limit;

  enum
  {
   ///Максимальное количество ошибок, добавляемых через tag_error_adapter_with_limit.
   c_max_error_count=ibp_limc_MaxErrorCountInBulkOperation,
  };

 public:
  /// <summary>
  ///  Конструктор инициализации. NO THROW.
  /// </summary>
  //! \param[in] pCallEntryObject
  //!  Not null.
  explicit IBP_CallContext(ole_lib::TBaseUnknown2* pCallEntryObject);

  /// <summary>
  ///  Деструктор. NO THROW [AS EXPECTED].
  /// </summary>
 ~IBP_CallContext();

 public: //interface -----------------------------------------------------
  ole_lib::TBaseUnknown2* GetCallEntryObject()const;

  /// <summary>
  ///  Доступ к ошибкам.
  /// </summary>
  tag_error_adapter Errors();

  /// <summary>
  ///  Доступ к ошибкам с ограничением на количество.
  /// </summary>
  tag_error_adapter_with_limit ErrorsWithLimit();

  /// <summary>
  ///  Обрабатываем текущее исключение.
  /// </summary>
  HRESULT ProcessCurrentException_NoThrow();

  /// <summary>
  ///  Создание и регистрация объекта с описанием ошибки.
  /// </summary>
  //! \param[in] providerClassID
  //! \param[in] exc_iid
  void SetErrorInfo_NoThrow(REFCLSID providerClassID,
                            REFIID   exc_iid)const;

 private:
  typedef structure::t_value_with_null
           <size_t>                         size_type_N;

  class tag_errors_accessor;

 private:
  void Helper__AddErrRecord(error_record_type* record);
  
  void Helper__AddErrLimit();

  void Helper__SetLastErrorAsPrimary();

  HRESULT Helper__ProcessCurrentException_NoThrow(const std::exception* pExc);

  void Helper__ProcessCurrentException(const std::exception* pExc);

 private:
  ole_lib::TBaseUnknown2* const m_pCallEntryObject;

#ifdef IBP_BUILD_TESTCODE
 public:
#else
 private:
#endif
  ///Ошибки и предупреждения вызова
  t_ibp_error_elements m_errors;

  ///Индекс главной ошибки, которая будет выводится через интерфейс IErrorInfo
  size_type_N m_primary_err_idx;
};//class IBP_CallContext

////////////////////////////////////////////////////////////////////////////////
//class IBP_CallContext::tag_error_adapter

class IBP_CallContext::tag_error_adapter LCPI_CPP_CFG__CLASS__FINAL
 :public t_ibp_error_adapter
{
 private:
  typedef tag_error_adapter                 self_type;

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef t_ibp_data_settings               ds_type;

 public:
  tag_error_adapter(const self_type&);

  explicit tag_error_adapter(IBP_CallContext* pCallContext);

 ~tag_error_adapter();

 public:
  void add_summary_error(mc_type        mc_id_2,
                         uint64_type    cErrors,
                         uint64_type    cTotal,
                         HRESULT        err_code);

 private:
  virtual void push_error(structure::t_err_record* err_record)COMP_W000004_OVERRIDE_FINAL;

 private:
  IBP_CallContext* m_pCallContext;
};//class IBP_CallContext::tag_error_adapter

////////////////////////////////////////////////////////////////////////////////
//class IBP_CallContext::tag_error_adapter_with_limit

class IBP_CallContext::tag_error_adapter_with_limit LCPI_CPP_CFG__CLASS__FINAL
 :public t_ibp_error_adapter
{
 private:
  typedef tag_error_adapter_with_limit                 self_type;

  self_type& operator = (const self_type&);

 public:
  tag_error_adapter_with_limit(const self_type&);

  explicit tag_error_adapter_with_limit(IBP_CallContext* pCallContext);

 ~tag_error_adapter_with_limit();

 private:
  virtual void push_error(structure::t_err_record* err_record)COMP_W000004_OVERRIDE_FINAL;

 private:
  IBP_CallContext* m_pCallContext;
};//class IBP_CallContext::tag_error_adapter_with_limit

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
