////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__write.h
//! \brief   ������ ������ �����.
//! \author  Kovalenko Dmitry.
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__write_H_
#define _remote_fb__api_p13__blob__write_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__write.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__WriteBlob

/// <summary>
///  ������ ������ �����.
/// </summary>
class RemoteFB__API_P13__WriteBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__WriteBlob)
{
 private:
  typedef RemoteFB__API_P13__WriteBlob      self_type;

  RemoteFB__API_P13__WriteBlob(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef blob_handle_type::item_type       blob_data_type;

 private:
  RemoteFB__API_P13__WriteBlob();

  virtual ~RemoteFB__API_P13__WriteBlob();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  ������ ������ �����.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobHandle
  //!  Not null. �� ����� ������ ��������� �� ���������� ������������ �����.
  //! \param[in] cbBuffer
  //!  ������ ������
  //! \param[out] pvBuffer
  //!  ����� � �������
  virtual void exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle,
                    size_t                   cbBuffer,
                    const void*              pvBuffer)COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P13__WriteBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
