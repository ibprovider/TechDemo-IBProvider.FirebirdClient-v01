////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__process_auth_response.cpp
//! \brief   Утилиты подключения. Обработка данных ответа авторизации.
//! \author  Kovalenko Dmitry
//! \date    12.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__process_auth_response.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/ibp_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__ProcessAuthResponse

void RemoteFB__P13__ProcessAuthResponse::exec
        (RemoteFB__ClientConnectBlock_v2&                 clientConnectBlock,
         const protocol::set02::P_CSTRING_CONST_V2* const pResponse_AuthPluginName,
         const protocol::set02::P_CSTRING_CONST_V2* const pResponse_AuthPluginData)
{
 assert(pResponse_AuthPluginName);
 assert(pResponse_AuthPluginData);

 //----------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P13__ProcessAuthResponse::exec";

 //---------- читаем имя сервис аутентификации, который предлагает нам сервер.
 if(pResponse_AuthPluginName)
 {
  std::wstring serverAuthPluginName;

  if(!IBP_Utils::Utf8ToWStr__Fast(structure::make_str_box(*pResponse_AuthPluginName),
                                  &serverAuthPluginName))
  {
   //ERROR - ошибка конвертирования имени плагина из кодовой страницы UTF8

   RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_auth_service_name_from_utf8_to_wstr
    (c_bugcheck_src,
     L"#001");
  }//if

  assert(clientConnectBlock.GetCurrentAuthPlugin());

  if(!serverAuthPluginName.empty())
  {
   //Предлагают заюзать другой сервис аутентификации.

   clientConnectBlock.SetCurrentAuthPlugin2(serverAuthPluginName); //throw
  }//if

  assert(clientConnectBlock.GetCurrentAuthPlugin());
 }//if pResponse_AuthPluginName

 //----------
 if(pResponse_AuthPluginData)
 {
  CHECK_READ_TYPED_PTR(pResponse_AuthPluginData->cstr_address,
                       pResponse_AuthPluginData->cstr_length);

  assert_s(sizeof(*pResponse_AuthPluginData->cstr_address)==1);

  memcpy(clientConnectBlock.m_dataForAuthPlugin.alloc(pResponse_AuthPluginData->cstr_length),
         pResponse_AuthPluginData->cstr_address,
         pResponse_AuthPluginData->cstr_length);

  assert(clientConnectBlock.m_dataForAuthPlugin.size()==pResponse_AuthPluginData->cstr_length);
 }//if pResponse_AuthPluginData
}//Helper__ProcessAuthResponse_P13

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
