////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector__api.cpp
//! \brief   Класс управления подключением к FireBird.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

void RemoteFB__Connector::GetDatabaseInfo(protocol::P_USHORT       Incornation,
                                          protocol::P_USHORT       cItems,
                                          const protocol::P_UCHAR* pItems,
                                          RemoteFB__InfoBuffer&    ResultBuffer)
{
 assert(m_spData);
 assert(Incornation==0); //[2015-11-09]

 CHECK_READ_TYPED_PTR(pItems,cItems);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__GetDatabaseInfo.get()->exec
  (m_spData,
   Incornation,
   cItems,
   pItems,
   ResultBuffer);
}//GetDatabaseInfo

//------------------------------------------------------------------------
void RemoteFB__Connector::DetachDatabase()
{
 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__DetachDatabase.get()->exec
  (m_spData); //throw
}//DetachDatabase

//------------------------------------------------------------------------
void RemoteFB__Connector::DropDatabase()
{
 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__DropDatabase.get()->exec
  (m_spData); //throw
}//DropDatabase

//------------------------------------------------------------------------
void RemoteFB__Connector::StartTransaction(tr_handle_type*      const pTrHandle,
                                           size_t               const tpb_length,
                                           const unsigned char* const tpb)
{
 assert(pTrHandle!=nullptr);

 CHECK_READ_TYPED_PTR(tpb,tpb_length);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__StartTransaction.get()->exec
  (m_spData,
   pTrHandle,
   tpb_length,
   tpb); //throw
}//StartTransaction

//------------------------------------------------------------------------
void RemoteFB__Connector::PrepareTransaction(tr_handle_type* const pTrHandle,
                                             size_t          const data_length,
                                             const void*     const data)
{
 assert(pTrHandle!=nullptr);

 assert(m_spData);

 CHECK_READ_PTR(data,data_length);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__PrepareTransaction.get()->exec
  (m_spData,
   pTrHandle,
   data_length,
   data); //throw
}//PrepareTransaction

//------------------------------------------------------------------------
void RemoteFB__Connector::Rollback(tr_handle_type* const pTrHandle)
{
 assert(pTrHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__Rollback.get()->exec
  (m_spData,
   pTrHandle); //throw
}//Rollback

//------------------------------------------------------------------------
void RemoteFB__Connector::RollbackRetaining(tr_handle_type* const pTrHandle)
{
 assert(pTrHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__RollbackRetaining.get()->exec
  (m_spData,
   pTrHandle); //throw
}//RollbackRetaining

//------------------------------------------------------------------------
void RemoteFB__Connector::Commit(tr_handle_type* const pTrHandle)
{
 assert(pTrHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__Commit.get()->exec
  (m_spData,
   pTrHandle); //throw
}//Commit

//------------------------------------------------------------------------
void RemoteFB__Connector::CommitRetaining(tr_handle_type* const pTrHandle)
{
 assert(pTrHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__CommitRetaining.get()->exec
  (m_spData,
   pTrHandle); //throw
}//CommitRetaining

//------------------------------------------------------------------------
void RemoteFB__Connector::ExecuteImmediate(db_obj::t_db_operation_context& OpCtx,
                                           tr_handle_type*           const pTrHandle,
                                           protocol::P_USHORT        const SQL_dialect,
                                           str_box_type              const SQL_str,
                                           const isc_api::XSQLDA_V1* const pInXSQLDA,
                                           const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pTrHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__ExecuteImmediate.get()->exec
  (OpCtx,
   m_spData,
   pTrHandle,
   SQL_dialect,
   SQL_str,
   pInXSQLDA,
   pOutXSQLDA);
}//ExecuteImmediate

//------------------------------------------------------------------------
void RemoteFB__Connector::ExecuteImmediate_M(db_obj::t_db_operation_context&  OpCtx,
                                             tr_handle_type*            const pTrHandle,
                                             protocol::P_USHORT         const SQL_dialect,
                                             str_box_type               const SQL_str,
                                             const RemoteFB__InMsg_v1*  const pInMsg,
                                             const RemoteFB__OutMsg_v1* const pOutMsg)
{
 assert(pTrHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__ExecuteImmediate_M.get()->exec
  (OpCtx,
   m_spData,
   pTrHandle,
   SQL_dialect,
   SQL_str,
   pInMsg,
   pOutMsg);
}//ExecuteImmediate_M

//------------------------------------------------------------------------
void RemoteFB__Connector::StmtAllocate(stmt_handle_type* const pStmtHandle)
{
 assert(pStmtHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__AllocateStatement.get()->exec
  (m_spData,
   pStmtHandle); //throw
}//StmtAllocate

//------------------------------------------------------------------------
void RemoteFB__Connector::StmtDrop(stmt_handle_type* const pStmtHandle)
{
 assert(pStmtHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__DropStatement.get()->exec
  (m_spData,
   pStmtHandle); //throw
}//StmtDrop

//------------------------------------------------------------------------
void RemoteFB__Connector::StmtPrepare(db_obj::t_db_operation_context& OpCtx,
                                      tr_handle_type*           const pTrHandle,
                                      stmt_handle_type*         const pStmtHandle,
                                      protocol::P_USHORT        const SQL_dialect,
                                      str_box_type              const SQL_str,
                                      unsigned long*            const pStmtTypeID)
{
 assert(pStmtHandle!=nullptr);
 assert(pStmtTypeID!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__PrepareStatement.get()->exec
  (OpCtx,
   m_spData,
   pTrHandle,
   pStmtHandle,
   SQL_dialect,
   SQL_str,
   pStmtTypeID); //throw
}//StmtPrepare

//------------------------------------------------------------------------
void RemoteFB__Connector::GetStatementInfo(db_obj::t_db_operation_context& OpCtx,
                                           stmt_handle_type*               pStmtHandle,
                                           unsigned short                  Incornation,
                                           unsigned short                  cItems,
                                           const unsigned char*            pItems,
                                           RemoteFB__InfoBuffer&           ResultBuffer)
{
 assert(pStmtHandle!=nullptr);

 CHECK_READ_TYPED_PTR(pItems,cItems);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__GetStatementInfo.get()->exec
  (OpCtx,
   m_spData,
   pStmtHandle,
   Incornation,
   cItems,
   pItems,
   ResultBuffer);
}//GetStatementInfo

//------------------------------------------------------------------------
void RemoteFB__Connector::GetColumns(db_obj::t_db_operation_context& OpCtx,
                                     stmt_handle_type*         const pStmtHandle,
                                     isc_api::XSQLDA_V1*       const xsqlda)
{
 assert(pStmtHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__GetColumns.get()->exec
  (OpCtx,
   m_spData,
   pStmtHandle,
   xsqlda);
}//GetColumns

//------------------------------------------------------------------------
void RemoteFB__Connector::GetParameters(db_obj::t_db_operation_context& OpCtx,
                                        stmt_handle_type*         const pStmtHandle,
                                        isc_api::XSQLDA_V1*       const xsqlda)
{
 assert(pStmtHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__GetParameters.get()->exec
  (OpCtx,
   m_spData,
   pStmtHandle,
   xsqlda);
}//GetParameters

//------------------------------------------------------------------------
void RemoteFB__Connector::StmtExecute(db_obj::t_db_operation_context& OpCtx,
                                      tr_handle_type*           const pTrHandle,
                                      stmt_handle_type*         const pStmtHandle,
                                      const isc_api::XSQLDA_V1* const pInXSQLDA,
                                      const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pTrHandle!=nullptr);
 assert(pStmtHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__ExecuteStatement.get()->exec
  (OpCtx,
   m_spData,
   pTrHandle,
   pStmtHandle,
   pInXSQLDA,
   pOutXSQLDA);
}//StmtExecute

//------------------------------------------------------------------------
void RemoteFB__Connector::StmtExecute_M(db_obj::t_db_operation_context&  OpCtx,
                                        tr_handle_type*            const pTrHandle,
                                        stmt_handle_type*          const pStmtHandle,
                                        const RemoteFB__InMsg_v1*  const pInMsg,
                                        const RemoteFB__OutMsg_v1* const pOutMsg)

{
 assert(pTrHandle!=nullptr);
 assert(pStmtHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__ExecuteStatement_M.get()->exec
  (OpCtx,
   m_spData,
   pTrHandle,
   pStmtHandle,
   pInMsg,
   pOutMsg);
}//StmtExecute_M

//------------------------------------------------------------------------
bool RemoteFB__Connector::StmtFetch(db_obj::t_db_operation_context& OpCtx,
                                    stmt_handle_type*         const pStmtHandle,
                                    const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pStmtHandle!=nullptr);
 assert(pOutXSQLDA!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 return m_spData->m_API__FetchStatement.get()->exec
         (OpCtx,
          m_spData,
          pStmtHandle,
          pOutXSQLDA);
}//StmtFetch

//------------------------------------------------------------------------
bool RemoteFB__Connector::StmtFetch_M(db_obj::t_db_operation_context&  OpCtx,
                                      stmt_handle_type*          const pStmtHandle,
                                      const RemoteFB__OutMsg_v1* const pOutMsg)
{
 assert(pStmtHandle!=nullptr);
 assert(pOutMsg!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 return m_spData->m_API__FetchStatement_M.get()->exec
         (OpCtx,
          m_spData,
          pStmtHandle,
          pOutMsg);
}//StmtFetch_M

//------------------------------------------------------------------------
void RemoteFB__Connector::StmtClose(stmt_handle_type* const pStmtHandle)
{
 assert(pStmtHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__CloseStatement.get()->exec
  (m_spData,
   pStmtHandle); //throw
}//StmtClose

//------------------------------------------------------------------------
void RemoteFB__Connector::OpenBlob(tr_handle_type*     const  pTrHandle,
                                   blob_handle_type*   const  pBlobHandle,
                                   const db_obj::DB_IBBLOBID& blobID)
{
 assert(pTrHandle!=nullptr);
 assert(pBlobHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__OpenBlob.get()->exec
  (m_spData,
   pTrHandle,
   pBlobHandle,
   blobID); //throw
}//OpenBlob

//------------------------------------------------------------------------
void RemoteFB__Connector::CreateBlob(tr_handle_type*          const pTrHandle,
                                     blob_handle_type*        const pBlobHandle,
                                     db_obj::DB_IBBLOBID*     const pBlobID,
                                     size_t                   const szBPB,
                                     const protocol::P_UCHAR* const pBPB)
{
 assert(pTrHandle!=nullptr);
 assert(pBlobHandle!=nullptr);

 CHECK_READ_TYPED_PTR(pBPB,szBPB);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__CreateBlob.get()->exec
  (m_spData,
   pTrHandle,
   pBlobHandle,
   pBlobID,
   szBPB,
   pBPB); //throw
}//CreateBlob

//------------------------------------------------------------------------
void RemoteFB__Connector::CloseBlob(blob_handle_type* const pBlobHandle)
{
 assert(pBlobHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__CloseBlob.get()->exec
  (m_spData,
   pBlobHandle); //throw
}//CloseBlob

//------------------------------------------------------------------------
void RemoteFB__Connector::CancelBlob(blob_handle_type* const pBlobHandle)
{
 assert(pBlobHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__CancelBlob.get()->exec
  (m_spData,
   pBlobHandle); //throw
}//CancelBlob

//------------------------------------------------------------------------
void RemoteFB__Connector::GetBlobInfo(blob_handle_type*    const pBlobHandle,
                                      unsigned short       const cItems,
                                      const unsigned char* const pItems,
                                      RemoteFB__InfoBuffer&      ResultBuffer)
{
 assert(pBlobHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 m_spData->m_API__GetBlobInfo.get()->exec
  (m_spData,
   pBlobHandle,
   cItems,
   pItems,
   ResultBuffer); //throw
}//GetBlobInfo

//------------------------------------------------------------------------
bool RemoteFB__Connector::ReadBlob(blob_handle_type* const pBlobHandle,
                                   size_t            const cbBuffer,
                                   void*             const pvBuffer,
                                   size_t*           const pcbActualReaded)
{
 assert(pBlobHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 return m_spData->m_API__ReadBlob.get()->exec
         (m_spData,
          pBlobHandle,
          cbBuffer,
          pvBuffer,
          pcbActualReaded);
}//ReadBlob

//------------------------------------------------------------------------
void RemoteFB__Connector::WriteBlob(blob_handle_type* const pBlobHandle,
                                    size_t            const cbBuffer,
                                    const void*       const pvBuffer)
{
 assert(pBlobHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 return m_spData->m_API__WriteBlob.get()->exec
         (m_spData,
          pBlobHandle,
          cbBuffer,
          pvBuffer);
}//WriteBlob

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

void RemoteFB__Connector::FlushBlob(blob_handle_type* const pBlobHandle)
{
 assert(pBlobHandle!=nullptr);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 return m_spData->m_API__FlushBlob.get()->exec
         (m_spData,
          pBlobHandle);
}//FlushBlob

#endif //IBP_BUILD_TESTCODE

//------------------------------------------------------------------------
void RemoteFB__Connector::PutArraySlice(db_obj::t_db_operation_context& opCtx,
                                        tr_handle_type*           const pTrHandle,
                                        db_obj::DB_IBARRAYID*     const pArrayID,
                                        size_t                    const szArraySDL,
                                        const unsigned char*      const pArraySDL,
                                        size_t                    const szArrayData,
                                        const void*               const pArrayData)
{
 assert(pTrHandle!=nullptr);
 assert(pArrayID!=nullptr);

 CHECK_READ_TYPED_PTR(pArraySDL,szArraySDL);

 CHECK_READ_PTR(pArrayData,szArrayData);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 return m_spData->m_API__PutArraySlice.get()->exec
         (opCtx,
          m_spData,
          pTrHandle,
          pArrayID,
          szArraySDL,
          pArraySDL,
          szArrayData,
          pArrayData);
}//PutArraySlice

//------------------------------------------------------------------------
void RemoteFB__Connector::GetArraySlice(db_obj::t_db_operation_context& opCtx,
                                        tr_handle_type*           const pTrHandle,
                                        const db_obj::DB_IBARRAYID&     ArrayID,
                                        size_t                    const szArraySDL,
                                        const unsigned char*      const pArraySDL,
                                        size_t                    const szArrayData,
                                        void*                     const pArrayData)
{
 assert(pTrHandle!=nullptr);

 CHECK_READ_TYPED_PTR(pArraySDL,szArraySDL);

 CHECK_READ_PTR(pArrayData,szArrayData);

 assert(m_spData);

 //-----------------------------------------
 const lock_guard_type lock(m_Guard);

 return m_spData->m_API__GetArraySlice.get()->exec
         (opCtx,
          m_spData,
          pTrHandle,
          ArrayID,
          szArraySDL,
          pArraySDL,
          szArrayData,
          pArrayData);
}//GetArraySlice

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
