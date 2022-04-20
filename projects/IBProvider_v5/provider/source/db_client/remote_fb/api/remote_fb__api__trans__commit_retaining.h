////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__trans__commit_retaining.h
//! \brief   ������ ���������� � ����������� ���������.
//! \author  Kovalenko Dmitry
//! \date    18.02.2015
#ifndef _remote_fb__api__trans__commit_retaining_H_
#define _remote_fb__api__trans__commit_retaining_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__CommitRetaining

/// <summary>
///  ������ ���������� � ����������� ���������.
/// </summary>
//! \note
//!  �������� �������� ������� � 4-�� ���������.
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__CommitRetaining:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle       tr_handle_type;

 public:
  /// <summary>
  ///  ������ ���������� � ����������� ���������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle)=0;
};//class RemoteFB__API__CommitRetaining

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
