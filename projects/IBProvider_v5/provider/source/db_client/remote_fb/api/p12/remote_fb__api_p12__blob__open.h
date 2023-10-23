////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__open.h
//! \brief   Открытие блоба.
//! \author  Kovalenko Dmitry
//! \date    11.09.2015
#ifndef _remote_fb__api_p12__blob__open_H_
#define _remote_fb__api_p12__blob__open_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__open.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__OpenBlob

/// <summary>
///  Открытие блоба.
/// </summary>
class RemoteFB__API_P12__OpenBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__OpenBlob)
{
 private:
  using self_type=RemoteFB__API_P12__OpenBlob;

  RemoteFB__API_P12__OpenBlob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P12__OpenBlob();

  virtual ~RemoteFB__API_P12__OpenBlob();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Открытие блоба.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. Дескриптор транзации.
  //! \param[in,out] pBlobHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //! \param[in] blobId
  //!  Идентификатор блоб поля.
  virtual void exec(RemoteFB__ConnectorData*   pData,
                    tr_handle_type*            pTrHandle,
                    blob_handle_type*          pBlobHandle,
                    const db_obj::DB_IBBLOBID& blobId) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__OpenBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif