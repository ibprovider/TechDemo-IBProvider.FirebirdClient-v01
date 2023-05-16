////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__array__put_slice.cpp
//! \brief   Сохранение массива.
//! \author  Kovalenko Dmitry.
//! \date    22.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__array__put_slice.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__array_slice_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__get_array_slice_descr.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__PutArraySlice::tagOpGetArraySliceDescr

class RemoteFB__API_P12__PutArraySlice::tagOpGetArraySliceDescr
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__OpSvc__GetArraySliceDescr)
{
 private:
  typedef tagOpGetArraySliceDescr           self_type;

  tagOpGetArraySliceDescr(const self_type&);
  self_type& operator = (const self_type&);

 public:
  RemoteFB__ArraySliceDescr m_descr;

 public:
  tagOpGetArraySliceDescr();

  virtual ~tagOpGetArraySliceDescr();

  //interface ------------------------------------------------------------
  virtual const RemoteFB__ArraySliceDescr& GetArraySliceDescr()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//RemoteFB__API_P12__PutArraySlice::tagOpGetArraySliceDescr

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__PutArraySlice::tagOpGetArraySliceDescr

RemoteFB__API_P12__PutArraySlice::tagOpGetArraySliceDescr::tagOpGetArraySliceDescr()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__PutArraySlice::tagOpGetArraySliceDescr::~tagOpGetArraySliceDescr()
{;}

//interface --------------------------------------------------------------
const RemoteFB__ArraySliceDescr&
 RemoteFB__API_P12__PutArraySlice::tagOpGetArraySliceDescr::GetArraySliceDescr()const
{
 return m_descr;
}//GetArraySliceDescr

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__PutArraySlice

RemoteFB__API_P12__PutArraySlice RemoteFB__API_P12__PutArraySlice::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__PutArraySlice::RemoteFB__API_P12__PutArraySlice()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__PutArraySlice::~RemoteFB__API_P12__PutArraySlice()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12__PutArraySlice::exec(db_obj::t_db_operation_context& opCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            db_obj::DB_IBARRAYID*     const pArrayID,
                                            size_t                    const szArraySDL,
                                            const unsigned char*      const pArraySDL,
                                            size_t                    const szArrayData,
                                            const void*               const pArrayData)
{
 assert(pData!=nullptr);
 assert(pTrHandle!=nullptr);
 assert(pArrayID!=nullptr);

 CHECK_READ_TYPED_PTR(pArraySDL,szArraySDL);

 CHECK_READ_PTR(pArrayData,szArrayData);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__PutArraySlice::exec";

 //-----------------------------------------
 if(!(*pTrHandle))
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pTrHandle)->m_ID.has_value())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 pData->BugCheck__CheckTr
  (*pTrHandle,
   c_bugcheck_src,
   L"#003");

 //-----------------------------------------
 tagOpGetArraySliceDescr GetArraySliceDescrSvc;

 helpers::RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL
  (opCtx,
   szArraySDL,
   pArraySDL,
   &GetArraySliceDescrSvc.m_descr);//throw

 //-----------------------------------------
 if(GetArraySliceDescrSvc.m_descr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] нулевая длина элемента массива

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#004",
    GetArraySliceDescrSvc.m_descr.m_element_blr_typeid);
 }//if

 //проверка размера буфера под элементы массива
 {
  const size_t ExpectedArraySize=GetArraySliceDescrSvc.m_descr.GetMemorySize();

  if(ExpectedArraySize!=szArrayData)
  {
   //ERROR - invalid array buffer size

   RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__InvalidBufferSize
    (c_bugcheck_src,
     L"#005",
     GetArraySliceDescrSvc.m_descr.m_relation_name.c_str(),
     GetArraySliceDescrSvc.m_descr.m_field_name.c_str(),
     szArrayData,
     ExpectedArraySize);
  }//if
 }//local

 //-----------------------------------------
 db_obj::DB_IBARRAYID newArrayId={};

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_put_slice;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_put_slc_transaction
  packet.p_put_slc.p_put_slc__transaction=(*pTrHandle)->m_ID.get_value();

  //---------------------------------------- p_put_slc_id
  packet.p_put_slc.p_put_slc__id=*pArrayID;

  //---------------------------------------- p_put_slc_sdl
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_put_slc.p_put_slc__sdl,
    szArraySDL,
    ibp_mce_isc__too_large_sdl_buffer_size_2);

  assert(packet.p_put_slc.p_put_slc__sdl.cstr_length==szArraySDL);

  assert_s(sizeof(*packet.p_put_slc.p_put_slc__sdl.cstr_address)==sizeof(*pArraySDL));

  structure::reinterpret_ptr_cast
   (&packet.p_put_slc.p_put_slc__sdl.cstr_address,
    pArraySDL);

  //---------------------------------------- p_put_slc_parameters

  //no params
  packet.p_put_slc.p_put_slc__parameters.cstr_length=0;

  //---------------------------------------- p_put_slc_slice
  if(!structure::can_numeric_cast(&packet.p_put_slc.p_put_slc__slice.lstr_length,
                                  szArrayData))
  {
   //ERROR - Too large array data

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_isc__too_large_array_slice_buffer_size_2,
     szArrayData,
     structure::get_numeric_limits(packet.p_put_slc.p_put_slc__slice.lstr_length).max_value());
  }//if

  structure::static_numeric_cast
   (&packet.p_put_slc.p_put_slc__slice.lstr_length,
    szArrayData);

  assert_s(sizeof(*packet.p_put_slc.p_put_slc__slice.lstr_address)==1);

  structure::reinterpret_ptr_cast
   (&packet.p_put_slc.p_put_slc__slice.lstr_address,
    pArrayData);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc(&GetArraySliceDescrSvc);

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //запоминаем идентификатор массива
   newArrayId=packet.p_resp.p_resp__blob_id;

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#006",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT
 (*pArrayID)=newArrayId;
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
