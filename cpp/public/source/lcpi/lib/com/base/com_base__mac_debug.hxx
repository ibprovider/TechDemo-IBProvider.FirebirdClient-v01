////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__mac_debug_H_
#define _cpp_public_lcpi_lib_com_base__mac_debug_H_

#if defined(_DEBUG_COM_LIVE_) && (_DEBUG_COM_LIVE_==1)
# include <lcpi/lib/structure/debug/t_debug__unique_instance_id.h>
#endif

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////

#if defined(_DEBUG_COM_LIVE_) && (_DEBUG_COM_LIVE_==1)

class t_debug_com_live__com_object_group{};

using t_debug_com_live__com_object_instance_id
 =structure::debug::t_debug__unique_instance_id
   <t_debug_com_live__com_object_group,
    unsigned __int64>;

#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

#define OLE_LIB__TRACE_NOT_IMPL(msg)          \
{                                             \
 DebugMessage("NOT IMPL:"<<msg);              \
 return E_NOTIMPL;                            \
}

#define OLE_LIB__DEFINE_NOT_IMPL(Class,Func)  \
HRESULT __stdcall Class::Func                 \
{                                             \
 OLE_LIB__IMETHOD_PROLOG                      \
                                              \
 TRACE_NOT_IMPL(#Class<<"::"<<#Func)          \
}

//////////////////////////////////////////////////////////////////////////////////////
//Macroses for debug COM-objects live
//
// In class declarations:
//  OLE_LIB__DECLARE_DEBUG_COM_LIVE(TClassName)
//
// Wite in CPP file:
//  OLE_LIB__DEFINE_DEBUG_COM_LIVE(TClassName)
//
// Write in constructor and destructor:
//  OLE_LIB__CREATE_COMPONENT()
//  OLE_LIB__DESTROY_COMPONENT()

#if defined(_DEBUG_COM_LIVE_2)
# error "Deprecated settings. Please define _DEBUG_COM_LIVE_=2 instead _DEBUG_COM_LIVE_2."
#endif

//Verification
#if   !defined(_DEBUG_COM_LIVE_)
#elif (_DEBUG_COM_LIVE_==0)
//ok
#elif (_DEBUG_COM_LIVE_==1)
//ok
#elif (_DEBUG_COM_LIVE_==2)
//ok
#else
# error Unexpected value of _DEBUG_COM_LIVE_
#endif

#if defined(NO_ODS) || !defined(_DEBUG_COM_LIVE_) || (_DEBUG_COM_LIVE_==0)

#define OLE_LIB__SPY_CLASS_INSTANCE(className)

#define OLE_LIB__DECLARE_DEBUG_COM_LIVE(classNameSign)

#define OLE_LIB__DEFINE_DEBUG_COM_LIVE2(templateHeader,className)
#define OLE_LIB__DEFINE_DEBUG_COM_LIVE(className)

#define OLE_LIB__CREATE_COMPONENT()
#define OLE_LIB__CREATE_COMPONENT1(text)

#define OLE_LIB__DESTROY_COMPONENT()
#define OLE_LIB__DESTROY_COMPONENT1(text)

#elif (_DEBUG_COM_LIVE_==1)

#define OLE_LIB__SPY_CLASS_INSTANCE(className)                                   \
 className::SpyGetClassInstance();

//------------------------------------------------------------------------
#define OLE_LIB__DECLARE_DEBUG_COM_LIVE(classNameSign)                           \
private:                                                                         \
 static size_t sm_debug_com_live___cInstances;                                   \
                                                                                 \
 const ::lcpi::lib::com::base::detail::t_debug_com_live__com_object_instance_id  \
    m_debug_com_live__InstanceID;                                                \
                                                                                 \
 static const char* COM_Name() {return #classNameSign;}                          \
                                                                                 \
 void SpyCreateComponent(structure::str_parameter comment=nullptr);              \
                                                                                 \
 void SpyDestroyComponent(structure::str_parameter comment=nullptr);             \
                                                                                 \
public:                                                                          \
 static void SpyGetClassInstance();

//------------------------------------------------------------------------
#define OLE_LIB__DEFINE_DEBUG_COM_LIVE2(templateHeader,                          \
                                        className)                               \
                                                                                 \
templateHeader                                                                   \
size_t className::sm_debug_com_live___cInstances=0;                              \
                                                                                 \
templateHeader                                                                   \
void className::SpyCreateComponent(structure::str_parameter comment)             \
{                                                                                \
 ::lcpi::lib::structure::mt::interlocked::increment                              \
    (&sm_debug_com_live___cInstances);                                           \
                                                                                 \
 DebugMessage("SPY: create #"<<m_debug_com_live__InstanceID.get_value()<<" "     \
              "[this=0x"<<std::hex<<this<<std::dec<<"]"                          \
              "["<<COM_Name()<<"] "<<                                            \
              comment.str()<<" "                                                 \
              "module lock count="<<_Module.GetLockCount());                     \
}                                                                                \
                                                                                 \
templateHeader                                                                   \
void className::SpyDestroyComponent(structure::str_parameter comment)            \
{                                                                                \
 ::lcpi::lib::structure::mt::interlocked::decrement                              \
    (&sm_debug_com_live___cInstances);                                           \
                                                                                 \
 DebugMessage("SPY: destroy #"<<m_debug_com_live__InstanceID.get_value()<<" "    \
              "[this=0x"<<std::hex<<this<<std::dec<<"]"                          \
              "["<<COM_Name()<<"] "<<                                            \
              comment.str()<<" "                                                 \
              "module lock count="<<(_Module.GetLockCount()-1));                 \
}                                                                                \
                                                                                 \
templateHeader                                                                   \
void className::SpyGetClassInstance()                                            \
{                                                                                \
 DebugMessage("Instance of "<<COM_Name()<<" "                                    \
              <<sm_debug_com_live___cInstances);                                 \
}

#define OLE_LIB__DEFINE_DEBUG_COM_LIVE(className)                                \
 OLE_LIB__DEFINE_DEBUG_COM_LIVE2(,className)

//------------------------------------------------------------------------
#define OLE_LIB__CREATE_COMPONENT()       SpyCreateComponent();
#define OLE_LIB__CREATE_COMPONENT1(text)  SpyCreateComponent(text);

#define OLE_LIB__DESTROY_COMPONENT()      SpyDestroyComponent();
#define OLE_LIB__DESTROY_COMPONENT1(text) SpyDestroyComponent(text);

#elif (_DEBUG_COM_LIVE_==2)

#define SPY_CLASS_INSTANCE(className) className::SpyGetClassInstance();

//------------------------------------------------------------------------
#define OLE_LIB__DECLARE_DEBUG_COM_LIVE(classNameSign)             \
private:                                                           \
 static size_t sm_debug_com_live___cInstances;                     \
                                                                   \
 static const char* COM_Name() {return #classNameSign;}            \
                                                                   \
 void SpyCreateComponent()                                         \
  {                                                                \
   ::lcpi::lib::structure::mt::interlocked::increment              \
     (&sm_debug_com_live___cInstances);                            \
  }                                                                \
                                                                   \
 void SpyDestroyComponent()                                        \
  {                                                                \
   ::lcpi::lib::structure::mt::decrement                           \
     (&sm_debug_com_live___cInstances);                            \
  }                                                                \
                                                                   \
public:                                                            \
 static void SpyGetClassInstance();

//------------------------------------------------------------------------
#define OLE_LIB__DEFINE_DEBUG_COM_LIVE2(templateHeader,              \
                                        className)                   \
templateHeader                                                       \
size_t className::sm_debug_com_live___cInstances=0;                  \
                                                                     \
templateHeader                                                       \
void className::SpyGetClassInstance()                                \
{                                                                    \
 DebugMessage                                                        \
  ("Instance of "<<COM_Name()<<" "<<sm_debug_com_live___cInstances); \
}

#define OLE_LIB__DEFINE_DEBUG_COM_LIVE(className)                  \
 OLE_LIB__DEFINE_DEBUG_COM_LIVE2(,className)

//------------------------------------------------------------------------
#define OLE_LIB__CREATE_COMPONENT()       SpyCreateComponent();
#define OLE_LIB__CREATE_COMPONENT1(text)  OLE_LIB__CREATE_COMPONENT()

//------------------------------------------------------------------------
#define OLE_LIB__DESTROY_COMPONENT()      SpyDestroyComponent();
#define OLE_LIB__DESTROY_COMPONENT1(text) OLE_LIB__DESTROY_COMPONENT()

#else

#error Unexpected value of _DEBUG_COM_LIVE_

#endif //else

//////////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif
