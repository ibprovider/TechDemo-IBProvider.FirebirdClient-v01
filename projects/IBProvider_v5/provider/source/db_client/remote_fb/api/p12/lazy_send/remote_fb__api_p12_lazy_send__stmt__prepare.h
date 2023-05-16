////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__prepare.h
//! \brief   Подготовка запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    26.10.2015
#ifndef _remote_fb__api_p12_lazy_send__stmt__prepare_H_
#define _remote_fb__api_p12_lazy_send__stmt__prepare_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__prepare.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__PrepareStatement

/// <summary>
///  Подготовка запроса. Версия для lazy_send-протокола.
/// </summary>
class RemoteFB__API_P12_LAZY_SEND__PrepareStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__PrepareStatement)
{
 private:
  typedef RemoteFB__API_P12_LAZY_SEND__PrepareStatement      self_type;

  RemoteFB__API_P12_LAZY_SEND__PrepareStatement(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type                        stmt_data_type;

 private:
  RemoteFB__API_P12_LAZY_SEND__PrepareStatement();

  virtual ~RemoteFB__API_P12_LAZY_SEND__PrepareStatement();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Подготовка запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //! \param[in] pStmtHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //! \param[in] SQL_dialect
  //! \param[in] SQL_str
  //! \param[out] pStmtTypeID
  //!  Not null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    protocol::P_USHORT              SQL_dialect,
                    sql_str_box_type                SQL_str,
                    unsigned long*                  pStmtTypeID)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static void helper__exec__prepare
                   (RemoteFB__P12__SrvOperation& serverOperation,
                    RemoteFB__ConnectorData*     pData,
                    tr_handle_type*              pTrHandle,
                    stmt_data_type*              pStmt,
                    protocol::P_USHORT           SQL_dialect,
                    sql_str_box_type             SQL_str);

  static void helper__exec__allocate_and_prepare
                   (RemoteFB__P12__SrvOperation& serverOperation,
                    RemoteFB__ConnectorData*     pData,
                    tr_handle_type*              pTrHandle,
                    stmt_data_type*              pStmt,
                    protocol::P_USHORT           SQL_dialect,
                    sql_str_box_type             SQL_str);

  static void helper__exec__close_and_prepare
                   (RemoteFB__P12__SrvOperation& serverOperation,
                    RemoteFB__ConnectorData*     pData,
                    tr_handle_type*              pTrHandle,
                    stmt_data_type*              pStmt,
                    protocol::P_USHORT           SQL_dialect,
                    sql_str_box_type             SQL_str);
};//class RemoteFB__API_P12_LAZY_SEND__PrepareStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
