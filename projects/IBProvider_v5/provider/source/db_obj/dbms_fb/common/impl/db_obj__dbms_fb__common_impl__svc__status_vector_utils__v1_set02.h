////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common_impl
//! \file    db_obj__dbms_fb__common_impl__svc__status_vector_utils__v1_set02.h
//! \brief   Базовая реализация сервиса для работы со статус вектором.
//! \author  Kovalenko Dmitry
//! \date    08.08.2016
#ifndef _db_obj__dbms_fb__common_impl__svc__status_vector_utils__v1_set02_H_
#define _db_obj__dbms_fb__common_impl__svc__status_vector_utils__v1_set02_H_

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common__svc__status_vector_utils.h"
#include "source/db_obj/isc_base/isc_error_code_descr2.h"
#include "source/db_obj/db_charset_manager_v2.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{namespace impl{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__common_impl
//! @{
////////////////////////////////////////////////////////////////////////////////
//class fb_common_impl__svc__status_vector_utils__v1_set02

/// <summary>
///  Базовая реализация сервиса для работы со статус вектором.
/// </summary>
class fb_common_impl__svc__status_vector_utils__v1_set02
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(common::fb_common__svc__status_vector_utils)
{
 private:
  using self_type=fb_common_impl__svc__status_vector_utils__v1_set02;

  fb_common_impl__svc__status_vector_utils__v1_set02(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  /// Максимально ожидаемое количество аргументов сообщения об ошибке.
  static const size_t c_max_expected_args_count=10;

 protected:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] cErrDescrs
  //! \param[in] pErrDescrs
  //! \param[in] pCsMng
  //!  Not NULL.
  fb_common_impl__svc__status_vector_utils__v1_set02
   (size_t                                   cErrDescrs,
    const isc_base::t_isc_error_code_descr2* pErrDescrs,
    db_obj::t_db_charset_manager_v2*         pCsMng);

  /// <summary>
  ///  Деструктор.
  /// </summary>
 ~fb_common_impl__svc__status_vector_utils__v1_set02();

 public:
  //interface ------------------------------------------------------------
  /// <summary>
  ///  Получение описания ISC-ошибки
  /// </summary>
  //! \param[in] status
  //! \return
  //!  NULL, если описание не найдено.
  virtual const descr2_type* get_err_descr2(status_type status)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Отображения status_vector на SQLSTATE code.
  /// </summary>
  //! \param[in] sv_beg
  //! \param[in] sv_end
  //! \param[out] sqlstate
  //!  Not null.
  //! \return
  //!  Result code.
  virtual gresult_data_type get_sqlstate(const status_type* sv_beg,
                                         const status_type* sv_end,
                                         std::string*       sqlstate)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Получение кода основной ошибки.
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] general_error_code
  //!  Not null.
  //! \return
  //!  Result data.
  virtual gresult_data_type get_general_error(const status_type* sv_beg,
                                              const status_type* sv_end,
                                              status_type*       general_error_code)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Получение кода ошибки.
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] error_code
  //!  Not null.
  //! \return
  //!  Result data.
  virtual gresult_data_type get_error(const status_type* sv_beg,
                                      const status_type* sv_end,
                                      status_type*       error_code)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Формирование текста ошибки.
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] message
  //!  Not null.
  //! \param[in]  lcid
  //! \return
  //!  Result data.
  virtual gresult_data_type get_message(const status_type* sv_beg,
                                        const status_type* sv_end,
                                        std::wstring*      message,
                                        LCID               lcid)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Вычисление размера косвенных данных статус вектора
  /// </summary>
  //! \param[in]  sv_beg
  //! \param[in]  sv_end
  //! \param[out] sv_info__num_of_elements
  //!  Количество актуальных элементов. Not null.
  //! \param[out] sv_info__indirect_data_size
  //!  Размер косвенных данных статус вектора. Not null.
  //! \return
  //!  Result data.
  virtual gresult_data_type get_sv_info(const status_type* sv_beg,
                                        const status_type* sv_end,
                                        size_t*            sv_info__num_of_elements,
                                        size_t*            sv_info__indirect_data_size)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Перемещение косвенных данных в буфер.
  /// </summary>
  //! \param[in] sv_beg
  //! \param[in] sv_end
  //! \param[in] buf_beg
  //! \param[in] buf_end
  //! \return
  //!  Result data.
  virtual gresult_data_type move_indirect_data_to_buf
                                      (status_type*       sv_beg,
                                       const status_type* sv_end,
                                       void*              buf_beg,
                                       const void*        buf_end)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 protected:
  enum class arg_cs_kind
  {
   connection,
   metadata,
   system,
  };//enum class arg_cs_kind

 private:
  using args_type
   =structure::t_stl_vector<IBP_ErrorVariant,db_obj::t_db_memory_allocator>;

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
                    const IBP_ErrorVariant*     rgArgs)const=0;

  virtual bool internal__is_useless_error_code
                   (const status_type s)const=0;


  virtual status_type internal__get_unexpected_error_code()const=0;

  virtual arg_cs_kind internal__get_cs_for_arg
                   (status_type iscErrorCode,
                    size_t      argNumber)const=0;

 private:
  /// <summary>
  ///  Получение описания ISC-ошибки. Реализация.
  /// </summary>
  //! \param[in] status
  //! \return
  //!  NULL, если описание не найдено.
  const descr2_type*
   helper__get_err_descr2(status_type status)const;

 private:
  using find_next_result_type
   =std::pair<const status_type*,gresult_data_type>;

  /// <summary>
  ///  Утилита для поиска следующего элемента статус вектора
  /// </summary>
  //! \param[in] cur_sv
  //! \param[in] end_sv
  static find_next_result_type
   helper__find_next_status_vector_element(const status_type* cur_sv,
                                           const status_type* end_sv);

  /// <summary>
  ///  Тестирование ошибки на принадлежность категории "общих"
  /// </summary>
  //! \param[in] err_descr2
  //!  Not NULL
  static bool
   helper__is_common_error_code(const descr2_type* const err_descr2);

#ifdef IBP_BUILD_TESTCODE
 public:
#else
 private:
#endif
  /// <summary>
  ///  Трансляция логической единицы статус-вектора
  /// </summary>
  //! \param[in]  pps
  //! \param[in]  sv_end
  //! \param[out] msg_part
  //!  Not null.
  //! \param[in]  lcid
  //! \return
  //!  Result data.
  gresult_data_type helper__translate_msg_part
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid)const;

  /// <summary>
  ///  Трансляция isc_arg_end.
  /// </summary>
  static gresult_data_type helper__translate_msg_part__arg_end
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part);

  /// <summary>
  ///  Трансляция isc_arg_sql_state.
  /// </summary>
  static gresult_data_type helper__translate_msg_part__arg_sql_state
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part);

  /// <summary>
  ///  Трансляция isc_arg_interpreted.
  /// </summary>
  gresult_data_type helper__translate_msg_part__arg_interpreted
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid)const;

  /// <summary>
  ///  Трансляция isc_arg_dos.
  /// </summary>
  static gresult_data_type helper__translate_msg_part__arg_dos
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid);

  /// <summary>
  ///  Трансляция isc_arg_next_mach.
  /// </summary>
  static gresult_data_type helper__translate_msg_part__arg_next_mach
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid);

  /// <summary>
  ///  Трансляция isc_arg_unix.
  /// </summary>
  static gresult_data_type helper__translate_msg_part__arg_unix
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid);

  /// <summary>
  ///  Трансляция isc_arg_win32.
  /// </summary>
  static gresult_data_type helper__translate_msg_part__arg_win32
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid);

  /// <summary>
  ///  Трансляция isc_arg_gds.
  /// </summary>
  gresult_data_type helper__translate_msg_part__arg_gds
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid)const;

  /// <summary>
  ///  Трансляция isc_arg_warning.
  /// </summary>
  gresult_data_type helper__translate_msg_part__arg_warning
                                           (const status_type** pps,
                                            const status_type*  sv_end,
                                            std::wstring*       msg_part,
                                            LCID                lcid)const;
 private:
  /// <summary>
  ///  Вспомогательная функция для получения текста ошибки UNIX
  /// </summary>
  //! \param[in]  errnum
  //! \param[out] msg
  //!  Not null
  //! \return
  //!  true, если функция отработала без ошибок.
  static bool helper__get_unix_error_msg(int           errnum,
                                         std::wstring* msg);

  /// <summary>
  ///  Вспомогательная функция для получения текста ошибки WIN32
  /// </summary>
  //! \param[in]  errnum
  //! \param[out] msg
  //!  Not null
  //! \param[in]  lcid
  //! \return
  //!  true, если функция отработала без ошибок.
  static bool helper__get_win32_error_msg(DWORD         errnum,
                                          std::wstring* msg,
                                          LCID          lcid);

 private:
  /// <summary>
  ///  Формирование списка аргументов ошибки/предупреждения
  /// </summary>
  gresult_data_type helper__get_args(status_type         iscErrorCode,
                                     const status_type** pps,
                                     const status_type*  sv_end,
                                     args_type&          args)const;

 private:
  using str_box_type  =lib::structure::t_const_str_box;
  using wstr_box_type =lib::structure::t_const_wstr_box;

  std::wstring helper__encode_str_arg
                        (status_type    iscErrorCode,
                         size_t         argNumber,
                         str_box_type   strArg)const;

  static std::wstring helper__build_str_raw_info
                        (wstr_box_type expectedCsName,
                         str_box_type  strArg);

 private:
  size_t                                   const m_cErrDescrs;
  const isc_base::t_isc_error_code_descr2* const m_pErrDescrs;
  db_obj::t_db_charset_manager_v2_ptr      const m_spCsMng;
};//class fb_common_impl__svc__status_vector_utils__v1_set02

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms impl*/}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
