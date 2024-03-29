////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Configuration.
//                                               Dmitry Kovalenko. 30.09.2020.
#ifndef _cpp_public_lcpi_config__config_compiler_H_
#define _cpp_public_lcpi_config__config_compiler_H_

////////////////////////////////////////////////////////////////////////////////
//Definitions
//
// LCPI_CPP_CFG__METHOD__OVERRIDE
//
// LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL
//
// LCPI_CPP_CFG__CLASS__FINAL
//
// LCPI_CPP_CFG__DECLSPEC__NORETURN
//
// LCPI_CPP_CFG__DECLSPEC__NOVTABLE
//
//------------------------------------------------------------------------
//
// LCPI_CPP_CFG__SUPPORT_MEMBER_TEMPLATE
//  - compiler support member templates
//
// LCPI_CPP_CFG__SUPPORT_TEMPLATE_FUNC_RET_INNER_TYPE
//  - support template likes
//     template<class T>
//     typename T::value_type* func(T& x);
//
// LCPI_CPP_CFG__STABLE_PURE_METHOD_IN_TEMPLATE
//  - can use pure virtual methods in templates
//    BCB5 has bug compiler with this things
//
// LCPI_CPP_CFG__ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL
//  - compiler allow define copy constructor without implementation
//     in exception base classes
//    VC8 has bug compiler with this things
//
// LCPI_CPP_CFG__SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN
//  - support template function specializations like
//     template<class T> T func<spec_type1>(arg)
//     template<class T> T func<spec_type2>(arg)
//
// LCPI_CPP_CFG__TYPENAME_INIT_ARGUMENT(T)
//  - argumnent for init contructors
//
// LCPI_CPP_CFG__SUPPORT_OPERATOR_DELETE_EX
//  - full support of member operator delete. For example:
//      void delete (void*,void*)
//      void delete (void*,allocator&)
//
// LCPI_CPP_CFG__SUPPORT_PRAGMA_STARTUP
//  - support #pragma startup
//
// LCPI_CPP_CFG__SUPPORT_PRAGMA_ARGSUSED
//  - support #pragma argsused
//
// LCPI_CPP_CFG__SUPPORT_PRAGMA_ONCE
//  - support #pragma once
//
// LCPI_CPP_CFG__DLL_EXPORT
//  - keyword for export functions in DLL
//    __export or __declspec(dllexport)
//
// LCPI_CPP_CFG__CAN_USE_ACCESS_USING_IN_TEMPLATE
//  - can declare
//     using inherited_class::member
//    in template class
//
// LCPI_CPP_CFG__SUPPORT_CDECL_MEMBER
//  - support __cdecl
//
// LCPI_CPP_CFG__SUPPORT_STDCALL_MEMBER
//  - support __stdcall
//
// LCPI_CPP_CFG__SUPPORT_THISCALL_MEMBER
//  - support __thiscall
//
// LCPI_CPP_CFG__SUPPORT_CLRCALL_MEMBER
//  - support __clrcall
//
// LCPI_CPP_CFG__HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64
//  - BCB5 has problem with inlining of structure::can_numeric_cast<i64,ui64>(ui64)
//
// LCPI_CPP_CFG__SUPPORT_VARIADIC_TEMPLATES
//  - support template<class ...Arg>
//
// -----------------------------------------------------------------------
//
// LCPI_CPP_CFG__SUPPORT_RVALUE_REFERENCE
//  - support T&&
//
// LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE
//    - 0
//    - 1
//
// LCPI_CPP_CFG__SUPPORT_CPP_NULLPTR
//  - support of "nullptr" keyword (C++11)
//    - 0
//    - 1
//
// LCPI_CPP_CFG__SUPPORT_STATIC_ASSERT
//  - support of "static_assert"
//    - 0
//    - 1
//
// LCPI_CPP_CFG__SUPPORT_TEMPLATE_USING
//  - support of "template<...> using"
//    - 0
//    - 1
//
// LCPI_CPP_CFG__SUPPORT_ENUM_CLASS
//  - support of "enum class"
//    - 0
//    - 1
//
// LCPI_CPP_CFG__HAS_PROBLEM_WITH_TEMPLATE_001
//  - VS2008 can instance structure::t_basic_const_string_data__static<charT,staticSTR>,
//    where staticSTR is structure::t_basic_const_string::sm_emptyStr
//    - 0
//    - 1

////////////////////////////////////////////////////////////////////////////////
//Borland specific

// LCPI_CPP_CFG__BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED
//  - stupid warning in compare of (unsigned word) and (unsigned int)

////////////////////////////////////////////////////////////////////////////////
//Known compiler IDs

#define LCPI_CPP_COMP_ID__VISUALC_V120         0x400000C0
#define LCPI_CPP_COMP_ID__VISUALC_V140         0x400000E0
#define LCPI_CPP_COMP_ID__VISUALC_V150         0x400000F0

////////////////////////////////////////////////////////////////////////////////
//Detect compiler ID

#if !defined(LCPI_CPP_COMP_ID__CURRENT)

# if defined(_MSC_VER)

#  if   (_MSC_VER>=1910)
#    define LCPI_CPP_COMP_ID__CURRENT                   LCPI_CPP_COMP_ID__VISUALC_V150
#  elif (_MSC_VER>=1900)
#    define LCPI_CPP_COMP_ID__CURRENT                   LCPI_CPP_COMP_ID__VISUALC_V140
#  elif (_MSC_VER>=1800)
#    define LCPI_CPP_COMP_ID__CURRENT                   LCPI_CPP_COMP_ID__VISUALC_V120
#  else (_MSC_VER>=1700)
#    error Unsupported VC++ compiler
#  endif

# endif

# if !defined(LCPI_CPP_COMP_ID__CURRENT)
#  error Unknown Compiler
# endif

#endif //!defined(LCPI_CPP_COMP_ID__CURRENT)

////////////////////////////////////////////////////////////////////////////////
//Config for current compiler

//VC140 ------------------------------------------------------------------
#if (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V150)

# include <lcpi/config/compiler/.config_compiler__vc14.h>

#endif //LCPI_CPP_COMP_ID__VISUALC_V150

//VC140 ------------------------------------------------------------------
#if (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V140)

# include <lcpi/config/compiler/.config_compiler__vc14.h>

#endif //LCPI_CPP_COMP_ID__VISUALC_V140

//VC120 ------------------------------------------------------------------
#if (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V120)

# include <lcpi/config/compiler/.config_compiler__vc12.h>

#endif //LCPI_CPP_COMP_ID__VISUALC_V120

////////////////////////////////////////////////////////////////////////////////
//Verifications

#ifndef LCPI_CPP_CFG__METHOD__OVERRIDE
# error LCPI_CPP_CFG__METHOD__OVERRIDE is not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL
# error LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL is not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__CLASS__FINAL
# error LCPI_CPP_CFG__CLASS__FINAL is not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__DECLSPEC__NORETURN
# error LCPI_CPP_CFG__DECLSPEC__NORETURN is not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__DECLSPEC__NOVTABLE
# error LCPI_CPP_CFG__DECLSPEC__NOVTABLE is not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__CAN_USE__signed_long
# error LCPI_CPP_CFG__CAN_USE__signed_long is not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__CAN_USE__unsigned_long
# error LCPI_CPP_CFG__CAN_USE__unsigned_long is not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__CAN_USE__wchar_t
# error LCPI_CPP_CFG__CAN_USE__wchar_t is not defined
#endif

////////////////////////////////////////////////////////////////////////////////
//OLD Names [deprecated]

#define COMP_CONF_SUPPORT_MEMBER_TEMPLATE                          LCPI_CPP_CFG__SUPPORT_MEMBER_TEMPLATE
#define COMP_CONF_SUPPORT_TEMPLATE_FUNC_RET_INNER_TYPE             LCPI_CPP_CFG__SUPPORT_TEMPLATE_FUNC_RET_INNER_TYPE

#define COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE                   LCPI_CPP_CFG__STABLE_PURE_METHOD_IN_TEMPLATE
#define COMP_CONF_ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL   LCPI_CPP_CFG__ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL

#define COMP_CONF_SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN       LCPI_CPP_CFG__SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN
#define COMP_CONF_SUPPORT_OPERATOR_DELETE_EX                       LCPI_CPP_CFG__SUPPORT_OPERATOR_DELETE_EX
#define COMP_CONF_SUPPORT_PRAGMA_STARTUP                           LCPI_CPP_CFG__SUPPORT_PRAGMA_STARTUP
#define COMP_CONF_SUPPORT_PRAGMA_ARGSUSED                          LCPI_CPP_CFG__SUPPORT_PRAGMA_ARGSUSED
#define COMP_CONF_SUPPORT_PRAGMA_ONCE                              LCPI_CPP_CFG__SUPPORT_PRAGMA_ONCE

#define COMP_CONF_DLL_EXPORT                                       LCPI_CPP_CFG__DLL_EXPORT

#define COMP_CONF_CAN_USE_ACCESS_USING_IN_TEMPLATE                 LCPI_CPP_CFG__CAN_USE_ACCESS_USING_IN_TEMPLATE

#define COMP_CONF_SUPPORT_CDECL_MEMBER                             LCPI_CPP_CFG__SUPPORT_CDECL_MEMBER
#define COMP_CONF_SUPPORT_STDCALL_MEMBER                           LCPI_CPP_CFG__SUPPORT_STDCALL_MEMBER
#define COMP_CONF_SUPPORT_THISCALL_MEMBER                          LCPI_CPP_CFG__SUPPORT_THISCALL_MEMBER
#define COMP_CONF_SUPPORT_CLRCALL_MEMBER                           LCPI_CPP_CFG__SUPPORT_CLRCALL_MEMBER

#define COMP_CONF_HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64       LCPI_CPP_CFG__HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64

#define COMP_CONF_SUPPORT_VARIADIC_TEMPLATES                       LCPI_CPP_CFG__SUPPORT_VARIADIC_TEMPLATES

#define COMP_CONF_SUPPORT_RVALUE_REFERENCE                         LCPI_CPP_CFG__SUPPORT_RVALUE_REFERENCE

#define COMP_CONF_CAN_DETECT_UNUSED_CODE                           LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE

#define COMP_CONF_SUPPORT_CPP_NULLPTR                              LCPI_CPP_CFG__SUPPORT_CPP_NULLPTR

#define COMP_CONF_SUPPORT_STATIC_ASSERT                            LCPI_CPP_CFG__SUPPORT_STATIC_ASSERT

#define COMP_CONF_SUPPORT_TEMPLATE_USING                           LCPI_CPP_CFG__SUPPORT_TEMPLATE_USING

#define COMP_CONF_SUPPORT_ENUM_CLASS                               LCPI_CPP_CFG__SUPPORT_ENUM_CLASS

#define COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001                    LCPI_CPP_CFG__HAS_PROBLEM_WITH_TEMPLATE_001

////////////////////////////////////////////////////////////////////////////////
//define compiler workaround

#if !defined(LCPI_CPP_CFG__STABLE_PURE_METHOD_IN_TEMPLATE)
# error LCPI_CPP_CFG__STABLE_PURE_METHOD_IN_TEMPLATE is not defined.
#endif

#if(LCPI_CPP_CFG__STABLE_PURE_METHOD_IN_TEMPLATE)
# define LCPI_CPP_CODE__W000001_PURE_METHOD           =0
#else
# define LCPI_CPP_CODE__W000001_PURE_METHOD
#endif

#define COMP_W000001_PURE_METHOD LCPI_CPP_CODE__W000001_PURE_METHOD

////////////////////////////////////////////////////////////////////////////////

#if !defined(LCPI_CPP_CFG__ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL)
# error LCPI_CPP_CFG__ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL is not defined.
#endif

#if(LCPI_CPP_CFG__ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL)
# define LCPI_CPP_CODE__W000002_COPY_CTOR_IMPL        ;
#else
# define LCPI_CPP_CODE__W000002_COPY_CTOR_IMPL        {assert(false);}
#endif

#define COMP_W000002_COPY_CTOR_IMPL LCPI_CPP_CODE__W000002_COPY_CTOR_IMPL

////////////////////////////////////////////////////////////////////////////////
//Build unused code

#if !defined(LCPI_CPP_CFG__BUILD_UNUSED_CODE)

# if defined COMP_BUILD_UNUSED_CODE
#  error COMP_BUILD_UNUSED_CODE is defined!
# endif

# if !defined(LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE)
#  error LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE is not defined.
# endif

# if   (LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE==0)
#  define LCPI_CPP_CFG__BUILD_UNUSED_CODE             1
# elif (LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE==1)
#  if defined(NDEBUG)
#   define LCPI_CPP_CFG__BUILD_UNUSED_CODE            0
#  else
#   define LCPI_CPP_CFG__BUILD_UNUSED_CODE            1
#  endif
# else
#  error Unexpected value of LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE.
# endif

# endif

#define COMP_BUILD_UNUSED_CODE LCPI_CPP_CFG__BUILD_UNUSED_CODE

////////////////////////////////////////////////////////////////////////////////
#endif
