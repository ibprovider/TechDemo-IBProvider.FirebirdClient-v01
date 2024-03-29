////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api_p13__dsql__execute_immediate_m.h
//! \brief   The immediate execution of a statement.
//! \author  Kovalenko Dmitry
//! \date    13.04.2023
#ifndef _remote_fb__api_p13__dsql__execute_immediate_m_H_
#define _remote_fb__api_p13__dsql__execute_immediate_m_H_

#include "source/db_client/remote_fb/api/remote_fb__api__dsql__execute_immediate_m.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ExecuteImmediate_M

/// <summary>
///  The immediate execution of a statement.
/// </summary>
class RemoteFB__API_P13__ExecuteImmediate_M LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ExecuteImmediate_M)
{
 private:
  using self_type=RemoteFB__API_P13__ExecuteImmediate_M;

  RemoteFB__API_P13__ExecuteImmediate_M(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P13__ExecuteImmediate_M();

 ~RemoteFB__API_P13__ExecuteImmediate_M();

 public:
  /// The single instance of this class.
  static self_type Instance;

  /// <summary>
  ///  Immediate executing a statement.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of an operation.
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. The pointer to the handle of a transaction.
  //! \param[in] SQL_dialect
  //! \param[in] SQL_str
  //! \param[in] pInMsg
  //!  IN-parameters of a statement. Can be null.
  //! \param[in,out] pOutMsg
  //!  OUT-parameters of a statement. Can be null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    protocol::P_USHORT              SQL_dialect,
                    sql_str_box_type                SQL_str,
                    const RemoteFB__InMsg_v1*       pInMsg,
                    const RemoteFB__OutMsg_v1*      pOutMsg) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static protocol::P_OBJCT helper__execute
                             (RemoteFB__P13__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              protocol::P_USHORT            SQL_dialect,
                              sql_str_box_type              SQL_str);

  static protocol::P_OBJCT helper__execute2
                             (RemoteFB__P13__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              protocol::P_USHORT            SQL_dialect,
                              sql_str_box_type              SQL_str,
                              const RemoteFB__InMsg_v1*     pInMsg,
                              const RemoteFB__OutMsg_v1*    pOutMsg);
};//class RemoteFB__API_P13__ExecuteImmediate_M

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
