////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_records_r.h
//! \brief   Коллекция ошибок
//! \author  Kovalenko Dmitry
//! \date    27.11.2016
#ifndef _ibp_error_records_r_H_
#define _ibp_error_records_r_H_

#include <lcpi/lib/structure/error/t_err_records_r.h>
#include <lcpi/lib/structure/t_value_with_null.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_records_r

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_ibp_error_records_r
 :public lib::structure::t_err_records_r
{
 public:
  using size_type_N=lib::structure::t_value_with_null<size_t>;

 public:
  virtual ~t_ibp_error_records_r()
  {
  }

  //interface ------------------------------------------------------------
  virtual size_type_N get_primary_err_idx()const=0;
};//class t_ibp_error_records_r

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
