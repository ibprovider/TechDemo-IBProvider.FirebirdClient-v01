////////////////////////////////////////////////////////////////////////////////
//STL configurations. Using VC12 library
//                                                Dmitry Kovalenko. 11.05.2011
#ifndef _cpp_public_lcpi_lib__config_stl__vc12_H_
#define _cpp_public_lcpi_lib__config_stl__vc12_H_

////////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------
#define  LCPI_STL_CONSTRUCTOR_FUNC             std::_Construct
#define  LCPI_STL_DESTROYER_FUNC               std::_Destroy

//------------------------------------------------------------------------
#define LCPI_STL_RANDOM_ITERATOR_BASE_CLASS(T,                           \
                                         Distance,                       \
                                         Pointer,                        \
                                         Reference)                      \
         std::iterator<std::random_access_iterator_tag,                  \
                       T,                                                \
                       Distance,                                         \
                       Pointer,                                          \
                       Reference>

//------------------------------------------------------------------------
#define LCPI_STL_USE_FACET(FACET_TYPE,LOCALE)                            \
         std::use_facet<FACET_TYPE>(LOCALE)

//------------------------------------------------------------------------
#define LCPI_STL_CAN_USE_ALLOCATOR_REBIND              1

#define LCPI_STL_USE_ALLOCATOR(Allocator,T)            Allocator

//------------------------------------------------------------------------
#define LCPI_STL_STREAMBUF_HAS_MODE_MEMBER             0

#define LCPI_STL_HAS_STRTOLD                           0
#define LCPI_STL_HAS_WCSTOLD                           0

//------------------------------------------------------------------------
#define LCPI_STL_DEF_BASIC_STRING(charT)                                 \
         std::basic_string<charT>

//------------------------------------------------------------------------
#define LCPI_STL_BUG_IN_ISTREAMBUF_ITERATOR__EQUAL     0

//------------------------------------------------------------------------
#define LCPI_STL_HAS_ITERATOR_CATEGORY                 1

//------------------------------------------------------------------------
#define LCPI_STL_ITERATOR_CATEGORY(IteratorType)                         \
 (std::iterator_traits<IteratorType>::iterator_category())

//------------------------------------------------------------------------
#define LCPI_STL_EXCEPTION_DCR_THROW_SPEC

//------------------------------------------------------------------------
#define LCPI_STL_EXCEPTION_WHAT_THROW_SPEC

//------------------------------------------------------------------------
#define LCPI_STL_BASIC_STRING_ERASE_USE_CONST_ITERATOR               1

//------------------------------------------------------------------------
#define LCPI_STL_GET_STREAM_TELLP_VALUE(sb)                              \
         (sb.tellp().operator std::streamoff ())

//------------------------------------------------------------------------
#define LCPI_STL_STREAMBUF_SETP(sb,pFirst,pNext,pLast)                   \
 ( (sb).setp( (pFirst) , (pNext) , (pLast) ) )

//------------------------------------------------------------------------
#define LCPI_STL_MOVE_VALUE(x) std::move(x)

//------------------------------------------------------------------------
#define LCPI_STL_FORWARD_VALUE(T,x) std::forward<T>(x)

//------------------------------------------------------------------------
#define LCPI_STL_HAS_ENABLE_IF                         0

//------------------------------------------------------------------------
#define LCPI_STL_HAS_NEGATION                          0

////////////////////////////////////////////////////////////////////////////////
#endif
