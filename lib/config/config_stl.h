////////////////////////////////////////////////////////////////////////////////
//STL configurations.
//                                               Dmitry Kovalenko. 16.07.2003.
#ifndef _config_stl_H_
#define _config_stl_H_

////////////////////////////////////////////////////////////////////////////////
//standart namespaces

#if 0 // [2019-10-24] Bye
namespace std{}

using namespace std; //Standart Template Library
#endif

////////////////////////////////////////////////////////////////////////////////
//STL library IDs

// __STL_LIBRARY_ID

// Enumeration IDs of known STL libraries

//STLPort
#define __STL_LIBRARY_ID_STLPORT                0x10000000

//Rogue Wave STL [BCB3]
#define __STL_LIBRARY_ID_RW_BCB3                0x20000030

//Rogue Wave STL [BCB5]
#define __STL_LIBRARY_ID_RW_BCB5                0x20000050

//Visual Studio Library
#define __STL_LIBRARY_ID_VC6                    0x40000060
#define __STL_LIBRARY_ID_VC7                    0x40000070
#define __STL_LIBRARY_ID_VC8                    0x40000080
#define __STL_LIBRARY_ID_VC9                    0x40000090
#define __STL_LIBRARY_ID_VC10                   0x400000A0
#define __STL_LIBRARY_ID_VC15                   0x400000F0

////////////////////////////////////////////////////////////////////////////////
//definitions
//
// __STL_CONSTRUCTOR_FUNC
//  - STL-utility for constructing an object
//
// __STL_DESTROYER_FUNC
//  - STL-utility for destroying an object
//
// __STL_RANDOM_ITERATOR_BASE_CLASS(T,Distance,Pointer,Reference)
//  - base class of iterators for random access containers
//
// __STL_USE_FACET(FACET_TYPE,LOCALE)
//  - call of std::use_facet utility
//
// __STL_CAN_USE_ALLOCATOR_REBIND:
//  0 : std::allocator has not the template member struct rebind<U>::other
//  1 : std::allocator has the template member struct rebind<U>::other
//
// __STL_USE_ALLOCATOR(Allocator,T)
//  - for stupid STL from VC6 that does not support Allocator rebinding
//
// __STL_STREAMBUF_HAS_MODE_MEMBER
//  0 : std::basic_streambuf hasn't member _mode
//  1 : has
//
// __STL_HAS_STRTOLD
//  0 : hasn't '_strtold' function
//  1 : has
//
// __STL_HAS_WCSTOLD
//  0 : hasn't '_wcstold' function
//  1 : has
//
// __STL_DEF_BASIC_STRING(charT)
//  - std::basic_string<charT>
//
// __STL_BUG_IN_ISTREAMBUF_ITERATOR__EQUAL
//   bug in implementation of std::istreambuf_iterator::equal
//
//   1: has bug [Roque Wave STL all known version]
//   0: no bug
//
// __STL_HAS_ITERATOR_CATEGORY
//   0: iterator categories is not supported [BCB3]
//   1: can use iterator categories
//
// __STL_ITERATOR_CATEGORY(IteratorType)
//   get iterator category [iterator_traits<IteratorType>::iterator_category()]
//
// __STL_EXCEPTION_DCR_THROW_SPEC
//   throw-specification of ~std::exception
//
// __STL_EXCEPTION_WHAT_THROW_SPEC
//   throw-specification of std::exception::what
//
// __STL_BASIC_STRING_ERASE_USE_CONST_ITERATOR
//   0: basic_string::erase(iterator first,iterator last)
//   1: basic_string::erase(const_iterator first,const_iterator last)
//
// __STL_GET_STREAM_TELLP_VALUE(sb)
//   code for obtain stream.tellp() as simple (streamoff) type
//   for example: (sb.tellp().operator std::streamoff ())
//
// __STL_STREAMBUF_SETP(sb,pFirst,pNext,pLast)
//
// __STL_MOVE_VALUE(x)
//   std::move(x)
//
// __STL_FORWARD_VALUE(T,x)
//   std::forward<T>(x)
//
////////////////////////////////////////////////////////////////////////////////

#if !defined(__STL_LIBRARY_ID) //Automated detect STL Library ID

# if defined(__BORLANDC__)

#  if   (__BORLANDC__>=0x0570) //------------------------------------------

#   if  !defined(_USE_OLDER_RW_STL)

#    define __STL_LIBRARY_ID             __STL_LIBRARY_ID_VC7 //NOT TESTED

#   endif

#  elif (__BORLANDC__>=0x0560)

#   if !defined(_USE_OLD_RW_STL)

#    define __STL_LIBRARY_ID             __STL_LIBRARY_ID_STLPORT

#   elif defined(_STLPORT_VERSION) //--------------------------------------

#    define __STL_LIBRARY_ID             __STL_LIBRARY_ID_STLPORT

#   endif

#  endif //BCB6

#  if !defined(__STL_LIBRARY_ID)  //Try detect STLPort -------------------

#   include <stddef>

#   if defined(_STLPORT_VERSION)
#    define __STL_LIBRARY_ID             __STL_LIBRARY_ID_STLPORT
#   endif

#  endif //Try detect STLPort

#  if !defined(__STL_LIBRARY_ID)  //Roque Wave Library -------------------

#   include <stdcomp.h> // _RWSTD_VER

#   if    (_RWSTD_VER==0x0201)
#     define __STL_LIBRARY_ID            __STL_LIBRARY_ID_RW_BCB3

#   elif (_RWSTD_VER==0x020101)
#     define __STL_LIBRARY_ID            __STL_LIBRARY_ID_RW_BCB5

#   else
#     error "Unknown Roque Wave Library"
#   endif

#  endif //Roque Wave Library

// __BORLANDC__

# elif defined(_MSC_VER)

#  if   _MSC_VER>=1910
#   define __STL_LIBRARY_ID __STL_LIBRARY_ID_VC15
#  elif _MSC_VER>=1600
#   define __STL_LIBRARY_ID __STL_LIBRARY_ID_VC10
#  elif _MSC_VER>=1500
#   define __STL_LIBRARY_ID __STL_LIBRARY_ID_VC9
#  elif _MSC_VER>=1400
#   define __STL_LIBRARY_ID __STL_LIBRARY_ID_VC8
#  elif _MSC_VER>=1300
#   define __STL_LIBRARY_ID __STL_LIBRARY_ID_VC7
#  elif _MSC_VER>=1000
#   define __STL_LIBRARY_ID __STL_LIBRARY_ID_VC6
#  endif

# endif //_MSC_VER

# if !defined(__STL_LIBRARY_ID)
#  error "UNKNOWN STL"
# endif

#endif //Automated detect STL Library ID

//////////////////////////////////////////////////////////////////////////
//Include specific config headers

#if   (__STL_LIBRARY_ID==__STL_LIBRARY_ID_STLPORT)
# error STLPort longer not supported

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_RW_BCB3)
# error BCB3 longer not supported

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_RW_BCB5)
# include <config/stl/config_stl__rw_bcb5.h>

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_VC15)
# include <config/stl/config_stl__vc15.h>

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_VC10)
# include <config/stl/config_stl__vc10.h>

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_VC9)
# include <config/stl/config_stl__vc9.h>

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_VC8)
# include <config/stl/config_stl__vc8.h>

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_VC7)
# include <config/stl/config_stl__vc7.h>

#elif (__STL_LIBRARY_ID==__STL_LIBRARY_ID_VC6)
# include <config/stl/config_stl__vc6.h>

#else
# error "UNKNOWN STL"

#endif

////////////////////////////////////////////////////////////////////////////////
#endif

