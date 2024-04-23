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

#include "source/external/icu/ibp_external__icu__loader.h"

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
class t_ibp_charset_manager_v2 LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_charset_manager_v2)
{
 private:
  using self_type=t_ibp_charset_manager_v2;

  t_ibp_charset_manager_v2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

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

  typedef ibp::external::icu::ICU__Loader                 icu_loader_type;
  typedef icu_loader_type::self_ptr                       icu_loader_ptr;

  typedef ibp::external::icu::ICU__Dll                    icu_dll_type;
  typedef ibp::external::icu::ICU__Dll_Ptr                icu_dll_ptr;

 public:
  const BYTE m_wchars_in_utf8_symbol;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pIcuLoader
  //!  Not null.
  //! \param[in] wchars_in_utf8_symbol
  t_ibp_charset_manager_v2(icu_loader_type* pIcuLoader,
                           BYTE             wchars_in_utf8_symbol);

  /// <summary>
  ///  Регистрация идентификатора кодовой страницы
  /// </summary>
  //! \param[in] cs_id
  //! \param[in] cs_name
  void reg_cs_id_name(db_obj::db_cs_id        cs_id,
                      const cs_name_box_type& cs_name);

  //t_db_charset_manager_v2 interface ------------------------------------
  virtual db_obj::t_db_charset_const_ptr get_charset(const cs_name_box_type&   cs_name,
                                                     db_obj::t_db_cs_mng_flags flags) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual db_obj::t_db_charset_const_ptr get_charset(db_obj::db_cs_id cs_id) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

 private:
  using cs_map_type
   =structure::t_tree_avl
     <db_obj::t_db_charset_const_ptr,
      db_obj::t_db_charset::tag_less_by_name,
      db_obj::t_db_memory_allocator>;

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
  //! \param[in] pICUUC_DLL
  static charsets::t_ibp_charset_provider_ptr
   helper__create_icu_provider(icu_dll_type* pICUUC_DLL);

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
  using locale_services_ptr
   =ibp::t_ibp_locale_services::self_ptr;

 private:
  const locale_services_ptr m_spStdLocaleC;

 private:
  ///Внешняя ICU библиотека
  const icu_loader_ptr     m_spIcuLoader;

  ///Объект синхронизации доступа к собственным данным менеджера
  guard_type               m_guard;

  ///Созданные объекты кодовых страниц
  cs_map_type              m_cache;

  ///Указатель на провайдер ICU
  charsets::t_ibp_charset_provider_ptr m_icu_provider;

  ///Отображение cs_id на кодовую страницу
  std::array<db_obj::t_db_charset_const_ptr,5> m_cs_id_names;
};//class t_ibp_charset_manager_v2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
