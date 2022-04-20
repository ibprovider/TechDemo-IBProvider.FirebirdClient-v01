////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_sys_props.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

extern const TCHAR ibp_sprop_module[]                    =_T("module");
extern const TCHAR ibp_sprop_module_version[]            =_T("module_version");

extern const TCHAR ibp_sprop_provider_clsid[]            =_T("provider_clsid");
extern const TCHAR ibp_sprop_provider_prog_id[]          =_T("provider_prog_id");
extern const TCHAR ibp_sprop_provider_prog_id_no_ver[]   =_T("provider_prog_id_no_ver");
extern const TCHAR ibp_sprop_provider_descr[]            =_T("provider_descr");

extern const TCHAR ibp_sprop_error_service_clsid[]       =_T("error_service_clsid");
extern const TCHAR ibp_sprop_error_service_descr[]       =_T("error_service_descr");

extern const TCHAR ibp_sprop_data_link_page_clsid[]      =_T("data_link_page_clsid");
extern const TCHAR ibp_sprop_data_link_page_descr[]      =_T("data_link_page_descr");

extern const TCHAR ibp_sprop_adv_data_link_page_clsid[]  =_T("adv_data_link_page_clsid");
extern const TCHAR ibp_sprop_adv_data_link_page_descr[]  =_T("adv_data_link_page_descr");

////////////////////////////////////////////////////////////////////////////////
//Свойства трассировочной сборки провайдера

extern const TCHAR ibp_sprop_flush_log_period[]          =_T("flush_log_period");

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/

