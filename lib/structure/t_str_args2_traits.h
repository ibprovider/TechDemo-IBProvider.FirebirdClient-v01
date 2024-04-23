////////////////////////////////////////////////////////////////////////////////
//Traits for convert several simple types to std::basic_string
//                                                 Dmitry Kovalenko. xx.04.2024
#ifndef _lcpi_lib_structure__t_str_args2_traits_H_
#define _lcpi_lib_structure__t_str_args2_traits_H_

#include <structure/t_const_str_box.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class charT,class str_cvt_traits>
class t_str_args2_traits;

template<class str_cvt_traits>
class t_str_args2_traits<char,str_cvt_traits>;

template<class str_cvt_traits>
class t_str_args2_traits<wchar_t,str_cvt_traits>;

////////////////////////////////////////////////////////////////////////////////
//template class t_str_args2_traits

template<class charT,class str_cvt_traits>
class t_str_args2_traits
{
 public: //typedefs ------------------------------------------------------
  using char_type
   =charT;

  using cvt_traits_type
   =str_cvt_traits;

  //BCB3 did not define default template arguments
  using string_type
   =LCPI_STL_DEF_BASIC_STRING(char_type);

  using size_type
   =typename string_type::size_type;
};//template class t_str_args2_traits

////////////////////////////////////////////////////////////////////////////////
//class t_str_args2_traits<char>

template<class str_cvt_traits>
class t_str_args2_traits<char,str_cvt_traits>
{
 private:
  using self_type=t_str_args2_traits<char,str_cvt_traits>;

 public: //typedefs ------------------------------------------------------
  using char_type
   =char;

  using str_cvt_traits_type
   =str_cvt_traits;

  using string_type
   =LCPI_STL_DEF_BASIC_STRING(char_type);

  using size_type
   =string_type::size_type;

 public: //convert utility ------------------------------------------------
  static string_type arg_bool(bool value)
  {
   return value?"true":"false";
  }

  static string_type arg_int(std::int32_t value)
  {
   return LCPI_STL_TO_STRING(value);
  }//arg_int

  static string_type arg_uint(std::uint32_t value)
  {
   return LCPI_STL_TO_STRING(value);
  }//arg_uint

#if(LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static string_type arg_long(signed long value)
  {
   return LCPI_STL_TO_STRING(value);
  }//arg_long
#endif

#if(LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  static string_type arg_ulong(unsigned long value)
  {
   return LCPI_STL_TO_STRING(value);
  }//arg_ulong
#endif

  static string_type arg_int64(std::int64_t value)
  {
   return LCPI_STL_TO_STRING(value);
  }//arg_int64

  static string_type arg_uint64(std::uint64_t value)
  {
   return LCPI_STL_TO_STRING(value);
  }//arg_uint64

  static string_type arg_float(float value)
  {
   char_type tmp[128];

   LCPI_GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16lg",(double)value);

   return string_type(tmp);
  }//arg_float

  static string_type arg_double(double value)
  {
   char_type tmp[128];

   LCPI_GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16lg",value);

   return string_type(tmp);
  }//arg_double

  static string_type arg_long_double(long double value)
  {
   char_type tmp[128];

   LCPI_GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16Lg",value);

   return string_type(tmp);
  }//arg_long_double

  static string_type arg_str(const char* const value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
  }//arg_str

  static string_type arg_str2(const char* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,structure::make_str_box(s,n));

   return r;
  }//arg_str2

  static string_type arg_str(const string_type& value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
  }//arg_str

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type arg_str(string_type&& value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,LCPI_STL_MOVE_VALUE(value));

   return r;
  }//arg_str
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  static string_type arg_str(const wchar_t* const value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
  }//arg_str

  static string_type arg_str2(const wchar_t* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,structure::make_str_box(s,n));

   return r;
  }//arg_str2

  static string_type arg_str(const std::wstring& value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
  }//arg_str

 public: //generic -------------------------------------------------------
  static string_type arg(bool const value)
  {
   return self_type::arg_bool(value);
  }//arg

  static string_type arg(std::int32_t value)
  {
   return self_type::arg_int(value);
  }//arg

  static string_type arg(std::uint32_t value)
  {
   return self_type::arg_uint(value);
  }//arg

#if(LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static string_type arg(signed long value)
  {
   return self_type::arg_long(value);
  }//arg
#endif

#if(LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static string_type arg(unsigned long value)
  {
   return self_type::arg_ulong(value);
  }//arg
#endif

  static string_type arg(std::int64_t value)
  {
   return self_type::arg_int64(value);
  }//arg

  static string_type arg(std::uint64_t value)
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

  static string_type arg2(const wchar_t* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   return self_type::arg_str2(s,n);
  }//arg2

  static string_type arg(const std::wstring& value)
  {
   return self_type::arg_str(value);
  }//arg

  static string_type arg(const char* const value)
  {
   return self_type::arg_str(value);
  }//arg

  static string_type arg2(const char* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   return self_type::arg_str2(s,n);
  }//arg2

  static string_type arg(const string_type& value)
  {
   return self_type::arg_str(value);
  }//arg

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type arg(string_type&& value)
  {
   return self_type::arg_str(LCPI_STL_MOVE_VALUE(value));
  }//arg
 #endif
};//class t_str_args2_traits<char>

////////////////////////////////////////////////////////////////////////////////
//class t_str_args2_traits<wchar_t>

template<class str_cvt_traits>
class t_str_args2_traits<wchar_t,str_cvt_traits>
{
 private:
  using self_type=t_str_args2_traits<wchar_t,str_cvt_traits>;

 public: //typedefs ------------------------------------------------------
  using char_type
   =wchar_t;

  using str_cvt_traits_type
   =str_cvt_traits;

  using string_type
   =LCPI_STL_DEF_BASIC_STRING(char_type);

  using size_type
   =string_type::size_type;

 public: //convert utility ------------------------------------------------
  static string_type arg_bool(bool value)
  {
   return value?L"true":L"false";
  }

  static string_type arg_int(std::int32_t value)
  {
   return LCPI_STL_TO_WSTRING(value);
  }//arg_int

  static string_type arg_uint(std::uint32_t value)
  {
   return LCPI_STL_TO_WSTRING(value);
  }//arg_uint

#if(LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static string_type arg_long(signed long value)
  {
   return LCPI_STL_TO_WSTRING(value);
  }//arg_long
#endif

#if(LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  static string_type arg_ulong(unsigned long value)
  {
   return LCPI_STL_TO_WSTRING(value);
  }//arg_ulong
#endif

  static string_type arg_int64(std::int64_t value)
  {
   return LCPI_STL_TO_WSTRING(value);
  }//arg_int64

  static string_type arg_uint64(std::uint64_t value)
  {
   return LCPI_STL_TO_WSTRING(value);
  }//arg_uint64

  static string_type arg_float(float value)
  {
   char_type tmp[128];

   LCPI_GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16lg",(double)value);

   return string_type(tmp);
  }//arg_double

  static string_type arg_double(double value)
  {
   char_type tmp[128];

   LCPI_GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16lg",value);

   return string_type(tmp);
  }//arg_double

  static string_type arg_long_double(long double value)
  {
   char_type tmp[128];

   LCPI_GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16Lg",value);

   return string_type(tmp);
  }//arg_long_double

  static string_type arg_str(const wchar_t* const value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
  }//arg_str

  static string_type arg_str2(const wchar_t* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,structure::make_str_box(s,n));

   return r;
  }//arg_str2

  static string_type arg_str(const string_type& value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
  }//arg_str

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type arg_str(string_type&& value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,LCPI_STL_MOVE_VALUE(value));

   return r;
  }//arg_str
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  static string_type arg_str(const char* const value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
  }//arg_str

  static string_type arg_str2(const char* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,structure::make_str_box(s,n));

   return r;
  }//arg_str2

  static string_type arg_str(const std::string& value)
  {
   string_type r;

   str_cvt_traits::tstr_to_tstr(&r,value);

   return r;
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

#if(LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static string_type arg(signed long value)
  {
   return self_type::arg_long(value);
  }//arg
#endif

#if(LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  static string_type arg(unsigned long value)
  {
   return self_type::arg_ulong(value);
  }//arg
#endif

  static string_type arg(std::int64_t value)
  {
   return self_type::arg_int64(value);
  }//arg

  static string_type arg(std::uint64_t value)
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

  static string_type arg2(const wchar_t* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   return self_type::arg_str2(s,n);
  }//arg2

  static string_type arg(const string_type& value)
  {
   return self_type::arg_str(value);
  }//arg

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static string_type arg(string_type&& value)
  {
   return self_type::arg_str(LCPI_STL_MOVE_VALUE(value));
  }//arg
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  static string_type arg(const char* const value)
  {
   return self_type::arg_str(value);
  }//arg

  static string_type arg2(const char* const s,size_type const n)
  {
   CHECK_READ_TYPED_PTR(s,n);

   return self_type::arg_str2(s,n);
  }//arg2

  static string_type arg(const std::string& value)
  {
   return self_type::arg_str(value);
  }//arg
};//class t_str_args2_traits<wchar_t>

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
