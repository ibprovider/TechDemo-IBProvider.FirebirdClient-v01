////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_bind_data.cpp
//! \brief   Описание ошибки привязки данных
//! \author  Kovalenko Dmitry
//! \date    11.02.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_bind_data.h"
#include "source/error_services/ibp_error_build_message.h"
#include "source/error_services/ibp_error.h"
#include "source/ibp_limits.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//struct TIBPBindErrorDataTraits

TIBPBindErrorDataTraits::out_return_type&
 TIBPBindErrorDataTraits::out_ret(args_type& x)
{
 return *static_cast<out_return_type*>(&x);
}//out_ret

////////////////////////////////////////////////////////////////////////////////
//class TIBPBindErrorData

OLE_LIB__DEFINE_DEBUG_COM_LIVE(TIBPBindErrorData)

//------------------------------------------------------------------------
TIBPBindErrorData::TIBPBindErrorData(ordinal_type  const index,
                                     HRESULT       const err_code,
                                     msg_code_type const msg_code)
 :inherited   (NULL)
 ,m_index     (index)
 ,m_err_code  (err_code)
 ,m_msg_code  (msg_code)
 ,m_pNext     (NULL)
{
 DEBUG_CODE(m_InList=false;)

 //----
 OLE_LIB__CREATE_COMPONENT()
}//TIBPBindErrorData

//------------------------------------------------------------------------
TIBPBindErrorData::~TIBPBindErrorData()
{
 assert(!m_InList);
 assert(m_pNext==NULL);

 //----
 OLE_LIB__DESTROY_COMPONENT()
}//~TIBPBindErrorData

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(TIBPBindErrorData)
 OLE_LIB__ROOT_STATIC_INTERFACE_NS(ibprovider::,IBP_IText)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IBP_IText interface ----------------------------------------------------
HRESULT __stdcall TIBPBindErrorData::GetText(LCID  const lcid,
                                             BSTR* const pbstrText)
{
 OLE_LIB_IMETHOD_PROLOG

 LCPI_OS__SetErrorInfo(0,nullptr);

 if(pbstrText==NULL)
  return E_INVALIDARG;

 (*pbstrText)=NULL;

 HRESULT hr=S_OK;

 _OLE_TRY_
 {
  const lock_guard_type __lock(m_guard);

  //Для обеспечения гарантии константности объекта, осуществляем доступ к
  //собственным данным через pConstThis

  const self_type* const pConstThis=this;

  std::wstring tmpWStr;

  if(!TIBP_MessageTextBuilder::Build(&tmpWStr,
                                     ole_lib::TVariant::empty_variant,
                                     pConstThis->m_msg_code,
                                     lcid,
                                     pConstThis->m_params.size(),
                                     pConstThis->m_params.data(),
                                     pConstThis->m_err_code))
  {
   hr=DB_E_BADLOOKUPID;
  }
  else
  {
   (*pbstrText)=ole_lib::WStrToBStr(tmpWStr); //throw
  }//if
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetText

//------------------------------------------------------------------------
TIBPBindErrorData& TIBPBindErrorData::add_arg(const base_variant_type& x)
{
 const lock_guard_type __lock(m_guard);

 assert(!m_params.full());

 m_params.push_back(x);

 return *this;
}//add_arg

////////////////////////////////////////////////////////////////////////////////
//class TIBPBindErrorDataSet

TIBPBindErrorDataSet::TIBPBindErrorDataSet()
 :m_pHead  (NULL)
 ,m_pTail  (NULL)
 ,m_Size   (0)
{;}

//------------------------------------------------------------------------
TIBPBindErrorDataSet::~TIBPBindErrorDataSet()
{
 DEBUG_CODE(this->CheckState();)

 TIBPBindErrorData* tmp=NULL;

 while(m_pHead!=NULL)
 {
  assert(m_pHead->m_InList);
  assert(m_Size>0);

  tmp=m_pHead;

  //-------------------
  m_pHead=m_pHead->m_pNext;

  assert(tmp!=m_pHead);

  --m_Size;

  //------------------- отключаем элемент от списка
  DEBUG_CODE(tmp->m_InList=false;)

  tmp->m_pNext=NULL;

  //------------------- освобождаем блокировку счетчика ссылок
  tmp->Release();
 }//while m_pHead!=NULL

 //должны добраться до официального хвоста списка
 assert(tmp==m_pTail);

 assert(m_Size==0);

 //---
 m_pTail=NULL;

 DEBUG_CODE(this->CheckState();)
}//~TIBPBindErrorDataSet

//------------------------------------------------------------------------
bool TIBPBindErrorDataSet::IsEmpty()const
{
 DEBUG_CODE(this->CheckState();)

 return m_Size==0;
}//IsEmpty

//------------------------------------------------------------------------
void TIBPBindErrorDataSet::Add(TIBPBindErrorData* const pData)
{
 assert(pData);
 assert(!pData->m_InList);
 assert(pData->m_pNext==NULL);

 DEBUG_CODE(this->CheckState();)

 //явно увеличиваем счетчик ссылок на добавляемый объект
 pData->AddRef();

 //возводим флаг принадлежности списку
 DEBUG_CODE(pData->m_InList=true;)

 //инкремент счетчика объектов
 ++m_Size;

 //добавляем в хвост списка
 if(m_pHead==NULL)
 {
  assert(m_pTail==NULL);

  m_pHead=pData;
  m_pTail=pData;
 }
 else
 {
  assert_hint(m_pHead!=NULL);
  assert(m_pTail!=NULL);

  m_pTail->m_pNext=pData;

  m_pTail=pData;
 }//else

 //проверяем корректность проделанной работы
 DEBUG_CODE(this->CheckState();)
}//Add

//------------------------------------------------------------------------
void TIBPBindErrorDataSet::ThrowError(HRESULT           const ErrCode,
                                      ibp_msg_code_type const ErrMsgID_1)const
{
 DEBUG_CODE(this->CheckState();)

 t_ibp_error exc(ErrCode);

 //перечисляем в первые MaxBindError ошибок
 TIBPBindErrorData* pCurErr=m_pHead;

 for(;pCurErr;pCurErr=pCurErr->m_pNext)
 {
  assert(pCurErr);
  assert(pCurErr->m_pNext!=pCurErr);
  assert(pCurErr->m_InList);

  if(ibp_limc_MaxErrorCountInBulkOperation<exc.get_record_count())
  {
   exc.add_limit_event(); //throw

   break;
  }//if

  //---
  exc.add_error(pCurErr->ErrorCode(),ibp_mce_bind_error_2);

  exc<<pCurErr->Index()<<pCurErr;
 }//for pCurErr

 //это сообщение окажется первой в списке OLEDB ошибок
 exc.add_error(ErrCode,ErrMsgID_1);

 exc<<m_Size;

 //объявляем эту ошибку главной, в случае генерации ошибки автоматизации
 exc.set_last_error_as_primary();

 exc.raise_me();
}//ThrowError

//------------------------------------------------------------------------
#ifndef NDEBUG
void TIBPBindErrorDataSet::CheckState()const
{
 if(m_pHead==NULL)
 {
  assert(m_Size==0);

  assert(m_pTail==NULL);
 }
 else
 {
  assert_hint(m_pHead!=NULL);

  assert(m_Size>0);

  assert(m_pHead->m_pNext!=m_pHead);
  assert(m_pTail!=NULL);
  assert(m_pTail->m_pNext==NULL);

  assert(m_pHead->m_InList);
  assert(m_pTail->m_InList);

  if(m_pHead->m_pNext==NULL)
  {
   assert(m_pHead==m_pTail);
  }
 }//else

 if(m_Size==0)
 {
  assert(m_pHead==NULL);
  assert(m_pTail==NULL);
 }
 else
 if(m_Size==1)
 {
  assert(m_pHead!=NULL);
  assert(m_pHead==m_pTail);
  assert(m_pHead->m_pNext==NULL);
 }
 else
 {
  assert_hint(m_Size>1);

  assert(m_pHead!=NULL);
  assert(m_pHead!=m_pTail);
  assert(m_pHead->m_pNext!=NULL);

  assert(m_pTail!=NULL);
  assert(m_pTail->m_pNext==NULL);
 }//else
}//CheckState
#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
