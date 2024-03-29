////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__open.h
//! \brief   �������� �����.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__open_H_
#define _remote_fb__api_p13__blob__open_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__open.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__OpenBlob

/// <summary>
///  �������� �����.
/// </summary>
class RemoteFB__API_P13__OpenBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__OpenBlob)
{
 private:
  using self_type=RemoteFB__API_P13__OpenBlob;

  RemoteFB__API_P13__OpenBlob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P13__OpenBlob();

  virtual ~RemoteFB__API_P13__OpenBlob();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  �������� �����.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. ���������� ���������.
  //! \param[in,out] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ������� ��������.
  //! \param[in] blobId
  //!  ������������� ���� ����.
  virtual void exec(RemoteFB__ConnectorData*   pData,
                    tr_handle_type*            pTrHandle,
                    blob_handle_type*          pBlobHandle,
                    const db_obj::DB_IBBLOBID& blobId) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__OpenBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif