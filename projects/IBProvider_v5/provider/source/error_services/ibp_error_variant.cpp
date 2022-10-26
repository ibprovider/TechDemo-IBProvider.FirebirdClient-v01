////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_variant.cpp
//! \brief   The structures for storing an error parameter
//! \author  Kovalenko Dmitry
//! \date    20.10.2022
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_variant.h"

#include "source/ibp_memory.h"

#include <structure/utilities/to_underlying.h>

#include <lcpi/lib/common_utilities.h>
#include <lcpi/infrastructure/os/windows-oleaut32.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_ERRORVARIANT_UTILS

void IBP_ERRORVARIANT_UTILS::LinkWith__EMPTY
                             (IBP_ERRORVARIANT* const DEBUG_CODE(pDest))
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 //pDest->vt=IBP_EVT::V_EMPTY;
}//LinkWith__EMPTY

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__NULL
                             (IBP_ERRORVARIANT* const pDest)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->vt=IBP_EVT::V_NULL;
}//LinkWith__NULL

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__IUNKNOWN
                             (IBP_ERRORVARIANT* const pDest,
                              IUnknown*         const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.punk=value;

 pDest->vt=IBP_EVT::V_IUNKNOWN;
}//LinkWith__IUNKNOWN

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__BSTR
                             (IBP_ERRORVARIANT* const pDest,
                              BSTR              const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueWStr.ptr=value;
 pDest->value.valueWStr.len=value?LCPI_OS__SysStringLen(value):0;

 pDest->vt=IBP_EVT::V_WSTR;
}//LinkWith__BSTR

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__STR
                             (IBP_ERRORVARIANT* const pDest,
                              str_box_type      const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 CHECK_READ_TYPED_PTR(value.ptr,value.len);

 pDest->value.valueStr.ptr=const_cast<char*>(value.ptr);
 pDest->value.valueStr.len=value.len;

 pDest->vt=IBP_EVT::V_STR;
}//LinkWith__STR

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__WSTR
                             (IBP_ERRORVARIANT* const pDest,
                              wstr_box_type     const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 CHECK_READ_TYPED_PTR(value.ptr,value.len);

 pDest->value.valueWStr.ptr=const_cast<wchar_t*>(value.ptr);
 pDest->value.valueWStr.len=value.len;

 pDest->vt=IBP_EVT::V_WSTR;
}//LinkWith__WSTR

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__BOOL
                             (IBP_ERRORVARIANT*              const pDest,
                              IBP_ERRORVARIANT_TYPES::T_BOOL const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueBool=value;

 pDest->vt=IBP_EVT::V_BOOL;
}//LinkWith__BOOL

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__GUID
                             (IBP_ERRORVARIANT*               const pDest,
                              const IBP_ERRORVARIANT_TYPES::T_GUID& value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueGuid=value;

 pDest->vt=IBP_EVT::V_GUID;
}//LinkWith__GUID

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__R8
                             (IBP_ERRORVARIANT*            const pDest,
                              IBP_ERRORVARIANT_TYPES::T_R8 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueR8=value;

 pDest->vt=IBP_EVT::V_R8;
}//LinkWith__R8

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__I1
                             (IBP_ERRORVARIANT*            const pDest,
                              IBP_ERRORVARIANT_TYPES::T_I1 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueI1=value;

 pDest->vt=IBP_EVT::V_I1;
}//LinkWith__I1

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__I2
                             (IBP_ERRORVARIANT*            const pDest,
                              IBP_ERRORVARIANT_TYPES::T_I2 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueI2=value;

 pDest->vt=IBP_EVT::V_I2;
}//LinkWith__I2

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__I4
                             (IBP_ERRORVARIANT*            const pDest,
                              IBP_ERRORVARIANT_TYPES::T_I4 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueI4=value;

 pDest->vt=IBP_EVT::V_I4;
}//LinkWith__I4

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__I8
                             (IBP_ERRORVARIANT*            const pDest,
                              IBP_ERRORVARIANT_TYPES::T_I8 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueI8=value;

 pDest->vt=IBP_EVT::V_I8;
}//LinkWith__I8

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__LONG
                             (IBP_ERRORVARIANT*              const pDest,
                              IBP_ERRORVARIANT_TYPES::T_LONG const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueLong=value;

 pDest->vt=IBP_EVT::V_LONG;
}//LinkWith__LONG

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__UI1
                             (IBP_ERRORVARIANT*             const pDest,
                              IBP_ERRORVARIANT_TYPES::T_UI1 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueUI1=value;

 pDest->vt=IBP_EVT::V_UI1;
}//LinkWith__UI1

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__UI2
                             (IBP_ERRORVARIANT*             const pDest,
                              IBP_ERRORVARIANT_TYPES::T_UI2 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueUI2=value;

 pDest->vt=IBP_EVT::V_UI2;
}//LinkWith__UI2

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__UI4
                             (IBP_ERRORVARIANT*             const pDest,
                              IBP_ERRORVARIANT_TYPES::T_UI4 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueUI4=value;

 pDest->vt=IBP_EVT::V_UI4;
}//LinkWith__UI4

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__UI8
                             (IBP_ERRORVARIANT*             const pDest,
                              IBP_ERRORVARIANT_TYPES::T_UI8 const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueUI8=value;

 pDest->vt=IBP_EVT::V_UI8;
}//LinkWith__UI8

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__ULONG
                             (IBP_ERRORVARIANT*               const pDest,
                              IBP_ERRORVARIANT_TYPES::T_ULONG const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueULong=value;

 pDest->vt=IBP_EVT::V_ULONG;
}//LinkWith__ULONG

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__IBP_MSG_CODE
                             (IBP_ERRORVARIANT*                      const pDest,
                              IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueIBProviderMsgCode=value;

 pDest->vt=IBP_EVT::V_IBP_MSG_CODE;
}//LinkWith__IBP_MSG_CODE

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__WIN32_ERR
                             (IBP_ERRORVARIANT*                   const pDest,
                              IBP_ERRORVARIANT_TYPES::T_WIN32_ERR const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.valueWin32Err=value;

 pDest->vt=IBP_EVT::V_WIN32_ERR;
}//LinkWith__WIN32_ERR

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__CPP_ERR_RECORD
                             (IBP_ERRORVARIANT*                            const pDest,
                              IBP_ERRORVARIANT_TYPES::T_CPP_ERR_RECORD_PTR const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.pCppErrRecord=value;

 pDest->vt=IBP_EVT::V_CPP_ERR_RECORD;
}//LinkWith__CPP_ERR_RECORD

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith__CPP_ERR_TEXT
                             (IBP_ERRORVARIANT*                          const pDest,
                              IBP_ERRORVARIANT_TYPES::T_CPP_ERR_TEXT_PTR const value)
{
 assert(pDest);
 assert(pDest->vt==IBP_EVT::V_EMPTY);

 pDest->value.pCppErrText=value;

 pDest->vt=IBP_EVT::V_CPP_ERR_TEXT;
}//LinkWith__CPP_ERR_TEXT

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IUnknown* const value)
{
 return self_type::LinkWith__IUNKNOWN(pDest,value);
}//LinkWith - IUnknown*

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,const char* const value)
{
 return self_type::LinkWith__STR(pDest,value);
}//LinkWith - const char*

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,str_box_type const value)
{
 return self_type::LinkWith__STR(pDest,value);
}//LinkWith - str_box_type

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,const wchar_t* const value)
{
 return self_type::LinkWith__WSTR(pDest,value);
}//LinkWith - const wchar_t*

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,wstr_box_type const value)
{
 return self_type::LinkWith__WSTR(pDest,value);
}//LinkWith - wstr_box_type

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_BOOL const value)
{
 return self_type::LinkWith__BOOL(pDest,value);
}//LinkWith - BOOL

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,const IBP_ERRORVARIANT_TYPES::T_GUID& value)
{
 return self_type::LinkWith__GUID(pDest,value);
}//LinkWith - GUID

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_R8 const value)
{
 return self_type::LinkWith__R8(pDest,value);
}//LinkWith - R8

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_I1 const value)
{
 return self_type::LinkWith__I1(pDest,value);
}//LinkWith - I1

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_I2 const value)
{
 return self_type::LinkWith__I2(pDest,value);
}//LinkWith - I2

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_I4 const value)
{
 return self_type::LinkWith__I4(pDest,value);
}//LinkWith - I4

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_I8 const value)
{
 return self_type::LinkWith__I8(pDest,value);
}//LinkWith - I8

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_LONG const value)
{
 return self_type::LinkWith__LONG(pDest,value);
}//LinkWith - LONG

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_UI1 const value)
{
 return self_type::LinkWith__UI1(pDest,value);
}//LinkWith - UI1

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_UI2 const value)
{
 return self_type::LinkWith__UI2(pDest,value);
}//LinkWith - UI2

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_UI4 const value)
{
 return self_type::LinkWith__UI4(pDest,value);
}//LinkWith - UI4

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_UI8 const value)
{
 return self_type::LinkWith__UI8(pDest,value);
}//LinkWith - UI8

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_ULONG const value)
{
 return self_type::LinkWith__ULONG(pDest,value);
}//LinkWith - ULONG

//------------------------------------------------------------------------
void IBP_ERRORVARIANT_UTILS::LinkWith(IBP_ERRORVARIANT* const pDest,IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE const value)
{
 return self_type::LinkWith__IBP_MSG_CODE(pDest,value);
}//LinkWith - IBP_MSG_CODE

////////////////////////////////////////////////////////////////////////////////
//class IBP_ErrorVariant::tag_impl

class IBP_ErrorVariant::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef tag_impl self_type;

 public:
  using raw_alloc_type
   =IBP_MemoryAllocator::rebind<void>::other;

 public:
  using PFN_Init
   = void (*) (IBP_ERRORVARIANT* const pVar,const IBP_ERRORVARIANT& Source);

  using PFN_Clear
   = void (*) (IBP_ERRORVARIANT* pVar);

 public:
  struct tag_type_svc
  {
#ifndef NDEBUG
   IBP_EVT   vt;
#endif
   PFN_Init  pfnInit;
   PFN_Clear pfnClear;
  };//struct tag_type_svc

#ifndef NDEBUG
 private:
  static const self_type sm_DEBUG_SingleInstance;

  tag_impl();
#endif

 public:
  static void ERRVAR_Clear__NONE      (IBP_ERRORVARIANT* pVar);
  static void ERRVAR_Clear__IUNKNOWN  (IBP_ERRORVARIANT* pVar);
  static void ERRVAR_Clear__STR       (IBP_ERRORVARIANT* pVar);
  static void ERRVAR_Clear__WSTR      (IBP_ERRORVARIANT* pVar);

  static void ERRVAR_Clear__CPP_ERR_RECORD
                (IBP_ERRORVARIANT* pVar);

  static void ERRVAR_Clear__CPP_ERR_TEXT
                (IBP_ERRORVARIANT* pVar);

 private:
  static void Helper__LowLevelInit    (IBP_ERRORVARIANT* pVar);

 public:
  static void ERRVAR_Init__EMPTY      (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__NULL       (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__IUNKNOWN   (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__STR        (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__WSTR       (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__BOOL       (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__GUID       (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__R8         (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__I1         (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__I2         (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__I4         (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__I8         (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__LONG       (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__UI1        (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__UI2        (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__UI4        (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__UI8        (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);
  static void ERRVAR_Init__ULONG      (IBP_ERRORVARIANT* pVar,const IBP_ERRORVARIANT& Source);

  static void ERRVAR_Init__IBP_MSG_CODE
                (IBP_ERRORVARIANT*       pVar,
                 const IBP_ERRORVARIANT& Source);

  static void ERRVAR_Init__WIN32_ERR
                (IBP_ERRORVARIANT*       pVar,
                 const IBP_ERRORVARIANT& Source);

  static void ERRVAR_Init__CPP_ERR_RECORD
                (IBP_ERRORVARIANT*       pVar,
                 const IBP_ERRORVARIANT& Source);

  static void ERRVAR_Init__CPP_ERR_TEXT
                (IBP_ERRORVARIANT*       pVar,
                 const IBP_ERRORVARIANT& Source);

 public:
  static void DEBUG__check__sm_TypeServices();

 public:
  static const tag_type_svc sm_TypeServices[];
};//class IBP_ErrorVariant::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class IBP_ErrorVariant::tag_impl

#ifndef NDEBUG

#define DEF_TYPE_SVC(vt,InitFuncSign,ClearFuncSign)                  \
 {                                                                   \
  IBP_EVT::V_##vt,                                                   \
  ERRVAR_Init__##InitFuncSign,                                       \
  ERRVAR_Clear__##ClearFuncSign                                      \
 },

#define DEF_TYPE_SVC__NONE                                           \
 {IBP_EVT::V_EMPTY,nullptr,nullptr},

#else

#define DEF_TYPE_SVC(vt,InitFuncSign,ClearFuncSign)                  \
 {                                                                   \
  ERRVAR_Init__##InitFuncSign,                                       \
  ERRVAR_Clear__##ClearFuncSign                                      \
 },

#define DEF_TYPE_SVC__NONE                                           \
 {nullptr,nullptr},

#endif

////////////////////////////////////////////////////////////////////////////////
//
// EMPTY        =0,
// NULL         =1,
//
// IUNKNOWN     =3,
// STR          =4,
// WSTR         =5,
// BOOL         =6,
// GUID         =7,
// R8           =8,
//
// I1           =10,
// I2           =11,
// I4           =12,
// I8           =13,
// LONG         =14,
//
// UI1          =20,
// UI2          =21,
// UI4          =22,
// UI8          =23,
// ULONG        =24,
//
////////////////////////////////////////////////////////////////////////////////

const IBP_ErrorVariant::tag_impl::tag_type_svc
 IBP_ErrorVariant::tag_impl::sm_TypeServices[]=
{
 /*  0 */ DEF_TYPE_SVC       (EMPTY           ,EMPTY        ,NONE)
 /*  1 */ DEF_TYPE_SVC       (NULL            ,NULL         ,NONE)
 /*  2 */ DEF_TYPE_SVC__NONE
 /*  3 */ DEF_TYPE_SVC       (IUNKNOWN        ,IUNKNOWN     ,IUNKNOWN)
 /*  4 */ DEF_TYPE_SVC       (STR             ,STR          ,STR)
 /*  5 */ DEF_TYPE_SVC       (WSTR            ,WSTR         ,WSTR)
 /*  6 */ DEF_TYPE_SVC       (BOOL            ,BOOL         ,NONE)
 /*  7 */ DEF_TYPE_SVC       (GUID            ,GUID         ,NONE)
 /*  8 */ DEF_TYPE_SVC       (R8              ,R8           ,NONE)
 /*  9 */ DEF_TYPE_SVC__NONE
 /* 10 */ DEF_TYPE_SVC       (I1              ,I1           ,NONE)
 /* 11 */ DEF_TYPE_SVC       (I2              ,I2           ,NONE)
 /* 12 */ DEF_TYPE_SVC       (I4              ,I4           ,NONE)
 /* 13 */ DEF_TYPE_SVC       (I8              ,I8           ,NONE)
 /* 14 */ DEF_TYPE_SVC       (LONG            ,LONG         ,NONE)
 /* 15 */ DEF_TYPE_SVC__NONE
 /* 16 */ DEF_TYPE_SVC__NONE
 /* 17 */ DEF_TYPE_SVC__NONE
 /* 18 */ DEF_TYPE_SVC__NONE
 /* 19 */ DEF_TYPE_SVC__NONE
 /* 20 */ DEF_TYPE_SVC       (UI1             ,UI1          ,NONE)
 /* 21 */ DEF_TYPE_SVC       (UI2             ,UI2          ,NONE)
 /* 22 */ DEF_TYPE_SVC       (UI4             ,UI4          ,NONE)
 /* 23 */ DEF_TYPE_SVC       (UI8             ,UI8          ,NONE)
 /* 24 */ DEF_TYPE_SVC       (ULONG           ,ULONG        ,NONE)
 /* 25 */ DEF_TYPE_SVC__NONE
 /* 26 */ DEF_TYPE_SVC__NONE
 /* 27 */ DEF_TYPE_SVC__NONE
 /* 28 */ DEF_TYPE_SVC__NONE
 /* 29 */ DEF_TYPE_SVC__NONE
 /* 30 */ DEF_TYPE_SVC       (IBP_MSG_CODE    ,IBP_MSG_CODE    ,NONE)
 /* 31 */ DEF_TYPE_SVC       (WIN32_ERR       ,WIN32_ERR       ,NONE)
 /* 32 */ DEF_TYPE_SVC       (CPP_ERR_RECORD  ,CPP_ERR_RECORD  ,CPP_ERR_RECORD)
 /* 33 */ DEF_TYPE_SVC       (CPP_ERR_TEXT    ,CPP_ERR_TEXT    ,CPP_ERR_TEXT)
 /* 34 */
};//sm_TypeServices

////////////////////////////////////////////////////////////////////////////////

#undef DEF_TYPE_SVC
#undef DEF_TYPE_SVC__NONE

////////////////////////////////////////////////////////////////////////////////
//DEBUG Verifications

#ifndef NDEBUG

const IBP_ErrorVariant::tag_impl
 IBP_ErrorVariant::tag_impl::sm_DEBUG_SingleInstance;

//------------------------------------------------------------------------
IBP_ErrorVariant::tag_impl::tag_impl()
{
 for(size_t i=0;i!=_LCPI_DIM_(sm_TypeServices);++i)
 {
  if(i>0 && sm_TypeServices[i].vt==IBP_EVT::V_EMPTY)
  {
   assert(sm_TypeServices[i].pfnInit==nullptr);
   assert(sm_TypeServices[i].pfnClear==nullptr);
  }
  else
  {
   assert(structure::to_underlying(sm_TypeServices[i].vt)==i);

   assert(sm_TypeServices[i].pfnInit!=nullptr);
   assert(sm_TypeServices[i].pfnClear!=nullptr);
  }
 }//for i
}//tag_impl

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//CLEAR Functions

void IBP_ErrorVariant::tag_impl::ERRVAR_Clear__NONE
                                           (IBP_ERRORVARIANT* const pVar)
{
 assert(pVar);

 Helper__LowLevelInit(pVar);
}//ERRVAR_Clear__NONE

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Clear__IUNKNOWN
                                           (IBP_ERRORVARIANT* const pVar)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_IUNKNOWN);

 auto const p=pVar->value.punk;

 Helper__LowLevelInit(pVar);

 //---------------------------
 if(p)
  p->Release();
}//ERRVAR_Clear__IUNKNOWN

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Clear__STR
                                           (IBP_ERRORVARIANT* const pVar)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_STR);

 auto const p=pVar->value.valueStr.ptr;

 Helper__LowLevelInit(pVar);

 //---------------------------
 if(p)
  raw_alloc_type::instance.deallocate(p,0);
}//ERRVAR_Clear__STR

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Clear__WSTR
                                           (IBP_ERRORVARIANT* const pVar)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_WSTR);

 auto const p=pVar->value.valueWStr.ptr;

 Helper__LowLevelInit(pVar);

 //---------------------------
 if(p)
  raw_alloc_type::instance.deallocate(p,0);
}//ERRVAR_Clear__WSTR

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Clear__CPP_ERR_RECORD
                                           (IBP_ERRORVARIANT* const pVar)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_CPP_ERR_RECORD);

 auto const p=pVar->value.pCppErrRecord;

 Helper__LowLevelInit(pVar);

 //---------------------------
 if(p)
  p->release();
}//ERRVAR_Clear__CPP_ERR_RECORD

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Clear__CPP_ERR_TEXT
                                           (IBP_ERRORVARIANT* const pVar)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_CPP_ERR_TEXT);

 auto const p=pVar->value.pCppErrText;

 Helper__LowLevelInit(pVar);

 //---------------------------
 if(p)
  p->release();
}//ERRVAR_Clear__CPP_ERR_TEXT

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::Helper__LowLevelInit(IBP_ERRORVARIANT* pVar)
{
 (*pVar)=IBP_ERRORVARIANT();

 assert(pVar->vt==IBP_EVT::V_EMPTY);
}//Helper__LowLevelInit

////////////////////////////////////////////////////////////////////////////////
//INIT Functions

void IBP_ErrorVariant::tag_impl::ERRVAR_Init__EMPTY
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_EMPTY);

 //pVar->vt=IBP_EVT::V_EMPTY;
}//ERRVAR_Init__EMPTY

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__NULL
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_NULL);

 pVar->vt=IBP_EVT::V_NULL;
}//ERRVAR_Init__NULL

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__IUNKNOWN
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_IUNKNOWN);

 if(Source.value.punk!=nullptr)
  Source.value.punk->AddRef();

 pVar->value.punk=Source.value.punk;

 pVar->vt=IBP_EVT::V_IUNKNOWN;
}//ERRVAR_Init__IUNKNOWN

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__STR
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_STR);

 CHECK_READ_TYPED_PTR(Source.value.valueStr.ptr,Source.value.valueStr.len);

 if(Source.value.valueStr.len==0)
 {
  pVar->value.valueStr.ptr =nullptr;
  pVar->value.valueStr.len =0;
 }
 else
 {
  assert(Source.value.valueStr.ptr);

  const size_t sz=sizeof(char)*Source.value.valueStr.len;

  pVar->value.valueStr.ptr
   =(char*)raw_alloc_type::instance.allocate(sz); //thrpw

  assert(pVar->value.valueStr.ptr!=nullptr);

  pVar->value.valueStr.len
   =Source.value.valueStr.len;

  memcpy(pVar->value.valueStr.ptr,Source.value.valueStr.ptr,sz);
 }//else

 pVar->vt=IBP_EVT::V_STR;
}//ERRVAR_Init__STR

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__WSTR
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_WSTR);


 if(Source.value.valueWStr.len==0)
 {
  pVar->value.valueWStr.ptr =nullptr;
  pVar->value.valueWStr.len =0;
 }
 else
 {
  assert(Source.value.valueWStr.ptr);

  const size_t sz=sizeof(wchar_t)*Source.value.valueWStr.len;

  pVar->value.valueWStr.ptr
   =(wchar_t*)raw_alloc_type::instance.allocate(sz); //thrpw

  assert(pVar->value.valueWStr.ptr!=nullptr);

  pVar->value.valueWStr.len
   =Source.value.valueWStr.len;

  memcpy(pVar->value.valueWStr.ptr,Source.value.valueWStr.ptr,sz);
 }//else

 pVar->vt=IBP_EVT::V_WSTR;
}//ERRVAR_Init__WSTR

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__BOOL
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_BOOL);

 pVar->value.valueBool = Source.value.valueBool;
 pVar->vt              = IBP_EVT::V_BOOL;
}//ERRVAR_Init__BOOL

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__GUID
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_GUID);

 pVar->value.valueGuid = Source.value.valueGuid;
 pVar->vt              = IBP_EVT::V_GUID;
}//ERRVAR_Init__GUID

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__R8
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_R8);

 pVar->value.valueR8  = Source.value.valueR8;
 pVar->vt             = IBP_EVT::V_R8;
}//ERRVAR_Init__R8

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__I1
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_I1);

 pVar->value.valueI1  = Source.value.valueI1;
 pVar->vt             = IBP_EVT::V_I1;
}//ERRVAR_Init__I1

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__I2
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_I2);

 pVar->value.valueI2  = Source.value.valueI2;
 pVar->vt             = IBP_EVT::V_I2;
}//ERRVAR_Init__I2

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__I4
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_I4);

 pVar->value.valueI4  = Source.value.valueI4;
 pVar->vt             = IBP_EVT::V_I4;
}//ERRVAR_Init__I4

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__I8
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_I8);

 pVar->value.valueI8  = Source.value.valueI8;
 pVar->vt             = IBP_EVT::V_I8;
}//ERRVAR_Init__I8

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__LONG
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_LONG);

 pVar->value.valueLong = Source.value.valueLong;
 pVar->vt              = IBP_EVT::V_LONG;
}//ERRVAR_Init__LONG

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__UI1
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_UI1);

 pVar->value.valueUI1 = Source.value.valueUI1;
 pVar->vt             = IBP_EVT::V_UI1;
}//ERRVAR_Init__UI1

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__UI2
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_UI2);

 pVar->value.valueUI2 = Source.value.valueUI2;
 pVar->vt             = IBP_EVT::V_UI2;
}//ERRVAR_Init__UI2

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__UI4
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_UI4);

 pVar->value.valueUI4 = Source.value.valueUI4;
 pVar->vt             = IBP_EVT::V_UI4;
}//ERRVAR_Init__UI4

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__UI8
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_UI8);

 pVar->value.valueUI8 = Source.value.valueUI8;
 pVar->vt             = IBP_EVT::V_UI8;
}//ERRVAR_Init__UI8

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__ULONG
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_ULONG);

 pVar->value.valueULong = Source.value.valueULong;
 pVar->vt               = IBP_EVT::V_ULONG;
}//ERRVAR_Init__ULONG

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__IBP_MSG_CODE
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_IBP_MSG_CODE);

 pVar->value.valueIBProviderMsgCode = Source.value.valueIBProviderMsgCode;
 pVar->vt                           = IBP_EVT::V_IBP_MSG_CODE;
}//ERRVAR_Init__IBP_MSG_CODE

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__WIN32_ERR
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_WIN32_ERR);

 pVar->value.valueWin32Err = Source.value.valueWin32Err;
 pVar->vt                  = IBP_EVT::V_WIN32_ERR;
}//ERRVAR_Init__WIN32_ERR

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__CPP_ERR_RECORD
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_CPP_ERR_RECORD);

 if(Source.value.pCppErrRecord!=nullptr)
  Source.value.pCppErrRecord->add_ref();

 pVar->value.pCppErrRecord=Source.value.pCppErrRecord;

 pVar->vt=IBP_EVT::V_CPP_ERR_RECORD;
}//ERRVAR_Init__CPP_ERR_RECORD

//------------------------------------------------------------------------
void IBP_ErrorVariant::tag_impl::ERRVAR_Init__CPP_ERR_TEXT
                                           (IBP_ERRORVARIANT* const pVar,
                                            const IBP_ERRORVARIANT& Source)
{
 assert(pVar);
 assert(pVar->vt==IBP_EVT::V_EMPTY);
 assert(Source.vt==IBP_EVT::V_CPP_ERR_TEXT);

 if(Source.value.pCppErrText!=nullptr)
  Source.value.pCppErrText->add_ref();

 pVar->value.pCppErrText=Source.value.pCppErrText;

 pVar->vt=IBP_EVT::V_CPP_ERR_TEXT;
}//ERRVAR_Init__CPP_ERR_TEXT

////////////////////////////////////////////////////////////////////////////////
//class IBP_ErrorVariant

IBP_ErrorVariant::IBP_ErrorVariant()
{
 assert(m_data.vt==IBP_EVT::V_EMPTY);
}//IBP_ErrorVariant

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(const self_type& x)
{
 assert(m_data.vt==IBP_EVT::V_EMPTY);

 this->Helper__Init(x.m_data);
}//IBP_ErrorVariant

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(const IBP_ERRORVARIANT& data)
{
 assert(m_data.vt==IBP_EVT::V_EMPTY);

 this->Helper__Init(data);
}//IBP_ErrorVariant - data

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IUnknown* const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_IUNKNOWN);
 assert(data.value.punk==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - IUnknown*

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(const char* const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_STR);
 assert(data.value.valueStr.ptr==value);
 assert(data.value.valueStr.len==(value?strlen(value):0));

 this->Helper__Init(data);
}//IBP_ErrorVariant - str_box_type

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(str_box_type value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_STR);
 assert(data.value.valueStr.ptr==value.ptr);
 assert(data.value.valueStr.len==value.len);

 this->Helper__Init(data);
}//IBP_ErrorVariant - str_box_type

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(const wchar_t* const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_WSTR);
 assert(data.value.valueWStr.ptr==value);
 assert(data.value.valueWStr.len==(value?wcslen(value):0));

 this->Helper__Init(data);
}//IBP_ErrorVariant - const wchar_t*

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(wstr_box_type const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_WSTR);
 assert(data.value.valueWStr.ptr==value.ptr);
 assert(data.value.valueWStr.len==value.len);

 this->Helper__Init(data);
}//IBP_ErrorVariant - wstr_box_type

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_BOOL const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_BOOL);
 assert(data.value.valueBool==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - bool

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(const IBP_ERRORVARIANT_TYPES::T_GUID& value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_GUID);
 assert(data.value.valueGuid==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - guid

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_R8 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_R8);
 assert(data.value.valueR8==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - r8

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I1 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I1);
 assert(data.value.valueI1==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - i1

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I2 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I2);
 assert(data.value.valueI2==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - i2

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I4 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I4);
 assert(data.value.valueI4==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - i4

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I8 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I8);
 assert(data.value.valueI8==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - i8

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_LONG const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_LONG);
 assert(data.value.valueLong==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - long

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI1 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI1);
 assert(data.value.valueUI1==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - ui1

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI2 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI2);
 assert(data.value.valueUI2==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - ui2

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI4 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI4);
 assert(data.value.valueUI4==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - ui4

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI8 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI8);
 assert(data.value.valueUI8==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - ui8

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_ULONG const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_ULONG);
 assert(data.value.valueULong==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - ulong

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_IBP_MSG_CODE);
 assert(data.value.valueIBProviderMsgCode==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - ibp_msg_code

//------------------------------------------------------------------------
IBP_ErrorVariant::IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_CPP_ERR_RECORD_PTR const value)
{
 assert(value);

 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith__CPP_ERR_RECORD(&data,value);

 assert(data.vt==IBP_EVT::V_CPP_ERR_RECORD);
 assert(data.value.pCppErrRecord==value);

 this->Helper__Init(data);
}//IBP_ErrorVariant - cpp err record

//------------------------------------------------------------------------
IBP_ErrorVariant::~IBP_ErrorVariant()
{
 this->Helper__Clear();

 assert(m_data.vt==IBP_EVT::V_EMPTY);
}//~IBP_ErrorVariant

//------------------------------------------------------------------------
const IBP_ERRORVARIANT& IBP_ErrorVariant::Data()const
{
 return m_data;
}//Data

//------------------------------------------------------------------------
void IBP_ErrorVariant::Swap(self_type& x)
{
 std::swap(m_data,x.m_data);
}//Swap

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetUnknown(IUnknown* const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_IUNKNOWN);
 assert(data.value.punk==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetUnknown

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetStr(str_box_type const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_STR);
 assert(data.value.valueStr.ptr==value.ptr);
 assert(data.value.valueStr.len==value.len);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetStr

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetWStr(wstr_box_type const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_WSTR);
 assert(data.value.valueWStr.ptr==value.ptr);
 assert(data.value.valueWStr.len==value.len);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetWStr

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetBool(IBP_ERRORVARIANT_TYPES::T_BOOL const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_BOOL);
 assert(data.value.valueBool==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetBool

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetGuid(const IBP_ERRORVARIANT_TYPES::T_GUID& value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_GUID);
 assert(data.value.valueGuid==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetGuid

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetR8(IBP_ERRORVARIANT_TYPES::T_R8 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_R8);
 assert(data.value.valueR8==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetR8

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetI1(IBP_ERRORVARIANT_TYPES::T_I1 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I1);
 assert(data.value.valueI1==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetI1

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetI2(IBP_ERRORVARIANT_TYPES::T_I2 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I2);
 assert(data.value.valueI2==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetI2

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetI4(IBP_ERRORVARIANT_TYPES::T_I4 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I4);
 assert(data.value.valueI4==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetI4

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetI8(IBP_ERRORVARIANT_TYPES::T_I8 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_I8);
 assert(data.value.valueI8==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetI8

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetLong(IBP_ERRORVARIANT_TYPES::T_LONG const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_LONG);
 assert(data.value.valueLong==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetLong

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetUI1(IBP_ERRORVARIANT_TYPES::T_UI1 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI1);
 assert(data.value.valueUI1==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetUI1

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetUI2(IBP_ERRORVARIANT_TYPES::T_UI2 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI2);
 assert(data.value.valueUI2==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetUI2

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetUI4(IBP_ERRORVARIANT_TYPES::T_UI4 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI4);
 assert(data.value.valueUI4==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetUI4

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetUI8(IBP_ERRORVARIANT_TYPES::T_UI8 const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_UI8);
 assert(data.value.valueUI8==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetUI8

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetULong(IBP_ERRORVARIANT_TYPES::T_ULONG const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_ULONG);
 assert(data.value.valueULong==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetULong

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::SetIBProviderMsgCode(IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE const value)
{
 IBP_ERRORVARIANT data;

 IBP_ERRORVARIANT_UTILS::LinkWith(&data,value);

 assert(data.vt==IBP_EVT::V_IBP_MSG_CODE);
 assert(data.value.valueIBProviderMsgCode==value);

 self_type tmp(data);

 this->Swap(tmp);

 return *this;
}//SetIBProviderMsgCode

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IUnknown* const value)
{
 return this->SetUnknown(value);
}//operator = IUnknown*

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (const char* const value)
{
 return this->SetStr(value);
}//operator = const char*

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (str_box_type const value)
{
 return this->SetStr(value);
}//operator = str_box_type

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (const wchar_t* const value)
{
 return this->SetWStr(value);
}//operator = const wchar_t*

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (wstr_box_type const value)
{
 return this->SetWStr(value);
}//operator = wstr_box_type

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_BOOL const value)
{
 return this->SetBool(value);
}//operator = bool

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (const IBP_ERRORVARIANT_TYPES::T_GUID& value)
{
 return this->SetGuid(value);
}//operator = guid

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_R8 const value)
{
 return this->SetR8(value);
}//operator = r8

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_I1 const value)
{
 return this->SetI1(value);
}//operator = i1

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_I2 const value)
{
 return this->SetI2(value);
}//operator = i2

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_I4 const value)
{
 return this->SetI4(value);
}//operator = i4

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_I8 const value)
{
 return this->SetI8(value);
}//operator = i8

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_LONG const value)
{
 return this->SetLong(value);
}//operator = long

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_UI1 const value)
{
 return this->SetUI1(value);
}//operator = ui1

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_UI2 const value)
{
 return this->SetUI2(value);
}//operator = ui2

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_UI4 const value)
{
 return this->SetUI4(value);
}//operator = ui4

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_UI8 const value)
{
 return this->SetUI8(value);
}//operator = ui8

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_ULONG const value)
{
 return this->SetULong(value);
}//operator = ulong

//------------------------------------------------------------------------
IBP_ErrorVariant& IBP_ErrorVariant::operator = (IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE const value)
{
 return this->SetIBProviderMsgCode(value);
}//operator = ibp_msg_code

//Helper methods ---------------------------------------------------------
void IBP_ErrorVariant::Helper__Init(const IBP_ERRORVARIANT& data)
{
 assert(m_data.vt==IBP_EVT::V_EMPTY);

 auto const vt_i=structure::to_underlying(data.vt);

 assert(vt_i<_LCPI_DIM_(tag_impl::sm_TypeServices));

 assert(tag_impl::sm_TypeServices[vt_i].vt==data.vt);

 assert(tag_impl::sm_TypeServices[vt_i].pfnInit!=nullptr);

 tag_impl::sm_TypeServices[vt_i].pfnInit(&m_data,data); //throw

 assert(m_data.vt==data.vt);
}//Helper__Init

//------------------------------------------------------------------------
void IBP_ErrorVariant::Helper__Clear()
{
 auto const vt_i=structure::to_underlying(m_data.vt);

 assert(vt_i<_LCPI_DIM_(tag_impl::sm_TypeServices));

 assert(tag_impl::sm_TypeServices[vt_i].vt==m_data.vt);

 assert(tag_impl::sm_TypeServices[vt_i].pfnClear!=nullptr);

 tag_impl::sm_TypeServices[vt_i].pfnClear(&m_data); //throw

 assert(m_data.vt==IBP_EVT::V_EMPTY);
}//Helper__Clear

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
