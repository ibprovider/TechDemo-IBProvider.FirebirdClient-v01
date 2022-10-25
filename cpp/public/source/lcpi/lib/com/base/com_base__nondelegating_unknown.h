////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 16.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__nondelegating_unknown_H_
#define _cpp_public_lcpi_lib_com_base__nondelegating_unknown_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//Nondelegating IUnknown interface - Nondelegating version of IUnknown

struct LCPI_CPP_CFG__DECLSPEC__NOVTABLE INondelegatingUnknown
{
 virtual HRESULT __stdcall NondelegatingQueryInterface(const IID& iid, void** ppv)=0;

 virtual ULONG   __stdcall NondelegatingAddRef()=0;

 virtual ULONG   __stdcall NondelegatingRelease()=0;
};//struct INondelegatingUnknown

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif
