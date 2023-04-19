////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__execute_m.h
//! \brief   The API function for a statement execution.
//! \author  Kovalenko Dmitry
//! \date    31.03.2023
#ifndef _remote_fb__api_p13__stmt__execute_m_H_
#define _remote_fb__api_p13__stmt__execute_m_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__execute_m.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ExecuteStatement_M

/// <summary>
///  The API function for a statement execution.
/// </summary>
class RemoteFB__API_P13__ExecuteStatement_M LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ExecuteStatement_M)
{
 private:
  typedef RemoteFB__API_P13__ExecuteStatement_M          self_type;

  RemoteFB__API_P13__ExecuteStatement_M(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type                    stmt_data_type;
  typedef tr_handle_type::item_type                      tr_data_type;

 private:
  RemoteFB__API_P13__ExecuteStatement_M();

  virtual ~RemoteFB__API_P13__ExecuteStatement_M();

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
                             (RemoteFB__P13__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle);

  static protocol::P_OBJCT helper__execute
                             (RemoteFB__P13__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle,
                              const RemoteFB__InMsg_v1*     pInMsg);

 private:
  static protocol::P_OBJCT helper__execute2
                             (RemoteFB__P13__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle,
                              const RemoteFB__InMsg_v1*     pInMsg,
                              const RemoteFB__OutMsg_v1*    pOutMsg);
};//class RemoteFB__API_P13__ExecuteStatement_M

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
