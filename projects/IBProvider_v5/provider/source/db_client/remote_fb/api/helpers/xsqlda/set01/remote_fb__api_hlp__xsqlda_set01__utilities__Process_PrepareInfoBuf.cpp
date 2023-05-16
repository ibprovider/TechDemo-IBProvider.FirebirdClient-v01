////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__p12__xsqlda_utilities.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_obj/isc_base/helpers/xsqlda/set01/isc_api_hlp__xsqlda_set01__msg_utilities.h"
#include "source/db_obj/isc_base/helpers/xsqlda/set01/isc_api_hlp__xsqlda_set01__xvar_info_ids.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_SET01__Utilities

const RemoteFB__API_HLP__XSQLDA_SET01__Utilities::byte_type
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__prepare[26]=
{
 isc_api::ibp_isc_info_sql_stmt_type,              //0
 isc_api::ibp_isc_info_sql_batch_fetch,            //1

 // describe_select_info
 isc_api::ibp_isc_info_sql_select,                 //2
 IBP_ISC_API_HLP__XSQLDA_SET01__XVAR_INFO_IDS__C11 //3-13

 // describe_bind_info
 isc_api::ibp_isc_info_sql_bind,                   //14
 IBP_ISC_API_HLP__XSQLDA_SET01__XVAR_INFO_IDS__C11 //15-25
};//sm_sql_info__prepare

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf
                                            (stmt_data_type*  const pStmt,
                                             size_t           const szBuf,
                                             const byte_type* const pBuf)
{
 assert(pStmt!=nullptr);

 CHECK_READ_TYPED_PTR(pBuf,szBuf);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf";

 //-----------------------------------------
 //У нас четыре первичных элемента:
 // - ibp_isc_info_sql_stmt_type
 // - ibp_isc_info_sql_batch_fetch
 // - ibp_isc_info_sql_select
 // - ibp_isc_info_sql_bind

 const size_t c_primary_ids=4;

 typedef structure::t_fix_vector<c_primary_ids,unsigned char>  primary_ids_type;

 primary_ids_type processed_ids;

 //-----------------------------------------
 const byte_type* const _e_buffer=pBuf+szBuf;

 for(const byte_type* p=pBuf;p!=_e_buffer;)
 {
  const byte_type cluster_id=(*p);

  ++p;

  assert(p<=_e_buffer);

  //----------------------------------------
  if(cluster_id==isc_api::ibp_isc_info_end)
  {
   break;
  }//if

  //----------------------------------------
  if(cluster_id==isc_api::ibp_isc_info_truncated)
  {
   //ну, обрезаны, значит обрезаны. ничего страшного.
   break;
  }//if

  //----------------------------------------
  if(std::find(processed_ids.cbegin(),processed_ids.cend(),cluster_id)!=processed_ids.cend())
  {
   //ERROR - повторное указание cluster_id в полученном буфере

   IBP_ThrowBugCheck_InfoBuf__MultDefOfElement
    (c_bugcheck_src,
     L"#001",
     cluster_id);
  }//if

  //cluster_id будет зарегистрирован в processed_ids после обработки
  // - возможно нам подсунули что-то неизвестное.

  //----------------------------------------
  if(cluster_id==isc_api::ibp_isc_info_sql_select)
  {
   assert(!pStmt->m_PFlags.test(stmt_data_type::PFLAG__CACHE_COLS_INFO));

   const auto
    skip_result
     =isc_base::helpers::ISC_API_HLP__XSQLDA_SET01__MsgUtilities::Skip_XSQLVARS_Info
       (p,
        _e_buffer);

   assert(p==skip_result.data_beg);
   assert(skip_result.data_beg<=skip_result.data_end);
   assert(skip_result.data_end<=skip_result.position);

   assert(skip_result.position<=_e_buffer);

   if(skip_result.data_beg!=skip_result.data_end)
   {
    //сохраняем полученные данные в дескрипторе запросе
    Helper__SaveElementData
     (skip_result.data_beg,
      skip_result.data_end,
      skip_result.data_is_truncated,
      pStmt->m_PData__ColumnsData);

    pStmt->m_PFlags.set(stmt_data_type::PFLAG__CACHE_COLS_INFO);
   }//if

   p=skip_result.position;
  }//if
  else
  if(cluster_id==isc_api::ibp_isc_info_sql_bind)
  {
   assert(!pStmt->m_PFlags.test(stmt_data_type::PFLAG__CACHE_PARAMS_INFO));

   const auto
    skip_result
     =isc_base::helpers::ISC_API_HLP__XSQLDA_SET01__MsgUtilities::Skip_XSQLVARS_Info
       (p,
        _e_buffer);

   assert(p==skip_result.data_beg);
   assert(skip_result.data_beg<=skip_result.data_end);
   assert(skip_result.data_end<=skip_result.position);

   assert(skip_result.position<=_e_buffer);

   if(skip_result.data_beg!=skip_result.data_end)
   {
    //сохраняем полученные данные в дескрипторе запросе
    Helper__SaveElementData
     (skip_result.data_beg,
      skip_result.data_end,
      skip_result.data_is_truncated,
      pStmt->m_PData__ParametersData);

    pStmt->m_PFlags.set(stmt_data_type::PFLAG__CACHE_PARAMS_INFO);
   }//if

   p=skip_result.position;
  }//if
  else
  {
   //определяем длину данных кластера
   if(size_t(_e_buffer-p)<isc_api::ibp_isc__info_tag__data_length__byte_count)
   {
    //ERROR - [BUG CHECK] некорректный формат элемента.

    IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
     (c_bugcheck_src,
      L"#002",
      cluster_id);
   }//if

   size_t cluster_length=0;

   assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(cluster_length));

   _VERIFY(isc_base::isc_portable_format_to_integer::exec_r
            (isc_api::ibp_isc__info_tag__data_length__byte_count,
             p,
             &cluster_length));

   p+=isc_api::ibp_isc__info_tag__data_length__byte_count;

   assert(p<=_e_buffer);

   if(size_t(_e_buffer-p)<cluster_length)
   {
    //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

    IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
     (c_bugcheck_src,
      L"#003",
      cluster_id,
      cluster_length,
      size_t(_e_buffer-p));
   }//if

   //----------------------------------------
   const unsigned char* const cluster_data=p;

   p+=cluster_length;

   bool known_clusterID=true;

   try
   {
    switch(cluster_id)
    {
     case isc_api::ibp_isc_info_sql_stmt_type:
     {
      assert(pStmt->m_PData__StmtTypeID.null());

      isc_base::isc_portable_format_to_integer::exec
       (cluster_length,
        cluster_data,
        &pStmt->m_PData__StmtTypeID,
        ibp_subsystem__remote_fb,
        L"isc_info_sql_stmt_type");

      break;
     }//case ibp_isc_info_sql_stmt_type

     case isc_api::ibp_isc_info_sql_batch_fetch:
     {
      assert(pStmt->m_PData__BatchFetch.null());

      long v=0;

      isc_base::isc_portable_format_to_integer::exec
       (cluster_length,
        cluster_data,
        &v,
        ibp_subsystem__remote_fb,
        L"isc_info_sql_batch_fetch");

       pStmt->m_PData__BatchFetch=(v!=0);
       break;
     }//case ibp_isc_info_sql_batch_fetch

     default:
      {
       //ERROR - unexpected data in result buffer

       known_clusterID=false;

       break;
      }//default
    }//switch
   }
   catch(const std::exception& e)
   {
    IBP_ErrorUtils::Throw__Error
     (e,
      E_FAIL,
      ibp_subsystem__remote_fb,
      ibp_mce_cmd__in_stmt_info_processing_error_occurred_1,
      cluster_id);
   }//catch

   if(!known_clusterID)
   {
    IBP_ThrowBugCheck_InfoBuf__UnknownTag
     (c_bugcheck_src,
      L"#004",
      cluster_id);
   }//if
  }//else

  //----------------------------------------
  assert(processed_ids.size()<processed_ids.capacity());

  processed_ids.push_back(cluster_id);
 }//for p

 //проверка загрузки обязательных сведений о запросе ---------------------
 if(pStmt->m_PData__StmtTypeID.null())
 {
  Helper__ThrowError__GetStmtInfo__NoData(L"isc_info_sql_stmt_type");
 }//if

 if(pStmt->m_PData__BatchFetch.null())
 {
  Helper__ThrowError__GetStmtInfo__NoData(L"isc_info_sql_batch_fetch");
 }//if
}//Process_PrepareInfoBuf

//------------------------------------------------------------------------
template<class TBuffer>
void RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__SaveElementData
                                           (const byte_type* const data_beg,
                                            const byte_type* const data_end,
                                            bool             const data_is_truncated,
                                            TBuffer&               buffer)
{
 assert(data_beg<data_end);

 const size_t n=size_t(data_end-data_beg);

 assert(n<structure::get_numeric_limits(n).max_value());

 buffer.alloc(n+1);

 assert(buffer.size()==(n+1));

 memcpy(buffer.buffer(),
        data_beg,
        n);

 if(data_is_truncated)
  buffer[n]=isc_api::ibp_isc_info_truncated;
 else
  buffer[n]=isc_api::ibp_isc_info_end;
}//Helper__SaveElementData

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__ThrowError__GetStmtInfo__NoData
                                           (const wchar_t* const propSign)
{
 assert(propSign!=nullptr);

 IBP_ThrowCmdError__GetStmtInfo_NoData
  (ibp_subsystem__remote_fb,
   propSign);
}//Helper__ThrowError__GetStmtInfo__NoData

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
