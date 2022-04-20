////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__string_compare_H_
#define _lcpi_lib_structure_utilities__string__string_compare_H_

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class charT,class LessOp>
int string_compare(const charT* sz_s1,
                   const charT* sz_s2,
                   LessOp       less_op);

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* sz_s1,
                   const charT* sz_s2);

//------------------------------------------------------------------------
template<class charT,class LessOp>
int string_compare(const charT* sz_s1,
                   const charT* s2,
                   size_t       n2,
                   LessOp       less_op);

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* sz_s1,
                   const charT* s2,
                   size_t       n2);

//------------------------------------------------------------------------
template<class charT,class LessOp>
int string_compare(const charT* s1,
                   size_t       n1,
                   const charT* sz_s2,
                   LessOp       less_op);

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* s1,
                   size_t       n1,
                   const charT* sz_s2);

//------------------------------------------------------------------------
template<class charT,class LessOp>
int string_compare(const charT* s1,
                   size_t       n1,
                   const charT* s2,
                   size_t       n2,
                   LessOp       less_op);

//------------------------------------------------------------------------
template<class charT>
int string_compare(const charT* s1,
                   size_t       n1,
                   const charT* s2,
                   size_t       n2);

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/utilities/string/string_compare.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
