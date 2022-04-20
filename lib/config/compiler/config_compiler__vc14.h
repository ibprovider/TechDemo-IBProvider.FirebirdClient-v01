////////////////////////////////////////////////////////////////////////////////
//Compiler configuration. VS2015.
//                                                Kovalenko Dmitry. 01.11.2015.
#ifndef _config_compiler__vc14_H_
#define _config_compiler__vc14_H_

////////////////////////////////////////////////////////////////////////////////

#define  COMP_CONF_SUPPORT_MEMBER_TEMPLATE                        1
#define  COMP_CONF_SUPPORT_TEMPLATE_FUNC_RET_INNER_TYPE           1

#define  COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE                 1
#define  COMP_CONF_ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL 0

#define  COMP_CONF_SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN     1
#define  COMP_CONF_SUPPORT_OPERATOR_DELETE_EX                     1
#define  COMP_CONF_SUPPORT_PRAGMA_STARTUP                         0
#define  COMP_CONF_SUPPORT_PRAGMA_ARGSUSED                        0
#define  COMP_CONF_SUPPORT_PRAGMA_ONCE                            1

#define  COMP_CONF_DLL_EXPORT                                     __declspec(dllexport)

#define  COMP_CONF_DECLSPEC_NOVTABLE                              __declspec(novtable)

#define  COMP_CONF_DECLSPEC_NORETURN                              __declspec(noreturn)

#define  COMP_CONF_CAN_USE_ACCESS_USING_IN_TEMPLATE               1

#ifdef _WIN64
# define  COMP_CONF_SUPPORT_CDECL_MEMBER                          0
# define  COMP_CONF_SUPPORT_STDCALL_MEMBER                        1
# define  COMP_CONF_SUPPORT_THISCALL_MEMBER                       0
# define  COMP_CONF_SUPPORT_CLRCALL_MEMBER                        1
#else
# define  COMP_CONF_SUPPORT_CDECL_MEMBER                          1
# define  COMP_CONF_SUPPORT_STDCALL_MEMBER                        1
# define  COMP_CONF_SUPPORT_THISCALL_MEMBER                       1
# define  COMP_CONF_SUPPORT_CLRCALL_MEMBER                        1
#endif

#define  COMP_CONF_HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64     0

#define  COMP_CONF_SUPPORT_VARIADIC_TEMPLATES                     1

#define  COMP_CONF_SUPPORT_RVALUE_REFERENCE                       1

#define  COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_OVERRIDE            1

#define  COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL               1 //final

#define  COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL                 1 //final

#define  COMP_CONF_CAN_DETECT_UNUSED_CODE                         1

#define  COMP_CONF_SUPPORT_CPP_NULLPTR                            1

#define  COMP_CONF_SUPPORT_STATIC_ASSERT                          1

#define  COMP_CONF_SUPPORT_TEMPLATE_USING                         1

#define  COMP_CONF_SUPPORT_ENUM_CLASS                             1

#define  COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001                  0

////////////////////////////////////////////////////////////////////////////////
#endif
