////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__mac_help_H_
#define _cpp_public_lcpi_lib_com_base__mac_help_H_

////////////////////////////////////////////////////////////////////////////////
//
// Delegating IUnknown
//   - Delegates to the nondelegating IUnknown, or to the
//     outer IUnknown if the component is aggregated.
//

#define OLE_LIB__DECLARE_IUNKNOWN                                         \
 virtual HRESULT __stdcall QueryInterface                                 \
                            (const IID& iid,                              \
                             void**     ppv) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL  \
 {                                                                        \
  return this->OuterUnknown__QueryInterface(iid,ppv);                     \
 }                                                                        \
                                                                          \
 virtual ULONG __stdcall AddRef() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL    \
 {                                                                        \
  return this->OuterUnknown__AddRef();                                    \
 }                                                                        \
                                                                          \
 virtual ULONG __stdcall Release() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL   \
 {                                                                        \
  return this->OuterUnknown__Release();                                   \
 }

////////////////////////////////////////////////////////////////////////////////
//implementation of TGetComponentClassID

#define OLE_LIB__DECLARE_GET_COMPONENT_CLASS_ID(ComponentID)              \
 virtual REFCLSID GetComponentClassID()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL  \
 {                                                                        \
  return ComponentID;                                                     \
 }

////////////////////////////////////////////////////////////////////////////////

#ifdef _TRACE_QUERY_INTERFACE_
# define OLE_LIB_TRACE_QUERY_INTERFACE(msg)                               \
   DebugMessage("QI:["<<typeid(*this).name()<<"]"                         \
                   "[this=0x"<<std::hex<<this<<std::dec<<"] "<<msg)
#else
# define OLE_LIB_TRACE_QUERY_INTERFACE(msg)
#endif

//------------------------------------------------------------------------
#ifdef _TRACE_QUERY_INTERFACE_
# define OLE_LIB_TRACE_QUERY_INTERFACE_FAIL(msg)                          \
   DebugMessage("NQI:["<<typeid(*this).name()<<"]"                        \
                   "[this=0x"<<std::hex<<this<<std::dec<<"] "<<msg)
#else
# define OLE_LIB_TRACE_QUERY_INTERFACE_FAIL(msg)
#endif

////////////////////////////////////////////////////////////////////////////////
//implementation of NondelegatingQueryInterface

#define OLE_LIB__DECLARE_ROOT_INTERFACE                                      \
 virtual HRESULT __stdcall NondelegatingQueryInterface                       \
                           (REFIID        riid,                              \
                            void**        ppv) LCPI_CPP_CFG__METHOD__OVERRIDE;

#define OLE_LIB__DEFINE_ROOT_INTERFACE_INL()                                 \
 virtual HRESULT __stdcall NondelegatingQueryInterface                       \
                            (REFIID       riid,                              \
                             void** const ppv) LCPI_CPP_CFG__METHOD__OVERRIDE  \
 {                                                                           \
  OLE_LIB__IMETHOD_PROLOG                                                    \
                                                                             \
  if(ppv==nullptr)                                                           \
   return E_POINTER;                                                         \
                                                                             \
  (*ppv)=nullptr;

#define OLE_LIB__DEFINE_ROOT_INTERFACE(Component)                            \
 HRESULT __stdcall Component::NondelegatingQueryInterface(REFIID       riid, \
                                                          void** const ppv)  \
 {                                                                           \
  OLE_LIB__IMETHOD_PROLOG                                                    \
                                                                             \
  if(ppv==nullptr)                                                           \
   return E_POINTER;                                                         \
                                                                             \
  (*ppv)=nullptr;

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_INTERFACE(obj_riid,obj)                             \
 if(riid==IID_##obj_riid)                                                 \
 {                                                                        \
  if(!(obj))                                                              \
  {                                                                       \
   OLE_LIB_TRACE_QUERY_INTERFACE_FAIL("iid=" #obj_riid);                  \
                                                                          \
   return E_NOINTERFACE;                                                  \
  }                                                                       \
                                                                          \
  return (obj)->NondelegatingQueryInterface(riid,ppv);                    \
 }

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_INTERFACE_IF(obj_riid,obj,if_cond)                  \
 if(riid==IID_##obj_riid)                                                 \
 {                                                                        \
  if(!(obj) || !(if_cond))                                                \
  {                                                                       \
   OLE_LIB_TRACE_QUERY_INTERFACE_FAIL("iid=" #obj_riid);                  \
                                                                          \
   return E_NOINTERFACE;                                                  \
  }                                                                       \
                                                                          \
  return (obj)->NondelegatingQueryInterface(riid,ppv);                    \
 }

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_STATIC_INTERFACE_NS(NS,__interface__)               \
 if(riid==NS##IID_##__interface__)                                        \
 {                                                                        \
  OLE_LIB_TRACE_QUERY_INTERFACE("iid=" #NS #__interface__);               \
                                                                          \
  return self_type::FinishQI_Static                                       \
            (static_cast<NS##__interface__*>(this),ppv);                  \
 }

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_STATIC_INTERFACE(__interface__)                     \
 OLE_LIB__ROOT_STATIC_INTERFACE_NS(,__interface__)

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_STATIC_INTERFACE_IF(__interface__,if_cond)          \
 if(riid==IID_##__interface__)                                            \
 {                                                                        \
  if(!(if_cond))                                                          \
  {                                                                       \
   OLE_LIB_TRACE_QUERY_INTERFACE_FAIL("iid=" #__interface__);             \
                                                                          \
   return E_NOINTERFACE;                                                  \
  }                                                                       \
                                                                          \
  OLE_LIB_TRACE_QUERY_INTERFACE("iid=" #__interface__);                   \
                                                                          \
  return self_type::FinishQI_Static                                       \
            (static_cast<__interface__*>(this),ppv);                      \
 }

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_AGGREGATION_INTERFACE(__interface__,obj)            \
 if(riid==IID_##__interface__)                                            \
 {                                                                        \
  if(!(obj))                                                              \
  {                                                                       \
   OLE_LIB_TRACE_QUERY_INTERFACE_FAIL("iid=" #__interface__);             \
                                                                          \
   return E_NOINTERFACE;                                                  \
  }                                                                       \
                                                                          \
  OLE_LIB_TRACE_QUERY_INTERFACE("aggregate iid=" #__interface__)          \
                                                                          \
  return (obj)->QueryInterface(riid,ppv);                                 \
 }

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_AGGREGATION_INTERFACE_IF(__interface__,obj,if_cond) \
 if(riid==IID_##__interface__)                                            \
 {                                                                        \
  if(!(obj) || !(if_cond))                                                \
  {                                                                       \
   OLE_LIB_TRACE_QUERY_INTERFACE_FAIL("iid=" #__interface__);             \
                                                                          \
   return E_NOINTERFACE;                                                  \
  }                                                                       \
                                                                          \
  OLE_LIB_TRACE_QUERY_INTERFACE("aggregate iid=" #__interface__)          \
                                                                          \
  return (obj)->QueryInterface(riid,ppv);                                 \
 }

//------------------------------------------------------------------------
#define OLE_LIB__ROOT_STATIC_INTERFACE_UUIDOF(__interface__)              \
 if(riid==__uuidof(__interface__))                                        \
 {                                                                        \
  OLE_LIB_TRACE_QUERY_INTERFACE("iid=" #__interface__);                   \
                                                                          \
  return FinishQI(static_cast<__interface__*>(this),ppv);                 \
 }

//------------------------------------------------------------------------
#define OLE_LIB__END_ROOT_INTERFACE(BaseComponent)                        \
  return BaseComponent::NondelegatingQueryInterface(riid,ppv);            \
 }

////////////////////////////////////////////////////////////////////////////////
#endif
