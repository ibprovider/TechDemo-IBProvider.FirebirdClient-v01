////////////////////////////////////////////////////////////////////////////////
//Вспомогательные класс для реализации t_basic_string_formatter
//                                        Коваленко Дмитрий. 8 января 2002 года.
#ifndef _lcpi_lib_structure__t_str_formatter_traits_H_
#define _lcpi_lib_structure__t_str_formatter_traits_H_

#include <structure/t_str_args_traits.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing

template<class charT>
struct t_str_formatter_traits;

template<>
struct t_str_formatter_traits<char>;

template<>
struct t_str_formatter_traits<wchar_t>;

////////////////////////////////////////////////////////////////////////////////
//template class t_str_formatter_traits

template<class charT>
struct t_str_formatter_traits
{
 public: //typedefs ------------------------------------------------------
  using char_type=charT;
};//template class t_str_formatter_traits

////////////////////////////////////////////////////////////////////////////////
//struct t_str_formatter_traits<char>

template<>
struct t_str_formatter_traits<char> LCPI_CPP_CFG__CLASS__FINAL
 :public t_str_args_traits<char>
{
 private:
  using inherited=t_str_args_traits<char>;

 public: //typedefs ------------------------------------------------------
  using char_type   = inherited::char_type;
  using string_type = inherited::string_type;
  using size_type   = inherited::size_type;

 public: //members -------------------------------------------------------
  static char_type arg_prefix()
   {return '%';}

  static bool is_digit(char_type const c)
   {return c>='0' && c<='9';}

  static bool is_first_named_arg_char(char_type const c)
   {return c=='_' || (c>='a' && c<='z') || (c>='A' && c<'Z');}

  static bool is_second_named_param_char(char_type const c)
   {return is_first_named_arg_char(c) || is_digit(c);}

  static bool is_mult_arg_char(char_type const c)
   {return c=='*';}

  //call for no defined argument
  static string_type no_defined(const string_type& arg)
   {return arg_prefix()+arg;}

  static size_type length(const char_type* const str)
   {return str?strlen(str):0;}
};//struct t_str_formatter_traits<char>

////////////////////////////////////////////////////////////////////////////////
//struct t_str_formatter_traits<wchar_t>

template<>
struct t_str_formatter_traits<wchar_t> LCPI_CPP_CFG__CLASS__FINAL
 :public t_str_args_traits<wchar_t>
{
 private:
  using inherited=t_str_args_traits<wchar_t>;

 public: //typedefs ------------------------------------------------------
  using char_type   = inherited::char_type;
  using string_type = inherited::string_type;
  using size_type   = inherited::size_type;

 public: //members -------------------------------------------------------
  static char_type arg_prefix()
   {return L'%';}

  static bool is_digit(char_type const c)
   {return c>=L'0' && c<=L'9';}

  static bool is_first_named_arg_char(char_type const c)
   {return c==L'_' || (c>=L'a' && c<=L'z') || (c>=L'A' && c<L'Z');}

  static bool is_second_named_param_char(char_type const c)
   {return is_first_named_arg_char(c) || is_digit(c);}

  static bool is_mult_arg_char(char_type const c)
   {return c==L'*';}

  //call for no defined argument
  static string_type no_defined(const string_type& arg)
   {return arg_prefix()+arg;}

  static size_type length(const char_type* const str)
   {return str?wcslen(str):0;}
};//struct t_str_formatter_traits<wchar_t>

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
