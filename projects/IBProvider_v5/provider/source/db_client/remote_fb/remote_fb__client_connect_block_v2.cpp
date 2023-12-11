////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__client_connect_block_v2.cpp
//! \brief    ласс дл€ управлени€ данными подключени€.
//! \author  Kovalenko Dmitry
//! \date    08.10.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ClientConnectBlock_v2::tag_expected_ptype_descr

RemoteFB__ClientConnectBlock_v2::tag_expected_ptype_descr::tag_expected_ptype_descr
                                           ()
{;}

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v2::tag_expected_ptype_descr::tag_expected_ptype_descr
    (ptype_id_type                    const _ptypeID,
     lib::structure::t_const_wstr_box const _ptypeSign)
 :ptypeID(_ptypeID)
 ,ptypeSign(_ptypeSign.begin(),_ptypeSign.end())
{;}

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v2::tag_expected_ptype_descr::tag_expected_ptype_descr
    (lib::structure::t_const_wstr_box const _ptypeSign)
 :ptypeSign(_ptypeSign.begin(),_ptypeSign.end())
{;}

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v2::tag_expected_ptype_descr::~tag_expected_ptype_descr()
{;}

//------------------------------------------------------------------------
bool RemoteFB__ClientConnectBlock_v2::tag_expected_ptype_descr::operator == (ptype_id_type const id)const
{
 return this->ptypeID==id;
}//operator ==

//------------------------------------------------------------------------
bool RemoteFB__ClientConnectBlock_v2::tag_expected_ptype_descr::operator != (ptype_id_type const id)const
{
 return !((*this)==id);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ClientConnectBlock_v2

RemoteFB__ClientConnectBlock_v2::RemoteFB__ClientConnectBlock_v2
                               (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues)
 :m_spDsPropValues(lib::structure::not_null_ptr(pDsPropValues))
 ,m_DsProp__WireCrypt(pDsPropValues->Get_Remote_WireCrypt())
 ,m_DsProp__WireCompression(pDsPropValues->Get_Remote_WireCompression())
 ,m_CPB(L"clientCPB")
 ,m_authComplete(false)
{
 assert(m_spDsPropValues);
}//RemoteFB__ClientConnectBlock_v2

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v2::~RemoteFB__ClientConnectBlock_v2()
{
}

//------------------------------------------------------------------------
void RemoteFB__ClientConnectBlock_v2::RegAuthPluginFactory
                                           (plugins::auth::RemoteFB__Plugin_Auth_Factory* const pFactory)
{
 assert(pFactory);
 assert(!pFactory->get_name().empty());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__ClientConnectBlock_v2::RegAuthPluginFactory";

 if(this->Helper__FindAuthPluginFactory(pFactory->get_name()))
 {
  //ERROR - [BUG CHECK] ѕовторна€ регистраци€ фабрики плагина аутентификации.

  RemoteFB__ErrorUtils::Throw_BugCheck__auth_service_factory_already_was_registered
   (c_bugcheck_src,
    L"#001",
    pFactory->get_name());
 }//if

 if(!Helper__CheckAuthPluginName(pFactory->get_name()))
 {
  //ERROR - некорректное им€ плагина

  RemoteFB__ErrorUtils::Throw__IncorrectAuthServiceName
   (ibp_subsystem__remote_fb,
    pFactory->get_name());
 }//if

 m_AuthPlugins.push_back(pFactory);

 m_AuthPluginNames.reset();
}//RegAuthPluginFactory

//------------------------------------------------------------------------
bool RemoteFB__ClientConnectBlock_v2::SetCurrentAuthPlugin2
                                           (structure::t_const_wstr_box const pluginName)
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__ClientConnectBlock_v2::SetCurrentAuthPlugin";

 if(m_spCurrentAuthPlugin)
 {
  if(RemoteFB__Utils::EqualPluginNames(m_spCurrentAuthPlugin->get_name(),pluginName))
   return false;
 }//if

 if(!m_knownServerKeys.empty())
 {
  // [2016-10-13]
  //  Ќа вс€кий случай проверим что у нас нет описани€ типов ключей,
  //  полученных от сервера.

  structure::wstr_formatter
   freason(L"m_knownServerKeys not empty. Current auth service: [%1]");

  if(m_spCurrentAuthPlugin)
   freason<<m_spCurrentAuthPlugin->get_name();
  else
   freason<<L"???";

  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#001",
    freason.c_str());
 }//if

 if(plugins::auth::RemoteFB__Plugin_Auth_Factory* const pF=this->Helper__FindAuthPluginFactory(pluginName))
 {
  if(m_UsedAuthPlugins.find(pF->get_name())!=m_UsedAuthPlugins.end())
  {
   //ERROR - ѕовторна€ установка плагина - это €вное зацикливание процесса авторизации

   RemoteFB__ErrorUtils::Throw_BugCheck__auth_service_already_was_used
    (c_bugcheck_src,
     L"#002",
     pluginName);
  }//if

  //----
  plugins::auth::RemoteFB__Plugin_AuthPtr spNewPlugin(pF->create_plugin()); //throw

  assert(spNewPlugin);

  //----
  if(m_spCurrentAuthPlugin)
  {
   //запоминаем им€ замещаемого плагина

   _VERIFY(m_UsedAuthPlugins.insert(m_spCurrentAuthPlugin->get_name()) DEBUG_CODE(.second)); //throw
  }//if

  m_spCurrentAuthPlugin.swap(spNewPlugin);

  assert(m_spCurrentAuthPlugin);

  m_dataForAuthPlugin.free();

  m_dataFromAuthPlugin.free();

  // [2016-09-18]
  //  ѕо идее у нас не должно быть никаких ключей шифровани€.
  //
  //  ≈сли этот ассерт сработал, то надо разбиратьс€ - как они по€вились.
  
  // [2016-10-13]
  //  SRP-аутентификаци€ €вл€етс€ многошаговой. Ќа втором шаге передаетс€
  //  пароль и формируетс€ m_cryptKeys. —ервер может сказать что аутентификаци€
  //  не прошла (пароль не подходит) и предложить попробовать другой сервис
  //  аутентификации (Legacy_Auth).
  //
  //  “аким образом, в данной точке, нам таки надо очистить m_cryptKeys

  // assert(m_cryptKeys.empty());

  m_cryptKeys.clear();

  //сброс строки со списком доступных плагинов
  m_AuthPluginNames.reset();

  return true;
 }//if - нашли фабрику устанавливаемого плагина

 //! \todo
 //!  ћожно поискать им€ в глобальном списке предопределенных плагинов и
 //!  подсказать пользователю что сервис таки есть, но он недоступен дл€
 //!  текущих настроек.
 //!
 //!  Ќо эту ситуацию нужно сначала смоделировать через тесты.

 RemoteFB__ErrorUtils::Throw__UnknownAuthServiceName
  (ibp_subsystem__remote_fb,
   pluginName);

#if(COMP_BUILD_UNUSED_CODE)
 return false;
#endif
}//SetCurrentAuthPlugin2

//------------------------------------------------------------------------
const plugins::auth::RemoteFB__Plugin_AuthPtr&
 RemoteFB__ClientConnectBlock_v2::GetCurrentAuthPlugin()const
{
 assert(m_spCurrentAuthPlugin);

 return m_spCurrentAuthPlugin;
}//GetCurrentAuthPlugin

//------------------------------------------------------------------------
const std::wstring& RemoteFB__ClientConnectBlock_v2::GetAuthPluginNames()
{
 if(m_AuthPluginNames.null())
 {
  std::wstring result;

  for(size_t i=0,_c=m_AuthPlugins.size();i!=_c;++i)
  {
   assert(m_AuthPlugins[i]);

   assert(!m_AuthPlugins[i]->get_name().empty());

   assert(Helper__CheckAuthPluginName(m_AuthPlugins[i]->get_name()));

   //игнорируем ранее задейстованные плагины
   if(m_UsedAuthPlugins.find(m_AuthPlugins[i]->get_name())!=m_UsedAuthPlugins.end())
    continue;

   if(!result.empty())
    result+=L',';

   lib::structure::append(&result,m_AuthPlugins[i]->get_name());
  }//for i

  m_AuthPluginNames=__STL_MOVE_VALUE(result);
 }//if m_AuthPluginNames.null()

 assert(!m_AuthPluginNames.null());

 return m_AuthPluginNames.value();
}//GetAuthPluginNames

//helper methods ---------------------------------------------------------
plugins::auth::RemoteFB__Plugin_Auth_Factory*
 RemoteFB__ClientConnectBlock_v2::Helper__FindAuthPluginFactory
                                           (structure::t_const_wstr_box const pluginName)const
{
 for(size_t i=0,_c=m_AuthPlugins.size();i!=_c;++i)
 {
  assert(m_AuthPlugins[i]);

  if(RemoteFB__Utils::EqualPluginNames(m_AuthPlugins[i]->get_name(),
                                       pluginName))
  {
   return m_AuthPlugins[i];
  }//if
 }//for i

 return nullptr;
}//Helper__FindAuthPluginFactory

//------------------------------------------------------------------------
bool RemoteFB__ClientConnectBlock_v2::Helper__CheckAuthPluginName
                                           (structure::t_const_wstr_box const pluginName)
{
 if(pluginName.empty())
  return false; //empty name not allowed

 for(structure::t_const_wstr_box::iterator i(pluginName.begin()),
                                          _e(pluginName.end());
     i!=_e;
     ++i)
 {
  switch(*i)
  {
   case L'\0': //nonsense...
   case L'\t':
   case L'\n':
   case L'\r':
   case L' ':
   case L',':
   case L';': //our own restriction
    return false;
  }//switch
 }//for i

 return true;
}//Helper__CheckAuthPluginName

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
