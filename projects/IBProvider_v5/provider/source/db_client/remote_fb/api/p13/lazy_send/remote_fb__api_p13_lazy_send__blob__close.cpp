////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__blob__close.cpp
//! \brief   Закрытие блоба. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__api_p13_lazy_send__blob__close.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__CloseBlob

RemoteFB__API_P13_LAZY_SEND__CloseBlob RemoteFB__API_P13_LAZY_SEND__CloseBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__CloseBlob::RemoteFB__API_P13_LAZY_SEND__CloseBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__CloseBlob::~RemoteFB__API_P13_LAZY_SEND__CloseBlob()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__CloseBlob::exec
                                           (RemoteFB__ConnectorData* const pData,
                                            blob_handle_type*        const pBlobHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pBlobHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__CloseBlob::exec";

 //----------------------------------------- проверка дескриптора блоба
 if((*pBlobHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pBlobHandle)->m_ID.has_value())
 {
  //[2015-09-12] Пока это слишком жестоко - на текущий момент в IBProvider
  //не отслеживается косвенное закрытие блобов при коммите транзакций.
  //assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_blob__attempt_to_close_of_closed_blob_0);
 }//if

 pData->BugCheck__CheckBlob
  (*pBlobHandle,
   c_bugcheck_src,
   L"#003",
   L"#004");

 //-----------------------------------------
 if((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Create)
 {
  //мы не должны пытаться закрывать блоб после ошибки сохранения данных.
  assert((*pBlobHandle)->m_WriteMode__State!=blob_data_type::WriteState__Failed);

  try
  {
   //выгрузка буферизированных данных
   pData->m_API__FlushBlob.get()->exec
    (pData,
     pBlobHandle);
  }
  catch(const std::exception& e)
  {
   //добавляем дополнительную информацию о причинах сбоя.

   t_ibp_error exc(e);

   exc.add_error
    (exc.com_code(),
     ibp_subsystem__remote_fb__p13,
     ibp_mce_bw__fail_write_to_db_0);

   exc.raise_me();
  }//catch
 }//if
#ifndef NDEBUG
 else
 {
  assert((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Open);
 }//else
#endif

 //-----------------------------------------

 //переключаем идентификатор в состоянии "ожидаем закрытие"
 const blob_data_type::id_type::value_type blobID=(*pBlobHandle)->m_ID.get_value();

 (*pBlobHandle)->m_ID.set_wait_close(&blobID);

 assert((*pBlobHandle)->m_ID.is_wait_close());

 //(*pBlobHandle)->m_pParentTr не трогаем.
 // Транзакция продолжает отслеживать этот блоб.

 //Регистрируем блоб в глобальном списке блобов, ожидающих завершение.
 pData->DeletedBlobList__Add(*pBlobHandle);

 //----------------------------------------- EXIT

 //обнуляем дескриптор
 (*pBlobHandle)=nullptr;
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
