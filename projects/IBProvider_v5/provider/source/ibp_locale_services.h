////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_locale_services.h
//! \brief   Набор утилит для работы с локалями
//! \author  Kovalenko Dmitry
//! \date    03.11.2009
#ifndef _ibp_locale_services_H_
#define _ibp_locale_services_H_

#include "source/ibp_memory.h"
#include "source/ibp_char.h"

#include <lcpi/lib/structure/t_char_traits2.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_basic_locale_services

/// <summary>
///  Набор утилит для работы с локалью
/// </summary>
template<typename charT>
class t_ibp_basic_locale_services LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_SmartMemoryObject
{
 private:
  using self_type=t_ibp_basic_locale_services;

  t_ibp_basic_locale_services(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~t_ibp_basic_locale_services();

 public: //typedefs ------------------------------------------------------
  using self_ptr     =lib::structure::t_smart_object_ptr<const self_type>;

  using char_type    =charT;
  using string_type  =LCPI_STL_DEF_BASIC_STRING(char_type);
  using size_type    =size_t;

  using char_traits2 =lib::structure::t_char_traits2<charT>;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// <summary>
  t_ibp_basic_locale_services();

  //interface ------------------------------------------------------------
  bool isalpha(char_type c)const;

  bool isalnum(char_type c)const;

  bool isdigit(char_type c)const;

 public:
  char_type toupper_char(char_type c)const;

  void toupper_str(string_type* pstr)const;

 public:
  char_type tolower_char(char_type c)const;

  void tolower_str(string_type* str)const;

 public:
  int char_compare_i(char_type c1,
                     char_type c2)const;

 public:
  //! \brief
  //!  Сравнение строк
  //! \param[in] s1
  //! \param[in] s2
  //! \return
  //!  <0, 0, >0
  int string_compare_i(const string_type& s1,
                       const string_type& s2)const;

  //! \brief
  //!  Сравнение строк
  //! \param[in] s1
  //! \param[in] n1
  //! \param[in] s2
  //! \param[in] n2
  //! \return
  //!  <0, 0, >0
  //! \note
  //!  Пары [s1,n1], [s2,n2] должны быть корректными описателями строк.
  //!  Метод не осуществляет распознование NULL-указателей и длины равной -1.
  int string_compare_i(const char_type* s1,
                       size_type        n1,
                       const char_type* s2,
                       size_type        n2)const;

 public:
  bool eq_to_char_i(char_type c1,
                    char_type c2)const;

 public:
  bool eq_to_str_i(const char_type* s1,
                   size_type        n1,
                   const char_type* s2)const;

  bool eq_to_str_i(const char_type* s1,
                   const char_type* s2)const;

  template<typename Iterator>
  bool eq_to_str_i(Iterator         first1,
                   Iterator         last1,
                   const char_type* s2)const;
};//class t_ibp_basic_locale_services

////////////////////////////////////////////////////////////////////////////////
//typedefs

using t_ibp_ansi_locale_services    =t_ibp_basic_locale_services<char>;

using t_ibp_unicode_locale_services =t_ibp_basic_locale_services<wchar_t>;

using t_ibp_locale_services         =t_ibp_basic_locale_services<t_ibp_char>;

using t_ibp_sys_locale_services     =t_ibp_basic_locale_services<structure::t_char>;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_basic_equal_char_i

/// <summary>
///  Функтор для сравнения символов без учета регистра
/// </summary>
template<typename charT>
class t_ibp_basic_equal_char_i LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_ibp_basic_equal_char_i<charT>;

 public: //typedefs ------------------------------------------------------
  using char_type=charT;

  using locale_services_type =t_ibp_basic_locale_services<char_type>;
  using locale_services_ptr  =typename locale_services_type::self_ptr;

 public:
  //! \brief
  //!  Конструктор инициализации
  //! \param[in] pLocaleServices
  //!  Not NULL
  explicit t_ibp_basic_equal_char_i(const locale_services_type* pLocaleServices);

  //! \brief
  //!  Деструктор
 ~t_ibp_basic_equal_char_i();

  //! \brief
  //!  Сравнение символов. Регистр игнорируется
  //! \param[in] c1
  //! \param[in] c2
  //! \return
  //!  true, если символы эквивалентны
  bool operator () (char_type c1,char_type c2)const;

 private:
  /// Указатель на сервисный объект локали
  locale_services_ptr m_spLocaleServices;
};//t_ibp_basic_equal_char_i

////////////////////////////////////////////////////////////////////////////////

t_ibp_locale_services::self_ptr IBP_GetStdLocaleC();

t_ibp_sys_locale_services::self_ptr IBP_GetSysLocaleC();

t_ibp_ansi_locale_services::self_ptr IBP_GetAnsiLocaleC();

t_ibp_unicode_locale_services::self_ptr IBP_GetUnicodeLocaleC();

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/ibp_locale_services.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
