////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 11.10.2019
#ifndef _lcpi_lib_structure_utilities__string__equal_to_string_H_
#define _lcpi_lib_structure_utilities__string__equal_to_string_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//compare [first,last] with null terminated string

template<class charT,class ForwardIterator>
bool equal_to_string(ForwardIterator first,
                     ForwardIterator last,
                     const charT*    sz_s)
{
 if(!sz_s)
  return first==last;

 for(;;++sz_s,++first)
 {
  if((*sz_s)==0)
   return first==last;

  if(first==last)
   return false;

  if((*sz_s)!=(*first))
   return false;
 }//for[ever]
}//equal_to_string

//------------------------------------------------------------------------
template<class charT,class ForwardIterator,class EqBinaryOp>
bool equal_to_string(ForwardIterator first,
                     ForwardIterator last,
                     const charT*    sz_s,
                     EqBinaryOp      eq_op)
{
 if(!sz_s)
  return first==last;

 for(;;++sz_s,++first)
 {
  if(eq_op(*sz_s,0))
   return first==last;

  if(first==last)
   return false;

  if(!eq_op(*sz_s,*first))
   return false;
 }//for[ever]
}//equal_to_string

//------------------------------------------------------------------------
template<class charT>
inline bool equal_to_string_n(const charT* const s1,
                              size_t       const n1,
                              const charT* const sz_s2)
{
 return equal_to_string(s1,s1+n1,sz_s2);
}//equal_to_string_n

//------------------------------------------------------------------------
template<class charT,class EqBinaryOp>
bool equal_to_string_n(const charT* const s1,
                       size_t       const n1,
                       const charT* const sz_s2,
                       EqBinaryOp         eq_op)
{
 return equal_to_string(s1,s1+n1,sz_s2,eq_op);
}//equal_to_string_n

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/
#endif
