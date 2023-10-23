////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__blob__get_info.h
//! \brief   Получение сведений о блобе.
//! \author  Kovalenko Dmitry
//! \date    12.09.2015
#ifndef _remote_fb__api__blob__get_info_H_
#define _remote_fb__api__blob__get_info_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__blob.h"
#include "source/db_client/remote_fb/remote_fb__info_buffer.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__GetBlobInfo

/// <summary>
///  Получение сведений о блобе.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__GetBlobInfo
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using blob_handle_type=handles::RemoteFB__BlobHandle;

 public:
  /// <summary>
  ///  Получение сведений о блобе.
  /// </summary>
  //! \param[in]  pData
  //!  Not null.
  //! \param[in]  pBlobHandle
  //!  Действительный дескриптор блоба. Not null.
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  virtual void exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle,
                    protocol::P_USHORT       cItems,
                    const protocol::P_UCHAR* pItems,
                    RemoteFB__InfoBuffer&    ResultBuffer)=0;
};//class RemoteFB__API__GetBlobInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
