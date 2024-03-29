////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__get_info.h
//! \brief   ��������� �������� � �����.
//! \author  Kovalenko Dmitry
//! \date    12.09.2015
#ifndef _remote_fb__api_p12__blob__get_info_H_
#define _remote_fb__api_p12__blob__get_info_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__get_info.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__GetBlobInfo

/// <summary>
///  ��������� �������� � �����.
/// </summary>
class RemoteFB__API_P12__GetBlobInfo LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetBlobInfo)
{
 private:
  using self_type=RemoteFB__API_P12__GetBlobInfo;

  RemoteFB__API_P12__GetBlobInfo(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P12__GetBlobInfo();

  virtual ~RemoteFB__API_P12__GetBlobInfo();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ��������� �������� � �����.
  /// </summary>
  //! \param[in]  pData
  //!  Not null.
  //! \param[in]  pBlobHandle
  //!  �������������� ���������� �����. Not null.
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  virtual void exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle,
                    protocol::P_USHORT       cItems,
                    const protocol::P_UCHAR* pItems,
                    RemoteFB__InfoBuffer&    ResultBuffer)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;
};//class RemoteFB__API_P12__GetBlobInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
