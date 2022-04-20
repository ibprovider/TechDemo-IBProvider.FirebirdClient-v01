////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__write.cpp
//! \brief   Запись данных блоба.
//! \author  Kovalenko Dmitry.
//! \date    19.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__write.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__blob_helper.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__WriteBlob

RemoteFB__API_P12__WriteBlob RemoteFB__API_P12__WriteBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__WriteBlob::RemoteFB__API_P12__WriteBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__WriteBlob::~RemoteFB__API_P12__WriteBlob()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12__WriteBlob::exec(RemoteFB__ConnectorData* const pData,
                                        blob_handle_type*        const pBlobHandle,
                                        size_t                   const cbBuffer,
                                        const void*              const pvBuffer)
{
 assert(pData!=nullptr);
 assert(cbBuffer==0 || pvBuffer!=nullptr);

 CHECK_READ_PTR(pvBuffer,cbBuffer);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__WriteBlob::exec";

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
    ibp_mce_blob__write_data_into_closed_blob_0);
 }//if

 pData->BugCheck__CheckBlob
  (*pBlobHandle,
   c_bugcheck_src,
   L"#002",
   L"#003");

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
    L"#004",
    (*pBlobHandle)->m_BlobMode);
 }//if

 assert((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Create);

 //-----------------------------------------
 if((*pBlobHandle)->m_WriteMode__State==blob_data_type::WriteState__Failed)
 {
  assert(FAILED((*pBlobHandle)->m_Err.com_code()));

  (*pBlobHandle)->m_Err.raise();
 }//if

 //-----------------------------------------

 try //захват ошибок записи блоба
 {
  const protocol::P_USHORT
   c_WriteBufferSize=structure::t_numeric_limits<protocol::P_USHORT>::max_value();

  //-----------------------------------------
  typedef unsigned char byte_type;

  const byte_type* pSrc=reinterpret_cast<const byte_type*>(pvBuffer);

  const byte_type* const _eSrc=pSrc+cbBuffer;

  //-----------------------------------------
  for(;;)
  {
   assert(pSrc<=_eSrc);

   assert(structure::can_numeric_cast<protocol::P_USHORT>((*pBlobHandle)->m_Buffer.size()));

   assert((*pBlobHandle)->m_WriteMode__BufferPos<=(*pBlobHandle)->m_Buffer.size());

   if(pSrc==_eSrc)
    break;

   //-------------
   const size_t cbSrcTail=size_t(_eSrc-pSrc);

   if((*pBlobHandle)->m_WriteMode__BufferPos>0)
   {
    assert((*pBlobHandle)->m_Buffer.size()==c_WriteBufferSize);
    assert(!(*pBlobHandle)->m_Buffer.empty());

    if((*pBlobHandle)->m_WriteMode__BufferPos==(*pBlobHandle)->m_Buffer.size())
    {
     //Вызываем вспомогательную функцию для сохранения данных в блобе
     RemoteFB__P12__BlobHelper::WriteSegment
      (pData,
       (*pBlobHandle)->m_ID.get_value(),
       static_cast<protocol::P_USHORT>((*pBlobHandle)->m_WriteMode__BufferPos),
       (*pBlobHandle)->m_Buffer.buffer()); //throw

     (*pBlobHandle)->m_WriteMode__BufferPos=0;

     continue;
    }//if (*pBlobHandle)->m_WriteMode__BufferPos==(*pBlobHandle)->m_Buffer.size()

    assert((*pBlobHandle)->m_WriteMode__BufferPos<(*pBlobHandle)->m_Buffer.size());

    //напоминаем, что:
    assert((*pBlobHandle)->m_WriteMode__BufferPos>0);

    //дописываем данные в буфер
    size_t x=(*pBlobHandle)->m_Buffer.size()-(*pBlobHandle)->m_WriteMode__BufferPos;

    if(cbSrcTail<x)
     x=cbSrcTail;

    memcpy((*pBlobHandle)->m_Buffer.ptr_at((*pBlobHandle)->m_WriteMode__BufferPos),
           pSrc,
           x);

    pSrc+=x;

    (*pBlobHandle)->m_WriteMode__BufferPos+=x;

    continue;
   }//if (*pBlobHandle)->m_WriteMode__BufferPos>0

   assert((*pBlobHandle)->m_WriteMode__BufferPos==0);

   if(cbSrcTail>=c_WriteBufferSize)
   {
    //пишем данные прямо в блоб (c_WriteBufferSize, pSrc)
    RemoteFB__P12__BlobHelper::WriteSegment
     (pData,
      (*pBlobHandle)->m_ID.get_value(),
      c_WriteBufferSize,
      pSrc); //throw

    pSrc+=c_WriteBufferSize;

    continue;
   }//if(cbSrcTail>=c_WriteBufferSize)

   assert(cbSrcTail<c_WriteBufferSize);

   assert((*pBlobHandle)->m_Buffer.empty() || (*pBlobHandle)->m_Buffer.size()==c_WriteBufferSize);

   //еще раз - у нас нет буферизированных данных
   assert((*pBlobHandle)->m_WriteMode__BufferPos==0);

   (*pBlobHandle)->m_Buffer.alloc(c_WriteBufferSize); //throw!

   memcpy((*pBlobHandle)->m_Buffer.buffer(),pSrc,cbSrcTail);

   pSrc+=cbSrcTail;

   (*pBlobHandle)->m_WriteMode__BufferPos=cbSrcTail;

   //в данной точке, мы можем смело выходить из цикла
   break;
  }//for[ever]

  assert(pSrc==_eSrc);
 }
 catch(const std::bad_alloc&)
 {
  (*pBlobHandle)->m_WriteMode__State=blob_data_type::WriteState__Failed;

  (*pBlobHandle)->m_Err.clear_state(E_OUTOFMEMORY);

  (*pBlobHandle)->m_Err.raise();
 }
 catch(t_ibp_error& exc)
 {
  assert(FAILED(exc.com_code()));

  (*pBlobHandle)->m_WriteMode__State=blob_data_type::WriteState__Failed;

  (*pBlobHandle)->m_Err.swap(exc); //no throw!

  assert(FAILED((*pBlobHandle)->m_Err.com_code()));

  (*pBlobHandle)->m_Err.raise();
 }//catch exc

 //----------------------------------------- EXIT.
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
