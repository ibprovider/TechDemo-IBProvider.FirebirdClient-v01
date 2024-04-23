////////////////////////////////////////////////////////////////////////////////
//Системные характеристики Firebird
//                                             Коваленко Дмитрий. 24.05.2006.
#ifndef _fb_sys_data_H_
#define _fb_sys_data_H_

#include "source/db_obj/ib_base/ib_base.h"

namespace lcpi{namespace ibp{namespace fb_base{
////////////////////////////////////////////////////////////////////////////////

extern const wchar_t g_ods_cs__fb04_0_0[];  //UTF8

////////////////////////////////////////////////////////////////////////////////
//Перечисление идентификаторов ODS для баз данных Firebird

extern const isc_base::t_isc_ods_id g_ods_id_fb00_9_0;   //10.0
extern const isc_base::t_isc_ods_id g_ods_id_fb01_0_0;   //10.0
extern const isc_base::t_isc_ods_id g_ods_id_fb01_5_0;   //10.1
extern const isc_base::t_isc_ods_id g_ods_id_fb02_0_0;   //11.0
extern const isc_base::t_isc_ods_id g_ods_id_fb02_1_0;   //11.1
extern const isc_base::t_isc_ods_id g_ods_id_fb02_5_0;   //11.2
extern const isc_base::t_isc_ods_id g_ods_id_fb03_0_0;   //12.0
extern const isc_base::t_isc_ods_id g_ods_id_fb03_0_4;   //12.2
extern const isc_base::t_isc_ods_id g_ods_id_fb04_0_0;   //13.0

////////////////////////////////////////////////////////////////////////////////

///Максимальная длина текста SQL-запроса FB0.9
const size_t c_fb00_max_sql_text_length=USHRT_MAX;

///Максимальная длина текста SQL-запроса FB3.0
const size_t c_fb03_max_sql_text_length=10*1024*1024;

////////////////////////////////////////////////////////////////////////////////
}/*nms fb_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
