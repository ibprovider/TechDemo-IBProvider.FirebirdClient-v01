////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_types.cpp
//! \brief   Определение описаний и идентификаторов типов данных
//! \author  Kovalenko Dmitry
//! \date    18.03.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/db_types.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////

const wchar_t* get_dbstatus2_name(t_dbstatus const status)
{
 switch(status)
 {
  case dbstatus2__ok:
   return L"ok";

  case dbstatus2__is_null:
   return L"is_null";

  case dbstatus2__default:
   return L"default";
 }//switch status

 assert_msg(false,"status: "<<int(status));

 return L"???";
}//get_dbstatus2_name

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
