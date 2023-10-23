////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_locale_services.h
//! \brief   ����� ������ ��� ������ � ��������
//! \author  Kovalenko Dmitry
//! \date    03.11.2009
#ifndef _ibp_locale_services_H_
#define _ibp_locale_services_H_

#include "source/ibp_memory.h"
#include "source/ibp_char.h"

#include <structure/t_char_traits2.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_basic_locale_services

/// <summary>
///  ����� ������ ��� ������ � �������
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
  using self_ptr=lib::structure::t_smart_object_ptr<const self_type>;

  typedef charT                                              char_type;
  typedef __STL_DEF_BASIC_STRING(char_type)                  string_type;
  typedef size_t                                             size_type;

  typedef structure::t_char_traits2<charT>                   char_traits2;

 public:
  /// <summary>
  ///  ����������� �������������
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
  //!  ��������� �����
  //! \param[in] s1
  //! \param[in] s2
  //! \return
  //!  <0, 0, >0
  int string_compare_i(const string_type& s1,
                       const string_type& s2)const;

  //! \brief
  //!  ��������� �����
  //! \param[in] s1
  //! \param[in] n1
  //! \param[in] s2
  //! \param[in] n2
  //! \return
  //!  <0, 0, >0
  //! \note
  //!  ���� [s1,n1], [s2,n2] ������ ���� ����������� ����������� �����.
  //!  ����� �� ������������ ������������� NULL-���������� � ����� ������ -1.
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

typedef t_ibp_basic_locale_services<char>               t_ibp_ansi_locale_services;

typedef t_ibp_basic_locale_services<wchar_t>            t_ibp_unicode_locale_services;

typedef t_ibp_basic_locale_services<t_ibp_char>         t_ibp_locale_services;

typedef t_ibp_basic_locale_services<structure::t_char>  t_ibp_sys_locale_services;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_basic_equal_char_i

/// <summary>
///  ������� ��� ��������� �������� ��� ����� ��������
/// </summary>
template<typename charT>
class t_ibp_basic_equal_char_i LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef t_ibp_basic_equal_char_i<charT>               self_type;

 public: //typedefs ------------------------------------------------------
  typedef charT                                         char_type;

  typedef t_ibp_basic_locale_services<char_type>        locale_services_type;
  typedef typename locale_services_type::self_ptr       locale_services_ptr;

 public:
  //! \brief
  //!  ����������� �������������
  //! \param[in] pLocaleServices
  //!  Not NULL
  explicit t_ibp_basic_equal_char_i(const locale_services_type* pLocaleServices);

  //! \brief
  //!  ����������
 ~t_ibp_basic_equal_char_i();

  //! \brief
  //!  ��������� ��������. ������� ������������
  //! \param[in] c1
  //! \param[in] c2
  //! \return
  //!  true, ���� ������� ������������
  bool operator () (char_type c1,char_type c2)const;

 private:
  /// ��������� �� ��������� ������ ������
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
