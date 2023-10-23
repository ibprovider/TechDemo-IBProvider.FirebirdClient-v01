////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector_data.h
//! \brief   Класс контейнера данных подключения к FireBird.
//! \author  Kovalenko Dmitry
//! \date    25.02.2015.
#ifndef _remote_fb__connector_data_H_
#define _remote_fb__connector_data_H_

#include "source/db_client/remote_fb/api/remote_fb__api__db__get_info.h"
#include "source/db_client/remote_fb/api/remote_fb__api__db__detach.h"
#include "source/db_client/remote_fb/api/remote_fb__api__db__drop.h"
#include "source/db_client/remote_fb/api/remote_fb__api__trans__start.h"
#include "source/db_client/remote_fb/api/remote_fb__api__trans__prepare.h"
#include "source/db_client/remote_fb/api/remote_fb__api__trans__rollback.h"
#include "source/db_client/remote_fb/api/remote_fb__api__trans__rollback_retaining.h"
#include "source/db_client/remote_fb/api/remote_fb__api__trans__commit.h"
#include "source/db_client/remote_fb/api/remote_fb__api__trans__commit_retaining.h"
#include "source/db_client/remote_fb/api/remote_fb__api__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/remote_fb__api__dsql__execute_immediate_m.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__allocate.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__drop.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__prepare.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_info.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_columns.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_parameters.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__execute.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__execute_m.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__fetch.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__fetch_m.h"
#include "source/db_client/remote_fb/api/remote_fb__api__stmt__close.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__open.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__create.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__close.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__cancel.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__get_info.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__read.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__write.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__flush.h"
#include "source/db_client/remote_fb/api/remote_fb__api__array__put_slice.h"
#include "source/db_client/remote_fb/api/remote_fb__api__array__get_slice.h"

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_client/remote_fb/remote_fb__api_entry.h"

#include "source/db_obj/db_charset_manager_v2.h"

#include <structure/t_list_external.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ConnectorData

/// <summary>
///  Класс контейнера данных подключения к FireBird.
/// </summary>
class RemoteFB__ConnectorData LCPI_CPP_CFG__CLASS__FINAL
 :public db_obj::t_db_service_provider
 ,public RemoteFB__SmartObjectBase2
{
 private:
  using self_type=RemoteFB__ConnectorData;

  RemoteFB__ConnectorData(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using tr_data_type=handles::RemoteFB__HandleData_Transaction;

  using stmt_data_type=handles::RemoteFB__HandleData_Statement;

  using blob_data_type=handles::RemoteFB__HandleData_Blob;

 public:
  ///Имя сервера базы данных
  std::wstring m_DBMS_Name;

 public:
#define DEF_API_ENTRY(ApiSign)              \
  RemoteFB__ApiEntry<api::RemoteFB__API__##ApiSign> m_API__##ApiSign

  DEF_API_ENTRY(DetachDatabase);
  DEF_API_ENTRY(DropDatabase);
  DEF_API_ENTRY(GetDatabaseInfo);
  DEF_API_ENTRY(StartTransaction);
  DEF_API_ENTRY(PrepareTransaction);
  DEF_API_ENTRY(Commit);
  DEF_API_ENTRY(CommitRetaining);
  DEF_API_ENTRY(Rollback);
  DEF_API_ENTRY(RollbackRetaining);
  DEF_API_ENTRY(ExecuteImmediate);
  DEF_API_ENTRY(ExecuteImmediate_M);
  DEF_API_ENTRY(AllocateStatement);
  DEF_API_ENTRY(DropStatement);
  DEF_API_ENTRY(PrepareStatement);
  DEF_API_ENTRY(GetStatementInfo);
  DEF_API_ENTRY(GetColumns);
  DEF_API_ENTRY(GetParameters);
  DEF_API_ENTRY(ExecuteStatement);
  DEF_API_ENTRY(ExecuteStatement_M);
  DEF_API_ENTRY(FetchStatement);
  DEF_API_ENTRY(FetchStatement_M);
  DEF_API_ENTRY(CloseStatement);
  DEF_API_ENTRY(OpenBlob);
  DEF_API_ENTRY(CreateBlob);
  DEF_API_ENTRY(CloseBlob);
  DEF_API_ENTRY(CancelBlob);
  DEF_API_ENTRY(GetBlobInfo);
  DEF_API_ENTRY(ReadBlob);
  DEF_API_ENTRY(WriteBlob);
  DEF_API_ENTRY(FlushBlob);
  DEF_API_ENTRY(PutArraySlice);
  DEF_API_ENTRY(GetArraySlice);
#undef DEF_API_ENTRY

 public:
  /// <summary>
  ///  Предварительно созданный объект транзакции.
  /// </summary>
  ///  Используется при старте транзакции через API и SQL.
  tr_data_type::self_ptr m_spPreCreatedTr;

 private:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  RemoteFB__ConnectorData(RemoteFB__Port* pPort);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__ConnectorData();

 public:
  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  static self_ptr Create(RemoteFB__Port* pPort);

  //smart interface management -------------------------------------------

  SLIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS__FINAL

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Регистрация вспомогательного сервиса.
  /// </summary>
  //! \param[in] svcID
  //! \param[in] pSvc
  //!  Not null.
  void RegService(REFGUID                   svcID,
                  RemoteFB__SmartInterface* pSvc);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Доступ к объекту порта
  /// </summary>
  //! \return
  //!  Not NULL.
  RemoteFB__Port* GetPort()const;

  //----------------------------------------------------------------------
  /// <summary>
  ///  Добавление в m_Transactions. No Throw.
  /// </summary>
  //! \param[in] phTrData
  //!  Not null.
  void TrList__Add(tr_data_type* phTrData);

  /// <summary>
  ///  Удаление из m_Transactions. No Throw.
  /// </summary>
  //! \param[in] phTrData
  //!  Not null.
  void TrList__Remove(tr_data_type* phTrData);

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

  //----------------------------------------------------------------------
  /// <summary>
  ///  Добавление в m_DeletedStatements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void DeletedStmtList__Add(stmt_data_type* phStmtData);

  /// <summary>
  ///  Удаление из m_DeletedStatements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void DeletedStmtList__Remove(stmt_data_type* phStmtData);

  /// <summary>
  ///  Получение указателя на начало списка m_DeletedStatements
  /// </summary>
  //! \return
  //!  null, если список пустой
  stmt_data_type* DeletedStmtList__GetHead()const;

  /// <summary>
  ///  Получение числа элементов в списке m_DeletedStatements
  /// </summary>
  size_t DeletedStmtList__GetCount()const;

  //----------------------------------------------------------------------
  /// <summary>
  ///  Добавление в m_DeletedBlobs. No Throw.
  /// </summary>
  //! \param[in] phBlobData
  //!  Not null.
  void DeletedBlobList__Add(blob_data_type* phBlobData);

  /// <summary>
  ///  Удаление из m_DeletedBlobs. No Throw.
  /// </summary>
  //! \param[in] phBlobData
  //!  Not null.
  void DeletedBlobList__Remove(blob_data_type* phBlobData);

  /// <summary>
  ///  Получение указателя на начало списка m_DeletedBlobs
  /// </summary>
  //! \return
  //!  null, если список пустой
  blob_data_type* DeletedBlobList__GetHead()const;

  /// <summary>
  ///  Получение числа элементов в списке m_DeletedBlobs
  /// </summary>
  size_t DeletedBlobList__GetCount()const;

  //----------------------------------------------------------------------
  void BugCheck__CheckTr(tr_data_type*   phTrData,
                         const wchar_t*  bugcheck_src,
                         const wchar_t*  bugcheck_point)const;

  void BugCheck__CheckStmt(stmt_data_type* phStmtData,
                           const wchar_t*  bugcheck_src,
                           const wchar_t*  bugcheck_point)const;

  void BugCheck__CheckBlob(blob_data_type* phBlobData,
                           const wchar_t*  bugcheck_src,
                           const wchar_t*  bugcheck_point1,
                           const wchar_t*  bugcheck_point2)const;

  //t_db_service_provider interface --------------------------------------
  /// <summary>
  /// Запрос сервисного объекта
  /// </summary>
  //! \param[in] rguidService
  //!  Идентификатор сервиса
  //! \return
  //!  Возвращает указатель на сервисный объект. Если запрашиваемый
  //!  сервис не поддерживается, то возвращается NULL
  virtual db_obj::t_db_object_ptr query_service(REFGUID rguidService)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 public:
  /// <summary>
  ///  Освобождение всех ресурсов подключения.
  /// </summary>
  void ReleaseAllResources();

 private:
  using tr_handle_list_traits
   =tr_data_type::tag_list_adapter;

  using tr_handle_list_type
   =structure::t_list_external<tr_handle_list_traits>;

 private:
  using stmt_handle_list_traits
   =stmt_data_type::tag_cn_list_adapter;

  using stmt_handle_list_type
   =structure::t_list_external<stmt_handle_list_traits>;

 private:
  using nclosed_blob_list_traits
   =blob_data_type::tag_nclosed_blob_list_adapter;

  using nclosed_blob_list_type
   =structure::t_list_external<nclosed_blob_list_traits>;

 private:
  /// Порт подключения
  const RemoteFB__PortPtr m_spPort;

  /// Список транзакций подключения
  tr_handle_list_type m_Transactions;

  /// Список активных запросов подключения
  stmt_handle_list_type m_Statements;

  /// <summary>
  ///  Список удаленных запросов подключения
  /// </summary>
  //! \note
  //!  Здесь могут находится запросы с открытыми курсорами.
  stmt_handle_list_type m_DeletedStatements;

  /// <summary>
  ///  Список блобов, ожидающих завершения (close, cancel)
  /// <summary>
  nclosed_blob_list_type m_DeletedBlobs;

 private:
  using services_type
   =structure::t_stl_map
     <GUID,
      RemoteFB__SmartObjectPtr,
      ole_lib::TGuidLess,
      RemoteFB__MemoryAllocator>;

  ///Вспомогательные сервисы для работы с подключением
  services_type m_Services;
};//class RemoteFB__ConnectorData

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
