////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__port_stream.h
//! \brief   Интерфейс ввода/вывода данных порта.
//! \author  Kovalenko Dmitry
//! \date    16.08.2016
#ifndef _remote_fb__port_stream_H_
#define _remote_fb__port_stream_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortStream

/// <summary>
///  Интерфейс ввода/вывода данных порта.
/// </summary>
class RemoteFB__PortStream:public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  Перечисление категорий потоков ввода вывода
  /// </summary>
  enum tag_stream_class
  {
   /// Транспортный поток
   stream_class__transport   =1,

   /// Поток шифрования данных
   stream_class__crypt       =2,

   /// Поток компрессора
   stream_class__compressor  =3,
  };//enum tag_stream_class

 public:
  /// <summary>
  ///  Получение идентификатора категории потока
  /// </summary>
  virtual tag_stream_class GetStreamClass()const=0;

  /// <summary>
  ///  Получение указателя на родительский поток.
  /// </summary>
  //! \return
  //!  Can be null.
  virtual RemoteFB__PortStream* GetParentStream()const=0;

  /// <summary>
  ///  Замена родительского потока.
  /// </summary>
  //! \param[in] pParentStream
  //!  Not null.
  virtual void SetParentStream(RemoteFB__PortStream* pParentStream)=0;

  /// <summary>
  ///  Получение размера буфера для записи.
  /// </summary>
  virtual size_t GetWriteBufSize()const=0;

  /// <summary>
  ///  Буферизированная запись данных в порт. THROW.
  /// </summary>
  //! \param[in] cb
  //!  Количество байт
  //! \param[in] pv
  //!  Указатель на буфер с отправляемыми данными
  virtual void Write(size_t      cb,
                     const void* pv)=0;

  /// <summary>
  ///  Сброс write-буфера
  /// </summary>
  virtual void FlushWriteBuf()=0;

  /// <summary>
  ///  Буферизированное чтение данных из порта. THROW
  /// </summary>
  //! \param[in]  cb
  //!  Размер буфера под данные. Значение должно быть больше нуля.
  //! \param[out] pv
  //!  Указатель на буфер. Not null.
  //! \return
  //!  Количество загруженных данных. Больше нуля, но не больше чем cb.
  virtual size_t Read2(size_t  cb,
                       void*   pv)=0;
};//class RemoteFB__PortStream

////////////////////////////////////////////////////////////////////////////////

typedef lib::structure::t_smart_object_ptr<RemoteFB__PortStream> RemoteFB__PortStreamPtr;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif