////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__blob__write.h
//! \brief   Запись данных блоба.
//! \author  Kovalenko Dmitry
//! \date    19.09.2015
#ifndef _remote_fb__api__blob__write_H_
#define _remote_fb__api__blob__write_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__blob.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__WriteBlob

/// <summary>
///  Запись данных блоба.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__WriteBlob
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using blob_handle_type=handles::RemoteFB__BlobHandle;

 public:
  /// <summary>
  ///  Запись данных блоба.
  /// </summary>
  //! \param[in] OpCtx
  //!  The operation context.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор создаваемого блоба.
  //! \param[in] cbBuffer
  //!  Размер буфера
  //! \param[out] pvBuffer
  //!  Буфер с данными
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    blob_handle_type*               pBlobHandle,
                    size_t                          cbBuffer,
                    const void*                     pvBuffer)=0;
};//class RemoteFB__API__WriteBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
