////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_charset_manager_v2.h
//! \brief   Реализация интерфейса t_db_charset_manager_v2
//! \author  Kovalenko Dmitry
//! \date    05.10.2008
#ifndef _ibp_charset_manager_v2_H_
#define _ibp_charset_manager_v2_H_

#include "source/charsets/ibp_charset_provider.h"
#include "source/db_obj/db_charset_manager_v2.h"
#include "source/ibp_locale_services.h"
#include <structure/tree/t_tree_avl.h>

#include <array>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////

size_t ibp_get_count_of_connection_charsets();

const t_ibp_char* ibp_get_connection_charset_name(size_t index);

const t_ibp_char* const* ibp_get_charset_std_collations(const t_ibp_str_box& cset_name);

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_charset_manager_v2

/// <summary>
///  Реализация менеджера кодовых страниц
/// </summary>
class t_ibp_charset_manager_v2
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_charset_manager_v2)
{
 private:
  typedef t_ibp_charset_manager_v2                        self_type;

  t_ibp_charset_manager_v2(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_charset_manager_v2();

 public: //typedefs ------------------------------------------------------
  class tag_own_cs;

  class tag_aliase;
  class tag_aliase_less_by_name;

  typedef t_ibp_string                                    string_type;

  typedef const cs_name_box_type::value_type*             charset_name_ptr;

  typedef std::basic_string<cs_name_box_type::value_type> charset_name_type;

 public:
  const BYTE m_wchars_in_utf8_symbol;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] icu_library
  //! \param[in] wchars_in_utf8_symbol
  t_ibp_charset_manager_v2(const string_type&       icu_library,
                           BYTE                     wchars_in_utf8_symbol);

  /// <summary>
  ///  Регистрация идентификатора кодовой страницы
  /// </summary>
  //! \param[in] cs_id
  //! \param[in] cs_name
  void reg_cs_id_name(db_obj::db_cs_id        cs_id,
                      const cs_name_box_type& cs_name);

  //t_db_charset_manager_v2 interface ------------------------------------
  virtual db_obj::t_db_charset_const_ptr get_charset(const cs_name_box_type&   cs_name,
                                                     db_obj::t_db_cs_mng_flags flags) COMP_W000004_OVERRIDE_FINAL;

  virtual db_obj::t_db_charset_const_ptr get_charset(db_obj::db_cs_id cs_id) COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef structure::t_multi_thread_traits               thread_traits;
  typedef thread_traits::guard_type                      guard_type;
  typedef thread_traits::lock_guard_type                 lock_guard_type;

 private:
  typedef structure::t_tree_avl<db_obj::t_db_charset_const_ptr,
                                db_obj::t_db_charset::tag_less_by_name,
                                db_obj::t_db_memory_allocator>    cs_map_type;

 private:
  /// <summary>
  ///  Внутренняя реализация получения конвертора кодовой страницы
  /// </summary>
  //! \param[in] cs_name
  //!  Нормализованное имя кодовой страницы
  //! \param[in] flags
  //! \param[in] mce_unk_cs_1
  //!  Идентификатор шаблона ошибки "Неизвестная кодовая страница"
  db_obj::t_db_charset_const_ptr
   helper__get_charset(const charset_name_type&  cs_name,
                       db_obj::t_db_cs_mng_flags flags,
                       ibp_msg_code_type         mce_unk_cs_1);

  db_obj::t_db_charset_const_ptr
   helper__get_charset(const charset_name_type& cs_name,
                       ibp_msg_code_type        mce_unk_cs_1);

  /// <summary>
  ///  Создание объекта для внешней кодовой страницы
  /// </summary>
  //! \param[in] cs_name
  //! \return
  //!  Can be NULL
  db_obj::t_db_charset_const_ptr
   helper__create_icu_charset(const cs_name_box_type& cs_name);

  /// <summary>
  ///  Создание ICU провайдера
  /// </summary>
  void helper__create_icu_provider();

  /// <summary>
  ///  Транслирование имени кодовой страницы пользователя
  /// </summary>
  //! \param[in] user_cs_name
  //! \param[in] mce_1
  //!  Шаблон ошибки о невозможности трансляции user_cs_name
  charset_name_type
   helper__translate_user_cs_name(const cs_name_box_type& user_cs_name,
                                  ibp_msg_code_type       mce_1)const;

  /// <summary>
  ///  Нормализация имени кодовой страницы
  /// </summary>
  //! \param[in] cs_name
  //! \param[in] process_empty_name
  charset_name_type
   helper__make_std_cs_name(const cs_name_box_type& cs_name,
                            bool                    process_empty_name)const;

 private:
  typedef ibp::t_ibp_locale_services::self_ptr local_services_ptr;

 private:
  const local_services_ptr m_spStdLocaleC;

 private:
  ///Внешняя ICU библиотека
  const string_type       m_icu_library;

  ///Объект синхронизации доступа к собственным данным менеджера
  guard_type              m_guard;

  ///Созданные объекты кодовых страниц
  cs_map_type             m_cache;

  ///Указатель на провайдер ICU
  charsets::t_ibp_charset_provider_ptr m_icu_provider;

  ///Отображение cs_id на кодовую страницу
  std::array<db_obj::t_db_charset_const_ptr,4> m_cs_id_names;
};//class t_ibp_charset_manager_v2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
