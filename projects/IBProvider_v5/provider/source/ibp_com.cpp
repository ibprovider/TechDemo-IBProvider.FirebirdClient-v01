////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com.cpp
//! \brief   �������� COM-������
//! \author  Kovalenko Dmitry
//! \date    28.04.2004
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_com_helper.h"

#ifndef IBP_BUILD_TESTCODE
# include "source/oledb/ibp_oledb__exception_handler.h"
# include "source/oledb/ibp_oledb__class_factory.h"
# include "source/error_services/ibp_error__com_module_is_shutdown.h"
# include "source/ibp_global_objects.h"
#endif

#include <win32lib/win32lib.h>
#include <structure/t_str_formatter.h>

#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//static data

HINSTANCE              TIBP_ComModule::sm_hInstance=NULL;
TIBP_ComModule::TData* TIBP_ComModule::sm_pData=NULL;

////////////////////////////////////////////////////////////////////////////////
//class TIBP_ComModule

bool TIBP_ComModule::Init(HINSTANCE const hInstance)
{
 bool bResult=false;

 try
 {
  for(;;)
  {
   sm_hInstance=hInstance;

   //�������� ���
   if(!THelper::InitHeaps())
    break;

   //������������� ��������� ������
   if(!THelper::InitData(hInstance))
    break;

#ifndef IBP_BUILD_TESTCODE
   //������������� ��������� ���������� ��������
   if(!IBP_GlobalObjects::Init())
    break;
#endif // !IBP_BUILD_TESTCODE

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
void TIBP_ComModule::Term()
{
#ifdef DebugMessage
 try
 {
  const string_type
   ModuleName(win32lib::GetModuleFileName(sm_hInstance)); //throw

  DebugMessage("*****************************")

  DebugMessage("TIBP_ComModule::Term "
               "["<<structure::tstr_to_str(ModuleName)<<"]");

  if(sm_pData!=NULL)
  {
   if(auto const active_component_count=sm_pData->m_active_component_count)
   {
    assert_hint(active_component_count!=0);

    assert(active_component_count>0); //[2018-12-24]

    DebugMessage("COM MODULE HAS LEAKS "
                 "["<<active_component_count<<"]"
                 " "<<structure::tstr_to_str(ModuleName));

    assert_msg(false,
               "active_component_count: "<<active_component_count);
   }//if
  }//if
 }
 catch(...)
 {;}
#endif //DebugMessage

#ifndef NDEBUG
 if(sm_pData!=NULL)
 {
  if(auto const active_component_count=sm_pData->m_active_component_count)
  {
   assert_hint(active_component_count!=0);

   assert(active_component_count>0); //[2018-12-24]

   assert_msg(false,
              "active_component_count: "<<active_component_count);
  }//if

  if(auto const server_lock_count=sm_pData->m_server_lock_count)
  {
   assert_hint(server_lock_count!=0);

   assert(server_lock_count>0); //[2018-12-24]

   assert_msg(false,
              "server_lock_count: "<<server_lock_count);
  }//if
 }//if sm_pData!=0
#endif

#ifndef IBP_BUILD_TESTCODE
 //������������ ���������� ��������
 IBP_GlobalObjects::Done();
#endif

 //����������� ����������� ������ ��������� ������
 THelper::TermData();

 //��������� ����������� ����
 THelper::TermHeaps();
}//Term

////////////////////////////////////////////////////////////////////////////////
//���������� COM-�������

HINSTANCE TIBP_ComModule::GetModuleInstance()
{
 return sm_hInstance;
}//GetModuleInstance

//------------------------------------------------------------------------
const TIBP_ComModule::string_type& TIBP_ComModule::GetModulePath()
{
 assert(sm_pData);

 return sm_pData->GetModulePath();
}//GetModulePath

//------------------------------------------------------------------------
const TIBP_ComModule::string_type& TIBP_ComModule::GetModuleName()
{
 assert(sm_pData);

 return sm_pData->GetModuleName();
}//GetModuleName

//������ ������ ������ ���������� ----------------------------------------
TIBP_ComModule::string_type TIBP_ComModule::GetModuleVersion(const char_type* const prefix)
{
 string_type result;

 if(prefix!=nullptr)
  result+=prefix;

 result+=_T(IBP_VI_PRODUCT_VER_STRING1);

 return result;
}//GetModuleVersion

//------------------------------------------------------------------------
TIBP_ComModule::string_type TIBP_ComModule::GetProviderLabel()
{
#ifndef IBP_PLATFORM_ID
# error IBP_PLATFORM_ID not defined!
#endif

#if   (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
 const char_type* flabel_tstr(_T("%1 %2 [64-bit]"));
#elif (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
 const char_type* flabel_tstr(_T("%1 %2 [32-bit]"));
#else
# error Unknown platform ID!
#endif

 structure::t_basic_str_formatter<char_type> flabel(flabel_tstr);

 return flabel<<IBP_VI_PRODUCT_NAME<<self_type::GetModuleVersion(NULL);
}//GetProviderLabel

//------------------------------------------------------------------------
#ifndef NDEBUG

bool TIBP_ComModule::DEBUG__ModuleIsActive()
{
 return self_type::GetComponentCount()!=0;
}//DEBUG__ModuleIsActive

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

bool TIBP_ComModule::DEBUG__ModuleIsShutdown()
{
 return self_type::GetComponentCount()==0;
}//DEBUG__ModuleIsShutdown

#endif // !NDEBUG

//------------------------------------------------------------------------
TIBP_ComModule::lock_count_type TIBP_ComModule::GetComponentCount()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_active_component_count;
}//GetComponentCount

//------------------------------------------------------------------------
bool TIBP_ComModule::DllCanUnloadNow()
{
 assert(sm_pData!=NULL);

 if(sm_pData->m_active_component_count!=0)
  return false;

 if(sm_pData->m_server_lock_count!=0)
  return false;

 return true;
}//DllCanUnloadNow

//------------------------------------------------------------------------
#ifndef IBP_BUILD_TESTCODE

void TIBP_ComModule::CheckActiveState()
{
 if(self_type::GetComponentCount()==0)
 {
  t_ibp_error__com_module_is_shutdown::throw_error();
 }//if

 assert(self_type::GetComponentCount()>0);
}//CheckActiveState

#endif

//------------------------------------------------------------------------
void TIBP_ComModule::IncrementComponentCount()
{
 assert(sm_pData!=nullptr);

 const thread_traits::lock_guard_type lock(sm_pData->m_active_component_count_guard);

 lib::structure::mt::interlocked::increment(&sm_pData->m_active_component_count);
}//IncrementComponentCount

//------------------------------------------------------------------------
void TIBP_ComModule::DecrementComponentCount()
{
 assert(sm_pData!=nullptr);

 const thread_traits::lock_guard_type lock(sm_pData->m_active_component_count_guard);

 assert(sm_pData->m_active_component_count>0);

 if(lib::structure::mt::interlocked::decrement(&sm_pData->m_active_component_count)!=0)
  return;

#ifndef IBP_BUILD_TESTCODE
 ///���������� ��� ���������� �������� �� ������������ ��������� ����������
 ///COM-������. ����� ����������� ��������� ������� �������.
 IBP_GlobalObjects::ReleaseLastModuleLock();
#endif

 //---
 return;
}//DecrementComponentCount

//------------------------------------------------------------------------
void TIBP_ComModule::LockServer()
{
 assert(sm_pData!=nullptr);

 lib::structure::mt::interlocked::increment(&sm_pData->m_server_lock_count);
}//LockServer

//------------------------------------------------------------------------
void TIBP_ComModule::UnlockServer()
{
 assert(sm_pData!=nullptr);
 assert(sm_pData->m_server_lock_count>0);

 lib::structure::mt::interlocked::decrement(&sm_pData->m_server_lock_count);
}//UnlockServer

////////////////////////////////////////////////////////////////////////////////
//�������� ������ COM-�������� ������

#ifndef IBP_BUILD_TESTCODE

HRESULT TIBP_ComModule::GetClassObject(REFCLSID     rclsid,
                                       REFIID       riid,
                                       void** const ppv)
{
 assert(sm_pData!=NULL);

 if(ppv==NULL)
  return E_POINTER;

 (*ppv)=NULL;

 OLE_LIB__DECLARE_HR(CLASS_E_CLASSNOTAVAILABLE);

 _OLE_TRY_
 {
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
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetClassObject

#endif //IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////
//��������� ���������� ����������� ������ � �������

const TIBP_ComModule::string_type& TIBP_ComModule::GetProgRegParams()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_prog_reg_params;
}//GetProgRegParams

//------------------------------------------------------------------------
const TIBP_ComModule::string_type& TIBP_ComModule::Get_IBProvider_FileExt()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_IBProvider_FileExt;
}//Get_IBProvider_FileExt

//------------------------------------------------------------------------
const TIBP_ComModule::string_type& TIBP_ComModule::Get_IBProvider_ProgID()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_IBProvider_ProgID;
}//Get_IBProvider_ProgID

//------------------------------------------------------------------------
const TIBP_ComModule::string_type& TIBP_ComModule::Get_IBProvider_Descr()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_IBProvider_Descr;
}//Get_IBProvider_Descr

//------------------------------------------------------------------------
#ifdef _PROCESS_DEBUG_MESSAGE_
LONG TIBP_ComModule::Get_FlushLogFilePeriod()
{
 return TData::sm_FlushLogFilePeriod;
}//Get_FlushLogFilePeriod
#endif

////////////////////////////////////////////////////////////////////////////////
//��������� ��������������� ��������� ������

REFCLSID TIBP_ComModule::Get_CLSID_IBProvider()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProvider;
}//Get_CLSID_IBProvider

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::Get_CLSID_IBProvider__private()
{
 return TData::Get_CLSID_IBProvider__private();
}//Get_CLSID_IBProvider__private

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::Get_CLSID_IBProviderErrors()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProviderErrors;
}//Get_CLSID_IBProviderErrors

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::Get_CLSID_IBProviderDataLinkPropPage()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProviderDataLinkPropPage;
}//Get_CLSID_IBProviderDataLinkPropPage

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::Get_CLSID_IBProviderDataLinkPropPage__private()
{
 return TData::Get_CLSID_IBProviderDataLinkPropPage__private();
}//Get_CLSID_IBProviderDataLinkPropPage__private

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::Get_CLSID_IBProviderDataLinkAdvPropPage()
{
 assert(sm_pData!=NULL);

 return sm_pData->m_CLSID_IBProviderDataLinkAdvPropPage;
}//Get_CLSID_IBProviderDataLinkAdvPropPage

//------------------------------------------------------------------------
REFCLSID TIBP_ComModule::Get_CLSID_IBProviderDataLinkAdvPropPage__private()
{
 return TData::Get_CLSID_IBProviderDataLinkAdvPropPage__private();
}//Get_CLSID_IBProviderDataLinkAdvPropPage__private

//------------------------------------------------------------------------
#ifndef IBP_BUILD_TESTCODE

HRESULT TIBP_ComModule::CurrentExceptionHandler(REFCLSID   ComponentID,
                                                REFIID     InterfaceID,
                                                bool const CreateErrInfo)
{
 try
 {
  try
  {
   throw;
  }
  catch(std::exception& exc)
  {
   return oledb::IBP_OLEDBErrorExceptionHandler
           (ComponentID,
            InterfaceID,
            &exc,
            CreateErrInfo);
  }
  catch(...)
  {
   return oledb::IBP_OLEDBErrorExceptionHandler
           (ComponentID,
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

size_t TIBP_ComModule::TestCode__GetAllocBlockCount()
{
 return THelper::TestCode__GetAllocBlockCount();
}//TestCode__GetAllocBlockCount

#endif

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
