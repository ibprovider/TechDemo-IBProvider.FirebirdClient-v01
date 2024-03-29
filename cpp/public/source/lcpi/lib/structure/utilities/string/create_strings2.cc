////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__create_strings2_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string__create_strings2_CC_

#include <lcpi/lib/structure/t_char_traits2.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//Extracting substring divided '\n' '\r' '\r\n' and adding it to container
//returning the number of added strings

template<class TContainer,class ForwardIterator>
size_t __create_strings2(TContainer&     container,
                         ForwardIterator beg,
                         ForwardIterator end)
{
 using char_type
  =typename std::iterator_traits<ForwardIterator>::value_type;

 using _t2
  =t_char_traits2<char_type>;

 using string_type
  =std::basic_string<char_type>;

 ForwardIterator e(beg);

 size_t      result=0;
 char_type   c;
 string_type ts;

 while(e!=end)
 {
  if((*e)!=_t2::ch_new_line() && (*e)!=_t2::ch_return_line() && (*e)!=0)
  {
   ts+=*(e++);
  }
  else
  {
   container.push_back(ts);

   ts.erase();

   ++result;

   c=*(e++);

   if(c==_t2::ch_return_line() && e!=end && (*e)==_t2::ch_new_line())
    ++e;//пропускаем '\r\n'
  }//else
 }//while

 if(!ts.empty())
 {
  ++result;

  container.push_back(ts);
 }

 return result;
}//__create_strings2

////////////////////////////////////////////////////////////////////////////////

template<class TContainer,class charT>
size_t create_strings2(TContainer&        container,
                       const charT* const str)
{
 if(!str)
  __create_strings2(container,str,str);

 assert(str);

 return __create_strings2(container,str,str+std::char_traits<charT>::length(str));
}//create_strings2

//------------------------------------------------------------------------
template<class TContainer,class charT>
size_t create_strings2(TContainer&                     container,
                       const std::basic_string<charT>& str)
{
 return __create_strings2(container,str.cbegin(),str.cend());
}//create_strings2

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
