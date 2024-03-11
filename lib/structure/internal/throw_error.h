////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                Dmitry Kovalenko. 04.12.2018.
#ifndef _lcpi_lib_structure_internal__throw_error_H_
#define _lcpi_lib_structure_internal__throw_error_H_

#include <structure/t_const_str_box.h>

namespace structure{namespace internal{
////////////////////////////////////////////////////////////////////////////////
//class throw_error

class throw_error
{
 public:
  typedef t_const_str_box                   astr_box_type;
  typedef t_const_wstr_box                  wstr_box_type;

 public: //t_basic_parameter_list errors ---------------------------------
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void parameter_list__duplicate_param(astr_box_type name);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void parameter_list__duplicate_param(wstr_box_type name);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void parameter_list__bad_format_of_quoted_item_name();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void parameter_list__bad_format_of_quoted_item_value();
};//class throw_error

////////////////////////////////////////////////////////////////////////////////
}/*nms internal*/}/*nms structure*/
#endif
