////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__api_entry.h
//! \brief   The class for RemoteFB API entry point.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#ifndef _remote_fb__api_entry_H_
#define _remote_fb__api_entry_H_

#include "source/error_services/ibp_error_utils.h"
#include <lcpi/lib/structure/t_smart_object_ptr.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ApiEntry

template<typename TApiItem>
class RemoteFB__ApiEntry
{
 private:
  typedef RemoteFB__ApiEntry<TApiItem>      self_type;

  RemoteFB__ApiEntry(const self_type&);
  self_type& operator = (const self_type&);

 public:
  RemoteFB__ApiEntry();

 ~RemoteFB__ApiEntry();

  void init(TApiItem* pApiItem);

  TApiItem* get()const;

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__not_defined();

 private:
  lib::structure::t_smart_object_ptr<TApiItem> m_spApiItem;
};//class RemoteFB__ApiEntry

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ApiEntry

template<typename TApiItem>
RemoteFB__ApiEntry<TApiItem>::RemoteFB__ApiEntry()
{
}

//------------------------------------------------------------------------
template<typename TApiItem>
RemoteFB__ApiEntry<TApiItem>::~RemoteFB__ApiEntry()
{
}

//------------------------------------------------------------------------
template<typename TApiItem>
void RemoteFB__ApiEntry<TApiItem>::init(TApiItem* const pApiItem)
{
 //one-time initialization of a object

 assert(!m_spApiItem);

 assert(pApiItem!=nullptr);

 m_spApiItem=lib::structure::not_null_ptr(pApiItem);
}//init

//------------------------------------------------------------------------
template<typename TApiItem>
TApiItem* RemoteFB__ApiEntry<TApiItem>::get()const
{
 if(!m_spApiItem)
  self_type::helper__throw_error__not_defined();

 return m_spApiItem;
}//get

//helper methods ---------------------------------------------------------
template<typename TApiItem>
void RemoteFB__ApiEntry<TApiItem>::helper__throw_error__not_defined()
{
 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (L"RemoteFB__ApiEntry::get",
   L"#001",
   L"the api entry [%1] is not defined",
   typeid(TApiItem).name());
}//helper__throw_error__not_defined

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif