////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__srv_resource_id.cpp
//! \brief   Класс для представления идентификатора серверного ресурса.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
#include <structure/t_negative_one.h>
#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SrvResourceID

RemoteFB__SrvResourceID::RemoteFB__SrvResourceID()
 :m_state(state__null)
 ,m_value(structure::negative_one)
{;}

//------------------------------------------------------------------------
RemoteFB__SrvResourceID::~RemoteFB__SrvResourceID()
{;}

//interface --------------------------------------------------------------
RemoteFB__SrvResourceID::state_type RemoteFB__SrvResourceID::get_state()const
{
 return m_state;
}//get_state

//------------------------------------------------------------------------
bool RemoteFB__SrvResourceID::is_null()const
{
 return m_state==state__null;
}//is_null

//------------------------------------------------------------------------
bool RemoteFB__SrvResourceID::is_defer()const
{
 return m_state==state__defer;
}//is_defer

//------------------------------------------------------------------------
bool RemoteFB__SrvResourceID::is_wait_drop()const
{
 return m_state==state__wait_drop;
}//is_wait_drop

//------------------------------------------------------------------------
bool RemoteFB__SrvResourceID::is_wait_close()const
{
 return m_state==state__wait_close;
}//is_wait_close

//------------------------------------------------------------------------
bool RemoteFB__SrvResourceID::is_wait_cancel()const
{
 return m_state==state__wait_cancel;
}//is_wait_cancel

//------------------------------------------------------------------------
bool RemoteFB__SrvResourceID::has_value()const
{
 return m_state==state__value;
}//has_value

//------------------------------------------------------------------------
RemoteFB__SrvResourceID::value_type RemoteFB__SrvResourceID::get_value()const
{
 assert_msg(m_state==state__value,"state: "<<structure::to_underlying(m_state));

 return m_value;
}//get_value

//------------------------------------------------------------------------
RemoteFB__SrvResourceID::value_type RemoteFB__SrvResourceID::get_wait_drop()const
{
 assert_msg(m_state==state__wait_drop,"state: "<<structure::to_underlying(m_state));

 return m_value;
}//get_wait_drop

//------------------------------------------------------------------------
RemoteFB__SrvResourceID::value_type RemoteFB__SrvResourceID::get_wait_close()const
{
 assert_msg(m_state==state__wait_close,"state: "<<structure::to_underlying(m_state));

 return m_value;
}//get_wait_close

//------------------------------------------------------------------------
RemoteFB__SrvResourceID::value_type RemoteFB__SrvResourceID::get_wait_cancel()const
{
 assert_msg(m_state==state__wait_cancel,"state: "<<structure::to_underlying(m_state));

 return m_value;
}//get_wait_cancel

//------------------------------------------------------------------------
void RemoteFB__SrvResourceID::reset()
{
 m_state=state__null;

 m_value=structure::negative_one;
}//reset

//------------------------------------------------------------------------
void RemoteFB__SrvResourceID::set_defer()
{
 m_state=state__defer;

 m_value=structure::negative_one;
}//set_defer

//------------------------------------------------------------------------
void RemoteFB__SrvResourceID::set_value(const value_type* const pv)
{
 assert(pv!=nullptr);

 m_state=state__value;

 m_value=(*pv);
}//set_value

//------------------------------------------------------------------------
void RemoteFB__SrvResourceID::set_wait_drop(const value_type* const pv)
{
 assert(pv!=nullptr);

 m_state=state__wait_drop;

 m_value=(*pv);
}//set_wait_drop

//------------------------------------------------------------------------
void RemoteFB__SrvResourceID::set_wait_close(const value_type* const pv)
{
 assert(pv!=nullptr);

 m_state=state__wait_close;

 m_value=(*pv);
}//set_wait_close

//------------------------------------------------------------------------
void RemoteFB__SrvResourceID::set_wait_cancel(const value_type* const pv)
{
 assert(pv!=nullptr);

 m_state=state__wait_cancel;

 m_value=(*pv);
}//set_wait_cancel

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
