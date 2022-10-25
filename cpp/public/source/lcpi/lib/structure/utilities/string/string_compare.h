////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__string_compare_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__string_compare_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
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
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/string/string_compare.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
