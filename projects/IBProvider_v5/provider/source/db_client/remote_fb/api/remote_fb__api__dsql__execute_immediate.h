////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__dsql__execute_immediate.h
//! \brief   Немедленное выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    06.11.2015
#ifndef _remote_fb__api__dsql__execute_immediate_H_
#define _remote_fb__api__dsql__execute_immediate_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__ExecuteImmediate

/// <summary>
///  Немедленное выполнение запроса.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__ExecuteImmediate
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using tr_handle_type  =handles::RemoteFB__TrHandle;

  using sql_str_box_type=lib::structure::t_const_str_box;

 public:
  /// <summary>
  ///  Немедленное выполнение запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. Дескриптор транзации.
  //! \param[in] SQL_dialect
  //! \param[in] SQL_str
  //! \param[in] pInXSQLDA
  //!  IN-параметры запроса. Can be null.
  //! \param[in] pOutXSQLDA
  //!  OUT-параметры запроса. Can be null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    protocol::P_USHORT              SQL_dialect,
                    sql_str_box_type                SQL_str,
                    const isc_api::XSQLDA_V1*       pInXSQLDA,
                    const isc_api::XSQLDA_V1*       pOutXSQLDA)=0;
};//class RemoteFB__API__ExecuteImmediate

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
