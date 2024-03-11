////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__read.h
//! \brief   ������ ������ �����.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__read_H_
#define _remote_fb__api_p13__blob__read_H_

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"
#include "source/db_client/remote_fb/api/remote_fb__api__blob__read.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ReadBlob

/// <summary>
///  ������ ������ �����.
/// </summary>
class RemoteFB__API_P13__ReadBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ReadBlob)
{
 private:
  using self_type=RemoteFB__API_P13__ReadBlob;

  RemoteFB__API_P13__ReadBlob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P13__ReadBlob();

  virtual ~RemoteFB__API_P13__ReadBlob();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  ������ ������ �����.
  /// </summary>
  //! \param[in] OpCtx
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
  virtual bool exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    blob_handle_type*               pBlobHandle,
                    size_t                          cbBuffer,
                    void*                           pvBuffer,
                    size_t*                         pcbActualReaded)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;

 private:
  /// <summary>
  ///  �������� ������ � ����� ����������� �����.
  /// </summary>
  //! \param[in] serverOperation
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobData
  //!  Not null.
  static void helper__read_to_buffer
               (RemoteFB__P13__SrvOperation& serverOperation,
                RemoteFB__ConnectorData*     pData,
                blob_data_type*              pBlobData);
};//class RemoteFB__API_P13__ReadBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
