////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__drop.h
//! \brief   ������������ ����������� �������. ������ ��� lazy_send-���������.
//! \author  Kovalenko Dmitry
//! \date    28.10.2015
#ifndef _remote_fb__api_p12_lazy_send__stmt__drop_H_
#define _remote_fb__api_p12_lazy_send__stmt__drop_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__drop.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__DropStatement

/// <summary>
///  ������������ ����������� �������. ������ ��� lazy_send-���������.
/// </summary>
class RemoteFB__API_P12_LAZY_SEND__DropStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__DropStatement)
{
 private:
  typedef RemoteFB__API_P12_LAZY_SEND__DropStatement        self_type;

  RemoteFB__API_P12_LAZY_SEND__DropStatement(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__StmtHandle                     stmt_handle_type;

  typedef stmt_handle_type::item_type                       stmt_data_type;

 private:
  RemoteFB__API_P12_LAZY_SEND__DropStatement();

  virtual ~RemoteFB__API_P12_LAZY_SEND__DropStatement();

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
};//class RemoteFB__API_P12_LAZY_SEND__DropStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
