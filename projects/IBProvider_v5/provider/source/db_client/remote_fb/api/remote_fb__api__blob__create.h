////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__blob__create.h
//! \brief   Создание блоба.
//! \author  Kovalenko Dmitry
//! \date    18.09.2015
#ifndef _remote_fb__api__blob__create_H_
#define _remote_fb__api__blob__create_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__blob.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__CreateBlob

/// <summary>
///  Создание блоба.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__CreateBlob:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle       tr_handle_type;
  typedef handles::RemoteFB__BlobHandle     blob_handle_type;

 public:
  /// <summary>
  ///  Создание блоба.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. Дескриптор транзации.
  //! \param[in,out] pBlobHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //! \param[out] pBlobId
  //!  Идентификатор созданного блоб поля.
  //! \param[in] szBPB
  //!  Размер pBPB
  //! \param[in] pBPB
  //!  Буфер с параметрами блоба
  virtual void exec(RemoteFB__ConnectorData*  pData,
                    tr_handle_type*           pTrHandle,
                    blob_handle_type*         pBlobHandle,
                    db_obj::DB_IBBLOBID*      pBlobId,
                    size_t                    szBPB,
                    const protocol::P_UCHAR*  pBPB)=0;
};//class RemoteFB__API__CreateBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
