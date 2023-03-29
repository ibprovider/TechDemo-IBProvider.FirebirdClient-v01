////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__statement.h
//! \brief   Конструкции для представления данных дескриптора запроса.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#ifndef _remote_fb__handle_data__statement_H_
#define _remote_fb__handle_data__statement_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
//#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
//#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__flags.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/error_services/ibp_error.h"
#include <structure/t_simple_buffer.h>
#include <structure/t_cycle_buffer_manager.h>
#include <structure/t_value_with_null.h>
#include <structure/stl/t_stl_vector.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////
//the content

class RemoteFB__FetchResult;
class RemoteFB__HandleData_Statement;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__FetchResult

/// <summary>
///  Объект для обслуживание результатов операции op_fetch
/// </summary>
//! \todo
//!  Переделать класс для хранения всех буферов непосредственно в блоке объекта
class RemoteFB__FetchResult:public RemoteFB__SmartMemoryObject
{
 private:
  typedef RemoteFB__FetchResult                               self_type;

  RemoteFB__FetchResult(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>            self_ptr;

  typedef unsigned char                                       byte_type;
  typedef size_t                                              size_type;

  typedef RemoteFB__MemoryAllocator                           allocator_type;

  typedef structure::t_typed_simple_buffer
            <byte_type,
             allocator_type>                                  msg_data_buffer_type;

  /// <summary>
  ///  Перечисление состояний процесса обработки пакетов с ответами
  /// </summary>
  enum tag_state
  {
   /// Выборка незавершена
   state__active    =0,

   /// Выборка завершена. Обработаны все пакеты с ответом сервера.
   state__completed =1,

   /// Выборка завершена. Достигнут конец результирующего множества.
   state__eof       =2,

   /// Выборка завершена по ошибке.
   state__failed    =3,
  };//enum tag_state

 public:
  /// Количество рядов, запрошенное для загрузки (op_fetch).
  const size_type m_RequestedFetchCount;

  /// Количество обработанных рядов (op_fetch_response).
  size_type m_ProcessedFetchCount;

  /// Состояние процесса
  tag_state m_State;

  /// Описание ошибки выборки данных
  t_ibp_error m_FetchErr;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] RequestedFetchCount
  //!  Ожидаемое количество рядов. Должно быть больше нуля.
  //! \param[in] cbRowData
  //!  Размер данных ряда
  //! \param[in] cbRowDataAlign
  //!  Выравнивающая граница для блоков с данными ряда
  RemoteFB__FetchResult(size_type RequestedFetchCount,
                        size_type cbRowData,
                        size_type cbRowDataAlign);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__FetchResult();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  static self_ptr Create(size_type RequestedFetchCount,
                         size_type cbRowData,
                         size_type cbRowDataAlign);

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Получение доступных (загруженных) рядов в буфере
  /// </summary>
  size_type ROWS__GetCount()const;

  /// <summary>
  ///  Получение размера данных ряда в байтах
  /// </summary>
  //! \note
  //!  Размер \b блока под данные ряда может быть больше, потому что в блок
  //!  включены выравнивающие байты.
  size_type ROWS__GetDataSize()const;

  byte_type* ROWS__AllocBlock();

  const byte_type* ROWS__GetFirstBlock()const;

  void ROWS__FreeFirstBlock();

  void ROWS__FreeLastBlock();

  //----------------------------------------------------------------------
  /// <summary>
  ///  Переинициализация для выборки следуюшей партии записей
  /// </summary>
  void Reactivate();

 private:
  /// Размер данных ряда
  size_type const m_cbRowData;

  /// Размер блока под данные ряда (m_cbRowData + выравнивающее значение)
  size_type m_cbRowBlock;

 private:
  typedef structure::t_cycle_buffer_manager__num_traits<size_type>
   msg_data_buf_mng_traits_type;

  typedef structure::t_cycle_buffer_manager<msg_data_buf_mng_traits_type>
   msg_data_buf_mng_type;

 private:
  msg_data_buf_mng_type  m_RowsDataBufferManager;

  msg_data_buffer_type   m_RowsDataBuffer;
};//class RemoteFB__FetchResult

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement

/// <summary>
///  Данные запроса.
/// </summary>
class RemoteFB__HandleData_Statement:public RemoteFB__SmartMemoryObject
{
 private:
  typedef RemoteFB__HandleData_Statement                      self_type;

  RemoteFB__HandleData_Statement(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Идентификатор сервиса.
  /// </summary>
  static const GUID svcID;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>            self_ptr;

  typedef RemoteFB__SrvResourceID                             id_type;

  typedef handles::RemoteFB__HandleData_Transaction           tr_data_type;

 public:
  typedef unsigned short                                      flag_base_type;
  typedef RemoteFB__Flags<flag_base_type>                     flags_type;

  //Values for m_Flags.

  /// Дескриптор содержит подготовленный запрос
  static const flag_base_type PFLAG__PREPARED            = 0x0001;

  /// Statement relates to blob op
  //static const flag_base_type PFLAG__BLOB                = 0x0002;

  /// op_execute can be deferred
  static const flag_base_type PFLAG__DEFER_EXECUTE       = 0x0004;

  /// Закэшированы описания колонок запроса
  static const flag_base_type PFLAG__CACHE_COLS_INFO     = 0x0008;

  /// Закэшированы описания параметров запроса
  static const flag_base_type PFLAG__CACHE_PARAMS_INFO   = 0x0010;

 public:
  /// EOF was returned by fetch from this statement
  static const flag_base_type EFLAG__PAST_EOF               = 0x0001;

  /// Выполнение запроса было отложено 
  static const flag_base_type EFLAG__EXECUTION_WAS_DEFERRED = 0x0002;

 public:
  class tag_cn_list_adapter;
  class tag_tr_list_adapter;
  class tag_nclosed_stmt_list_adapter;

 public:
  typedef RemoteFB__MemoryAllocator                        allocator_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               xsqlvars_data_buffer_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               msg_blr_buffer_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               msg_data_buffer_type;

  typedef structure::t_stl_vector
            <RemoteFB__MsgDataElementDescr,
             allocator_type>                               msg_data_descrs_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               msg_nulls_buffer_type;

 private:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  RemoteFB__HandleData_Statement();

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__HandleData_Statement();

 public:
  /// Родительский объект подключения
  RemoteFB__Port* m_pParentPort;

 #ifndef NDEBUG
  /// DEBUG: Указатель на родительский список в рамках объекта подключения
  void*           m_pvOwnerCnList;
 #endif

  //двунаправленный список запросов подключения
  self_type*      m_pPrevCnStmt;
  self_type*      m_pNextCnStmt;

  /// Текущая транзакция запроса
  tr_data_type*   m_pParentTr;

  //двунаправленный список запросов транзакции
  self_type*      m_pPrevTrStmt;
  self_type*      m_pNextTrStmt;

 public: //элементы для поддержки lazy_send протокола

  /// Транзакция, которой принадлежит незакрытый курсор
  tr_data_type*   m_pClosingTr;

  //двунаправленный список незакрытых курсоров m_pClosingTr
  self_type*      m_pPrevNotClosedStmt;
  self_type*      m_pNextNotClosedStmt;

 public:
  /// Серверный идентификатор запроса
  id_type     m_ID;

  /// Флаги подготовки запроса
  flags_type  m_PFlags;

  /// Флаги выполнения запроса
  flags_type  m_EFlags;

 public:
  /// PREPARE DATA: Серверный идентификатор типа запроса
  structure::t_value_with_null<unsigned long> m_PData__StmtTypeID;

  /// PREPARE DATA: Флаг допустимости групповой загрузки записей
  structure::t_value_with_null<bool> m_PData__BatchFetch;

  /// <summary>
  ///  PREPARE DATA: Буфер с данными описаний колонок.
  /// </summary>
  /// Хранятся raw-данные начиная с ibp_isc_info_sql_describe_vars тега.
  /// В конец буфера добавляется ibp_isc_info_end или ibp_isc_info_truncated.
  xsqlvars_data_buffer_type m_PData__ColumnsData;

  /// <summary>
  ///  PREPARE DATA: Буфер с данными описаний параметров.
  /// </summary>
  /// Хранятся raw-данные начиная с ibp_isc_info_sql_describe_vars тега.
  /// В конец буфера добавляется ibp_isc_info_end или ibp_isc_info_truncated.
  xsqlvars_data_buffer_type m_PData__ParametersData;

 public:
  msg_blr_buffer_type    m_InParams__MSG_BLR;

  msg_data_buffer_type   m_InParams__MSG_DATA;

  //используется начиная с 13-го протокола.
  msg_data_descrs_type   m_InParams__MSG_DATA_DESCRS;

  msg_nulls_buffer_type  m_InParams__MSG_NULLS;

 public:
  msg_blr_buffer_type    m_OutParams__MSG_BLR;

  msg_data_descrs_type   m_OutParams__MSG_DATA_DESCRS;

  msg_data_buffer_type   m_OutParams__MSG_DATA;

  size_t                 m_OutParams__MSG_DATA_SIZE;

  size_t                 m_OutParams__MSG_DATA_ALIGN;

  //используется начиная с 13-го протокола.
  msg_nulls_buffer_type  m_OutParams__MSG_NULLS;

 public:
  /// Результаты запроса op_fetch
  RemoteFB__FetchResult::self_ptr m_spFetchResult;

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  static self_ptr Create();

  //interface ------------------------------------------------------------
  void ResetPrepareState();

  void ResetExecuteState();

  /// <summary>
  ///  Закрытие курсора, принадлежащего ParentTr.
  /// </summary>
  //! \attention
  //!  Этот метод может освободить последние ссылки на объект!
  void Dangerous__CloseCursorOfParentTr();

  /// <summary>
  ///  Закрытие курсора, принадлежащего ClosingTr.
  /// </summary>
  //! \attention
  //!  Этот метод может освободить последние ссылки на объект!
  void Dangerous__CloseCursorOfClosingTr();

  /// <summary>
  ///  Отрабатываем закрытие дескриптора.
  /// </summary>
  //! \attention
  //!  Этот метод может освободить последние ссылки на объект!
  void Dangerous__DropHandle();
};//class RemoteFB__HandleData_Statement

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

/// <summary>
///  Адаптер списка запросов подключения.
/// </summary>
class RemoteFB__HandleData_Statement::tag_cn_list_adapter
{
 private:
  typedef tag_cn_list_adapter                             self_type;

 public:
  typedef RemoteFB__HandleData_Statement                  node_type;
  typedef node_type*                                      node_ptr_type;

 public:
  tag_cn_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_tr_list_adapter

/// <summary>
///  Адаптер списка запросов транзакции.
/// </summary>
class RemoteFB__HandleData_Statement::tag_tr_list_adapter
{
 private:
  typedef tag_tr_list_adapter                             self_type;

 public:
  typedef RemoteFB__HandleData_Statement                  node_type;
  typedef node_type*                                      node_ptr_type;

 public:
  tag_tr_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter

/// <summary>
///  Адаптер списка незакрытых запросов транзакции.
/// </summary>
class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter
{
 private:
  typedef tag_nclosed_stmt_list_adapter                   self_type;

 public:
  typedef RemoteFB__HandleData_Statement                  node_type;
  typedef node_type*                                      node_ptr_type;

 public:
  tag_nclosed_stmt_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
