////////////////////////////////////////////////////////////////////////////////
//Service for compare string with template
//                                                 Kovalenko Dmitry. 17.05.2007
#ifndef _t_str_like_H_
#define _t_str_like_H_

#include <structure/t_value_with_null.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<typename Iterator1,typename Iterator2=Iterator1>
class t_str_like;

////////////////////////////////////////////////////////////////////////////////
//template t_str_like

template<typename Iterator1,typename Iterator2>
class t_str_like
{
 public:
  typedef Iterator1        iterator1_type;
  typedef Iterator2        iterator2_type;

  struct tag_restart_point
  {
   public:
    iterator1_type i_str;
    iterator2_type i_templ;
    iterator2_type e_templ;
  };//class tag_restart_data

  typedef tag_restart_point                        restart_point_type;
  typedef t_value_with_null<restart_point_type>    restart_point_type_N;

  typedef typename std::iterator_traits<iterator2_type>::value_type  char_type;

 public:
  char_type m_any_sym;
  char_type m_any_seq;

  t_str_like(char_type any_sym,char_type any_seq);

  bool run(iterator1_type i_str,
           iterator1_type e_str,
           iterator2_type i_templ,
           iterator2_type e_templ)const;

 private:
  bool run_impl(iterator1_type        i_str,
                iterator1_type        e_str,
                iterator2_type        i_templ,
                iterator2_type        e_templ,
                restart_point_type_N& restart_point)const;
};//class t_str_like

////////////////////////////////////////////////////////////////////////////////
//helper utilities

template<typename charT>
bool is_like_str(charT                                any_sym,
                 charT                                any_seq,
                 const __STL_DEF_BASIC_STRING(charT)& str,
                 const __STL_DEF_BASIC_STRING(charT)& templ);

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_str_like.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
