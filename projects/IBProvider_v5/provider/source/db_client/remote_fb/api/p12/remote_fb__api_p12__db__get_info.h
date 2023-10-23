////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__db__get_info.h
//! \brief   Получение сведений о сервере и база данных.
//! \author  Kovalenko Dmitry
//! \date    16.02.2015
#ifndef _remote_fb__api_p12__db__get_info_H_
#define _remote_fb__api_p12__db__get_info_H_

#include "source/db_client/remote_fb/api/remote_fb__api__db__get_info.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__GetDatabaseInfo

/// <summary>
///  Получение сведений о сервере и база данных.
/// </summary>
class RemoteFB__API_P12__GetDatabaseInfo LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetDatabaseInfo)
{
 private:
  using self_type=RemoteFB__API_P12__GetDatabaseInfo;

  RemoteFB__API_P12__GetDatabaseInfo(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P12__GetDatabaseInfo();

  virtual ~RemoteFB__API_P12__GetDatabaseInfo();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Получение сведений о сервере и база данных.
  /// </summary>
  //! \param[in]  pData
  //!  Not null.
  //! \param[in]  Incornation
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  virtual void exec(RemoteFB__ConnectorData* pData,
                    unsigned short           Incornation,
                    protocol::P_USHORT       cItems,
                    const protocol::P_UCHAR* pItems,
                    RemoteFB__InfoBuffer&    ResultBuffer)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;
};//class RemoteFB__API_P12__GetDatabaseInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
