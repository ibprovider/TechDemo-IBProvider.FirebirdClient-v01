////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__del_space_CC_
#define _lcpi_lib_structure_utilities__string__del_space_CC_

#include <structure/utilities/string/trim.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//service templates for del_space functions

//is_space - return true for delete of char

template<class TStr,class TSpaceComp>
TStr del_space(const TStr& str,bool all,TSpaceComp is_space)
{
 TStr result;

 typename TStr::const_iterator b(str.begin());
 typename TStr::const_iterator i(str.begin());

 bool skip_space=false;//пропуск пробелов

 for(;i!=str.end();++i)
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

 return self_trim(result,is_space);
}//del_space

//------------------------------------------------------------------------
template<class TStr,class TSpaceComp>
TStr& self_del_space(TStr& str,bool all,TSpaceComp is_space)
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
}//self_del_space

////////////////////////////////////////////////////////////////////////////////
//del_space functions

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 del_space(const std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return del_space
          (str,
           all,
           tag_is_trim_char<typename traits::char_type>());
 }//del_space

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 total_del_space(const std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return del_space
          (str,
           all,
           tag_is_total_trim_char<typename traits::char_type>());
 }//total_del_space

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 self_del_space(std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return self_del_space
          (str,
           all,
           tag_is_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 total_self_del_space(std::basic_string<charT,traits,Allocator>& str,bool all)
 {
  return self_del_space
          (str,
           all,
           tag_is_total_trim_char<typename traits::char_type>());
 }//total_self_del_space

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/utilities/string/del_space.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
