////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__flush.cpp
//! \brief   ������ ���������������� ������ �����.
//! \author  Kovalenko Dmitry.
//! \date    20.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__flush.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__blob_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__FlushBlob

RemoteFB__API_P12__FlushBlob RemoteFB__API_P12__FlushBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__FlushBlob::RemoteFB__API_P12__FlushBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__FlushBlob::~RemoteFB__API_P12__FlushBlob()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12__FlushBlob::exec(db_obj::t_db_operation_context& OpCtx,
                                        RemoteFB__ConnectorData*  const pData,
                                        blob_handle_type*         const pBlobHandle)
{
 assert(pData!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__FlushBlob::exec";

 //-----------------------------------------
 RemoteFB__P12__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- �������� ����������� �����
 if((*pBlobHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pBlobHandle)->m_ID.has_value())
 {
  //[2015-09-12] ���� ��� ������� ������� - �� ������� ������ � IBProvider
  //�� ������������� ��������� �������� ������ ��� ������� ����������.
  //assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_blob__write_data_into_closed_blob_0);
 }//if

 pData->BugCheck__CheckBlob
  (*pBlobHandle,
   c_bugcheck_src,
   L"#003",
   L"#004");

 //-----------------------------------------
 if((*pBlobHandle)->m_BlobMode!=blob_data_type::BlobMode__Create)
 {
  //���� �� ��� ���� �������� API, �� ������ ������ ����� ���� �� ������������
  //�� �����������, � �� ��� BUG CHECK.

  //�� ��������� API � ������ ��� ������� �������, �� ������ � ��� ���������� ��������.
  // ������� assert � BUG CHECK.

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectBlobHandleMode
   (c_bugcheck_src,
    L"#005",
    (*pBlobHandle)->m_BlobMode);
 }//if

 assert((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Create);

 //-----------------------------------------
 if((*pBlobHandle)->m_WriteMode__State==blob_data_type::WriteState__Failed)
 {
  assert((*pBlobHandle)->m_spExc);

  std::rethrow_exception((*pBlobHandle)->m_spExc);
 }//if

  assert(!(*pBlobHandle)->m_spExc);

 //-----------------------------------------
 assert(structure::can_numeric_cast<protocol::P_USHORT>((*pBlobHandle)->m_Buffer.size()));

 assert((*pBlobHandle)->m_WriteMode__BufferPos<=(*pBlobHandle)->m_Buffer.size());

 try
 {
  if((*pBlobHandle)->m_WriteMode__BufferPos>0)
  {
   RemoteFB__P12__BlobHelper::WriteSegment
    (serverOperation,
     pData,
     (*pBlobHandle)->m_ID.get_value(),
     static_cast<protocol::P_USHORT>((*pBlobHandle)->m_WriteMode__BufferPos),
     (*pBlobHandle)->m_Buffer.buffer()); //throw

   (*pBlobHandle)->m_WriteMode__BufferPos=0;
  }//if
 }
 catch(...)
 {
  (*pBlobHandle)->m_WriteMode__State=blob_data_type::WriteState__Failed;

  (*pBlobHandle)->m_spExc=std::current_exception();

  assert((*pBlobHandle)->m_spExc);

  throw;
 }//catch
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
