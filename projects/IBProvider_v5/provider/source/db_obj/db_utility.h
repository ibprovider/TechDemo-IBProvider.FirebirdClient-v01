////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_utility.h
//! \brief   ��������� ����������� �������������� ���������� ������� � ������� ��.
//! \author  Kovalenko Dmitry
//! \date    28.07.2003
#ifndef _db_utility_H_
#define _db_utility_H_

#include "source/db_obj/db_types.h"

////////////////////////////////////////////////////////////////////////////////
namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//��������� ������

LCPI_CPP_CFG__DECLSPEC__NORETURN
void throw_cantconvertvalue(t_dbtype src_dbtype,
                            t_dbtype dest_type);

////////////////////////////////////////////////////////////////////////////////
//��������� ��������� � �������

std::string extract_substr_with_version(const char* str);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
