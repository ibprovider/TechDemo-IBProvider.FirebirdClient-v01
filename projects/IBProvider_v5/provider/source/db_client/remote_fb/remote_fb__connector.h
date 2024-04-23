////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector.h
//! \brief   Класс управления подключением к FireBird.
//! \author  Kovalenko Dmitry
//! \date    28.10.2014.
#ifndef _remote_fb__connector_H_
#define _remote_fb__connector_H_

#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_obj/isc_base/isc_base.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__forwards.h>

#include <lcpi/lib/structure/t_list_external.h>
#include <lcpi/lib/structure/mt/t_guard.h>
#include <lcpi/lib/structure/mt/t_lock_guard.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

class RemoteFB__Connector LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__SmartMemoryObject
{
 private:
  using self_type=RemoteFB__Connector;

  RemoteFB__Connector(self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using wstr_box_type=lib::structure::t_const_wstr_box;

  using str_box_type=lib::structure::t_const_str_box;

  using cns_type=isc_base::t_isc_connection_settings;

  using tr_handle_type=handles::RemoteFB__TrHandle;

  using stmt_handle_type=handles::RemoteFB__StmtHandle;

  using blob_handle_type=handles::RemoteFB__BlobHandle;

 private:
  explicit RemoteFB__Connector(RemoteFB__Port* pPort);

  virtual ~RemoteFB__Connector();

 public:
  /// <summary>
  ///  Поключение к базе данных.
  /// </summary>
  //! \param[in]  pDsPropValues
  //!  Not null.
  //! \param[out] cns
  static self_ptr ConnectToDatabase
                   (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                    cns_type&                                            cns);

  /// <summary>
  ///  Создание базы данных и подключение к ней.
  /// </summary>
  //! \param[in]  pDsPropValues
  //!  Not null.
  //! \param[out] cns
  static self_ptr CreateDatabase
                   (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                    cns_type&                                            cns);

  //----------------------------------------------------------------------
 #ifdef IBP_BUILD_TESTCODE

  /// <summary>
  ///  TEST_CODE: Получение указателя на объект с данными подключения.
  /// </summary>
  RemoteFB__ConnectorData* GetData()const;

  /// <summary>
  ///  TEST_CODE: Получение указателя на порт подключения.
  /// </summary>
  RemoteFB__Port* GetPort()const;
 #endif

  //----------------------------------------------------------------------

  /// <summary>
  ///  Тестирование недействительного состояния порта.
  /// </summary>
  bool PortHasInvalidState()const;

  //----------------------------------------------------------------------
  /// <summary>
  ///  Получение сведений о сервере и базе данных.
  /// </summary>
  //! \param[in]  Incornation
  //!  Передавать нулевое значение.
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  void GetDatabaseInfo(protocol::P_USHORT       Incornation,
                       protocol::P_USHORT       cItems,
                       const protocol::P_UCHAR* pItems,
                       RemoteFB__InfoBuffer&    ResultBuffer);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Отключение от базы данных.
  /// </summary>
  void DetachDatabase();

  //----------------------------------------------------------------------
  /// <summary>
  ///  Удаление базы данных.
  /// </summary>
  void DropDatabase();

  //----------------------------------------------------------------------
  /// <summary>
  ///  Создание транзакции.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //!  На выходе параметру присвоится дескриптор созданной транзакции.
  //! \param[in] tpb_length
  //! \param[in] tpb
  void StartTransaction(tr_handle_type*      pTrHandle,
                        size_t               tpb_length,
                        const unsigned char* tpb);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Подготовка транзакции.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. На входе должен указывать на действительный дескриптор собственной транзакции.
  //! \param[in] data_length
  //! \param[in] data
  void PrepareTransaction(tr_handle_type* pTrHandle,
                          size_t          data_length,
                          const void*     data);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Откат транзакции.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. На входе должен указывать на действительный дескриптор собственной транзакции.
  //!
  //! В случае успешного отката транзакции, (*pTrHandle) будет обнулен.
  void Rollback(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Откат транзакции с сохранением контекста.
  /// </summary>
  //! \param[in] pTrHandle
  //!  Not null. На входе должен указывать на действительный дескриптор собственной транзакции.
  void RollbackRetaining(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Коммит транзакции.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. На входе должен указывать на действительный дескриптор собственной транзакции.
  //!
  //! В случае успешного коммита транзакции, (*pTrHandle) будет обнулен.
  void Commit(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Коммит транзакции с сохранением контекста.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. На входе должен указывать на действительный дескриптор собственной транзакции.
  void CommitRetaining(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Немедленное выполнение запроса.
  /// </summary>
  //! \param[in]     OpCtx
  //!  Контекст операции.
  //! \param[in,out] pTrHandle
  //!  Дескриптор транзакции. Not null.
  //! \param[in]     SQL_dialect
  //! \param[in]     SQL_str
  //! \param[in]     pInXSQLDA
  //! \param[in,out] pOutXSQLDA
  void ExecuteImmediate(db_obj::t_db_operation_context& OpCtx,
                        tr_handle_type*                 pTrHandle,
                        protocol::P_USHORT              SQL_dialect,
                        str_box_type                    SQL_str,
                        const isc_api::XSQLDA_V1*       pInXSQLDA,
                        const isc_api::XSQLDA_V1*       pOutXSQLDA);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Immediate executing a statement.
  /// </summary>
  //! \param[in]     OpCtx
  //!  The context of an operation.
  //! \param[in,out] pTrHandle
  //!  The pointer to the handle of a transaction. Not null.
  //! \param[in]     SQL_dialect
  //! \param[in]     SQL_str
  //! \param[in]     pInMsg
  //!  IN-parameters of a statement. Can be null.
  //! \param[in,out] pOutMsg
  //!  OUT-parameters of a statement. Can be null.
  void ExecuteImmediate_M(db_obj::t_db_operation_context& OpCtx,
                          tr_handle_type*                 pTrHandle,
                          protocol::P_USHORT              SQL_dialect,
                          str_box_type                    SQL_str,
                          const RemoteFB__InMsg_v1*       pInMsg,
                          const RemoteFB__OutMsg_v1*      pOutMsg);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Создание дескриптора для управления запросом.
  /// </summary>
  //! \param[in,out] pStmtHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //!  На выходе параметру присвоится дескриптор запроса.
  void StmtAllocate(stmt_handle_type* pStmtHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Освобождение дескриптора для управления запросом.
  /// </summary>
  //! \param[in,out] pStmtHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //!  На выходе параметру присвоится нулевое значение.
  void StmtDrop(stmt_handle_type* pStmtHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Подготовка запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in] pTrHandle
  //! \param[in] pStmtHandle
  //! \param[in] SQL_dialect
  //! \param[in] SQL_str
  //! \param[out] pStmtTypeID
  //!  Not null.
  void StmtPrepare(db_obj::t_db_operation_context& OpCtx,
                   tr_handle_type*                 pTrHandle,
                   stmt_handle_type*               pStmtHandle,
                   protocol::P_USHORT              SQL_dialect,
                   str_box_type                    SQL_str,
                   unsigned long*                  pStmtTypeID);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Получение информационных данных запроса.
  /// </summary>
  //! \param[in]     OpCtx
  //!  Контекст операции.
  //! \param[in]     pStmtHandle
  //!  Действительный дескриптор запроса. Not null.
  //! \param[in]     Incornation
  //! \param[in]     cItems
  //! \param[in]     pItems
  //! \param[in,out] ResultBuffer
  void GetStatementInfo(db_obj::t_db_operation_context& OpCtx,
                        stmt_handle_type*               pStmtHandle,
                        unsigned short                  Incornation,
                        unsigned short                  cItems,
                        const unsigned char*            pItems,
                        RemoteFB__InfoBuffer&           ResultBuffer);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Получение описаний колонок запроса.
  /// </summary>
  //! \param[in]     OpCtx
  //!  Контекст операции.
  //! \param[in]     pStmtHandle
  //!  Действительный дескриптор запроса. Not null.
  //! \param[in,out] xsqlda
  //!  Описания колонок запроса. Not null.
  void GetColumns(db_obj::t_db_operation_context& OpCtx,
                  stmt_handle_type*               pStmtHandle,
                  isc_api::XSQLDA_V1*             xsqlda);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Получение описаний параметров запроса.
  /// </summary>
  //! \param[in]     OpCtx
  //!  Контекст операции.
  //! \param[in]     pStmtHandle
  //!  Действительный дескриптор запроса. Not null.
  //! \param[in,out] xsqlda
  //!  Описания параметров запроса. Not null.
  void GetParameters(db_obj::t_db_operation_context& OpCtx,
                     stmt_handle_type*               pStmtHandle,
                     isc_api::XSQLDA_V1*             xsqlda);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Выполнение запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in,out] pTrHandle
  //!  Дескриптор транзакции. Not null.
  //! \param[in] pStmt
  //!  Действительный дескриптор запроса. Not null.
  //! \param[in]     pInXSQLDA
  //! \param[in,out] pOutXSQLDA
  void StmtExecute(db_obj::t_db_operation_context& OpCtx,
                   tr_handle_type*                 pTrHandle,
                   stmt_handle_type*               pStmtHandle,
                   const isc_api::XSQLDA_V1*       pInXSQLDA,
                   const isc_api::XSQLDA_V1*       pOutXSQLDA);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Выполнение запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in,out] pTrHandle
  //!  Дескриптор транзакции. Not null.
  //! \param[in] pStmt
  //!  Действительный дескриптор запроса. Not null.
  //! \param[in] pInMsg
  //!  Input parameters data. Can be null.
  //! \param[in,out] pOutMsg
  //!  Output parameters data. Can be null.
  void StmtExecute_M(db_obj::t_db_operation_context& OpCtx,
                     tr_handle_type*                 pTrHandle,
                     stmt_handle_type*               pStmtHandle,
                     const RemoteFB__InMsg_v1*       pInMsg,
                     const RemoteFB__OutMsg_v1*      pOutMsg);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Fetching the row of result set.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of an operation.
  //! \param[in] pStmt
  //!  The valid handle of a statement. Not null.
  //! \param[in,out] pOutXSQLDA
  //!  Not null.
  //! \return
  //!  false when a record was not fetched (the end of result set was reached).
  bool StmtFetch(db_obj::t_db_operation_context& OpCtx,
                 stmt_handle_type*               pStmtHandle,
                 const isc_api::XSQLDA_V1*       pOutXSQLDA);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Fetching the row of result set.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of an operation.
  //! \param[in] pStmt
  //!  The valid handle of a statement. Not null.
  //! \param[in,out] pOutMsg
  //!  Not null.
  //! \return
  //!  false when a record was not fetched (the end of result set was reached).
  bool StmtFetch_M(db_obj::t_db_operation_context& OpCtx,
                   stmt_handle_type*               pStmtHandle,
                   const RemoteFB__OutMsg_v1*      pOutMsg);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Закрытие курсора запроса.
  /// </summary>
  //! \param[in,out] pStmtHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  void StmtClose(stmt_handle_type* pStmtHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Открытие блоба.
  /// </summary>
  //! \param[in] pTrHandle
  //!  Not null.
  //! \param[in,out] pBlobHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //!  На выходе будет назначен указатель на управляющие данные дескриптора.
  //! \param[in] blobID
  void OpenBlob(tr_handle_type*            pTrHandle,
                blob_handle_type*          pBlobHandle,
                const db_obj::DB_IBBLOBID& blobID);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Создание блоба.
  /// </summary>
  //! \param[in] pTrHandle
  //!  Not null.
  //! \param[in,out] pBlobHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //!  На выходе будет назначен указатель на управляющие данные дескриптора.
  //! \param[out] pBlobID
  //!  Not null.
  //! \param[in] szBPB
  //!  Размер pBPB
  //! \param[in] pBPB
  //!  Буфер с параметрами блоба
  void CreateBlob(tr_handle_type*          pTrHandle,
                  blob_handle_type*        pBlobHandle,
                  db_obj::DB_IBBLOBID*     pBlobID,
                  size_t                   szBPB,
                  const protocol::P_UCHAR* pBPB);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Закрытие блоба.
  /// </summary>
  //! \param[in] OpCtx
  //! \param[in,out] pBlobHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  void CloseBlob(db_obj::t_db_operation_context& OpCtx,
                 blob_handle_type*               pBlobHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Отмена создания блоба.
  /// </summary>
  //! \param[in,out] pBlobHandle
  //!  Указатель на действительный дескриптор создаваемого блоба. Not null.
  void CancelBlob(blob_handle_type* pBlobHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Получение сведений о блобе.
  /// </summary>
  //! \param[in]     pBlobHandle
  //!  Действительный дескриптор блоба. Not null.
  //! \param[in]     cItems
  //! \param[in]     pItems
  //! \param[in,out] ResultBuffer
  void GetBlobInfo(blob_handle_type*     pBlobHandle,
                   unsigned short        cItems,
                   const unsigned char*  pItems,
                   RemoteFB__InfoBuffer& ResultBuffer);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Чтение данных блоба.
  /// </summary>
  //! \param[in] OpCtx
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор открытого блоба.
  //! \param[in] cbBuffer
  //!  Размер буфера
  //! \param[out] pvBuffer
  //!  Указатель на приемник
  //! \param[out] pcbActualReaded
  //!  Количество записанных байт в буфер. Not null.
  //! \return
  //!  - false, если был достигут конец блоба.
  //!
  //! \note
  //!  При достижении конца буфера с данными мы можем вернуть данные.
  bool ReadBlob(db_obj::t_db_operation_context& OpCtx,
                blob_handle_type*               pBlobHandle,
                size_t                          cbBuffer,
                void*                           pvBuffer,
                size_t*                         pcbActualReaded);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Запись данных блоба.
  /// </summary>
  //! \param[in] OpCtx
  //!  The operation context.
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор создаваемого блоба.
  //! \param[in] cbBuffer
  //!  Размер буфера
  //! \param[out] pvBuffer
  //!  Указатель на данные
  void WriteBlob(db_obj::t_db_operation_context& OpCtx,
                 blob_handle_type*               pBlobHandle,
                 size_t                          cbBuffer,
                 const void*                     pvBuffer);

  //----------------------------------------------------------------------
 #ifdef IBP_BUILD_TESTCODE

  /// <summary>
  ///  Сброс буферизированных данных блоба.
  /// </summary>
  //! \param[in] OpCtx
  //!  The operation context.
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор создаваемого блоба.
  void FlushBlob(db_obj::t_db_operation_context& OpCtx,
                 blob_handle_type*               pBlobHandle);

 #endif //IBP_BUILD_TESTCODE

  //----------------------------------------------------------------------
  /// <summary>
  ///  Сохранение массива.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pTrHandle
  //!  Указатель на дескриптор активной транзакции. Not null.
  //! \param[in,out] pArrayID
  //!  Указатель на идентификатор обновляемого (создаваемого) массива. Not null.
  //! \param[in] szArraySDL
  //! \param[in] pArraySDL
  //! \param[in] szArrayData
  //! \param[in] pArrayData
  void PutArraySlice(db_obj::t_db_operation_context& opCtx,
                     tr_handle_type*                 pTrHandle,
                     db_obj::DB_IBARRAYID*           pArrayID,
                     size_t                          szArraySDL,
                     const unsigned char*            pArraySDL,
                     size_t                          szArrayData,
                     const void*                     pArrayData);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Чтение массива.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pTrHandle
  //!  Указатель на дескриптор активной транзакции. Not null.
  //! \param[in,out] pArrayID
  //!  Идентификатор загружаемого массива.
  //! \param[in] szArraySDL
  //! \param[in] pArraySDL
  //! \param[in] szArrayData
  //! \param[out] pArrayData
  void GetArraySlice(db_obj::t_db_operation_context& opCtx,
                     tr_handle_type*                 pTrHandle,
                     const db_obj::DB_IBARRAYID&     ArrayID,
                     size_t                          szArraySDL,
                     const unsigned char*            pArraySDL,
                     size_t                          szArrayData,
                     void*                           pArrayData);

 private:
  struct tag_port_factories;

  static self_ptr
          Helper__Create
           (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
            cns_type&                                            cns,
            const tag_port_factories&                            Factories);

  static RemoteFB__PortPtr
          Helper__CreateRemotePort
           (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
            cns_type&                                            cns,
            const tag_port_factories&                            Factories);

  static RemoteFB__PortPtr
          Helper__TryCreateRemotePort_INET_v3
           (wstr_box_type                                        ucs2DbLocation,
            oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
            const tag_port_factories&                            Factories);

  static RemoteFB__PortPtr
          Helper__TryCreateRemotePort_INET_v2
           (wstr_box_type                                        ucs2DbLocation,
            oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
            const tag_port_factories&                            Factories);

 private: //private typedefs ---------------------------------------------
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

 private:
  using tr_handle_data_type
   =handles::RemoteFB__HandleData_Transaction;

  using tr_handle_list_traits
   =tr_handle_data_type::tag_list_adapter;

  using tr_handle_list_type
   =lib::structure::t_list_external<tr_handle_list_traits>;

 private:
  using stmt_handle_data_type
   =handles::RemoteFB__HandleData_Statement;

  using stmt_handle_list_traits
   =stmt_handle_data_type::tag_cn_list_adapter;

  using stmt_handle_list_type
   =lib::structure::t_list_external<stmt_handle_list_traits>;

 private:
  /// <summary>
  ///  Завершение инициализации.
  /// </summary>
  //! \param[in] pDsPropValues
  //!  Not null.
  //!  Параметры строки подключения.
  //! \param[out] cns
  //!  Сведения о подключении.
  //!
  //! - Настройка API
  //! - Загрузка сведений о сервере и базе данных.
  void Helper__FinalInitialize
        (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
         cns_type&                                                  cns);

 private:
  /// <summary>
  ///  Завершение инициализации. Настройка API 10-го протокола. NoLazy-протокол.
  /// </summary>
  void Helper__FinalInitialize__P10__no_lazy();

  /// <summary>
  ///  Завершение инициализации. Настройка API 10-го протокола. LazySend-протокол.
  /// </summary>
  void Helper__FinalInitialize__P10__lazy_send();

 private:
  /// <summary>
  ///  Завершение инициализации. Настройка API 11-го протокола. NoLazy-протокол.
  /// </summary>
  void Helper__FinalInitialize__P11__no_lazy();

  /// <summary>
  ///  Завершение инициализации. Настройка API 11-го протокола. LazySend-протокол.
  /// </summary>
  void Helper__FinalInitialize__P11__lazy_send();

 private:
  /// <summary>
  ///  Завершение инициализации. Настройка API 12-го протокола. NoLazy-протокол.
  /// </summary>
  void Helper__FinalInitialize__P12__no_lazy();

  /// <summary>
  ///  Завершение инициализации. Настройка API 12-го протокола. LazySend-протокол.
  /// </summary>
  void Helper__FinalInitialize__P12__lazy_send();

 private:
  /// <summary>
  ///  Завершение инициализации. Настройка API 13-го протокола. NoLazy-протокол.
  /// </summary>
  void Helper__FinalInitialize__P13__no_lazy();

  /// <summary>
  ///  Завершение инициализации. Настройка API 13-го протокола. LazySend-протокол.
  /// </summary>
  void Helper__FinalInitialize__P13__lazy_send();

 private:
  /// <summary>
  ///  The final initialization. Firebird Server.
  /// </summary>
  void Helper__FinalInitialize__FB
            (const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
             const cns_type&                              cns);

  void Helper__FinalInitialize__FB_02_05
            (const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
             const cns_type&                              cns);

  void Helper__FinalInitialize__FB_03_00
            (const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
             const cns_type&                              cns);

  void Helper__FinalInitialize__FB_04_00
            (const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
             const cns_type&                              cns);

 private:
  /// MT-защита объекта
  guard_type m_Guard;

  /// Данные подключения
  const RemoteFB__ConnectorData::self_ptr m_spData;

 private:
  //! \brief
  //!  Фабрики подключения к базе данных
  static const tag_port_factories sm_port_factories_for_connect_to_db;

  //! \brief
  //!  Фабрики создания базы данных
  static const tag_port_factories sm_port_factories_for_create_db;
};//class RemoteFB__Connector

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

#ifdef IBP_BUILD_TESTCODE

inline RemoteFB__ConnectorData* RemoteFB__Connector::GetData()const
{
 assert(m_spData);

 return m_spData;
}//GetData

//------------------------------------------------------------------------
inline RemoteFB__Port* RemoteFB__Connector::GetPort()const
{
 assert(m_spData);

 return m_spData->GetPort();
}//GetPort

#endif //IBP_BUILD_TESTCODE

//------------------------------------------------------------------------
inline bool RemoteFB__Connector::PortHasInvalidState()const
{
 assert(m_spData);
 assert(m_spData->GetPort());

 return m_spData->GetPort()->port_has_invalid_state();
}//PortHasInvalidState

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
