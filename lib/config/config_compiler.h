////////////////////////////////////////////////////////////////////////////////
//COMPILER CONFIGURATION FILE
//                                        Kovalenko Dmitry. 10 september, 2002.
#ifndef _config_compiler_H_
#define _config_compiler_H_

////////////////////////////////////////////////////////////////////////////////
//defines
//
// COMP_CONF_SUPPORT_MEMBER_TEMPLATE
//  - compiler support member templates
//
// COMP_CONF_SUPPORT_TEMPLATE_FUNC_RET_INNER_TYPE
//  - support template likes
//     template<class T>
//     typename T::value_type* func(T& x);
//
// COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE
//  - can use pure virtual methods in templates
//    BCB5 has bug compiler with this things
//
// COMP_CONF_ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL
//  - compiler allow define copy constructor without implementation
//     in exception base classes
//    VC8 has bug compiler with this things
//
// COMP_CONF_SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN
//  - support template function specializations like
//     template<class T> T func<spec_type1>(arg)
//     template<class T> T func<spec_type2>(arg)
//
// COMP_CONF_TYPENAME_INIT_ARGUMENT(T)
//  - argumnent for init contructors
//
// COMP_CONF_SUPPORT_OPERATOR_DELETE_EX
//  - full support of member operator delete. For example
//    void delete (void*,void*)
//    void delete (void*,allocator&)
//
// COMP_CONF_SUPPORT_PRAGMA_STARTUP
//  - support #pragma startup
//
// COMP_CONF_SUPPORT_PRAGMA_ARGSUSED
//  - support #pragma argsused
//
// COMP_CONF_SUPPORT_PRAGMA_ONCE
//  - support #pragma once
//
// COMP_CONF_DLL_EXPORT
//  - keyword for export functions in DLL
//    __export or __declspec(dllexport)
//
// COMP_CONF_DECLSPEC_NOVTABLE
//  - __declspec(novtable)
//
// COMP_CONF_DECLSPEC_NORETURN
//  - __declspec(noreturn)
//
// COMP_CONF_CAN_USE_ACCESS_USING_IN_TEMPLATE
//  - can declare
//     using inherited_class::member
//    in template class
//
// COMP_CONF_SUPPORT_CDECL_MEMBER
//  - support __cdecl
//
// COMP_CONF_SUPPORT_STDCALL_MEMBER
//  - support __stdcall
//
// COMP_CONF_SUPPORT_THISCALL_MEMBER
//  - support __thiscall
//
// COMP_CONF_SUPPORT_CLRCALL_MEMBER
//  - support __clrcall
//
// COMP_CONF_HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64
//  - BCB5 has problem with inlining of structure::can_numeric_cast<i64,ui64>(ui64)
//
// COMP_CONF_SUPPORT_VARIADIC_TEMPLATES
//  - support template<class ...Arg>
//
// -----------------------------------------------------------------------
//
// COMP_CONF_SUPPORT_RVALUE_REFERENCE
//  - support T&&
//
// COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_OVERRIDE
//  - support 'override' modificator for virtual methods
//
// COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL
//  - support 'final' modificator for virtual methods. possible value
//    - 0 (none)
//    - 1 (final)
//    - 2 (sealed)
//
// COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL
//  - support 'final' declaration of classes. possible value
//    - 0 (none)
//    - 1 (final)
//    - 2 (sealed)
//
// COMP_CONF_CAN_DETECT_UNUSED_CODE
//    - 0
//    - 1
//
// COMP_CONF_SUPPORT_CPP_NULLPTR
//  - support of "nullptr" keyword (C++11)
//    - 0
//    - 1
//
// COMP_CONF_SUPPORT_STATIC_ASSERT
//  - support of "static_assert"
//    - 0
//    - 1
//
// COMP_CONF_SUPPORT_TEMPLATE_USING
//  - support of "template<...> using"
//    - 0
//    - 1
//
// COMP_CONF_SUPPORT_ENUM_CLASS
//  - support of "enum class"
//    - 0
//    - 1
//
// COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001
//  - VS2008 can instance structure::t_basic_const_string_data__static<charT,staticSTR>,
//    where staticSTR is structure::t_basic_const_string::sm_emptyStr
//    - 0
//    - 1

////////////////////////////////////////////////////////////////////////////////
//Borland specific

// COMP_CONF_BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED
//  - stupid warning in compare of (unsigned word) and (unsigned int)

////////////////////////////////////////////////////////////////////////////////
//Known compiler IDs

#define __COMP_ID_BORLAND_CBUILDER3                  0x20000030
#define __COMP_ID_BORLAND_CBUILDER4                  0x20000040
#define __COMP_ID_BORLAND_CBUILDER5                  0x20000050
#define __COMP_ID_BORLAND_CBUILDER6                  0x20000060
#define __COMP_ID_BORLAND_CBUILDER7                  0x20000070

#define __COMP_ID_VISUALC_V60                        0x40000060
#define __COMP_ID_VISUALC_V70                        0x40000070
#define __COMP_ID_VISUALC_V80                        0x40000080
#define __COMP_ID_VISUALC_V90                        0x40000090
#define __COMP_ID_VISUALC_V100                       0x400000A0
#define __COMP_ID_VISUALC_V110                       0x400000B0
#define __COMP_ID_VISUALC_V120                       0x400000C0
#define __COMP_ID_VISUALC_V140                       0x400000D0

////////////////////////////////////////////////////////////////////////////////
//Detect compiler ID

#if !defined(__COMP_ID_CURRENT)

# ifdef __BORLANDC__

#  if   (__BCPLUSPLUS__>=0x0570)
#    define __COMP_ID_CURRENT                   __COMP_ID_BORLAND_CBUILDER7
#  elif (__BCPLUSPLUS__>=0x0560)
#    define __COMP_ID_CURRENT                   __COMP_ID_BORLAND_CBUILDER6
#  elif (__BCPLUSPLUS__>=0x0550)
#    define __COMP_ID_CURRENT                   __COMP_ID_BORLAND_CBUILDER5
#  elif (__BCPLUSPLUS__>=0x0540)
#    define __COMP_ID_CURRENT                   __COMP_ID_BORLAND_CBUILDER4
#  elif (__BCPLUSPLUS__>=0x0530)
#    define __COMP_ID_CURRENT                   __COMP_ID_BORLAND_CBUILDER3
#  endif

# elif defined(_MSC_VER)

#  if   (_MSC_VER>=1900)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V140
#  elif (_MSC_VER>=1800)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V120
#  elif (_MSC_VER>=1700)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V110
#  elif (_MSC_VER>=1600)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V100
#  elif (_MSC_VER>=1500)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V90
#  elif   (_MSC_VER>=1400)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V80
#  elif (_MSC_VER>=1300)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V70
#  elif (_MSC_VER>=1200)
#    define __COMP_ID_CURRENT                   __COMP_ID_VISUALC_V60
#  endif

# endif

# if !defined(__COMP_ID_CURRENT)
#  error "unknown compiler"
# endif

#endif //!defined(__COMP_ID_CURRENT)

////////////////////////////////////////////////////////////////////////////////
//Config for current compiler

//BCB3 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER3)

# error BCB3 longer not supported

#endif //__COMP_ID_BORLAND_CBUILDER3

//BCB4 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER4)

# error BCB4 longer not supported

#endif //__COMP_ID_BORLAND_CBUILDER4

//BCB5 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER5)

# include <config/compiler/config_compiler__bcb5.h>

#endif //__COMP_ID_BORLAND_CBUILDER5

//BCB6 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER6)

# include <config/compiler/config_compiler__bcb6.h>

#endif //__COMP_ID_BORLAND_CBUILDER6

//BCB7 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER7)

# include <config/compiler/config_compiler__bcb7.h>

#endif //__COMP_ID_BORLAND_CBUILDER7

//VC140 ------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V140)

# include <config/compiler/config_compiler__vc14.h>

#endif //__COMP_ID_VISUALC_V140

//VC120 ------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V120)

# include <config/compiler/config_compiler__vc12.h>

#endif //__COMP_ID_VISUALC_V120

//VC110 ------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V110)

# include <config/compiler/config_compiler__vc11.h>

#endif //__COMP_ID_VISUALC_V110

//VC100 ------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V100)

# include <config/compiler/config_compiler__vc10.h>

#endif //__COMP_ID_VISUALC_V100

//VC90 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V90)

# include <config/compiler/config_compiler__vc9.h>

#endif //__COMP_ID_VISUALC_V90

//VC80 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V80)

# include <config/compiler/config_compiler__vc8.h>

#endif //__COMP_ID_VISUALC_V80

//VC70 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V70)

# include <config/compiler/config_compiler__vc7.h>

#endif //__COMP_ID_VISUALC_V70

//VC60 -------------------------------------------------------------------
#if (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V60)

# include <config/compiler/config_compiler__vc6.h>

#endif//__COMP_ID_VISUALC_V60

////////////////////////////////////////////////////////////////////////////////
//define compiler workaround

#if !defined(COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE)
# error "COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE is not defined"
#endif

#if(COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE)
# define COMP_W000001_PURE_METHOD                     =0
#else
# define COMP_W000001_PURE_METHOD
#endif

//------------------------------------------------------------------------
#if !defined(COMP_CONF_ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL)
# error "COMP_CONF_ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL is not defined"
#endif

#if(COMP_CONF_ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL)
# define COMP_W000002_COPY_CTOR_IMPL                  ;
#else
# define COMP_W000002_COPY_CTOR_IMPL                  {assert(false);}
#endif

//------------------------------------------------------------------------
#if !defined(COMP_CONF_CAN_USE_ACCESS_USING_IN_TEMPLATE)
# error "COMP_CONF_CAN_USE_ACCESS_USING_IN_TEMPLATE is not defined"
#endif

#if(COMP_CONF_CAN_USE_ACCESS_USING_IN_TEMPLATE)
# define COMP_W000003_USING                           using
#else
# define COMP_W000003_USING
#endif

//------------------------------------------------------------------------
#if !defined(COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_OVERRIDE)
# error "COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_OVERRIDE is not defined"
#endif

#if(COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_OVERRIDE)
# define COMP_W000004_OVERRIDE                        override
#else
# define COMP_W000004_OVERRIDE
#endif

//------------------------------------------------------------------------
#if !defined(COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL)
# error "COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL is not defined"
#endif

#if   (COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL==0)
# define COMP_W000005_FINAL
#elif (COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL==1)
# define COMP_W000005_FINAL                           final
#elif (COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL==2)
# define COMP_W000005_FINAL                           sealed
#else
# error "COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL has unknown value"
#endif

////////////////////////////////////////////////////////////////////////////////
//override final

#if !defined(COMP_W000004_OVERRIDE)
# error "COMP_W000004_OVERRIDE is not defined"
#endif

#if !defined(COMP_W000005_FINAL)
# error "COMP_W000005_FINAL is not defined"
#endif

#define COMP_W000004_OVERRIDE_FINAL  COMP_W000004_OVERRIDE COMP_W000005_FINAL

//------------------------------------------------------------------------
#if !defined(COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL)
# error COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL is not defined
#endif

#if   (COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL==0)
# define COMP_W000006_CLASS_FINAL
#elif (COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL==1)
# define COMP_W000006_CLASS_FINAL                     final
#elif (COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL==2)
# define COMP_W000006_CLASS_FINAL                     sealed
#else
# error COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL has unknown value
#endif

////////////////////////////////////////////////////////////////////////////////
//Build unused code

#if !defined(COMP_BUILD_UNUSED_CODE)

# if !defined(COMP_CONF_CAN_DETECT_UNUSED_CODE)
#  error "COMP_CONF_CAN_DETECT_UNUSED_CODE is not defined"
# endif

# if   (COMP_CONF_CAN_DETECT_UNUSED_CODE==0)
#  define COMP_BUILD_UNUSED_CODE             1
# elif (COMP_CONF_CAN_DETECT_UNUSED_CODE==1)
#  if defined(NDEBUG)
#   define COMP_BUILD_UNUSED_CODE            0
#  else
#   define COMP_BUILD_UNUSED_CODE            1
#  endif
# else
#  error "unexpected value of COMP_CONF_CAN_DETECT_UNUSED_CODE"
# endif

# endif

////////////////////////////////////////////////////////////////////////////////
#endif
