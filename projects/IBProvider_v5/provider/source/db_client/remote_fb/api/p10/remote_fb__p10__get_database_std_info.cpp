////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__p10__get_database_std_info.cpp
//! \brief   Запрос стандартных сведений о сервере и базе данных.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p10/remote_fb__p10__get_database_std_info.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_obj/isc_base/isc_database_info_utils.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/fb_base/fb_api.h"
#include "source/db_obj/db_utility.h"
#include "source/error_services/ibp_error_bug_check.h"
#include <structure/t_str_version.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P10__GetDatabaseStdInfo

void RemoteFB__P10__GetDatabaseStdInfo::exec(RemoteFB__ConnectorData* const pData,
                                             cns_type&                      cns)
{
 assert(pData!=nullptr);

 //1. читаем базовые свойства сервера и базы данных
 self_type::helper__exec1(pData,cns);

 //2. определяем версию сервера и формируем список дополнительных свойств

 //выдираем строку с версией, находящейся за словом Firebird -------------

 //Firebird v0.9.4
 //сведения от сервера "WI-T0.9.4.41 Firebird Test1"

 //Firebird v1.0.2
 //сведения от сервера "WI-V6.2.908 Firebird 1.0"

 //Firebird v1.0.3
 //сведения от сервера "WI-V6.2.972 Firebird 1.0.3"

 //Firebird v1.5.3
 //сведения от сервера "WI-V6.3.3.4870 Firebird 1.5"

 //Firebird v2 RC1
 //сведения от сервера "6.3.0.12484 Firebird 2.0 Release Candidate 1"

 {
  assert(!cns.dbms.descr_Ex.null());

  std::string::size_type
   iFB=cns.dbms.descr_Ex.value().find(isc_base::g_dbms_name_Firebird);

  if(iFB==std::string::npos)
  {
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__p10,
     ibp_mce_common__unknown_dbms_1,
     cns.dbms.descr_Ex.value());
  }//if

  if(structure::cmp_str_version_prefix(cns.dbms.version.c_str(),"0.9")!=0)
  {
   iFB+=strlen(isc_base::g_dbms_name_Firebird);

   assert(iFB<=cns.dbms.descr_Ex.value().size());

   //выдираем описание
   cns.dbms.version=db_obj::extract_substr_with_version(cns.dbms.descr_Ex.value().c_str()+iFB);
  }//if - это не версия 0.9.x.x
 }//local

 //3. читаем дополнительные свойства сервера и базы данных
 helper__exec2(pData,cns);
}//exec

//------------------------------------------------------------------------
const unsigned char RemoteFB__P10__GetDatabaseStdInfo::sm_db_info_items1[]=
{
 isc_api::ibp_isc_info_implementation,
 isc_api::ibp_isc_info_db_id,
 isc_api::ibp_isc_info_db_SQL_dialect,    //IB6+
 isc_api::ibp_isc_info_page_size,
 isc_api::ibp_isc_info_version,
 isc_api::ibp_isc_info_db_read_only,      //IB6+
 isc_api::ibp_isc_info_ods_version,
 isc_api::ibp_isc_info_ods_minor_version,

 //fb_api::ibp_frb_info_firebird_version, //FB1.5
 //fb_api::ibp_frb_info_creation_date,    //FB2.0
};//sm_db_info_items1

//helper methods ---------------------------------------------------------
void RemoteFB__P10__GetDatabaseStdInfo::helper__exec1
                                           (RemoteFB__ConnectorData* const pData,
                                            cns_type&                      cns)
{
 assert(pData!=nullptr);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P10__GetDatabaseStdInfo::helper__exec1";

 //-----------------------------------------------------------------------
 const size_t c_query_ids=_DIM_(sm_db_info_items1);

 typedef structure::t_fix_vector<c_query_ids,unsigned char>  query_ids_type;

 //-----------------------------------------------------------------------
 RemoteFB__InfoBuffer buffer2;

 try
 {
  //query information
  pData->m_API__GetDatabaseInfo.get()->exec
   (pData,
    /*Incornation*/0,
    _DIM_(sm_db_info_items1),
    sm_db_info_items1,
    buffer2); //throw
 }
 catch(const std::exception& e)
 {
  //дополнительная информация о причинах сбоя.
  t_ibp_error exc(e);

  exc.add_error(exc.com_code(),
                ibp_subsystem__remote_fb__p10,
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
     ibp_subsystem__remote_fb__p10,
     ibp_mce_dbobj_fail_get_db_info__buf_is_small_1,
     buffer2.size());
  }//if

  //----------------------------------------
  if(std::find(sm_db_info_items1,_END_(sm_db_info_items1),cluster_id)==_END_(sm_db_info_items1))
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
       ibp_subsystem__remote_fb__p10,
       L"isc_info_db_SQL_dialect");

     break;
    }//ibp_isc_info_db_SQL_dialect

    case isc_api::ibp_isc_info_page_size:
    {
     isc_base::isc_portable_format_to_integer::exec
      (cluster_length,
       cluster_data,
       &cns.db_page_size_Ex,
       ibp_subsystem__remote_fb__p10,
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
       ibp_subsystem__remote_fb__p10,
       L"isc_info_ods_version");

     break;
    }//ibp_isc_info_ods_version

    case isc_api::ibp_isc_info_ods_minor_version:
    {
     isc_base::isc_portable_format_to_integer::exec
      (cluster_length,
       cluster_data,
       &tmp__db_ods_id.minor_num,
       ibp_subsystem__remote_fb__p10,
       L"isc_info_ods_minor_version");

     break;
    }//ibp_isc_info_ods_minor_version

    case isc_api::ibp_isc_info_version:
    {
     isc_base::isc_database_info_utils::read_info__server_version
      (cluster_length,
       cluster_data,
       cns);

     break;
    }//ibp_isc_info_version

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
     ibp_subsystem__remote_fb__p10,
     ibp_mce_dbobj__in_db_info_processing_error_occurred_1,
     cluster_id);
  }//catch
 }//for p

 assert(processed_ids.size()<=_DIM_(sm_db_info_items1));

 if(processed_ids.size()<_DIM_(sm_db_info_items1))
 {
  //ERROR - сервер не вернул сведения для некоторых тегов

  std::wstringstream tags;

  const unsigned char* const b1=sm_db_info_items1;
  const unsigned char* const e1=_END_(sm_db_info_items1);

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
    ibp_subsystem__remote_fb__p10,
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
}//helper__exec1

//------------------------------------------------------------------------
const unsigned char RemoteFB__P10__GetDatabaseStdInfo::sm_db_info_items2[]=
{
 //----------------------------------------- FB 1.5
 fb_api::ibp_frb_info_firebird_version,

 //----------------------------------------- FB2.0
 fb_api::ibp_frb_info_creation_date,
};//sm_db_info_items2

//------------------------------------------------------------------------
void RemoteFB__P10__GetDatabaseStdInfo::helper__exec2
                                           (RemoteFB__ConnectorData* const pData,
                                            cns_type&                      cns)
{
 assert(pData!=nullptr);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P10__GetDatabaseStdInfo::helper__exec2";

 //-----------------------------------------------------------------------
 structure::str_version const fb_ver(cns.dbms.version);//throw

 const size_t c_query_ids=_DIM_(sm_db_info_items2);

 typedef structure::t_fix_vector<c_query_ids,unsigned char>  query_ids_type;

 query_ids_type query_ids;

 //-----------------------------------------------------------------------
 {
  size_t n=structure::negative_one;

  if(fb_ver>=structure::str_version("2"))
  {
   //Firebird 2.0 [all props]
   n=_DIM_(sm_db_info_items2);
  }
  else
  if(fb_ver>=structure::str_version("1.5"))
  {
   //Firebird 1.5
   n=1;
  }
  else
  {
   n=0;
  }//else

  assert(n<=_DIM_(sm_db_info_items2));

  std::copy(sm_db_info_items2,
            sm_db_info_items2+n,
            std::back_inserter(query_ids));
 }//local

 //-----------------------------------------------------------------------
 if(query_ids.empty())
  return; //пустой список информационных элементов

 //-----------------------------------------------------------------------
 RemoteFB__InfoBuffer buffer2;

 try
 {
  //query information
  pData->m_API__GetDatabaseInfo.get()->exec
   (pData,
    /*Incornation*/0,
    static_cast<protocol::P_USHORT>(query_ids.size()),
    query_ids.data(),
    buffer2); //throw
 }
 catch(const std::exception& e)
 {
  //дополнительная информация о причинах сбоя.
  t_ibp_error exc(e);

  exc.add_error(exc.com_code(),
                ibp_subsystem__remote_fb__p10,
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
     ibp_subsystem__remote_fb__p10,
     ibp_mce_dbobj_fail_get_db_info__buf_is_small_1,
     buffer2.size());
  }//if

  //----------------------------------------
  if(std::find(query_ids.cbegin(),query_ids.cend(),cluster_id)==query_ids.cend())
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
     ibp_subsystem__remote_fb__p10,
     ibp_mce_dbobj__in_db_info_processing_error_occurred_1,
     cluster_id);
  }//catch
 }//for p

 assert(processed_ids.size()<=query_ids.size());

 if(processed_ids.size()<query_ids.size())
 {
  //ERROR - сервер не вернул сведения для некоторых тегов

  std::wstringstream tags;

  query_ids_type::const_iterator const b1=query_ids.cbegin();
  query_ids_type::const_iterator const e1=query_ids.cend();

  DEBUG_CODE(size_t not_processed_tag_count=0;)

  const wchar_t* sep=L"";

  for(query_ids_type::const_iterator i1(b1);i1!=e1;++i1)
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
    ibp_subsystem__remote_fb__p10,
    ibp_mce_dbobj_fail_get_db_info__no_data_2,
    ibp::push_value(cns.dbms.descr_Ex,L"???"),
    tags.str());

  assert(false);
 }//if

 /*all is ok*/
}//helper__exec2

////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
