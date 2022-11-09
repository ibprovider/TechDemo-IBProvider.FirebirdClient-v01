////////////////////////////////////////////////////////////////////////////////
//IBProvider - OLE DB Provider for Firebird/InterBase.
//                                                 Kovalenko Dmitry. 29.10.2022.
#ifndef __ibp__ole_lib__base_unknown2_H__
#define __ibp__ole_lib__base_unknown2_H__

#include "source/ibp_memory.h"

#include <ole_lib/ole_lib__memory_allocator.h>

#include <lcpi/lib/com/base/com_base__base_unknown3.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK_DATA

class TBaseUnknown2__SERVER_LINK_DATA
 :public ::lcpi::ibp::IBP_SmartInterface
{
 public:
  using self_ptr=lcpi::lib::structure::t_smart_object_ptr<TBaseUnknown2__SERVER_LINK_DATA>;

 public:
  virtual bool IsReal()const=0;

  virtual void IncrementComponentCount()=0;

  virtual void DecrementComponentCount()=0;
};//class TBaseUnknown2__SERVER_LINK_DATA

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK

class TBaseUnknown2__SERVER_LINK LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef TBaseUnknown2__SERVER_LINK                                 self_type;

  self_type& operator = (const self_type&);

 public:
  TBaseUnknown2__SERVER_LINK(const self_type& ptr);

  explicit TBaseUnknown2__SERVER_LINK(TBaseUnknown2__SERVER_LINK_DATA* pData);

 ~TBaseUnknown2__SERVER_LINK();

  //----------------------------------------------------------------------
  static self_type Create_REAL();

  static self_type Create_DUMMY();

  //interface ------------------------------------------------------------
  TBaseUnknown2__SERVER_LINK_DATA* GetData() const;

 private:
  using data_ptr
   =lcpi::lib::structure::t_smart_object_ptr
     <TBaseUnknown2__SERVER_LINK_DATA>;

 private:
  const data_ptr m_spData;
};//class TBaseUnknown2__SERVER_LINK

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2

class TBaseUnknown2:public ::lcpi::lib::com::base::TBaseUnknown3A<ole_lib::TComObjectMemoryAllocator>
{
 private:
  typedef TBaseUnknown2                                              self_type;
  typedef TBaseUnknown3A<ole_lib::TComObjectMemoryAllocator>         inherited;

  TBaseUnknown2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  typedef TBaseUnknown2__SERVER_LINK                                 COM_SERVER_LINK_TYPE;

 public:
  template<class ... TCOM_SERVER_LINK_ARGS>
  explicit TBaseUnknown2(IUnknown* pUnknownOuter,TCOM_SERVER_LINK_ARGS&& ... ComServerLinkArgs);

 protected:
  virtual ~TBaseUnknown2();

 public:
  const COM_SERVER_LINK_TYPE& GetComServerLink()const;

 private:
  const COM_SERVER_LINK_TYPE m_COM_SERVER_LINK;
};//class TBaseUnknown2

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2

template<class ... TCOM_SERVER_LINK_ARGS>
TBaseUnknown2::TBaseUnknown2(IUnknown*             const pUnknownOuter,
                             TCOM_SERVER_LINK_ARGS&& ... ComServerLinkArgs)
 :inherited(pUnknownOuter)
 ,m_COM_SERVER_LINK(std::forward<TCOM_SERVER_LINK_ARGS>(ComServerLinkArgs)...)
{
 assert(m_COM_SERVER_LINK.GetData());

 m_COM_SERVER_LINK.GetData()->IncrementComponentCount();
}//TBaseUnknown2

////////////////////////////////////////////////////////////////////////////////

using TBaseUnknown2NPtr
 =::lcpi::lib::com::base::INondelegatingPtr2<TBaseUnknown2>;

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
