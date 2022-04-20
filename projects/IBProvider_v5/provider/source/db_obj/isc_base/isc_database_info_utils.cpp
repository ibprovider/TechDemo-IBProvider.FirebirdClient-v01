////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_database_info_utils.cpp
//! \brief   Утилиты для обработки информационных свойств базы данных
//! \author  Kovalenko Dmitry
//! \date    04.01.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_database_info_utils.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/db_utility.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_database_info_utils

void isc_database_info_utils::read_info__isc_implementations
                                           (size_t               const szData,
                                            const unsigned char* const pData,
                                            cns_type&                  cns)
{
 CHECK_READ_TYPED_PTR(pData,szData);

 assert(cns.db_info__impl_stack.empty());

 //-----------------------------------------
 cns.db_info__impl_stack.clear();

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"isc_database_info_utils::read_info__isc_implementations";

 if(szData==0 || ((szData-1)%2)!=0)
 {
  //ERROR - некорректная длина данных
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    szData);
 }//if

 assert(szData>0);
 assert(((szData-1)%2)==0);

 const size_t expectedBlockCount=((szData-1)/2);

 unsigned char actualBlockCount=*pData;

 if(actualBlockCount!=expectedBlockCount)
 {
  structure::wstr_formatter
   freason(ibp::me_bug_check__unexpected_block_count_2);

  freason<<actualBlockCount<<expectedBlockCount;

  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#002",
    freason.c_str());
 }//if actualBlockCount!=expectedBlockCount

 assert(actualBlockCount==expectedBlockCount);

 const unsigned char* p=pData+1;

 //----------------------------------------- перекачиваем данные в cns.db_impl_stack
 cns.db_info__impl_stack.reserve(actualBlockCount);

 cns_type::tag_db_info__impl impl;

 for(;actualBlockCount>0;--actualBlockCount)
 {
  impl.isc_implId=*p;

  ++p;

  impl.isc_classId=*p;

  ++p;

  //----
  cns.db_info__impl_stack.push_back(impl);
 }//for n
}//read_info__isc_implementations

//------------------------------------------------------------------------
void isc_database_info_utils::read_info__db_id
                                           (size_t               const szData,
                                            const unsigned char* const pData,
                                            cns_type&                  cns)
{
 CHECK_READ_TYPED_PTR(pData,szData);

 const wchar_t* const c_bugcheck_src
  =L"isc_database_info_utils::read_info__db_id";

 if(szData<3)
 {
  //ERROR - некорректная длина данных
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    szData);
 }//if

 assert(3<=szData);

 const size_t fl=pData[1];

 if(size_t(szData-3)<fl)
 {
  //ERROR - длина имени файла вылазит за границу буфера

  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    fl,
    szData-3);
 }//if

 assert(fl<(fl+2));

 const size_t sl=pData[2+fl];

 if(size_t(szData-3-fl)<sl)
 {
  //ERROR - длина имени хоста вылазит за границу буфера

  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#003",
    fl,
    szData-3-fl);
 }//if

 cns.db_info__file_name_Ex=std::string(reinterpret_cast<const char*>(pData+2)   ,fl);
 cns.db_info__site_name_Ex=std::string(reinterpret_cast<const char*>(pData+3+fl),sl);
}//read_info__db_id

//------------------------------------------------------------------------
void isc_database_info_utils::read_info__server_version
                                           (size_t               const szData,
                                            const unsigned char* const pData,
                                            cns_type&                  cns)
{
 CHECK_READ_TYPED_PTR(pData,szData);

 const wchar_t* const c_bugcheck_src
  =L"isc_database_info_utils::read_info__server_version";

 if(szData<2)
 {
  //ERROR - некорректная структура данных
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    szData);
 }//if

 //if(p[0]!=1) //standart value of byte
 // break;

 const size_t fl=pData[1];

 assert(2<=szData);

 if((szData-2)<fl)
 {
  //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    fl,
    szData-2);
 }//if

 cns.dbms.descr_Ex=std::string(reinterpret_cast<const char*>(pData+2),fl);

 {
  const std::string
   tmp_str_with_ver(db_obj::extract_substr_with_version(cns.dbms.descr_Ex.value().c_str()));

  if(!tmp_str_with_ver.empty())
   cns.dbms.version=tmp_str_with_ver;
 }//local
}//read_info__server_version

//------------------------------------------------------------------------
void isc_database_info_utils::read_info__db_creation_data
                                           (size_t               const szData,
                                            const unsigned char* const pData,
                                            cns_type&                  cns)
{
 CHECK_READ_TYPED_PTR(pData,szData);

 const wchar_t* const c_bugcheck_src
  =L"isc_database_info_utils::read_info__db_creation_data";

 if(szData!=sizeof(isc_api::t_ibp_isc_timestamp))
 {
  //ERROR - некорректная длина данных
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    szData);
 }//if

 isc_api::t_ibp_isc_timestamp d;

 isc_base::isc_portable_format_to_integer::exec
  (sizeof(d.timestamp_date),
   pData,
   &d.timestamp_date,
   ibp_subsystem__isc_api__init_cn,
   L"db_info_creation_date.date"); //throw

 isc_base::isc_portable_format_to_integer::exec
  (sizeof(d.timestamp_time),
   pData+sizeof(d.timestamp_date),
   &d.timestamp_time,
   ibp_subsystem__isc_api__init_cn,
   L"db_info_creation_date.time"); //throw

 cns.db_date_create_Ex=d;
}//helper__read_info__db_creation_data

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
