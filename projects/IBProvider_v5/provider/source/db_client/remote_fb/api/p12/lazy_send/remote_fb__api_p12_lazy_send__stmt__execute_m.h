////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__execute_m.h
//! \brief   The API function for a statement execution. The version for a lazy_send-protocol.
//! \author  Kovalenko Dmitry
//! \date    12.04.2023
#ifndef _remote_fb__api_p12_lazy_send__stmt__execute_m_H_
#define _remote_fb__api_p12_lazy_send__stmt__execute_m_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__execute_m.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__ExecuteStatement_M

/// <summary>
///  The API function for a statement execution.
/// </summary>
class RemoteFB__API_P12_LAZY_SEND__ExecuteStatement_M LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ExecuteStatement_M)
{
 private:
  using self_type=RemoteFB__API_P12_LAZY_SEND__ExecuteStatement_M;

  RemoteFB__API_P12_LAZY_SEND__ExecuteStatement_M(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;
  using tr_data_type  =tr_handle_type::item_type;

 private:
  RemoteFB__API_P12_LAZY_SEND__ExecuteStatement_M();

  virtual ~RemoteFB__API_P12_LAZY_SEND__ExecuteStatement_M();

 public:
  /// The single instance of this class.
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  The execution of a statement.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of operation.
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. The descriptor of transaction.
  //! \param[in] pStmtHandle
  //!  Not null. The descriptor of statement. It must be a not null pointer on a not null value.
  //! \param[in] pInMsg
  //!  Input parameters of a statement. Can be null.
  //! \param[in] pOutMsg
  //!  Output parameters of a statement. Can be null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    const RemoteFB__InMsg_v1*       pInMsg,
                    const RemoteFB__OutMsg_v1*      pOutMsg) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static protocol::P_OBJCT helper__execute
                             (RemoteFB__P12__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle);

  static protocol::P_OBJCT helper__execute
                             (RemoteFB__P12__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle,
                              const RemoteFB__InMsg_v1*     pInMsg);

 private:
  static protocol::P_OBJCT helper__execute2
                             (RemoteFB__P12__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle,
                              const RemoteFB__InMsg_v1*     pInMsg,
                              const RemoteFB__OutMsg_v1*    pOutMsg);
};//class RemoteFB__API_P12_LAZY_SEND__ExecuteStatement_M

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
