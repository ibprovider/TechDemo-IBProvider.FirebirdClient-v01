////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_loader.cpp
//! \brief   Реализация загрузчика DLL
//! \author  Kovalenko Dmitry
//! \date    29.06.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/ibp_os_win32__dll_loader.h"

#include "source/error_services/ibp_error.h"

#include <win32lib/win32_error.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_loader

t_ibp_os_win32__dll_loader::t_ibp_os_win32__dll_loader(t_ibp_str_box const DLL_Name)
 :m_DLL_Name(DLL_Name.begin(),DLL_Name.end())
 ,m_hDLL(NULL)
 ,m_NoUnLoad(0)
{
 ///Загрузка DLL
 m_hDLL=::LoadLibrary(structure::tstr_to_tstr(m_DLL_Name).c_str());

 if(m_hDLL==NULL)
 {
  //Fail load library \"%1\"
  const DWORD err_code=::GetLastError();

  t_ibp_error exc(HRESULT_FROM_WIN32(err_code),
                  ibp_mce_win32__fail_load_dynamic_library_2);

  exc<<m_DLL_Name<<ibp_err_data__win32_error_msg(err_code);

  exc.raise_me();
 }//if
}//t_ibp_os_win32__dll_loader

//------------------------------------------------------------------------
t_ibp_os_win32__dll_loader::~t_ibp_os_win32__dll_loader()
{
 //[2017-10-02]
 // Здесь был try{}catch(...){} вокруг кода. Думаю, это реально глупая затея.
 // Если там что-то будет падать, то пусть падает все.

 ///Выгрузка DLL
 if(m_NoUnLoad==0 && m_hDLL)
 {
  _VERIFY(::FreeLibrary(m_hDLL));
 }//if
}//~t_ibp_os_win32__dll_loader

//------------------------------------------------------------------------
FARPROC t_ibp_os_win32__dll_loader::get_proc_address(LPCSTR const point_name)const
{
 assert(point_name!=nullptr);

 if(const FARPROC pf=::GetProcAddress(this->get_dll_handle(),point_name))
  return pf;

 //Формально в этой точке у нас возможно паралелльное исполнение
 //Это не страшно, поскольку ::GetLastError хранит данные на уровне потока

 //Fail get proc address \"%1\".\"%2\"
 const DWORD err_code=::GetLastError();

 const HRESULT hr=HRESULT_FROM_WIN32(err_code);

 assert(FAILED(hr));

 t_ibp_error exc(hr,
                 ibp_mce_win32__fail_get_api_func_address_2);

 exc<<m_DLL_Name
    <<point_name
    <<ibp_err_data__win32_error_msg(err_code);

 exc.raise_me();

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//get_proc_address

//------------------------------------------------------------------------
FARPROC t_ibp_os_win32__dll_loader::try_get_proc_address(LPCSTR const point_name)const
{
 assert(point_name!=nullptr);

 return ::GetProcAddress(this->get_dll_handle(),point_name);
}//try_get_proc_address

//------------------------------------------------------------------------
IBP_SmartInterfacePtr t_ibp_os_win32__dll_loader::get_service_obj
                             (REFGUID                 rServiceObjID,
                              pfn_service_obj_creator pfnServiceObjCreator)
{
 assert(pfnServiceObjCreator);

 const lock_guard_type __lock(m_ServiceObjs_Guard);

 const service_objects_map_type::const_iterator
  x=m_ServiceObjs.find(rServiceObjID);

 if(x!=m_ServiceObjs.cend())
 {
  assert((*x).second);

  return (*x).second.not_null_ptr();
 }//if

 assert(x==m_ServiceObjs.cend());

 IBP_SmartInterfacePtr
  spNewServiceObj
   =pfnServiceObjCreator();

 assert(spNewServiceObj);

 _VERIFY
  (m_ServiceObjs.insert(service_objects_map_type::value_type(rServiceObjID,spNewServiceObj))
    DEBUG_CODE(.second));

 assert(spNewServiceObj);

 return spNewServiceObj;
}//get_service_obj

//------------------------------------------------------------------------
void t_ibp_os_win32__dll_loader::lock_in_memory()
{
 /// Устанавливаем m_NoUnLoad равным 1. Используем InterlockedExchange.

 ::InterlockedExchange(&m_NoUnLoad,1);
}//lock_in_memory

//------------------------------------------------------------------------
bool t_ibp_os_win32__dll_loader::is_locked_in_memory()const
{
 if(m_NoUnLoad==0)
  return false;

 return true;
}//is_locked_in_memory

////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
