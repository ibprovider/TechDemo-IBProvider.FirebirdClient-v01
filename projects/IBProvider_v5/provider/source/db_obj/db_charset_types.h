////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_charset_types.h
//! \brief   Ѕазовые типы дл€ конструкций, управл€ющих кодовыми страницами
//! \author  Kovalenko Dmitry
//! \date    22.01.2009
#ifndef _db_charset_types_H_
#define _db_charset_types_H_

#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//struct db_charset_types

struct db_charset_types
{
 using name_char_type=t_ibp_char;
};//struct db_charset_types

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
