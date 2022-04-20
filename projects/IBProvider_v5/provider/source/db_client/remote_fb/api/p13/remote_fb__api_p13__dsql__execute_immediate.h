////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api_p13__dsql__execute_immediate.h
//! \brief   Немедленное выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    23.06.2016
#ifndef _remote_fb__api_p13__dsql__execute_immediate_H_
#define _remote_fb__api_p13__dsql__execute_immediate_H_

#include "source/db_client/remote_fb/api/remote_fb__api__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ExecuteImmediate

/// <summary>
///  Немедленное выполнение запроса.
/// </summary>
class RemoteFB__API_P13__ExecuteImmediate LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ExecuteImmediate)
{
 private:
  typedef RemoteFB__API_P13__ExecuteImmediate         self_type;

  RemoteFB__API_P13__ExecuteImmediate(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P13__ExecuteImmediate();

 ~RemoteFB__API_P13__ExecuteImmediate();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

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
                    const isc_api::XSQLDA_V1*       pOutXSQLDA) COMP_W000004_OVERRIDE_FINAL;

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
                              const isc_api::XSQLDA_V1*     pInXSQLDA,
                              const isc_api::XSQLDA_V1*     pOutXSQLDA);
};//class RemoteFB__API_P13__ExecuteImmediate

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
