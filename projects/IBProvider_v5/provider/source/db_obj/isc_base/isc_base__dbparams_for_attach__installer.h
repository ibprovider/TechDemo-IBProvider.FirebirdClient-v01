////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base__dbparams_for_attach__installer.h
//! \brief   Интерфейс установщика параметров инициализации подключения.
//! \author  Kovalenko Dmitry
//! \date    16.02.2019
#ifndef _isc_base__dbparams_for_attach__installer_H_
#define _isc_base__dbparams_for_attach__installer_H_

#include <structure/t_const_str_box.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_base__dbparams_for_attach__installer

class isc_base__dbparams_for_attach__installer
{
 public:
  typedef structure::t_const_wstr_box       wstr_box_type;

 public:
  virtual void set_dbinit_param___auth__integrated(wstr_box_type propValue)=0;

  virtual void set_dbinit_param___auth__user_id(wstr_box_type propValue)=0;

  virtual void set_dbinit_param___auth__password(wstr_box_type propValue)=0;

  virtual void set_dbinit_param___auth__rolename(wstr_box_type propValue)=0;

  virtual void set_dbinit_param___ctype(wstr_box_type propValue)=0;

  virtual void set_dbinit_param___garbage_collect(bool propValue)=0;

  virtual void set_dbinit_param___num_buffers(long propValue)=0;

  virtual void set_dbinit_param___enable_db_trigger(long propValue)=0;

  virtual void set_dbinit_param___sys_encrypt_password(wstr_box_type propValue)=0;
};//class isc_base__dbparams_for_attach__installer

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
