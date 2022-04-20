////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__position_in_str_H_
#define _lcpi_lib_structure_utilities__string__position_in_str_H_

#include <structure/t_common.h>
#include <utility>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//calculate position as [line,col]

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
}//namespace structure
#endif
