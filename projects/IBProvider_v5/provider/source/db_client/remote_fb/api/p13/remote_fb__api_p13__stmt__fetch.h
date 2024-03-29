////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__fetch.h
//! \brief   ������� ����������� ���������� �������.
//! \author  Kovalenko Dmitry
//! \date    22.09.2016
#ifndef _remote_fb__api_p13__stmt__fetch_H_
#define _remote_fb__api_p13__stmt__fetch_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__FetchStatement

/// <summary>
///  ������� ����������� ���������� �������.
/// </summary>
class RemoteFB__API_P13__FetchStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__FetchStatement)
{
 private:
  using self_type=RemoteFB__API_P13__FetchStatement;

  RemoteFB__API_P13__FetchStatement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;

 private:
  RemoteFB__API_P13__FetchStatement();

  virtual ~RemoteFB__API_P13__FetchStatement();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ������� ����������� �������.
  /// </summary>
  //! \param[in] OpCtx
  //!  �������� ��������.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //! \param[in] pOutXSQLDA
  //!  Not null.
  //! \return
  //!  false, ���� ������ �� ������� (��������� ����� ��������������� ���������).
  virtual bool exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    const isc_api::XSQLDA_V1*       pOutXSQLDA)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__FetchStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
