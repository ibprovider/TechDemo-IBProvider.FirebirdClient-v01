////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_records_r.h
//! \brief   Коллекция ошибок
//! \author  Kovalenko Dmitry
//! \date    27.11.2016
#ifndef _ibp_error_records_r_H_
#define _ibp_error_records_r_H_

#include <structure/error/t_err_records.h>
#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_records_r

class COMP_CONF_DECLSPEC_NOVTABLE t_ibp_error_records_r:public structure::t_err_records_r
{
 public:
  typedef structure::t_value_with_null<size_t>    size_type_N;

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
