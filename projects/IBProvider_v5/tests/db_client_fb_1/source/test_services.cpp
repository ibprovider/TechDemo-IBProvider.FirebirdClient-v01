////////////////////////////////////////////////////////////////////////////////
//Charset: UTF8 without BOM!
#include <_pch_.h>
#pragma hdrstop

#include "source/test_services.h"
#include "source/db_client/remote_fb/ports/factories/inet/remote_fb__ports__factories__inet.h"
#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__static_cfg.h"
#include "source/db_obj/isc_base/isc_initialize_utils.h"
#include "source/ibp_global_objects_data__dlls.h"

#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestServices

void TestServices::Throw_WeWaitTheError()
{
 throw std::runtime_error("We wait the error!");
}//Throw_WeWaitTheError

//------------------------------------------------------------------------
void TestServices::Throw_UnknownProtocolVersion(remote_fb::protocol::P_PROTOCOL_VERSION v)
{
 structure::str_formatter fmsg("unknown connection protocol version: %1");

 fmsg<<(v&remote_fb::protocol::FB_PROTOCOL_MASK);

 throw std::runtime_error(fmsg.str());
}//Throw_UnknownProtocolVersion

//------------------------------------------------------------------------
std::wstring TestServices::BuildLocationString(const TTSO_GlobalContext* const pParams)
{
 assert(pParams);

 const wchar_t* c_templ;

 if(pParams->calc_expression("SRV<FB-3"))
  c_templ=L"inet4://[%1]/%2";
 else
  c_templ=L"inet://[%1]/%2";

 structure::wstr_formatter dbLocation(c_templ);

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 return dbLocation.str();
}//BuildLocationString

//------------------------------------------------------------------------
TestServices::winsock_dll_ptr
 TestServices::WinSock__LoadDLL(TTSO_Tracer&         tracer,
                                const wchar_t* const pDllName)
{
 assert(pDllName!=nullptr);

 tracer<<L"Load WinSock DLL ["<<pDllName<<L"] ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 winsock_dll_ptr spDLL;

 try
 {
  spDLL=ibp::IBP_GlobalObjectsData__DLLs::GetDLL(pDllName,0);

  _TSO_CHECK(spDLL!=nullptr);
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";

 return spDLL;
}//WinSock__LoadDLL

//------------------------------------------------------------------------
TestServices::winsock_provider_ptr
 TestServices::WinSock__CreateProvider(TTSO_Tracer&            tracer,
                                       winsock_dll_type* const pDLL)
{
 assert(pDLL!=nullptr);

 tracer<<L"Create WinSock provider ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 winsock_provider_ptr  spProvider;

 try
 {
  spProvider=winsock_provider_type::create(pDLL);

  _TSO_CHECK(spProvider!=nullptr);
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";

 return spProvider;
}//WinSock__CreateProvider

//------------------------------------------------------------------------
TestServices::winsock_provider_ptr
 TestServices::WinSock__CreateProvider__STD(TTSO_Tracer& tracer)
{
 const winsock_dll_ptr spDLL
  =WinSock__LoadDLL(tracer,remote_fb_inet_stream::RemoteFB__INET_StaticCfg::c_WinSockDllName);

 return WinSock__CreateProvider(tracer,spDLL);
}//WinSock__CreateProvider__STD

////////////////////////////////////////////////////////////////////////////////

TestServices::remote_fb_inet_socket_ptr
 TestServices::RemoteFB_INET_Socket__Connect2(TTSO_Tracer&                 tracer,
                                              winsock_provider_type* const pProvider,
                                              int                    const socketFamily,
                                              const wchar_t*         const ucs2_host,
                                              const wchar_t*         const ucs2_port)
{
 assert(pProvider!=nullptr);

 tracer<<L"Connect2 RemoteFB__INET_Socket to ["<<ucs2_host<<L"] [family: "<<socketFamily<<"] ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 remote_fb_inet_socket_ptr spSocket;

 try
 {
  spSocket
   =remote_fb_inet_socket_type::Connect_v2
     (pProvider,
      socketFamily,
      ucs2_host,
      ucs2_port);

  _TSO_CHECK(spSocket!=nullptr);
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";

 return spSocket;
}//RemoteFB_INET_Socket__Connect2

////////////////////////////////////////////////////////////////////////////////

TestServices::remote_fb_inet_port_ptr
 TestServices::RemoteFB_INET_Port__ConnectToDatabase
                                           (TTSO_Tracer&         tracer,
                                            int            const socketFamily,
                                            wstr_box_type  const ucs2_host,
                                            wstr_box_type  const ucs2_port,
                                            wstr_box_type  const ucs2_database_name,
                                            const dbprops_type&  params)
{
 tracer<<L"RemoteFB__INET_Port ConnectToDatabase ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 remote_fb_inet_port_ptr spPort;

 try
 {
  const remote_fb::RemoteFB__PortPtr
   ptr
    =remote_fb_inet_factory::RemoteFB__PortFactory__INET::ConnectToDatabase
       (socketFamily,
        ucs2_host,
        ucs2_port,
        ucs2_database_name,
        params);

  _TSO_CHECK(ptr!=nullptr);

  spPort=dynamic_cast<remote_fb_inet_port_type*>(ptr.ptr());

  _TSO_CHECK(spPort!=nullptr);
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";

 return spPort;
}//RemoteFB_INET_Port__ConnectToDatabase

////////////////////////////////////////////////////////////////////////////////

TestServices::remote_fb_inet_port_ptr
 TestServices::RemoteFB_INET_Port__CreateDatabase
                                           (TTSO_Tracer&         tracer,
                                            int            const socketFamily,
                                            const wchar_t* const ucs2_host,
                                            const wchar_t* const ucs2_port,
                                            const wchar_t* const ucs2_database_name,
                                            const dbprops_type&  params)
{
 tracer<<L"RemoteFB__INET_Port CreateDatabase ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 remote_fb_inet_port_ptr spPort;

 try
 {
  const remote_fb::RemoteFB__PortPtr
   ptr
    =remote_fb_inet_factory::RemoteFB__PortFactory__INET::CreateDatabase
      (socketFamily,
       ucs2_host,
       ucs2_port,
       ucs2_database_name,
       params);

  _TSO_CHECK(ptr!=nullptr);

  spPort=dynamic_cast<remote_fb_inet_port_type*>(ptr.ptr());

  _TSO_CHECK(spPort!=nullptr);
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";

 return spPort;
}//RemoteFB_INET_Port__CreateDatabase

////////////////////////////////////////////////////////////////////////////////

TestServices::remote_fb_connector_ptr
 TestServices::RemoteFB_Connector__ConnectToDatabase(TTSO_Tracer&        tracer,
                                                     const dbprops_type& params,
                                                     cns_type&           cns)
{
 tracer<<L"RemoteFB__Connector::ConnectToDatabase ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 remote_fb_connector_ptr spConnector;

 try
 {
  spConnector
   =remote_fb_connector_type::ConnectToDatabase
     (params,
      cns);

  _TSO_CHECK(spConnector!=nullptr);
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";

 return spConnector;
}//RemoteFB_Connector__ConnectToDatabase

//-------------------------------------------------------------------------
TestServices::remote_fb_connector_ptr
 TestServices::RemoteFB_Connector__CreateDatabase(TTSO_Tracer&        tracer,
                                                  const dbprops_type& params,
                                                  cns_type&           cns)
{
 tracer<<L"RemoteFB__Connector::CreateDatabase ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 remote_fb_connector_ptr spConnector;

 try
 {
  spConnector
   =remote_fb_connector_type::CreateDatabase
     (params,
      cns);

  _TSO_CHECK(spConnector!=nullptr);
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";

 return spConnector;
}//RemoteFB_Connector__CreateDatabase

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__DetachDatabase
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::DetachDatabase ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->DetachDatabase(); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__DetachDatabase

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__DropDatabase
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::DropDatabase ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->DropDatabase(); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__DropDatabase

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__GetDatabaseInfo
                                      (TTSO_Tracer&                     tracer,
                                       remote_fb_connector_type*        pConnector,
                                       unsigned short                   Incornation,
                                       unsigned short                   cItems,
                                       const unsigned char*             pItems,
                                       remote_fb::RemoteFB__InfoBuffer& ResultBuffer)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::GetDatabaseInfo ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->GetDatabaseInfo
   (Incornation,
    cItems,
    pItems,
    ResultBuffer);//throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__GetDatabaseInfo

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StartTransaction
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector,
                                        remote_fb_tr_handle_type* const pTrHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StartTransaction ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->StartTransaction
   (pTrHandle,
    0,
    nullptr); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__StartTransaction

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StartTransaction
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector,
                                        remote_fb_tr_handle_type* const pTrHandle,
                                        size_t                    const tpb_length,
                                        const unsigned char*      const tpb)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StartTransaction ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->StartTransaction
   (pTrHandle,
    tpb_length,
    tpb); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__StartTransaction

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__PrepareTransaction
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector,
                                        remote_fb_tr_handle_type* const pTrHandle,
                                        size_t                    const data_length,
                                        const void*               const data)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::PrepareTransaction ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->PrepareTransaction
   (pTrHandle,
    data_length,
    data); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__PrepareTransaction

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__Rollback
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector,
                                        remote_fb_tr_handle_type* const pTrHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::Rollback ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->Rollback(pTrHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__Rollback

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__RollbackRetaining
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector,
                                        remote_fb_tr_handle_type* const pTrHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::RollbackRetaining ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->RollbackRetaining(pTrHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__RollbackRetaining

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__Commit
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector,
                                        remote_fb_tr_handle_type* const pTrHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::Commit ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->Commit(pTrHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__Commit

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__CommitRetaining
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type* const pConnector,
                                        remote_fb_tr_handle_type* const pTrHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::CommitRetaining ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->CommitRetaining(pTrHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__CommitRetaining

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__ExecuteImmediate
                                       (TTSO_Tracer&                    tracer,
                                        remote_fb_connector_type*       pConnector,
                                        db_obj::t_db_operation_context& op_ctx,
                                        remote_fb_tr_handle_type*       pTrHandle,
                                        remote_fb::protocol::P_USHORT   SQL_Dialect,
                                        structure::t_const_str_box      SQL_str,
                                        const isc_api::XSQLDA_V1*       pInXSQLDA,
                                        const isc_api::XSQLDA_V1*       pOutXSQLDA)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::ExecuteImmediate ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->ExecuteImmediate
   (op_ctx,
    pTrHandle,
    SQL_Dialect,
    SQL_str,
    pInXSQLDA,
    pOutXSQLDA); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__ExecuteImmediate

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtAllocate
                                       (TTSO_Tracer&                      tracer,
                                        remote_fb_connector_type*   const pConnector,
                                        remote_fb_stmt_handle_type* const pStmtHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtAllocate ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->StmtAllocate(pStmtHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__StmtAllocate

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtDrop
                                       (TTSO_Tracer&                      tracer,
                                        remote_fb_connector_type*   const pConnector,
                                        remote_fb_stmt_handle_type* const pStmtHandle,
                                        const wchar_t*              const stmtSign)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtDrop "<<stmtSign<<L"...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->StmtDrop(pStmtHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__StmtDrop

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtClose
                                       (TTSO_Tracer&                      tracer,
                                        remote_fb_connector_type*   const pConnector,
                                        remote_fb_stmt_handle_type* const pStmtHandle,
                                        const wchar_t*              const stmtSign)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtClose "<<stmtSign<<"...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->StmtClose(pStmtHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__StmtClose

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtClose
                                       (remote_fb_connector_type*   const pConnector,
                                        remote_fb_stmt_handle_type* const pStmtHandle)
{
 assert(pConnector);

 pConnector->StmtClose(pStmtHandle); //throw
}//RemoteFB_Connector__StmtClose

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtPrepare
                             (TTSO_Tracer&                        tracer,
                              remote_fb_connector_type*     const pConnector,
                              db_obj::t_db_operation_context&     opCtx,
                              remote_fb_tr_handle_type*     const pTrHandle,
                              remote_fb_stmt_handle_type*   const pStmtHandle,
                              remote_fb::protocol::P_USHORT const SQL_dialect,
                              structure::t_const_str_box    const SQL_str)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtPrepare ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  unsigned long iscStmtTypeID=0;

  pConnector->StmtPrepare
   (opCtx,
    pTrHandle,
    pStmtHandle,
    SQL_dialect,
    SQL_str,
    &iscStmtTypeID); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__StmtPrepare

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtPrepare
                             (remote_fb_connector_type*     const pConnector,
                              db_obj::t_db_operation_context&     opCtx,
                              remote_fb_tr_handle_type*     const pTrHandle,
                              remote_fb_stmt_handle_type*   const pStmtHandle,
                              remote_fb::protocol::P_USHORT const SQL_dialect,
                              structure::t_const_str_box    const SQL_str)
{
 assert(pConnector);

 unsigned long iscStmtTypeID=0;

 pConnector->StmtPrepare
  (opCtx,
   pTrHandle,
   pStmtHandle,
   SQL_dialect,
   SQL_str,
   &iscStmtTypeID); //throw
}//RemoteFB_Connector__StmtPrepare

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__GetColumns
                             (TTSO_Tracer&                    tracer,
                              remote_fb_connector_type*       pConnector,
                              db_obj::t_db_operation_context& opCtx,
                              remote_fb_stmt_handle_type*     pStmtHandle,
                              isc_api::XSQLDA_V1*             xsqlda)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::GetColumns ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->GetColumns
   (opCtx,
    pStmtHandle,
    xsqlda); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__GetColumns

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__GetParameters
                             (TTSO_Tracer&                    tracer,
                              remote_fb_connector_type*       pConnector,
                              db_obj::t_db_operation_context& opCtx,
                              remote_fb_stmt_handle_type*     pStmtHandle,
                              isc_api::XSQLDA_V1*             xsqlda)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::GetParameters ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->GetParameters
   (opCtx,
    pStmtHandle,
    xsqlda); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__GetParameters

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__GetStatementInfo
                             (TTSO_Tracer&                     tracer,
                              remote_fb_connector_type*        pConnector,
                              db_obj::t_db_operation_context&  opCtx,
                              remote_fb_stmt_handle_type*      pStmtHandle,
                              unsigned short                   Incornation,
                              unsigned short                   cItems,
                              const unsigned char*             pItems,
                              remote_fb::RemoteFB__InfoBuffer& ResultBuffer)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::GetColumns ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->GetStatementInfo
   (opCtx,
    pStmtHandle,
    Incornation,
    cItems,
    pItems,
    ResultBuffer); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__GetStatementInfo

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtExecute
                             (TTSO_Tracer&                      tracer,
                              remote_fb_connector_type*   const pConnector,
                              db_obj::t_db_operation_context&   op_ctx,
                              remote_fb_tr_handle_type*   const pTrHandle,
                              remote_fb_stmt_handle_type* const pStmtHandle,
                              const isc_api::XSQLDA_V1*   const pInXSQLDA,
                              const isc_api::XSQLDA_V1*   const pOutXSQLDA)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtExecute ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->StmtExecute
   (op_ctx,
    pTrHandle,
    pStmtHandle,
    pInXSQLDA,
    pOutXSQLDA); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__StmtExecute

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtExecute
                             (remote_fb_connector_type*   const pConnector,
                              db_obj::t_db_operation_context&   op_ctx,
                              remote_fb_tr_handle_type*   const pTrHandle,
                              remote_fb_stmt_handle_type* const pStmtHandle,
                              const isc_api::XSQLDA_V1*   const pInXSQLDA,
                              const isc_api::XSQLDA_V1*   const pOutXSQLDA)
{
 assert(pConnector);

 pConnector->StmtExecute
  (op_ctx,
   pTrHandle,
   pStmtHandle,
   pInXSQLDA,
   pOutXSQLDA); //throw
}//RemoteFB_Connector__StmtExecute

//-------------------------------------------------------------------------
bool TestServices::RemoteFB_Connector__StmtFetch
                             (TTSO_Tracer&                      tracer,
                              remote_fb_connector_type*   const pConnector,
                              db_obj::t_db_operation_context&   opCtx,
                              remote_fb_stmt_handle_type* const pStmtHandle,
                              const isc_api::XSQLDA_V1*   const pOutXSQLDA)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtFetch ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 bool resultValue=false;

 try
 {
  resultValue
   =pConnector->StmtFetch
     (opCtx,
      pStmtHandle,
      pOutXSQLDA); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK ["<<resultValue<<L"]";

 return resultValue;
}//RemoteFB_Connector__StmtFetch

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtFetch_ToRow
                             (TTSO_Tracer&                      tracer,
                              remote_fb_connector_type*   const pConnector,
                              db_obj::t_db_operation_context&   opCtx,
                              remote_fb_stmt_handle_type* const pStmtHandle,
                              const isc_api::XSQLDA_V1*   const pOutXSQLDA)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtFetch ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 bool fetchResult=false;

 try
 {
  fetchResult
   =pConnector->StmtFetch
     (opCtx,
      pStmtHandle,
      pOutXSQLDA); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK ["<<fetchResult<<L"]";

 if(!fetchResult)
  throw std::runtime_error("Problem with fetch from resultSet. We expected get the record!");
}//RemoteFB_Connector__StmtFetch_ToRow

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtFetch_ToRow
                             (remote_fb_connector_type*   const pConnector,
                              db_obj::t_db_operation_context&   opCtx,
                              remote_fb_stmt_handle_type* const pStmtHandle,
                              const isc_api::XSQLDA_V1*   const pOutXSQLDA)
{
 assert(pConnector);

 const bool fetchResult
  =pConnector->StmtFetch
    (opCtx,
     pStmtHandle,
     pOutXSQLDA); //throw

 if(!fetchResult)
  throw std::runtime_error("Problem with fetch from resultSet. We expected get the record!");
}//RemoteFB_Connector__StmtFetch_ToRow

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtFetch_ToEOF
                             (TTSO_Tracer&                      tracer,
                              remote_fb_connector_type*   const pConnector,
                              db_obj::t_db_operation_context&   opCtx,
                              remote_fb_stmt_handle_type* const pStmtHandle,
                              const isc_api::XSQLDA_V1*   const pOutXSQLDA)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::StmtFetch ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 bool fetchResult=false;

 try
 {
  fetchResult
   =pConnector->StmtFetch
     (opCtx,
      pStmtHandle,
      pOutXSQLDA); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK ["<<fetchResult<<L"]";

 if(fetchResult)
  throw std::runtime_error("Problem with fetch from resultSet. We expected get the EOF!");
}//RemoteFB_Connector__StmtFetch_ToEOF

//-------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__StmtFetch_ToEOF
                             (remote_fb_connector_type*   const pConnector,
                              db_obj::t_db_operation_context&   opCtx,
                              remote_fb_stmt_handle_type* const pStmtHandle,
                              const isc_api::XSQLDA_V1*   const pOutXSQLDA)
{
 assert(pConnector);

 const bool fetchResult
  =pConnector->StmtFetch
    (opCtx,
     pStmtHandle,
     pOutXSQLDA); //throw

 if(fetchResult)
  throw std::runtime_error("Problem with fetch from resultSet. We expected get the EOF!");
}//RemoteFB_Connector__StmtFetch_ToEOF

////////////////////////////////////////////////////////////////////////////////

void TestServices::RemoteFB_Connector__OpenBlob
                                           (TTSO_Tracer&                      tracer,
                                            remote_fb_connector_type*   const pConnector,
                                            remote_fb_tr_handle_type*   const pTrHandle,
                                            remote_fb_blob_handle_type* const pBlobHandle,
                                            const db_obj::DB_IBBLOBID&        blobID)
{
 assert(pConnector);
 assert(pTrHandle);
 assert(pBlobHandle);

 tracer<<L"RemoteFB__Connector::OpenBlob ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->OpenBlob
   (pTrHandle,
    pBlobHandle,
    blobID); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__OpenBlob

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__CreateBlob
                                           (TTSO_Tracer&                      tracer,
                                            remote_fb_connector_type*   const pConnector,
                                            remote_fb_tr_handle_type*   const pTrHandle,
                                            remote_fb_blob_handle_type* const pBlobHandle,
                                            db_obj::DB_IBBLOBID*        const pBlobID)
{
 assert(pConnector);
 assert(pTrHandle);
 assert(pBlobHandle);
 assert(pBlobID);

 tracer<<L"RemoteFB__Connector::CreateBlob ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->CreateBlob
   (pTrHandle,
    pBlobHandle,
    pBlobID,
    /*szBPB*/0,
    /*pBPB*/nullptr); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__CreateBlob

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__CreateBlob
                         (TTSO_Tracer&                               tracer,
                          remote_fb_connector_type*            const pConnector,
                          remote_fb_tr_handle_type*            const pTrHandle,
                          remote_fb_blob_handle_type*          const pBlobHandle,
                          db_obj::DB_IBBLOBID*                 const pBlobID,
                           size_t                              const szBPB,
                           const remote_fb::protocol::P_UCHAR* const pBPB)
{
 assert(pConnector);
 assert(pTrHandle);
 assert(pBlobHandle);
 assert(pBlobID);

 tracer<<L"RemoteFB__Connector::CreateBlob ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->CreateBlob
   (pTrHandle,
    pBlobHandle,
    pBlobID,
    szBPB,
    pBPB); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__CreateBlob

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__CloseBlob
                                           (TTSO_Tracer&                      tracer,
                                            remote_fb_connector_type*   const pConnector,
                                            remote_fb_blob_handle_type* const pBlobHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::CloseBlob ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->CloseBlob(pBlobHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__CloseBlob

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__CancelBlob
                                           (TTSO_Tracer&                      tracer,
                                            remote_fb_connector_type*   const pConnector,
                                            remote_fb_blob_handle_type* const pBlobHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::CancelBlob ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->CancelBlob(pBlobHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__CancelBlob

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__GetBlobInfo
                                           (TTSO_Tracer&                      tracer,
                                            remote_fb_connector_type*   const pConnector,
                                            remote_fb_blob_handle_type* const pBlobHandle,
                                            unsigned short              const cItems,
                                            const unsigned char*        const pItems,
                                            remote_fb::RemoteFB__InfoBuffer&  ResultBuffer)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::GetBlobInfo ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->GetBlobInfo
   (pBlobHandle,
    cItems,
    pItems,
    ResultBuffer); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK";
}//RemoteFB_Connector__GetBlobInfo

//------------------------------------------------------------------------------
bool TestServices::RemoteFB_Connector__ReadBlob(TTSO_Tracer&                      tracer,
                                                remote_fb_connector_type*   const pConnector,
                                                remote_fb_blob_handle_type* const pBlobHandle,
                                                size_t                      const cbBuffer,
                                                void*                       const pvBuffer,
                                                size_t*                     const pcbActualReaded)
{
 assert(pConnector);
 assert(pcbActualReaded);

 assert(cbBuffer==0 || pvBuffer!=nullptr);

 CHECK_WRITE_PTR(pvBuffer,cbBuffer);

 tracer<<L"RemoteFB__Connector::ReadBlob(cbBuffer: "<<cbBuffer<<L") ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 bool resultValue;

 try
 {
  resultValue
   =pConnector->ReadBlob
     (pBlobHandle,
      cbBuffer,
      pvBuffer,
      pcbActualReaded); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK. ActualReaded: "<<(*pcbActualReaded)<<L". ResultValue: "<<resultValue<<L".";

 return resultValue;
}//RemoteFB_Connector__ReadBlob

//------------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__WriteBlob(TTSO_Tracer&                      tracer,
                                                 remote_fb_connector_type*   const pConnector,
                                                 remote_fb_blob_handle_type* const pBlobHandle,
                                                 size_t                      const cbBuffer,
                                                 const void*                 const pvBuffer)
{
 assert(pConnector);

 assert(cbBuffer==0 || pvBuffer!=nullptr);

 CHECK_READ_PTR(pvBuffer,cbBuffer);

 tracer<<L"RemoteFB__Connector::WriteBlob(cbBuffer: "<<cbBuffer<<L") ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->WriteBlob
   (pBlobHandle,
    cbBuffer,
    pvBuffer); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK.";
}//RemoteFB_Connector__WriteBlob

//------------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__FlushBlob(TTSO_Tracer&                      tracer,
                                                 remote_fb_connector_type*   const pConnector,
                                                 remote_fb_blob_handle_type* const pBlobHandle)
{
 assert(pConnector);

 tracer<<L"RemoteFB__Connector::FlushBlob ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->FlushBlob(pBlobHandle); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK.";
}//RemoteFB_Connector__FlushBlob

////////////////////////////////////////////////////////////////////////////////

void TestServices::RemoteFB_Connector__PutArraySlice
                                           (TTSO_Tracer&                    tracer,
                                            remote_fb_connector_type* const pConnector,
                                            db_obj::t_db_operation_context& op_ctx,
                                            remote_fb_tr_handle_type* const pTrHandle,
                                            db_obj::DB_IBARRAYID*     const pArrayID,
                                            size_t                    const szArraySDL,
                                            const unsigned char*      const pArraySDL,
                                            size_t                    const szArrayData,
                                            const void*               const pArrayData)
{
 assert(pConnector);
 assert(pTrHandle);
 assert(pArrayID);

 tracer<<L"RemoteFB__Connector::PutArraySlice ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->PutArraySlice
   (op_ctx,
    pTrHandle,
    pArrayID,
    szArraySDL,
    pArraySDL,
    szArrayData,
    pArrayData); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK.";
}//RemoteFB_Connector__PutArraySlice

//------------------------------------------------------------------------
void TestServices::RemoteFB_Connector__GetArraySlice
                                           (TTSO_Tracer&                    tracer,
                                            remote_fb_connector_type* const pConnector,
                                            db_obj::t_db_operation_context& op_ctx,
                                            remote_fb_tr_handle_type* const pTrHandle,
                                            const db_obj::DB_IBARRAYID&     ArrayID,
                                            size_t                    const szArraySDL,
                                            const unsigned char*      const pArraySDL,
                                            size_t                    const szArrayData,
                                            void*                     const pArrayData)
{
 assert(pConnector);
 assert(pTrHandle);

 tracer<<L"RemoteFB__Connector::GetArraySlice ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  pConnector->GetArraySlice
   (op_ctx,
    pTrHandle,
    ArrayID,
    szArraySDL,
    pArraySDL,
    szArrayData,
    pArrayData); //throw
 }
 catch(...)
 {
  tracer<<L" FAILED";

  throw;
 }//catch

 tracer<<L"OK.";
}//RemoteFB_Connector__GetArraySlice

////////////////////////////////////////////////////////////////////////////////

void TestServices::XSQLDA_check_sqld(TTSO_Tracer&                    tracer,
                                     const isc_api::XSQLDA_V1* const xsqlda,
                                     short                     const sqld)
{
 assert(xsqlda);

 tracer<<L"Check XSQLDA_V1::sqld ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  if(xsqlda->sqld!=sqld)
  {
   structure::str_formatter fmsg("incorrect XSQLDA_V1::xsqld: %1. Expected: %2");

   fmsg<<xsqlda->sqld<<sqld;

   throw std::runtime_error(fmsg.str());
  }//if
 }
 catch(...)
 {
  tracer<<L" INCORRECT";

  throw;
 }//catch

 tracer<<L"OK: "<<sqld;
}//XSQLDA_check_sqld

/////////////////////////////////////////////////////////////////////////////////

void TestServices::XSQLVAR_check_sqltype(TTSO_Tracer&                     tracer,
                                         const isc_api::XSQLVAR_V1* const xsqlvar,
                                         short                      const sqltype)
{
 assert(xsqlvar);

 tracer<<L"Check XSQLVAR_V1::sqltype ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  if(xsqlvar->sqltype!=sqltype)
  {
   structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqltype: %1. Expected: %2");

   fmsg<<xsqlvar->sqltype<<sqltype;

   throw std::runtime_error(fmsg.str());
  }//if
 }
 catch(...)
 {
  tracer<<L" INCORRECT";

  throw;
 }//catch

 tracer<<L"OK: "<<sqltype;
}//XSQLVAR_check_sqltype

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqlsubtype(TTSO_Tracer&                     tracer,
                                            const isc_api::XSQLVAR_V1* const xsqlvar,
                                            short                      const sqlsubtype)
{
 assert(xsqlvar);

 tracer<<L"Check XSQLVAR_V1::sqlsubtype ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  if(xsqlvar->sqlsubtype!=sqlsubtype)
  {
   structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlsubtype: %1. Expected: %2");

   fmsg<<xsqlvar->sqlsubtype<<sqlsubtype;

   throw std::runtime_error(fmsg.str());
  }//if
 }
 catch(...)
 {
  tracer<<L" INCORRECT";

  throw;
 }//catch

 tracer<<L"OK: "<<sqlsubtype;
}//XSQLVAR_check_sqlsubtype

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqlscale(TTSO_Tracer&                     tracer,
                                          const isc_api::XSQLVAR_V1* const xsqlvar,
                                          short                      const sqlscale)
{
 assert(xsqlvar);

 tracer<<L"Check XSQLVAR_V1::sqlscale ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  if(xsqlvar->sqlscale!=sqlscale)
  {
   structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlscale: %1. Expected: %2");

   fmsg<<xsqlvar->sqlscale<<sqlscale;

   throw std::runtime_error(fmsg.str());
  }//if
 }
 catch(...)
 {
  tracer<<L" INCORRECT";

  throw;
 }//catch

 tracer<<L"OK: "<<sqlscale;
}//XSQLVAR_check_sqlscale

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqllen(TTSO_Tracer&                     tracer,
                                        const isc_api::XSQLVAR_V1* const xsqlvar,
                                        short                      const sqllen)
{
 assert(xsqlvar);

 tracer<<L"Check XSQLVAR_V1::sqlscale ...";

 TTSO_TracerAutoSend __auto_send(tracer);

 try
 {
  if(xsqlvar->sqllen!=sqllen)
  {
   structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqllen: %1. Expected: %2");

   fmsg<<xsqlvar->sqllen<<sqllen;

   throw std::runtime_error(fmsg.str());
  }//if
 }
 catch(...)
 {
  tracer<<L" INCORRECT";

  throw;
 }//catch

 tracer<<L"OK: "<<sqllen;
}//XSQLVAR_check_sqllen

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqlname(TTSO_Tracer&                     tracer,
                                         const isc_api::XSQLVAR_V1* const xsqlvar,
                                         str_box_type               const sqlname)
{
 assert(xsqlvar);

 {
  tracer<<L"Check XSQLVAR_V1::sqlname ...";

  TTSO_TracerAutoSend __auto_send(tracer);

  try
  {
   if(xsqlvar->sqlname_length!=0 && !(xsqlvar->sqlname_length>0 && xsqlvar->sqlname_length<=_DIM_(xsqlvar->sqlname)))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlname_length: %1.");

    fmsg<<xsqlvar->sqlname_length;

    throw std::runtime_error(fmsg.str());
   }//if

   if(!sqlname.equal(xsqlvar->sqlname,(size_t)xsqlvar->sqlname_length))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlname: [%1]. Expected: [%2].");

    fmsg<<str_box_type(xsqlvar->sqlname,(size_t)xsqlvar->sqlname_length)<<sqlname;

    throw std::runtime_error(fmsg.str());
   }//if
  }
  catch(...)
  {
   tracer<<L" INCORRECT";

   throw;
  }//catch

  tracer<<L"OK: ["<<sqlname<<L"]";
 }//local

 for(size_t i=(size_t)xsqlvar->sqlname_length;i!=_DIM_(xsqlvar->sqlname);++i)
 {
  if(xsqlvar->sqlname[i]!=' ')
  {
   tracer(tso_msg_warning,-1)
    <<L"Garbage in XSQLVAR_V1::sqlname"
    <<send;

   break;
  }//if
 }//for i
}//XSQLVAR_check_sqlname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_relname(TTSO_Tracer&                     tracer,
                                         const isc_api::XSQLVAR_V1* const xsqlvar,
                                         str_box_type               const relname)
{
 assert(xsqlvar);

 {
  tracer<<L"Check XSQLVAR_V1::relname ...";

  TTSO_TracerAutoSend __auto_send(tracer);

  try
  {
   if(xsqlvar->relname_length!=0 && !(xsqlvar->relname_length>0 && xsqlvar->relname_length<=_DIM_(xsqlvar->relname)))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::relname_length: %1.");

    fmsg<<xsqlvar->relname_length;

    throw std::runtime_error(fmsg.str());
   }//if

   if(!relname.equal(xsqlvar->relname,(size_t)xsqlvar->relname_length))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::relname: [%1]. Expected: [%2].");

    fmsg<<str_box_type(xsqlvar->relname,(size_t)xsqlvar->relname_length)<<relname;

    throw std::runtime_error(fmsg.str());
   }//if
  }
  catch(...)
  {
   tracer<<L" INCORRECT";

   throw;
  }//catch

  tracer<<L"OK: ["<<relname<<L"]";
 }//local

 for(size_t i=(size_t)xsqlvar->relname_length;i!=_DIM_(xsqlvar->relname);++i)
 {
  if(xsqlvar->relname[i]!=' ')
  {
   tracer(tso_msg_warning,-1)
    <<L"Garbage in XSQLVAR_V1::relname"
    <<send;

   break;
  }//if
 }//for i
}//XSQLVAR_check_relname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_ownname(TTSO_Tracer&                     tracer,
                                         const isc_api::XSQLVAR_V1* const xsqlvar,
                                         str_box_type               const ownname)
{
 assert(xsqlvar);

 {
  tracer<<L"Check XSQLVAR_V1::ownname ...";

  TTSO_TracerAutoSend __auto_send(tracer);

  try
  {
   if(xsqlvar->ownname_length!=0 && !(xsqlvar->ownname_length>0 && xsqlvar->ownname_length<=_DIM_(xsqlvar->ownname)))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::ownname_length: %1.");

    fmsg<<xsqlvar->ownname_length;

    throw std::runtime_error(fmsg.str());
   }//if

   if(!ownname.equal(xsqlvar->ownname,(size_t)xsqlvar->ownname_length))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::ownname: [%1]. Expected: [%2].");

    fmsg<<str_box_type(xsqlvar->ownname,(size_t)xsqlvar->ownname_length)<<ownname;

    throw std::runtime_error(fmsg.str());
   }//if
  }
  catch(...)
  {
   tracer<<L" INCORRECT";

   throw;
  }//catch

  tracer<<L"OK: ["<<ownname<<L"]";
 }//local

 for(size_t i=(size_t)xsqlvar->ownname_length;i!=_DIM_(xsqlvar->ownname);++i)
 {
  if(xsqlvar->ownname[i]!=' ')
  {
   tracer(tso_msg_warning,-1)
    <<L"Garbage in XSQLVAR_V1::ownname"
    <<send;

   break;
  }//if
 }//for i
}//XSQLVAR_check_ownname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_aliasname(TTSO_Tracer&                     tracer,
                                           const isc_api::XSQLVAR_V1* const xsqlvar,
                                           str_box_type               const aliasname)
{
 assert(xsqlvar);

 {
  tracer<<L"Check XSQLVAR_V1::aliasname ...";

  TTSO_TracerAutoSend __auto_send(tracer);

  try
  {
   if(xsqlvar->aliasname_length!=0 && !(xsqlvar->aliasname_length>0 && xsqlvar->aliasname_length<=_DIM_(xsqlvar->aliasname)))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::aliasname_length: %1.");

    fmsg<<xsqlvar->aliasname_length;

    throw std::runtime_error(fmsg.str());
   }//if

   if(!aliasname.equal(xsqlvar->aliasname,(size_t)xsqlvar->aliasname_length))
   {
    structure::str_formatter fmsg("incorrect XSQLVAR_V1::aliasname: [%1]. Expected: [%2].");

    fmsg<<str_box_type(xsqlvar->aliasname,(size_t)xsqlvar->aliasname_length)<<aliasname;

    throw std::runtime_error(fmsg.str());
   }//if
  }
  catch(...)
  {
   tracer<<L" INCORRECT";

   throw;
  }//catch

  tracer<<L"OK: ["<<aliasname<<L"]";
 }//local

 for(size_t i=(size_t)xsqlvar->aliasname_length;i!=_DIM_(xsqlvar->aliasname);++i)
 {
  if(xsqlvar->aliasname[i]!=' ')
  {
   tracer(tso_msg_warning,-1)
    <<L"Garbage in XSQLVAR_V1::aliasname"
    <<send;

   break;
  }//if
 }//for i
}//XSQLVAR_check_aliasname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check(TTSO_Tracer&                     tracer,
                                 const isc_api::XSQLVAR_V1* const xsqlvar,
                                 short                      const sqltype,
                                 short                      const sqlsubtype,
                                 short                      const sqlscale,
                                 short                      const sqllen,
                                 str_box_type               const sqlname,
                                 str_box_type               const relname,
                                 str_box_type               const ownname,
                                 str_box_type               const aliasname)
{
 XSQLVAR_check_sqltype
  (tracer,
   xsqlvar,
   sqltype);

 XSQLVAR_check_sqlsubtype
  (tracer,
   xsqlvar,
   sqlsubtype);

 XSQLVAR_check_sqlscale
  (tracer,
   xsqlvar,
   sqlscale);

 XSQLVAR_check_sqllen
  (tracer,
   xsqlvar,
   sqllen);

 XSQLVAR_check_sqlname
  (tracer,
   xsqlvar,
   sqlname);

 XSQLVAR_check_relname
  (tracer,
   xsqlvar,
   relname);

 XSQLVAR_check_ownname
  (tracer,
   xsqlvar,
   ownname);

 XSQLVAR_check_aliasname
  (tracer,
   xsqlvar,
   aliasname);
}//XSQLVAR_check

/////////////////////////////////////////////////////////////////////////////////

void TestServices::XSQLVAR_check_sqltype(const isc_api::XSQLVAR_V1* const xsqlvar,
                                         short                      const sqltype)
{
 assert(xsqlvar);

 if(xsqlvar->sqltype!=sqltype)
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqltype: %1. Expected: %2");

  fmsg<<xsqlvar->sqltype<<sqltype;

  throw std::runtime_error(fmsg.str());
 }//if
}//XSQLVAR_check_sqltype

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqlsubtype(const isc_api::XSQLVAR_V1* const xsqlvar,
                                            short                      const sqlsubtype)
{
 assert(xsqlvar);

 if(xsqlvar->sqlsubtype!=sqlsubtype)
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlsubtype: %1. Expected: %2");

  fmsg<<xsqlvar->sqlsubtype<<sqlsubtype;

  throw std::runtime_error(fmsg.str());
 }//if
}//XSQLVAR_check_sqlsubtype

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqlscale(const isc_api::XSQLVAR_V1* const xsqlvar,
                                          short                      const sqlscale)
{
 assert(xsqlvar);

 if(xsqlvar->sqlscale!=sqlscale)
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlscale: %1. Expected: %2");

  fmsg<<xsqlvar->sqlscale<<sqlscale;

  throw std::runtime_error(fmsg.str());
 }//if
}//XSQLVAR_check_sqlscale

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqllen(const isc_api::XSQLVAR_V1* const xsqlvar,
                                        short                      const sqllen)
{
 assert(xsqlvar);

 if(xsqlvar->sqllen!=sqllen)
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqllen: %1. Expected: %2");

  fmsg<<xsqlvar->sqllen<<sqllen;

  throw std::runtime_error(fmsg.str());
 }//if
}//XSQLVAR_check_sqllen

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_sqlname(const isc_api::XSQLVAR_V1* const xsqlvar,
                                         str_box_type               const sqlname)
{
 assert(xsqlvar);

 if(xsqlvar->sqlname_length!=0 && !(xsqlvar->sqlname_length>0 && xsqlvar->sqlname_length<_DIM_(xsqlvar->sqlname)))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlname_length: %1.");

  fmsg<<xsqlvar->sqlname_length;

  throw std::runtime_error(fmsg.str());
 }//if

 if(!sqlname.equal(xsqlvar->sqlname,(size_t)xsqlvar->sqlname_length))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::sqlname: [%1]. Expected: [%2].");

  fmsg<<str_box_type(xsqlvar->sqlname,(size_t)xsqlvar->sqlname_length)<<sqlname;

  throw std::runtime_error(fmsg.str());
 }//if

 for(size_t i=(size_t)xsqlvar->sqlname_length;i!=_DIM_(xsqlvar->sqlname);++i)
 {
  if(xsqlvar->sqlname[i]!=' ')
  {
   throw std::runtime_error("Garbage in XSQLVAR_V1::sqlname.");
  }//if
 }//for i
}//XSQLVAR_check_sqlname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_relname(const isc_api::XSQLVAR_V1* const xsqlvar,
                                         str_box_type               const relname)
{
 assert(xsqlvar);

 if(xsqlvar->relname_length!=0 && !(xsqlvar->relname_length>0 && xsqlvar->relname_length<_DIM_(xsqlvar->relname)))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::relname_length: %1.");

  fmsg<<xsqlvar->relname_length;

  throw std::runtime_error(fmsg.str());
 }//if

 if(!relname.equal(xsqlvar->relname,(size_t)xsqlvar->relname_length))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::relname: [%1]. Expected: [%2].");

  fmsg<<str_box_type(xsqlvar->relname,(size_t)xsqlvar->relname_length)<<relname;

  throw std::runtime_error(fmsg.str());
 }//if

 for(size_t i=(size_t)xsqlvar->relname_length;i!=_DIM_(xsqlvar->relname);++i)
 {
  if(xsqlvar->relname[i]!=' ')
  {
   throw std::runtime_error("Garbage in XSQLVAR_V1::relname.");
  }//if
 }//for i
}//XSQLVAR_check_relname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_ownname(const isc_api::XSQLVAR_V1* const xsqlvar,
                                         str_box_type               const ownname)
{
 assert(xsqlvar);

 if(xsqlvar->ownname_length!=0 && !(xsqlvar->ownname_length>0 && xsqlvar->ownname_length<_DIM_(xsqlvar->ownname)))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::ownname_length: %1.");

  fmsg<<xsqlvar->ownname_length;

  throw std::runtime_error(fmsg.str());
 }//if

 if(!ownname.equal(xsqlvar->ownname,(size_t)xsqlvar->ownname_length))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::ownname: [%1]. Expected: [%2].");

  fmsg<<str_box_type(xsqlvar->ownname,(size_t)xsqlvar->ownname_length)<<ownname;

  throw std::runtime_error(fmsg.str());
 }//if

 for(size_t i=(size_t)xsqlvar->ownname_length;i!=_DIM_(xsqlvar->ownname);++i)
 {
  if(xsqlvar->ownname[i]!=' ')
  {
   throw std::runtime_error("Garbage in XSQLVAR_V1::ownname.");
  }//if
 }//for i
}//XSQLVAR_check_ownname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check_aliasname(const isc_api::XSQLVAR_V1* const xsqlvar,
                                           str_box_type               const aliasname)
{
 assert(xsqlvar);

 if(xsqlvar->aliasname_length!=0 && !(xsqlvar->aliasname_length>0 && xsqlvar->aliasname_length<_DIM_(xsqlvar->aliasname)))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::aliasname_length: %1.");

  fmsg<<xsqlvar->aliasname_length;

  throw std::runtime_error(fmsg.str());
 }//if

 if(!aliasname.equal(xsqlvar->aliasname,(size_t)xsqlvar->aliasname_length))
 {
  structure::str_formatter fmsg("incorrect XSQLVAR_V1::aliasname: [%1]. Expected: [%2].");

  fmsg<<str_box_type(xsqlvar->aliasname,(size_t)xsqlvar->aliasname_length)<<aliasname;

  throw std::runtime_error(fmsg.str());
 }//if

 for(size_t i=(size_t)xsqlvar->aliasname_length;i!=_DIM_(xsqlvar->aliasname);++i)
 {
  if(xsqlvar->aliasname[i]!=' ')
  {
   throw std::runtime_error("Garbage in XSQLVAR_V1::aliasname.");
  }//if
 }//for i
}//XSQLVAR_check_aliasname

//------------------------------------------------------------------------
void TestServices::XSQLVAR_check(const isc_api::XSQLVAR_V1* const xsqlvar,
                                 short                      const sqltype,
                                 short                      const sqlsubtype,
                                 short                      const sqlscale,
                                 short                      const sqllen,
                                 str_box_type               const sqlname,
                                 str_box_type               const relname,
                                 str_box_type               const ownname,
                                 str_box_type               const aliasname)
{
 XSQLVAR_check_sqltype
  (xsqlvar,
   sqltype);

 XSQLVAR_check_sqlsubtype
  (xsqlvar,
   sqlsubtype);

 XSQLVAR_check_sqlscale
  (xsqlvar,
   sqlscale);

 XSQLVAR_check_sqllen
  (xsqlvar,
   sqllen);

 XSQLVAR_check_sqlname
  (xsqlvar,
   sqlname);

 XSQLVAR_check_relname
  (xsqlvar,
   relname);

 XSQLVAR_check_ownname
  (xsqlvar,
   ownname);

 XSQLVAR_check_aliasname
  (xsqlvar,
   aliasname);
}//XSQLVAR_check

/////////////////////////////////////////////////////////////////////////////////

void TestServices::HACK__DetachCn(TTSO_Tracer&                    tracer,
                                  remote_fb_connector_type* const pConnector)
{
 assert(pConnector);

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  {
   return Helper__PSET01__HACK__DetachCn
           (tracer,
            pConnector);
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
  {
   return Helper__PSET02__HACK__DetachCn
           (tracer,
            pConnector);
  }//case p13

  default:
  {
   assert(false);

   self_type::Throw_UnknownProtocolVersion(v);
  }//default
 }//switch
}//HACK__DetachCn

//------------------------------------------------------------------------
void TestServices::HACK__DropDb(TTSO_Tracer&                    tracer,
                                remote_fb_connector_type* const pConnector)
{
 assert(pConnector);

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  {
   return Helper__PSET01__HACK__DropDb
           (tracer,
            pConnector);
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
  {
   return Helper__PSET02__HACK__DropDb
           (tracer,
            pConnector);
  }//case p13

  default:
  {
   assert(false);

   self_type::Throw_UnknownProtocolVersion(v);
  }//default
 }//switch
}//HACK__DropDb

//------------------------------------------------------------------------
void TestServices::HACK__DropStmt(TTSO_Tracer&                                    tracer,
                                  remote_fb_connector_type*                 const pConnector,
                                  remote_fb::handles::RemoteFB__StmtHandle* const pStmtHandle)
{
 assert(pConnector);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_ID.has_value());

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  {
   return Helper__PSET01__HACK__DropStmt
           (tracer,
            pConnector,
            pStmtHandle);
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
  {
   return Helper__PSET02__HACK__DropStmt
           (tracer,
            pConnector,
            pStmtHandle);
  }//case p13

  default:
  {
   assert(false);

   self_type::Throw_UnknownProtocolVersion(v);
  }//default
 }//switch
}//HACK__DropStmt

//------------------------------------------------------------------------
void TestServices::HACK__CloseStmt(TTSO_Tracer&                                    tracer,
                                   remote_fb_connector_type*                 const pConnector,
                                   remote_fb::handles::RemoteFB__StmtHandle* const pStmtHandle)
{
 assert(pConnector);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_ID.has_value());

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  {
   return Helper__PSET01__HACK__CloseStmt
           (tracer,
            pConnector,
            pStmtHandle);
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
  {
   return Helper__PSET02__HACK__CloseStmt
           (tracer,
            pConnector,
            pStmtHandle);
  }//case p13

  default:
  {
   assert(false);

   self_type::Throw_UnknownProtocolVersion(v);
  }//default
 }//switch
}//HACK__CloseStmt

//------------------------------------------------------------------------
void TestServices::HACK__UnprepareStmt(TTSO_Tracer&                                    tracer,
                                       remote_fb_connector_type*                 const pConnector,
                                       remote_fb::handles::RemoteFB__StmtHandle* const pStmtHandle)
{
 assert(pConnector);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_ID.has_value());

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  {
   return Helper__PSET01__HACK__UnprepareStmt
           (tracer,
            pConnector,
            pStmtHandle);
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
  {
   return Helper__PSET02__HACK__UnprepareStmt
           (tracer,
            pConnector,
            pStmtHandle);
  }//case p13

  default:
  {
   assert(false);

   self_type::Throw_UnknownProtocolVersion(v);
  }//default
 }//switch
}//HACK__UnprepareStmt

//------------------------------------------------------------------------
void TestServices::HACK__CommitTr(TTSO_Tracer&                            tracer,
                                  remote_fb_connector_type*               pConnector,
                                  remote_fb::handles::RemoteFB__TrHandle* pTrHandle)
{
 assert(pConnector);
 assert(pTrHandle);
 assert(*pTrHandle);
 assert((*pTrHandle)->m_ID.has_value());

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  {
   return Helper__PSET01__HACK__CommitTr
           (tracer,
            pConnector,
            pTrHandle);
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
  {
   return Helper__PSET02__HACK__CommitTr
           (tracer,
            pConnector,
            pTrHandle);
  }//case p13

  default:
  {
   assert(false);

   self_type::Throw_UnknownProtocolVersion(v);
  }//default
 }//switch
}//HACK__CommitTr

//------------------------------------------------------------------------
void TestServices::HACK__CloseBlob(TTSO_Tracer&                              tracer,
                                   remote_fb_connector_type*                 pConnector,
                                   remote_fb::handles::RemoteFB__BlobHandle* pBlobHandle)
{
 assert(pConnector);
 assert(pBlobHandle);
 assert(*pBlobHandle);
 assert((*pBlobHandle)->m_ID.has_value());

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  {
   return Helper__PSET01__HACK__CloseBlob
           (tracer,
            pConnector,
            pBlobHandle);
  }//case p10, p11, p12

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
  {
   return Helper__PSET02__HACK__CloseBlob
           (tracer,
            pConnector,
            pBlobHandle);
  }//case p10, p11, p12

  default:
  {
   assert(false);

   self_type::Throw_UnknownProtocolVersion(v);
  }//default
 }//switch
}//HACK__CloseBlob

////////////////////////////////////////////////////////////////////////////////

bool TestServices::checkValue__I2(TTSO_Tracer&                 tracer,
                                  short                  const actualSqlInd,
                                  db_obj::t_dbvalue__i2  const actualSqlValue,
                                  short                  const expectedSqlInd,
                                  db_obj::t_dbvalue__i2  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [i2] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__I2

//------------------------------------------------------------------------
bool TestServices::checkValue__I4(TTSO_Tracer&                 tracer,
                                  short                  const actualSqlInd,
                                  db_obj::t_dbvalue__i4  const actualSqlValue,
                                  short                  const expectedSqlInd,
                                  db_obj::t_dbvalue__i4  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [i4] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__I4

//------------------------------------------------------------------------
bool TestServices::checkValue__I8(TTSO_Tracer&                 tracer,
                                  short                  const actualSqlInd,
                                  db_obj::t_dbvalue__i8  const actualSqlValue,
                                  short                  const expectedSqlInd,
                                  db_obj::t_dbvalue__i8  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [i8] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__I8

//------------------------------------------------------------------------
bool TestServices::checkValue__R4(TTSO_Tracer&                 tracer,
                                  short                  const actualSqlInd,
                                  db_obj::t_dbvalue__r4  const actualSqlValue,
                                  short                  const expectedSqlInd,
                                  db_obj::t_dbvalue__r4  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [r4] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__R4

//------------------------------------------------------------------------
bool TestServices::checkValue__R8(TTSO_Tracer&                 tracer,
                                  short                  const actualSqlInd,
                                  db_obj::t_dbvalue__r8  const actualSqlValue,
                                  short                  const expectedSqlInd,
                                  db_obj::t_dbvalue__r8  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [r8] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__R8

//------------------------------------------------------------------------
bool TestServices::checkValue__TIME(TTSO_Tracer&                   tracer,
                                    short                    const actualSqlInd,
                                    isc_api::t_ibp_isc_time  const actualSqlValue,
                                    short                    const expectedSqlInd,
                                    isc_api::t_ibp_isc_time  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [time] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__TIME

//------------------------------------------------------------------------
bool TestServices::checkValue__DATE(TTSO_Tracer&                   tracer,
                                    short                    const actualSqlInd,
                                    isc_api::t_ibp_isc_date  const actualSqlValue,
                                    short                    const expectedSqlInd,
                                    isc_api::t_ibp_isc_date  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [date] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__DATE

//------------------------------------------------------------------------
bool TestServices::checkValue__TIMESTAMP(TTSO_Tracer&                        tracer,
                                         short                               actualSqlInd,
                                         const isc_api::t_ibp_isc_timestamp& actualSqlValue,
                                         short                               expectedSqlInd,
                                         const isc_api::t_ibp_isc_timestamp& expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [timestamp] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__TIMESTAMP

//------------------------------------------------------------------------
bool TestServices::checkValue__TEXT(TTSO_Tracer&                        tracer,
                                    short                               actualSqlInd,
                                    const structure::t_const_str_box&   actualSqlValue,
                                    short                               expectedSqlInd,
                                    const structure::t_const_str_box&   expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [timestamp] (ind: "<<actualSqlInd<<L", "<<PrepareStrForPrint(actualSqlValue)<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue.equal(expectedSqlValue))
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(!actualSqlValue.equal(expectedSqlValue))
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<PrepareStrForPrint(actualSqlValue)
                          <<L". Expected: "<<PrepareStrForPrint(expectedSqlValue)<<L"."<<send;
 }//if

 return false;
}//checkValue__TEXT

//------------------------------------------------------------------------
bool TestServices::checkValue__BOOLEAN(TTSO_Tracer&                    tracer,
                                       short                     const actualSqlInd,
                                       isc_api::t_ibp_fb30_bool  const actualSqlValue,
                                       short                     const expectedSqlInd,
                                       isc_api::t_ibp_fb30_bool  const expectedSqlValue)
{
 for(;;)
 {
  tracer<<L"check value [boolean] (ind: "<<actualSqlInd<<L", "<<actualSqlValue<<L") ...";

  if(actualSqlInd==expectedSqlInd && actualSqlValue==expectedSqlValue)
  {
   tracer<<L"OK"<<send;

   return true;
  }

  tracer<<L"FAILED"<<send;

  break;
 }//for[ever]

 if(actualSqlInd!=expectedSqlInd)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect indicator: "<<actualSqlInd<<L". Expected: "<<expectedSqlInd<<L"."<<send;
 }//if

 if(actualSqlValue!=expectedSqlValue)
 {
  tracer(tso_msg_error,-1)<<L"Incorrect value: "<<actualSqlValue<<L". Expected: "<<expectedSqlValue<<L"."<<send;
 }//if

 return false;
}//checkValue__BOOLEAN

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
