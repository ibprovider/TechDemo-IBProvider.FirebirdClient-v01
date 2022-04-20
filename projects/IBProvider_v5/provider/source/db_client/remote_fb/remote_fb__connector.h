////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector.h
//! \brief   ����� ���������� ������������ � FireBird.
//! \author  Kovalenko Dmitry
//! \date    28.10.2014.
#ifndef _remote_fb__connector_H_
#define _remote_fb__connector_H_

#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_obj/isc_base/isc_base.h"
#include <structure/t_list_external.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

class RemoteFB__Connector:public db_obj::t_db_service_provider
                         ,public RemoteFB__SmartObjectBase2
{
 private:
  typedef RemoteFB__Connector                                  self_type;

  RemoteFB__Connector(self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>             self_ptr;

  typedef structure::t_const_wstr_box                          wstr_box_type;

  typedef structure::t_const_str_box                           str_box_type;

  typedef isc_base::t_isc_connection_settings                  cns_type;

  typedef handles::RemoteFB__TrHandle                          tr_handle_type;

  typedef handles::RemoteFB__StmtHandle                        stmt_handle_type;

  typedef handles::RemoteFB__BlobHandle                        blob_handle_type;

 private:
  explicit RemoteFB__Connector(RemoteFB__Port* pPort);

  virtual ~RemoteFB__Connector();

 public:
  /// <summary>
  ///  ���������� � ���� ������.
  /// </summary>
  //! \param[in]  pDsPropValues
  //!  Not null.
  //! \param[out] cns
  static self_ptr ConnectToDatabase
                   (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                    cns_type&                                            cns);

  /// <summary>
  ///  �������� ���� ������ � ����������� � ���.
  /// </summary>
  //! \param[in]  pDsPropValues
  //!  Not null.
  //! \param[out] cns
  static self_ptr CreateDatabase
                   (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                    cns_type&                                            cns);

  //----------------------------------------------------------------------

  LCPI_CPP_LIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS__FINAL

  //----------------------------------------------------------------------
 #ifdef IBP_BUILD_TESTCODE

  /// <summary>
  ///  TEST_CODE: ��������� ��������� �� ������ � ������� �����������.
  /// </summary>
  RemoteFB__ConnectorData* GetData()const;

  /// <summary>
  ///  TEST_CODE: ��������� ��������� �� ���� �����������.
  /// </summary>
  RemoteFB__Port* GetPort()const;
 #endif

  //----------------------------------------------------------------------
  
  /// <summary>
  ///  ������������ ����������������� ��������� �����.
  /// </summary>
  bool PortHasInvalidState()const;
  
  //----------------------------------------------------------------------
  /// <summary>
  ///  ��������� �������� � ������� � ���� ������.
  /// </summary>
  //! \param[in]  Incornation
  //!  ���������� ������� ��������.
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  void GetDatabaseInfo(protocol::P_USHORT       Incornation,
                       protocol::P_USHORT       cItems,
                       const protocol::P_UCHAR* pItems,
                       RemoteFB__InfoBuffer&    ResultBuffer);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ���������� �� ���� ������.
  /// </summary>
  void DetachDatabase();

  //----------------------------------------------------------------------
  /// <summary>
  ///  �������� ���� ������.
  /// </summary>
  void DropDatabase();

  //----------------------------------------------------------------------
  /// <summary>
  ///  �������� ����������.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� ������� ��������.
  //!  �� ������ ��������� ���������� ���������� ��������� ����������.
  //! \param[in] tpb_length
  //! \param[in] tpb
  void StartTransaction(tr_handle_type*      pTrHandle,
                        size_t               tpb_length,
                        const unsigned char* tpb);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ���������� ����������.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� �������������� ���������� ����������� ����������.
  //! \param[in] data_length
  //! \param[in] data
  void PrepareTransaction(tr_handle_type* pTrHandle,
                          size_t          data_length,
                          const void*     data);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ����� ����������.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� �������������� ���������� ����������� ����������.
  //!
  //! � ������ ��������� ������ ����������, (*pTrHandle) ����� �������.
  void Rollback(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ����� ���������� � ����������� ���������.
  /// </summary>
  //! \param[in] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� �������������� ���������� ����������� ����������.
  void RollbackRetaining(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������ ����������.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� �������������� ���������� ����������� ����������.
  //!
  //! � ������ ��������� ������� ����������, (*pTrHandle) ����� �������.
  void Commit(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������ ���������� � ����������� ���������.
  /// </summary>
  //! \param[in,out] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� �������������� ���������� ����������� ����������.
  void CommitRetaining(tr_handle_type* pTrHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ����������� ���������� �������.
  /// </summary>
  //! \param[in]     OpCtx
  //!  �������� ��������.
  //! \param[in,out] pTrHandle
  //!  ���������� ����������. Not null.
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
  ///  �������� ����������� ��� ���������� ��������.
  /// </summary>
  //! \param[in,out] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ������� ��������.
  //!  �� ������ ��������� ���������� ���������� �������.
  void StmtAllocate(stmt_handle_type* pStmtHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������������ ����������� ��� ���������� ��������.
  /// </summary>
  //! \param[in,out] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //!  �� ������ ��������� ���������� ������� ��������.
  void StmtDrop(stmt_handle_type* pStmtHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ���������� �������.
  /// </summary>
  //! \param[in] OpCtx
  //!  �������� ��������.
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
  ///  ��������� �������������� ������ �������.
  /// </summary>
  //! \param[in]     OpCtx
  //!  �������� ��������.
  //! \param[in]     pStmtHandle
  //!  �������������� ���������� �������. Not null.
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
  ///  ��������� �������� ������� �������.
  /// </summary>
  //! \param[in]     OpCtx
  //!  �������� ��������.
  //! \param[in]     pStmtHandle
  //!  �������������� ���������� �������. Not null.
  //! \param[in,out] xsqlda
  //!  �������� ������� �������. Not null.
  void GetColumns(db_obj::t_db_operation_context& OpCtx,
                  stmt_handle_type*               pStmtHandle,
                  isc_api::XSQLDA_V1*             xsqlda);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ��������� �������� ���������� �������.
  /// </summary>
  //! \param[in]     OpCtx
  //!  �������� ��������.
  //! \param[in]     pStmtHandle
  //!  �������������� ���������� �������. Not null.
  //! \param[in,out] xsqlda
  //!  �������� ���������� �������. Not null.
  void GetParameters(db_obj::t_db_operation_context& OpCtx,
                     stmt_handle_type*               pStmtHandle,
                     isc_api::XSQLDA_V1*             xsqlda);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ���������� �������.
  /// </summary>
  //! \param[in] OpCtx
  //!  �������� ��������.
  //! \param[in,out] pTrHandle
  //!  ���������� ����������. Not null.
  //! \param[in] pStmt
  //!  �������������� ���������� �������. Not null.
  //! \param[in]     pInXSQLDA
  //! \param[in,out] pOutXSQLDA
  void StmtExecute(db_obj::t_db_operation_context& OpCtx,
                   tr_handle_type*                 pTrHandle,
                   stmt_handle_type*               pStmtHandle,
                   const isc_api::XSQLDA_V1*       pInXSQLDA,
                   const isc_api::XSQLDA_V1*       pOutXSQLDA);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������� ����.
  /// </summary>
  //! \param[in] OpCtx
  //!  �������� ��������.
  //! \param[in] pStmt
  //!  �������������� ���������� �������. Not null.
  //! \param[in,out] pOutXSQLDA
  //!  Not null.
  //! \return
  //!  false, ���� ������ �� ������� (��������� ����� ��������������� ���������).
  bool StmtFetch(db_obj::t_db_operation_context& OpCtx,
                 stmt_handle_type*               pStmtHandle,
                 const isc_api::XSQLDA_V1*       pOutXSQLDA);

  //----------------------------------------------------------------------
  /// <summary>
  ///  �������� ������� �������.
  /// </summary>
  //! \param[in,out] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  void StmtClose(stmt_handle_type* pStmtHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  �������� �����.
  /// </summary>
  //! \param[in] pTrHandle
  //!  Not null.
  //! \param[in,out] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ������� ��������.
  //!  �� ������ ����� �������� ��������� �� ����������� ������ �����������.
  //! \param[in] blobID
  void OpenBlob(tr_handle_type*            pTrHandle,
                blob_handle_type*          pBlobHandle,
                const db_obj::DB_IBBLOBID& blobID);

  //----------------------------------------------------------------------
  /// <summary>
  ///  �������� �����.
  /// </summary>
  //! \param[in] pTrHandle
  //!  Not null.
  //! \param[in,out] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ������� ��������.
  //!  �� ������ ����� �������� ��������� �� ����������� ������ �����������.
  //! \param[out] pBlobID
  //!  Not null.
  //! \param[in] szBPB
  //!  ������ pBPB
  //! \param[in] pBPB
  //!  ����� � ����������� �����
  void CreateBlob(tr_handle_type*          pTrHandle,
                  blob_handle_type*        pBlobHandle,
                  db_obj::DB_IBBLOBID*     pBlobID,
                  size_t                   szBPB,
                  const protocol::P_UCHAR* pBPB);

  //----------------------------------------------------------------------
  /// <summary>
  ///  �������� �����.
  /// </summary>
  //! \param[in,out] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  void CloseBlob(blob_handle_type* pBlobHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������ �������� �����.
  /// </summary>
  //! \param[in,out] pBlobHandle
  //!  ��������� �� �������������� ���������� ������������ �����. Not null.
  void CancelBlob(blob_handle_type* pBlobHandle);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ��������� �������� � �����.
  /// </summary>
  //! \param[in]     pBlobHandle
  //!  �������������� ���������� �����. Not null.
  //! \param[in]     cItems
  //! \param[in]     pItems
  //! \param[in,out] ResultBuffer
  void GetBlobInfo(blob_handle_type*     pBlobHandle,
                   unsigned short        cItems,
                   const unsigned char*  pItems,
                   RemoteFB__InfoBuffer& ResultBuffer);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������ ������ �����.
  /// </summary>
  //! \param[in] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ���������� ��������� �����.
  //! \param[in] cbBuffer
  //!  ������ ������
  //! \param[out] pvBuffer
  //!  ��������� �� ��������
  //! \param[out] pcbActualReaded
  //!  ���������� ���������� ���� � �����. Not null.
  //! \return
  //!  - false, ���� ��� �������� ����� �����.
  //!
  //! \note
  //!  ��� ���������� ����� ������ � ������� �� ����� ������� ������.
  bool ReadBlob(blob_handle_type* pBlobHandle,
                size_t            cbBuffer,
                void*             pvBuffer,
                size_t*           pcbActualReaded);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������ ������ �����.
  /// </summary>
  //! \param[in] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ���������� ������������ �����.
  //! \param[in] cbBuffer
  //!  ������ ������
  //! \param[out] pvBuffer
  //!  ��������� �� ������
  void WriteBlob(blob_handle_type* pBlobHandle,
                 size_t            cbBuffer,
                 const void*       pvBuffer);

  //----------------------------------------------------------------------
 #ifdef IBP_BUILD_TESTCODE

  /// <summary>
  ///  ����� ���������������� ������ �����.
  /// </summary>
  //! \param[in] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ���������� ������������ �����.
  void FlushBlob(blob_handle_type* pBlobHandle);

 #endif //IBP_BUILD_TESTCODE

  //----------------------------------------------------------------------
  /// <summary>
  ///  ���������� �������.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pTrHandle
  //!  ��������� �� ���������� �������� ����������. Not null.
  //! \param[in,out] pArrayID
  //!  ��������� �� ������������� ������������ (������������) �������. Not null.
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
  ///  ������ �������.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pTrHandle
  //!  ��������� �� ���������� �������� ����������. Not null.
  //! \param[in,out] pArrayID
  //!  ������������� ������������ �������.
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

  //t_db_service_provider interface --------------------------------------
  /// <summary>
  /// ������ ���������� �������
  /// </summary>
  //! \param[in] rguidService
  //!   ������������� �������
  //! \return
  //!   ���������� ��������� �� ��������� ������. ���� �������������
  //!   ������ �� ��������������, �� ������������ NULL
  virtual db_obj::t_db_object_ptr query_service(REFGUID rguidService)COMP_W000004_OVERRIDE_FINAL;

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
  typedef structure::t_multi_thread_traits              thread_traits;

  typedef thread_traits::guard_type                     guard_type;

  typedef thread_traits::lock_guard_type                lock_guard_type;

 private:
  typedef handles::RemoteFB__HandleData_Transaction     tr_handle_data_type;

  typedef tr_handle_data_type::tag_list_adapter         tr_handle_list_traits;

  typedef structure::t_list_external
           <tr_handle_list_traits>                      tr_handle_list_type;

 private:
  typedef handles::RemoteFB__HandleData_Statement       stmt_handle_data_type;

  typedef stmt_handle_data_type::tag_cn_list_adapter    stmt_handle_list_traits;

  typedef structure::t_list_external
           <stmt_handle_list_traits>                    stmt_handle_list_type;

 private:
  /// <summary>
  ///  ���������� �������������.
  /// </summary>
  //! \param[in] pDsPropValues
  //!  Not null.
  //!  ��������� ������ �����������.
  //! \param[out] cns
  //!  �������� � �����������.
  //!
  //! - ��������� API
  //! - �������� �������� � ������� � ���� ������.
  void Helper__FinalInitialize
        (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
         cns_type&                                                  cns);

 private:
  /// <summary>
  ///  ���������� �������������. ��������� API 10-�� ���������. NoLazy-��������.
  /// </summary>
  void Helper__FinalInitialize__P10__no_lazy();

  /// <summary>
  ///  ���������� �������������. ��������� API 10-�� ���������. LazySend-��������.
  /// </summary>
  void Helper__FinalInitialize__P10__lazy_send();

 private:
  /// <summary>
  ///  ���������� �������������. ��������� API 11-�� ���������. NoLazy-��������.
  /// </summary>
  void Helper__FinalInitialize__P11__no_lazy();

  /// <summary>
  ///  ���������� �������������. ��������� API 11-�� ���������. LazySend-��������.
  /// </summary>
  void Helper__FinalInitialize__P11__lazy_send();

 private:
  /// <summary>
  ///  ���������� �������������. ��������� API 12-�� ���������. NoLazy-��������.
  /// </summary>
  void Helper__FinalInitialize__P12__no_lazy();

  /// <summary>
  ///  ���������� �������������. ��������� API 12-�� ���������. LazySend-��������.
  /// </summary>
  void Helper__FinalInitialize__P12__lazy_send();

 private:
  /// <summary>
  ///  ���������� �������������. ��������� API 13-�� ���������. NoLazy-��������.
  /// </summary>
  void Helper__FinalInitialize__P13__no_lazy();

  /// <summary>
  ///  ���������� �������������. ��������� API 13-�� ���������. LazySend-��������.
  /// </summary>
  void Helper__FinalInitialize__P13__lazy_send();

 private:
  /// MT-������ �������
  guard_type m_Guard;

  /// ������ �����������
  const RemoteFB__ConnectorData::self_ptr m_spData;

 private:
  //! \brief
  //!  ������� ����������� � ���� ������
  static const tag_port_factories sm_port_factories_for_connect_to_db;

  //! \brief
  //!  ������� �������� ���� ������
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
