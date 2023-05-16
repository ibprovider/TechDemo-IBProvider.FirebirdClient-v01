////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__db__drop.h
//! \brief   ”даление базы данных.
//! \author  Kovalenko Dmitry
//! \date    21.02.2015
#ifndef _remote_fb__api_p12__db__drop_H_
#define _remote_fb__api_p12__db__drop_H_

#include "source/db_client/remote_fb/api/remote_fb__api__db__drop.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__DropDatabase

/// <summary>
///  ќтключение от базы данных.
/// </summary>
class RemoteFB__API_P12__DropDatabase LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__DropDatabase)
{
 private:
  typedef RemoteFB__API_P12__DropDatabase                      self_type;

  RemoteFB__API_P12__DropDatabase(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P12__DropDatabase();

  virtual ~RemoteFB__API_P12__DropDatabase();

 public:
  /// ≈динственный экземпл€р класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ќткат транзакции.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__DropDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
