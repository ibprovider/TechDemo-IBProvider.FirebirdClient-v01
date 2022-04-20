////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error__com_module_is_shutdown.cpp
//! \brief   Класс исключений для попыток работы с деактивизированным COM-модулем.
//! \author  Kovalenko Dmitry
//! \date    07.10.2020
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error__com_module_is_shutdown.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error__com_module_is_shutdown

t_ibp_error__com_module_is_shutdown::t_ibp_error__com_module_is_shutdown()
{
}//t_ibp_error__com_module_is_shutdown

//------------------------------------------------------------------------
void t_ibp_error__com_module_is_shutdown::throw_error()
{
 throw self_type();
}//throw_error

//std::exception interface -----------------------------------------------
const char* t_ibp_error__com_module_is_shutdown::what()const __STL_EXCEPTION_WHAT_THROW_SPEC
{
 return "IBProvider module is in shutdown state.";
}//what

//------------------------------------------------------------------------
void t_ibp_error__com_module_is_shutdown::raise()const
{
 throw *this;
}//raise

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
