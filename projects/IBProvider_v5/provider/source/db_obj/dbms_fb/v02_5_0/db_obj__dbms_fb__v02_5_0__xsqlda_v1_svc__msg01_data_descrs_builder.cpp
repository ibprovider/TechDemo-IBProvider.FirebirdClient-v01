////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v02_5_0
//! \file    db_obj__dbms_fb__v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder.cpp
//! \brief   XSQLDA_V1 service for building MSG DATA DESCRS [v01].
//! \author  Kovalenko Dmitry
//! \date    23.08.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder.h"
#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__factories.h"
#include "source/db_obj/isc_base/helpers/xsqlda/isc_api_hlp__xsqlda__error_utils.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/ibp_memory_utils.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v02_5_0{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_object_ptr create_xsqlda_v1_svc__msg01_data_descrs_builder()
{
 return fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder::create();
}//create_xsqlda_v1_svc__msg01_data_descrs_builder

////////////////////////////////////////////////////////////////////////////////
//class fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder

fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder
 fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder::sm_Instance;

//------------------------------------------------------------------------
fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder::fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder()
{
}//fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder

//------------------------------------------------------------------------
fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder::~fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder()
{
}//~fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder

//------------------------------------------------------------------------
db_obj::t_db_object_ptr
 fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder::create()
{
 return lib::structure::not_null_ptr(&sm_Instance);
}//create

//t_isc_xsqlda_v1_svc__msg01_data_descrs_builder interface -----------------
void fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder::Build_XSQLDA_MSG_DATA_DESCRS
                             (const isc_api::XSQLDA_V1* const pXSQLDA,
                              msg_data_descrs_type&           MsgDescrs,
                              size_t*                   const pResult_DataSize,
                              size_t*                   const pResult_DataAlign)
{
 assert(pResult_DataSize);
 assert(pResult_DataAlign);

 //-----------------------------------------
 MsgDescrs.clear();

 (*pResult_DataSize)=0;

 (*pResult_DataAlign)=1;

 //-----------------------------------------
 if(pXSQLDA==nullptr)
  return;

 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 if(pXSQLDA->sqld==0)
  return;

 MsgDescrs.resize(static_cast<size_t>(pXSQLDA->sqld));

 size_t szMsg=0;
 size_t cbResultAlign=1;

 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 msg_data_descrs_type::iterator pMsgDescr(MsgDescrs.begin());

 for(;pXVar!=_eXVar;++pXVar,++pMsgDescr)
 {
  assert(pMsgDescr!=MsgDescrs.end());

  try
  {
   szMsg
    =Helper__Build_XSQLDA_MSG_DATA_DESCRS
      (pXVar,
       szMsg,
       *pMsgDescr,
       &cbResultAlign);
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__isc_api__fb2_5,
     ibp_mce_isc__failed_to_process_the_xsqlvar_1,
     (pXVar-pXSQLDA->sqlvar));
  }//catch - e
 }//for pXVar

 (*pResult_DataSize)=szMsg;

 (*pResult_DataAlign)=cbResultAlign;
}//Build_XSQLDA_MSG_DATA_DESCRS

//------------------------------------------------------------------------
size_t fb_v02_5_0__xsqlda_v1_svc__msg01_data_descrs_builder::Helper__Build_XSQLDA_MSG_DATA_DESCRS
                             (const isc_api::XSQLVAR_V1* const pXSQLVAR,
                              size_t                           szMsg,
                              msg_data_descr_type&             MsgDescr,
                              size_t*                    const pcbResultAlign)
{
 assert(pXSQLVAR!=nullptr);

 const isc_api::XSQLVAR_V1::sqltype_type xvar_sqltype=pXSQLVAR->get_typeID();

 MsgDescr.m_xvar_sqltype=xvar_sqltype;

 switch(xvar_sqltype)
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__varying,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(isc_api::isc_varchar_size_type)); //throw

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       xvar_sqllen); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(isc_api::isc_varchar_size_type)+xvar_sqllen;                  // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__varying;

   //---------------------------------------
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

   //---------------------------------------
   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       xvar_sqllen); //throw

   MsgDescr.m_msg_value_block_size
    =xvar_sqllen;                                                         // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__text;

   //---------------------------------------
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

   //---------------------------------------
   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   MsgDescr.m_msg_value_block_size
    =0;                                                                   // SIZE

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__text;

   //---------------------------------------
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__short,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(db_obj::t_dbvalue__i2)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(db_obj::t_dbvalue__i2);                                       // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__short;

   //---------------------------------------
   MsgDescr.m_xvar_sqlscale=pXSQLVAR->sqlscale;

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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__long,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(db_obj::t_dbvalue__i4)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(db_obj::t_dbvalue__i4);                                       // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__long;

   //---------------------------------------
   MsgDescr.m_xvar_sqlscale=pXSQLVAR->sqlscale;

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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__int64,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(db_obj::t_dbvalue__i8)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(db_obj::t_dbvalue__i8);                                       // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__int64;

   //---------------------------------------
   MsgDescr.m_xvar_sqlscale=pXSQLVAR->sqlscale;

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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__quad,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(db_obj::DB_IBBLOBID)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(db_obj::DB_IBBLOBID);                                         // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__quad;

   //---------------------------------------
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__quad,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(db_obj::DB_IBARRAYID)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(db_obj::DB_IBARRAYID);                                        // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__quad;

   //---------------------------------------
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__float,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(db_obj::t_dbvalue__r4)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(db_obj::t_dbvalue__r4);                                       // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__float;

   //---------------------------------------
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__double,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(db_obj::t_dbvalue__r8)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(db_obj::t_dbvalue__r8);                                       // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__double;

   //---------------------------------------
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__time,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(isc_api::t_ibp_isc_time)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(isc_api::t_ibp_isc_time);                                     // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__sql_time;

   //---------------------------------------
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__date,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(isc_api::t_ibp_isc_date)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(isc_api::t_ibp_isc_date);                                     // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__sql_date;

   //---------------------------------------
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

   //---------------------------------------
   szMsg
    =IBP_Memory_Utils::AlignMemLength
      (szMsg,
       isc_api::ibp_isc_type_align__timestamp,
       pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg
    =IBP_Memory_Utils::AddMemLength
      (szMsg,
       sizeof(isc_api::t_ibp_isc_timestamp)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(isc_api::t_ibp_isc_timestamp);                                // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__timestamp;

   //---------------------------------------
   break;
  }//ibp_isc_sql_timestamp

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

 //место под SQLIND
 assert_s(sizeof(db_obj::t_dbvalue__i2)==sizeof(*pXSQLVAR->sqlind));

 szMsg
  =IBP_Memory_Utils::AlignMemLength
    (szMsg,
     /*align*/isc_api::ibp_isc_type_align__short,
     pcbResultAlign); //throw

 MsgDescr.m_msg_sqlind_offset=szMsg;

 szMsg
  =IBP_Memory_Utils::AddMemLength
    (szMsg,
     sizeof(db_obj::t_dbvalue__i2)); //throw

 //-------------------------------------------------------------
 return szMsg;
}//Helper__Build_XSQLDA_MSG_DATA_DESCRS

////////////////////////////////////////////////////////////////////////////////
}/*nms v02_5_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
