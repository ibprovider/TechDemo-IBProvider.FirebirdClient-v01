////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error__com_module_is_shutdown.h
//! \brief   Класс исключений для попыток работы с деактивизированным COM-модулем.
//! \author  Kovalenko Dmitry
//! \date    07.10.2020
#ifndef _ibp_error__com_module_is_shutdown_H_
#define _ibp_error__com_module_is_shutdown_H_

#include <lcpi/lib/structure/t_exception.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error__com_module_is_shutdown

/// <summary>
///  Класс и
/// </summary>
class t_ibp_error__com_module_is_shutdown LCPI_CPP_CFG__CLASS__FINAL
 :public lib::structure::t_exception
{
 private:
  using self_type=t_ibp_error__com_module_is_shutdown;

 public:
  t_ibp_error__com_module_is_shutdown();

  /// <summary>
  ///  Утилита для генерации исключения.
  /// </summary>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void throw_error();

  //std::exception interface ---------------------------------------------
  virtual const char* what()const LCPI_STL_EXCEPTION_WHAT_THROW_SPEC LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //structure::t_exception interface -------------------------------------
  LCPI_CPP_CFG__DECLSPEC__NORETURN virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class t_ibp_error__com_module_is_shutdown

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
