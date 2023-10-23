////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_version_info.cpp
//! \brief   Класс для получения информации о версии DLL
//! \author  Kovalenko Dmitry
//! \date    11.09.2007
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/ibp_os_win32__dll_version_info.h"
#include <win32lib/win32_resource.h>
#include <win32lib/win32_resource_versioninfo.h>

#include <structure/utilities/string/trim.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_os_win32__dll_version_info::tag_loader

struct t_ibp_os_win32__dll_version_info::tag_loader
{
 public:
  typedef t_ibp_os_win32__dll_version_info  data_type;

 public:
  static void load(HINSTANCE hInstance,data_type* pData);

 private:
  typedef win32lib::t_ver_info_element ver_info_element_type;

  static std::wstring build_ver_str(DWORD MS,DWORD LS);

  static const VS_FIXEDFILEINFO* get_fixed_info(const ver_info_element_type* pVerInfo);

  static std::wstring get_lang_and_cp_id(const ver_info_element_type* pVerInfo);

  static std::wstring get_string(const ver_info_element_type* pVerInfo);
};//struct t_ibp_os_win32__dll_version_info::tag_loader

////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_os_win32__dll_version_info::tag_loader

void t_ibp_os_win32__dll_version_info::tag_loader::load(HINSTANCE  const hInstance,
                                                        data_type* const pData)
{
 assert(pData);

 using namespace win32lib;

 t_ver_info_element_ptr spVerInfo;

 {
  TResourceLoader ResLoader(hInstance);

  DWORD         cbResource=0;
  HGLOBAL const hResource=ResLoader.LoadResourceLangEx(RT_VERSION,1,&cbResource);

  if(!hResource)
   throw std::runtime_error("#error. client library without VERSIONINFO resource.");

  const void* const pvResource=::LockResource(hResource);

  if(!pvResource)
   throw std::runtime_error("#error. can't lock VERSIONINFO resource of client library.");

  CHECK_READ_PTR(pvResource,cbResource);

  //распаковка ресурса
  spVerInfo=load_ver_info_element(pvResource,cbResource);

  assert(spVerInfo);
 }//local

 //-----------------------------------------------------------------------
 assert(spVerInfo);

 {
  //определение версий файла и продукта
  const VS_FIXEDFILEINFO* const pFixedInfo=get_fixed_info(spVerInfo); //throw

  assert(pFixedInfo);

  build_ver_str(pFixedInfo->dwFileVersionMS,
                pFixedInfo->dwFileVersionLS)
   .swap(pData->m_file_version);

  build_ver_str(pFixedInfo->dwProductVersionMS,
                pFixedInfo->dwProductVersionLS)
   .swap(pData->m_prod_version);
 }//local

 {
  //определяем идентификатор языка и кодовой страницы
  const std::wstring lang_and_cp_id(get_lang_and_cp_id(spVerInfo));//throw

  structure::wstr_formatter query_path(L"\\StringFileInfo\\%1\\%%1");

  query_path<<lang_and_cp_id<<structure::self_init;

  using structure::flush;
  using structure::c_str;

  //определяем описание модуля
  get_string(spVerInfo->query(query_path<<flush<<L"ProductName"<<c_str,false))
   .swap(pData->m_prod_name);

  get_string(spVerInfo->query(query_path<<flush<<L"FileDescription"<<c_str,false))
   .swap(pData->m_file_descr);

  //--------
  get_string(spVerInfo->query(query_path<<flush<<L"FileVersion"<<c_str,false))
   .swap(pData->m_file_version_str);

  get_string(spVerInfo->query(query_path<<flush<<L"ProductVersion"<<c_str,false))
   .swap(pData->m_prod_version_str);
 }//local
}//load

//------------------------------------------------------------------------
std::wstring t_ibp_os_win32__dll_version_info::tag_loader::build_ver_str
                                           (DWORD const MS,
                                            DWORD const LS)
{
 structure::wstr_formatter fver(L"%1.%2.%3.%4");

 fver<<HIWORD(MS)
     <<LOWORD(MS)
     <<HIWORD(LS)
     <<LOWORD(LS);

 return fver.str();
}//build_ver_str

//------------------------------------------------------------------------
const VS_FIXEDFILEINFO*
 t_ibp_os_win32__dll_version_info::tag_loader::get_fixed_info
                                           (const ver_info_element_type* const pVerInfo)
{
 assert(pVerInfo);

 typedef win32lib::t_ver_info_element__VS_VERSION_INFO root_element_type;

 const root_element_type* const
  pRootVerInfo
   =dynamic_cast<const root_element_type*>(pVerInfo);

 if(!pRootVerInfo)
  throw std::runtime_error("#error. Can't find VS_FIXEDFILEINFO of client library.");

 return pRootVerInfo->fixed_info(true);
}//get_fixed_info

//------------------------------------------------------------------------
std::wstring t_ibp_os_win32__dll_version_info::tag_loader::get_lang_and_cp_id
                                           (const ver_info_element_type* const pVerInfo)
{
 assert(pVerInfo);

 typedef win32lib::t_ver_info_element__Var var_element_type;

 const lib::structure::t_smart_object_ptr<const var_element_type>
  spVar
   =dynamic_cast<const var_element_type*>(pVerInfo->query(L"\\VarFileInfo\\Translation",true).ptr());

 if(!spVar || spVar->id_count()==0)
  throw std::runtime_error("#error. can't detect translation of client library version info");

 return spVar->id_as_str(0);
}//get_lang_and_cp_id

//------------------------------------------------------------------------
std::wstring t_ibp_os_win32__dll_version_info::tag_loader::get_string
                                           (const ver_info_element_type* const pVerInfo)
{
 if(!pVerInfo)
  return std::wstring();

 typedef win32lib::t_ver_info_element__String str_element_type;

 const str_element_type*
  const pStr=dynamic_cast<const str_element_type*>(pVerInfo);

 if(!pStr)
  return std::wstring();

 return structure::trim(pStr->value());
}//get_string

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_version_info

t_ibp_os_win32__dll_version_info::t_ibp_os_win32__dll_version_info()
{;}

//------------------------------------------------------------------------
t_ibp_os_win32__dll_version_info::~t_ibp_os_win32__dll_version_info()
{;}

//------------------------------------------------------------------------
void t_ibp_os_win32__dll_version_info::swap(self_type& x)
{
 m_file_version.swap(x.m_file_version);
 m_prod_version.swap(x.m_prod_version);

 m_prod_name   .swap(x.m_prod_name);
 m_file_descr  .swap(x.m_file_descr);

 m_file_version_str  .swap(x.m_file_version_str);
 m_prod_version_str  .swap(x.m_prod_version_str);
}//swap

//------------------------------------------------------------------------
bool t_ibp_os_win32__dll_version_info::load(HINSTANCE hDLL)
{
 self_type tmp;

 try
 {
  tag_loader::load(hDLL,&tmp);
 }
 catch(...)
 {
  return false;
 }

 this->swap(tmp);

 return true;
}//load

//------------------------------------------------------------------------
const std::wstring& t_ibp_os_win32__dll_version_info::prod_descr()const
{
 if(!m_prod_name.empty())
  return m_prod_name;

 return m_file_descr;
}//prod_descr

////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
