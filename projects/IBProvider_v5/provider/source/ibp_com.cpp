////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com.cpp
//! \brief   Менеджер COM-модуля
//! \author  Kovalenko Dmitry
//! \date    28.04.2004
#include <_pch_.h>
#pragma hdrstop

#ifndef IBP_ENGINE_GLOBAL_OBJECTS
# error IBP_ENGINE_GLOBAL_OBJECTS is not defined
#endif

//------------------------------------------------------------------------
#include "source/ibp_com_helper.h"

#ifndef IBP_BUILD_TESTCODE
# include "source/oledb/ibp_oledb__exception_handler.h"
# include "source/oledb/ibp_oledb__class_factory.h"
# include "source/error_services/ibp_error__com_module_is_shutdown.h"
# include "source/error_services/ibp_error_utils.h"
#endif

#if(IBP_ENGINE_GLOBAL_OBJECTS!=0)
# include "source/ibp_global_objects.h"
#endif

#include <win32lib/win32lib.h>
#include <structure/t_str_formatter.h>

#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//static data

HINSTANCE IBP_ComModule::sm_hInstance=NULL;

IBP_ComModule::TData* IBP_ComModule::sm_pData=NULL;

////////////////////////////////////////////////////////////////////////////////
//class IBP_ComModule

bool IBP_ComModule::Init(HINSTANCE const hInstance)
{
 bool bResult=false;

 try
 {
  for(;;)
  {
   sm_hInstance=hInstance;

   //создание куч
   if(!THelper::InitHeaps())
    break;

   //инициализация служебных данных
   if(!THelper::InitData(hInstance))
    break;

#if(IBP_ENGINE_GLOBAL_OBJECTS!=0)
   //инициализация менеджера глобальных объектов
   if(!IBP_GlobalObjects::Init())
    break;
#endif // IBP_ENGINE_GLOBAL_OBJECTS!=0

   bResult=true;

   break;
  }//for[ever]
 }
 catch(...)
 {
  bResult=false;
 }//catch

 if(!bResult)
  self_type::Term();

 return bResult;
}//Init

//------------------------------------------------------------------------
void IBP_ComModule::Term()
{
#ifdef DebugMessage
 try
 {
  const string_type
   ModuleName(win32lib::GetModuleFileName(sm_hInstance)); //throw

  DebugMessage("*****************************")

  DebugMessage("IBP_ComModule::Term "
               "["<<structure::tstr_to_str(ModuleName)<<"]");

  if(sm_pData!=nullptr)
  {
   if(auto const module_lock_count=sm_pData->m_module_lock_count)
   {
    assert_hint(module_lock_count!=0);

    assert(module_lock_count>0); //[2018-12-24]

    DebugMessage("COM MODULE HAS ACTIVE LOCKS "
                 "["<<module_lock_count<<"]"
                 " "<<structure::tstr_to_str(ModuleName));

    assert_msg(false,
               "module_lock_count: "<<module_lock_count<<". "
               "component_count: "<<sm_pData->m_component_count);
   }//if
  }//if
 }
 catch(...)
 {;}
#endif //DebugMessage

#ifndef NDEBUG
 if(sm_pData!=nullptr)
 {
  if(auto const module_lock_count=sm_pData->m_module_lock_count)
  {
   assert_hint(module_lock_count!=0);

   assert(module_lock_count>0); //[2018-12-24]

   assert_msg(false,
              "module_lock_count: "<<module_lock_count<<". "
              "component_count: "<<sm_pData->m_component_count);
  }//if

  assert(sm_pData->m_module_lock_count==0);

  if(auto const component_count=sm_pData->m_component_count)
  {
   assert_hint(component_count!=0);

   assert(component_count>0); //[2022-11-08]

   assert_msg(false,
              "module_lock_count: "<<sm_pData->m_module_lock_count<<". "
              "component_count: "<<component_count);
  }//if

  assert(sm_pData->m_component_count==0);

  if(auto const server_lock_count=sm_pData->m_server_lock_count)
  {
   assert_hint(server_lock_count!=0);

   assert(server_lock_count>0); //[2018-12-24]

   assert_msg(false,
              "server_lock_count: "<<server_lock_count);
  }//if

  assert(sm_pData->m_server_lock_count==0);
 }//if sm_pData!=nullptr
#endif

#if(IBP_ENGINE_GLOBAL_OBJECTS!=0)
 //освобождение глобальных объектов
 IBP_GlobalObjects::Done();
#endif //IBP_ENGINE_GLOBAL_OBJECTS!=0

 //уничтожение собственных данных менеджера модуля
 THelper::TermData();

 //разрушаем собственные кучи
 THelper::TermHeaps();
}//Term

////////////////////////////////////////////////////////////////////////////////
//Управление COM-модулем

HINSTANCE IBP_ComModule::GetModuleInstance()
{
 return sm_hInstance;
}//GetModuleInstance

//------------------------------------------------------------------------
const IBP_ComModule::string_type& IBP_ComModule::GetModulePath()
{
 assert(sm_pData);

 return sm_pData->GetModulePath();
}//GetModulePath

//------------------------------------------------------------------------
const IBP_ComModule::string_type& IBP_ComModule::GetModuleName()
{
 assert(sm_pData);

 return sm_pData->GetModuleName();
}//GetModuleName

//сборка номера версии провайдера ----------------------------------------
IBP_ComModule::string_type IBP_ComModule::GetModuleVersion(const char_type* const prefix)
{
 string_type result;

 if(prefix!=nullptr)
  result+=prefix;

 result+=_T(IBP_VI_PRODUCT_VER_STRING1);

 return result;
}//GetModuleVersion

//------------------------------------------------------------------------
REFGUID IBP_ComModule::GetComApiID()
{
 assert(sm_pData!=nullptr);

 return sm_pData->m_ComApiID;
}//GetComApiID

//------------------------------------------------------------------------
IBP_ComModule::string_type IBP_ComModule::GetProviderLabel()
{
#ifndef IBP_PLATFORM_ID
# error IBP_PLATFORM_ID is not defined!
#endif

#if   (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
 const char_type* flabel_tstr(_T("%1 %2 [64-bit]"));
#elif (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
 const char_type* flabel_tstr(_T("%1 %2 [32-bit]"));
#else
# error Unknown platform ID!
#endif

 structure::t_basic_str_formatter<char_type> flabel(flabel_tstr);

 return flabel<<IBP_PROVIDER_NAME<<self_type::GetModuleVersion(NULL);
}//GetProviderLabel

//------------------------------------------------------------------------
#ifndef NDEBUG

bool IBP_ComModule::DEBUG__ModuleIsActive()
{
 return self_type::GetModuleLockCount()!=0;
}//DEBUG__ModuleIsActive

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

bool IBP_ComModule::DEBUG__ModuleIsShutdown()
{
 return self_type::GetModuleLockCount()==0;
}//DEBUG__ModuleIsShutdown

#endif // !NDEBUG

//------------------------------------------------------------------------
size_t IBP_ComModule::GetModuleLockCount()
{
 assert(sm_pData!=nullptr);

 return sm_pData->m_module_lock_count;
}//GetModuleLockCount

//------------------------------------------------------------------------
size_t IBP_ComModule::GetComponentCount()
{
 assert(sm_pData!=nullptr);

 return sm_pData->m_component_count;
}//GetComponentCount

//------------------------------------------------------------------------
bool IBP_ComModule::DllCanUnloadNow()
{
 assert(sm_pData!=nullptr);

 if(sm_pData->m_module_lock_count!=0)
  return false;

 if(sm_pData->m_server_lock_count!=0)
  return false;

 return true;
}//DllCanUnloadNow

//------------------------------------------------------------------------
#ifndef IBP_BUILD_TESTCODE

void IBP_ComModule::CheckActiveState()
{
 if(self_type::GetModuleLockCount()==0)
 {
  t_ibp_error__com_module_is_shutdown::throw_error();
 }//if

 assert(self_type::GetModuleLockCount()>0);
}//CheckActiveState

#endif

//------------------------------------------------------------------------
void IBP_ComModule::IncrementModuleLockCount()
{
 assert(sm_pData!=nullptr);

 const thread_traits::lock_guard_type lock(sm_pData->m_module_lock_count_guard);

 lib::structure::mt::interlocked::increment(&sm_pData->m_module_lock_count);
}//IncrementModuleLockCount

//------------------------------------------------------------------------
void IBP_ComModule::DecrementModuleLockCount()
{
 assert(sm_pData!=nullptr);

 const thread_traits::lock_guard_type lock(sm_pData->m_module_lock_count_guard);

 assert(sm_pData->m_module_lock_count>0);

 if(lib::structure::mt::interlocked::decrement(&sm_pData->m_module_lock_count)!=0)
  return;

#ifndef IBP_BUILD_TESTCODE
 ///Уведомляем пул глобальных объектов об освобождении последней блокировки
 ///COM-модуля. Будут остановлены менеджеры рабочих потоков.

 IBP_GlobalObjects::ReleaseLastModuleLock();
#endif

 //---
 return;
}//DecrementModuleLockCount

//------------------------------------------------------------------------
void IBP_ComModule::IncrementComponentCount2()
{
 assert(sm_pData!=nullptr);

 lib::structure::mt::interlocked::increment(&sm_pData->m_component_count);
}//IncrementComponentCount2

//------------------------------------------------------------------------
void IBP_ComModule::DecrementComponentCount2()
{
 assert(sm_pData!=nullptr);

 assert(sm_pData->m_component_count>0);

 lib::structure::mt::interlocked::decrement(&sm_pData->m_component_count);
}//DecrementComponentCount2

//------------------------------------------------------------------------
void IBP_ComModule::LockServer()
{
 assert(sm_pData!=nullptr);

 lib::structure::mt::interlocked::increment(&sm_pData->m_server_lock_count);
}//LockServer

//------------------------------------------------------------------------
void IBP_ComModule::UnlockServer()
{
 assert(sm_pData!=nullptr);
 assert(sm_pData->m_server_lock_count>0);

 lib::structure::mt::interlocked::decrement(&sm_pData->m_server_lock_count);
}//UnlockServer

////////////////////////////////////////////////////////////////////////////////
//Создание фабрик COM-объектов модуля

#ifndef IBP_BUILD_TESTCODE

HRESULT IBP_ComModule::GetClassObject(REFGUID      rComApiID,
                                       REFCLSID     rclsid,
                                       REFIID       riid,
                                       void** const ppv)
{
 assert(sm_pData!=nullptr);

 if(ppv==nullptr)
  return E_POINTER;

 (*ppv)=nullptr;

 OLE_LIB__DECLARE_HR(CLASS_E_CLASSNOTAVAILABLE);

 _OLE_TRY_
 {
  if(rComApiID!=self_type::GetComApiID())
  {
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_common__unsupported_com_api_2,
     rComApiID,
     self_type::GetComApiID());
  }//if

  assert(rComApiID==self_type::GetComApiID());

  //----------------------------------------
  typedef TData::class_factory_datas_type::const_iterator const_iterator;

  const_iterator        i(sm_pData->m_ClassFactoryDatas.begin());
  const_iterator const _e(sm_pData->m_ClassFactoryDatas.end());

  for(;i!=_e;++i)
  {
   if((*i).m_ClassID!=rclsid)
    continue;

   hr=ole_lib::TBaseUnknown2::FullCreate(new IBP_OLEDB__ClassFactory(*i),riid,ppv);

   break;
  }//for
 }
 _OLE_CATCHES4_(reinterpret_cast<IUnknown*>(nullptr),CLSID_NULL,IID_NULL,true)

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetClassObject

#endif //IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////
//получение параметров регистрации модуля в системе

const IBP_ComModule::string_type& IBP_ComModule::GetProgRegParams()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_prog_reg_params;
}//GetProgRegParams

//------------------------------------------------------------------------
const IBP_ComModule::string_type& IBP_ComModule::Get_IBProvider_FileExt()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_IBProvider_FileExt;
}//Get_IBProvider_FileExt

//------------------------------------------------------------------------
const IBP_ComModule::string_type& IBP_ComModule::Get_IBProvider_ProgID()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_IBProvider_ProgID;
}//Get_IBProvider_ProgID

//------------------------------------------------------------------------
const IBP_ComModule::string_type& IBP_ComModule::Get_IBProvider_Descr()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_IBProvider_Descr;
}//Get_IBProvider_Descr

//------------------------------------------------------------------------
#ifdef _PROCESS_DEBUG_MESSAGE_
LONG IBP_ComModule::Get_FlushLogFilePeriod()
{
 return TData::sm_FlushLogFilePeriod;
}//Get_FlushLogFilePeriod
#endif

////////////////////////////////////////////////////////////////////////////////
//получение идентификаторов компонент модуля

REFCLSID IBP_ComModule::Get_CLSID_IBProvider()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProvider;
}//Get_CLSID_IBProvider

//------------------------------------------------------------------------
REFCLSID IBP_ComModule::Get_CLSID_IBProvider__private()
{
 return TData::Get_CLSID_IBProvider__private();
}//Get_CLSID_IBProvider__private

//------------------------------------------------------------------------
REFCLSID IBP_ComModule::Get_CLSID_IBProviderErrors()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProviderErrors;
}//Get_CLSID_IBProviderErrors

//------------------------------------------------------------------------
REFCLSID IBP_ComModule::Get_CLSID_IBProviderDataLinkPropPage()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProviderDataLinkPropPage;
}//Get_CLSID_IBProviderDataLinkPropPage

//------------------------------------------------------------------------
REFCLSID IBP_ComModule::Get_CLSID_IBProviderDataLinkPropPage__private()
{
 return TData::Get_CLSID_IBProviderDataLinkPropPage__private();
}//Get_CLSID_IBProviderDataLinkPropPage__private

//------------------------------------------------------------------------
REFCLSID IBP_ComModule::Get_CLSID_IBProviderDataLinkAdvPropPage()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProviderDataLinkAdvPropPage;
}//Get_CLSID_IBProviderDataLinkAdvPropPage

//------------------------------------------------------------------------
REFCLSID IBP_ComModule::Get_CLSID_IBProviderDataLinkAdvPropPage__private()
{
 return TData::Get_CLSID_IBProviderDataLinkAdvPropPage__private();
}//Get_CLSID_IBProviderDataLinkAdvPropPage__private

//------------------------------------------------------------------------
#ifndef IBP_BUILD_TESTCODE

HRESULT IBP_ComModule::CurrentExceptionHandler(ole_lib::TBaseUnknown2* const pRootInterface,
                                                REFCLSID                      ComponentID,
                                                REFIID                        InterfaceID,
                                                bool const                    CreateErrInfo)
{
 try
 {
  try
  {
   throw;
  }
  catch(const std::exception& exc)
  {
   return oledb::IBP_OLEDBErrorExceptionHandler
           (pRootInterface,
            ComponentID,
            InterfaceID,
            &exc,
            CreateErrInfo);
  }
  catch(...)
  {
   return oledb::IBP_OLEDBErrorExceptionHandler
           (pRootInterface,
            ComponentID,
            InterfaceID,
            nullptr,
            CreateErrInfo);
  }//catch all
 }
 catch(...)
 {
  assert(false);

  return E_FAIL;
 }//catch
}//CurrentExceptionHandler

#endif //ndef IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////

#ifdef IBP_BUILD_TESTCODE

size_t IBP_ComModule::TestCode__GetAllocBlockCount()
{
 return THelper::TestCode__GetAllocBlockCount();
}//TestCode__GetAllocBlockCount

#endif

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
