////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__internal_crypt_key.h
//! \brief   Интерфейс ключа для шифрования.
//! \author  Kovalenko Dmitry
//! \date    18.09.2016
#ifndef _remote_fb__internal_crypt_key_H_
#define _remote_fb__internal_crypt_key_H_

#include "source/db_client/remote_fb/remote_fb__crypt_key_data_view.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"
#include <structure/t_const_string.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__InternalCryptKey

/// <summary>
///  Интерфейс ключа для шифрования.
/// </summary>
class RemoteFB__InternalCryptKey:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstring        tname_type;

 public:
  /// <summary>
  ///  Получение имени типа ключа
  /// </summary>
  //! \return
  //!  Not empty.
  virtual tname_type GetType()const=0;

  virtual const RemoteFB__CryptKeyDataView GetEncryptKey()const=0;

  virtual const RemoteFB__CryptKeyDataView GetDecryptKey()const=0;
};//class RemoteFB__InternalCryptKey

////////////////////////////////////////////////////////////////////////////////

typedef structure::t_smart_object_ptr<RemoteFB__InternalCryptKey> RemoteFB__InternalCryptKeyPtr;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
