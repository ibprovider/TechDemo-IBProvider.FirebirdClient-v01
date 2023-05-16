////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__get_info.h
//! \brief   Получение сведений о блобе.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__get_info_H_
#define _remote_fb__api_p13__blob__get_info_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__get_info.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetBlobInfo

/// <summary>
///  Получение сведений о блобе.
/// </summary>
class RemoteFB__API_P13__GetBlobInfo LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetBlobInfo)
{
 private:
  typedef RemoteFB__API_P13__GetBlobInfo    self_type;

  RemoteFB__API_P13__GetBlobInfo(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef blob_handle_type::item_type       blob_data_type;

 private:
  RemoteFB__API_P13__GetBlobInfo();

  virtual ~RemoteFB__API_P13__GetBlobInfo();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

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
                    RemoteFB__InfoBuffer&    ResultBuffer)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;
};//class RemoteFB__API_P13__GetBlobInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
