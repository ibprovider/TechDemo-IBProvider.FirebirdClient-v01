////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__p11__get_database_std_info.cpp
//! \brief   Запрос стандартных сведений о сервере и базе данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p11/remote_fb__p11__get_database_std_info.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_obj/isc_base/isc_database_info_utils.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/fb_base/fb_api.h"
#include "source/db_obj/db_utility.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P11__GetDatabaseStdInfo

const unsigned char RemoteFB__P11__GetDatabaseStdInfo::sm_db_info_items[]=
{
 isc_api::ibp_isc_info_implementation,
 isc_api::ibp_isc_info_db_id,
 isc_api::ibp_isc_info_db_SQL_dialect,  //IB6+
 isc_api::ibp_isc_info_page_size,
 //isc_api::ibp_isc_info_version,
 isc_api::ibp_isc_info_db_read_only,    //IB6+
 isc_api::ibp_isc_info_ods_version,
 isc_api::ibp_isc_info_ods_minor_version,

 fb_api::ibp_frb_info_firebird_version, //FB1.5
 fb_api::ibp_frb_info_creation_date,    //FB2.0
};//sm_db_info_items

//------------------------------------------------------------------------
void RemoteFB__P11__GetDatabaseStdInfo::exec(RemoteFB__ConnectorData* const pData,
                                             cns_type&                      cns)
{
 assert(pData!=nullptr);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P11__GetDatabaseStdInfo::exec";

 //-----------------------------------------------------------------------
 const size_t c_query_ids=_DIM_(sm_db_info_items);

 typedef structure::t_fix_vector<c_query_ids,unsigned char>  query_ids_type;

 //-----------------------------------------------------------------------
 RemoteFB__InfoBuffer buffer2;

 try
 {
  //query information
  pData->m_API__GetDatabaseInfo.get()->exec
   (pData,
    /*Incornation*/0,
    _DIM_(sm_db_info_items),
    sm_db_info_items,
    buffer2); //throw
 }
 catch(const std::exception& e)
 {
  //дополнительная информация о причинах сбоя.
  t_ibp_error exc(e);

  exc.add_error
   (exc.com_code(),
    ibp_subsystem__remote_fb__p11,
    ibp_mce_dbobj_fail_get_db_info_0);

  exc.raise_me();
 }//catch

 //обработка элементов буфера
 query_ids_type processed_ids;

 isc_base::t_isc_ods_id tmp__db_ods_id;

 for(RemoteFB__InfoBuffer::const_pointer p=buffer2.buffer(),
                                         _e_buffer2=buffer2.buffer_end();
     p!=_e_buffer2;)
 {
  const unsigned char cluster_id=(*p);

  ++p;

  assert(p<=_e_buffer2);

  //----------------------------------------
  if(cluster_id==isc_api::ibp_isc_info_end)
  {
   break;
  }//if

  if(cluster_id==isc_api::ibp_isc_info_truncated)
  {
   //ERROR - buffer is too small

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__p11,
     ibp_mce_dbobj_fail_get_db_info__buf_is_small_1,
     buffer2.size());
  }//if

  //----------------------------------------
  if(std::find(sm_db_info_items,_END_(sm_db_info_items),cluster_id)==_END_(sm_db_info_items))
  {
   //ERROR - unexpected data in result buffer

   IBP_ThrowBugCheck_InfoBuf__UnknownTag
    (c_bugcheck_src,
     L"#001",
     cluster_id);
  }//if

  //----------------------------------------
  if(std::find(processed_ids.cbegin(),processed_ids.cend(),cluster_id)!=processed_ids.cend())
  {
   //ERROR - повторное указание cluster_id в полученном буфере

   IBP_ThrowBugCheck_InfoBuf__MultDefOfElement
    (c_bugcheck_src,
     L"#002",
     cluster_id);
  }//if

  assert(processed_ids.size()<processed_ids.capacity());

  processed_ids.push_back(cluster_id);

  //---------------------------------------- определяем длину данных кластера
  if(size_t(_e_buffer2-p)<isc_api::ibp_isc__info_tag__data_length__byte_count)
  {
   //ERROR - [BUG CHECK] некорректный формат элемента.
   IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
    (c_bugcheck_src,
     L"#003",
     cluster_id);
  }//if

  size_t cluster_length=0;

  assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(cluster_length));

  _VERIFY(isc_base::isc_portable_format_to_integer::exec_r
              (isc_api::ibp_isc__info_tag__data_length__byte_count,
               p,
               &cluster_length));

  p+=isc_api::ibp_isc__info_tag__data_length__byte_count;

  assert(p<=_e_buffer2);

  if(size_t(_e_buffer2-p)<cluster_length)
  {
   //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

   IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
    (c_bugcheck_src,
     L"#004",
     cluster_id,
     cluster_length,
     size_t(_e_buffer2-p));
  }//if

  //----------------------------------------
  const unsigned char* const cluster_data=p;

  p+=cluster_length;

  try
  {
   switch(cluster_id)
   {
    case isc_api::ibp_isc_info_implementation:
    {
     isc_base::isc_database_info_utils::read_info__isc_implementations
      (cluster_length,
       cluster_data,
       cns);

     break;
    }//ibp_isc_info_implementation

    case isc_api::ibp_isc_info_db_id:
    {
     isc_base::isc_database_info_utils::read_info__db_id
      (cluster_length,
       cluster_data,
       cns);

     break;
    }//ibp_isc_info_db_id

    case isc_api::ibp_isc_info_db_SQL_dialect:
    {
     isc_base::isc_portable_format_to_integer::exec
      (cluster_length,
       cluster_data,
       &cns.db_dialect_Ex,
       ibp_subsystem__remote_fb__p11,
       L"isc_info_db_SQL_dialect");

     break;
    }//ibp_isc_info_db_SQL_dialect

    case isc_api::ibp_isc_info_page_size:
    {
     isc_base::isc_portable_format_to_integer::exec
      (cluster_length,
       cluster_data,
       &cns.db_page_size_Ex,
       ibp_subsystem__remote_fb__p11,
       L"isc_info_page_size");

     break;
    }//ibp_isc_info_page_size

    case isc_api::ibp_isc_info_db_read_only:
    {
     cns.db_read_only_Ex
      =!isc_base::isc_portable_integer__is_zero
         (cluster_length,
          cluster_data);

     break;
    }//ibp_isc_info_db_read_only

    case isc_api::ibp_isc_info_ods_version:
    {
     isc_base::isc_portable_format_to_integer::exec
      (cluster_length,
       cluster_data,
       &tmp__db_ods_id.major_num,
       ibp_subsystem__remote_fb__p11,
       L"isc_info_ods_version");

     break;
    }//ibp_isc_info_ods_version

    case isc_api::ibp_isc_info_ods_minor_version:
    {
     isc_base::isc_portable_format_to_integer::exec
      (cluster_length,
       cluster_data,
       &tmp__db_ods_id.minor_num,
       ibp_subsystem__remote_fb__p11,
       L"isc_info_ods_minor_version");

     break;
    }//ibp_isc_info_ods_minor_version

    case fb_api::ibp_frb_info_firebird_version:
    {
     isc_base::isc_database_info_utils::read_info__server_version
      (cluster_length,
       cluster_data,
       cns);

     break;
    }//ibp_frb_info_firebird_version

    case fb_api::ibp_frb_info_creation_date:
    {
     isc_base::isc_database_info_utils::read_info__db_creation_data
      (cluster_length,
       cluster_data,
       cns); //throw

     break;
    }//ibp_frb_info_creation_date

 #ifndef NDEBUG
    default:
    {
     //неизвестные теги мы выявляем в начале текущего цикла

     assert_msg(false,"cluster_id="<<cluster_id);
    }//default
 #endif
   }//switch
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb__p11,
     ibp_mce_dbobj__in_db_info_processing_error_occurred_1,
     cluster_id);
  }//catch
 }//for p

 assert(processed_ids.size()<=_DIM_(sm_db_info_items));

 if(processed_ids.size()<_DIM_(sm_db_info_items))
 {
  //ERROR - сервер не вернул сведения для некоторых тегов

  std::wstringstream tags;

  const unsigned char* const b1=sm_db_info_items;
  const unsigned char* const e1=_END_(sm_db_info_items);

  DEBUG_CODE(size_t not_processed_tag_count=0;)

  const wchar_t* sep=L"";

  for(const unsigned char* i1(b1);i1!=e1;++i1)
  {
   if(std::find(processed_ids.cbegin(),processed_ids.cend(),*i1)!=processed_ids.cend())
    continue;

   DEBUG_CODE(++not_processed_tag_count;)

   tags<<sep<<unsigned(*i1);

   sep=L", ";
  }//for i1

  assert(not_processed_tag_count>0);

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p11,
    ibp_mce_dbobj_fail_get_db_info__no_data_2,
    ibp::push_value(cns.dbms.descr_Ex,L"???"),
    tags.str());

  assert(false);
 }//if

 /*all is ok*/
 cns.db_ods_Ex=tmp__db_ods_id;

 assert(!cns.db_info__file_name_Ex.null());
 assert(!cns.db_info__site_name_Ex.null());
 assert(!cns.db_page_size_Ex.null());
 assert(!cns.dbms.descr_Ex.null());
 assert(!cns.db_ods_Ex.null());
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
