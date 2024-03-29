////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__fetch.h
//! \brief   ������� ����������� ���������� �������.
//! \author  Kovalenko Dmitry
//! \date    25.08.2015
#ifndef _remote_fb__api_p12__stmt__fetch_H_
#define _remote_fb__api_p12__stmt__fetch_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__FetchStatement

/// <summary>
///  ������� ����������� ���������� �������.
/// </summary>
class RemoteFB__API_P12__FetchStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__FetchStatement)
{
 private:
  using self_type=RemoteFB__API_P12__FetchStatement;

  RemoteFB__API_P12__FetchStatement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;

 private:
  RemoteFB__API_P12__FetchStatement();

  virtual ~RemoteFB__API_P12__FetchStatement();

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
};//class RemoteFB__API_P12__FetchStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
