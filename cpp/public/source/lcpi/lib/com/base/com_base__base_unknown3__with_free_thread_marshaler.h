////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__base_unknown3__with_free_thread_marshaler_H_
#define _cpp_public_lcpi_lib_com_base__base_unknown3__with_free_thread_marshaler_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown3_WithFreeThreadMarshaler

template<class tagBaseUnknown>
class TBaseUnknown3_WithFreeThreadMarshaler:public tagBaseUnknown
{
 private:
  typedef TBaseUnknown3_WithFreeThreadMarshaler         self_type;
  typedef tagBaseUnknown                                inherited;

  TBaseUnknown3_WithFreeThreadMarshaler(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  template<class ...TARGS>
  explicit TBaseUnknown3_WithFreeThreadMarshaler(TARGS&& ... args);

  virtual ~TBaseUnknown3_WithFreeThreadMarshaler();

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

 protected:
  bool BaseUnknown__IsSupportedInterface(REFIID riid)const;

 private:
  HRESULT Helper__Create_IMarshal();

 private:
  IUnknown* m_pFreeThreadMarshaller;
};//class TBaseUnknown3_WithFreeThreadMarshaler

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/com/base/com_base__base_unknown3__with_free_thread_marshaler.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
