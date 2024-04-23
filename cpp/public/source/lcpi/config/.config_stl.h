///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Library.
//                                               Dmitry Kovalenko. 30.09.2020.
#ifndef _cpp_public_lcpi_config__config_stl_H_
#define _cpp_public_lcpi_config__config_stl_H_

#include <lcpi/config/.config_compiler.h>

////////////////////////////////////////////////////////////////////////////////
//STL library IDs

#define LCPI_STL_LIBRARY_ID_VC12                   0x400000C0
#define LCPI_STL_LIBRARY_ID_VC14                   0x400000D0
#define LCPI_STL_LIBRARY_ID_VC15                   0x400000F0

////////////////////////////////////////////////////////////////////////////////
//definitions
//
// LCPI_STL_CONSTRUCTOR_FUNC
//  - STL-utility for constructing an object
//
// LCPI_STL_DESTROYER_FUNC
//  - STL-utility for destroying an object
//
// LCPI_STL_RANDOM_ITERATOR_BASE_CLASS(T,Distance,Pointer,Reference)
//  - base class of iterators for random access containers
//
// LCPI_STL_USE_FACET(FACET_TYPE,LOCALE)
//  - call of std::use_facet utility
//
// LCPI_STL_CAN_USE_ALLOCATOR_REBIND:
//  0 : std::allocator has not the template member struct rebind<U>::other
//  1 : std::allocator has the template member struct rebind<U>::other
//
// LCPI_STL_USE_ALLOCATOR(Allocator,T)
//  - for stupid STL from VC6 that does not support Allocator rebinding
//
// LCPI_STL_STREAMBUF_HAS_MODE_MEMBER
//  0 : std::basic_streambuf hasn't member _mode
//  1 : has
//
// LCPI_STL_HAS_STRTOLD
//  0 : hasn't '_strtold' function
//  1 : has
//
// LCPI_STL_HAS_WCSTOLD
//  0 : hasn't '_wcstold' function
//  1 : has
//
// LCPI_STL_DEF_BASIC_STRING(charT)
//  - std::basic_string<charT>
//
// LCPI_STL_BUG_IN_ISTREAMBUF_ITERATOR__EQUAL
//   bug in implementation of std::istreambuf_iterator::equal
//
//   1: has bug [Roque Wave STL all known version]
//   0: no bug
//
// LCPI_STL_HAS_ITERATOR_CATEGORY
//   0: iterator categories is not supported [BCB3]
//   1: can use iterator categories
//
// LCPI_STL_ITERATOR_CATEGORY(IteratorType)
//   get iterator category [iterator_traits<IteratorType>::iterator_category()]
//
// LCPI_STL_EXCEPTION_DCR_THROW_SPEC
//   throw-specification of ~std::exception
//
// LCPI_STL_EXCEPTION_WHAT_THROW_SPEC
//   throw-specification of std::exception::what
//
// LCPI_STL_BASIC_STRING_ERASE_USE_CONST_ITERATOR
//   0: basic_string::erase(iterator first,iterator last)
//   1: basic_string::erase(const_iterator first,const_iterator last)
//
// LCPI_STL_GET_STREAM_TELLP_VALUE(sb)
//   code for obtain stream.tellp() as simple (streamoff) type
//   for example: (sb.tellp().operator std::streamoff ())
//
// LCPI_STL_STREAMBUF_SETP(sb,pFirst,pNext,pLast)
//
// LCPI_STL_MOVE_VALUE(x)
//   std::move(x)
//
// LCPI_STL_FORWARD_VALUE(T,x)
//   std::forward<T>(x)
//
// LCPI_STL_HAS_ENABLE_IF
//  0 : hasn't 'std::enable_if' function
//  1 : has
//
// LCPI_STL_HAS_NEGATION
//  0 : hasn't 'std::negation' function
//  1 : has
//
// LCPI_STL_TO_STRING(value)
//   std::to_string(value)
//
// LCPI_STL_TO_WSTRING(value)
//   std::to_wstring(value)
//
///////////////////////////////////////////////////////////////////////////////
//Detect CRT Library ID

#if !defined(LCPI_STL_LIBRARY_ID)

# if !defined(LCPI_CPP_COMP_ID__CURRENT)
#  error "Unknown compiler"
# endif

# if    (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V120)
#  define LCPI_STL_LIBRARY_ID                              LCPI_STL_LIBRARY_ID_VC12
# elif  (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V140)
#  define LCPI_STL_LIBRARY_ID                              LCPI_STL_LIBRARY_ID_VC14
# elif  (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V150)
#  define LCPI_STL_LIBRARY_ID                              LCPI_STL_LIBRARY_ID_VC15
# else
#  error "Can't detect CRT ID. Unknown complier."
# endif
#endif //LCPI_STL_LIBRARY_ID


//////////////////////////////////////////////////////////////////////////
//Include specific config headers


#if (LCPI_STL_LIBRARY_ID==LCPI_STL_LIBRARY_ID_VC15)
# include <lcpi/config/stl/.config_stl__vc15.h>

#elif (LCPI_STL_LIBRARY_ID==LCPI_STL_LIBRARY_ID_VC14)
# include <lcpi/config/stl/.config_stl__vc14.h>

#elif (LCPI_STL_LIBRARY_ID==LCPI_STL_LIBRARY_ID_VC12)
# include <lcpi/config/stl/.config_stl__vc12.h>

#else
# error "UNKNOWN STL"

#endif

////////////////////////////////////////////////////////////////////////////////
#endif

