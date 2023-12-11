////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 03.12.2023
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__skip_spaces_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__skip_spaces_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//Miss space functions

template<class ForwardIterator>
inline ForwardIterator skip_spaces
        (ForwardIterator first,
         ForwardIterator last);

template<class ForwardIterator>
inline ForwardIterator skip_spaces2
        (ForwardIterator fisrt,
         ForwardIterator last);

template<class ForwardIterator>
inline ForwardIterator total_skip_spaces
        (ForwardIterator fisrt,
         ForwardIterator last);

//------------------------------------------------------------------------
template<class BidirectionalIterator>
inline BidirectionalIterator skip_spaces_back
        (BidirectionalIterator first,
         BidirectionalIterator last);

template<class BidirectionalIterator>
inline BidirectionalIterator skip_spaces2_back
        (BidirectionalIterator first,
         BidirectionalIterator last);

template<class BidirectionalIterator>
inline BidirectionalIterator total_skip_spaces_back
        (BidirectionalIterator first,
         BidirectionalIterator last);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/string/skip_spaces.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
