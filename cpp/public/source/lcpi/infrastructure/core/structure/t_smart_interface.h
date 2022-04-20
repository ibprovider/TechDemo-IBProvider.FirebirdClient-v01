///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 16.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_smart_interface_H_
#define _lcpi_infrastructure_core_structure__t_smart_interface_H_

#include <lcpi/infrastructure/core/.config.h>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
///////////////////////////////////////////////////////////////////////////////
//class t_smart_interface

class LCPI_INFRASTRUCTURE_CORE__CFG__IFACE_STG __declspec(novtable) t_smart_interface
{
 public:
  t_smart_interface()=default;

  t_smart_interface(const t_smart_interface&)=delete;
  t_smart_interface(t_smart_interface&&)=delete;

 ~t_smart_interface()=default;

  t_smart_interface& operator = (const t_smart_interface&)=delete;
  t_smart_interface& operator = (t_smart_interface&&)=delete;

 public:
  virtual void add_ref()=0;
  virtual void release()=0;
};//class t_smart_interface

///////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
