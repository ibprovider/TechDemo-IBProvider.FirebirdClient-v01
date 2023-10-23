////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__crypt_key_data_view.h
//! \brief   Класс для представления данных ключа шифрования.
//! \author  Kovalenko Dmitry
//! \date    18.09.2019
#ifndef _remote_fb__crypt_key_data_view_H_
#define _remote_fb__crypt_key_data_view_H_

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__CryptKeyDataView

/// <summary>
///  Класс для представления данных ключа шифрования.
/// </summary>
class RemoteFB__CryptKeyDataView LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  size_t      size;
  const void* ptr;

 public:
  RemoteFB__CryptKeyDataView(size_t      const _size,
                             const void* const _ptr)
   :size(_size)
   ,ptr (_ptr)
  {;}
};//class RemoteFB__CryptKeyDataView

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
