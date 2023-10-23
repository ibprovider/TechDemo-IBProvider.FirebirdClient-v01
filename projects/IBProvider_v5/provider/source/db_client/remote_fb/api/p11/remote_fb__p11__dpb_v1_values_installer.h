////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__p11__dpb_v1_values_installer.h
//! \brief   Класс установки параметров подключения.
//! \author  Kovalenko Dmitry
//! \date    27.02.2019
#ifndef _remote_fb__p11__dpb_v1_values_installer_H_
#define _remote_fb__p11__dpb_v1_values_installer_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h"

#include "source/db_obj/isc_base/isc_base__dbparams_for_attach__installer.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_create__installer.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__forwards.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p11
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P11__DpbV1_ValuesInstaller

/// <summary>
///  Класс установки параметров подключения.
/// </summary>
//!  - Установка элементов DPB
//!  - Установка DBPROP_USERNAME
class RemoteFB__P11__DpbV1_ValuesInstaller LCPI_CPP_CFG__CLASS__FINAL
 :public isc_base::isc_base__dbparams_for_attach__installer
 ,public isc_base::isc_base__dbparams_for_create__installer
{
 private:
  using self_type=RemoteFB__P11__DpbV1_ValuesInstaller;

  RemoteFB__P11__DpbV1_ValuesInstaller(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using dpb_type=isc_base::t_isc_param_buffer_v1_builder;

  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:

  //! \brief
  //!  Конструктор инициализации
  //! \param[in] pDPB
  //! \param[in] pDsPropValues
  //! \param[in] CnUseIntegratedAuth
  explicit RemoteFB__P11__DpbV1_ValuesInstaller
            (dpb_type*                              pDPB,
             oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
             bool                                   CnUseIntegratedAuth);

  //! \brief
  //!  Деструктор
 ~RemoteFB__P11__DpbV1_ValuesInstaller();

  //interface ------------------------------------------------------------

 public: //isc_base__dbparams_for_attach__installer interface ------------
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
  dpb_type* const m_pDPB;

  oledb_lib::OLEDB_Props2__Data__Values* m_pDsPropValues;

  ///Флаг использования интегрированной аутентификации
  bool const m_CnUseIntegratedAuth;

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
};//class RemoteFB__P11__DpbV1_ValuesInstaller

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
