////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__cancel.h
//! \brief   ������ �������� �����.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__cancel_H_
#define _remote_fb__api_p13__blob__cancel_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__cancel.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__CancelBlob

/// <summary>
///  ������ �������� �����.
/// </summary>
class RemoteFB__API_P13__CancelBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__CancelBlob)
{
 private:
  using self_type=RemoteFB__API_P13__CancelBlob;

  RemoteFB__API_P13__CancelBlob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P13__CancelBlob();

  virtual ~RemoteFB__API_P13__CancelBlob();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ������ �������� �����.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__CancelBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
