////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__base_unknown3_CC_
#define _cpp_public_lcpi_lib_com_base__base_unknown3_CC_

#include <utility>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown3

template<class TCOM_SERVER_LINK,class Allocator>
template<class ... TCOM_SERVER_LINK_ARGS>
TBaseUnknown3<TCOM_SERVER_LINK,Allocator>::TBaseUnknown3
                             (IUnknown*             const pUnknownOuter,
                              TCOM_SERVER_LINK_ARGS&& ... ComServerLinkArgs)
 :inherited(pUnknownOuter)
 ,m_ComServerLink(std::forward<TCOM_SERVER_LINK_ARGS>(ComServerLinkArgs)...)
{
 m_ComServerLink.IncrementComponentCount();
}//TBaseUnknown3

//------------------------------------------------------------------------
template<class TCOM_SERVER_LINK,class Allocator>
TBaseUnknown3<TCOM_SERVER_LINK,Allocator>::~TBaseUnknown3()
{
 m_ComServerLink.DecrementComponentCount();
}//~TBaseUnknown3

//------------------------------------------------------------------------
template<class TCOM_SERVER_LINK,class Allocator>
const TCOM_SERVER_LINK& TBaseUnknown3<TCOM_SERVER_LINK,Allocator>::GetComServerLink()const
{
 return m_ComServerLink;
}//GetComServerLink

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif