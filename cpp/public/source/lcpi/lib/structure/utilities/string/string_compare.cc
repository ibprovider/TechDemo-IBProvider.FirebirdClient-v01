////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__string_compare_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string__string_compare_CC_

#include <lcpi/lib/structure/t_negative_one.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//string comparer

template<class charT,class LessOp>
int string_compare(const charT* sz_s1,
                   const charT* sz_s2,
                   LessOp       less_op)
{
 if(sz_s1==nullptr)
 {
  if(sz_s2==nullptr || !(*sz_s2))
   return 0;

  return -1;
 }//if

 if(sz_s2==nullptr)
 {
  if(!(*sz_s1))
   return 0;

  return 1;
 }//if

 for(;;++sz_s1,++sz_s2)
 {
  if(!(*sz_s1))
  {
   if(!(*sz_s2))
    return 0;

   return -1;
  }//if

  if(!(*sz_s2))
   return 1;

  if(less_op(*sz_s1,*sz_s2))
   return -1;

  if(less_op(*sz_s2,*sz_s1))
   return 1;
 }//for
}//string_compare sz_s1,sz_s2,less_op

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* const sz_s1,
                   const charT* const sz_s2)
{
 return string_compare(sz_s1,sz_s2,std::less<charT>());
}//string_compare sz_s1,sz_s2

//------------------------------------------------------------------------
template<class charT,class LessOp>
int string_compare(const charT* sz_s1,
                   const charT* s2,
                   size_t       n2,
                   LessOp       less_op)
{
 if(s2==nullptr || structure::is_negative_one(n2))
  return string_compare(sz_s1,s2,less_op);

 if(sz_s1==nullptr)
 {
  if(n2==0)
   return 0;

  return -1;
 }//if

 for(;;++sz_s1,++s2,--n2)
 {
  if(!(*sz_s1))
  {
   if(n2==0)
    return 0;

   return -1;
  }//if

  if(n2==0)
   return 1;

  if(less_op(*sz_s1,*s2))
   return -1;

  if(less_op(*s2,*sz_s1))
   return 1;
 }//for[ever]
}//string_compare sz_s1,s2

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* const sz_s1,
                   const charT* const s2,
                   size_t       const n2)
{
 return string_compare(sz_s1,s2,n2,std::less<charT>());
}//string_compare sz_s1,s2

//------------------------------------------------------------------------
template<class charT,class LessOp>
int string_compare(const charT* const s1,
                   size_t       const n1,
                   const charT* const sz_s2,
                   LessOp       const less_op)
{
 return -string_compare(sz_s2,s1,n1,less_op);
}//string_compare s1<sz_s2

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* s1,
                   size_t       n1,
                   const charT* sz_s2)
{
 return -string_compare(sz_s2,s1,n1,std::less<charT>());
}//string_compare s1,sz_s2

//------------------------------------------------------------------------
template<class charT,class LessOp>
int string_compare(const charT* s1,
                   size_t       n1,
                   const charT* s2,
                   size_t       n2,
                   LessOp       less_op)
{
 if(s1==nullptr || structure::is_negative_one(n1))
  return string_compare(s1,s2,n2,less_op);

 if(s2==nullptr || structure::is_negative_one(n2))
  return string_compare(s1,n1,s2,less_op);

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
 }//for
}//string_compare s1,s2

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* const s1,
                   size_t       const n1,
                   const charT* const s2,
                   size_t       const n2)
{
 return string_compare
         (s1,
          n1,
          s2,
          n2,
          std::less<charT>());
}//string_compare s1,s2

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
