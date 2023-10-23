////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__prepare.h
//! \brief   ���������� �������.
//! \author  Kovalenko Dmitry
//! \date    21.04.2015
#ifndef _remote_fb__api_p12__stmt__prepare_H_
#define _remote_fb__api_p12__stmt__prepare_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__prepare.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__PrepareStatement

/// <summary>
///  ���������� �������.
/// </summary>
class RemoteFB__API_P12__PrepareStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__PrepareStatement)
{
 private:
  using self_type=RemoteFB__API_P12__PrepareStatement;

  RemoteFB__API_P12__PrepareStatement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;

 private:
  RemoteFB__API_P12__PrepareStatement();

  virtual ~RemoteFB__API_P12__PrepareStatement();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ���������� �������.
  /// </summary>
  //! \param[in] OpCtx
  //!  �������� ��������.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //! \param[in] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //! \param[in] SQL_dialect
  //! \param[in] SQL_str
  //! \param[out] pStmtTypeID
  //!  ������������� ���������� ���� �������. Not null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    stmt_handle_type*               pStmtHandle,
                    protocol::P_USHORT              SQL_dialect,
                    sql_str_box_type                SQL_str,
                    unsigned long*                  pStmtTypeID)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__PrepareStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
