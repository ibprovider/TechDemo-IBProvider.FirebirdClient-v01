////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__get_parameters_v01.cpp
//! \brief   Getting the parameter definitions of statement (v01).
//! \author  Kovalenko Dmitry
//! \date    28.03.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__stmt__get_parameters_v01.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/isc_base/isc_integer_to_portable_format.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__GetParameters_v01

RemoteFB__API_HLP__GetParameters_v01 RemoteFB__API_HLP__GetParameters_v01::Instance;

//------------------------------------------------------------------------
RemoteFB__API_HLP__GetParameters_v01::RemoteFB__API_HLP__GetParameters_v01()
{
}

//------------------------------------------------------------------------
RemoteFB__API_HLP__GetParameters_v01::~RemoteFB__API_HLP__GetParameters_v01()
{
}

//interface --------------------------------------------------------------
void RemoteFB__API_HLP__GetParameters_v01::exec(db_obj::t_db_operation_context& OpCtx,
                                                RemoteFB__ConnectorData*  const pData,
                                                stmt_handle_type*         const pStmtHandle,
                                                isc_api::XSQLDA_V1*       const xsqlda)
{
 assert(pData!=nullptr);
 assert(pStmtHandle!=nullptr);
 assert(xsqlda!=nullptr);

 assert(xsqlda->sqln==0 || xsqlda->sqln>0);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__GetParameters_v01::exec";

 //----------------------------------------- проверка версии xsqlda
 if(xsqlda->version!=xsqlda->c_version_num)
 {
  RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
   (c_bugcheck_src,
    L"#001",
    L"xsqlda",
    xsqlda->version);
 }//if

 //----------------------------------------- проверка дескриптора запроса
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value() && !((*pStmtHandle)->m_ID.is_defer()))
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#003");
 }//if

 pData->BugCheck__CheckStmt
  (*pStmtHandle,
   c_bugcheck_src,
   L"#004");

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED))
 {
  IBP_ErrorUtils::Throw__Error
   (DB_E_NOTPREPARED,
    ibp_subsystem__remote_fb,
    ibp_mce_cmd_not_prepared_0);
 }//if

 assert((*pStmtHandle)->m_ID.has_value());

 //-----------------------------------------
 try
 {
  typedef protocol::P_USHORT StartIndexType;

  bool IsFirstInfoBlock=true;

  StartIndexType StartIndex=0;

  if((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__CACHE_PARAMS_INFO))
  {
   helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::parse_result_type
    parseResult
     =helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
       ((*pStmtHandle)->m_PData__ParametersData.size(),
        (*pStmtHandle)->m_PData__ParametersData.buffer(),
        IsFirstInfoBlock,
        StartIndex,
        xsqlda);

   if(parseResult.second)
    return;

   //Нужно запросить следующую порцию данных ------------------------------
   IsFirstInfoBlock=false;

   StartIndex=parseResult.first;

   assert(xsqlda->sqld>0);
   assert(xsqlda->sqld<=xsqlda->sqln);

   assert(StartIndex<size_t(xsqlda->sqld));
  }//if FLAG__CACHE_PARAMS_INFO

  assert(StartIndex!=structure::get_numeric_limits(StartIndex).max_value());

  const size_t
   c_sz_info_items
    =1          //isc_info_sql_sqlda_start
    +1          //2 (sizeof(StartIndex))
    +sizeof(StartIndex)
    +sizeof(helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__describe_bind);

  structure::t_fix_vector<c_sz_info_items,unsigned char> info_items;

  RemoteFB__InfoBuffer ResultBuffer;

  for(;;)
  {
   assert(info_items.empty());

   assert(ResultBuffer.empty());

   //----------------------------------------
   info_items.push_back(isc_api::ibp_isc_info_sql_sqlda_start);

   info_items.push_back(sizeof(StartIndex));

   {
    assert(StartIndex!=structure::get_numeric_limits(StartIndex).max_value());

    const StartIndexType StartOrdinal=static_cast<StartIndexType>(StartIndex+1);

    isc_base::isc_integer_to_portable_format::tag_buffer<sizeof(StartOrdinal)> data;

    isc_base::isc_integer_to_portable_format::exec(&data,StartOrdinal);

    std::copy(data.data,_END_(data.data),std::back_inserter(info_items));
   }//local

   std::copy
    (helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__describe_bind,
     _END_(helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__describe_bind),
     std::back_inserter(info_items));

   assert(info_items.full());

   //----------------------------------------
   assert(structure::can_numeric_cast<unsigned short>(info_items.size()));

   pData->m_API__GetStatementInfo.get()->exec
    (OpCtx,
     pData,
     pStmtHandle,
     /*Incornation*/0,
     static_cast<unsigned short>(info_items.size()),
     info_items.data(),
     ResultBuffer);

   const unsigned char*       pos=ResultBuffer.buffer();
   const unsigned char* const end=ResultBuffer.buffer_end();

   if(pos==end)
   {
    //ERROR - [BUG CHECK] empty buffer

    IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
     (c_bugcheck_src,
      L"#005");
   }//if

   if((*pos)!=isc_api::ibp_isc_info_sql_bind)
   {
    //ERROR - [BUG CHECK] unexpected element

    IBP_ThrowBugCheck_InfoBuf__UnknownTag
     (c_bugcheck_src,
      L"#006",
      *pos);
   }//if

   ++pos;

   helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::parse_result_type
    parseResult
     =helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
       (static_cast<size_t>(end-pos),
        pos,
        IsFirstInfoBlock,
        StartIndex,
        xsqlda);

   if(parseResult.second)
    return;

   //Нужно запросить следующую порцию данных ------------------------------

   if(IsFirstInfoBlock)
   {
    IsFirstInfoBlock=false;
   }
   else
   {
    assert(!IsFirstInfoBlock);

    //начиная со второй итерации мы должны двигаться вперед
    assert(StartIndex<parseResult.first);

    if(!(StartIndex<parseResult.first))
    {
     //ERROR - зацикливание или некорректная работа парсера данных XSQLDA

     IBP_ErrorUtils::Throw__BugCheck__DEBUG
      (c_bugcheck_src,
       L"#007",
        L"detected an infinite cycle or incorrect work of XSQLDA parser. "
        L"StartIndex: %1. parseResult.first: %2",
       StartIndex,
       parseResult.first);
    }//if
   }//else

   StartIndex=parseResult.first;

   assert(xsqlda->sqld>0);
   assert(xsqlda->sqld<=xsqlda->sqln);

   assert(StartIndex<size_t(xsqlda->sqld));

   ResultBuffer.alloc(0);

   info_items.clear();
  }//for[ever]
 }
 catch(const std::exception& e)
 {
  IBP_ErrorUtils::Throw__Error
   (e,
    E_FAIL,
    ibp_mce_cmd__describe_stmt_params_0);
 }//catch
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
