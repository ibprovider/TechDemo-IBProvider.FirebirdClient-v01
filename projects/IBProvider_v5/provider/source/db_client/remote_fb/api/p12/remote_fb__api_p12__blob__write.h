////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__write.h
//! \brief   Запись данных блоба.
//! \author  Kovalenko Dmitry.
//! \date    19.09.2015
#ifndef _remote_fb__api_p12__blob__write_H_
#define _remote_fb__api_p12__blob__write_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__write.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__WriteBlob

/// <summary>
///  Запись данных блоба.
/// </summary>
class RemoteFB__API_P12__WriteBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__WriteBlob)
{
 private:
  using self_type=RemoteFB__API_P12__WriteBlob;

  RemoteFB__API_P12__WriteBlob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P12__WriteBlob();

  virtual ~RemoteFB__API_P12__WriteBlob();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------
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
                    const void*                     pvBuffer)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__WriteBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
