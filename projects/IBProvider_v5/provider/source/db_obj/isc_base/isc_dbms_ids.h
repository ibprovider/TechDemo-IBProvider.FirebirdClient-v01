////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_dbms_ids.h
//! \brief   Идентификаторы ISC-совместимых серверов
//! \author  Kovalenko Dmitry
//! \date    19.06.2008
#ifndef _isc_dbms_ids_H_
#define _isc_dbms_ids_H_

#include <structure/t_common.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//enum InterBase clones IDs

/// <summary>
///  Перечисление клонов InterBase
/// </summary>
enum t_isc_dbms_id
{
 /// Unknown
 isc_dbms_id_Unknown   =0,

 /// InterBase SQL Server
 isc_dbms_id_InterBase =1,

 /// Firebird SQL Server
 isc_dbms_id_Firebird  =2,

 /// Yaffil SQL Server
 isc_dbms_id_Yaffil    =3,
};//enum t_isc_dbms_id

////////////////////////////////////////////////////////////////////////////////
//Константы с известными названиями клонов InterBase

/// <summary>
///  Символьный идентификатор, используемый для неизвестного сервера
/// </summary>
extern const char* const g_dbms_name_Unknown;

/// <summary>
///  Символьный идентификатор InterBase
/// </summary>
extern const char* const g_dbms_name_InterBase;

/// <summary>
///  Символьный идентификатор Firebird
/// </summary>
extern const char* const g_dbms_name_Firebird;

/// <summary>
///  Символьный идентификатор Yaffil
/// </summary>
extern const char* const g_dbms_name_Yaffil;

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
