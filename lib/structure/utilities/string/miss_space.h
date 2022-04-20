////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__miss_space_H_
#define _lcpi_lib_structure_utilities__string__miss_space_H_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//Miss space functions

template<class ForwardIterator>
inline ForwardIterator miss_space(ForwardIterator first,
                                  ForwardIterator last);

template<class ForwardIterator>
inline ForwardIterator miss_space2(ForwardIterator fisrt,
                                   ForwardIterator last);

template<class ForwardIterator>
inline ForwardIterator total_miss_space(ForwardIterator fisrt,
                                        ForwardIterator last);

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator miss_space_back(BidirectionalIterator first,
                                             BidirectionalIterator last);

template<class BidirectionalIterator>
inline BidirectionalIterator miss_space2_back(BidirectionalIterator first,
                                              BidirectionalIterator last);

template<class BidirectionalIterator>
inline BidirectionalIterator total_miss_space_back(BidirectionalIterator first,
                                                   BidirectionalIterator last);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/utilities/string/miss_space.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
