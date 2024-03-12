////////////////////////////////////////////////////////////////////////////////
//Compiler configuration. VS2015.
//                                                Kovalenko Dmitry. 30.09.2020.
#ifndef _cpp_public_lcpi_config__config_compiler__vc14_H_
#define _cpp_public_lcpi_config__config_compiler__vc14_H_

////////////////////////////////////////////////////////////////////////////////

#define LCPI_CPP_CFG__METHOD__OVERRIDE                                override

#define LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL                          override final

#define LCPI_CPP_CFG__CLASS__FINAL                                    final

#define LCPI_CPP_CFG__DECLSPEC__NORETURN                              __declspec(noreturn)

#define LCPI_CPP_CFG__DECLSPEC__NOVTABLE                             __declspec(novtable)

////////////////////////////////////////////////////////////////////////////////

#define  LCPI_CPP_CFG__SUPPORT_MEMBER_TEMPLATE                        1
#define  LCPI_CPP_CFG__SUPPORT_TEMPLATE_FUNC_RET_INNER_TYPE           1

#define  LCPI_CPP_CFG__STABLE_PURE_METHOD_IN_TEMPLATE                 1
#define  LCPI_CPP_CFG__ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL 0

#define  LCPI_CPP_CFG__SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN     1
#define  LCPI_CPP_CFG__SUPPORT_OPERATOR_DELETE_EX                     1
#define  LCPI_CPP_CFG__SUPPORT_PRAGMA_STARTUP                         0
#define  LCPI_CPP_CFG__SUPPORT_PRAGMA_ARGSUSED                        0
#define  LCPI_CPP_CFG__SUPPORT_PRAGMA_ONCE                            1

#define  LCPI_CPP_CFG__DLL_EXPORT                                     __declspec(dllexport)

#define  LCPI_CPP_CFG__CAN_USE_ACCESS_USING_IN_TEMPLATE               1

#ifdef _WIN64
# define  LCPI_CPP_CFG__SUPPORT_CDECL_MEMBER                          0
# define  LCPI_CPP_CFG__SUPPORT_STDCALL_MEMBER                        1
# define  LCPI_CPP_CFG__SUPPORT_THISCALL_MEMBER                       0
# define  LCPI_CPP_CFG__SUPPORT_CLRCALL_MEMBER                        1
#else
# define  LCPI_CPP_CFG__SUPPORT_CDECL_MEMBER                          1
# define  LCPI_CPP_CFG__SUPPORT_STDCALL_MEMBER                        1
# define  LCPI_CPP_CFG__SUPPORT_THISCALL_MEMBER                       1
# define  LCPI_CPP_CFG__SUPPORT_CLRCALL_MEMBER                        1
#endif

#define  LCPI_CPP_CFG__HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64     0

#define  LCPI_CPP_CFG__SUPPORT_VARIADIC_TEMPLATES                     1

#define  LCPI_CPP_CFG__SUPPORT_RVALUE_REFERENCE                       1

#define  LCPI_CPP_CFG__CAN_DETECT_UNUSED_CODE                         1

#define  LCPI_CPP_CFG__SUPPORT_CPP_NULLPTR                            1

#define  LCPI_CPP_CFG__SUPPORT_STATIC_ASSERT                          1

#define  LCPI_CPP_CFG__SUPPORT_TEMPLATE_USING                         1

#define  LCPI_CPP_CFG__SUPPORT_ENUM_CLASS                             1

#define  LCPI_CPP_CFG__HAS_PROBLEM_WITH_TEMPLATE_001                  0

////////////////////////////////////////////////////////////////////////////////
#endif
