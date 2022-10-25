////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__ptr_H_
#define _cpp_public_lcpi_lib_com_base__ptr_H_

#include <lcpi/lib/structure/t_not_null_ptr.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////

#define OLE_LIB__BUILD_IPTR_TYPE_NS(NS,INTERFACE)                         \
 ::lcpi::lib::com::base::IPtr< NS##INTERFACE , &NS##IID_##INTERFACE >

//------------------------------------------------------------------------
#define OLE_LIB__BUILD_IPTR_TYPE(INTERFACE)                               \
 OLE_LIB__BUILD_IPTR_TYPE_NS(::,INTERFACE)

//------------------------------------------------------------------------
#define OLE_LIB__DECLARE_IPTR_TYPE_NS(NS,INTERFACE)                       \
 typedef OLE_LIB__BUILD_IPTR_TYPE_NS(NS,INTERFACE)    INTERFACE##Ptr

//------------------------------------------------------------------------
#define OLE_LIB__DECLARE_IPTR_TYPE(INTERFACE)                             \
 OLE_LIB__DECLARE_IPTR_TYPE_NS(::,INTERFACE)

////////////////////////////////////////////////////////////////////////////////
//deprecated

#define DECLARE_IPTR_TYPE_NS(NS,INTERFACE)                                \
 OLE_LIB__DECLARE_IPTR_TYPE_NS(NS,INTERFACE)

//------------------------------------------------------------------------
#define DECLARE_IPTR_TYPE(INTERFACE)                                      \
 OLE_LIB__DECLARE_IPTR_TYPE_NS(::,INTERFACE)

////////////////////////////////////////////////////////////////////////////////
//containings

//smart-pointer for COM objects without support QueryInterface
template<class T,const IID* piid> class IPtr;

template<> class IPtr<IUnknown,&IID_IUnknown>;

//smart-pointer for COM-objects without support QueryInterface
template<class T> class IPtr2;

//The smart-pointer class which are based on INondelegatingUnknown.
//It use for creating and initialization a compound components (TBaseUnknown3A)
template<class T> class INondelegatingPtr2;

////////////////////////////////////////////////////////////////////////////////
//helper functions

template<class ISource,class IDest>
HRESULT CopyComInterface(ISource* pISource,IDest** ppIDest);

template<class ISource,class IDest>
HRESULT MoveComInterface(ISource* &rpISource,IDest** ppIDest);

template<class ISource,class IDest>
void CopyComInterface2(ISource* pISource,IDest* &rpIDest);

template<class ISource,class IDest>
void MoveComInterface2(ISource* &rpISource,IDest* &rpIDest);

template<class I1,class I2>
bool IsEqualComObject(I1* p1,I2* p2);

template<class I>
void ReleaseComInterface(I* &pI);

template<class T>
HRESULT QueryComInterface(T* ptr,REFIID riid,void** ppv,HRESULT null_ptr_hr);

////////////////////////////////////////////////////////////////////////////////
//class IPtr - smart pointer with support QueryInterface

template <class T,const IID* piid>
class IPtr
{
 private:
  typedef IPtr<T,piid>                    self_type;

 public:
  typedef T                               interface_type;

 public:
  HRESULT m_hr;

  IPtr();

  IPtr(const self_type& ptr);

  IPtr(self_type&& ptr);

  IPtr(std::nullptr_t x);

  IPtr(interface_type* const pI);

  template<class U>
  IPtr(const structure::t_not_null_ptr<U>& nn_ptr);

  IPtr(IUnknown* const pI);

  IPtr(const structure::t_not_null_ptr<IUnknown>& nn_ptr);

 ~IPtr() ;

  interface_type* ptr() const;

  IUnknown* unk_ptr()const;

  interface_type* &ref_ptr();

  IUnknown* &ref_unk_ptr();

  void** ppv();

  HRESULT QueryInterface(REFIID riid,void** ppv,HRESULT null_ptr_hr/*=E_FAIL*/)const;

  self_type& Release();

  HRESULT set(interface_type* pI);
  HRESULT set(IUnknown* pI);

  template<class U>
  HRESULT set(const structure::t_not_null_ptr<U>& nn_ptr);

  self_type& operator = (const self_type& ptr);

  self_type& operator = (self_type&& ptr);

  self_type& operator = (interface_type* ptr);

  self_type& operator = (IUnknown* pUnknown);

  template<class U>
  self_type& operator = (const structure::t_not_null_ptr<U>& nn_ptr);

  self_type& operator = (std::nullptr_t x);

  void swap(self_type& ptr);
  void swap(interface_type* &ptr);

  template<class U>
  HRESULT MoveTo(U** pptr);

  template<class U>
  void MoveTo_Fast(U** pptr);

 public: //selectors -----------------------------------------------------
  template<class U>
  HRESULT CopyTo(U** pptr)const;

  template<class U>
  void CopyTo_Fast(U** pptr)const;

  bool IsEqualObject(IUnknown* pUnk)const;

  static REFIID iid();

  interface_type* operator -> () const;

  operator interface_type* () const;

 private:
  interface_type* m_pI;
};//class IPtr

////////////////////////////////////////////////////////////////////////////////
//class IPtr<IUnknown,&IID_IUnknown>

template<>
class IPtr<IUnknown,&IID_IUnknown>
{
 private:
  typedef IPtr<IUnknown,&IID_IUnknown>    self_type;

 public:
  typedef IUnknown                        interface_type;

 public:
  HRESULT m_hr;

  IPtr();

  IPtr(const self_type& ptr);

  IPtr(self_type&& ptr);

  IPtr(std::nullptr_t x);

  IPtr(interface_type* const pI);

  template<class U>
  IPtr(const structure::t_not_null_ptr<U>& nn_ptr);

 ~IPtr() ;

  interface_type* ptr() const;

  IUnknown* unk_ptr()const;

  interface_type* &ref_ptr();

  IUnknown* &ref_unk_ptr();

  void** ppv();

  HRESULT QueryInterface(REFIID riid,void** ppv,HRESULT null_ptr_hr/*=E_FAIL*/)const;

  self_type& Release();

  HRESULT set(interface_type* pI);

  template<class U>
  HRESULT set(const structure::t_not_null_ptr<U>& nn_ptr);

  self_type& operator = (const self_type& ptr);

  self_type& operator = (self_type&& ptr);

  self_type& operator = (interface_type* ptr);

  template<class U>
  self_type& operator = (const structure::t_not_null_ptr<U>& nn_ptr);

  self_type& operator = (std::nullptr_t x);

  void swap(self_type& ptr);
  void swap(interface_type* &ptr);

  template<class U>
  HRESULT MoveTo(U** pptr);

  template<class U>
  void MoveTo_Fast(U** pptr);

 public: //selectors -----------------------------------------------------
  template<class U>
  HRESULT CopyTo(U** pptr)const;

  template<class U>
  void CopyTo_Fast(U** pptr)const;

  bool IsEqualObject(IUnknown* pUnk)const;

  static REFIID iid();

  interface_type* operator -> () const;

  operator interface_type* () const;

 private:
  interface_type* m_pI;
};//class IPtr<IUnknown,&IID_IUnknown>

//typedef IPtr<IUnknown,&IID_IUnknown> IUnknownPtr;

////////////////////////////////////////////////////////////////////////////////
//class IPtr2 - without use QueryInterface

#define OLE_LIB__DECLARE_IPTR2_TYPE_EX(InterfaceType,typedef_name)        \
 typedef ::lcpi::lib::com::base::IPtr2<InterfaceType> typedef_name

#define OLE_LIB__DECLARE_IPTR2_TYPE(InterfaceType)                        \
 OLE_LIB__DECLARE_IPTR2_TYPE_EX(InterfaceType,InterfaceType##Ptr)

//deprecated -------------------------------------------------------------
#define DECLARE_IPTR2_TYPE_EX(InterfaceType,typedef_name)                 \
 OLE_LIB__DECLARE_IPTR2_TYPE_EX(InterfaceType,typedef_name)

#define DECLARE_IPTR2_TYPE(InterfaceType)                                 \
 OLE_LIB__DECLARE_IPTR2_TYPE(InterfaceType)

//------------------------------------------------------------------------
template<class T>
class IPtr2
{
 private:
  typedef IPtr2<T> self_type;

 public:
  typedef T        interface_type;

 public:
  IPtr2();

  IPtr2(const self_type& x);

  IPtr2(self_type&& x);

  template<class U>
  IPtr2(IPtr2<U>&& x);

  IPtr2(interface_type* ptr);

  template<class U>
  IPtr2(const structure::t_not_null_ptr<U>& nn_ptr);

  IPtr2(std::nullptr_t x);

 ~IPtr2();

 public:
  HRESULT QueryInterface(REFIID riid,void** ppv,HRESULT null_ptr_hr/*=E_FAIL*/)const;

  self_type& Release();

  void Terminate(); //force release of pointer (without call m_ptr->Release())

  self_type& set (interface_type* const ptr);

  template<class U>
  self_type& set (const structure::t_not_null_ptr<U>& nn_ptr);

  //self_type& set (const self_type& x);

  self_type& operator = (const self_type& x);

  self_type& operator = (self_type&& x);

  template<class U>
  self_type& operator = (IPtr2<U>&& x);

  self_type& operator = (interface_type* const ptr);

  template<class U>
  self_type& operator = (const structure::t_not_null_ptr<U>& nn_ptr);

  self_type& operator = (std::nullptr_t x);

  inline void swap(self_type& x);

  template<class U>
  HRESULT CopyTo(U** pptr)const;

  template<class U>
  void CopyTo_Fast(U** pptr)const;

  template<class U>
  HRESULT MoveTo(U** pptr);

  template<class U>
  void MoveTo_Fast(U** pptr);

 public: //selectors -----------------------------------------------------
  interface_type* operator -> () const;

  operator interface_type* () const;

  interface_type* ptr() const;

  interface_type* &ref_ptr();

  bool IsEqualObject(IUnknown* pUnk)const;

 private:
  interface_type* m_ptr;
};//template class IPtr2

//deprecated [2017-03-26]
typedef IPtr2<IUnknown> IUnknownPtr;

typedef IPtr2<IUnknown> IUnknownPtr2;

////////////////////////////////////////////////////////////////////////////////
//class INondelegatingPtr2

template<class T>
class INondelegatingPtr2
{
 private:
  typedef INondelegatingPtr2<T> self_type;

  INondelegatingPtr2(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef T                     interface_type;

 public:
  INondelegatingPtr2();

  explicit INondelegatingPtr2(interface_type* const ptr);

  template<class U>
  explicit INondelegatingPtr2(const structure::t_not_null_ptr<U>& nn_ptr);

 ~INondelegatingPtr2();

  //----------------------------------------------------------------------
  self_type& Release();

  //
  // Install and initialize component
  //
  HRESULT set(interface_type* const ptr,bool const init);

  //
  // Getting a pointer to the component interface.
  //
  // If IsAggregation==true, then riid must be equal IID_IUnknown.
  //

  HRESULT get_out(REFIID        riid,
                  void**  const ppv,
                  HRESULT const errAggregation=CLASS_E_NOAGGREGATION)const;

  HRESULT get_out(REFIID           riid,
                  IUnknown** const ppUnk,
                  HRESULT    const errAggregation=CLASS_E_NOAGGREGATION)const;

  //selectors ------------------------------------------------------------
  interface_type* operator -> () const;

  operator interface_type* () const;

  interface_type* ptr() const;

  interface_type* &ref_ptr();

  HRESULT CopyTo(interface_type** pptr)const;

  //----------------------------------------------------------------------
  void swap(self_type& x);

 private:
  interface_type* m_ptr;
};//template class INondelegatingPtr2

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/com/base/com_base__ptr.cc>
////////////////////////////////////////////////////////////////////////////////

namespace std{
////////////////////////////////////////////////////////////////////////////////
//STL specializations

template<class T,IID* piid>
inline void swap(lcpi::lib::com::base::IPtr<T,piid>& x1,
                 lcpi::lib::com::base::IPtr<T,piid>& x2)
{
 x1.swap(x2);
}//swap IPtr

//------------------------------------------------------------------------
template<class T>
inline void swap(lcpi::lib::com::base::IPtr2<T>& x1,
                 lcpi::lib::com::base::IPtr2<T>& x2)
{
 x1.swap(x2);
}//swap IPtr2

//------------------------------------------------------------------------
template<class T>
inline void swap(lcpi::lib::com::base::INondelegatingPtr2<T>& x1,
                 lcpi::lib::com::base::INondelegatingPtr2<T>& x2)
{
 x1.swap(x2);
}//swap INondelegatingPtr2

////////////////////////////////////////////////////////////////////////////////
}//namespace std
#endif
