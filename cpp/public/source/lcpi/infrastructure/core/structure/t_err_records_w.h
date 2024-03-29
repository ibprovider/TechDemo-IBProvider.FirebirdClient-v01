////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_err_records_w_H_
#define _lcpi_infrastructure_core_structure__t_err_records_w_H_

#include <lcpi/infrastructure/core/structure/t_err_record.h>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_records_w

class LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_err_records_w
{
 public:
  virtual ~t_err_records_w()
  {
  }

  virtual void add_record(t_err_record*)=0;
};//class t_err_records_w

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
