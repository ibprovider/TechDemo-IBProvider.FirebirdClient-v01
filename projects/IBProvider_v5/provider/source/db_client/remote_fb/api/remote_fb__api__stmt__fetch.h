////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__fetch.h
//! \brief   ??????? ??????????? ???????.
//! \author  Kovalenko Dmitry
//! \date    25.08.2015
#ifndef _remote_fb__api__stmt__fetch_H_
#define _remote_fb__api__stmt__fetch_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__FetchStatement

/// <summary>
///  ?????????? ???????.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__FetchStatement:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__StmtHandle     stmt_handle_type;

 public:
  /// <summary>
  ///  ?????????? ???????.
  /// </summary>
  //! \param[in] OpCtx
  //!  ???????? ????????.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. ?? ????? ?????? ????????? ?? ????????? ????????.
  //! \param[in] pOutXSQLDA
  //!  Not null.
  //! \return
  //!  false, ???? ?????? ?? ??????? (????????? ????? ??????????????? ?????????).
  virtual bool exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    const isc_api::XSQLDA_V1*       pOutXSQLDA)=0;
};//class RemoteFB__API__FetchStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
