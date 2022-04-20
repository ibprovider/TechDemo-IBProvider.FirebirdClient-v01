////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__trans__commit.h
//! \brief   ������ ����������.
//! \author  Kovalenko Dmitry
//! \date    18.02.2015
#ifndef _remote_fb__api__trans__commit_H_
#define _remote_fb__api__trans__commit_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__Commit

/// <summary>
///  ����� ����������.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__Commit:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle       tr_handle_type;

 public:
  /// <summary>
  ///  ����� ����������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //!
  //! � ������ ��������� ������� ����������, � (*pTrHandle) ����� ������� ID.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle)=0;
};//class RemoteFB__API__Commit

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
