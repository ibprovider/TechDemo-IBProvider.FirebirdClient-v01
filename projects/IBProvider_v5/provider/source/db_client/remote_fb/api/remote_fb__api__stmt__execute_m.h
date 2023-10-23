////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__execute_m.h
//! \brief   The service for a statement execution.
//! \author  Kovalenko Dmitry
//! \date    29.03.2023
#ifndef _remote_fb__api__stmt__execute_m_H_
#define _remote_fb__api__stmt__execute_m_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__ExecuteStatement_M

/// <summary>
///  The service for a statement execution.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__ExecuteStatement_M
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using tr_handle_type  =handles::RemoteFB__TrHandle;
  using stmt_handle_type=handles::RemoteFB__StmtHandle;

 public:
  /// <summary>
  ///  Executing of a statement.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of an operation.
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. The descriptor of a transaction.
  //! \param[in] pStmtHandle
  //!  Not null. The descriptor of a statement. It must be not null pointer on a not zero value.
  //! \param[in] pInMsg
  //!  IN-parameters of a statement. Can be null.
  //! \param[in,out] pOutMsg
  //!  OUT-parameters of a statement. Can be null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    const RemoteFB__InMsg_v1*       pInMsg,
                    const RemoteFB__OutMsg_v1*      pOutMsg)=0;
};//class RemoteFB__API__ExecuteStatement_M

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
