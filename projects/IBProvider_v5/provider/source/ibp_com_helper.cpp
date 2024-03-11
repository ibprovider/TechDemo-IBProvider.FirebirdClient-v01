////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com_helper.cpp
//! \brief   Реализация вспомогательного класса IBP_ComModule::THelper
//! \author  Kovalenko Dmitry
//! \date    07.05.2009
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_com_helper.h"
#include "source/ibp_com_data.h"
#include "source/ibp_debug.h"

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

#include "source/os/ibp_os__registry_utils.h"

#include "source/ibp_sys_props.h"
#include "source/ibp_guids.h"

#include <ole_lib/ole_lib__memory_allocator.h>
#include <ole_lib/ole_base.h>

#include <win32lib/win32_memory_heap.h>
#include <win32lib/win32_resource.h>
#include <win32lib/win32_error.h>
#include <win32lib/win32_memory_allocator.h>

#include <lcpi/lib/com/base/com_base__string_to_guid.h>

#include <lcpi/infrastructure/os/.config.h>

#include "rc/ibp_reg_data.rh"

#include "source/Version/ibp_v05_info_data.h"

//------------------------------------------------------------------------
#ifndef LCPI_INFRASTRUCTURE_OS__BUILD_MODE
# error LCPI_INFRASTRUCTURE_OS__BUILD_MODE is not defined
#endif

#if   (LCPI_INFRASTRUCTURE_OS__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__NONE)
# include <lcpi/infrastructure/os/lcpi.infrastructure.os-com_api_ids.h>
#elif (LCPI_INFRASTRUCTURE_OS__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__IMPORT)
# include "source/GEN__ibprovider_satellite_assemblies.h"
#endif

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

bool IBP_ComModule::THelper::InitHeaps()
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

 win32lib::TWin32MemoryAllocator::adapter::SetMemoryManager
  (g_DataHeap.vAlloc,
   g_DataHeap.vFree);

 return true;
}//InitHeaps

//------------------------------------------------------------------------
void IBP_ComModule::THelper::TermHeaps()
{
 self_type::Helper__DestroyHeap(g_DataHeap);
 self_type::Helper__DestroyHeap(g_ObjectHeap);
}//TermHeaps

//------------------------------------------------------------------------
template<class THeap>
void IBP_ComModule::THelper::Helper__DestroyHeap(THeap& UNUSED_ARG(Heap))
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

bool IBP_ComModule::THelper::InitData(HINSTANCE hInstance)
{
 bool result=false;

 try
 {
  for(;;)
  {
   assert(sm_pData==nullptr);

   sm_pData=new TData(hInstance);

   if(!self_type::Helper__DetectComApiID())
    break;

 #if(IBP_CFG_HAS_MODULE_CONFIG)
   //обработка служебной конфигурации модуля
   self_type::Helper__ProcessModuleConfig();
 #endif //IBP_CFG_HAS_MODULE_CONFIG

   //обработка конфигурации компонент модуля
   self_type::Helper__ProcessComponentConfig();

 #ifndef IBP_BUILD_TESTCODE
   //формируем данные для фабрик классов
   self_type::Helper__CreateFactoryData();
 #endif

  //чтение служебных параметров модуля
 #ifdef _PROCESS_DEBUG_MESSAGE_
   self_type::Helper__ReadFlushLogFilePeriod();
 #endif

   result=true;

   break;
  }//for[ever]
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
void IBP_ComModule::THelper::TermData()
{
 TData* const pTmp=sm_pData;

 sm_pData=nullptr;

 delete pTmp;
}//TermData

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

size_t IBP_ComModule::THelper::TestCode__GetAllocBlockCount()
{
 return g_DataHeap.GetAllocCount()+g_ObjectHeap.GetAllocCount();
}//TestCode__GetAllocBlockCount

#endif

////////////////////////////////////////////////////////////////////////////////

#ifndef LCPI_INFRASTRUCTURE_OS__BUILD_MODE
# error LCPI_INFRASTRUCTURE_OS__BUILD_MODE is not defined
#endif

#if(LCPI_INFRASTRUCTURE_OS__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__IMPORT)

#ifndef IBP_BUILD_PROP__SATELLITE_ASSEMBLY__OS_API__OLE32
# error IBP_BUILD_PROP__SATELLITE_ASSEMBLY__OS_API__OLE32 is not defined
#endif

#ifndef IBP_BUILD_PROP__SATELLITE_ASSEMBLY__OS_API__OLEAUT32
# error IBP_BUILD_PROP__SATELLITE_ASSEMBLY__OS_API__OLEAUT32 is not defined
#endif

#ifndef IBP_BUILD_PROP__SATELLITE_ASSEMBLY__MULTITASKING
# error IBP_BUILD_PROP__SATELLITE_ASSEMBLY__MULTITASKING is not defined
#endif

static const wchar_t* const g_COM_API_Providers[]=
{
 IBP_BUILD_PROP__SATELLITE_ASSEMBLY__OS_API__OLE32,
 IBP_BUILD_PROP__SATELLITE_ASSEMBLY__OS_API__OLEAUT32,
 IBP_BUILD_PROP__SATELLITE_ASSEMBLY__MULTITASKING,
};//g_COM_API_Providers

#endif // LCPI_INFRASTRUCTURE_OS__BUILD_MODE__IMPORT

////////////////////////////////////////////////////////////////////////////////

bool IBP_ComModule::THelper::Helper__DetectComApiID()
{
 assert(sm_pData!=nullptr);

#if(LCPI_INFRASTRUCTURE_OS__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__NONE)

 sm_pData->m_ComApiID=infrastructure::os::COM_API_ID__STANDARD;

#elif(LCPI_INFRASTRUCTURE_OS__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__IMPORT)

 GUID ComApiID=GUID_NULL;

 for(size_t iComApiProvider=0;iComApiProvider!=_LCPI_DIM_(g_COM_API_Providers);++iComApiProvider)
 {
  const auto comApiProviderName
   =g_COM_API_Providers[iComApiProvider];

  //-------------------------------------------------- 1. Get DLL

  const HINSTANCE hComApiProvider=::GetModuleHandle(comApiProviderName);

  if(hComApiProvider==NULL)
  {
   IBP_OUTPUT_DEBUG_STRING
    (_T("[")<<comApiProviderName<<_T("] was not found!"));

   return false;
  }//if

  assert(hComApiProvider!=NULL);

  //-------------------------------------------------- 2. Get LCPI_OS__GetComApiID

  using TPF_GetComApiID
   =BOOL (__stdcall *) (GUID* pComApiID);

  const TPF_GetComApiID
   pfnGetComApiID
    =(TPF_GetComApiID)::GetProcAddress(hComApiProvider,"LCPI_OS__GetComApiID");

  if(pfnGetComApiID==nullptr)
  {
   IBP_OUTPUT_DEBUG_STRING
    (_T("[")<<comApiProviderName<<_T("] doesn't export LCPI_OS__GetComApiID function!"));

   return false;
  }//if

  assert(pfnGetComApiID!=nullptr);

  //-------------------------------------------------- 3. Call LCPI_OS__GetComApiID
  GUID tmpID=GUID_NULL;

  if(!pfnGetComApiID(&tmpID))
  {
   IBP_OUTPUT_DEBUG_STRING
    (_T("[")<<comApiProviderName<<_T("].[LCPI_OS__GetComApiID] returns FALSE!"));

   return false;
  }//if

  if(iComApiProvider==0)
  {
   ComApiID=tmpID;

   continue;
  }//if

  assert(iComApiProvider>0);

  if(tmpID!=ComApiID)
  {
   IBP_OUTPUT_DEBUG_STRING
    (_T("[")<<comApiProviderName<<_T("] provides unexpected API: ")<<ole_lib::guid_to_tstr(tmpID)<<_T(". ")
     _T("Expected API: ")<<ole_lib::guid_to_tstr(ComApiID));

   return false;
  }//if

  assert(tmpID==ComApiID);
 }//for iComApiProvider

 //--------------------------------------------------- 4. Remember ComApiID

 sm_pData->m_ComApiID=ComApiID;
#else
# error Unknown LCPI_INFRASTRUCTURE_OS__BUILD_MODE
#endif

 return true;
}//Helper__DetectComApiID

////////////////////////////////////////////////////////////////////////////////
//Чтение конфигурационных данных модуля

#if(IBP_CFG_HAS_MODULE_CONFIG)
void IBP_ComModule::THelper::Helper__ProcessModuleConfig()
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
void IBP_ComModule::THelper::Helper__ProcessComponentConfig()
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
   IBP_PROVIDER_PROG_ID_VER,
   &sm_pData->m_IBProvider_ProgID);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_provider_prog_id_no_ver,
   IBP_PROVIDER_PROG_ID_NO_VER,
   nullptr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_provider_descr,
   IBP_PROVIDER_DESCRIPTION_STRING,
   &sm_pData->m_IBProvider_Descr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_error_service_descr,
   IBP_ERRORS_DESCRIPTION_STRING,
   nullptr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_data_link_page_descr,
   IBP_DATA_LINK_STD_PROP_PAGE_DESCRIPTION_STRING,
   nullptr);

 self_type::Helper__ProcessRegParam__String
  (params,
   ibp_sprop_adv_data_link_page_descr,
   IBP_DATA_LINK_ADV_PROP_PAGE_DESCRIPTION_STRING,
   nullptr);

 //формируем строку с параметрами для регистрации сервера ----------------
 sm_pData->m_prog_reg_params=params.to_string();
}//Helper__ProcessComponentConfig

//------------------------------------------------------------------------
void IBP_ComModule::THelper::Helper__ProcessRegParam__CLSID
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
  (*(i.position)).value()=ole_lib::guid_to_tstr(user_clsid);

  return;
 }//if

 (*pclsid)=default_clsid;

 params.set(prop_id,ole_lib::guid_to_tstr(default_clsid));
}//Helper__ProcessRegParam__CLSID

//------------------------------------------------------------------------
bool IBP_ComModule::THelper::Helper__HasComponent
                                           (const string_type& param_value,
                                            CLSID&             clsid)
{
 if(param_value.empty())
 {
  return false;
 }

 if(!lib::com::base::string_to_guid(param_value,&clsid))
 {
  return false;
 }

 return true;
}//Helper__HasComponent

//------------------------------------------------------------------------
void IBP_ComModule::THelper::Helper__ProcessRegParam__String
                                           (param_parser_type&     params,
                                            const char_type* const prop_id,
                                            const char*      const prop_def_value,
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

 string_type x(structure::tstr_to_tstr(prop_def_value));

 params.set(prop_id,x);

 if(value)
  value->swap(x);
}//Helper__ProcessRegParam__String

////////////////////////////////////////////////////////////////////////////////
//Создание данных для фабрик

#ifndef IBP_BUILD_TESTCODE

void IBP_ComModule::THelper::Helper__CreateFactoryData()
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
  (TData::Get_CLSID_IBProviderErrorLookup__private(),
   oledb::IBP_OLEDB__ErrorLookup::Create);

 Helper__AddFactoryData
  (TData::Get_CLSID_IBProviderDataLinkPropPage__private(),
   oledb::ui::TIBPDataLinkPropertyPage::Create);

 Helper__AddFactoryData
  (TData::Get_CLSID_IBProviderDataLinkAdvPropPage__private(),
   oledb::ui::TIBPDataLinkAdvPropertyPage::Create);
}//Helper__CreateFactoryData

//------------------------------------------------------------------------
void IBP_ComModule::THelper::Helper__AddFactoryData
                                           (REFCLSID                 rclsid,
                                            PFNCREATEINSTANCE1 const fn)
{
 assert(sm_pData!=NULL);

 if(rclsid==CLSID_NULL)
  return;

 sm_pData->m_ClassFactoryDatas.push_back
  (IBP_OLEDB__ClassFactoryData
    (rclsid,
     fn));
}//Helper__AddFactoryData - PFNCREATEINSTANCE1

////////////////////////////////////////////////////////////////////////////////
#endif // !IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////
//чтение служебных параметров модуля

#ifdef _PROCESS_DEBUG_MESSAGE_
void IBP_ComModule::THelper::Helper__ReadFlushLogFilePeriod()
{//Читаем настройки трассировочной версии
 assert(sm_pData!=NULL);

 if(sm_pData->m_CLSID_IBProvider==CLSID_NULL)
  return;

 const auto get_r
  =os::t_ibp_os__registry_utils::read_flush_period_for_log_file
    (sm_pData->m_CLSID_IBProvider);

 if(get_r.first)
  TData::sm_FlushLogFilePeriod=get_r.second;
}//Helper__ReadFlushLogFilePeriod
#endif //_PROCESS_DEBUG_MESSAGE_

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
