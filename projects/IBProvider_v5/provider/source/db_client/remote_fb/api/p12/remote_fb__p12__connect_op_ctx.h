////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__connect_op_ctx.h
//! \brief   �������� �������� �����������/�������� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    15.02.2015
#ifndef _remote_fb__p12__connect_op_ctx_H_
#define _remote_fb__p12__connect_op_ctx_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/os/win32/auth/ibp_os_win32_auth__descr_builder.h"
#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__ConnectOpCtx

/// <summary>
///  �������� �������� �����������/�������� ���� ������.
/// </summary>
class RemoteFB__P12__ConnectOpCtx LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P12__ConnectOpCtx                   self_type;

  RemoteFB__P12__ConnectOpCtx(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef isc_base::t_isc_param_buffer_v1_builder       dpb_type;

  typedef ibp::os::win32::auth::t_auth__descr_builder   auth_descr_builder_type;

  typedef auth_descr_builder_type::output_type          auth_output_type;

 public:
  dpb_type m_dpb;

  //! \brief
  //!  ����������� �������������
  //! \param[in] clientConnectBlock
  //!  ���� ���������� �����������/�������� ��. ������������ ��� ������������ DPB.
  //! \param[in] setNewDbParams
  explicit RemoteFB__P12__ConnectOpCtx(const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                       bool                                   setNewDbParams);

  //! \brief
  //!  ����������
 ~RemoteFB__P12__ConnectOpCtx();

  //interface ------------------------------------------------------------

  /// <summary>
  ///  �������� ����� ������������� ��������������� ��������������
  /// </summary>
  bool cn_use_integ_auth()const;

  /// <summary>
  ///  �������� ������������� �������� ��������������� ��������������
  /// </summary>
  bool auth_data_is_completed()const;

  /// <summary>
  ///  ��������� ������ ��� ��������������� ��������������
  /// </summary>
  void request_auth_data(size_t            cbInput,
                         const void*       pvInput,
                         auth_output_type& Output);

 private:
  typedef ibp::os::win32::auth::t_auth__provider        auth_provider_type;

 private:
  void Helper__BuildDPB(const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                        bool                                   setNewDbParams);

 private:
  auth_provider_type::self_ptr m_spAuthProvider;
  auth_descr_builder_type      m_AuthData;

  ///���� ������������� ��������������� ��������������
  bool m_CnUseIntegratedAuth;
};//class RemoteFB__P12__ConnectOpCtx

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
