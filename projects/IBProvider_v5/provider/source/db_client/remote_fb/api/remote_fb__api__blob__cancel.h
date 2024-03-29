////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__blob__cancel.h
//! \brief   ������ �������� �����.
//! \author  Kovalenko Dmitry
//! \date    22.09.2015
#ifndef _remote_fb__api__blob__cancel_H_
#define _remote_fb__api__blob__cancel_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__blob.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__CancelBlob

/// <summary>
///  ������ �������� �����.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__CancelBlob
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using blob_handle_type=handles::RemoteFB__BlobHandle;

 public:
  /// <summary>
  ///  ������ �������� �����.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pBlobHandle
  //!  ��������� �� �������������� ���������� ������������ �����. Not null.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle)=0;
};//class RemoteFB__API__CancelBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
