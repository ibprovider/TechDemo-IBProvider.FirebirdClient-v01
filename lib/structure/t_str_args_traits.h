////////////////////////////////////////////////////////////////////////////////
//Traits for convert several simple types to std::basic_string
//                                                 Dmitry Kovalenko. xx.04.2004
#ifndef _t_str_args_traits_H_
#define _t_str_args_traits_H_

#include <structure/t_char_converter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class charT>
class t_str_args_traits;

template<>
class t_str_args_traits<char>;

template<>
class t_str_args_traits<wchar_t>;

////////////////////////////////////////////////////////////////////////////////
//template class t_str_formatter_traits

template<class charT>
class t_str_args_traits
{
 public: //typedefs ------------------------------------------------------
  typedef charT                                           char_type;

  //BCB3 not define default template arguments
  typedef __STL_DEF_BASIC_STRING(char_type)               string_type;

  typedef typename string_type::size_type                 size_type;
};//template class t_str_formatter_traits

////////////////////////////////////////////////////////////////////////////////
//class t_str_args_traits<char>

template<>
class t_str_args_traits<char>
{
 private:
  typedef t_str_args_traits<char>                         self_type;

 public: //typedefs ------------------------------------------------------
  typedef char                                            char_type;

  //BCB3 not define default template arguments
  typedef __STL_DEF_BASIC_STRING(char_type)               string_type;

  typedef string_type::size_type                          size_type;

 public: //convert utility ------------------------------------------------
  static string_type arg_bool(bool value)
   {return value?"true":"false";}

  static string_type arg_int(signed int value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_itoa_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_int

  static string_type arg_uint(unsigned int value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ultoa_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_uint

  static string_type arg_long(signed long value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ltoa_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_long

  static string_type arg_ulong(unsigned long value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ultoa_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_ulong

  static string_type arg_int64(signed __int64 value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_i64toa_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_int64

  static string_type arg_uint64(unsigned __int64 value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ui64toa_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_uint64

  static string_type arg_float(float value)
   {
    char_type tmp[128];

    _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16lg",(double)value);

    return string_type(tmp);
   }//arg_float

  static string_type arg_double(double value)
   {
    char_type tmp[128];

    _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16lg",value);

    return string_type(tmp);
   }//arg_double

  static string_type arg_long_double(long double value)
   {
    char_type tmp[128];

    _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16Lg",value);

    return string_type(tmp);
   }//arg_long_double

  static string_type arg_str(const char* const value)
   {
    return basic_string_builder<string_type>::build(value);
   }//arg_str

  static string_type arg_str(const char* const s,size_type const n)
   {
    //this code has in basic_string_builder::build
    //n=((s==NULL)?0:((n==-1)?strlen(s):n));

    return basic_string_builder<string_type>::build(s,n);
   }//arg_str

  static const string_type& arg_str(const string_type& value)
   {
    return value;
   }//arg_str

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type&& arg_str(string_type&& value)
   {
    return __STL_MOVE_VALUE(value);
   }//arg_str
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  static string_type arg_str(const wchar_t* const value)
   {
    return unicode_to_ansi(value);
   }//arg_str

  static string_type arg_str(const wchar_t* const s,size_type const n)
   {
    return unicode_to_ansi(s,n);
   }//arg_str

  static string_type arg_str(const std::wstring& value)
   {
    return unicode_to_ansi(value);
   }//arg_str

 public: //generic -------------------------------------------------------
  static string_type arg(bool const value)
   {
    return self_type::arg_bool(value);
   }//arg

  static string_type arg(signed int value)
   {
    return self_type::arg_int(value);
   }//arg

  static string_type arg(unsigned int value)
   {
    return self_type::arg_uint(value);
   }//arg

  static string_type arg(signed long value)
   {
    return self_type::arg_long(value);
   }//arg

  static string_type arg(unsigned long value)
   {
    return self_type::arg_ulong(value);
   }//arg

  static string_type arg(signed __int64 value)
   {
    return self_type::arg_int64(value);
   }//arg

  static string_type arg(unsigned __int64 value)
   {
    return self_type::arg_uint64(value);
   }//arg

  static string_type arg(float value)
   {
    return self_type::arg_float(value);
   }//arg

  static string_type arg(double value)
   {
    return self_type::arg_double(value);
   }//arg

  static string_type arg(long double value)
   {
    return self_type::arg_long_double(value);
   }//arg

  static string_type arg(const wchar_t* const value)
   {
    return self_type::arg_str(value);
   }//arg

  static string_type arg(const wchar_t* const s,size_type const n)
   {
    return self_type::arg_str(s,n);
   }//arg

  static string_type arg(const std::wstring& value)
   {
    return self_type::arg_str(value);
   }//arg

  static string_type arg(const char* const value)
   {
    return self_type::arg_str(value);
   }//arg

  static string_type arg(const char* const s,size_type const n)
   {
    return self_type::arg_str(s,n);
   }//arg

  static const string_type& arg(const string_type& value)
   {
    return value;
   }//arg

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type&& arg(string_type&& value)
   {
    return __STL_MOVE_VALUE(value);
   }//arg
 #endif
};//class t_str_args_traits<char>

////////////////////////////////////////////////////////////////////////////////
//class t_str_args_traits<wchar_t>

template<>
class t_str_args_traits<wchar_t>
{
 private:
  typedef t_str_args_traits<wchar_t>                      self_type;

 public: //typedefs ------------------------------------------------------
  typedef wchar_t                                         char_type;

  typedef __STL_DEF_BASIC_STRING(char_type)               string_type;

  typedef string_type::size_type                          size_type;

 public: //convert utility ------------------------------------------------
  static string_type arg_bool(bool value)
   {return value?L"true":L"false";}

  static string_type arg_int(signed int value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_itow_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_int

  static string_type arg_uint(unsigned int value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ultow_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_uint

  static string_type arg_long(signed long value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ltow_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_long

  static string_type arg_ulong(unsigned long value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ultow_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_ulong

  static string_type arg_int64(signed __int64 value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_i64tow_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_int64

  static string_type arg_uint64(unsigned __int64 value)
   {
    char_type tmp[64];

    _VERIFY_EQ(_GCRT_ui64tow_s(value,tmp,_DIM_(tmp),10),0L);

    return string_type(tmp);
   }//arg_uint64

  static string_type arg_float(float value)
   {
    char_type tmp[128];

    _GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16lg",(double)value);

    return string_type(tmp);
   }//arg_double

  static string_type arg_double(double value)
   {
    char_type tmp[128];

    _GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16lg",value);

    return string_type(tmp);
   }//arg_double

  static string_type arg_long_double(long double value)
   {
    char_type tmp[128];

    _GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16Lg",value);

    return string_type(tmp);
   }//arg_long_double

  static string_type arg_str(const wchar_t* const value)
   {
    return basic_string_builder<string_type>::build(value);
   }//arg_str

  static string_type arg_str(const wchar_t* const s,size_type const n)
   {
    //this code has in basic_string_builder::build
    //n=((s==NULL)?0:((n==-1)?wcslen(s):n));

    return basic_string_builder<string_type>::build(s,n);
   }//arg_str

  static const string_type& arg_str(const string_type& value)
   {
    return value;
   }//arg_str

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type&& arg_str(string_type&& value)
   {
    return __STL_MOVE_VALUE(value);
   }//arg_str
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  static string_type arg_str(const char* const value)
   {
    return ansi_to_unicode(value);
   }//arg_str

  static string_type arg_str(const char* const s,size_type const n)
   {
    return ansi_to_unicode(s,n);
   }//arg_str

  static string_type arg_str(const std::string& value)
   {
    return ansi_to_unicode(value);
   }//arg_str

 public: //generic -------------------------------------------------------
  static string_type arg(bool const value)
   {
    return self_type::arg_bool(value);
   }//arg

  static string_type arg(signed int value)
   {
    return self_type::arg_int(value);
   }//arg

  static string_type arg(unsigned int value)
   {
    return self_type::arg_uint(value);
   }//arg

  static string_type arg(signed long value)
   {
    return self_type::arg_long(value);
   }//arg

  static string_type arg(unsigned long value)
   {
    return self_type::arg_ulong(value);
   }//arg

  static string_type arg(signed __int64 value)
   {
    return self_type::arg_int64(value);
   }//arg

  static string_type arg(unsigned __int64 value)
   {
    return self_type::arg_uint64(value);
   }//arg

  static string_type arg(float value)
   {
    return self_type::arg_float(value);
   }//arg

  static string_type arg(double value)
   {
    return self_type::arg_double(value);
   }//arg

  static string_type arg(long double value)
   {
    return self_type::arg_long_double(value);
   }//arg

  static string_type arg(const wchar_t* const value)
   {
    return self_type::arg_str(value);
   }//arg

  static string_type arg(const wchar_t* const s,size_type const n)
   {
    return self_type::arg_str(s,n);
   }//arg

  static const string_type& arg(const string_type& value)
   {
    return value;
   }//arg

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type&& arg(string_type&& value)
   {
    return __STL_MOVE_VALUE(value);
   }//arg
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  static string_type arg(const char* const value)
   {
    return self_type::arg_str(value);
   }//arg

  static string_type arg(const char* const s,size_type const n)
   {
    return self_type::arg_str(s,n);
   }//arg

  static string_type arg(const std::string& value)
   {
    return self_type::arg_str(value);
   }//arg
};//t_str_args_traits<wchar_t>

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
