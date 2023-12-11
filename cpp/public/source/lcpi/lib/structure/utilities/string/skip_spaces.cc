////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 03.12.2023
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__skip_spaces_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string__skip_spaces_CC_

#include <lcpi/lib/structure/utilities/string/is_trim_char.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//miss space functions

template<class ForwardIterator,class TSpaceComp>
ForwardIterator __skip_spaces(ForwardIterator first,
                              ForwardIterator last,
                              TSpaceComp      is_space)
{
 while(first!=last && is_space(*first))
  ++first;

 return first;
}//__skip_spaces

//------------------------------------------------------------------------
template<class ForwardIterator>
inline ForwardIterator skip_spaces(ForwardIterator first,
                                   ForwardIterator last)
{
 typedef typename std::iterator_traits<ForwardIterator>::value_type char_type;

 return __skip_spaces
         (first,
          last,
          tag_is_trim_char<char_type>());
}//skip_spaces

//------------------------------------------------------------------------
template<class ForwardIterator>
inline ForwardIterator skip_spaces2(ForwardIterator first,
                                    ForwardIterator last)
{
 typedef typename std::iterator_traits<ForwardIterator>::value_type char_type;

 return __skip_spaces
         (first,
          last,
          tag_is_trim_char2<char_type>());
}//skip_spaces2

//------------------------------------------------------------------------
template<class ForwardIterator>
inline ForwardIterator total_skip_spaces(ForwardIterator first,
                                         ForwardIterator last)
{
 typedef typename std::iterator_traits<ForwardIterator>::value_type char_type;

 return __skip_spaces
         (first,
          last,
          tag_is_total_trim_char<char_type>());
}//total_skip_spaces

//back -------------------------------------------------------------------
template<class BidirectionalIterator,class TSpaceComp>
BidirectionalIterator __skip_spaces_back(BidirectionalIterator first,
                                         BidirectionalIterator last,
                                         TSpaceComp            is_space)
{
 while(first!=last)
 {
  const BidirectionalIterator t(last);

  --last;

  if(!is_space(*last))
   return t;
 }//while

 return last;
}//__skip_spaces_back

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator skip_spaces_back(BidirectionalIterator first,
                                              BidirectionalIterator last)
{
 typedef typename std::iterator_traits<BidirectionalIterator>::value_type char_type;

 return __skip_spaces_back
         (first,
          last,
          tag_is_trim_char<char_type>());
}//skip_spaces_back

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator skip_spaces2_back(BidirectionalIterator first,
                                               BidirectionalIterator last)
{
 typedef typename std::iterator_traits<BidirectionalIterator>::value_type char_type;

 return __skip_spaces_back
         (first,
          last,
          tag_is_trim_char2<char_type>());
}//skip_spaces2_back

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator total_skip_spaces_back(BidirectionalIterator first,
                                                   BidirectionalIterator last)
{
 typedef typename std::iterator_traits<BidirectionalIterator>::value_type char_type;

 return __skip_spaces_back
         (first,
          last,
          tag_is_total_trim_char<char_type>());
}//total_skip_spaces_back

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
