////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__db__detach.h
//! \brief   ќтключение от базы данных.
//! \author  Kovalenko Dmitry
//! \date    14.09.2016
#ifndef _remote_fb__api_p13__db__detach_H_
#define _remote_fb__api_p13__db__detach_H_

#include "source/db_client/remote_fb/api/remote_fb__api__db__detach.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__DetachDatabase

/// <summary>
///  ќтключение от базы данных.
/// </summary>
class RemoteFB__API_P13__DetachDatabase LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__DetachDatabase)
{
 private:
  typedef RemoteFB__API_P13__DetachDatabase                      self_type;

  RemoteFB__API_P13__DetachDatabase(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P13__DetachDatabase();

  virtual ~RemoteFB__API_P13__DetachDatabase();

 public:
  /// ≈динственный экземпл€р класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ќтключение от базы данных.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P13__DetachDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
