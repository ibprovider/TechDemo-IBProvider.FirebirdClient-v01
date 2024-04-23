////////////////////////////////////////////////////////////////////////////////
//Template wrapper for char* and const string& arguments
//                                                 Dmitry Kovalenko. 20.11.2006
#ifndef _lcpi_lib_structure__t_str_parameter_H_
#define _lcpi_lib_structure__t_str_parameter_H_

#include <lcpi/lib/.config.h>
#include <string>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_str_parameter

template<class charT,class strT=LCPI_STL_DEF_BASIC_STRING(charT) >
class t_str_parameter LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_str_parameter<charT,strT>;

  self_type& operator = (const self_type&)=delete;

 public:
  using string_type = strT;
  using char_type   = typename string_type::value_type;

 public:
  t_str_parameter(const self_type& x)
   :m_s(x.m_s)
  {
  }

  t_str_parameter(const char_type* const s)
   :m_s(s)
  {
  }

  t_str_parameter(const string_type& s)
   :m_s(s.c_str())
  {
  }

  t_str_parameter(std::nullptr_t const x)
   :m_s(x)
  {
  }

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
   return m_s==nullptr || (*m_s)==0;
  }//empty

  size_t length()const
  {
   if(m_s==nullptr)
    return 0;

   return std::char_traits<char_type>::length(m_s);
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

using str_parameter=t_str_parameter<char>;

using wstr_parameter=t_str_parameter<wchar_t>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
//non member operators

template<class charT,class strT>
std::basic_ostream<charT>& operator << (std::basic_ostream<charT>& os,
                                        const structure::t_str_parameter<charT,strT>& s)
{
 return os<<s.c_str();
}//<<

////////////////////////////////////////////////////////////////////////////////
#endif
