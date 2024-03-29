////////////////////////////////////////////////////////////////////////////////
//Helper macros for C++ exception handling
//                                            Kovalenko Dmitry. 08 January 2015.

////////////////////////////////////////////////////////////////////////////////
//C++ exception catching

#ifndef OLE_LIB__CURRENT_EXCEPTION_HANDLER
# define OLE_LIB__CURRENT_EXCEPTION_HANDLER(pInterface,                   \
                                            ComponentID,                  \
                                            InterfaceID,                  \
                                            CreateErrInfo)                \
   ole_lib::OLE_CurrentExceptionHandler__DefaultImpl                      \
    (ComponentID,                                                         \
     InterfaceID,                                                         \
     CreateErrInfo)

# ifndef OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER
#  define OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER 1
# endif

#else

# ifndef OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER
#  define OLE_LIB__BUILD_DEFAULT_CURRENT_EXCEPTION_HANDLER 0
# endif

#endif

#define _OLE_TRY_                                               \
 try

#define _OLE_CATCHES4_(pInterface,                              \
                       ComponentID,                             \
                       InterfaceID,                             \
                       CreateErrInfo)                           \
 catch(...)                                                     \
 {                                                              \
  hr=OLE_LIB__CURRENT_EXCEPTION_HANDLER                         \
      (pInterface,                                              \
       ComponentID,                                             \
       InterfaceID,                                             \
       CreateErrInfo);                                          \
 }

#define _OLE_CATCHES3_(ComponentID,                             \
                       InterfaceID,                             \
                       CreateErrInfo)                           \
 _OLE_CATCHES4_                                                 \
  (this,                                                        \
   ComponentID,                                                 \
   InterfaceID,                                                 \
   CreateErrInfo);                                              \

//------------------------------------------------------------------------
#define _OLE_CATCHES2_CODE_                                     \
 _OLE_CATCHES4_                                                 \
  (static_cast<IUnknown*>(nullptr),                             \
   CLSID_NULL,                                                  \
   IID_NULL,                                                    \
   false)

//------------------------------------------------------------------------
#define _OLE_CATCHES2_IID_(InterfaceID)                         \
 _OLE_CATCHES3_                                                 \
  (this->GetComponentClassID(),                                 \
   InterfaceID,                                                 \
   true)

////////////////////////////////////////////////////////////////////////////////
