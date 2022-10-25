////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 26.05.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__string_compare_v2_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string__string_compare_v2_CC_

#include <lcpi/lib/structure/t_negative_one.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//string comparer

template<class charT,class LessOp>
int string_compare_v2(const charT* s1,
                      size_t       n1,
                      const charT* s2,
                      size_t       n2,
                      LessOp       less_op)
{
 assert(n1==0 || s1!=nullptr);
 assert(n2==0 || s2!=nullptr);

 CHECK_READ_TYPED_PTR(s1,n1);
 CHECK_READ_TYPED_PTR(s2,n2);

 for(;;++s1,--n1,++s2,--n2)
 {
  if(n1==0)
  {
   if(n2==0)
    return 0;

   return -1;
  }//if

  if(n2==0)
   return 1;

  if(less_op(*s1,*s2))
   return -1;

  if(less_op(*s2,*s1))
   return 1;
 }//for[ever]
}//string_compare_v2 s1,n1,s2,n2,less_op

//------------------------------------------------------------------------
template<class charT>
int string_compare_v2(const charT* const s1,
                      size_t       const n1,
                      const charT* const s2,
                      size_t       const n2)
{
 return string_compare_v2
         (s1,
          n1,
          s2,
          n2,
          std::less<charT>());
}//string_compare_v2 s1,n1,s2,n2

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
