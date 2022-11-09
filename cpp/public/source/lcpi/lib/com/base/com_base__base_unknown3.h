////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__base_unknown3_H_
#define _cpp_public_lcpi_lib_com_base__base_unknown3_H_

#include <lcpi/lib/com/base/com_base__base_unknown3a.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown3

//
// TCOM_SERVER_LINK
//  - void IncrementComponentCount()
//  - void DecrementComponentCount()
//

template<class TCOM_SERVER_LINK,class Allocator>
class TBaseUnknown3:public TBaseUnknown3A<Allocator>
{
 private:
  typedef TBaseUnknown3                                    self_type;
  typedef TBaseUnknown3A<Allocator>                        inherited;

  TBaseUnknown3(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  template<class ... TCOM_SERVER_LINK_ARGS>
  explicit TBaseUnknown3(IUnknown* pUnknownOuter,TCOM_SERVER_LINK_ARGS&& ... ComServerLinkArgs);

  virtual ~TBaseUnknown3();

  //interface ------------------------------------------------------------
  const TCOM_SERVER_LINK& GetComServerLink()const;

 private:
  TCOM_SERVER_LINK m_ComServerLink;
};//class TBaseUnknown3

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/com/base/com_base__base_unknown3.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
