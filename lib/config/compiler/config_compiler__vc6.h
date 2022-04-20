////////////////////////////////////////////////////////////////////////////////
//Compiler configuration. VC++ 6.
//                                                Kovalenko Dmitry. 19.10.2012.
#ifndef _config_compiler__vc6_H_
#define _config_compiler__vc6_H_

////////////////////////////////////////////////////////////////////////////////

#define  COMP_CONF_SUPPORT_MEMBER_TEMPLATE                        0
#define  COMP_CONF_SUPPORT_TEMPLATE_FUNC_RET_INNER_TYPE           0

//not tested
#define  COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE                 1
#define  COMP_CONF_ALLOW_COPY_CTOR_IN_EXCEPTION_BASE_WITHOUT_IMPL 1

#define  COMP_CONF_SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN     0
#define  COMP_CONF_SUPPORT_OPERATOR_DELETE_EX                     1
#define  COMP_CONF_SUPPORT_PRAGMA_STARTUP                         0
#define  COMP_CONF_SUPPORT_PRAGMA_ARGSUSED                        0
#define  COMP_CONF_SUPPORT_PRAGMA_ONCE                            1

#define  COMP_CONF_DLL_EXPORT                                     __declspec(dllexport)

#define  COMP_CONF_DECLSPEC_NOVTABLE                              __declspec(novtable)

//not tested
#define  COMP_CONF_DECLSPEC_NORETURN

//not tested
#define  COMP_CONF_CAN_USE_ACCESS_USING_IN_TEMPLATE               0

//not tested
#define  COMP_CONF_SUPPORT_CDECL_MEMBER                           1
#define  COMP_CONF_SUPPORT_STDCALL_MEMBER                         1
#define  COMP_CONF_SUPPORT_THISCALL_MEMBER                        0
#define  COMP_CONF_SUPPORT_CLRCALL_MEMBER                         0

#define  COMP_CONF_SUPPORT_VARIADIC_TEMPLATES                     0

#define  COMP_CONF_SUPPORT_RVALUE_REFERENCE                       0

#define  COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_OVERRIDE            0

#define  COMP_CONF_SUPPORT_CONTROL_OF_VIRTUAL_FINAL               0

#define  COMP_CONF_SUPPORT_CONTROL_OF_CLASS_FINAL                 0

//not tested
#define  COMP_CONF_CAN_DETECT_UNUSED_CODE                         0

#define  COMP_CONF_SUPPORT_CPP_NULLPTR                            0

#define  COMP_CONF_SUPPORT_STATIC_ASSERT                          0

#define  COMP_CONF_SUPPORT_TEMPLATE_USING                         0

#define  COMP_CONF_SUPPORT_ENUM_CLASS                             0

////////////////////////////////////////////////////////////////////////////////
#endif
