////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__xsqlda_utilities__Build_XSQLDA_MSG_DATA_DESCRS.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/remote_fb__api_hlp__xsqlda__error_utils.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__XSQLDA_Utilities

void RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA_DESCRS
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
   szMsg=Helper__Build_XSQLDA_MSG_DATA_DESCRS(pXVar,
                                              szMsg,
                                              *pMsgDescr,
                                              &cbResultAlign);
  }
  catch(const std::exception& e)
  {
   t_ibp_error exc(e);

   exc.add_error(E_FAIL,
                 ibp_subsystem__remote_fb__p13,
                 ibp_mce_isc__failed_to_process_the_xsqlvar_1);

   exc<<(pXVar-pXSQLDA->sqlvar);

   exc.raise_me();
  }//catch - e
 }//for pXVar

 (*pResult_DataSize)=szMsg;

 (*pResult_DataAlign)=cbResultAlign;
}//Build_XSQLDA_MSG_DATA_DESCRS

//------------------------------------------------------------------------
size_t RemoteFB__P13__XSQLDA_Utilities::Helper__Build_XSQLDA_MSG_DATA_DESCRS
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
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_varying",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   if(isc_api::ibp_isc_max_varchar_length<xvar_sqllen)
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_varying",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__varying,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(isc_api::isc_varchar_size_type)); //throw

   szMsg=Helper__AddMsgLength(szMsg,
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
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_text",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   if(isc_api::ibp_isc_max_char_length<xvar_sqllen)
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_text",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              xvar_sqllen); //throw

   MsgDescr.m_msg_value_block_size
    =xvar_sqllen;                                                         // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__text;

   //---------------------------------------
   break;
  }//ibp_isc_sql_text

  //------------------------------------------------------------
  case isc_api::ibp_fb25_sql_null:
  {
   if(pXSQLVAR->sqllen!=0)
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
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
  }//ibp_fb25_sql_null

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_short:
  {
   if(pXSQLVAR->sqllen!=sizeof(protocol::P_SHORT))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_short",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__short,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(protocol::P_SHORT)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(protocol::P_SHORT);                                           // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__short;

   //---------------------------------------
   MsgDescr.m_xvar_sqlscale=pXSQLVAR->sqlscale;

   break;
  }//ibp_isc_sql_short

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_long:
  {
   if(pXSQLVAR->sqllen!=sizeof(protocol::P_LONG))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_long",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__long,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(protocol::P_LONG)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(protocol::P_LONG);                                            // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__long;

   //---------------------------------------
   MsgDescr.m_xvar_sqlscale=pXSQLVAR->sqlscale;

   break;
  }//ibp_isc_sql_long

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_int64:
  {
   if(pXSQLVAR->sqllen!=sizeof(protocol::P_INT64))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_int64",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__int64,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(protocol::P_INT64)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(protocol::P_INT64);                                           // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__int64;

   //---------------------------------------
   MsgDescr.m_xvar_sqlscale=pXSQLVAR->sqlscale;

   break;
  }//ibp_isc_sql_int64

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_blob:
  {
   if(pXSQLVAR->sqllen!=sizeof(protocol::P_BID))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_blob",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__quad,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(protocol::P_BID)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(protocol::P_BID);                                             // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__quad;

   //---------------------------------------
   break;
  }//ibp_isc_sql_blob

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_array:
  {
   if(pXSQLVAR->sqllen!=sizeof(protocol::P_BID))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_array",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__quad,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(protocol::P_BID)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(protocol::P_BID);                                             // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__quad;

   //---------------------------------------
   break;
  }//ibp_isc_sql_array

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_float:
  {
   if(pXSQLVAR->sqllen!=sizeof(protocol::P_FLOAT))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_float",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__float,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(protocol::P_FLOAT)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(protocol::P_FLOAT);                                           // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__float;

   //---------------------------------------
   break;
  }//ibp_isc_sql_float

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_double:
  {
   if(pXSQLVAR->sqllen!=sizeof(protocol::P_DOUBLE))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_double",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__double,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(protocol::P_DOUBLE)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(protocol::P_DOUBLE);                                          // SIZE

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
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_time",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__time,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
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
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_date",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__date,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
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
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_timestamp",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_isc_type_align__timestamp,
                                pcbResultAlign); //throw

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(isc_api::t_ibp_isc_timestamp)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(isc_api::t_ibp_isc_timestamp);                                // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_isc_blr_dtype__timestamp;

   //---------------------------------------
   break;
  }//ibp_isc_sql_timestamp

  //------------------------------------------------------------
  case isc_api::ibp_fb30_sql_boolean:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_fb30_bool))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_boolean",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   szMsg=Helper__AlignMsgLength(szMsg,
                                isc_api::ibp_fb30_type_align__bool,
                                pcbResultAlign); //throw         6

   MsgDescr.m_msg_value_block_offset
    =szMsg;                                                               // OFFSET

   szMsg=Helper__AddMsgLength(szMsg,
                              sizeof(isc_api::t_ibp_fb30_bool)); //throw

   MsgDescr.m_msg_value_block_size
    =sizeof(isc_api::t_ibp_fb30_bool);                                    // SIZE

   assert(MsgDescr.m_msg_value_block_size==(szMsg-MsgDescr.m_msg_value_block_offset));

   MsgDescr.m_msg_blrtype=isc_api::ibp_fb30_blr_dtype__bool;

   //---------------------------------------
   break;
  }//ibp_fb30_sql_boolean

  //------------------------------------------------------------
  default:
  {
   //ERROR - [BUG CHECK] unexpected sqltypeID

   t_ibp_error exc(E_FAIL,
                   ibp_mce_isc__bug_check__unknown_sqltype_in_xvar_1);

   exc<<pXSQLVAR->sqltype;

   exc.raise_me();
  }//default
 }//switch

 //место под SQLIND
 assert_s(sizeof(protocol::P_SHORT)==sizeof(*pXSQLVAR->sqlind));

 szMsg=Helper__AlignMsgLength(szMsg,
                              /*align*/isc_api::ibp_isc_type_align__short,
                              pcbResultAlign); //throw

 MsgDescr.m_msg_sqlind_offset=szMsg;

 szMsg=Helper__AddMsgLength(szMsg,
                            sizeof(protocol::P_SHORT)); //throw

 //-------------------------------------------------------------
 return szMsg;
}//Helper__Build_XSQLDA_MSG_DATA_DESCRS

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
