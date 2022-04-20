////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__create.h
//! \brief   �������� �����.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__create_H_
#define _remote_fb__api_p13__blob__create_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__create.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__CreateBlob

/// <summary>
///  �������� �����.
/// </summary>
class RemoteFB__API_P13__CreateBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__CreateBlob)
{
 private:
  typedef RemoteFB__API_P13__CreateBlob     self_type;

  RemoteFB__API_P13__CreateBlob(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef blob_handle_type::item_type       blob_data_type;

 private:
  RemoteFB__API_P13__CreateBlob();

  virtual ~RemoteFB__API_P13__CreateBlob();

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
  //! \param[out] pBlobId
  //!  Not null. ������������� ���� ����.
  //! \param[in] szBPB
  //!  ������ pBPB
  //! \param[in] pBPB
  //!  ����� � ����������� �����
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle,
                    blob_handle_type*        pBlobHandle,
                    db_obj::DB_IBBLOBID*     pBlobId,
                    size_t                   szBPB,
                    const protocol::P_UCHAR* pBPB) COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P13__CreateBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif