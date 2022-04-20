////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__transaction.h
//! \brief   Конструкции для представления данных дескриптора транзакции.
//! \author  Kovalenko Dmitry
//! \date    16.02.2015
#ifndef _remote_fb__handle_data__transaction_H_
#define _remote_fb__handle_data__transaction_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle_data__blob.h"
//#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
//#include "source/db_client/remote_fb/remote_fb__memory.h"
//#include "source/db_client/remote_fb/remote_fb__forward.h"
#include <structure/t_list_external.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////
//contains

class RemoteFB__HandleData_Transaction;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Transaction

/// <summary>
///  Данные транзакции.
/// </summary>
class RemoteFB__HandleData_Transaction:public RemoteFB__SmartMemoryObject
{
 private:
  typedef RemoteFB__HandleData_Transaction                    self_type;

  RemoteFB__HandleData_Transaction(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>            self_ptr;

  typedef RemoteFB__SrvResourceID                             id_type;

  typedef RemoteFB__HandleData_Statement                      stmt_data_type;

  typedef RemoteFB__HandleData_Blob                           blob_data_type;

  class tag_list_adapter;

 private:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  RemoteFB__HandleData_Transaction();

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__HandleData_Transaction();

 public:
  /// Родительский объект подключения
  RemoteFB__Port* m_pParentPort;

 public: //двунаправленный список транзакций подключения
  self_type*  m_pPrevTr;
  self_type*  m_pNextTr;

 public:
  /// Серверный идентификатор транзакции
  id_type     m_ID;

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  static self_ptr Create();

 public:
  /// <summary>
  ///  Добавление в m_Statements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void StmtList__Add(stmt_data_type* phStmtData);

  /// <summary>
  ///  Удаление из m_Statements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void StmtList__Remove(stmt_data_type* phStmtData);

 public:
  /// <summary>
  ///  Добавление в m_NotClosedStatements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void NotClosedStmtList__Add(stmt_data_type* phStmtData);

  /// <summary>
  ///  Удаление из m_NotClosedStatements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void NotClosedStmtList__Remove(stmt_data_type* phStmtData);

 public:
  /// <summary>
  ///  Добавление в m_Blobs. No Throw.
  /// </summary>
  //! \param[in] phBlobData
  //!  Not null.
  void BlobList__Add(blob_data_type* phBlobData);

  /// <summary>
  ///  Удаление из m_Blobs. No Throw.
  /// </summary>
  //! \param[in] phBlobData
  //!  Not null.
  void BlobList__Remove(blob_data_type* phBlobData);

 public:
  /// <summary>
  ///  Очистка и отключение связанных ресурсов транзакции
  /// </summary>
  void CleanupTrResources();

 private:
  /// <summary>
  ///  Освобождение всех ресурсов, привязанных к транзакции
  /// </summary>
  void Helper__ReleaseAllResources();

 private: //typedefs -----------------------------------------------------
  typedef stmt_data_type::tag_tr_list_adapter             stmt_list_traits;

  typedef structure::t_list_external
            <stmt_list_traits>                            stmt_list_type;

  typedef stmt_data_type::tag_nclosed_stmt_list_adapter   nclosed_stmt_list_traits;

  typedef structure::t_list_external
            <nclosed_stmt_list_traits>                    nclosed_stmt_list_type;

  typedef blob_data_type::tag_tr_list_adapter             blob_list_traits;

  typedef structure::t_list_external
            <blob_list_traits>                            blob_list_type;

#ifdef IBP_BUILD_TESTCODE
 public:
#else
 private:
#endif
  /// <summary>
  ///  Список запросов, привязанных к транзакции.
  /// </summary>
  //! \note
  //!  Элементы списка блокируются в памяти.
  stmt_list_type m_Statements;

  /// <summary>
  ///  Список незакрытых запросов, привязанных к транзакции.
  /// </summary>
  //! \note
  //!  Элементы списка блокируются в памяти.
  nclosed_stmt_list_type m_NotClosedStatements;

  /// <summary>
  ///  Список блобов, привязанных к транзакции.
  /// </summary>
  //! \note
  //!  Элементы списка блокируются в памяти.
  //! \note
  //!  В списке могут находится объекты, фактическое закрытие которых было отложено.
  blob_list_type m_Blobs;
};//class RemoteFB__HandleData_Transaction

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Transaction::tag_list_adapter

/// <summary>
///  Адаптер списка транзакций подключения.
/// </summary>
class RemoteFB__HandleData_Transaction::tag_list_adapter
{
 private:
  typedef tag_list_adapter                                self_type;

 public:
  typedef RemoteFB__HandleData_Transaction                node_type;
  typedef node_type*                                      node_ptr_type;

 public:
  tag_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Transaction::tag_list_adapter

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
