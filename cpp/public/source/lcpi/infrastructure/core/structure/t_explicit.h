////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_explicit_H_
#define _lcpi_infrastructure_core_structure__t_explicit_H_

#include <lcpi/infrastructure/core/.config.h>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_explicit

template<typename T>
class t_explicit final
{
 public:
  using value_type=T;

 public:
  value_type value;

  t_explicit(value_type v)
   :value(v)
  {;}
};//class t_explicit

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
