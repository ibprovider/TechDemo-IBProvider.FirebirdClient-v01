////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__trim_CC_
#define _lcpi_lib_structure_utilities__string__trim_CC_

#include <structure/utilities/string/miss_space.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class TStr,class TTrimComp>
TStr trimr(const TStr& str,TTrimComp is_trim_char)
{
 typename TStr::const_iterator const beg(str.begin());
 typename TStr::const_iterator const end(str.end());

 typename TStr::const_iterator const i(__miss_space_back(beg,end,is_trim_char));

 return TStr(beg,i);
}//trimr

//------------------------------------------------------------------------
template<class TStr,class TTrimComp>
TStr triml(const TStr& str,TTrimComp is_trim_char)
{
 typename TStr::const_iterator const beg(str.begin());
 typename TStr::const_iterator const end(str.end());

 typename TStr::const_iterator const i(__miss_space(beg,end,is_trim_char));

 return TStr(i,end);
}//triml

//------------------------------------------------------------------------
template<class TStr,class TTrimComp>
TStr trim(const TStr& str,TTrimComp is_trim_char)
{
 TStr t(trimr(str,is_trim_char));

 return self_triml(t,is_trim_char);
}//trim

//------------------------------------------------------------------------
template<class TStr,class TTrimComp>
TStr& self_trimr(TStr& str,TTrimComp is_trim_char)
{
 typename TStr::iterator const beg(str.begin());
 typename TStr::iterator const end(str.end());

 typename TStr::iterator const i(__miss_space_back(beg,end,is_trim_char));

 str.erase(i,end);

 return str;
}//self_trimr

//------------------------------------------------------------------------
template<class TStr,class TTrimComp>
TStr& self_triml(TStr& str,TTrimComp is_trim_char)
{
 typename TStr::iterator const beg(str.begin());
 typename TStr::iterator const end(str.end());
 typename TStr::iterator const i(__miss_space(beg,end,is_trim_char));

 str.erase(beg,i);

 return str;
}//self_triml

//------------------------------------------------------------------------
template<class TStr,class TTrimComp>
TStr& self_trim(TStr& str,TTrimComp is_trim_char)
{
 return self_triml(self_trimr(str,is_trim_char),is_trim_char);
}//self_trim

////////////////////////////////////////////////////////////////////////////////
//trim string functions

//GENERIC trimXXX --------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 trimr(const std::basic_string<charT,traits,Allocator>& str)
 {
  return trimr(str,tag_is_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 triml(const std::basic_string<charT,traits,Allocator>& str)
 {
  return triml(str,tag_is_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 trim(const std::basic_string<charT,traits,Allocator>& str)
 {
  return trim(str,tag_is_trim_char<typename traits::char_type>());
 }

//GENERIC self_trimXXX ---------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 self_trimr(std::basic_string<charT,traits,Allocator>& str)
 {
  return self_trimr(str,tag_is_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 self_triml(std::basic_string<charT,traits,Allocator>& str)
 {
  return self_triml(str,tag_is_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 self_trim(std::basic_string<charT,traits,Allocator>& str)
 {
  return self_trim(str,tag_is_trim_char<typename traits::char_type>());
 }

//GENERIC total_trimXXX --------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 total_trimr(const std::basic_string<charT,traits,Allocator>& str)
 {
  return trimr(str,tag_is_total_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 total_triml(const std::basic_string<charT,traits,Allocator>& str)
 {
  return triml(str,tag_is_total_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 total_trim(const std::basic_string<charT,traits,Allocator>& str)
 {
  return trim(str,tag_is_total_trim_char<typename traits::char_type>());
 }

//GENERIC total_self_trimXXX ---------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 total_self_trimr(std::basic_string<charT,traits,Allocator>& str)
 {
  return self_trimr(str,tag_is_total_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 total_self_triml(std::basic_string<charT,traits,Allocator>& str)
 {
  return self_triml(str,tag_is_total_trim_char<typename traits::char_type>());
 }

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 total_self_trim(std::basic_string<charT,traits,Allocator>& str)
 {
  return self_trim(str,tag_is_total_trim_char<typename traits::char_type>());
 }

////////////////////////////////////////////////////////////////////////////////
//detect empty trimed string

template<class ForwardIterator,class TTrimComp>
bool __trim_empty(ForwardIterator beg,ForwardIterator end,TTrimComp is_space_char)
{
 return __miss_space
         (beg,
          end,
          is_space_char)==end;
}//__trim_empty

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline bool trim_empty(const std::basic_string<charT,traits,Allocator>& str)
{
 return __trim_empty
         (str.begin(),
          str.end(),
          tag_is_trim_char<typename traits::char_type>());
}//trim_empty

//------------------------------------------------------------------------
template<class charT,class traits,class Allocator>
inline bool total_trim_empty(const std::basic_string<charT,traits,Allocator>& str)
{
 return __trim_empty
         (str.begin(),
          str.end(),
          tag_is_total_trim_char<typename traits::char_type>());
}//total_trim_empty

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
