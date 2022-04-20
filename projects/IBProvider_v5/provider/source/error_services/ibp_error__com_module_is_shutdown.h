////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error__com_module_is_shutdown.h
//! \brief   Класс исключений для попыток работы с деактивизированным COM-модулем.
//! \author  Kovalenko Dmitry
//! \date    07.10.2020
#ifndef _ibp_error__com_module_is_shutdown_H_
#define _ibp_error__com_module_is_shutdown_H_

#include <structure/t_exception.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error__com_module_is_shutdown

/// <summary>
///  Класс и
/// </summary>
class t_ibp_error__com_module_is_shutdown LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_exception
{
 private:
  typedef t_ibp_error__com_module_is_shutdown                       self_type;

 public:
  t_ibp_error__com_module_is_shutdown();

  /// <summary>
  ///  Утилита для генерации исключения.
  /// </summary>
  static void throw_error();

  //std::exception interface ---------------------------------------------
  virtual const char* what()const __STL_EXCEPTION_WHAT_THROW_SPEC LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //structure::t_exception interface -------------------------------------
  COMP_CONF_DECLSPEC_NORETURN virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class t_ibp_error__com_module_is_shutdown

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
