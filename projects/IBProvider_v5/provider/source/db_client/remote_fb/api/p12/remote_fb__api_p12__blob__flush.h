////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__flush.h
//! \brief   Запись буферизированных данных блоба.
//! \author  Kovalenko Dmitry.
//! \date    20.09.2015
#ifndef _remote_fb__api_p12__blob__flush_H_
#define _remote_fb__api_p12__blob__flush_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__flush.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__FlushBlob

/// <summary>
///  Запись буферизированных данных блоба.
/// </summary>
class RemoteFB__API_P12__FlushBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__FlushBlob)
{
 private:
  typedef RemoteFB__API_P12__FlushBlob      self_type;

  RemoteFB__API_P12__FlushBlob(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef blob_handle_type::item_type       blob_data_type;

 private:
  RemoteFB__API_P12__FlushBlob();

  virtual ~RemoteFB__API_P12__FlushBlob();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Запись буферизированных данных блоба
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор создаваемого блоба.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle)COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P12__FlushBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
