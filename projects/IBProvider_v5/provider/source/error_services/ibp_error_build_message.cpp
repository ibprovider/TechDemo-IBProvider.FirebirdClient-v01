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

#include <ole_lib/oledb/variant/oledb_variant.h>
#include <structure/t_str_formatter.h>
#include <structure/t_function.h>

#include <structure/utilities/string/trim.h>
#include <structure/utilities/to_hex.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_MessageTextBuilder

std::wstring TIBP_MessageTextBuilder::GetSystemErrorMsg(LCID  const lcid,
                                                        DWORD const errorCode)
{
 //! \todo
 //!  Append the terminate point?

 WCHAR* Pointer=nullptr;

 const DWORD res=::FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER |
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
  result+=structure::to_hex::upper<wchar_t>(errorCode).c_str();
  result+=L">";

  return result;
 }//if res==0

 assert_hint(res>0);

 if(!Pointer)
 {
  assert_msg(false,"errorCode=0x"<<std::hex<<errorCode);

  std::wstring result;

  result =L"<[bug check] null pointer to message of system error 0x";
  result+=structure::to_hex::upper<wchar_t>(errorCode).c_str();
  result+=L">";

  return result;
 }//if !Pointer

 assert(Pointer);

 CHECK_READ_TYPED_PTR(Pointer,res);

 typedef HLOCAL __stdcall t_local_free(HLOCAL);

 //automated call of LocalFree
 typedef structure::t_auto_fun_1<t_local_free*,HLOCAL> auto_free_type;

 const auto_free_type _local_free(::LocalFree,Pointer);

 WCHAR* const ePointer=structure::total_miss_space_back(Pointer,Pointer+res);

 if(Pointer==ePointer)
 {
  std::wstring result;

  result =L"<[bug check] empty message of system error 0x";
  result+=structure::to_hex::upper<wchar_t>(errorCode).c_str();
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
 }//VT_BSTR

 return false;
}//BuildSrc

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Build(std::wstring*  const pResultText,
                                    const VARIANT&       varSubSystemId,
                                    DWORD          const msg_code,
                                    LCID           const lcid,
                                    size_t         const cArgs,
                                    const VARIANT* const rgArgs,
                                    HRESULT        const ErrorCode)
{
 assert(pResultText);

 CHECK_READ_TYPED_PTR(rgArgs,cArgs);

 structure::t_stl_vector<oledb_lib::DBVARIANT,IBP_MemoryAllocator> DBVars(cArgs);

 for(size_t iArg(0);iArg!=cArgs;++iArg)
 {
  const HRESULT hr=oledb_lib::UnpackVariantToDBVariant(rgArgs[iArg],&DBVars[iArg]);

  if(FAILED(hr))
  {
   DBVars[iArg].wType       =DBTYPE_WSTR;
   DBVars[iArg].wstrVal.ptr =const_cast<wchar_t*>(L"<error>");
   DBVars[iArg].wstrVal.len =wcslen(DBVars[iArg].wstrVal.ptr);
  }
 }//for iArg

 return self_type::Build(pResultText,
                         varSubSystemId,
                         msg_code,
                         lcid,
                         DBVars.size(),
                         DBVars.data(),
                         ErrorCode);
}//Build - VARIANT

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Build(std::wstring*               const pResultText,
                                    const VARIANT&                    varSubSystemId,
                                    DWORD                       const msg_code,
                                    LCID                        const lcid,
                                    size_t                      const cArgs,
                                    const oledb_lib::DBVARIANT* const rgArgs,
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
}//Build - DBVARIANT

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Build(std::wstring*               const pResultText,
                                    DWORD                       const msg_code,
                                    LCID                        const lcid,
                                    size_t                      const cArgs,
                                    const oledb_lib::DBVARIANT* const rgArgs,
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
}//Build

//------------------------------------------------------------------------
bool TIBP_MessageTextBuilder::Helper__BuildDescription
                                      (std::wstring*               const pResultText,
                                       DWORD                       const msg_code,
                                       LCID                        const lcid,
                                       size_t                      const cArgs,
                                       const oledb_lib::DBVARIANT* const rgArgs,
                                       const TIBP_MsgTableLoader&        MsgTableLoader)
{
 assert(pResultText!=nullptr);

 CHECK_READ_TYPED_PTR(rgArgs,cArgs);

 //использование кода сообщения для загрузки шаблона из ресурса ----------
 structure::wstr_formatter fmsg;

 {
  std::wstring wstr;

  const TIBP_MsgTableLoader::error_code_type
   ldrErr=MsgTableLoader.GetMessage(msg_code,lcid,wstr);

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
 DECLARE_IPTR_TYPE_NS(ibprovider::,IBP_IErrorExtendedParameter);
 DECLARE_IPTR_TYPE_NS(ibprovider::,IBP_IText);

 for(const oledb_lib::DBVARIANT *pv=rgArgs,* const _end=rgArgs+cArgs;pv!=_end;++pv)
 {
  if(pv->wType==VT_UNKNOWN) //вложенная ошибка
  {
   IBP_ITextPtr                   spText;
   IBP_IErrorExtendedParameterPtr spExtendedError;

   //----
   spText=pv->unkVal.ptr;

   if(!spText)
    spExtendedError=pv->unkVal.ptr;

   //---------------------------------------
   ole_lib::TBSTR tmpMsg;
   HRESULT        hr;

   if(spText)
   {
    hr=spText->GetText(lcid,&tmpMsg.ref_bstr());
   }
   else
   if(spExtendedError)
   {
    hr=spExtendedError->GetErrorDescription(lcid,/*pbstrSource*/NULL,&tmpMsg.ref_bstr());
   }
   else
   {
    fmsg<<L"[unk arg object]";

    continue;
   }//else

   //---------------------------------------
   if(hr!=S_OK)
   {
    assert(FAILED(hr));

    fmsg<<L"[bad arg object]";

    continue;
   }//if

   //формируем текст вложенной ошибки ------
   fmsg<<tmpMsg.wstr();

   continue;
  }//вложенная ошибка

  oledb_lib::t_oledb_value__CPP_WSTR_n wstrN;

  if(pv->IsNull_Ext())
   fmsg<<L"NULL";
  else
  if(pv->to_wstr(&wstrN)!=S_OK)
   fmsg<<L"???";
  else
  if(wstrN.null())
   fmsg<<L"NULL";
  else
   fmsg<<__STL_MOVE_VALUE(wstrN.value());
 }//for pv

 (*pResultText)=fmsg.str();

 structure::total_self_trim(*pResultText);

 if(pResultText->empty())
 {
  fmsg(L"[IBP] Unknown internal error. MsgCode: %1.")
   <<msg_code;

  (*pResultText)=fmsg.str();
 }//if

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
   ldrErr=_SubSystemNameTableLoader.GetMessage((UINT)varSubSystemId.llVal,
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

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
