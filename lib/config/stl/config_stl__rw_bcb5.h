////////////////////////////////////////////////////////////////////////////////
//STL configuration. Rogue Wave STL [BCB5]
//                                                Dmitry Kovalenko. 01.08.2003.
#ifndef _config_stl__rw_bcb5_H_
#define _config_stl__rw_bcb5_H_

////////////////////////////////////////////////////////////////////////////////
//say, that need create implemntation of STL templates

#define _RWSTD_COMPILE_INSTANTIATE

////////////////////////////////////////////////////////////////////////////////
#include <structure/cfg_stl/t_cfg_stl_rw_bcb.h>

////////////////////////////////////////////////////////////////////////////////
#define __STL_RANDOM_ITERATOR_BASE_CLASS(T,                              \
                                         Distance,                       \
                                         Pointer,                        \
                                         Reference)                      \
         std::iterator<std::random_access_iterator_tag,                  \
                       T,                                                \
                       Distance,                                         \
                       Pointer,                                          \
                       Reference>

//------------------------------------------------------------------------
#define __STL_USE_FACET(FACET_TYPE,LOCALE)                               \
         std::use_facet<FACET_TYPE>(LOCALE)

//------------------------------------------------------------------------
#define __STL_CAN_USE_ALLOCATOR_REBIND              1

#define __STL_USE_ALLOCATOR(Allocator,T)            Allocator

//------------------------------------------------------------------------
#define __STL_STREAMBUF_HAS_MODE_MEMBER             1

#define __STL_HAS_STRTOLD                           1
#define __STL_HAS_WCSTOLD                           1

//------------------------------------------------------------------------
#define __STL_DEF_BASIC_STRING(charT)                                    \
         std::basic_string<charT>

//------------------------------------------------------------------------
#define __STL_BUG_IN_ISTREAMBUF_ITERATOR__EQUAL     1

//------------------------------------------------------------------------
#define __STL_HAS_ITERATOR_CATEGORY                 1

//------------------------------------------------------------------------
#define __STL_ITERATOR_CATEGORY(IteratorType)                            \
 (std::__iterator_category(IteratorType()))

//------------------------------------------------------------------------
#define __STL_EXCEPTION_DCR_THROW_SPEC              _RWSTD_THROW_SPEC_NULL

//------------------------------------------------------------------------
#define __STL_EXCEPTION_WHAT_THROW_SPEC             _RWSTD_THROW_SPEC_NULL

//------------------------------------------------------------------------
#define __STL_BASIC_STRING_ERASE_USE_CONST_ITERATOR               0

//------------------------------------------------------------------------
#define __STL_GET_STREAM_TELLP_VALUE(sb)                                 \
         (sb.tellp().operator std::streamoff ())

//------------------------------------------------------------------------
#define __STL_STREAMBUF_SETP(sb,pFirst,pNext,pLast)                      \
 ( ((sb).setp((pFirst),(pLast))),                                        \
   ((sb).pbump((pNext)-(pFirst))) )

//------------------------------------------------------------------------
#define __STL_MOVE_VALUE(x) (x)

//------------------------------------------------------------------------
//#define __STL_FORWARD_VALUE(T,x) (x)

////////////////////////////////////////////////////////////////////////////////
#endif
