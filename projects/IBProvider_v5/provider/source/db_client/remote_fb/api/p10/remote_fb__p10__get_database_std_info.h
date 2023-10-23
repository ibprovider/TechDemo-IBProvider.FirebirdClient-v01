////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__p10__get_database_std_info.h
//! \brief   «апрос стандартных сведений о сервере и базе данных.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#ifndef _remote_fb__p10__get_database_std_info_H_
#define _remote_fb__p10__get_database_std_info_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p10
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P10__GetDatabaseStdInfo

/// <summary>
///  «апрос стандартных сведений о сервере и базе данных.
/// </summary>
class RemoteFB__P10__GetDatabaseStdInfo LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__P10__GetDatabaseStdInfo;

 public:
  using cns_type=isc_base::t_isc_connection_settings;

 public:
  /// <summary>
  ///  «агрузка сведений.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] cns
  static void exec(RemoteFB__ConnectorData* pData,
                   cns_type&                cns);

 private:
  static void helper__exec1(RemoteFB__ConnectorData* pData,
                            cns_type&                cns);

  static void helper__exec2(RemoteFB__ConnectorData* pData,
                            cns_type&                cns);

 private:
  static const unsigned char sm_db_info_items1[];
  static const unsigned char sm_db_info_items2[];
};//class RemoteFB__P10__GetDatabaseStdInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
