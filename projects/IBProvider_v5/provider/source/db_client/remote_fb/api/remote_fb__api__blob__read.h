////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__blob__read.h
//! \brief   Чтение данных блоба.
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
///  Чтение данных блоба.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__ReadBlob
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using blob_handle_type=handles::RemoteFB__BlobHandle;

 public:
  /// <summary>
  ///  Чтение данных блоба.
  /// </summary>
  //! \param[in] OpCtx
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор открытого блоба.
  //! \param[in] cbBuffer
  //!  Размер буфера
  //! \param[out] pvBuffer
  //!  Указатель на приемник
  //! \param[out] pcbActualReaded
  //!  Количество записанных байт в буфер. Not null.
  //! \return
  //!  - false, если был достигут конец блоба.
  //!
  //! \note
  //!  При достижении конца буфера с данными мы можем вернуть данные.
  virtual bool exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    blob_handle_type*               pBlobHandle,
                    size_t                          cbBuffer,
                    void*                           pvBuffer,
                    size_t*                         pcbActualReaded)=0;
};//class RemoteFB__API__ReadBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
