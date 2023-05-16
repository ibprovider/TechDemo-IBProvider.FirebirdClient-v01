////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__svc__status_vector_utils.h
//! \brief   Реализация сервиса для работы со статус вектором.
//! \author  Kovalenko Dmitry
//! \date    07.08.2016
#ifndef _db_obj__dbms_fb__v03_0_0__svc__status_vector_utils_H_
#define _db_obj__dbms_fb__v03_0_0__svc__status_vector_utils_H_

#include "source/db_obj/dbms_fb/common/impl/db_obj__dbms_fb__common_impl__svc__status_vector_utils__v1_set02.h"
#include "source/ibp_resources.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__v03_0_0
//! @{
////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__svc__status_vector_utils

class fb_v03_0_0__svc__status_vector_utils LCPI_CPP_CFG__CLASS__FINAL
 :public common::impl::fb_common_impl__svc__status_vector_utils__v1_set02
{
 private:
  typedef fb_v03_0_0__svc__status_vector_utils                               self_type;
  typedef common::impl::fb_common_impl__svc__status_vector_utils__v1_set02   inherited;

  fb_v03_0_0__svc__status_vector_utils(const self_type&);
  self_type& operator = (const self_type&);

 private:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  fb_v03_0_0__svc__status_vector_utils();

  /// <summary>
  ///  Деструктор.
  /// </summary>
 ~fb_v03_0_0__svc__status_vector_utils();

 public:

  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  static common::fb_common__svc__status_vector_utils_ptr create();

 private:
  /// <summary>
  ///  Формирование текста ошибки
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  msg_code
  //! \param[in]  lcid
  //! \param[in]  cArgs
  //! \param[in]  rgArgs
  virtual void internal__build_err_message
                   (std::wstring*               pResultText,
                    DWORD                       msg_code,
                    LCID                        lcid,
                    size_t                      cArgs,
                    const IBP_ErrorVariant*     rgArgs)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool internal__is_useless_error_code
                   (const status_type s)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;


  virtual status_type internal__get_unexpected_error_code()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TIBP_MsgTableLoader m_ErrMsgTableLoader;

 private:
  /// Единственный экземпляр класса
  static self_type sm_Instance;
};//class fb_v03_0_0__svc__status_vector_utils

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
