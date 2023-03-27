////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_bind_data.cpp
//! \brief   ќписание ошибки прив€зки данных
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
//class IBP_BindErrorData

IBP_BindErrorData::IBP_BindErrorData(ordinal_type  const index,
                                     HRESULT       const err_code,
                                     msg_code_type const msg_code)
 :m_index     (index)
 ,m_err_code  (err_code)
 ,m_msg_code  (msg_code)
 ,m_pNext     (nullptr)
#ifndef NDEBUG
 ,m_DEBUG__pOwnerList(nullptr)
#endif
{
}//IBP_BindErrorData

//------------------------------------------------------------------------
IBP_BindErrorData::~IBP_BindErrorData()
{
 assert(m_DEBUG__pOwnerList==nullptr);
 assert(m_pNext==nullptr);
}//~IBP_BindErrorData

//IBP_IText interface ----------------------------------------------------
bool IBP_BindErrorData::get_text(lcid_type    const lcid,
                                 string_type* const text)const
{
 const lock_guard_type __lock(m_guard);

 const auto r=
  TIBP_MessageTextBuilder::Build
   (text,
    ole_lib::TVariant::empty_variant,
    m_msg_code,
    lcid.get_number(),
    m_params.size(),
    m_params.data(),
    m_err_code);

 return r;
}//get_text

//------------------------------------------------------------------------
IBP_BindErrorData& IBP_BindErrorData::add_arg(const base_variant_type& x)
{
 const lock_guard_type __lock(m_guard);

 assert(!m_params.full());

 m_params.emplace_back(x);

 return *this;
}//add_arg

////////////////////////////////////////////////////////////////////////////////
//class IBP_BindErrorDataSet

IBP_BindErrorDataSet::IBP_BindErrorDataSet()
 :m_pHead  (nullptr)
 ,m_pTail  (nullptr)
 ,m_Size   (0)
{
}

//------------------------------------------------------------------------
IBP_BindErrorDataSet::~IBP_BindErrorDataSet()
{
 DEBUG_CODE(this->DEBUG__CheckState();)

 IBP_BindErrorData* tmp=nullptr;

 while(m_pHead!=nullptr)
 {
  assert(m_pHead->m_DEBUG__pOwnerList==this);
  assert(m_Size>0);

  tmp=m_pHead;

  //-------------------
  m_pHead=m_pHead->m_pNext;

  assert(tmp!=m_pHead);

  --m_Size;

  //------------------- отключаем элемент от списка
  DEBUG_CODE(tmp->m_DEBUG__pOwnerList=nullptr;)

  tmp->m_pNext=nullptr;

  //------------------- освобождаем блокировку счетчика ссылок
  tmp->release();
 }//while m_pHead!=nullptr

 //It must reach the known tail of our list
 assert(tmp==m_pTail);

 assert(m_Size==0);

 //---
 m_pTail=nullptr;

 DEBUG_CODE(this->DEBUG__CheckState();)
}//~IBP_BindErrorDataSet

//------------------------------------------------------------------------
bool IBP_BindErrorDataSet::IsEmpty()const
{
 DEBUG_CODE(this->DEBUG__CheckState();)

 return m_Size==0;
}//IsEmpty

//------------------------------------------------------------------------
void IBP_BindErrorDataSet::Add(IBP_BindErrorData* const pData)
{
 assert(pData);
 assert(pData->m_DEBUG__pOwnerList==nullptr);
 assert(pData->m_pNext==nullptr);

 DEBUG_CODE(this->DEBUG__CheckState();)

 //€вно увеличиваем счетчик ссылок на добавл€емый объект
 pData->add_ref();

 //возводим флаг принадлежности списку
 DEBUG_CODE(pData->m_DEBUG__pOwnerList=this;)

 //инкремент счетчика объектов
 ++m_Size;

 //добавл€ем в хвост списка
 if(m_pHead==nullptr)
 {
  assert(m_pTail==nullptr);

  m_pHead=pData;
  m_pTail=pData;
 }
 else
 {
  assert_hint(m_pHead!=nullptr);
  assert(m_pTail!=nullptr);

  m_pTail->m_pNext=pData;

  m_pTail=pData;
 }//else

 //провер€ем корректность проделанной работы
 DEBUG_CODE(this->DEBUG__CheckState();)
}//Add

//------------------------------------------------------------------------
void IBP_BindErrorDataSet::ThrowError(HRESULT           const ErrCode,
                                      ibp_msg_code_type const ErrMsgID_1)const
{
 DEBUG_CODE(this->DEBUG__CheckState();)

 t_ibp_error exc(ErrCode);

 //перечисл€ем в первые MaxBindError ошибок
 IBP_BindErrorData* pCurErr=m_pHead;

 for(;pCurErr;pCurErr=pCurErr->m_pNext)
 {
  assert(pCurErr);
  assert(pCurErr->m_pNext!=pCurErr);
  assert(pCurErr->m_DEBUG__pOwnerList==this);

  if(ibp_limc_MaxErrorCountInBulkOperation<exc.get_record_count())
  {
   exc.add_limit_event(); //throw

   break;
  }//if

  //---
  exc.add_error(pCurErr->ErrorCode(),ibp_mce_bind_error_2);

  exc<<pCurErr->Index()<<pCurErr;
 }//for pCurErr

 //это сообщение окажетс€ первой в списке OLEDB ошибок
 exc.add_error(ErrCode,ErrMsgID_1);

 exc<<m_Size;

 //объ€вл€ем эту ошибку главной, в случае генерации ошибки автоматизации
 exc.set_last_error_as_primary();

 exc.raise_me();
}//ThrowError

//------------------------------------------------------------------------
#ifndef NDEBUG
void IBP_BindErrorDataSet::DEBUG__CheckState()const
{
 if(m_pHead==nullptr)
 {
  assert(m_Size==0);

  assert(m_pTail==nullptr);
 }
 else
 {
  assert_hint(m_pHead!=nullptr);

  assert(m_Size>0);

  assert(m_pHead->m_pNext!=m_pHead);
  assert(m_pTail!=nullptr);
  assert(m_pTail->m_pNext==nullptr);

  assert(m_pHead->m_DEBUG__pOwnerList==this);
  assert(m_pTail->m_DEBUG__pOwnerList==this);

  if(m_pHead->m_pNext==nullptr)
  {
   assert(m_pHead==m_pTail);
  }
 }//else

 if(m_Size==0)
 {
  assert(m_pHead==nullptr);
  assert(m_pTail==nullptr);
 }
 else
 if(m_Size==1)
 {
  assert(m_pHead!=nullptr);
  assert(m_pHead==m_pTail);
  assert(m_pHead->m_pNext==nullptr);
 }
 else
 {
  assert_hint(m_Size>1);

  assert(m_pHead!=nullptr);
  assert(m_pHead!=m_pTail);
  assert(m_pHead->m_pNext!=nullptr);

  assert(m_pTail!=nullptr);
  assert(m_pTail->m_pNext==nullptr);
 }//else
}//DEBUG__CheckState
#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
