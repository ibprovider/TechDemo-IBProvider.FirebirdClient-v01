////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__blob__read.h
//! \brief   ������ ������ �����.
//! \author  Kovalenko Dmitry
//! \date    15.09.2015
#ifndef _remote_fb__api__blob__read_H_
#define _remote_fb__api__blob__read_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__blob.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__ReadBlob

/// <summary>
///  ������ ������ �����.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__ReadBlob:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__BlobHandle     blob_handle_type;

 public:
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
                    size_t*                  pcbActualReaded)=0;
};//class RemoteFB__API__ReadBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
