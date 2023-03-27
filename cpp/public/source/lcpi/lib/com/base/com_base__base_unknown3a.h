////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__base_unknown3a_H_
#define _cpp_public_lcpi_lib_com_base__base_unknown3a_H_

#include <lcpi/lib/com/base/com_base__nondelegating_unknown.h>

#include <lcpi/lib/com/base/com_base__mac_help.h>
#include <lcpi/lib/com/base/com_base__mac_debug.h>
#include <lcpi/lib/com/.config.h>

#include <lcpi/lib/structure/cnt_ref_traits.h>

#include <Unknwn.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown3A

template<class Allocator>
class TBaseUnknown3A:INondelegatingUnknown
{
 private:
  typedef TBaseUnknown3A                                   self_type;

  TBaseUnknown3A(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  typedef lcpi::lib::structure::cnt_ref_traits             cnt_ref_traits;
  typedef cnt_ref_traits::cnt_ref_type                     cnt_ref_type;

 public:
  explicit TBaseUnknown3A(IUnknown* pOuterUnknown);

  virtual ~TBaseUnknown3A();

  // INondelegatingUnknown interface ------------------------------------
  virtual HRESULT __stdcall NondelegatingQueryInterface(REFIID,void**)LCPI_CPP_CFG__METHOD__OVERRIDE;

  virtual ULONG   __stdcall NondelegatingAddRef()LCPI_CPP_CFG__METHOD__OVERRIDE;

  virtual ULONG   __stdcall NondelegatingRelease()LCPI_CPP_CFG__METHOD__OVERRIDE;

  // Initialization (especially for aggregates)
  virtual HRESULT Init();

  // Get component ID. Used in the error processing infrastructure.
  virtual REFCLSID GetComponentClassID()const;

 protected:
  // Notification to derived classes that we are releasing.
  virtual void FinalRelease();

 public: //---------------------------------------------------------------
  cnt_ref_type GetCntRef()const;

  IUnknown* GetNondelegatingUnknown();

  //Support for delegation
  IUnknown* GetOuterUnknown()const;

  bool IsAggregated()const;

 public:
  //Setup an external controller.
  void SetOuterUnknown(IUnknown* pNewUnkOuter);

  //Detaching the external controller of this object.
  void ResetOuterUnknown();

 public:
 #ifndef NDEBUG
  cnt_ref_type Debug__GetNondelegatingCntRef()const;

  cnt_ref_type Debug__GetInterfaceCntRef()const;
 #endif

 public: //---------------------------------------------------------------
  HRESULT __stdcall OuterUnknown__QueryInterface(REFIID riid,void** ppv);

  ULONG   __stdcall OuterUnknown__AddRef();

  ULONG   __stdcall OuterUnknown__Release();

 public: //Helper static function ----------------------------------------
  //
  // It is used in class-factory static function.
  //
  template<class tagComponent,class tagBaseUnknown>
  static HRESULT FinishCreate(tagComponent*    pNewObj,
                              tagBaseUnknown** ppObject);

  //
  // Full creating of COM object
  //
  static HRESULT FullCreate(TBaseUnknown3A* pNewObj,
                            REFIID          riid,
                            void**          ppv,
                            HRESULT         errAggregation=CLASS_E_NOAGGREGATION);//throw

  static HRESULT FinishQI(IUnknown* pI,void** ppv);

  static HRESULT FinishQI_Static(IUnknown* pI,void** ppv);

 protected:
  bool BaseUnknown__IsSupportedInterface(REFIID riid)const;

 private:
  typedef typename Allocator::template rebind<void>::other      raw_alloc_type;

 public: //---------------------------------------------------------------
  static void* operator new(size_t sz);

  static void operator delete (void* pv);

 private:
  //
  // Pointer to (external) outer IUnknown
  //
  IUnknown* /*const*/ m_pOuterUnknown;

  //
  // Reference count for this object
  //
  cnt_ref_type m_NondelegatingCntRef;

#ifndef NDEBUG
  //
  // Counter of usage our interfaces
  //
  cnt_ref_type m_InterfaceCntRef__debug;
#endif

 private:
#ifndef NDEBUG
  bool m_COM_OBJECT_IS_DESTROY;
#endif
};//class TBaseUnknown3A

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/com/base/com_base__base_unknown3a.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
