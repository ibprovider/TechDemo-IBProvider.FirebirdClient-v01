////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                               Kovalenko Dmitry. 12.11.2014.
#ifndef _test_services_H_
#define _test_services_H_

#include "source/test_cn_params.h"

//#include "source/db_client/remote_fb/ports/inet/remote_fb__inet__socket.h"
#include "source/db_client/remote_fb/ports/factories/inet/remote_fb__ports__factories__inet.h"
#include "source/db_client/remote_fb/ports/inet/remote_fb__ports__inet.h"
#include "source/db_client/remote_fb/remote_fb__connector.h"

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//namespaces

namespace remote_fb                         =ibp::db_client::remote_fb;
namespace remote_fb_inet_factory            =remote_fb::ports::factories::inet;
namespace remote_fb_inet_stream             =remote_fb::ports::streams::inet;
namespace remote_fb_inet_port               =remote_fb::ports::inet;
namespace winsock                           =ibp::os::win32::winsock;
namespace isc_api                           =ibp::isc_api;
namespace isc_base                          =ibp::isc_base;
namespace db_obj                            =ibp::db_obj;

////////////////////////////////////////////////////////////////////////////////
//class TestServices

class TestServices
{
 private:
  typedef TestServices                                  self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstr_box                   wstr_box_type;
  typedef structure::t_const_str_box                    str_box_type;

  //----------------------------------------
  typedef isc_base::t_isc_connection_settings           cns_type;

  typedef TestCnParams                                  dbprops_type;

  //----------------------------------------
  typedef winsock::t_winsock__provider                  winsock_provider_type;

  typedef winsock_provider_type::self_ptr               winsock_provider_ptr;

  typedef winsock_provider_type::dll_type               winsock_dll_type;

  typedef winsock_dll_type::self_ptr                    winsock_dll_ptr;

  //----------------------------------------
  typedef remote_fb_inet_stream::RemoteFB__INET_Socket  remote_fb_inet_socket_type;

  typedef remote_fb_inet_socket_type::self_ptr          remote_fb_inet_socket_ptr;

  typedef remote_fb_inet_port::RemoteFB__Port_INET      remote_fb_inet_port_type;

  typedef remote_fb_inet_port_type::self_ptr            remote_fb_inet_port_ptr;

  //----------------------------------------
  typedef remote_fb::RemoteFB__Connector                remote_fb_connector_type;

  typedef remote_fb_connector_type::self_ptr            remote_fb_connector_ptr;

  //----------------------------------------
  typedef remote_fb_connector_type::tr_handle_type      remote_fb_tr_handle_type;

  typedef remote_fb_connector_type::stmt_handle_type    remote_fb_stmt_handle_type;

  typedef remote_fb_connector_type::blob_handle_type    remote_fb_blob_handle_type;

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_WeWaitTheError();

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_UnknownProtocolVersion(remote_fb::protocol::P_PROTOCOL_VERSION v);

 public: //--------------------------------- CommonServices
  template<typename charT>
  static std::basic_string<charT>
   PrepareStrForPrint(structure::t_basic_const_str_box<charT> src);

 public:
  static std::wstring BuildLocationString(const TTSO_GlobalContext* pParams);

 public: //--------------------------------- WinSock
  static winsock_dll_ptr
   WinSock__LoadDLL(TTSO_Tracer&   tracer,
                    const wchar_t* pDllName);

  static winsock_provider_ptr
   WinSock__CreateProvider(TTSO_Tracer&      tracer,
                           winsock_dll_type* pDLL);

  //STD version
  static winsock_provider_ptr
   WinSock__CreateProvider__STD(TTSO_Tracer&      tracer);

 public: //--------------------------------- DirectFB_INET
  static remote_fb_inet_socket_ptr
   RemoteFB_INET_Socket__Connect2(TTSO_Tracer&           tracer,
                                  winsock_provider_type* pProvider,
                                  int                    socketFamily,
                                  const wchar_t*         ucs2_host,
                                  const wchar_t*         ucs2_port);

  static remote_fb_inet_port_ptr
   RemoteFB_INET_Port__ConnectToDatabase(TTSO_Tracer&         tracer,
                                         int                  socketFamily,
                                         wstr_box_type        ucs2_host,
                                         wstr_box_type        ucs2_port,
                                         wstr_box_type        ucs2_database_name,
                                         const dbprops_type&  params);

  static remote_fb_inet_port_ptr
   RemoteFB_INET_Port__CreateDatabase(TTSO_Tracer&         tracer,
                                      int                  socketFamily,
                                      const wchar_t*       ucs2_host,
                                      const wchar_t*       ucs2_port,
                                      const wchar_t*       ucs2_database_name,
                                      const dbprops_type&  params);

 public: //--------------------------------- RemoteFB__Connector
  static remote_fb_connector_ptr
   RemoteFB_Connector__ConnectToDatabase(TTSO_Tracer&        tracer,
                                         const dbprops_type& params,
                                         cns_type&           cns);

  static remote_fb_connector_ptr
   RemoteFB_Connector__CreateDatabase(TTSO_Tracer&        tracer,
                                      const dbprops_type& params,
                                      cns_type&           cns);

  static void
   RemoteFB_Connector__DetachDatabase(TTSO_Tracer&              tracer,
                                      remote_fb_connector_type* pConnector);

  static void
   RemoteFB_Connector__DropDatabase(TTSO_Tracer&              tracer,
                                    remote_fb_connector_type* pConnector);

  static void
   RemoteFB_Connector__GetDatabaseInfo(TTSO_Tracer&                     tracer,
                                       remote_fb_connector_type*        pConnector,
                                       unsigned short                   Incornation,
                                       unsigned short                   cItems,
                                       const unsigned char*             pItems,
                                       remote_fb::RemoteFB__InfoBuffer& ResultBuffer);

  static void
   RemoteFB_Connector__StartTransaction(TTSO_Tracer&              tracer,
                                        remote_fb_connector_type* pConnector,
                                        remote_fb_tr_handle_type* pTrHandle);

  static void
   RemoteFB_Connector__StartTransaction(TTSO_Tracer&              tracer,
                                        remote_fb_connector_type* pConnector,
                                        remote_fb_tr_handle_type* pTrHandle,
                                        size_t                    tpb_length,
                                        const unsigned char*      tpb);

  static void
   RemoteFB_Connector__PrepareTransaction(TTSO_Tracer&              tracer,
                                          remote_fb_connector_type* pConnector,
                                          remote_fb_tr_handle_type* pTrHandle,
                                          size_t                    data_length,
                                          const void*               data);

  static void
   RemoteFB_Connector__Rollback(TTSO_Tracer&              tracer,
                                remote_fb_connector_type* pConnector,
                                remote_fb_tr_handle_type* pTrHandle);

  static void
   RemoteFB_Connector__RollbackRetaining(TTSO_Tracer&              tracer,
                                         remote_fb_connector_type* pConnector,
                                         remote_fb_tr_handle_type* pTrHandle);

  static void
   RemoteFB_Connector__Commit(TTSO_Tracer&              tracer,
                              remote_fb_connector_type* pConnector,
                              remote_fb_tr_handle_type* pTrHandle);

  static void
   RemoteFB_Connector__CommitRetaining(TTSO_Tracer&              tracer,
                                       remote_fb_connector_type* pConnector,
                                       remote_fb_tr_handle_type* pTrHandle);

 public:
  static void
   RemoteFB_Connector__ExecuteImmediate(TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type*       pConnector,
                                        db_obj::t_db_operation_context& op_ctx,
                                        remote_fb_tr_handle_type*       pTrHandle,
                                        remote_fb::protocol::P_USHORT   SQL_Dialect,
                                        structure::t_const_str_box      SQL_str,
                                        const isc_api::XSQLDA_V1*       pInXSQLDA,
                                        const isc_api::XSQLDA_V1*       pOutXSQLDA);

 public:
  static void
   RemoteFB_Connector__StmtAllocate(TTSO_Tracer&                tracer,
                                    remote_fb_connector_type*   pConnector,
                                    remote_fb_stmt_handle_type* pStmtHandle);
  static void
   RemoteFB_Connector__StmtDrop(TTSO_Tracer&                tracer,
                                remote_fb_connector_type*   pConnector,
                                remote_fb_stmt_handle_type* pStmtHandle,
                                const wchar_t*              stmtSign=nullptr);

  static void
   RemoteFB_Connector__StmtClose(TTSO_Tracer&                tracer,
                                 remote_fb_connector_type*   pConnector,
                                 remote_fb_stmt_handle_type* pStmtHandle,
                                 const wchar_t*              stmtSign=nullptr);

  static void
   RemoteFB_Connector__StmtClose(remote_fb_connector_type*   pConnector,
                                 remote_fb_stmt_handle_type* pStmtHandle);

  static void
   RemoteFB_Connector__StmtPrepare(TTSO_Tracer&                    tracer,
                                   remote_fb_connector_type*       pConnector,
                                   db_obj::t_db_operation_context& opCtx,
                                   remote_fb_tr_handle_type*       pTrHandle,
                                   remote_fb_stmt_handle_type*     pStmtHandle,
                                   remote_fb::protocol::P_USHORT   SQL_dialect,
                                   structure::t_const_str_box      SQL_str);

  static void
   RemoteFB_Connector__StmtPrepare(remote_fb_connector_type*       pConnector,
                                   db_obj::t_db_operation_context& opCtx,
                                   remote_fb_tr_handle_type*       pTrHandle,
                                   remote_fb_stmt_handle_type*     pStmtHandle,
                                   remote_fb::protocol::P_USHORT   SQL_dialect,
                                   structure::t_const_str_box      SQL_str);

  static void
   RemoteFB_Connector__GetColumns(TTSO_Tracer&                    tracer,
                                  remote_fb_connector_type*       pConnector,
                                  db_obj::t_db_operation_context& opCtx,
                                  remote_fb_stmt_handle_type*     pStmtHandle,
                                  isc_api::XSQLDA_V1*             xsqlda);

  static void
   RemoteFB_Connector__GetParameters(TTSO_Tracer&                    tracer,
                                     remote_fb_connector_type*       pConnector,
                                     db_obj::t_db_operation_context& opCtx,
                                     remote_fb_stmt_handle_type*     pStmtHandle,
                                     isc_api::XSQLDA_V1*             xsqlda);

  static void
   RemoteFB_Connector__GetStatementInfo(TTSO_Tracer&                     tracer,
                                        remote_fb_connector_type*        pConnector,
                                        db_obj::t_db_operation_context&  opCtx,
                                        remote_fb_stmt_handle_type*      pStmtHandle,
                                        unsigned short                   Incornation,
                                        unsigned short                   cItems,
                                        const unsigned char*             pItems,
                                        remote_fb::RemoteFB__InfoBuffer& ResultBuffer);

  static void
   RemoteFB_Connector__StmtExecute(TTSO_Tracer&                    tracer,
                                   remote_fb_connector_type*       pConnector,
                                   db_obj::t_db_operation_context& opCtx,
                                   remote_fb_tr_handle_type*       pTrHandle,
                                   remote_fb_stmt_handle_type*     pStmtHandle,
                                   const isc_api::XSQLDA_V1*       pInXSQLDA,
                                   const isc_api::XSQLDA_V1*       pOutXSQLDA);

  static void
   RemoteFB_Connector__StmtExecute(remote_fb_connector_type*       pConnector,
                                   db_obj::t_db_operation_context& opCtx,
                                   remote_fb_tr_handle_type*       pTrHandle,
                                   remote_fb_stmt_handle_type*     pStmtHandle,
                                   const isc_api::XSQLDA_V1*       pInXSQLDA,
                                   const isc_api::XSQLDA_V1*       pOutXSQLDA);

  static bool
   RemoteFB_Connector__StmtFetch(TTSO_Tracer&                    tracer,
                                 remote_fb_connector_type*       pConnector,
                                 db_obj::t_db_operation_context& opCtx,
                                 remote_fb_stmt_handle_type*     pStmtHandle,
                                 const isc_api::XSQLDA_V1*       pOutXSQLDA);

  static void
   RemoteFB_Connector__StmtFetch_ToRow(TTSO_Tracer&                    tracer,
                                       remote_fb_connector_type*       pConnector,
                                       db_obj::t_db_operation_context& opCtx,
                                       remote_fb_stmt_handle_type*     pStmtHandle,
                                       const isc_api::XSQLDA_V1*       pOutXSQLDA);

  static void
   RemoteFB_Connector__StmtFetch_ToRow(remote_fb_connector_type*       pConnector,
                                       db_obj::t_db_operation_context& opCtx,
                                       remote_fb_stmt_handle_type*     pStmtHandle,
                                       const isc_api::XSQLDA_V1*       pOutXSQLDA);

  static void
   RemoteFB_Connector__StmtFetch_ToEOF(TTSO_Tracer&                    tracer,
                                       remote_fb_connector_type*       pConnector,
                                       db_obj::t_db_operation_context& opCtx,
                                       remote_fb_stmt_handle_type*     pStmtHandle,
                                       const isc_api::XSQLDA_V1*       pOutXSQLDA);

  static void
   RemoteFB_Connector__StmtFetch_ToEOF(remote_fb_connector_type*       pConnector,
                                       db_obj::t_db_operation_context& opCtx,
                                       remote_fb_stmt_handle_type*     pStmtHandle,
                                       const isc_api::XSQLDA_V1*       pOutXSQLDA);

 public:
  static void RemoteFB_Connector__OpenBlob(TTSO_Tracer&                 tracer,
                                           remote_fb_connector_type*    pConnector,
                                           remote_fb_tr_handle_type*    pTrHandle,
                                           remote_fb_blob_handle_type*  pBlobHandle,
                                           const db_obj::DB_IBBLOBID&   blobID);

  static void RemoteFB_Connector__CreateBlob(TTSO_Tracer&                 tracer,
                                             remote_fb_connector_type*    pConnector,
                                             remote_fb_tr_handle_type*    pTrHandle,
                                             remote_fb_blob_handle_type*  pBlobHandle,
                                             db_obj::DB_IBBLOBID*         pBlobID);

  static void RemoteFB_Connector__CreateBlob(TTSO_Tracer&                        tracer,
                                             remote_fb_connector_type*           pConnector,
                                             remote_fb_tr_handle_type*           pTrHandle,
                                             remote_fb_blob_handle_type*         pBlobHandle,
                                             db_obj::DB_IBBLOBID*                pBlobID,
                                             size_t                              szBPB,
                                             const remote_fb::protocol::P_UCHAR* pBPB);

  static void RemoteFB_Connector__CloseBlob(TTSO_Tracer&                 tracer,
                                            remote_fb_connector_type*    pConnector,
                                            remote_fb_blob_handle_type*  pBlobHandle);

  static void RemoteFB_Connector__CancelBlob(TTSO_Tracer&                 tracer,
                                             remote_fb_connector_type*    pConnector,
                                             remote_fb_blob_handle_type*  pBlobHandle);

  static void RemoteFB_Connector__GetBlobInfo(TTSO_Tracer&                     tracer,
                                              remote_fb_connector_type*        pConnector,
                                              remote_fb_blob_handle_type*      pBlobHandle,
                                              unsigned short                   cItems,
                                              const unsigned char*             pItems,
                                              remote_fb::RemoteFB__InfoBuffer& ResultBuffer);

  static bool RemoteFB_Connector__ReadBlob(TTSO_Tracer&                tracer,
                                           remote_fb_connector_type*   pConnector,
                                           remote_fb_blob_handle_type* pBlobHandle,
                                           size_t                      cbBuffer,
                                           void*                       pvBuffer,
                                           size_t*                     pcbActualReaded);

  static void RemoteFB_Connector__WriteBlob(TTSO_Tracer&                tracer,
                                            remote_fb_connector_type*   pConnector,
                                            remote_fb_blob_handle_type* pBlobHandle,
                                            size_t                      cbBuffer,
                                            const void*                 pvBuffer);

  static void RemoteFB_Connector__FlushBlob(TTSO_Tracer&                tracer,
                                            remote_fb_connector_type*   pConnector,
                                            remote_fb_blob_handle_type* pBlobHandle);

 public:
  static void RemoteFB_Connector__PutArraySlice(TTSO_Tracer&                    tracer,
                                                remote_fb_connector_type*       pConnector,
                                                db_obj::t_db_operation_context& op_ctx,
                                                remote_fb_tr_handle_type*       pTrHandle,
                                                db_obj::DB_IBARRAYID*           pArrayID,
                                                size_t                          szArraySDL,
                                                const unsigned char*            pArraySDL,
                                                size_t                          szArrayData,
                                                const void*                     pArrayData);

  static void RemoteFB_Connector__GetArraySlice(TTSO_Tracer&                    tracer,
                                                remote_fb_connector_type*       pConnector,
                                                db_obj::t_db_operation_context& op_ctx,
                                                remote_fb_tr_handle_type*       pTrHandle,
                                                const db_obj::DB_IBARRAYID&     ArrayID,
                                                size_t                          szArraySDL,
                                                const unsigned char*            pArraySDL,
                                                size_t                          szArrayData,
                                                void*                           pArrayData);

 public:
  static void XSQLDA_check_sqld
               (TTSO_Tracer&              tracer,
                const isc_api::XSQLDA_V1* xsqlda,
                short                     sqld);

 public:
  static void XSQLVAR_check_sqltype
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqltype);

  static void XSQLVAR_check_sqlsubtype
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqlsubtype);

  static void XSQLVAR_check_sqlscale
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqlscale);

  static void XSQLVAR_check_sqllen
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqllen);

  static void XSQLVAR_check_sqlname
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               sqlname);

  static void XSQLVAR_check_relname
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               relname);

  static void XSQLVAR_check_ownname
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               ownname);

  static void XSQLVAR_check_aliasname
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               aliasname);

  //----------
  static void XSQLVAR_check
               (TTSO_Tracer&               tracer,
                const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqltype,
                short                      sqlsubtype,
                short                      sqlscale,
                short                      sqllen,
                str_box_type               sqlname,
                str_box_type               relname,
                str_box_type               ownname,
                str_box_type               aliasname);

 public:
  static void XSQLVAR_check_sqltype
               (const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqltype);

  static void XSQLVAR_check_sqlsubtype
               (const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqlsubtype);

  static void XSQLVAR_check_sqlscale
               (const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqlscale);

  static void XSQLVAR_check_sqllen
               (const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqllen);

  static void XSQLVAR_check_sqlname
               (const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               sqlname);

  static void XSQLVAR_check_relname
               (const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               relname);

  static void XSQLVAR_check_ownname
               (const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               ownname);

  static void XSQLVAR_check_aliasname
               (const isc_api::XSQLVAR_V1* xsqlvar,
                str_box_type               aliasname);

  //----------
  static void XSQLVAR_check
               (const isc_api::XSQLVAR_V1* xsqlvar,
                short                      sqltype,
                short                      sqlsubtype,
                short                      sqlscale,
                short                      sqllen,
                str_box_type               sqlname,
                str_box_type               relname,
                str_box_type               ownname,
                str_box_type               aliasname);
 public:
  static void
   HACK__DetachCn(TTSO_Tracer&              tracer,
                  remote_fb_connector_type* pConnector);

  static void
   HACK__DropDb(TTSO_Tracer&                              tracer,
                remote_fb_connector_type*                 pConnector);

  static void
   HACK__DropStmt(TTSO_Tracer&                              tracer,
                  remote_fb_connector_type*                 pConnector,
                  remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   HACK__CloseStmt(TTSO_Tracer&                             tracer,
                  remote_fb_connector_type*                 pConnector,
                  remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   HACK__UnprepareStmt(TTSO_Tracer&                              tracer,
                       remote_fb_connector_type*                 pConnector,
                       remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   HACK__CommitTr(TTSO_Tracer&                            tracer,
                  remote_fb_connector_type*               pConnector,
                  remote_fb::handles::RemoteFB__TrHandle* pTrHandle);

  static void
   HACK__CloseBlob(TTSO_Tracer&                              tracer,
                   remote_fb_connector_type*                 pConnector,
                   remote_fb::handles::RemoteFB__BlobHandle* pBlobHandle);

 private:
  static void
   Helper__PSET01__HACK__DetachCn
    (TTSO_Tracer&              tracer,
     remote_fb_connector_type* pConnector);

  static void
   Helper__PSET01__HACK__DropDb
    (TTSO_Tracer&              tracer,
     remote_fb_connector_type* pConnector);

  static void
   Helper__PSET01__HACK__DropStmt
    (TTSO_Tracer&                              tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   Helper__PSET01__HACK__CloseStmt
    (TTSO_Tracer&                             tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   Helper__PSET01__HACK__UnprepareStmt
    (TTSO_Tracer&                              tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   Helper__PSET01__HACK__CommitTr
    (TTSO_Tracer&                            tracer,
     remote_fb_connector_type*               pConnector,
     remote_fb::handles::RemoteFB__TrHandle* pTrHandle);

  static void
   Helper__PSET01__HACK__CloseBlob
    (TTSO_Tracer&                              tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__BlobHandle* pBlobHandle);

 private:
  static void
   Helper__PSET02__HACK__DetachCn
    (TTSO_Tracer&              tracer,
     remote_fb_connector_type* pConnector);

  static void
   Helper__PSET02__HACK__DropDb
    (TTSO_Tracer&              tracer,
     remote_fb_connector_type* pConnector);

  static void
   Helper__PSET02__HACK__DropStmt
    (TTSO_Tracer&                              tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   Helper__PSET02__HACK__CloseStmt
    (TTSO_Tracer&                             tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   Helper__PSET02__HACK__UnprepareStmt
    (TTSO_Tracer&                              tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__StmtHandle* pStmtHandle);

  static void
   Helper__PSET02__HACK__CommitTr
    (TTSO_Tracer&                            tracer,
     remote_fb_connector_type*               pConnector,
     remote_fb::handles::RemoteFB__TrHandle* pTrHandle);

  static void
   Helper__PSET02__HACK__CloseBlob
    (TTSO_Tracer&                              tracer,
     remote_fb_connector_type*                 pConnector,
     remote_fb::handles::RemoteFB__BlobHandle* pBlobHandle);

 public:
  static bool checkValue__I2
               (TTSO_Tracer&           tracer,
                short                  actualSqlInd,
                db_obj::t_dbvalue__i2  actualSqlValue,
                short                  expectedSqlInd,
                db_obj::t_dbvalue__i2  expectedSqlValue);

  static bool checkValue__I4
               (TTSO_Tracer&           tracer,
                short                  actualSqlInd,
                db_obj::t_dbvalue__i4  actualSqlValue,
                short                  expectedSqlInd,
                db_obj::t_dbvalue__i4  expectedSqlValue);

  static bool checkValue__I8
               (TTSO_Tracer&           tracer,
                short                  actualSqlInd,
                db_obj::t_dbvalue__i8  actualSqlValue,
                short                  expectedSqlInd,
                db_obj::t_dbvalue__i8  expectedSqlValue);

  static bool checkValue__R4
               (TTSO_Tracer&           tracer,
                short                  actualSqlInd,
                db_obj::t_dbvalue__r4  actualSqlValue,
                short                  expectedSqlInd,
                db_obj::t_dbvalue__r4  expectedSqlValue);

  static bool checkValue__R8
               (TTSO_Tracer&           tracer,
                short                  actualSqlInd,
                db_obj::t_dbvalue__r8  actualSqlValue,
                short                  expectedSqlInd,
                db_obj::t_dbvalue__r8  expectedSqlValue);

  static bool checkValue__TIME
               (TTSO_Tracer&            tracer,
                short                   actualSqlInd,
                isc_api::t_ibp_isc_time actualSqlValue,
                short                   expectedSqlInd,
                isc_api::t_ibp_isc_time expectedSqlValue);

  static bool checkValue__DATE
               (TTSO_Tracer&            tracer,
                short                   actualSqlInd,
                isc_api::t_ibp_isc_date actualSqlValue,
                short                   expectedSqlInd,
                isc_api::t_ibp_isc_date expectedSqlValue);

  static bool checkValue__TIMESTAMP
               (TTSO_Tracer&                        tracer,
                short                               actualSqlInd,
                const isc_api::t_ibp_isc_timestamp& actualSqlValue,
                short                               expectedSqlInd,
                const isc_api::t_ibp_isc_timestamp& expectedSqlValue);

  static bool checkValue__TEXT
               (TTSO_Tracer&                        tracer,
                short                               actualSqlInd,
                const structure::t_const_str_box&   actualSqlValue,
                short                               expectedSqlInd,
                const structure::t_const_str_box&   expectedSqlValue);

  static bool checkValue__BOOLEAN
               (TTSO_Tracer&             tracer,
                short                    actualSqlInd,
                isc_api::t_ibp_fb30_bool actualSqlValue,
                short                    expectedSqlInd,
                isc_api::t_ibp_fb30_bool expectedSqlValue);
};//class TestServices

////////////////////////////////////////////////////////////////////////////////
//TestServices - implementation

template<typename charT>
std::basic_string<charT>
 TestServices::PrepareStrForPrint(structure::t_basic_const_str_box<charT> const src)
{
 typedef structure::t_char_traits2<charT> _ct2;

 std::basic_string<charT> result;

 if(src.ptr==nullptr)
  return __STL_MOVE_VALUE(structure::tstr_to_tstr(&result,"NULL"));

 result+='\"';

 for(auto ch : src)
 {
  switch(ch)
  {
   case '\0':
    result+='\\';
    result+='0';
    break;

   case '\t':
    result+='\\';
    result+='t';
    break;

   case '\r':
    result+='\\';
    result+='r';
    break;

   case '\n':
    result+='\\';
    result+='n';
    break;

   default:
    result+=ch;
    break;
  }//switch
 }//for each ch

 result+='\"';

 return __STL_MOVE_VALUE(result);
}//PrepareStrForPrint

////////////////////////////////////////////////////////////////////////////////

inline TTSO_Tracer& operator << (TTSO_Tracer& tracer,const isc_api::t_ibp_isc_timestamp& x)
{
 return tracer<<L"{"<<x.timestamp_date<<L","<<x.timestamp_time<<L"}";
}//operator tracer<<isc_api::t_ibp_isc_timestamp

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif
