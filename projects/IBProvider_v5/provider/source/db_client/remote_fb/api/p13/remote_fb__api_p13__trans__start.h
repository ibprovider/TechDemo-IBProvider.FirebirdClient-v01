////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__trans__start.h
//! \brief   ����� ����������.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#ifndef _remote_fb__api_p13__trans__start_H_
#define _remote_fb__api_p13__trans__start_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__start.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__StartTransaction

/// <summary>
///  ����� ����������.
/// </summary>
class RemoteFB__API_P13__StartTransaction LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__StartTransaction)
{
 private:
  using self_type=RemoteFB__API_P13__StartTransaction;

  RemoteFB__API_P13__StartTransaction(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P13__StartTransaction();

  virtual ~RemoteFB__API_P13__StartTransaction();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  �������� ����������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� ������� ��������.
  //!  �� ������ ��������� ���������� ���������� ��������� ����������.
  //! \param[in] tpb_length
  //! \param[in] tpb
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle,
                    size_t                   tpb_length,
                    const unsigned char*     tpb)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__StartTransaction

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
