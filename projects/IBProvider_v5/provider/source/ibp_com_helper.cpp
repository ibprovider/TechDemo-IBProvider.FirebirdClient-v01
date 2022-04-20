////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com_helper.cpp
//! \brief   Реализация вспомогательного класса TIBP_ComModule::THelper
//! \author  Kovalenko Dmitry
//! \date    07.05.2009
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_com_helper.h"
#include "source/ibp_com_data.h"

#ifndef IBP_BUILD_TESTCODE

# include "source/oledb/data_source/ibp_oledb__data_source.h"
# include "source/oledb/ui/ibp_oledb__ui_ds_prop_page.h"
# include "source/oledb/ui/ibp_oledb__ui_adv_prop_page.h"

# include "source/oledb/error/ibp_oledb__error_lookup.h"

# include "source/oledb/ibp_oledb__class_factory_data.h"

#endif // !IBP_BUILD_TESTCODE

# if(IBP_CFG_HAS_MODULE_CONFIG)
#  include "source/config/ibp_cfg_loader.h"
#  include "rc/ibp_config.rh"
# endif

#include "source/ibp_sys_props.h"
#include "source/ibp_guids.h"

#include <ole_lib/oledb/variant/oledb_variant_cvt_utils.h>
#include <win32lib/win32_memory_heap.h>
#include <win32lib/win32_resource.h>
#include <win32lib/win32_registry.h>
#include <win32lib/win32_error.h>

#include "rc/ibp_reg_data.rh"

#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//Memory heaps

//! \cond DOXYGEN_PROCESS_ALL

WIN32LIB__DECLARE_HEAP(g_ObjectHeap)
WIN32LIB__DEFINE_HEAP(,g_ObjectHeap,throw std::bad_alloc())

WIN32LIB__DECLARE_HEAP(g_DataHeap)//объявляем кучу для временных объектов
WIN32LIB__DEFINE_HEAP(,g_DataHeap,throw std::bad_alloc())

//! \endcond

////////////////////////////////////////////////////////////////////////////////
//Создание/уничтожение собственных куч

bool TIBP_ComModule::THelper::InitHeaps()
{
 if(!g_ObjectHeap.Create(0,64*1024,0))
  return false;

 if(!g_DataHeap.Create(0,64*1024,0))
  return false;

 ole_lib::TComObjectMemoryAllocator::adapter::SetMemoryManager
  (g_ObjectHeap.vAlloc,
   g_ObjectHeap.vFree);

 oledb_lib::TOLEDBMemoryAllocator::adapter::SetMemoryManager
  (g_DataHeap.vAlloc,
   g_DataHeap.vFree);

 return true;
}//InitHeaps

//------------------------------------------------------------------------
void TIBP_ComModule::THelper::TermHeaps()
{
 self_type::Helper__DestroyHeap(g_DataHeap);
 self_type::Helper__DestroyHeap(g_ObjectHeap);
}//TermHeaps

//------------------------------------------------------------------------
template<class THeap>
void TIBP_ComModule::THelper::Helper__DestroyHeap(THeap& UNUSED_ARG(Heap))
{
 assert_msg(THeap::GetAllocCount()==0,
            "Heap: ["<<THeap::GetName()<<"]. "
            "BlockCount: "<<THeap::GetAllocCount());

 if(THeap::Created())
 {
  assert_msg(THeap::Validate(0),"Heap: ["<<THeap::GetName()<<"]");

  DEBUG_CODE(const BOOL bDestroyResult=)THeap::Destroy();

  assert_msg(bDestroyResult,
             "Heap: ["<<THeap::GetName()<<"]. "
             <<structure::tstr_to_str(win32lib::GetErrorMsg(::GetLastError())));
 }//if Heap.Created()
}//Helper__DestroyHeap

////////////////////////////////////////////////////////////////////////////////
//Инициализация/деинициализация собственных данных

bool TIBP_ComModule::THelper::InitData()
{
 assert(sm_pData==NULL);

 bool result=true;

 try
 {
  sm_pData=new TData(_Module.GetModuleInstance());

 #if(IBP_CFG_HAS_MODULE_CONFIG)
  //обработка служебной конфигурации модуля
  Helper__ProcessModuleConfig();
 #endif //IBP_CFG_HAS_MODULE_CONFIG

  //обработка конфигурации компонент модуля
  Helper__ProcessComponentConfig();

 #ifndef IBP_BUILD_TESTCODE
  //формируем данные для фабрик классов
  Helper__CreateFactoryData();
 #endif

  //чтение служебных параметров модуля
 #ifdef _PROCESS_DEBUG_MESSAGE_
  Helper__ReadFlushLogFilePeriod();
 #endif
 }
 catch(...)
 {
  result=false;

  //! \attention
  //!  Here we may get the exception, which uses our Memory Heaps!

#ifdef DebugMessage
  try
  {
   DebugMessage("IBPROVIDER: PROBLEM WITH DLL INITIALIZATION!");
  }
  catch(...)
  {}
#endif
 }//catch

 if(!result)
 {
  self_type::TermData();
 }

 return result;
}//InitData

//------------------------------------------------------------------------
void TIBP_ComModule::THelper::TermData()
{
 TData* const pTmp=sm_pData;

 sm_pData=nullptr;

 delete pTmp;
}//TermData

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

size_t TIBP_ComModule::THelper::TestCode__GetAllocBlockCount()
{
 return g_DataHeap.GetAllocCount()+g_ObjectHeap.GetAllocCount();
}//TestCode__GetAllocBlockCount

#endif

////////////////////////////////////////////////////////////////////////////////
//Чтение конфигурационных данных модуля

#if(IBP_CFG_HAS_MODULE_CONFIG)
void TIBP_ComModule::THelper::Helper__ProcessModuleConfig()
{
 assert(sm_pData!=NULL);
 assert(_Module.GetModuleInstance()!=NULL);

 {
  const HRSRC hRes=::FindResourceEx(_Module.GetModuleInstance(),
                                    _T("IBP_CONFIG"),
                                    TResID(IBP_ID_MODULE_CONFIG),
                                    MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL));

  if(hRes!=NULL)
  {
   const DWORD cbRes= //определяем размер ресурса
    ::SizeofResource(_Module.GetModuleInstance(),hRes);

   const char* const pRes=
    reinterpret_cast<const char*>(::LoadResource(_Module.GetModuleInstance(),hRes));

   _VERIFY(IBP_LoadConfig(sm_pData->m_config,pRes,cbRes));
  }//if
 }//local

 //Инициализация ---------------------------------------------------------

 //конфигурирование контроллера FPU CW
 t_fpu_cw_guard::set_default(sm_pData->m_config);
}//Helper__ProcessModuleConfig
#endif //IBP_CFG_HAS_MODULE_CONFIG

//------------------------------------------------------------------------
void TIBP_ComModule::THelper::Helper__ProcessComponentConfig()
{
 assert(sm_pData!=NULL);
 assert(_Module.GetModuleInstance()!=NULL);

 param_parser_type params;

 {
  const HRSRC hRes=::FindResourceEx(_Module.GetModuleInstance(),
                                    _T("LCPI.PROG_REG_PARAMS"),
                                    win32lib::TResID(IBP_ID_PROG_REG_PARAMS),
                                    MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL));

  if(hRes!=NULL)
  {
   const DWORD cbRes= //определяем размер ресурса
    ::SizeofResource(_Module.GetModuleInstance(),hRes);

   const char* const pRes=
    reinterpret_cast<const char*>(::LoadResource(_Module.GetModuleInstance(),hRes));

   params.parse(structure::str_to_tstr(pRes,cbRes)); //throw
  }//if
 }//local

 //обработка идентификаторов компонент
 self_type::Helper__ProcessRegParam__CLSID
  (params,
   ibp_sprop_provider_clsid,
   DEFAULT_CLSID_IBProvider,
   &sm_pData->m_CLSID_IBProvider);

 self_type::Helper__ProcessRegParam__CLSID
  (params,
   ibp_sprop_error_service_clsid,
   DEFAULT_CLSID_IBProviderErrors,
   &sm_pData->m_CLSID_IBProviderErrors);

 self_type::Helper__ProcessRegParam__CLSID
  (params,
   ibp_sprop_data_link_page_clsid,
   DEFAULT_CLSID_IBProviderDataLinkPropPage,
   &sm_pData->m_CLSID_IBProviderDataLinkPropPage);

 self_type::Helper__ProcessRegParam__CLSID
  (params,
   ibp_sprop_adv_data_link_page_clsid,
   DEFAULT_CLSID_IBProviderDataLinkAdvPropPage,
   &sm_pData->m_CLSID_IBProviderDataLinkAdvPropPage);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_provider_prog_id,
   _T(IBP_PROVIDER_PROG_ID_VER),
   &sm_pData->m_IBProvider_ProgID);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_provider_prog_id_no_ver,
   _T(IBP_PROVIDER_PROG_ID_NO_VER),
   nullptr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_provider_descr,
   _T(IBP_PROVIDER_DESCRIPTION_STRING),
   &sm_pData->m_IBProvider_Descr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_error_service_descr,
   _T(IBP_ERRORS_DESCRIPTION_STRING),
   nullptr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_data_link_page_descr,
   _T(IBP_DATA_LINK_PROP_PAGE_DESCRIPTION_STRING),
   nullptr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_adv_data_link_page_descr,
   _T(IBP_DATA_LINK_ADV_PROP_PAGE_DESCRIPTION_STRING),
   nullptr);

 //формируем строку с параметрами для регистрации сервера ----------------
 sm_pData->m_prog_reg_params=params.to_string();
}//Helper__ProcessComponentConfig

//------------------------------------------------------------------------
void TIBP_ComModule::THelper::Helper__ProcessRegParam__CLSID
                                           (param_parser_type&     params,
                                            const char_type* const prop_id,
                                            REFCLSID               default_clsid,
                                            CLSID*           const pclsid)
{
 assert(prop_id!=NULL);
 assert(default_clsid!=CLSID_NULL);
 assert(pclsid!=NULL);

 if(const param_parser_type::search_result_type i=params.search(prop_id))
 {
  CLSID user_clsid=CLSID_NULL;

  if(!self_type::Helper__HasComponent((*i.position).value(),user_clsid))  //отказ от компоненты
  {
   params.erase(i.position);

   (*pclsid)=CLSID_NULL;

   return;
  }//if

  (*pclsid)=user_clsid;

  //запоминаем назначенный идентификатор компоненты
  (*(i.position)).value()=ole_lib::clsid_to_tstr(user_clsid);

  return;
 }//if

 (*pclsid)=default_clsid;

 params.set(prop_id,ole_lib::clsid_to_tstr(default_clsid));
}//Helper__ProcessRegParam__CLSID

//------------------------------------------------------------------------
bool TIBP_ComModule::THelper::Helper__HasComponent(const string_type& param_value,
                                                   CLSID&             clsid)
{
 if(param_value.empty())
 {
  return false;
 }

 if(oledb_lib::DBVARIANT_CVT_UTILS::TStrToGUID(param_value.c_str(),
                                               param_value.size(),
                                               &clsid)!=S_OK)
 {
  return false;
 }

 return true;
}//Helper__HasComponent

//------------------------------------------------------------------------
void TIBP_ComModule::THelper::Helper__ProcessRegParam__String
                                           (param_parser_type&     params,
                                            const char_type* const prop_id,
                                            const char_type* const prop_def_value,
                                            string_type*     const value)
{
 assert(prop_id);
 assert(prop_def_value);

 if(const param_parser_type::search_result_type i=params.search(prop_id))
 {
  if(!(*i.position).value().empty())
  {
   if(value)
    (*value)=(*i.position).value();

   return;
  }//if
 }//if

 params.set(prop_id,prop_def_value);

 if(value)
  (*value)=prop_def_value;
}//Helper__ProcessRegParam__String

////////////////////////////////////////////////////////////////////////////////
//Создание данных для фабрик

#ifndef IBP_BUILD_TESTCODE

void TIBP_ComModule::THelper::Helper__CreateFactoryData()
{
 assert(sm_pData!=NULL);

 Helper__AddFactoryData
  (sm_pData->m_CLSID_IBProvider,
   oledb::IBP_OLEDB__DataSource::Create);

 Helper__AddFactoryData
  (sm_pData->m_CLSID_IBProviderErrors,
   oledb::IBP_OLEDB__ErrorLookup::Create);

 Helper__AddFactoryData
  (sm_pData->m_CLSID_IBProviderDataLinkPropPage,
   oledb::ui::TIBPDataLinkPropertyPage::Create);

 Helper__AddFactoryData
  (sm_pData->m_CLSID_IBProviderDataLinkAdvPropPage,
   oledb::ui::TIBPDataLinkAdvPropertyPage::Create);

 //----------------------------------------- private clsids
 Helper__AddFactoryData
  (TData::Get_CLSID_IBProvider__private(),
   oledb::IBP_OLEDB__DataSource::Create);

 Helper__AddFactoryData
  (TData::Get_CLSID_IBProviderDataLinkPropPage__private(),
   oledb::ui::TIBPDataLinkPropertyPage::Create);

 Helper__AddFactoryData
  (TData::Get_CLSID_IBProviderDataLinkAdvPropPage__private(),
   oledb::ui::TIBPDataLinkAdvPropertyPage::Create);
}//Helper__CreateFactoryData

//------------------------------------------------------------------------
void TIBP_ComModule::THelper::Helper__AddFactoryData
                                           (REFCLSID                 rclsid,
                                            PFNCREATEINSTANCE1 const fn)
{
 assert(sm_pData!=NULL);

 if(rclsid==CLSID_NULL)
  return;

 const ole_lib::TBaseClassFactoryData::self_ptr
  spData(IBP_ClassFactoryData::Create(rclsid,fn));

 assert(spData);

 sm_pData->m_FactoryData.push_back(spData);
}//Helper__AddFactoryData - PFNCREATEINSTANCE1

//------------------------------------------------------------------------
void TIBP_ComModule::THelper::Helper__AddFactoryData
                                           (REFCLSID                 rclsid,
                                            PFNCREATEINSTANCE2 const fn)
{
 assert(sm_pData!=NULL);

 if(rclsid==CLSID_NULL)
  return;

 const ole_lib::TBaseClassFactoryData::self_ptr
  spData(ole_lib::TAggregationClassFactoryData::Create(rclsid,fn));

 assert(spData);

 sm_pData->m_FactoryData.push_back(spData);
}//Helper__AddFactoryData - PFNCREATEINSTANCE2

////////////////////////////////////////////////////////////////////////////////
#endif // !IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////
//чтение служебных параметров модуля

#ifdef _PROCESS_DEBUG_MESSAGE_
void TIBP_ComModule::THelper::Helper__ReadFlushLogFilePeriod()
{//Читаем настройки трассировочной версии
 assert(sm_pData!=NULL);

 if(sm_pData->m_CLSID_IBProvider==CLSID_NULL)
  return;

 win32lib::TRegistry Reg(HKEY_CLASSES_ROOT);

 win32lib::t_string reg_path(_T("CLSID\\"));

 reg_path+=ole_lib::clsid_to_tstr(sm_pData->m_CLSID_IBProvider);

 if(Reg.OpenKeyEx(reg_path,KEY_READ,/*create*/false)==ERROR_SUCCESS)
  TData::sm_FlushLogFilePeriod=Reg.ReadInteger(ibp_sprop_flush_log_period,NULL);
}//Helper__ReadFlushLogFilePeriod
#endif //_PROCESS_DEBUG_MESSAGE_

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
