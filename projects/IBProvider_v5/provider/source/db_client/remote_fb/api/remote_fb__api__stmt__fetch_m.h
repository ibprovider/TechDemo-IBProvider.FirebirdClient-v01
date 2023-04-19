////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__fetch_m.h
//! \brief   API for fetching the row of result set.
//! \author  Kovalenko Dmitry
//! \date    14.04.2023
#ifndef _remote_fb__api__stmt__fetch_m_H_
#define _remote_fb__api__stmt__fetch_m_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__FetchStatement_M

/// <summary>
///  API for fetching the row of result set.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__FetchStatement_M:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__StmtHandle     stmt_handle_type;

 public:
  /// <summary>
  ///  Fetching the row or result set.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of an operation.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. It must point on a not zero value.
  //! \param[in] pOutMsg
  //!  Not null. It must define at least one column.
  //! \return
  //!  false when a record was not fetched (the end of result set was reached).
  virtual bool exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    const RemoteFB__OutMsg_v1*      pOutMsg)=0;
};//class RemoteFB__API__FetchStatement_M

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
