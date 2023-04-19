////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13_lazy_send__stmt_helper.h
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    11.04.2023
#ifndef _remote_fb__p13_lazy_send__stmt_helper_H_
#define _remote_fb__p13_lazy_send__stmt_helper_H_

#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

#include "source/structure/ibp_buffer_view.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__StmtHelper

/// <summary>
///  Вспомогательный класс с кодом для работы с запросами.
/// </summary>
class RemoteFB__P13_LAZY_SEND__StmtHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P13_LAZY_SEND__StmtHelper   self_type;

 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle           tr_handle_type;
  typedef handles::RemoteFB__StmtHandle         stmt_handle_type;

  typedef tr_handle_type::item_type             tr_data_type;
  typedef stmt_handle_type::item_type           stmt_data_type;

  typedef structure::t_const_str_box            sql_str_box_type;

  typedef unsigned char                         byte_type;

 public:
  static protocol::P_OBJCT Execute__lazy_send
                             (RemoteFB__P13__SrvOperation&         serverOperation,
                              RemoteFB__ConnectorData*             pData,
                              tr_handle_type*                      pTrHandle,
                              stmt_handle_type*                    pStmtHandle,
                              RemoteFB__OpSvc__StmtExecuteData_v2* pStmtExecData);

  static protocol::P_OBJCT Execute2__lazy_send
                             (RemoteFB__P13__SrvOperation&         serverOperation,
                              RemoteFB__ConnectorData*             pData,
                              tr_handle_type*                      pTrHandle,
                              stmt_handle_type*                    pStmtHandle,
                              RemoteFB__OpSvc__StmtExecuteData_v2* pStmtExecData);

 public:
  /// <summary>
  ///  Loading the next block with rows.
  /// </summary>
  //! \param[in] serverOperation
  //! \param[in] pData
  //! \param[in] pStmt
  //!  Not null.
  static void FetchNextRows(RemoteFB__P13__SrvOperation& serverOperation,
                            RemoteFB__ConnectorData*     pData,
                            stmt_data_type*              pStmt);
};//class RemoteFB__P13_LAZY_SEND__StmtHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
