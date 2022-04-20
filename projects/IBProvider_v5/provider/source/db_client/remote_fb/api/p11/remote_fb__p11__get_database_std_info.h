////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__p11__get_database_std_info.h
//! \brief   «апрос стандартных сведений о сервере и базе данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#ifndef _remote_fb__p11__get_database_std_info_H_
#define _remote_fb__p11__get_database_std_info_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p11
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P11__GetDatabaseStdInfo

/// <summary>
///  «апрос стандартных сведений о сервере и базе данных.
/// </summary>
class RemoteFB__P11__GetDatabaseStdInfo LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P11__GetDatabaseStdInfo                    self_type;

 public:
  typedef isc_base::t_isc_connection_settings                  cns_type;

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
  static const unsigned char sm_db_info_items[];
};//class RemoteFB__P11__GetDatabaseStdInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
