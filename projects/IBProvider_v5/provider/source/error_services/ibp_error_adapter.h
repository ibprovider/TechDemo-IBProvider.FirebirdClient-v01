////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_adapter.h
//! \brief   Класс для трансформации ошибок
//! \author  Kovalenko Dmitry
//! \date    03.06.2010
#ifndef _ibp_error_adapter_H_
#define _ibp_error_adapter_H_

#include "source/error_services/ibp_error_codes.h"
#include <structure/t_str_parameter.h>

#include <lcpi/lib/structure/error/t_err_records_r.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class t_ibp_error_adapter;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_adapter

/// <summary>
///  Класс для трансформации ошибок
/// </summary>
//!  Абстрактный метод:
//!  - push_error
class t_ibp_error_adapter
{
 private:
  using self_type=t_ibp_error_adapter;

  t_ibp_error_adapter(const self_type&) COMP_W000002_COPY_CTOR_IMPL
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef ibp_msg_code_type                            mc_type;

  typedef lib::structure::t_err_record                 base_error_record_type;

  typedef structure::t_str_parameter<char>             str_arg_type;

  typedef std::uint64_t                                uint64_type;

 public: //---------------------------------------------------------------
  /// <summary>
  ///  Конструктор по умолчанию
  /// </summary>
  t_ibp_error_adapter();

 protected:
  /// <summary>
  ///  Деструктор
  /// </summary>
  //! В принципе, виртуальность здесь лишняя. Но мы оставим её на всякий случай.
  virtual ~t_ibp_error_adapter();

 public: //добавление ошибок
  void add(const std::exception& exc);

  void add(HRESULT err_code);

  void add(HRESULT err_code,str_arg_type msg);

  void add(base_error_record_type* pErrorRecord);

 public:
  void add__no_throw(const std::exception& exc);

 public:
  void add(mc_type               mc_id_2,
           uint64_type           num,
           const std::exception& exc);

  void add(mc_type          mc_id_2,
           uint64_type      num,
           HRESULT          err_code);

  void add(mc_type          mc_id_2,
           uint64_type      num,
           HRESULT          err_code,
           str_arg_type     msg);

 public:
  /// <summary>
  ///  Обработка ошибки ряда. Вызывается из catch-секции
  /// </summary>
  //! \param[in] mc_id_3
  //! \param[in] num
  //! \param[in] RowStatus
  void catch_row_error(mc_type     mc_id_3,
                       uint64_type num,
                       DBROWSTATUS RowStatus);

 private:
  void add_row_error(mc_type               mc_id_3,
                     uint64_type           num,
                     DBROWSTATUS           RowStatus,
                     const std::exception& exc);

  void add_row_error(mc_type          mc_id_3,
                     uint64_type      num,
                     DBROWSTATUS      RowStatus,
                     HRESULT          err_code);

  void add_row_error(mc_type          mc_id_3,
                     uint64_type      num,
                     DBROWSTATUS      RowStatus,
                     HRESULT          err_code,
                     str_arg_type     msg);

 private:
  void helper__push_ibp_error_ex
        (mc_type                                mc_id_2,
         uint64_type                            num,
         const lib::structure::t_err_records_r* recs);

 private:
  void helper__push_row_ibp_error_ex
        (mc_type                                mc_id_3,
         uint64_type                            num,
         DBROWSTATUS                            RowStatus,
         const lib::structure::t_err_records_r* recs);

 protected:
  virtual void push_error(base_error_record_type* pError)=0;
};//class t_ibp_error_adapter

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
