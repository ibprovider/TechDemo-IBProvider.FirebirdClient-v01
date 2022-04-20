////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__platform
//! \file    db_platform.h
//! \brief   Определение конструкций, связанных с платформой базы данных
//! \author  Kovalenko Dmitry
//! \date    05.01.2016
#ifndef _db_platform_H_
#define _db_platform_H_

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__platform
//! @{
////////////////////////////////////////////////////////////////////////////////
//enum t_db_impl_id

/// <summary>
///  Перечисление идентификаторов известных реализаций DBMS
/// </summary>
enum t_db_impl_id
{
 db_impl__unknown                           =0,

 db_impl__winnt_x86                         =1,

 db_impl__winnt_amd64                       =2,
};//enum t_db_impl_id

////////////////////////////////////////////////////////////////////////////////
//enum t_db_class_id

/// <summary>
///  Перечисление идентификаторов уровней, обеспечивающих доступ к базе данных.
/// </summary>
enum t_db_class_id
{
 db_class__unknown                          =0,

 db_class__access                           =1,
 db_class__y_valve                          =2,
 db_class__rem_int                          =3,
 db_class__rem_srvr                         =4,
 db_class__pipe_int                         =7,
 db_class__pipe_srvr                        =8,
 db_class__sam_int                          =9,
 db_class__sam_srvr                         =10,
 db_class__gateway                          =11,
 db_class__cache                            =12,
};//enum t_db_class_id

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
