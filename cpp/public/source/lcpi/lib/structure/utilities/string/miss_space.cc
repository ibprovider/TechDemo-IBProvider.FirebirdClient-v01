////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__miss_space_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string__miss_space_CC_

#include <lcpi/lib/structure/utilities/string/is_trim_char.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//miss space functions

template<class ForwardIterator,class TSpaceComp>
ForwardIterator __miss_space(ForwardIterator first,
                             ForwardIterator last,
                             TSpaceComp      is_space)
{
 while(first!=last && is_space(*first))
  ++first;

 return first;
}//__miss_space

//------------------------------------------------------------------------
template<class ForwardIterator>
inline ForwardIterator miss_space(ForwardIterator first,
                                  ForwardIterator last)
{
 typedef typename std::iterator_traits<ForwardIterator>::value_type char_type;

 return __miss_space
         (first,
          last,
          tag_is_trim_char<char_type>());
}//miss_space

//------------------------------------------------------------------------
template<class ForwardIterator>
inline ForwardIterator miss_space2(ForwardIterator first,
                                         ForwardIterator last)
{
 typedef typename std::iterator_traits<ForwardIterator>::value_type char_type;

 return __miss_space
         (first,
          last,
          tag_is_trim_char2<char_type>());
}//miss_space2

//------------------------------------------------------------------------
template<class ForwardIterator>
inline ForwardIterator total_miss_space(ForwardIterator first,
                                        ForwardIterator last)
{
 typedef typename std::iterator_traits<ForwardIterator>::value_type char_type;

 return __miss_space
         (first,
          last,
          tag_is_total_trim_char<char_type>());
}//total_miss_space

//back -------------------------------------------------------------------
template<class BidirectionalIterator,class TSpaceComp>
BidirectionalIterator __miss_space_back(BidirectionalIterator first,
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
}//__miss_space_back

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator miss_space_back(BidirectionalIterator first,
                                             BidirectionalIterator last)
{
 typedef typename std::iterator_traits<BidirectionalIterator>::value_type char_type;

 return __miss_space_back
         (first,
          last,
          tag_is_trim_char<char_type>());
}//miss_space_back

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator miss_space2_back(BidirectionalIterator first,
                                              BidirectionalIterator last)
{
 typedef typename std::iterator_traits<BidirectionalIterator>::value_type char_type;

 return __miss_space_back
         (first,
          last,
          tag_is_trim_char2<char_type>());
}//miss_space2_back

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator total_miss_space_back(BidirectionalIterator first,
                                                   BidirectionalIterator last)
{
 typedef typename std::iterator_traits<BidirectionalIterator>::value_type char_type;

 return __miss_space_back
         (first,
          last,
          tag_is_total_trim_char<char_type>());
}//total_miss_space_back

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
