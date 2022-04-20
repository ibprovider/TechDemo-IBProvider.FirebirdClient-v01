////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__read.h
//! \brief   ������ ������ �����.
//! \author  Kovalenko Dmitry
//! \date    15.09.2015
#ifndef _remote_fb__api_p12__blob__read_H_
#define _remote_fb__api_p12__blob__read_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__read.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__ReadBlob

/// <summary>
///  ������ ������ �����.
/// </summary>
class RemoteFB__API_P12__ReadBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ReadBlob)
{
 private:
  typedef RemoteFB__API_P12__ReadBlob       self_type;

  RemoteFB__API_P12__ReadBlob(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef blob_handle_type::item_type       blob_data_type;

 private:
  RemoteFB__API_P12__ReadBlob();

  virtual ~RemoteFB__API_P12__ReadBlob();

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
  //!  Not null. �� ����� ������ ��������� �� ���������� ��������� �����.
  //! \param[in] cbBuffer
  //!  ������ ������
  //! \param[out] pvBuffer
  //!  ��������� �� ��������
  //! \param[out] pcbActualReaded
  //!  ���������� ���������� ���� � �����. Not null.
  //! \return
  //!  - false, ���� ��� �������� ����� �����.
  //!
  //! \note
  //!  ��� ���������� ����� ������ � ������� �� ����� ������� ������.
  virtual bool exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle,
                    size_t                   cbBuffer,
                    void*                    pvBuffer,
                    size_t*                  pcbActualReaded)COMP_W000004_OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;

 private:
  /// <summary>
  ///  �������� ������ � ����� ����������� �����.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobData
  //!  Not null.
  static void helper__read_to_buffer(RemoteFB__ConnectorData* pData,
                                     blob_data_type*          pBlobData);
};//class RemoteFB__API_P12__ReadBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
