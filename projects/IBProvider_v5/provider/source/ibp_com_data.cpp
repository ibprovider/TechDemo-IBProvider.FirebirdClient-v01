////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com_data.cpp
//! \brief   Данные менеджера COM-модуля
//! \author  Kovalenko Dmitry
//! \date    07.05.2009
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_com_data.h"

#include <win32lib/win32lib.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_ComModule::TData

 #ifdef _PROCESS_DEBUG_MESSAGE_
LONG TIBP_ComModule::TData::sm_FlushLogFilePeriod=0;
#endif

TIBP_ComModule::TData::TData(HINSTANCE const hInstance)
 :m_ModulePath(win32lib::GetModuleFileName(hInstance))
 ,m_module_lock_count_guard()
 ,m_module_lock_count(0)
 ,m_component_count(0)
 ,m_server_lock_count(0)
 ,m_CLSID_IBProvider(CLSID_NULL)
 ,m_CLSID_IBProviderErrors(CLSID_NULL)
 ,m_CLSID_IBProviderDataLinkPropPage(CLSID_NULL)
 ,m_CLSID_IBProviderDataLinkAdvPropPage(CLSID_NULL)
{
 //! \todo: It needs to use OS Utils!
 m_ModuleName=m_ModulePath.substr(m_ModulePath.rfind(_T('\\'))+1);

#if(IBP_CFG_HAS_MODULE_CONFIG)
 //DONE 5: Здесь нужно проинициализировать m_config по умолчанию
 t_fpu_cw_guard::get_default(m_config);
#endif
}//TData

//------------------------------------------------------------------------
TIBP_ComModule::TData::~TData()
{
 assert_msg
  (m_module_lock_count==0,
   "module_lock_count: "<<m_module_lock_count);

 assert_msg
  (m_component_count==0,
   "component_count: "<<m_component_count);

 assert_msg
  (m_server_lock_count==0,
   "server_lock_count: "<<m_server_lock_count);
}//~TData

//------------------------------------------------------------------------
#if _IBP_BUILD__CREATE_TRIAL
# define IBP__BUILD_PRIVATE_CLSID1(a,b,c,d,e) a##b##_##c##_##d##_##e##_trial
#else
# define IBP__BUILD_PRIVATE_CLSID1(a,b,c,d,e) a##b##_##c##_##d##_##e
#endif

#define IBP__BUILD_PRIVATE_CLSID(a,b,c,d,e) IBP__BUILD_PRIVATE_CLSID1(a,b,c,d,e)

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::TData::Get_CLSID_IBProvider__private()
{
return IBP__BUILD_PRIVATE_CLSID
   (ibprovider::CLSID_IBProvider__private__,
    IBP_BINARY_COMPILER_SIGN,
    IBP_BINARY_PLATFORM_SIGN,
    IBP_BINARY_EDITION_SIGN,
    IBP_BINARY_CONFIGURATION_SIGN);
}//Get_CLSID_IBProvider__private

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::TData::Get_CLSID_IBProviderDataLinkPropPage__private()
{
return IBP__BUILD_PRIVATE_CLSID
   (ibprovider::CLSID_IBProviderDataLinkPropPage__private__,
    IBP_BINARY_COMPILER_SIGN,
    IBP_BINARY_PLATFORM_SIGN,
    IBP_BINARY_EDITION_SIGN,
    IBP_BINARY_CONFIGURATION_SIGN);
}//Get_CLSID_IBProviderDataLinkPropPage__private

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::TData::Get_CLSID_IBProviderDataLinkAdvPropPage__private()
{
return IBP__BUILD_PRIVATE_CLSID
   (ibprovider::CLSID_IBProviderDataLinkAdvPropPage__private__,
    IBP_BINARY_COMPILER_SIGN,
    IBP_BINARY_PLATFORM_SIGN,
    IBP_BINARY_EDITION_SIGN,
    IBP_BINARY_CONFIGURATION_SIGN);
}//Get_CLSID_IBProviderDataLinkAdvPropPage__private

//------------------------------------------------------------------------
#undef IBP__BUILD_PRIVATE_CLSID
#undef IBP__BUILD_PRIVATE_CLSID1

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
