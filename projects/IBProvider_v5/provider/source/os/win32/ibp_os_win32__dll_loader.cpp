////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_loader.cpp
//! \brief   ?????????? ?????????? DLL
//! \author  Kovalenko Dmitry
//! \date    29.06.2003
#include <_pch_.h>
#pragma hdrstop

#ifndef IBP_BUILD_TESTCODE
# include "source/ibp_global_objects_data__dlls.h"
#else
# include "source/os/win32/ibp_os_win32__dll_loader.h"
#endif

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
 ///???????? DLL
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
 // ????? ??? try{}catch(...){} ?????? ????. ?????, ??? ??????? ?????? ?????.
 // ???? ??? ???-?? ????? ??????, ?? ????? ?????? ???.

 ///???????? DLL
 if(m_NoUnLoad==0 && m_hDLL)
 {
  _VERIFY(::FreeLibrary(m_hDLL));
 }//if
}//~t_ibp_os_win32__dll_loader

//------------------------------------------------------------------------
t_ibp_os_win32__dll_loader::self_ptr t_ibp_os_win32__dll_loader::create
                                           (t_ibp_str_box const DLL_Name,
                                            long          const DLL_Lock_Rule)
{
#ifndef IBP_BUILD_TESTCODE
 if(DLL_Lock_Rule==ibprovider::ibp_propval_dll_lock_rule__unload)
 {
  return IBP_GlobalObjectsData__DLLs::GetDLL(DLL_Name);
 }//ibp_propval_dll_lock_rule__unload

 if(DLL_Lock_Rule==ibprovider::ibp_propval_dll_lock_rule__no_unload)
 {
  self_ptr
   spDLL(IBP_GlobalObjectsData__DLLs::GetDLL(DLL_Name));

  assert(spDLL);

  spDLL->lock_in_memory();

  assert(spDLL);

  return /*move*/ spDLL;
 }//ibp_propval_dll_lock_rule__no_unload
#endif //ndef IBP_BUILD_TESTCODE

 //DEFAULT: Force unload
 return structure::not_null_ptr(new self_type(DLL_Name));
}//create

//------------------------------------------------------------------------
FARPROC t_ibp_os_win32__dll_loader::get_proc_address(LPCSTR const point_name)const
{
 assert(point_name!=nullptr);

 if(const FARPROC pf=::GetProcAddress(this->get_dll_handle(),point_name))
  return pf;

 //????????? ? ???? ????? ? ??? ???????? ???????????? ??????????
 //??? ?? ???????, ????????? ::GetLastError ?????? ?????? ?? ?????? ??????

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
void t_ibp_os_win32__dll_loader::lock_in_memory()
{
 /// ????????????? m_NoUnLoad ?????? 1. ?????????? InterlockedExchange.

 ::InterlockedExchange(&m_NoUnLoad,1);
}//lock_in_memory

////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
