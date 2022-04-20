////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__blob__cancel.h
//! \brief   ������ �������� �����. ������ ��� lazy_send-���������.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_p13_lazy_send__blob__cancel_H_
#define _remote_fb__api_p13_lazy_send__blob__cancel_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__cancel.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__CancelBlob

/// <summary>
///  ������ �������� �����. ������ ��� lazy_send-���������.
/// </summary>
class RemoteFB__API_P13_LAZY_SEND__CancelBlob
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__CancelBlob)
{
 private:
  typedef RemoteFB__API_P13_LAZY_SEND__CancelBlob                      self_type;

  RemoteFB__API_P13_LAZY_SEND__CancelBlob(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef blob_handle_type::item_type                       blob_data_type;

 private:
  RemoteFB__API_P13_LAZY_SEND__CancelBlob();

  virtual ~RemoteFB__API_P13_LAZY_SEND__CancelBlob();

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
                    blob_handle_type*        pBlobHandle) COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P13_LAZY_SEND__CancelBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
