////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__srv_operation_v1.h
//! \brief   Объект операции с сервером базы данных.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#ifndef _remote_fb__api_hlp__srv_operation_v1_H_
#define _remote_fb__api_hlp__srv_operation_v1_H_

#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_obj/db_operation.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__SrvOperation_v1

/// <summary>
///  Объект операции с сервером базы данных.
/// </summary>
class RemoteFB__API_HLP__SrvOperation_v1 LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(db_obj::t_db_operation)
{
 private:
  using self_type=RemoteFB__API_HLP__SrvOperation_v1;

  RemoteFB__API_HLP__SrvOperation_v1(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  class tag_send_frame;

 public:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] pCnData
  //!  Not null.
  explicit RemoteFB__API_HLP__SrvOperation_v1(RemoteFB__ConnectorData* pCnData);

  /// <summary>
  ///  Деструктор.
  /// </summary>
 ~RemoteFB__API_HLP__SrvOperation_v1();

  //t_db_operation interface ---------------------------------------------
  /// <summary>
  ///  Отмена операции
  /// </summary>
  virtual void cancel()LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //----------------------------------------------------------------------
  /// <summary>
  ///  Уведомляем о начале отправки команды на сервер. THROW.
  /// </summary>
  void on_before_send();

  /// <summary>
  ///  Уведомляем о завершении отправки команды на сервер. THROW.
  /// </summary>
  void on_after_send();

 private:
  typedef structure::t_multi_thread_traits  thread_traits;
  typedef thread_traits::int_type           state_type;

 private:
  static const state_type  c_state__before_send =0;
  static const state_type  c_state__after_send  =1;
  static const state_type  c_state__cancelled   =2;

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_err__cancel_not_support();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_bug_check__unk_state(const wchar_t* place,
                                                 const wchar_t* point,
                                                 state_type     stateID);

 private:
  /// Указатель на сервисные данные подключения. Not null.
  RemoteFB__ConnectorData::self_ptr const m_spCnData;

  /// Состояние операции
  state_type m_state;

 #ifndef NDEBUG
  thread_traits::int_type m_debug__op_cancel_was_sended;
 #endif
};//class RemoteFB__API_HLP__SrvOperation_v1

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__SrvOperation_v1::tag_send_frame

class RemoteFB__API_HLP__SrvOperation_v1::tag_send_frame LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_send_frame;

  tag_send_frame(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  explicit tag_send_frame(RemoteFB__API_HLP__SrvOperation_v1* pOp);

 ~tag_send_frame();

  //interface ------------------------------------------------------------
  void complete();

 private:
  self_ptr m_spOp;
};//class RemoteFB__API_HLP__SrvOperation_v1::tag_send

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
