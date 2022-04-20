////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__is_trim_char_H_
#define _lcpi_lib_structure_utilities__string__is_trim_char_H_

#include <structure/t_char_traits2.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename charT>
bool is_trim_char(const charT ch)
{
 return ch==t_char_traits2<charT>::ch_space();
}//is_trim_char

//------------------------------------------------------------------------
template<typename charT>
bool is_trim_char2(const charT ch)
{
 return ch==t_char_traits2<charT>::ch_space()       ||
        ch==t_char_traits2<charT>::ch_new_line()    ||
        ch==t_char_traits2<charT>::ch_return_line() ||
        ch==t_char_traits2<charT>::ch_tab();
}//is_trim_char2

//------------------------------------------------------------------------
template<typename charT>
bool is_total_trim_char(const charT ch)
{
 return ch==0                                       ||
        ch==t_char_traits2<charT>::ch_space()       ||
        ch==t_char_traits2<charT>::ch_new_line()    ||
        ch==t_char_traits2<charT>::ch_return_line() ||
        ch==t_char_traits2<charT>::ch_tab();
}//is_total_trim_char

////////////////////////////////////////////////////////////////////////////////
//class tag_is_trim_char

template<class charT>
class tag_is_trim_char
{
 public: //typedefs ------------------------------------------------------
  typedef charT                             char_type;

 public:
  tag_is_trim_char(){;}

  bool operator () (char_type const ch) const
  {
   return is_trim_char(ch);
  }
};//class tag_is_trim_char

////////////////////////////////////////////////////////////////////////////////
//class tag_is_trim_char2

template<class charT>
class tag_is_trim_char2
{
 public: //typedefs ------------------------------------------------------
  typedef charT                             char_type;

 public:
  tag_is_trim_char2(){;}

  bool operator () (char_type const ch) const
  {
   return is_trim_char2(ch);
  }
};//class tag_is_trim_char2

////////////////////////////////////////////////////////////////////////////////
//class tag_is_total_trim_char

template<class charT>
class tag_is_total_trim_char
{
 public: //typedefs ------------------------------------------------------
  typedef charT                             char_type;

 public:
  tag_is_total_trim_char(){;}

  bool operator () (char_type const ch) const
  {
   return is_total_trim_char(ch);
  }
};//class tag_is_total_trim_char

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/
#endif
