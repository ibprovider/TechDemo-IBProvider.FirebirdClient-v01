////////////////////////////////////////////////////////////////////////////////
//Определение идентификаторов системных свойств провайдера
//                                               Коваленко Дмитрий. 19.04.2004
#ifndef _ibp_sys_props_H_
#define _ibp_sys_props_H_

#include <lcpi/lib/.config.h>

#include <tchar.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

extern const TCHAR ibp_sprop_module[];
extern const TCHAR ibp_sprop_module_version[];

extern const TCHAR ibp_sprop_provider_clsid[];
extern const TCHAR ibp_sprop_provider_prog_id[];
extern const TCHAR ibp_sprop_provider_prog_id_no_ver[];
extern const TCHAR ibp_sprop_provider_descr[];

extern const TCHAR ibp_sprop_error_service_clsid[];
extern const TCHAR ibp_sprop_error_service_descr[];

extern const TCHAR ibp_sprop_data_link_page_clsid[];
extern const TCHAR ibp_sprop_data_link_page_descr[];

extern const TCHAR ibp_sprop_adv_data_link_page_clsid[];
extern const TCHAR ibp_sprop_adv_data_link_page_descr[];

////////////////////////////////////////////////////////////////////////////////
//Свойства трассировочной сборки провайдера

extern const TCHAR ibp_sprop_flush_log_period[];

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
