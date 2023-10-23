////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__blob__cancel.h
//! \brief   Отмена создания блоба. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    02.11.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__api_p12_lazy_send__blob__cancel.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__CancelBlob

RemoteFB__API_P12_LAZY_SEND__CancelBlob RemoteFB__API_P12_LAZY_SEND__CancelBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__CancelBlob::RemoteFB__API_P12_LAZY_SEND__CancelBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__CancelBlob::~RemoteFB__API_P12_LAZY_SEND__CancelBlob()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12_LAZY_SEND__CancelBlob::exec
                                           (RemoteFB__ConnectorData* const pData,
                                            blob_handle_type*        const pBlobHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pBlobHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_LAZY_SEND__CancelBlob::exec";

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
    ibp_subsystem__remote_fb__p12,
    ibp_mce_blob__attempt_to_cancel_of_closed_blob_0);
 }//if

 pData->BugCheck__CheckBlob
  (*pBlobHandle,
   c_bugcheck_src,
   L"#003",
   L"#004");

 //-----------------------------------------
 if((*pBlobHandle)->m_BlobMode!=blob_data_type::BlobMode__Create)
 {
  //Если бы это было открытое API, то данную ошибку нужно было бы обрабатывать
  //по нормальному, а не как BUG CHECK.

  //Но поскольку API закрытое, то значит у нас внутренняя проблема.
  // Поэтому assert и BUG CHECK.

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectBlobHandleMode
   (c_bugcheck_src,
    L"#005",
    lib::structure::to_underlying((*pBlobHandle)->m_BlobMode));
 }//if

 assert((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Create);

 //-----------------------------------------

 //переключаем идентификатор в состоянии "ожидаем отмену"
 const blob_data_type::id_type::value_type blobID=(*pBlobHandle)->m_ID.get_value();

 (*pBlobHandle)->m_ID.set_wait_cancel(&blobID);

 assert((*pBlobHandle)->m_ID.is_wait_cancel());

 //(*pBlobHandle)->m_pParentTr не трогаем.
 // Транзакция продолжает отслеживать этот блоб.

 //Регистрируем блоб в глобальном списке блобов, ожидающих завершение.
 pData->DeletedBlobList__Add(*pBlobHandle);

 //----------------------------------------- EXIT

 //обнуляем дескриптор
 (*pBlobHandle)=nullptr;
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
