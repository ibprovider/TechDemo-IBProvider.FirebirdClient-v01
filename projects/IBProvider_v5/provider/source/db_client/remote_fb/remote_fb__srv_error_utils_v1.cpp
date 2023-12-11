////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__srv_error_utils_v1.cpp
//! \brief   Утилиты для обработки ошибок сервера.
//! \author  Kovalenko Dmitry
//! \date    12.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__srv_error_utils_v1.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common__error_text_obj.h"
#include "source/db_obj/isc_base/isc_error_code_descr2.h"
#include "source/db_obj/isc_base/isc_dbms_ids.h"
#include "source/db_obj/db_service_utils.h"

#include "source/error_services/ibp_custom_error_object__sql.h"

#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SrvErrorUtils_v1

isc_api::t_ibp_isc_status
 RemoteFB__SrvErrorUtils_v1::GetResultCode(RemoteFB__ConnectorData*       const _pData,
                                           p_operation_id_type            const _op_id,
                                           const protocol::P_ISC_STATUS_VECTOR& _status_vector)
{
 assert(_pData);

 DEBUG_CODE(_status_vector.debug__check_state();)

 //-----------------------------------------
 using sv_utils_type
  =db_obj::dbms_fb::common::fb_common__svc__status_vector_utils;

 using sv_utils_ptr
  =db_obj::dbms_fb::common::fb_common__svc__status_vector_utils_ptr;

 const sv_utils_ptr
  sv_utils(db_obj::query_db_service<sv_utils_type>(_pData));

 assert(sv_utils);

 //-----------------------------------------
 isc_api::t_ibp_isc_status iscError=0;

 const sv_utils_type::gresult_data_type
  gresult
   =sv_utils->get_error
     (_status_vector.cbegin(),
      _status_vector.cend(),
      &iscError);

 if(gresult!=sv_utils_type::gresult__ok)
 {
  assert(gresult==sv_utils_type::gresult__bad_sv);

  //ERROR - incorrect status vector. наверное следует указать ID операции.
  RemoteFB__ErrorUtils::Throw__OpStatusVectorProcessingError
   (ibp_subsystem__remote_fb,
    _op_id,
    gresult.check_place,
    gresult.check_point);
 }//if

 return iscError;
}//GetResultCode

//------------------------------------------------------------------------
t_ibp_error_element::self_ptr
 RemoteFB__SrvErrorUtils_v1::BuildServerErrorRecord
                                           (RemoteFB__ConnectorData*       const _pData,
                                            p_operation_id_type            const _op_id,
                                            const protocol::P_ISC_STATUS_VECTOR& _status_vector,
                                            HRESULT                              _hr)
{
 assert(_pData);

 //-----------------------------------------
 /*const*/ t_ibp_error_element::self_ptr
  spErrRec
   (self_type::Helper__BuildServerErrorRecord
     (_pData,
      _op_id,
      _status_vector,
      _hr));

 if(!spErrRec)
  return nullptr;

 assert(spErrRec);

 //-------------- указываем имя источника ошибки
 assert(_pData);

 if(_pData->m_DBMS_Name.empty())
 {
  spErrRec->m_varSourceID=isc_base::g_dbms_name_Unknown;
 }
 else
 {
  spErrRec->m_varSourceID=_pData->m_DBMS_Name;
 }//else

 //--------------
 assert(spErrRec);

 return spErrRec;
}//BuildServerErrorRecord

//------------------------------------------------------------------------
void
 RemoteFB__SrvErrorUtils_v1::ProcessServerResult
                                           (RemoteFB__ConnectorData*       const _pData,
                                            p_operation_id_type            const _op_id,
                                            const protocol::P_ISC_STATUS_VECTOR& _status_vector,
                                            HRESULT                        const _hr)
{
 assert(_pData);

 const t_ibp_error_element::self_ptr
  spErrRec
   (self_type::BuildServerErrorRecord
     (_pData,
      _op_id,
      _status_vector,
      _hr));

 if(spErrRec)
 {
  assert(FAILED(spErrRec->get_error_code()));

  t_ibp_error(spErrRec).raise_me();
 }//if spErrRec
}//ProcessServerResult

//------------------------------------------------------------------------
t_ibp_error_element::self_ptr
 RemoteFB__SrvErrorUtils_v1::BuildServerErrorRecord2
                                           (RemoteFB__Port*              const   _pPort,
                                            p_operation_id_type          const   _op_id,
                                            const protocol::P_ISC_STATUS_VECTOR& _status_vector,
                                            HRESULT                      const   _hr)
{
 assert(_pPort);

 //-----------------------------------------
 /*const*/ t_ibp_error_element::self_ptr
  spErrRec
   (self_type::Helper__BuildServerErrorRecord
     (_pPort,
      _op_id,
      _status_vector,
      _hr));

 if(!spErrRec)
  return nullptr;

 assert(spErrRec);

 //-------------- указываем имя источника ошибки
 spErrRec->m_varSourceID=isc_base::g_dbms_name_Unknown;

 //--------------
 assert(spErrRec);

 return spErrRec;
}//BuildServerErrorRecord2 - Port

//------------------------------------------------------------------------
void
 RemoteFB__SrvErrorUtils_v1::ProcessServerResult2
                                           (RemoteFB__Port*                const _pPort,
                                            p_operation_id_type            const _op_id,
                                            const protocol::P_ISC_STATUS_VECTOR& _status_vector,
                                            HRESULT                        const _hr)
{
 assert(_pPort);

 const t_ibp_error_element::self_ptr
  spErrRec
   (self_type::BuildServerErrorRecord2
     (_pPort,
      _op_id,
      _status_vector,
      _hr));

 if(spErrRec)
 {
  assert(FAILED(spErrRec->get_error_code()));

  t_ibp_error(spErrRec).raise_me();
 }//if spErrRec
}//ProcessServerResult2 - Port

//helper methods ---------------------------------------------------------
t_ibp_error_element::self_ptr
 RemoteFB__SrvErrorUtils_v1::Helper__BuildServerErrorRecord
                                           (db_obj::t_db_service_provider* const _pSvcProvider,
                                            p_operation_id_type                  _op_id,
                                            const protocol::P_ISC_STATUS_VECTOR& _status_vector,
                                            HRESULT                              _hr)
{
 assert(_pSvcProvider);

 DEBUG_CODE(_status_vector.debug__check_state();)

 //-----------------------------------------
 using sv_utils_type
  =db_obj::dbms_fb::common::fb_common__svc__status_vector_utils;

 using sv_utils_ptr
  =db_obj::dbms_fb::common::fb_common__svc__status_vector_utils_ptr;

 const sv_utils_ptr
  sv_utils(db_obj::query_db_service<sv_utils_type>(_pSvcProvider));

 assert(sv_utils);

 //--------------- General ISC Error
 isc_api::isc_status IscGeneralError=0;

 {
  const sv_utils_type::gresult_data_type
   gresult
    (sv_utils->get_general_error
      (_status_vector.cbegin(),
       _status_vector.cend(),
       &IscGeneralError));

  if(gresult!=sv_utils_type::gresult__ok)
  {
   assert(gresult==sv_utils_type::gresult__bad_sv);

   //ERROR - incorrect status vector.
   RemoteFB__ErrorUtils::Throw__OpStatusVectorProcessingError
    (ibp_subsystem__remote_fb,
     _op_id,
     gresult.check_place,
     gresult.check_point);
  }//if

  if(IscGeneralError==0)
   return nullptr;
 }//local

 //--------------- Map To OLEDB Error Code
 if(const isc_base::t_isc_error_code_descr2* const x=sv_utils->get_err_descr2(IscGeneralError))
 {
  if(x->oledb_code_is_def())
   _hr=x->oledb_code;
 }//if

 //-------------- SQLSTATE
 std::string strSQLState;

 {
  const sv_utils_type::gresult_data_type
   gresult
    (sv_utils->get_sqlstate
      (_status_vector.cbegin(),
       _status_vector.cend(),
       &strSQLState));

  if(gresult!=sv_utils_type::gresult__ok)
  {
   assert(gresult==sv_utils_type::gresult__bad_sv);

   //ERROR - incorrect status vector.

   RemoteFB__ErrorUtils::Throw__OpStatusVectorProcessingError
    (ibp_subsystem__remote_fb,
     _op_id,
     gresult.check_place,
     gresult.check_point);
  }//if
 }//local

 //--------------
 const t_ibp_error_element::self_ptr
  spErrRec
   (lib::structure::not_null_ptr
     (new t_ibp_error_element
       (_hr,
        ibp_mce_unknown_error_1)));

 //
 // Making an object, which will build the text is based on status vector data.
 //
 const lib::structure::t_err_text::self_ptr
  spErrorText
   (db_obj::dbms_fb::common::FB_ErrorTextObj::Create
      (sv_utils,
       _status_vector.cbegin(),
       _status_vector.cend()));

 assert(spErrorText);

 (*spErrRec)<<spErrorText;

 //-------------- формирование объекта с дополнительным описанием ошибки
 assert(structure::can_numeric_cast<LONG>(IscGeneralError));

 spErrRec->m_spGetCustomError
  =ibp::t_ibp_custom_error_object__sql::create
    (strSQLState,
     static_cast<LONG>(IscGeneralError));

 assert(spErrRec);

 //--------------
 return spErrRec;
}//Helper__BuildServerErrorRecord

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
