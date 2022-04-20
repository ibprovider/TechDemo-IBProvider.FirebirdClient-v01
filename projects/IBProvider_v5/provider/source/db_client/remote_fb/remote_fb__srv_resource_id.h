////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__srv_resource_id.h
//! \brief   Класс для представления идентификатора серверного ресурса.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015.
#ifndef _remote_fb__srv_resource_id_H_
#define _remote_fb__srv_resource_id_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SrvResourceID

class RemoteFB__SrvResourceID
{
 private:
  typedef RemoteFB__SrvResourceID           self_type;

  RemoteFB__SrvResourceID(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef protocol::P_OBJCT                 value_type;

  enum state_type
  {
   state__null         =0,
   state__defer        =1,
   state__value        =2,
   state__wait_drop    =3,
   state__wait_close   =4,
   state__wait_cancel  =5,
  };//enum state_type

 public:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  RemoteFB__SrvResourceID();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~RemoteFB__SrvResourceID();

  //selectors ------------------------------------------------------------
  state_type get_state()const;

  bool is_null()const;

  bool is_defer()const;

  bool is_wait_drop()const;

  bool is_wait_close()const;

  bool is_wait_cancel()const;

  bool has_value()const;

  value_type get_value()const;

  value_type get_wait_drop()const;

  value_type get_wait_close()const;

  value_type get_wait_cancel()const;

  //modificators ---------------------------------------------------------
  void reset();

  void set_defer();

  void set_value(const value_type* pv);

  void set_wait_drop(const value_type* pv);

  void set_wait_close(const value_type* pv);

  void set_wait_cancel(const value_type* pv);

 private:
  /// Состояние идентификатора.
  state_type     m_state;

  /// Идентификатор.
  value_type     m_value;
};//class RemoteFB__SrvResourceID

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
