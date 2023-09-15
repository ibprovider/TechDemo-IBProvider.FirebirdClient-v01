////////////////////////////////////////////////////////////////////////////////
//IBProvider Version Information.
//                                                 Kovalenko Dmitry. 2002-08-09.
#ifndef _ibp_v05_info_data_H_
#define _ibp_v05_info_data_H_

#include "source/Version/_version_info.h"
#include "source/Version/ibp_v05_info.h"
#include "source/ibp_cfg_compile__edition_ids.h"

////////////////////////////////////////////////////////////////////////////////
#ifndef IBP_EDITION_ID
# error "IBP_EDITION_ID not defined"
#endif

////////////////////////////////////////////////////////////////////////////////

#define IBP_VI_T(t) t

#define IBP_BUILD_VI_ADD0(x)  x IBP_VI_T("\0")

////////////////////////////////////////////////////////////////////////////////
//Сведения, общие для всех типов сборок

#define IBP_VI_COMPANY_NAME                 IBP_VI_T(VI_COMPANY_NAME)

#define IBP_VI_LEGAL_COPYRIGHT              IBP_VI_T(VI_LEGAL_COPYRIGHT)

#define IBP_VI_INTERNAL_NAME                IBP_VI_T("IBProvider\0")

////////////////////////////////////////////////////////////////////////////////

#define IBP_VDATA_BLOCK__VER_SIGN2          IBP_VI_T(" [v5]")

#ifdef _IBP_BUILD__CREATE_TRIAL
# define IBP_VDATA_BLOCK__TRIAL_SIGN2       IBP_VI_T(" [Trial]")
#else
# define IBP_VDATA_BLOCK__TRIAL_SIGN2       IBP_VI_T("")
#endif

////////////////////////////////////////////////////////////////////////////////

#define IBP_VDATA_BLOCK__PROVIDER_DESCR     IBP_VI_T("LCPI OLE DB Provider for InterBase")
#define IBP_VDATA_BLOCK__ERR_SVC_DESCR      IBP_VI_T("LCPI.IBProvider Error Lookup")

#define IBP_VDATA_BLOCK__PPAGE1_DESCR       IBP_VI_T("LCPI.IBProvider Connection Data Link Page")
#define IBP_VDATA_BLOCK__PPAGE2_DESCR       IBP_VI_T("LCPI.IBProvider Advanced Data Link Page")

////////////////////////////////////////////////////////////////////////////////

#if(IBP_EDITION_ID==IBP_EDITION_ID__PROF)

# define IBP_VDATA_BLOCK__EDITION_SIGN2     IBP_VI_T(" [Prof]")

//# define IBP_VI_PRODUCT_STATE               IBP_VI_T("Beta\0")

# define IBP_VI_PRODUCT_NAME                IBP_VI_T("LCPI.IBProvider Professional Edition\0")
# define IBP_PROVIDER_PROG_ID_NO_VER        IBP_VI_T("LCPI.IBProvider\0")
# define IBP_PROVIDER_PROG_ID_VER           IBP_VI_T("LCPI.IBProvider.5\0")

# define IBP_PROVIDER_NAME                  IBP_VI_T("IBProvider\0")

#elif(IBP_EDITION_ID==IBP_EDITION_ID__FREE)

# define IBP_VDATA_BLOCK__EDITION_SIGN2     IBP_VI_T(" [Free]")

# define IBP_VI_PRODUCT_NAME                IBP_VI_T("LCPI.IBProvider Free Edition\0")
# define IBP_PROVIDER_PROG_ID_NO_VER        IBP_VI_T("LCPI.IBProvider\0")
# define IBP_PROVIDER_PROG_ID_VER           IBP_VI_T("LCPI.IBProvider.5.Free\0")

# define IBP_PROVIDER_NAME                  IBP_VI_T("Free IBProvider\0")

#elif(IBP_EDITION_ID==IBP_EDITION_ID__LITE)

# define IBP_VDATA_BLOCK__EDITION_SIGN2     IBP_VI_T(" [Lite]")

//# define IBP_VI_PRODUCT_STATE               IBP_VI_T("Beta\0")

# define IBP_VI_PRODUCT_NAME                IBP_VI_T("LCPI.IBProvider Lite Edition\0")
# define IBP_PROVIDER_PROG_ID_NO_VER        IBP_VI_T("LCPI.IBProvider\0")
# define IBP_PROVIDER_PROG_ID_VER           IBP_VI_T("LCPI.IBProvider.5.Lite\0")

# define IBP_PROVIDER_NAME                  IBP_VI_T("Lite IBProvider\0")

#else

# error "Unknown IBP_EDITION_ID"

#endif

////////////////////////////////////////////////////////////////////////////////

#define IBP_VDATA_BLOCK2__SUFFIX            IBP_VDATA_BLOCK__VER_SIGN2 IBP_VDATA_BLOCK__EDITION_SIGN2 IBP_VDATA_BLOCK__TRIAL_SIGN2

#define IBP_VI_FILE_DESCRIPTION_STRING      IBP_BUILD_VI_ADD0(IBP_VDATA_BLOCK__PROVIDER_DESCR IBP_VDATA_BLOCK2__SUFFIX)

//-----------
#define IBP_VI_PRODUCT_DESCRIPTION_STRING   IBP_VI_FILE_DESCRIPTION_STRING
#define IBP_VI_COMMENTS                     IBP_VI_FILE_DESCRIPTION_STRING

//OLEDB Provider
#define IBP_PROVIDER_DESCRIPTION_STRING     IBP_VI_FILE_DESCRIPTION_STRING

//Errors Service
#define IBP_ERRORS_DESCRIPTION_STRING       IBP_BUILD_VI_ADD0(IBP_VDATA_BLOCK__ERR_SVC_DESCR IBP_VDATA_BLOCK2__SUFFIX)

//Data Link Property Page
#define IBP_DATA_LINK_STD_PROP_PAGE_DESCRIPTION_STRING  IBP_BUILD_VI_ADD0(IBP_VDATA_BLOCK__PPAGE1_DESCR IBP_VDATA_BLOCK2__SUFFIX)
#define IBP_DATA_LINK_ADV_PROP_PAGE_DESCRIPTION_STRING  IBP_BUILD_VI_ADD0(IBP_VDATA_BLOCK__PPAGE2_DESCR IBP_VDATA_BLOCK2__SUFFIX)

////////////////////////////////////////////////////////////////////////////////

#define IBP_SUBSYSTEM_SIGN__REMOTE_FB       IBP_VI_T("LCPI.IBProvider.RemoteFB")

////////////////////////////////////////////////////////////////////////////////
#endif

