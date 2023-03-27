////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__execute.h
//! \brief   Выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    07.05.2015
#ifndef _remote_fb__api__stmt__execute_H_
#define _remote_fb__api__stmt__execute_H_

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
//class RemoteFB__API__ExecuteStatement

/// <summary>
///  Выполнение запроса.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__ExecuteStatement:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle       tr_handle_type;
  typedef handles::RemoteFB__StmtHandle     stmt_handle_type;

 public:
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
                    const isc_api::XSQLDA_V1*       pOutXSQLDA)=0;
};//class RemoteFB__API__ExecuteStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
