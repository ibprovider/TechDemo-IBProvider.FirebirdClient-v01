////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__prepare.h
//! \brief   Подготовка запроса.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#ifndef _remote_fb__api_p13__stmt__prepare_H_
#define _remote_fb__api_p13__stmt__prepare_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__prepare.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__PrepareStatement

/// <summary>
///  Подготовка запроса.
/// </summary>
class RemoteFB__API_P13__PrepareStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__PrepareStatement)
{
 private:
  using self_type=RemoteFB__API_P13__PrepareStatement;

  RemoteFB__API_P13__PrepareStatement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;

 private:
  RemoteFB__API_P13__PrepareStatement();

  virtual ~RemoteFB__API_P13__PrepareStatement();

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
  //!  Идентификатор серверного типа запроса. Not null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    protocol::P_USHORT              SQL_dialect,
                    sql_str_box_type                SQL_str,
                    unsigned long*                  pStmtTypeID)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__PrepareStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
