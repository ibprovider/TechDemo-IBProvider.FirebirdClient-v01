////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__p10__connect_op_ctx.h
//! \brief   �������� �������� �����������/�������� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#ifndef _remote_fb__p10__connect_op_ctx_H_
#define _remote_fb__p10__connect_op_ctx_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p10
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P10__ConnectOpCtx

/// <summary>
///  �������� �������� �����������/�������� ���� ������.
/// </summary>
class RemoteFB__P10__ConnectOpCtx LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P10__ConnectOpCtx              self_type;

  RemoteFB__P10__ConnectOpCtx(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef isc_base::t_isc_param_buffer_v1_builder  dpb_type;

 public:
  dpb_type m_dpb;

  //! \brief
  //!  ����������� �������������
  //! \param[in] clientConnectBlock
  //!  ���� ���������� �����������/�������� ��. ������������ ��� ������������ DPB.
  //! \param[in] setNewDbParams
  RemoteFB__P10__ConnectOpCtx(const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                              bool                                   setNewDbParams);

  //! \brief
  //!  ����������
 ~RemoteFB__P10__ConnectOpCtx();

 private:
  void Helper__BuildDPB(const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                        bool                                   setNewDbParams);
};//class RemoteFB__P10__ConnectOpCtx

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
