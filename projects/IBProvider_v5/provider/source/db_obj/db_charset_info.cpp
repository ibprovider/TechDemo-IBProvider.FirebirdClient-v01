////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_charset_info.cpp
//! \brief   Конструкция для хранения описания кодовой страницей
//! \author  Kovalenko Dmitry
//! \date    05.10.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/db_charset_info.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_db_charset_info

t_db_charset_info::t_db_charset_info()
 :flags(0)
 ,bytes_per_char(0)
 ,min_bytes_per_char(0)
 ,ucs2_for_char(0)
{
}

//------------------------------------------------------------------------
t_db_charset_info::~t_db_charset_info()
{
}

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
