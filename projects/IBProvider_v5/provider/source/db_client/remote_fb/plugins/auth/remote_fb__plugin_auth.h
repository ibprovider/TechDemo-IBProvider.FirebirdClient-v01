////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth.h
//! \brief   Интерфейс плагина для аутентификации
//! \author  Kovalenko Dmitry
//! \date    12.07.2016
#ifndef _remote_fb__plugin_auth_H_
#define _remote_fb__plugin_auth_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"

#include <structure/t_const_string.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth

class RemoteFB__Plugin_Auth:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstring        name_type;

 public:
  /// <summary>
  ///  Строка с именем сервиса аутентификации.
  /// </summary>
  //! \return
  //!  Непустая строка.
  virtual name_type get_name()const=0;

  /// <summary>
  ///  Определение данных аутентификации в буфере с параметрами инициализации подключения.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void def_auth_params_in_cpb(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)=0;

  /// <summary>
  ///  Установка данных аутентификации.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void authenticate(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)=0;
};//class RemoteFB__Plugin_Auth

typedef structure::t_smart_object_ptr<RemoteFB__Plugin_Auth> RemoteFB__Plugin_AuthPtr;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
