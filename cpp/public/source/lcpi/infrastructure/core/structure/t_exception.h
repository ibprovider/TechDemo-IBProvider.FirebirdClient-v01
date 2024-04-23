////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_exception_H_
#define _lcpi_infrastructure_core_structure__t_exception_H_

#include <lcpi/infrastructure/core/.config.h>

#include <exception>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_exception

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4275)
#endif

class LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG t_exception:public std::exception
{
 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN virtual void raise() const //throw
  {
   throw *this;
  }
};//class t_exception

#ifdef _MSC_VER
#pragma warning( pop )
#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
