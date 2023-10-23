////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__blob.h
//! \brief   Конструкции для представления данных дескриптора блоба.
//! \author  Kovalenko Dmitry
//! \date    11.09.2015
#ifndef _remote_fb__handle_data__blob_H_
#define _remote_fb__handle_data__blob_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
#include <structure/t_simple_buffer.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////
//the content

class RemoteFB__HandleData_Blob;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob

/// <summary>
///  Данные блоба.
/// </summary>
class RemoteFB__HandleData_Blob LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__SmartMemoryObject
{
 private:
  using self_type=RemoteFB__HandleData_Blob;

  RemoteFB__HandleData_Blob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using id_type=RemoteFB__SrvResourceID;

  using tr_data_type=handles::RemoteFB__HandleData_Transaction;

  using allocator_type=RemoteFB__MemoryAllocator;

  using buffer_type=structure::t_void_simple_buffer<allocator_type>;

  enum enumBlobMode
  {
   BlobMode__Open=1,
   BlobMode__Create=2,
  };

  enum enumReadState
  {
   ReadState__None        =0, //используется как индикатор первого вызова
   ReadState__Ok          =1,
   ReadState__Segment     =2,
   ReadState__EofPending  =3,
   ReadState__Failed      =4,
  };

  enum enumWriteState
  {
   WriteState__None        =0,
   WriteState__Failed      =4,
  };

 public:
  class tag_tr_list_adapter;
  class tag_nclosed_blob_list_adapter;

 private:
  /// <summary>
  ///  Конструктор по умолчанию
  /// </summary>
  //! \param[in] BlobMode
  RemoteFB__HandleData_Blob(enumBlobMode BlobMode);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__HandleData_Blob();

 public:
  /// Режим использование дескриптора блоба. Определяется при конструировании объекта.
  const enumBlobMode m_BlobMode;

  /// Родительская транзакция блоба
  tr_data_type*   m_pParentTr;

  //двунаправленный список блобов транзакции
  self_type*      m_pPrevTrBlob;
  self_type*      m_pNextTrBlob;

 public:
  /// DEBUG: Указатель на владельца списка (контейнер) незакрытых блобов подключения.
  RemoteFB__ConnectorData* m_pOwnerCnNClosedBlobList;

  //двунаправленный список незакрытых блобов подключения
  self_type*      m_pPrevCnNClosedBlob;
  self_type*      m_pNextCnNClosedBlob;

 public:
  /// Серверный идентификатор блоба
  id_type         m_ID;

  /// Буфер для чтения/записи данных блоба
  buffer_type     m_Buffer;

 public:
  /// Чтение данных. Количество актуальных данных в m_Buffer.
  buffer_type::size_type m_ReadMode__BufferActualSize;

  /// Чтение данных. Текущая позиция в буфере с данными блоба.
  buffer_type::size_type m_ReadMode__BufferPos;

  /// Чтение данных. Количество данных до конца блока (сегмента) данных
  buffer_type::size_type m_ReadMode__FragmentTailSize;

  /// Чтение данных. Состояние процесса загрузки данных.
  enumReadState m_ReadMode__State;

 public:
  /// Запись данных. Текущая позиция в буфере с данными блоба.
  buffer_type::size_type m_WriteMode__BufferPos;

  /// Запись данных. Состояние процесса записи данных.
  enumWriteState m_WriteMode__State;

 public:
  /// Текущая ошибка операции с блобоб.
  std::exception_ptr m_spExc;

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] BlobMode
  static self_ptr Create(enumBlobMode BlobMode);

  /// <summary>
  ///  Отрабатываем закрытие дескриптора.
  /// </summary>
  //! \attention
  //!  Этот метод может освободить последние ссылки на объект!
  void Dangerous__DropHandle();
};//class RemoteFB__HandleData_Blob

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob::tag_tr_list_adapter

/// <summary>
///  Адаптер списка блобов транзакции.
/// </summary>
class RemoteFB__HandleData_Blob::tag_tr_list_adapter LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_tr_list_adapter;

 public:
  using node_type    =RemoteFB__HandleData_Blob;
  using node_ptr_type=node_type*;

 public:
  tag_tr_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Blob::tag_tr_list_adapter

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter

/// <summary>
///  Адаптер списка незакрытых блобов подключения.
/// </summary>
class RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_nclosed_blob_list_adapter;

 public:
  using node_type    =RemoteFB__HandleData_Blob;
  using node_ptr_type=node_type*;

 public:
  tag_nclosed_blob_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif