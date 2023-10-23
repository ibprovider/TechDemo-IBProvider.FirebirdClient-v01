////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__stmt__execute.h
//! \brief   ���������� �������. ������ ��� lazy_send-���������.
//! \author  Kovalenko Dmitry
//! \date    21.09.2016
#ifndef _remote_fb__api_p13_lazy_send__stmt__execute_H_
#define _remote_fb__api_p13_lazy_send__stmt__execute_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__execute.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__ExecuteStatement

/// <summary>
///  ���������� �������. ������ ��� lazy_send-���������.
/// </summary>
class RemoteFB__API_P13_LAZY_SEND__ExecuteStatement
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ExecuteStatement)
{
 private:
  using self_type=RemoteFB__API_P13_LAZY_SEND__ExecuteStatement;

  RemoteFB__API_P13_LAZY_SEND__ExecuteStatement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;
  using tr_data_type  =tr_handle_type::item_type;

 private:
  RemoteFB__API_P13_LAZY_SEND__ExecuteStatement();

  virtual ~RemoteFB__API_P13_LAZY_SEND__ExecuteStatement();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ���������� �������.
  /// </summary>
  //! \param[in] OpCtx
  //!  �������� ��������.
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. ���������� ���������.
  //! \param[in] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //! \param[in] pInXSQLDA
  //!  IN-��������� �������. Can be null.
  //! \param[in] pOutXSQLDA
  //!  OUT-��������� �������. Can be null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    const isc_api::XSQLDA_V1*       pInXSQLDA,
                    const isc_api::XSQLDA_V1*       pOutXSQLDA)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

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
                              const isc_api::XSQLDA_V1*     pInXSQLDA);

  static protocol::P_OBJCT helper__execute2
                             (RemoteFB__P13__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle,
                              const isc_api::XSQLDA_V1*     pInXSQLDA,
                              const isc_api::XSQLDA_V1*     pOutXSQLDA);
};//class RemoteFB__API_P13_LAZY_SEND__ExecuteStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
