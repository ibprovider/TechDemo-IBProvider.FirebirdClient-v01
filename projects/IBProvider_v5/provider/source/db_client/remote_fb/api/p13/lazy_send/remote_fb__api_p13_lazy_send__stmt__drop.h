////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__stmt__drop.h
//! \brief   ������������ ����������� �������. ������ ��� lazy_send-���������.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#ifndef _remote_fb__api_p13_lazy_send__stmt__drop_H_
#define _remote_fb__api_p13_lazy_send__stmt__drop_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__drop.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__DropStatement

/// <summary>
///  ������������ ����������� �������. ������ ��� lazy_send-���������.
/// </summary>
class RemoteFB__API_P13_LAZY_SEND__DropStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__DropStatement)
{
 private:
  using self_type=RemoteFB__API_P13_LAZY_SEND__DropStatement;

  RemoteFB__API_P13_LAZY_SEND__DropStatement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;

 private:
  RemoteFB__API_P13_LAZY_SEND__DropStatement();

  virtual ~RemoteFB__API_P13_LAZY_SEND__DropStatement();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------
  /// <summary>
  ///  ������������ ����������� �������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //!
  //! � ������ ��������� ����������� �������, � (*pStmtHandle) ����� ������� ID
  //! � ����� ����������� ���������� �� ����������.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    stmt_handle_type*        pStmtHandle)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13_LAZY_SEND__DropStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
