////////////////////////////////////////////////////////////////////////////////
//Файл с информацией о версии провайдера
//                                      Коваленко Дмитрий. 9 августа 2002 года.
#ifndef _ax_ibp_ver3_info_data_H_
#define _ax_ibp_ver3_info_data_H_

#include "source/Version/_version_info.h"
#include "source/Version/ibp_v05_info.h"
#include "source/ibp_cfg_compile__edition_ids.h"

////////////////////////////////////////////////////////////////////////////////
#ifndef IBP_EDITION_ID
# error "IBP_EDITION_ID not defined"
#endif

////////////////////////////////////////////////////////////////////////////////
//Сведения, общие для всех типов сборок

#define IBP_VI_COMPANY_NAME                VI_COMPANY_NAME

#define IBP_VI_LEGAL_COPYRIGHT             VI_LEGAL_COPYRIGHT

#define IBP_VI_INTERNAL_NAME               "LCPI.IBProvider\0"

////////////////////////////////////////////////////////////////////////////////

#if(IBP_EDITION_ID==IBP_EDITION_ID__PROF)

# define IBP_VI_PRODUCT_NAME               "IBProvider\0"

# ifdef _IBP_BUILD__CREATE_TRIAL
#  define IBP_VI_FILE_DESCRIPTION_STRING   "[TRIAL] LCPI OLE DB Provider for InterBase [v5]\0"
# else
#  define IBP_VI_FILE_DESCRIPTION_STRING   "LCPI OLE DB Provider for InterBase [v5]\0"
# endif

# define IBP_VI_PRODUCT_DESCRIPTION_STRING IBP_VI_FILE_DESCRIPTION_STRING

# define IBP_VI_COMMENTS                   IBP_VI_FILE_DESCRIPTION_STRING

//OLEDB Provider
# define IBP_PROVIDER_DESCRIPTION_STRING   IBP_VI_FILE_DESCRIPTION_STRING
# define IBP_PROVIDER_PROG_ID_NO_VER       "LCPI.IBProvider\0"
# define IBP_PROVIDER_PROG_ID_VER          "LCPI.IBProvider.5\0"

//Errors Service
# define IBP_ERRORS_DESCRIPTION_STRING     "LCPI.IBProvider Error Lookup [v5]\0"

//Data Link Property Page
# define IBP_DATA_LINK_PROP_PAGE_DESCRIPTION_STRING      "LCPI.IBProvider Data Link Page [v5]\0"
# define IBP_DATA_LINK_ADV_PROP_PAGE_DESCRIPTION_STRING  "LCPI.IBProvider Advanced Data Link Page [v5]\0"

#elif(IBP_EDITION_ID==IBP_EDITION_ID__FREE)

# define IBP_VI_PRODUCT_NAME               "Free IBProvider\0"

# define IBP_VI_FILE_DESCRIPTION_STRING    "LCPI OLE DB Provider for InterBase [v5] [Free]\0"

# define IBP_VI_PRODUCT_DESCRIPTION_STRING IBP_VI_FILE_DESCRIPTION_STRING

# define IBP_VI_COMMENTS                   IBP_VI_FILE_DESCRIPTION_STRING

//OLEDB Provider
# define IBP_PROVIDER_DESCRIPTION_STRING   IBP_VI_FILE_DESCRIPTION_STRING
# define IBP_PROVIDER_PROG_ID_NO_VER       "LCPI.IBProvider\0"
# define IBP_PROVIDER_PROG_ID_VER          "LCPI.IBProvider.5.Free\0"

//Errors Service
# define IBP_ERRORS_DESCRIPTION_STRING     "LCPI.IBProvider Error Lookup [v5] [Free]\0"

//Data Link Property Page
# define IBP_DATA_LINK_PROP_PAGE_DESCRIPTION_STRING      "LCPI.IBProvider Data Link Page [v5] [Free]\0"
# define IBP_DATA_LINK_ADV_PROP_PAGE_DESCRIPTION_STRING  "LCPI.IBProvider Advanced Data Link Page [v5] [Free]\0"

#elif(IBP_EDITION_ID==IBP_EDITION_ID__LITE)

# define IBP_VI_PRODUCT_NAME               "Lite IBProvider\0"

# ifdef _IBP_BUILD__CREATE_TRIAL
#  define IBP_VI_FILE_DESCRIPTION_STRING   "[TRIAL] LCPI OLE DB Provider for InterBase [v5] [Lite]\0"
# else
#  define IBP_VI_FILE_DESCRIPTION_STRING   "LCPI OLE DB Provider for InterBase [v5] [Lite]\0"
# endif

# define IBP_VI_PRODUCT_DESCRIPTION_STRING IBP_VI_FILE_DESCRIPTION_STRING

# define IBP_VI_COMMENTS                   IBP_VI_FILE_DESCRIPTION_STRING

//OLEDB Provider
# define IBP_PROVIDER_DESCRIPTION_STRING   IBP_VI_FILE_DESCRIPTION_STRING
# define IBP_PROVIDER_PROG_ID_NO_VER       "LCPI.IBProvider\0"
# define IBP_PROVIDER_PROG_ID_VER          "LCPI.IBProvider.5.Lite\0"

//Errors Service
# define IBP_ERRORS_DESCRIPTION_STRING     "LCPI.IBProvider Error Lookup [v5] [Lite]\0"

//Data Link Property Page
# define IBP_DATA_LINK_PROP_PAGE_DESCRIPTION_STRING      "LCPI.IBProvider Data Link Page [v5] [Lite]\0"
# define IBP_DATA_LINK_ADV_PROP_PAGE_DESCRIPTION_STRING  "LCPI.IBProvider Advanced Data Link Page [v5] [Lite]\0"

#else

# error "Unknown IBP_EDITION_ID"

#endif

////////////////////////////////////////////////////////////////////////////////

#define IBP_SUBSYSTEM_SIGN__REMOTE_FB                    "LCPI.IBProvider.RemoteFB"

////////////////////////////////////////////////////////////////////////////////
#endif

