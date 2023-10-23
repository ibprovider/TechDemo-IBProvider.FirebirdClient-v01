////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__prepare.h
//! \brief   Подготовка запроса.
//! \author  Kovalenko Dmitry
//! \date    21.04.2015
#ifndef _remote_fb__api__stmt__prepare_H_
#define _remote_fb__api__stmt__prepare_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__PrepareStatement

/// <summary>
///  Подготовка запроса.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__PrepareStatement
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using tr_handle_type  =handles::RemoteFB__TrHandle;
  using stmt_handle_type=handles::RemoteFB__StmtHandle;

  using sql_str_box_type=lib::structure::t_const_str_box;

 public:
  /// <summary>
  ///  Подготовка запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //! \param[in] pStmtHandle
  //!  Not null. На входе должен указывать на действительный дескриптор.
  //! \param[in] SQL_dialect
  //! \param[in] SQL_str
  //! \param[out] pStmtTypeID
  //!  Идентификатор серверного типа запроса. Not null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    protocol::P_USHORT              SQL_dialect,
                    sql_str_box_type                SQL_str,
                    unsigned long*                  pStmtTypeID)=0;
};//class RemoteFB__API__PrepareStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
