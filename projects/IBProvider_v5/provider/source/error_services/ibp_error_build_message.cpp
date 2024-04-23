////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_build_message.cpp
//! \brief   Утилиты для формирования текста ошибки
//! \author  Kovalenko Dmitry
//! \date    03.02.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_build_message.h"
#include "source/ibp_memory.h"

#include "rc/ibp_msg_err_ids.rh"

#include <ole_lib/ole_auto/ole_auto_variant.h>

#include <structure/t_str_formatter.h>
#include <structure/t_dynamic_array.h>
#include <structure/t_function.h>

#include <lcpi/lib/structure/utilities/string/trim.h>
#include <lcpi/lib/structure/utilities/to_hex.h>
#include <lcpi/lib/structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_MessageTextBuilder

std::wstring TIBP_MessageTextBuilder::GetSystemErrorMsg(LCID  const lcid,
                                                        DWORD const errorCode)
{
 //! \todo
 //!  Append the terminate point?

 WCHAR* Pointer=nullptr;

 const DWORD res
  =::FormatMessageW
      (FORMAT_MESSAGE_ALLOCATE_BUFFER |
       FORMAT_MESSAGE_IGNORE_INSERTS |
       FORMAT_MESSAGE_FROM_SYSTEM |
       FORMAT_MESSAGE_MAX_WIDTH_MASK,
       0,
       errorCode,
       LANGIDFROMLCID(lcid),
       (WCHAR*)&Pointer,
       0,
       NULL);

 if(res==0)
 {
  assert(!Pointer);

  std::wstring result;

  result =L"<failed to get the message of system error 0x";
  result+=lib::structure::to_hex::upper<wchar_t>(errorCode).c_str();
  result+=L">";

  return result;
 }//if res==0

 assert_hint(res>0);

 if(!Pointer)
 {
  assert_msg(false,"errorCode=0x"<<std::hex<<errorCode);

  std::wstring result;

  result =L"<[bug check] null pointer to message of system error 0x";
  result+=lib::structure::to_hex::upper<wchar_t>(errorCode).c_str();
  result+=L">";

  return result;
 }//if !Pointer

 assert(Pointer);

 CHECK_READ_TYPED_PTR(Pointer,res);

 typedef HLOCAL __stdcall t_local_free(HLOCAL);

 //automated call of LocalFree
 typedef structure::t_auto_fun_1<t_local_free*,HLOCAL> auto_free_type;

 const auto_free_type _local_free(::LocalFree,Pointer);

 WCHAR* const ePointer=lib::structure::total_skip_spaces_back(Pointer,Pointer+res);

 if(Pointer==ePointer)
 {
  std::wstring result;

  result =L"<[bug check] empty message of system error 0x";
  result+=lib::structure::to_hex::upper<wchar_t>(errorCode).c_str();
  result+=L">";

  return result;
 }//if

 //! \note
 //!  No end pointer.
 return std::wstring(Pointer,ePointer);
}//GetSystemErrorMsg

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::BuildSrc(std::wstring* const pResultText,
                                       const VARIANT&      varSourceID)
{
 assert(pResultText);

 pResultText->clear();

 if(varSourceID.vt==VT_EMPTY)
 {
  structure::tstr_to_tstr(pResultText,_Module.Get_IBProvider_ProgID());

  return true;
 }//if VT_EMPTY

 if(varSourceID.vt==VT_BSTR)
 {
  ole_lib::BStrToWStr(pResultText,varSourceID.bstrVal);

  return true;
 }//if VT_BSTR

 if(varSourceID.vt==VT_UNKNOWN)
 {
  ole_lib::TBSTR bstrValue;

  const auto get_r
   =Helper__GetErrorSource
     (varSourceID.punkVal,
      /*lcid*/0,
      &bstrValue);

  if(get_r.first!=enumGetDataFlag::ok)
   return false;

  if(FAILED(get_r.second))
   return false;

  ole_lib::BStrToWStr(pResultText,bstrValue.bstr());

  return true;
 }//if VT_UNKNOWN

 return false;
}//BuildSrc

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Build(std::wstring*               const pResultText,
                                    const VARIANT&                    varSubSystemId,
                                    DWORD                       const msg_code,
                                    LCID                        const lcid,
                                    size_t                      const cArgs,
                                    const IBP_ErrorVariant*     const rgArgs,
                                    HRESULT                     const ErrorCode)
{
 assert(pResultText!=nullptr);

 CHECK_READ_TYPED_PTR(rgArgs,cArgs);

 structure::t_dynamic_array<IBP_ERRORVARIANT,IBP_MemoryAllocator> tmp(cArgs);

 for(size_t i=0;i!=cArgs;++i)
  tmp[i]=rgArgs[i].Data();

 return self_type::Build
         (pResultText,
          varSubSystemId,
          msg_code,
          lcid,
          cArgs,
          tmp.data(),
          ErrorCode);
}//Build - IBP_ErrorVariant

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Build(std::wstring*               const pResultText,
                                    DWORD                       const msg_code,
                                    LCID                        const lcid,
                                    size_t                      const cArgs,
                                    const IBP_ErrorVariant*     const rgArgs,
                                    const TIBP_MsgTableLoader&        MsgTableLoader)
{
 assert(pResultText!=nullptr);

 CHECK_READ_TYPED_PTR(rgArgs,cArgs);

 structure::t_dynamic_array<IBP_ERRORVARIANT,IBP_MemoryAllocator> tmp(cArgs);

 for(size_t i=0;i!=cArgs;++i)
  tmp[i]=rgArgs[i].Data();

 return self_type::Helper__BuildDescription
         (pResultText,
          msg_code,
          lcid,
          cArgs,
          tmp.data(),
          MsgTableLoader);
}//Build - IBP_ErrorVariant

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Build(std::wstring*               const pResultText,
                                    const VARIANT&                    varSubSystemId,
                                    DWORD                       const msg_code,
                                    LCID                        const lcid,
                                    size_t                      const cArgs,
                                    const IBP_ERRORVARIANT*     const rgArgs,
                                    HRESULT                     const ErrorCode)
{
 //Обработка стандартных ошибок OLEDB ------------------------------------
 if(msg_code==IDENTIFIER_SDK_ERROR)
 {
  (*pResultText)=self_type::GetSystemErrorMsg(lcid,ErrorCode);
 }
 else
 if(!self_type::Helper__BuildDescription(pResultText,
                                         msg_code,
                                         lcid,
                                         cArgs,
                                         rgArgs,
                                         _ErrMsgTableLoader))
 {
  return false;
 }//if

 std::wstring SubSystemName;

 if(self_type::Helper__BuildSubSystemName(&SubSystemName,
                                          varSubSystemId,
                                          lcid)==S_FALSE)
 {
  return true;
 }//if

 {
  std::wstring msgTemplate;

  _ErrMsgTableLoader.GetMessage_Throw
    (IBP_MCE_SUBSYSTEM_ERROR_MSG_TEMPLATE_2,
     lcid,
     msgTemplate);

  structure::wstr_formatter fmsg(msgTemplate);

  fmsg<<SubSystemName<<*pResultText;

  (*pResultText)=fmsg.str();
 }//local

 return true;
}//Build - IBP_ERRORVARIANT

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Build(std::wstring*               const pResultText,
                                    DWORD                       const msg_code,
                                    LCID                        const lcid,
                                    size_t                      const cArgs,
                                    const IBP_ERRORVARIANT*     const rgArgs,
                                    const TIBP_MsgTableLoader&        MsgTableLoader)
{
 assert(pResultText!=nullptr);

 CHECK_READ_TYPED_PTR(rgArgs,cArgs);

 return self_type::Helper__BuildDescription
         (pResultText,
          msg_code,
          lcid,
          cArgs,
          rgArgs,
          MsgTableLoader);
}//Build - IBP_ERRORVARIANT

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Helper__BuildDescription
                                      (std::wstring*               const pResultText,
                                       DWORD                       const msg_code,
                                       LCID                        const lcid,
                                       size_t                      const cArgs,
                                       const IBP_ERRORVARIANT*     const rgArgs,
                                       const TIBP_MsgTableLoader&        MsgTableLoader)
{
 assert(pResultText!=nullptr);

 CHECK_READ_TYPED_PTR(rgArgs,cArgs);

 //использование кода сообщения для загрузки шаблона из ресурса ----------
 structure::wstr_formatter fmsg;

 {
  std::wstring wstr;

  const TIBP_MsgTableLoader::error_code_type
   ldrErr
    =MsgTableLoader.GetMessage
      (msg_code,
       lcid,
       wstr);

  if(ldrErr!=TIBP_MsgTableLoader::err_none)
  {
   fmsg(L"[IBP] Failed to load the message [ID: %1]. LdrErr: %2.")
    <<msg_code
    <<ldrErr;

   (*pResultText)=fmsg.str();

   return false;
  }//if not found

  fmsg(wstr);
 }//local

 //устанавливаем параметры

 for(const IBP_ERRORVARIANT *pv=rgArgs,* const _end=rgArgs+cArgs;pv!=_end;++pv)
 {
  if(pv->vt==IBP_EVT::V_IUNKNOWN) //вложенная ошибка
  {
   ole_lib::TBSTR bstrValue;

   const auto get_r
    =Helper__GetErrorDescription
      (pv->value.punk,
       lcid,
       &bstrValue);

   fmsg<<Helper__ToText(get_r,bstrValue);

   continue;
  }//if - вложенная ошибка

  switch(pv->vt)
  {
   case IBP_EVT::V_EMPTY:
    fmsg<<L"#EMPTY";
    break;

   case IBP_EVT::V_NULL:
    fmsg<<L"NULL";
    break;

   case IBP_EVT::V_STR:
    fmsg<<structure::make_str_box(pv->value.valueStr.ptr,pv->value.valueStr.len);
    break;

   case IBP_EVT::V_WSTR:
    fmsg<<structure::make_str_box(pv->value.valueWStr.ptr,pv->value.valueWStr.len);
    break;

   case IBP_EVT::V_BOOL:
    fmsg<<(pv->value.valueBool?L"true":L"false");
    break;

   case IBP_EVT::V_GUID:
    fmsg<<ole_lib::guid_to_wstring(pv->value.valueGuid);
    break;

   case IBP_EVT::V_R8:
    fmsg<<pv->value.valueR8;
    break;

   case IBP_EVT::V_I1:
    fmsg<<pv->value.valueI1;
    break;
   case IBP_EVT::V_I2:
    fmsg<<pv->value.valueI2;
    break;

   case IBP_EVT::V_I4:
    fmsg<<pv->value.valueI4;
    break;

   case IBP_EVT::V_I8:
    fmsg<<pv->value.valueI8;
    break;

   case IBP_EVT::V_LONG:
    fmsg<<pv->value.valueLong;
    break;

   case IBP_EVT::V_UI1:
    fmsg<<pv->value.valueUI1;
    break;

   case IBP_EVT::V_UI2:
    fmsg<<pv->value.valueUI2;
    break;

   case IBP_EVT::V_UI4:
    fmsg<<pv->value.valueUI4;
    break;

   case IBP_EVT::V_UI8:
    fmsg<<pv->value.valueUI8;
    break;

   case IBP_EVT::V_ULONG:
    fmsg<<pv->value.valueULong;
    break;

   case IBP_EVT::V_IBP_MSG_CODE:
   {
    std::wstring tmp;

    const auto r
     =self_type::Build
       (&tmp,
        ole_lib::TVariant::empty_variant,
        pv->value.valueIBProviderMsgCode,
        lcid,
        0,
        reinterpret_cast<const IBP_ERRORVARIANT*>(nullptr),
        E_FAIL);

    if(r)
     fmsg<<std::move(tmp);
    else
     fmsg<<L"<bad ibp msg code>";

    break;
   }//case - V_IBP_MSG_CODE

   case IBP_EVT::V_WIN32_ERR:
   {
    std::wstring tmp
     (self_type::GetSystemErrorMsg
       (lcid,
        pv->value.valueWin32Err));

    fmsg<<std::move(tmp);

    break;
   }//case - V_WIN32_ERR

   case IBP_EVT::V_CPP_ERR_RECORD:
   {
    assert(pv->value.pCppErrRecord!=nullptr);

    if(pv->value.pCppErrRecord==nullptr)
    {
     fmsg<<L"<null ptr to error record>";
    }
    else
    {
     std::wstring tmp;

     if(!pv->value.pCppErrRecord->get_description(lcid,nullptr,&tmp))
     {
      fmsg<<L"<can't get error record description>";
     }
     else
     {
      fmsg<<std::move(tmp);
     }
    }//else

    break;
   }//case - V_CPP_ERR_RECORD

   case IBP_EVT::V_CPP_ERR_TEXT:
   {
    assert(pv->value.pCppErrText!=nullptr);

    if(pv->value.pCppErrText==nullptr)
    {
     fmsg<<L"<null ptr to error text>";
    }
    else
    {
     std::wstring tmp;

     if(!pv->value.pCppErrText->get_text(lcid,&tmp))
     {
      fmsg<<L"<can't get error text>";
     }
     else
     {
      fmsg<<std::move(tmp);
     }
    }//else

    break;
   }//case - V_CPP_ERR_TEXT

   default:
    assert_msg(false,"vt="<<lib::structure::to_underlying(pv->vt));

    fmsg<<L"???";
    break;
  }//switch
 }//for pv

 {
  const std::wstring fmsg_str=fmsg.str();

  //--------------------------
  // [2022-10-21] Simple shielding non-printable symbols.

  std::wstring tmp;

  const auto _bs=fmsg_str.cbegin();
  const auto _es=fmsg_str.cend();

  auto ps=_bs;

  while(ps!=_es)
  {
   assert(ps<_es);

   auto x=std::find(ps,_es,0);

   tmp.append(ps,x);

   if(x==_es)
    break;

   tmp+=L"[#00]";

   ++x;

   ps=x;
  }//while

  //--------------------------
  lib::structure::total_self_trim(tmp);

  //--------------------------
  if(tmp.empty())
  {
   fmsg(L"[IBP] Unknown internal error. MsgCode: %1.")
    <<msg_code;

   tmp=fmsg.str();
  }//if

  pResultText->swap(tmp);
 }//local

 return true;
}//Helper__BuildDescription

//------------------------------------------------------------------------
HRESULT TIBP_MessageTextBuilder::Helper__BuildSubSystemName
                                           (std::wstring* const pResultText,
                                            const VARIANT&      varSubSystemId,
                                            LCID          const lcid)
{
 assert(pResultText);

 if(varSubSystemId.vt==VT_EMPTY)
 {
  return S_FALSE;
 }//if

 if(varSubSystemId.vt==VT_I4)
 {
  if(!structure::can_numeric_cast<UINT>(varSubSystemId.lVal))
  {
   structure::wstr_formatter fmsg(L"Incorrect ID of subsystem: %1");

   fmsg<<varSubSystemId.lVal;

   (*pResultText)=fmsg.str();

   return E_FAIL;
  }//if

  const TIBP_MsgTableLoader::error_code_type
   ldrErr
    =_SubSystemNameTableLoader.GetMessage
      ((UINT)varSubSystemId.llVal,
       lcid,
       *pResultText);

  if(ldrErr==TIBP_MsgTableLoader::err_none)
  {
   return S_OK;
  }//if

  structure::wstr_formatter
   fmsg(L"Failed to load the subsystem name [ID: %1]. LdrErr: %2.");

  fmsg<<varSubSystemId.llVal
      <<ldrErr;

  (*pResultText)=fmsg.str();

  return E_FAIL;
 }//if VT_I4

 structure::wstr_formatter
  fmsg(L"Unknown var-type of subsystem ID: %1.");

 fmsg<<varSubSystemId.vt;

 (*pResultText)=fmsg.str();

 return E_FAIL;
}//Helper__BuildSubSystemName

//------------------------------------------------------------------------
TIBP_MessageTextBuilder::wstr_box_type
 TIBP_MessageTextBuilder::Helper__ToText
                             (const tagGetResult&   get_r,
                              const ole_lib::TBSTR& bstrValue)
{
 if(get_r.first==enumGetDataFlag::no_object)
  return L"[null arg object]";

 if(get_r.first==enumGetDataFlag::unk_object)
  return L"[unk arg object]";

 assert(get_r.first==enumGetDataFlag::ok);

 if(FAILED(get_r.second))
  return L"[can't get object data]";

 return ole_lib::BStrToBox(bstrValue.bstr());
}//Helper__ToText

//------------------------------------------------------------------------
TIBP_MessageTextBuilder::tagGetResult
 TIBP_MessageTextBuilder::Helper__GetErrorSource
                             (IUnknown*       const pUnk,
                              LCID            const lcid,
                              ole_lib::TBSTR* const pbstrValue)
{
 assert(pbstrValue);

 if(pUnk==nullptr)
  return tagGetResult(enumGetDataFlag::no_object,E_POINTER);

 //---------------------------
 OLE_LIB__DECLARE_IPTR_TYPE_NS(ibprovider::,IBP_IText);

 if(IBP_ITextPtr const spText=structure::not_null_ptr(pUnk))
 {
  return tagGetResult
           (enumGetDataFlag::ok,
            spText->GetText(lcid,&pbstrValue->ref_bstr()));
 }//if - spText

 //---------------------------
 OLE_LIB__DECLARE_IPTR_TYPE_NS(ibprovider::,IBP_IErrorExtendedParameter);

 if(IBP_IErrorExtendedParameterPtr const spExtendedError=structure::not_null_ptr(pUnk))
 {
  return tagGetResult
          (enumGetDataFlag::ok,
           spExtendedError->GetErrorDescription(lcid,&pbstrValue->ref_bstr(),/*pbstrDescr*/nullptr));
 }//if - spExtendedError

 //---------------------------
 OLE_LIB__DECLARE_IPTR_TYPE(IErrorInfo);

 if(IErrorInfoPtr const spErrorInfo=structure::not_null_ptr(pUnk))
 {
  return tagGetResult
          (enumGetDataFlag::ok,
           spErrorInfo->GetSource(&pbstrValue->ref_bstr()));
 }//if - spErrorInfo

 //---------------------------
 return tagGetResult(enumGetDataFlag::unk_object,DB_E_NOTSUPPORTED);
}//Helper__GetErrorSource

//------------------------------------------------------------------------
TIBP_MessageTextBuilder::tagGetResult
 TIBP_MessageTextBuilder::Helper__GetErrorDescription
                             (IUnknown*       const pUnk,
                              LCID            const lcid,
                              ole_lib::TBSTR* const pbstrValue)
{
 assert(pbstrValue);

 if(pUnk==nullptr)
  return tagGetResult(enumGetDataFlag::no_object,E_POINTER);

 //---------------------------
 OLE_LIB__DECLARE_IPTR_TYPE_NS(ibprovider::,IBP_IText);

 if(IBP_ITextPtr const spText=structure::not_null_ptr(pUnk))
 {
  return tagGetResult
          (enumGetDataFlag::ok,
           spText->GetText(lcid,&pbstrValue->ref_bstr()));
 }//if - spText

 //---------------------------
 OLE_LIB__DECLARE_IPTR_TYPE_NS(ibprovider::,IBP_IErrorExtendedParameter);

 if(IBP_IErrorExtendedParameterPtr const spExtendedError=structure::not_null_ptr(pUnk))
 {
  return tagGetResult
          (enumGetDataFlag::ok,
           spExtendedError->GetErrorDescription(lcid,/*pbstrSource*/nullptr,&pbstrValue->ref_bstr()));
 }//if - spExtendedError

 //---------------------------
 OLE_LIB__DECLARE_IPTR_TYPE(IErrorInfo);

 if(IErrorInfoPtr const spErrorInfo=structure::not_null_ptr(pUnk))
 {
  return tagGetResult
          (enumGetDataFlag::ok,
           spErrorInfo->GetDescription(&pbstrValue->ref_bstr()));
 }//if - spErrorInfo

 //---------------------------
 return tagGetResult(enumGetDataFlag::unk_object,DB_E_NOTSUPPORTED);
}//Helper__GetErrorDescription

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
