////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__del_spaces_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string__del_spaces_CC_

#include <lcpi/lib/structure/utilities/string/trim.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//service templates for del_spaces functions

//is_space - return true for delete of char

template<class TStr,class TSpaceComp>
TStr del_spaces(const TStr& str,bool all,TSpaceComp is_space)
{
 using const_iterator=typename TStr::const_iterator;

 const_iterator b(str.begin());
 const_iterator e(str.end());

 b=__skip_spaces     (b,e,is_space);
 e=__skip_spaces_back(b,e,is_space);

 const_iterator i(b);

 TStr result;

 bool skip_space=false;//пропуск пробелов

 for(;i!=e;++i)
 {
  if(!skip_space)
  {
   if(is_space(*i))
   {
    skip_space=true;

    //добавляем подстроку (если не all, то включая пробел)
    result.append(b,i+(all?0:1));
   }
  }
  else //skip_space==true
  if(!is_space(*i))
  {
   b=i; //stop skipping
   skip_space=false;
  }
 }//for i

 if(!skip_space)
  result.append(b,i);

 return result;
}//del_spaces

//------------------------------------------------------------------------
template<class TStr,class TSpaceComp>
TStr& self_del_spaces(TStr& str,bool all,TSpaceComp is_space)
{
 typename TStr::iterator b(str.begin());
 typename TStr::iterator i(str.begin());

 for(bool skip_space=true,comp_result;i!=str.end();++i,skip_space=comp_result)
 {
  if((comp_result=is_space(*i))!=false && (skip_space || all))
   continue;

  (*b)=(*i);

  ++b;
 }//for i

 str.erase(b,i);

 return self_trimr(str,is_space);
}//self_del_spaces

////////////////////////////////////////////////////////////////////////////////
//del_spaces functions

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 del_spaces(const std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return del_spaces
          (str,
           all,
           tag_is_trim_char<typename traits::char_type>());
 }//del_spaces

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 total_del_spaces(const std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return del_spaces
          (str,
           all,
           tag_is_total_trim_char<typename traits::char_type>());
 }//total_del_spaces

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 self_del_spaces(std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return self_del_spaces
          (str,
           all,
           tag_is_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 total_self_del_spaces(std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return self_del_spaces
          (str,
           all,
           tag_is_total_trim_char<typename traits::char_type>());
 }//total_self_del_spaces

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
