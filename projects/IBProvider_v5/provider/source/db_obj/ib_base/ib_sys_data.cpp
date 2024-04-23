////////////////////////////////////////////////////////////////////////////////
//! \ingroup ib_base
//! \file    ib_sys_data.cpp
//! \brief   Определение служебных данных для IB-совместимых серверов
//! \author  Kovalenko Dmitry
//! \date    16.11.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/ib_base/ib_sys_data.h"
#include "source/db_obj/isc_base/isc_ods_id.h"

namespace lcpi{namespace ibp{namespace ib_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ib_base
//! @{
////////////////////////////////////////////////////////////////////////////////

extern const wchar_t g_ods_cs__ib04_0_0[]
 =L"UNICODE_FSS";

////////////////////////////////////////////////////////////////////////////////
//Перечисление идентификаторов ODS для баз данных InterBase

extern const isc_base::t_isc_ods_id g_ods_id_ib04_0_0( 8,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib04_2_0( 8,2);
extern const isc_base::t_isc_ods_id g_ods_id_ib05_0_0( 9,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib05_5_0( 9,1);
extern const isc_base::t_isc_ods_id g_ods_id_ib06_0_0(10,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib06_5_0(10,1);
extern const isc_base::t_isc_ods_id g_ods_id_ib07_0_0(11,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib07_1_0(11,1);
extern const isc_base::t_isc_ods_id g_ods_id_ib07_5_0(11,2);
extern const isc_base::t_isc_ods_id g_ods_id_ib08_0_0(12,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib09_3_0(13,1);
extern const isc_base::t_isc_ods_id g_ods_id_ib10_0_0(15,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib12_0_0(16,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib13_0_0(17,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib14_0_0(18,0);
extern const isc_base::t_isc_ods_id g_ods_id_ib14_1_0(18,1);
extern const isc_base::t_isc_ods_id g_ods_id_ib14_2_0(18,2);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ib_base*/}/*nms ibp*/}/*nms lcpi*/
