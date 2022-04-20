////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base__dbparams_for_create__installer.h
//! \brief   Интерфейс установщика параметров новой базы данных.
//! \author  Kovalenko Dmitry
//! \date    16.02.2019
#ifndef _isc_base__dbparams_for_create__installer_H_
#define _isc_base__dbparams_for_create__installer_H_

#include <structure/t_const_str_box.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_base__dbparams_for_create__installer

class isc_base__dbparams_for_create__installer
{
 public:
  typedef structure::t_const_wstr_box       wstr_box_type;

 public:
  virtual void set_newdb_param___db_dialect(long propValue)=0;

  virtual void set_newdb_param___page_size(long propValue)=0;

  virtual void set_newdb_param___type_of_db_users(long propValue)=0;
};//class isc_base__dbparams_for_create__installer

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
