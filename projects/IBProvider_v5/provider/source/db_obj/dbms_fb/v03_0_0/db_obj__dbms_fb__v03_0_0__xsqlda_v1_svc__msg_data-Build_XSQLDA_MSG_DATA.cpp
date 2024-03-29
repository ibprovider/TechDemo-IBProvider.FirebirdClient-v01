////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg_data-Build_XSQLDA_MSG_DATA.cpp
//! \brief   XSQLDA_V1 service for working with message data.
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg_data.h"
#include "source/db_obj/isc_base/helpers/xsqlda/isc_api_hlp__xsqlda__error_utils.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/ibp_memory_utils.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__xsqlda_v1_svc__msg_data

void fb_v03_0_0__xsqlda_v1_svc__msg_data::Build_XSQLDA_MSG_DATA
                                           (const isc_api::XSQLDA_V1* const pXSQLDA,
                                            msg_data_buffer_type&           DataBuffer)
{
 if(pXSQLDA==nullptr)
 {
  DataBuffer.alloc(0);
  return;
 }//if

 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 if(pXSQLDA->sqld==0)
 {
  DataBuffer.alloc(0);
  return;
 }//if

 DataBuffer.alloc(Helper__Build_XSQLDA_MSG_DATA__CalcBufSize(pXSQLDA)); //throw

 Helper__Build_XSQLDA_MSG_DATA__FillBuf(pXSQLDA,DataBuffer); //throw
}//Build_XSQLDA_MSG_DATA

//------------------------------------------------------------------------
size_t fb_v03_0_0__xsqlda_v1_svc__msg_data::Helper__Build_XSQLDA_MSG_DATA__CalcBufSize
                                           (const isc_api::XSQLDA_V1* const pXSQLDA)
{
 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 size_t szMsg=0;

 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 for(;pXVar!=_eXVar;++pXVar)
 {
  try
  {
   szMsg=Helper__Build_XSQLDA_MSG_DATA__CalcBufSize(pXVar,szMsg);
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__isc_api__fb3_0,
     ibp_mce_isc__failed_to_process_the_xsqlvar_1,
     (pXVar-pXSQLDA->sqlvar));
  }//catch - e
 }//for pXVar

 return szMsg;
}//Helper__Build_XSQLDA_MSG_DATA__CalcBufSize

//------------------------------------------------------------------------
size_t fb_v03_0_0__xsqlda_v1_svc__msg_data::Helper__Build_XSQLDA_MSG_DATA__CalcBufSize
                                           (const isc_api::XSQLVAR_V1* const pXSQLVAR,
                                            size_t                           szMsg)
{
 assert(pXSQLVAR!=nullptr);

 switch(pXSQLVAR->get_typeID())
 {
  case isc_api::ibp_isc_sql_varying:
  {
   if(!structure::can_numeric_cast<size_t>(pXSQLVAR->sqllen))
   {
    assert(pXSQLVAR->sqllen<0);

    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_varying",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   if(isc_api::ibp_isc_max_varchar_length<xvar_sqllen)
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_varying",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(isc_api::isc_varchar_size_type),
       /*align*/isc_api::ibp_isc_type_align__varying,
       /*pcbResultAlign*/nullptr); //throw

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/xvar_sqllen); //throw

   break;
  }//ibp_isc_sql_varying

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_text:
  {
   if(!structure::can_numeric_cast<size_t>(pXSQLVAR->sqllen))
   {
    assert(pXSQLVAR->sqllen<0);

    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_text",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   if(isc_api::ibp_isc_max_char_length<xvar_sqllen)
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_text",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/xvar_sqllen); //throw

   break;
  }//ibp_isc_sql_text

  //------------------------------------------------------------
  case isc_api::ibp_fb025_sql_null:
  {
   if(pXSQLVAR->sqllen!=0)
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_null",
      pXSQLVAR->sqllen);
   }//if

   break;
  }//ibp_fb025_sql_null

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_short:
  {
   if(pXSQLVAR->sqllen!=sizeof(db_obj::t_dbvalue__i2))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_short",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(db_obj::t_dbvalue__i2),
       /*align*/isc_api::ibp_isc_type_align__short,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_short

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_long:
  {
   if(pXSQLVAR->sqllen!=sizeof(db_obj::t_dbvalue__i4))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_long",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(db_obj::t_dbvalue__i4),
       /*align*/isc_api::ibp_isc_type_align__long,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_long

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_int64:
  {
   if(pXSQLVAR->sqllen!=sizeof(db_obj::t_dbvalue__i8))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_int64",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(db_obj::t_dbvalue__i8),
       /*align*/isc_api::ibp_isc_type_align__int64,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_int64

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_blob:
  {
   if(pXSQLVAR->sqllen!=sizeof(db_obj::DB_IBBLOBID))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_blob",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(db_obj::DB_IBBLOBID),
       /*align*/isc_api::ibp_isc_type_align__quad,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_blob

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_array:
  {
   if(pXSQLVAR->sqllen!=sizeof(db_obj::DB_IBARRAYID))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_array",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(db_obj::DB_IBARRAYID),
       /*align*/isc_api::ibp_isc_type_align__quad,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_array

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_float:
  {
   if(pXSQLVAR->sqllen!=sizeof(db_obj::t_dbvalue__r4))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_float",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(db_obj::t_dbvalue__r4),
       /*align*/isc_api::ibp_isc_type_align__float,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_float

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_double:
  {
   if(pXSQLVAR->sqllen!=sizeof(db_obj::t_dbvalue__r8))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_double",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(db_obj::t_dbvalue__r8),
       /*align*/isc_api::ibp_isc_type_align__double,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_double

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_type_time:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_isc_time))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_time",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(isc_api::t_ibp_isc_time),
       /*align*/isc_api::ibp_isc_type_align__time,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_type_time

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_type_date:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_isc_date))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_date",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(isc_api::t_ibp_isc_date),
       /*align*/isc_api::ibp_isc_type_align__date,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_type_date

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_timestamp:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_isc_timestamp))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_timestamp",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(isc_api::t_ibp_isc_timestamp),
       /*align*/isc_api::ibp_isc_type_align__timestamp,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_isc_sql_timestamp

  //------------------------------------------------------------
  case isc_api::ibp_fb030_sql_boolean:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_fb030_bool))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_boolean",
      pXSQLVAR->sqllen);
   }//if

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       /*data size*/sizeof(isc_api::t_ibp_fb030_bool),
       /*align*/isc_api::ibp_fb030_type_align__bool,
       /*pcbResultAlign*/nullptr); //throw

   break;
  }//ibp_fb030_sql_boolean

  //------------------------------------------------------------
  default:
  {
   //ERROR - [BUG CHECK] unexpected sqltypeID

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_isc__bug_check__unknown_sqltype_in_xvar_1,
     pXSQLVAR->sqltype);
  }//default
 }//switch

 //����� ��� SQLIND
 szMsg
  =IBP_Memory_Utils::AddMemLength
    (szMsg,
     /*data size*/sizeof(db_obj::t_dbvalue__i2),
     /*align*/isc_api::ibp_isc_type_align__short,
     /*pcbResultAlign*/nullptr); //throw

 return szMsg;
}//Helper__Build_XSQLDA_MSG_DATA__CalcBufSize

//------------------------------------------------------------------------
void fb_v03_0_0__xsqlda_v1_svc__msg_data::Helper__Build_XSQLDA_MSG_DATA__FillBuf
                                           (const isc_api::XSQLDA_V1* const pXSQLDA,
                                            msg_data_buffer_type&           DataBuffer)
{
 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 assert(!DataBuffer.empty());

 //��������� ������������� (� ��� ����� - ������ ������)
 memset(DataBuffer.buffer(),0,DataBuffer.size());

 size_t offset=0;

 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 for(;pXVar!=_eXVar;++pXVar)
 {
  try
  {
   offset
    =Helper__Build_XSQLDA_MSG_DATA__FillBuf
      (pXVar,
       DataBuffer,
       offset);
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__isc_api__fb3_0,
     ibp_mce_isc__failed_to_process_the_xsqlvar_1,
     (pXVar-pXSQLDA->sqlvar));
  }//catch
 }//for pXVar

 assert(offset==DataBuffer.size());
}//Helper__Build_XSQLDA_MSG_DATA__FillBuf

//------------------------------------------------------------------------
size_t fb_v03_0_0__xsqlda_v1_svc__msg_data::Helper__Build_XSQLDA_MSG_DATA__FillBuf
                                           (const isc_api::XSQLVAR_V1* const pXSQLVAR,
                                            msg_data_buffer_type&            DataBuffer,
                                            size_t                           offset)
{
 assert(pXSQLVAR);
 assert(offset<=DataBuffer.size());

 //����������� NULL-�������� ����������� �� �������� � ISC API:
 // - ������ ���� ���������� ������� ���
 // - sqlind ��������� �� ��������� ��������
 bool IsNull=false;

 if(pXSQLVAR->get_value_may_be_null())
 {
  if(pXSQLVAR->sqlind==nullptr)
  {
   //ERROR - incorrect data in XSQLVAR structure. null pointer to sql indicator.

   isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
    (pXSQLVAR->sqltype);
  }//if

  IsNull=pXSQLVAR->get_value_is_null__std();
 }//if

 //-------------------------------------------------------------
 switch(pXSQLVAR->get_typeID())
 {
  case isc_api::ibp_isc_sql_varying:
  {
   assert(structure::can_numeric_cast<size_t>(pXSQLVAR->sqllen));

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   assert(xvar_sqllen<=isc_api::ibp_isc_max_varchar_length);

   assert(sizeof(isc_api::isc_varchar_size_type)<=structure::t_numeric_limits<size_t>::max_value());

   assert(xvar_sqllen<=structure::t_numeric_limits<size_t>::max_value());

   assert(xvar_sqllen<=structure::t_numeric_limits<size_t>::max_value()-sizeof(isc_api::isc_varchar_size_type));

   const size_t block_length=sizeof(isc_api::isc_varchar_size_type)+xvar_sqllen;

   //--------------------------------------
   assert(offset<=DataBuffer.size());

   const size_t c_align=isc_api::ibp_isc_type_align__varying;

   assert_s(c_align==sizeof(isc_api::isc_varchar_size_type));

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(block_length<=(DataBuffer.size()-offset));

   //--------------------------------------
   if(!IsNull)
   {
    assert(pXSQLVAR->sqldata!=nullptr);

    CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(isc_api::isc_varchar_size_type));

    assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%sizeof(isc_api::isc_varchar_size_type))==0);

    const isc_api::isc_varchar_size_type
     varchar_size
      =*reinterpret_cast<const isc_api::isc_varchar_size_type*>(pXSQLVAR->sqldata);

    if(!structure::can_numeric_cast<size_t>(varchar_size))
    {
     assert(varchar_size<0);

     //ERROR - [BUF CHECK] incorrect varchar size

     //[2015-05-16] ����� ��������� ���������� ������ ��� ������� �����.
     assert_msg(false,"sz: "<<varchar_size);

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__bug_check__incorrect_varchar_data_length_1,
       varchar_size);
    }//if

    if(xvar_sqllen<static_cast<size_t>(varchar_size))
    {
     //ERROR - [BUG CHECK] incorrect varchar size [��������� ����������� ���������� �����]

     //[2015-05-16] ����� ��������� ���������� ������ ��� ������� �����.
     assert_msg(false,"sz: "<<varchar_size<<". buf_sz: "<<xvar_sqllen);

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__bug_check__varchar_data_length_is_greater_than_buffer_size_2,
       varchar_size,
       xvar_sqllen);
    }//if

    const size_t cb=sizeof(isc_api::isc_varchar_size_type)+varchar_size;

    CHECK_READ_PTR(pXSQLVAR->sqldata,cb);

    memcpy(DataBuffer.ptr_at(offset),pXSQLVAR->sqldata,cb);
   }//if

   offset+=block_length;
   break;
  }//ibp_isc_sql_varying

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_text:
  {
   assert(structure::can_numeric_cast<size_t>(pXSQLVAR->sqllen));

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   assert(xvar_sqllen<=isc_api::ibp_isc_max_char_length);

   CHECK_READ_PTR(pXSQLVAR->sqldata,xvar_sqllen);

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   assert(xvar_sqllen<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    memcpy(DataBuffer.ptr_at(offset),pXSQLVAR->sqldata,xvar_sqllen);
   }//if

   offset+=xvar_sqllen;
   break;
  }//ibp_isc_sql_text

  //------------------------------------------------------------
  case isc_api::ibp_fb025_sql_null:
  {
   assert(pXSQLVAR->sqllen==0);

   break;
  }//ibp_fb025_sql_null

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_short:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__short;

   typedef db_obj::t_dbvalue__i2 sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_short

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_long:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__long;

   typedef db_obj::t_dbvalue__i4 sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_long

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_int64:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__int64;

   typedef db_obj::t_dbvalue__i8 sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   //[2015-05-09] ����� ����� ����� �������� � 32-������ ����. � ��� ������������ �� size_t.
   //[2015-05-12] ��� � ����.
   //assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_int64

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_blob:
  case isc_api::ibp_isc_sql_array:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__quad;

   typedef db_obj::DB_IBQUAD sqldata_type;

   //-------------------------------------
   assert_s(sizeof(db_obj::DB_IBARRAYID)==sizeof(sqldata_type));
   assert_s(sizeof(db_obj::DB_IBBLOBID)==sizeof(sqldata_type));

   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    //����������� DB_IBBLOBID/DB_IBARRAYID � P_BID

    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_blob,ibp_isc_sql_array

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_float:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__float;

   typedef db_obj::t_dbvalue__r4 sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_float

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_double:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__double;

   typedef db_obj::t_dbvalue__r8 sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   //! [2015-05-09] ����� ����� ����� �������� � 32-������ ����. � ��� ������������ �� size_t.
   //! [2015-05-15] ��� � ����.
   //assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_double

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_type_time:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__time;

   typedef isc_api::t_ibp_isc_time sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_type_time

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_type_date:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__date;

   typedef isc_api::t_ibp_isc_date sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_type_date

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_timestamp:
  {
   const size_t c_align=isc_api::ibp_isc_type_align__timestamp;

   typedef isc_api::t_ibp_isc_timestamp sqldata_type;

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_isc_sql_timestamp

  //------------------------------------------------------------
  case isc_api::ibp_fb030_sql_boolean:
  {
   const size_t c_align=isc_api::ibp_fb030_type_align__bool;

   typedef isc_api::t_ibp_fb030_bool sqldata_type;

   assert_s(c_align==sizeof(sqldata_type));

   //-------------------------------------
   assert(pXSQLVAR->sqllen==sizeof(sqldata_type));

   assert(pXSQLVAR->sqldata!=nullptr);

   assert((reinterpret_cast<size_t>(pXSQLVAR->sqldata)%c_align)==0);

   CHECK_READ_PTR(pXSQLVAR->sqldata,sizeof(sqldata_type));

   //-------------------------------------
   assert(offset<=DataBuffer.size());

   _VERIFY(structure::align_memory_size(offset,c_align));

   assert((offset%c_align)==0);
   assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

   assert(offset<=DataBuffer.size());

   assert(sizeof(sqldata_type)<=(DataBuffer.size()-offset));

   //-----
   if(!IsNull)
   {
    (*reinterpret_cast<sqldata_type*>(DataBuffer.ptr_at(offset)))
      =(*reinterpret_cast<const sqldata_type*>(pXSQLVAR->sqldata));
   }//if

   offset+=sizeof(sqldata_type);
   break;
  }//ibp_fb030_sql_boolean

  //------------------------------------------------------------
  default:
  {
   //[2015-05-14]
   // � ��� ����� �� �� ������ �������� � ��������.
   // ����������� ���� ������ ������������� �� ������ Helper__Build_XSQLDA_MSG_DATA__CalcBufSize
   assert(false);

   //ERROR - [BUG CHECK] unexpected sqltypeID

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_isc__bug_check__unknown_sqltype_in_xvar_1,
     pXSQLVAR->sqltype);
  }//default
 }//switch

 {
  //��������� �������� ���������� ������
  const size_t c_align=isc_api::ibp_isc_type_align__short;

  typedef db_obj::t_dbvalue__i2 value_type;

  assert_s(c_align==sizeof(value_type));

  //-------------------------------------
  assert(offset<=DataBuffer.size());

  _VERIFY(structure::align_memory_size(offset,c_align));

  assert((offset%c_align)==0);
  assert((reinterpret_cast<size_t>(DataBuffer.ptr_at(offset))%c_align)==0);

  assert(offset<=DataBuffer.size());

  assert(sizeof(value_type)<=(DataBuffer.size()-offset));

  //-----
  if(IsNull)
  {
   (*reinterpret_cast<value_type*>(DataBuffer.ptr_at(offset)))=-1;
  }
  else
  {
   //[2016-03-17] ����� ������ ��� ���� ��������������� ������
   assert((*reinterpret_cast<value_type*>(DataBuffer.ptr_at(offset)))==0);

   //[2016-03-17] ���� ������, ��� �������� NOT NULL.
   (*reinterpret_cast<value_type*>(DataBuffer.ptr_at(offset)))=0;
  }//else

  offset+=sizeof(value_type);
 }//local

 return offset;
}//Helper__Build_XSQLDA_MSG_DATA__FillBuf

////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
