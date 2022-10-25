////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__base_unknown3_CC_
#define _cpp_public_lcpi_lib_com_base__base_unknown3_CC_

#include <utility>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown3

template<class SERVER_LINK,class Allocator>
template<class ... TSERVER_LINK_ARGS>
TBaseUnknown3<SERVER_LINK,Allocator>::TBaseUnknown3
                             (IUnknown*         const pUnknownOuter,
                              TSERVER_LINK_ARGS&& ... ServerLinkArgs)
 :inherited(pUnknownOuter)
 ,m_ServerLink(std::forward<TSERVER_LINK_ARGS>(ServerLinkArgs)...)
{
 m_ServerLink.IncrementComponentCount();
}//TBaseUnknown3

//------------------------------------------------------------------------
template<class SERVER_LINK,class Allocator>
TBaseUnknown3<SERVER_LINK,Allocator>::~TBaseUnknown3()
{
 m_ServerLink.DecrementComponentCount();
}//~TBaseUnknown3

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif