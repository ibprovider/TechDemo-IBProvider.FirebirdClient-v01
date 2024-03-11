////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__flush.h
//! \brief   Запись буферизированных данных блоба.
//! \author  Kovalenko Dmitry.
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__flush_H_
#define _remote_fb__api_p13__blob__flush_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__flush.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__FlushBlob

/// <summary>
///  Запись буферизированных данных блоба.
/// </summary>
class RemoteFB__API_P13__FlushBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__FlushBlob)
{
 private:
  using self_type=RemoteFB__API_P13__FlushBlob;

  RemoteFB__API_P13__FlushBlob(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using blob_data_type=blob_handle_type::item_type;

 private:
  RemoteFB__API_P13__FlushBlob();

  virtual ~RemoteFB__API_P13__FlushBlob();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Запись буферизированных данных блоба
  /// </summary>
  //! \param[in] OpCtx
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор создаваемого блоба.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    blob_handle_type*               pBlobHandle)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__FlushBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
