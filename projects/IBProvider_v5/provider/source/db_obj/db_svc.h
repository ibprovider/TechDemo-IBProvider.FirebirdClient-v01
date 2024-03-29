////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_svc.h
//! \brief   Конструкции для определения сервисов.
//! \author  Kovalenko Dmitry
//! \date    05.12.2015
#ifndef _db_svc_H_
#define _db_svc_H_

#include <lcpi/lib/.config.h>
#include <guiddef.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//struct t_db_svc_descr

struct t_db_svc_descr
{
 GUID         guid;
 const char*  name;
};//struct t_db_svc_descr

////////////////////////////////////////////////////////////////////////////////

template<class T>
REFGUID __db_guid();//{sizeof(void);return CLSID_NULL;}

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
