////////////////////////////////////////////////////////////////////////////////
//STL configurations. Using VC6 library
//                                                Dmitry Kovalenko. 17.02.2005.
#ifndef _config_stl__vc6_H_
#define _config_stl__vc6_H_

////////////////////////////////////////////////////////////////////////////////

#define  __STL_CONSTRUCTOR_FUNC             _Construct
#define  __STL_DESTROYER_FUNC               _Destroy

//------------------------------------------------------------------------
#define __STL_RANDOM_ITERATOR_BASE_CLASS(T,                              \
                                         Distance,                       \
                                         Pointer,                        \
                                         Reference)                      \
         std::iterator<std::random_access_iterator_tag,                  \
                       T,                                                \
                       Distance>

//------------------------------------------------------------------------
#define __STL_USE_FACET(FACET_TYPE,LOCALE)          _USEFAC(LOCALE,FACET_TYPE)

//------------------------------------------------------------------------
#define __STL_CAN_USE_ALLOCATOR_REBIND              0

#define __STL_USE_ALLOCATOR(Allocator,T)                                 \
 structure::t_allocator_interface< Allocator , T >

//------------------------------------------------------------------------
#define __STL_STREAMBUF_HAS_MODE_MEMBER             0

#define __STL_HAS_STRTOLD                           0
#define __STL_HAS_WCSTOLD                           0

//------------------------------------------------------------------------
#define __STL_DEF_BASIC_STRING(charT)                                    \
         std::basic_string<charT>

//------------------------------------------------------------------------
#define __STL_BUG_IN_ISTREAMBUF_ITERATOR__EQUAL     0

//------------------------------------------------------------------------
#define __STL_EXCEPTION_DCR_THROW_SPEC

//------------------------------------------------------------------------
#define __STL_EXCEPTION_WHAT_THROW_SPEC

////////////////////////////////////////////////////////////////////////////////
#endif
