////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__position_in_str_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__position_in_str_H_

#include <lcpi/lib/.config.h>
#include <utility>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//calculate position as [line,col]

//
// This function calculates a position of the LAST symbol in range [beg,end)
//
// It means that:
//  ""     ->  returns (0,0)
//  "A"    ->  returns (1,1)
//  "\n"   ->  returns (2,0)
//  "\nA"  ->  returns (2,1)
//

template<class ForwardIterator>
std::pair<size_t,size_t> position_in_str(ForwardIterator beg,ForwardIterator end)
{
 std::pair<size_t,size_t> pos(0,0);

 while(beg!=end)
 {
  ++pos.first;

  pos.second=0;

  while(beg!=end)
  {
   if((*beg)=='\r')
   {
    ++beg;

    if(beg!=end && (*beg)=='\n')
     ++beg;

    break;  //new line
   }//if \r

   if((*beg)=='\n')
   {
    ++beg;

    break;  //new line
   }//if \n

   //next column
   ++pos.second;

   ++beg;
  }//while
 }//while

 return pos;
}//position_in_str

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
