////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__connect_op_ctx.h
//! \brief   Контекст операции подключения/создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    17.02.2019
#ifndef _remote_fb__p13__connect_op_ctx_H_
#define _remote_fb__p13__connect_op_ctx_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_param_buffer_v2_builder.h"

#include "source/db_obj/isc_base/isc_base__dbparams_for_attach__installer.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_create__installer.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__ConnectOpCtx

/// <summary>
///  Контекст операции подключения/создания базы данных.
/// </summary>
class RemoteFB__P13__ConnectOpCtx LCPI_CPP_CFG__CLASS__FINAL
 :private isc_base::isc_base__dbparams_for_attach__installer
 ,private isc_base::isc_base__dbparams_for_create__installer
{
 private:
  using self_type=RemoteFB__P13__ConnectOpCtx;

  RemoteFB__P13__ConnectOpCtx(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using dpb_type=isc_base::t_isc_param_buffer_v2_builder;

 public:
  dpb_type m_dpb;

  //! \brief
  //!  Конструктор инициализации
  //! \param[in] clientConnectBlock
  //!  Блок параметров подключения/создания БД. Используются для формирования DPB.
  //! \param[in] setNewDbParams
  RemoteFB__P13__ConnectOpCtx(RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                              bool                             setNewDbParams);

  //! \brief
  //!  Деструктор
 ~RemoteFB__P13__ConnectOpCtx();

 private:
  void Helper__BuildDPB(RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                        bool                             setNewDbParams);

 private:
  using wstr_box_type=lib::structure::t_const_wstr_box;

 private: //isc_base__dbparams_for_attach__installer interface -----------
  virtual void set_dbinit_param___auth__integrated(wstr_box_type propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___auth__user_id(wstr_box_type propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___auth__password(wstr_box_type propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___auth__rolename(wstr_box_type propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___ctype(wstr_box_type propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___garbage_collect(bool propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___num_buffers(long propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___enable_db_trigger(long propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_dbinit_param___sys_encrypt_password(wstr_box_type propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private: //isc_base__dbparams_for_create__installer interface -----------
  virtual void set_newdb_param___db_dialect(long propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_newdb_param___page_size(long propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void set_newdb_param___type_of_db_users(long propValue) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
#ifndef NDEBUG
  bool m_DEBUG__was_installed__dbinit_param___auth__integrated;
  bool m_DEBUG__was_installed__dbinit_param___auth__user_id;
  bool m_DEBUG__was_installed__dbinit_param___auth__password;
  bool m_DEBUG__was_installed__dbinit_param___auth__rolename;
  bool m_DEBUG__was_installed__dbinit_param___ctype;
  bool m_DEBUG__was_installed__dbinit_param___garbage_collect;
  bool m_DEBUG__was_installed__dbinit_param___num_buffers;
  bool m_DEBUG__was_installed__dbinit_param___enable_db_trigger;
  bool m_DEBUG__was_installed__dbinit_param___sys_encrypt_password;

  bool m_DEBUG__was_installed__newdb_param___db_dialect;
  bool m_DEBUG__was_installed__newdb_param___page_size;
  bool m_DEBUG__was_installed__newdb_param___type_of_db_users;
#endif
};//class RemoteFB__P13__ConnectOpCtx

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
