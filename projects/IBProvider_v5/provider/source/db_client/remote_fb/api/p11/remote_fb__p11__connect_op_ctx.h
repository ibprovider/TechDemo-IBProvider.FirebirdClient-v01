////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__p11__connect_op_ctx.h
//! \brief   Контекст операции подключения/создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#ifndef _remote_fb__p11__connect_op_ctx_H_
#define _remote_fb__p11__connect_op_ctx_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/os/win32/auth/ibp_os_win32_auth__descr_builder.h"
#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p11
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P11__ConnectOpCtx

/// <summary>
///  Контекст операции подключения/создания базы данных.
/// </summary>
class RemoteFB__P11__ConnectOpCtx LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__P11__ConnectOpCtx;

  RemoteFB__P11__ConnectOpCtx(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using dpb_type=isc_base::t_isc_param_buffer_v1_builder;

  using auth_descr_builder_type=ibp::os::win32::auth::t_auth__descr_builder;

  using auth_output_type=auth_descr_builder_type::output_type;

 public:
  dpb_type m_dpb;

  //! \brief
  //!  Конструктор инициализации
  //! \param[in] clientConnectBlock
  //!  Блок параметров подключения/создания БД. Используются для формирования DPB.
  //! \param[in] setNewDbParams
  explicit RemoteFB__P11__ConnectOpCtx(const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                       bool                                   setNewDbParams);

  //! \brief
  //!  Деструктор
 ~RemoteFB__P11__ConnectOpCtx();

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Проверка флага использования интегрированной аутентификации
  /// </summary>
  bool cn_use_integ_auth()const;

  /// <summary>
  ///  Проверка завершенности процесса интегрированной аутентификации
  /// </summary>
  bool auth_data_is_completed()const;

  /// <summary>
  ///  Получение данных для интегрированной аутентификации
  /// </summary>
  void request_auth_data(size_t            cbInput,
                         const void*       pvInput,
                         auth_output_type& Output);

 private:
  using auth_provider_type=ibp::os::win32::auth::t_auth__provider;

 private:
  void Helper__BuildDPB(const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                        bool                                   setNewDbParams);

 private:
  auth_provider_type::self_ptr m_spAuthProvider;
  auth_descr_builder_type      m_AuthData;

  ///Флаг использования интегрированной аутентификации
  bool m_CnUseIntegratedAuth;
};//class RemoteFB__P11__ConnectOpCtx

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
