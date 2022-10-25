////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_variant.h
//! \brief   The structures for storing an error parameter
//! \author  Kovalenko Dmitry
//! \date    20.10.2022
#ifndef _ibp_error_variant_H_
#define _ibp_error_variant_H_

#include "source/error_services/ibp_error_codes.h"
#include "source/ibp_memory.h"

#include <structure/error/t_err_record.h>
#include <structure/t_const_str_box.h>

#include <OleAuto.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//enum class IBP_EVT

enum class IBP_EVT
{
 V_EMPTY        =0,           // VT_EMPTY
 V_NULL         =1,           // VT_NULL

 V_IUNKNOWN     =3,           // VT_UNKNOWN
 V_STR          =4,           // VT_BSTR
 V_WSTR         =5,           // VT_BSTR
 V_BOOL         =6,           // VT_BOOL
 V_GUID         =7,           // VT_BSTR
 V_R8           =8,           // VT_R8

 V_I1           =10,          // VT_I1
 V_I2           =11,          // VT_I2
 V_I4           =12,          // VT_INT
 V_I8           =13,          // VT_I8
 V_LONG         =14,          // VT_I4

 V_UI1          =20,          // VT_UI1
 V_UI2          =21,          // VT_UI2
 V_UI4          =22,          // VT_UINT
 V_UI8          =23,          // VT_UI8
 V_ULONG        =24,          // VT_UI4

 V_IBP_MSG_CODE    =30,
 V_WIN32_ERR       =31,
 V_CPP_ERR_RECORD  =32,
};//enum class IBP_EVT

////////////////////////////////////////////////////////////////////////////////
//IBP_ERRORVARIANT_TYPES

struct IBP_ERRORVARIANT_TYPES LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using T_BOOL  =bool;
  using T_GUID  =::GUID;

  using T_R8    =double;

  using T_I1    =signed __int8;
  using T_I2    =signed __int16;
  using T_I4    =signed __int32;
  using T_I8    =signed __int64;
  using T_LONG  =signed long;

  using T_UI1   =unsigned __int8;
  using T_UI2   =unsigned __int16;
  using T_UI4   =unsigned __int32;
  using T_UI8   =unsigned __int64;
  using T_ULONG =unsigned long;

  struct T_WSTR
  {
   public:
    size_t   len;
    wchar_t* ptr;
  };//struct T_WSTR

  struct T_STR
  {
   public:
    size_t   len;
    char*    ptr;
  };//struct T_STR

 using T_IBP_MSG_CODE = ibp::ibp_msg_code_type;

 using T_WIN32_ERR      = T_LONG;

 using T_CPP_ERR_RECORD_PTR = structure::t_err_record*;
};//struct IBP_ERRORVARIANT_TYPES

////////////////////////////////////////////////////////////////////////////////
//struct IBP_ERRORVARIANT

struct IBP_ERRORVARIANT LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  IBP_EVT  vt;

  union
  {
   IUnknown*                        punk;

   IBP_ERRORVARIANT_TYPES::T_BOOL   valueBool;
   IBP_ERRORVARIANT_TYPES::T_GUID   valueGuid;

   IBP_ERRORVARIANT_TYPES::T_R8     valueR8;

   IBP_ERRORVARIANT_TYPES::T_I1     valueI1;
   IBP_ERRORVARIANT_TYPES::T_I2     valueI2;
   IBP_ERRORVARIANT_TYPES::T_I4     valueI4;
   IBP_ERRORVARIANT_TYPES::T_I8     valueI8;
   IBP_ERRORVARIANT_TYPES::T_LONG   valueLong;

   IBP_ERRORVARIANT_TYPES::T_UI1    valueUI1;
   IBP_ERRORVARIANT_TYPES::T_UI2    valueUI2;
   IBP_ERRORVARIANT_TYPES::T_UI4    valueUI4;
   IBP_ERRORVARIANT_TYPES::T_UI8    valueUI8;
   IBP_ERRORVARIANT_TYPES::T_ULONG  valueULong;

   IBP_ERRORVARIANT_TYPES::T_STR    valueStr;
   IBP_ERRORVARIANT_TYPES::T_WSTR   valueWStr;

   IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE   valueIBProviderMsgCode;

   IBP_ERRORVARIANT_TYPES::T_WIN32_ERR      valueWin32Err;

   IBP_ERRORVARIANT_TYPES::T_CPP_ERR_RECORD_PTR pCppErrRecord;
  } value;

 IBP_ERRORVARIANT()
 {
  memset(this,0,sizeof(*this));
 }
};//struct IBP_ERRORVARIANT

////////////////////////////////////////////////////////////////////////////////
//class IBP_ERRORVARIANT_UTILS

class IBP_ERRORVARIANT_UTILS LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef IBP_ERRORVARIANT_UTILS            self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_str_box        str_box_type;
  typedef structure::t_const_wstr_box       wstr_box_type;

 public:
  static void LinkWith__EMPTY
               (IBP_ERRORVARIANT* pDest);

  static void LinkWith__NULL
               (IBP_ERRORVARIANT* pDest);

  static void LinkWith__IUNKNOWN
               (IBP_ERRORVARIANT* pDest,
                IUnknown*         value);

  static void LinkWith__BSTR
               (IBP_ERRORVARIANT* pDest,
                BSTR              value);

  static void LinkWith__STR
               (IBP_ERRORVARIANT* pDest,
                str_box_type      value);

  static void LinkWith__WSTR
               (IBP_ERRORVARIANT* pDest,
                wstr_box_type     value);

  static void LinkWith__BOOL
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_BOOL         value);

  static void LinkWith__GUID
               (IBP_ERRORVARIANT*                      pDest,
                const IBP_ERRORVARIANT_TYPES::T_GUID&  value);

  static void LinkWith__R8
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_R8           value);

  static void LinkWith__I1
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_I1           value);

  static void LinkWith__I2
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_I2           value);

  static void LinkWith__I4
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_I4           value);

  static void LinkWith__I8
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_I8           value);

  static void LinkWith__LONG
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_LONG         value);

  static void LinkWith__UI1
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_UI1          value);

  static void LinkWith__UI2
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_UI2          value);

  static void LinkWith__UI4
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_UI4          value);

  static void LinkWith__UI8
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_UI8          value);

  static void LinkWith__ULONG
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_ULONG        value);

  static void LinkWith__IBP_MSG_CODE
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE value);

  static void LinkWith__WIN32_ERR
               (IBP_ERRORVARIANT*                      pDest,
                IBP_ERRORVARIANT_TYPES::T_WIN32_ERR    value);

  static void LinkWith__CPP_ERR_RECORD_PTR
               (IBP_ERRORVARIANT*                            pDest,
                IBP_ERRORVARIANT_TYPES::T_CPP_ERR_RECORD_PTR value);

 public:
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IUnknown*     value);

  static void LinkWith         (IBP_ERRORVARIANT* pDest,const char*   value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,str_box_type  value);

  static void LinkWith         (IBP_ERRORVARIANT* pDest,const wchar_t* value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,wstr_box_type  value);

  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_BOOL  value);

  static void LinkWith         (IBP_ERRORVARIANT* pDest,const IBP_ERRORVARIANT_TYPES::T_GUID& value);

  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_R8    value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_I1    value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_I2    value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_I4    value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_I8    value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_LONG  value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_UI1   value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_UI2   value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_UI4   value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_UI8   value);
  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_ULONG value);

  static void LinkWith         (IBP_ERRORVARIANT* pDest,IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE value);
};//class IBP_ERRORVARIANT_UTILS

////////////////////////////////////////////////////////////////////////////////
//class IBP_ErrorVariant

class IBP_ErrorVariant LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef IBP_ErrorVariant                  self_type;

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_str_box        str_box_type;
  typedef structure::t_const_wstr_box       wstr_box_type;

 public:
  IBP_ErrorVariant();

  IBP_ErrorVariant(const self_type& x);

  IBP_ErrorVariant(const IBP_ERRORVARIANT& data);

  IBP_ErrorVariant(IUnknown* value);

  IBP_ErrorVariant(const char*  value);
  IBP_ErrorVariant(str_box_type value);

  IBP_ErrorVariant(const wchar_t* value);
  IBP_ErrorVariant(wstr_box_type  value);

  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_BOOL  value);

  IBP_ErrorVariant(const IBP_ERRORVARIANT_TYPES::T_GUID& value);

  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_R8    value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I1    value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I2    value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I4    value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_I8    value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_LONG  value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI1   value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI2   value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI4   value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_UI8   value);
  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_ULONG value);

  IBP_ErrorVariant(IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE value);

 ~IBP_ErrorVariant();

  //interface ------------------------------------------------------------
  const IBP_ERRORVARIANT& Data()const;

  //----------------------------------------------------------------------
  void Swap(self_type& x);

  //----------------------------------------------------------------------
  self_type& SetUnknown(IUnknown* value);

  self_type& SetStr    (str_box_type value);
  self_type& SetWStr   (wstr_box_type value);

  self_type& SetBool   (IBP_ERRORVARIANT_TYPES::T_BOOL  value);

  self_type& SetGuid   (const IBP_ERRORVARIANT_TYPES::T_GUID& value);

  self_type& SetR8     (IBP_ERRORVARIANT_TYPES::T_R8    value);
  self_type& SetI1     (IBP_ERRORVARIANT_TYPES::T_I1    value);
  self_type& SetI2     (IBP_ERRORVARIANT_TYPES::T_I2    value);
  self_type& SetI4     (IBP_ERRORVARIANT_TYPES::T_I4    value);
  self_type& SetI8     (IBP_ERRORVARIANT_TYPES::T_I8    value);
  self_type& SetLong   (IBP_ERRORVARIANT_TYPES::T_LONG  value);
  self_type& SetUI1    (IBP_ERRORVARIANT_TYPES::T_UI1   value);
  self_type& SetUI2    (IBP_ERRORVARIANT_TYPES::T_UI2   value);
  self_type& SetUI4    (IBP_ERRORVARIANT_TYPES::T_UI4   value);
  self_type& SetUI8    (IBP_ERRORVARIANT_TYPES::T_UI8   value);
  self_type& SetULong  (IBP_ERRORVARIANT_TYPES::T_ULONG value);

  self_type& SetIBProviderMsgCode(IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE value);

  //----------------------------------------------------------------------
  self_type& operator = (IUnknown* value);

  self_type& operator = (const char*  value);
  self_type& operator = (str_box_type value);

  self_type& operator = (const wchar_t* value);
  self_type& operator = (wstr_box_type  value);

  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_BOOL  value);

  self_type& operator = (const IBP_ERRORVARIANT_TYPES::T_GUID& value);

  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_R8    value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_I1    value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_I2    value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_I4    value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_I8    value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_LONG  value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_UI1   value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_UI2   value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_UI4   value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_UI8   value);
  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_ULONG value);

  self_type& operator = (IBP_ERRORVARIANT_TYPES::T_IBP_MSG_CODE value);

 private:
  void Helper__Clear();

  void Helper__Init(const IBP_ERRORVARIANT& data);

 private:
  class tag_impl;

 private:
  IBP_ERRORVARIANT m_data;
};//class IBP_ErrorVariant

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
