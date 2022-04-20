////////////////////////////////////////////////////////////////////////////////
// Макросы для отладки COM объектов
//                                                 Dmitry Kovalenko. 20.06.2000.

////////////////////////////////////////////////////////////////////////////////

#define OLE_LIB__TRACE_NOT_IMPL(msg)          \
{                                             \
 DebugMessage("NOT IMPL:"<<msg);              \
 return E_NOTIMPL;                            \
}

#define OLE_LIB__DEFINE_NOT_IMPL(Class,Func)  \
HRESULT __stdcall Class::Func                 \
{                                             \
 OLE_LIB_IMETHOD_PROLOG                       \
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
 unsigned __int64 m_debug_com_live__InstanceID;                                  \
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
#define OLE_LIB__DEFINE_DEBUG_COM_LIVE2(templateHeader,                    \
                                        className)                         \
                                                                           \
templateHeader                                                             \
size_t className::sm_debug_com_live___cInstances=0;                        \
                                                                           \
templateHeader                                                             \
void className::SpyCreateComponent(structure::str_parameter comment)       \
{                                                                          \
 ::InterlockedIncrement(&sm_debug_com_live___cInstances);                  \
                                                                           \
 m_debug_com_live__InstanceID                                              \
  =ole_lib::TBaseUnknown2::DebugComLive__GenInstanceID();                  \
                                                                           \
 DebugMessage("SPY: create #"<<m_debug_com_live__InstanceID<<" "           \
              "[this=0x"<<std::hex<<this<<std::dec<<"]"                    \
              "["<<COM_Name()<<"] "<<                                      \
              comment.str()<<" "                                           \
              "count="<<_Module.GetLockCount());                           \
}                                                                          \
                                                                           \
templateHeader                                                             \
void className::SpyDestroyComponent(structure::str_parameter comment)      \
{                                                                          \
 ::InterlockedDecrement(&sm_debug_com_live___cInstances);                  \
                                                                           \
 DebugMessage("SPY: destroy #"<<m_debug_com_live__InstanceID<<" "          \
              "[this=0x"<<std::hex<<this<<std::dec<<"]"                    \
              "["<<COM_Name()<<"] "<<                                      \
              comment.str()<<" "                                           \
              "count="<<(_Module.GetLockCount()-1));                       \
}                                                                          \
                                                                           \
templateHeader                                                             \
void className::SpyGetClassInstance()                                      \
{                                                                          \
 DebugMessage("Instance of "<<COM_Name()<<" "                              \
              <<sm_debug_com_live___cInstances);                           \
}

#define OLE_LIB__DEFINE_DEBUG_COM_LIVE(className)                          \
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
  {::InterlockedIncrement(&sm_debug_com_live___cInstances);}       \
                                                                   \
 void SpyDestroyComponent()                                        \
  {::InterlockedDecrement(&sm_debug_com_live___cInstances);}       \
                                                                   \
public:                                                            \
 static void SpyGetClassInstance();

//------------------------------------------------------------------------
#define OLE_LIB__DEFINE_DEBUG_COM_LIVE2(templateHeader,            \
                                        className)                 \
templateHeader                                                     \
size_t className::sm_debug_com_live___cInstances=0;                \
                                                                   \
templateHeader                                                     \
void className::SpyGetClassInstance()                              \
{                                                                  \
 DebugMessage("Instance of "<<COM_Name()<<" "                      \
                            <<sm_debug_com_live___cInstances);     \
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
//deprecated

#if 0 //[2020-03-29]

#define SPY_CLASS_INSTANCE(className)                                     \
 OLE_LIB__SPY_CLASS_INSTANCE(className)

#define DECLARE_DEBUG_COM_LIVE(classNameSign)                             \
 OLE_LIB__DECLARE_DEBUG_COM_LIVE(classNameSign)

#define DEFINE_DEBUG_COM_LIVE2(templateHeader,className)                  \
 OLE_LIB__DEFINE_DEBUG_COM_LIVE2(templateHeader,className)

#define DEFINE_DEBUG_COM_LIVE(className)                                  \
 OLE_LIB__DEFINE_DEBUG_COM_LIVE(className)

#define CREATE_COMPONENT()                                                \
 OLE_LIB__CREATE_COMPONENT()

#define CREATE_COMPONENT1(text)                                           \
 OLE_LIB__CREATE_COMPONENT1(text)

#define DESTROY_COMPONENT()                                               \
 OLE_LIB__DESTROY_COMPONENT()

#define DESTROY_COMPONENT1(text)                                          \
 OLE_LIB__DESTROY_COMPONENT1(text)

#endif

//////////////////////////////////////////////////////////////////////////////////////
