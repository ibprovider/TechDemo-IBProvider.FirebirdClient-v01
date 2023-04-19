////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__execute.h
//! \brief   Выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__api_p13__stmt__execute_H_
#define _remote_fb__api_p13__stmt__execute_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__execute.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ExecuteStatement

/// <summary>
///  Выполнение запроса.
/// </summary>
class RemoteFB__API_P13__ExecuteStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ExecuteStatement)
{
 private:
  typedef RemoteFB__API_P13__ExecuteStatement            self_type;

  RemoteFB__API_P13__ExecuteStatement(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type                    stmt_data_type;
  typedef tr_handle_type::item_type                      tr_data_type;

 private:
  RemoteFB__API_P13__ExecuteStatement();

  virtual ~RemoteFB__API_P13__ExecuteStatement();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Выполнение запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. Дескриптор транзации.
  //! \param[in] pStmtHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //! \param[in] pInXSQLDA
  //!  IN-параметры запроса. Can be null.
  //! \param[in] pOutXSQLDA
  //!  OUT-параметры запроса. Can be null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    const isc_api::XSQLDA_V1*       pInXSQLDA,
                    const isc_api::XSQLDA_V1*       pOutXSQLDA)COMP_W000004_OVERRIDE_FINAL;

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
 private:
  static protocol::P_OBJCT helper__execute2
                             (RemoteFB__P13__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              stmt_handle_type*             pStmtHandle,
                              const isc_api::XSQLDA_V1*     pInXSQLDA,
                              const isc_api::XSQLDA_V1*     pOutXSQLDA);
};//class RemoteFB__API_P13__ExecuteStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
