////////////////////////////////////////////////////////////////////////////////
//! \ingroup ib_base
//! \file    ib_sys_data.h
//! \brief   Определение служебных данных для IB-совместимых серверов
//! \author  Kovalenko Dmitry
//! \date    16.11.2003
#ifndef _ib_sys_data_H_
#define _ib_sys_data_H_

#include "source/db_obj/ib_base/ib_base.h"

namespace lcpi{namespace ibp{namespace ib_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ib_base
//! @{
////////////////////////////////////////////////////////////////////////////////

extern const wchar_t g_ods_cs__ib04_0_0[];  //UNICODE_FSS

////////////////////////////////////////////////////////////////////////////////
//Перечисление идентификаторов ODS для баз данных InterBase

extern const isc_base::t_isc_ods_id g_ods_id_ib04_0_0;    //8.0
extern const isc_base::t_isc_ods_id g_ods_id_ib04_2_0;    //8.2
extern const isc_base::t_isc_ods_id g_ods_id_ib05_0_0;    //9.0
extern const isc_base::t_isc_ods_id g_ods_id_ib05_5_0;    //9.1
extern const isc_base::t_isc_ods_id g_ods_id_ib06_0_0;    //10.0
extern const isc_base::t_isc_ods_id g_ods_id_ib06_5_0;    //10.1
extern const isc_base::t_isc_ods_id g_ods_id_ib07_0_0;    //11.0
extern const isc_base::t_isc_ods_id g_ods_id_ib07_1_0;    //11.1
extern const isc_base::t_isc_ods_id g_ods_id_ib07_5_0;    //11.2
extern const isc_base::t_isc_ods_id g_ods_id_ib08_0_0;    //12.0
extern const isc_base::t_isc_ods_id g_ods_id_ib09_0_0;    //13.0
extern const isc_base::t_isc_ods_id g_ods_id_ib09_3_0;    //13.1
extern const isc_base::t_isc_ods_id g_ods_id_ib10_0_0;    //15.0
extern const isc_base::t_isc_ods_id g_ods_id_ib11_0_0;    //15.0
extern const isc_base::t_isc_ods_id g_ods_id_ib12_0_0;    //16.0
extern const isc_base::t_isc_ods_id g_ods_id_ib13_0_0;    //17.0
extern const isc_base::t_isc_ods_id g_ods_id_ib14_0_0;    //18.0
extern const isc_base::t_isc_ods_id g_ods_id_ib14_1_0;    //18.1
extern const isc_base::t_isc_ods_id g_ods_id_ib14_2_0;    //18.2

////////////////////////////////////////////////////////////////////////////////

///Максимальная длина текста SQL-запроса
const size_t c_ib04_max_sql_text_length=USHRT_MAX;

////////////////////////////////////////////////////////////////////////////////

///Размер сегмента BLOB-а по-умолчанию
const int c_ib_default_blob_segment_size=80;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ib_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
