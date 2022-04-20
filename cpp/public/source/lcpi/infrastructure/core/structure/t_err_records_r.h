////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_err_records_r_H_
#define _lcpi_infrastructure_core_structure__t_err_records_r_H_

#include <lcpi/infrastructure/core/structure/t_err_record.h>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_records_r

class LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG __declspec(novtable) t_err_records_r
{
 public:
  virtual ~t_err_records_r()
  {
  }

  virtual size_t get_record_count()const=0;

  virtual t_err_record::self_ptr get_record(size_t record_num)const=0;
};//class t_err_records_r

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
