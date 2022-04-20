////////////////////////////////////////////////////////////////////////////////
//Идентификаторы компонент провайдера
//                                     Коваленко Дмитрий. 2 февраля 2003 года.
#ifndef _ibp_guids_H_
#define _ibp_guids_H_

#include "source/ibp_cfg_compile__edition_ids.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

#ifndef IBP_EDITION_ID
# error "IBP_EDITION_ID not defined"
#endif

////////////////////////////////////////////////////////////////////////////////

#if(IBP_EDITION_ID==IBP_EDITION_ID__PROF)

REFCLSID DEFAULT_CLSID_IBProvider
 =ibprovider::CLSID_IBProvider__Prof;

REFCLSID DEFAULT_CLSID_IBProviderErrors
 =ibprovider::CLSID_IBProviderErrors__Prof;

REFCLSID DEFAULT_CLSID_IBProviderDataLinkPropPage
 =ibprovider::CLSID_IBProviderDataLinkPropPage__Prof;

REFCLSID DEFAULT_CLSID_IBProviderDataLinkAdvPropPage
 =ibprovider::CLSID_IBProviderDataLinkAdvPropPage__Prof;

#elif(IBP_EDITION_ID==IBP_EDITION_ID__FREE)

//определяем CLASSID-ы бесплатной версии

REFCLSID DEFAULT_CLSID_IBProvider
 =ibprovider::CLSID_IBProvider__Free;

REFCLSID DEFAULT_CLSID_IBProviderErrors
 =ibprovider::CLSID_IBProviderErrors__Free;

REFCLSID DEFAULT_CLSID_IBProviderDataLinkPropPage
 =ibprovider::CLSID_IBProviderDataLinkPropPage__Free;

REFCLSID DEFAULT_CLSID_IBProviderDataLinkAdvPropPage
 =ibprovider::CLSID_IBProviderDataLinkAdvPropPage__Free;

#elif(IBP_EDITION_ID==IBP_EDITION_ID__LITE)

//определяем CLASSID-ы lite-версии

REFCLSID DEFAULT_CLSID_IBProvider
 =ibprovider::CLSID_IBProvider__Lite;

REFCLSID DEFAULT_CLSID_IBProviderErrors
 =ibprovider::CLSID_IBProviderErrors__Lite;

REFCLSID DEFAULT_CLSID_IBProviderDataLinkPropPage
 =ibprovider::CLSID_IBProviderDataLinkPropPage__Lite;

REFCLSID DEFAULT_CLSID_IBProviderDataLinkAdvPropPage
 =ibprovider::CLSID_IBProviderDataLinkAdvPropPage__Lite;

#else

# error "Unknown IBP_EDITION_ID"

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
