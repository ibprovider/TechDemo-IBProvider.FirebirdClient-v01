////////////////////////////////////////////////////////////////////////////////
//Template wrapper for char* and const string& arguments
//                                                 Dmitry Kovalenko. 20.11.2006
#ifndef _t_str_parameter_H_
#define _t_str_parameter_H_

#include <structure/t_char_traits2.h>
#include <string>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_str_parameter

template<class charT,class strT=__STL_DEF_BASIC_STRING(charT) >
class t_str_parameter
{
 private:
  typedef t_str_parameter<charT,strT>                    self_type;

  self_type& operator = (const self_type&);

 public:
  typedef strT                                           string_type;
  typedef typename string_type::value_type               char_type;

  typedef std::char_traits<char_type>                    traits_type;

 #ifdef _USE_VCL_
  typedef t_char_traits2<char_type>::vcl_string_type     vcl_string_type;
 #endif

 public:
   t_str_parameter(const self_type& x)
    :m_s(x.m_s)
   {;}

  t_str_parameter(const char_type* const s)
   :m_s(s)
  {;}

  t_str_parameter(const string_type& s)
   :m_s(s.c_str())
  {;}

 #ifdef _USE_VCL_
  t_str_parameter(const vcl_string_type& s)
   :m_s(s.c_str())
  {;}
 #endif

  t_str_parameter(std::nullptr_t const x)
   :m_s(x)
  {;}

 public:
  //return: CAN BE NULL
  const char_type* c_str()const
  {
   return m_s;
  }//c_str

  //return: NOT NULL
  const char_type* str()const
  {
   return m_s?m_s:&sm_null_char;
  }//str

  bool empty()const
  {
   return !m_s || (*m_s)==0;
  }//empty

  size_t length()const
  {
   return m_s?std::char_traits<char_type>::length(m_s):0;
  }//length

 private:
  const char_type* const m_s;

 private:
  static const char_type sm_null_char;
};//class t_str_parameter

template<class charT,class strT>
const typename t_str_parameter<charT,strT>::char_type
 t_str_parameter<charT,strT>::sm_null_char=0;

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef t_str_parameter<char>           str_parameter;
typedef t_str_parameter<wchar_t>        wstr_parameter;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
//non member operators

template<class charT>
std::basic_ostream<charT>& operator << (std::basic_ostream<charT>& os,
                                        const structure::t_str_parameter<charT>& s)
{
 return os<<s.c_str();
}//<<

////////////////////////////////////////////////////////////////////////////////
#endif
