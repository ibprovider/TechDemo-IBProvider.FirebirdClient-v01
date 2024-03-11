////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__blob__close.h
//! \brief   Закрытие блоба. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    02.11.2015
#ifndef _remote_fb__api_p12_lazy_send__blob__close_H_
#define _remote_fb__api_p12_lazy_send__blob__close_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__close.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__CloseBlob

/// <summary>
///  Закрытие блоба. Версия для lazy_send-протокола.
/// </summary>
class RemoteFB__API_P12_LAZY_SEND__CloseBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__CloseBlob)
{
 private:
  using self_type=RemoteFB__API_P12_LAZY_SEND__CloseBlob;

  RemoteFB__API_P12_LAZY_SEND__CloseBlob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P12_LAZY_SEND__CloseBlob();

  virtual ~RemoteFB__API_P12_LAZY_SEND__CloseBlob();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Закрытие блоба.
  /// </summary>
  //! \param[in] OpCtx
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pBlobHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    blob_handle_type*               pBlobHandle) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12_LAZY_SEND__CloseBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
