////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api_p12__dsql__execute_immediate.h
//! \brief   Немедленное выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    06.11.2015
#ifndef _remote_fb__api_p12__dsql__execute_immediate_H_
#define _remote_fb__api_p12__dsql__execute_immediate_H_

#include "source/db_client/remote_fb/api/remote_fb__api__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__ExecuteImmediate

/// <summary>
///  Немедленное выполнение запроса.
/// </summary>
class RemoteFB__API_P12__ExecuteImmediate LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ExecuteImmediate)
{
 private:
  typedef RemoteFB__API_P12__ExecuteImmediate         self_type;

  RemoteFB__API_P12__ExecuteImmediate(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P12__ExecuteImmediate();

 ~RemoteFB__API_P12__ExecuteImmediate();

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
                    const isc_api::XSQLDA_V1*       pOutXSQLDA) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static protocol::P_OBJCT helper__execute
                             (RemoteFB__P12__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              protocol::P_USHORT            SQL_dialect,
                              sql_str_box_type              SQL_str);

  static protocol::P_OBJCT helper__execute2
                             (RemoteFB__P12__SrvOperation&  serverOperation,
                              RemoteFB__ConnectorData*      pData,
                              tr_handle_type*               pTrHandle,
                              protocol::P_USHORT            SQL_dialect,
                              sql_str_box_type              SQL_str,
                              const isc_api::XSQLDA_V1*     pInXSQLDA,
                              const isc_api::XSQLDA_V1*     pOutXSQLDA);
};//class RemoteFB__API_P12__ExecuteImmediate

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
