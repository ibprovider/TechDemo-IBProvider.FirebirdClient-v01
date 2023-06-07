////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_v01__utilities-Calc_XSQLDA_MAX_XDR_SIZE.cpp
//! \brief   Utilities for processing XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    10.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/remote_fb__api_hlp__xsqlda__error_utils.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__info.h"
#include "source/ibp_memory_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

size_t RemoteFB__API_HLP__XSQLDA_V01__Utilities::Calc_XSQLDA_MAX_XDR_SIZE
                                           (const isc_api::XSQLDA_V1* const pXSQLDA)
{
 if(pXSQLDA==nullptr)
 {
  return 0;
 }//if

 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 if(pXSQLDA->sqld==0)
 {
  return 0;
 }//if

 //-----------------------------------------
 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 size_t cbResult=0;

 for(;pXVar!=_eXVar;++pXVar)
 {
  try
  {
   const size_t x=Helper__Calc_XSQLDA_MAX_XDR_SIZE(pXVar);

   cbResult
    =IBP_Memory_Utils::AddMemLength
      (cbResult,
       x);
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb,
     ibp_mce_isc__failed_to_process_the_xsqlvar_1,
     (pXVar-pXSQLDA->sqlvar));
  }//catch - e
 }//for pXVar

 return cbResult;
}//Helper__Build_XSQLDA_MSG_BLR__FillBuf

//------------------------------------------------------------------------
size_t RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__Calc_XSQLDA_MAX_XDR_SIZE
                                           (const isc_api::XSQLVAR_V1* const pXSQLVAR)
{
 assert(pXSQLVAR!=nullptr);

 typedef transmission::RemoteFB__XDR__Info xdr;

 const isc_api::XSQLVAR_V1::sqltype_type xvar_sqltype=pXSQLVAR->get_typeID();

 size_t cbResult=0;

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
   cbResult =xdr::get_size__p_short(); //throw

   cbResult+=xdr::get_size__opaque(xvar_sqllen); //throw

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
   cbResult=xdr::get_size__opaque(xvar_sqllen); //throw

   //---------------------------------------
   break;
  }//ibp_isc_sql_text

  //------------------------------------------------------------
  case isc_api::ibp_fb025_sql_null:
  {
   if(pXSQLVAR->sqllen!=0)
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_null",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   cbResult=0;

   //---------------------------------------
   break;
  }//ibp_fb025_sql_null

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
   cbResult=xdr::get_size__p_short();

   //---------------------------------------
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
   cbResult=xdr::get_size__p_long();

   //---------------------------------------
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
   cbResult=xdr::get_size__p_int64();

   //---------------------------------------
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
   cbResult=xdr::get_size__p_bid();

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
   cbResult=xdr::get_size__p_bid();

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
   cbResult=xdr::get_size__p_float();

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
   cbResult=xdr::get_size__p_double();

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
   cbResult=xdr::get_size__p_ulong_as_p_long();

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
   cbResult=xdr::get_size__p_long();

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
   cbResult=xdr::get_size__p_long();

   cbResult+=xdr::get_size__p_ulong_as_p_long();

   //---------------------------------------
   break;
  }//ibp_isc_sql_timestamp

  //------------------------------------------------------------
  case isc_api::ibp_fb030_sql_boolean:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_fb030_bool))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_boolean",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   cbResult=xdr::get_size__opaque(sizeof(isc_api::t_ibp_fb030_bool));

   //---------------------------------------
   break;
  }//ibp_fb030_sql_boolean

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_int128:
  {
   assert_s(std::is_same<isc_api::t_ibp_fb040_int128 _LITER_COMMA_ protocol::P_INT128>::value);

   if(pXSQLVAR->sqllen!=sizeof(protocol::P_INT128))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_int128",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   cbResult=xdr::get_size__p_int128();

   assert(cbResult==sizeof(protocol::P_INT128));

   //---------------------------------------
   break;
  }//ibp_fb040_sql_int128

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_decfloat16:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_fb040_decfloat16))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_decfloat16",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   cbResult=xdr::get_size__p_decfloat16();

   assert(cbResult==sizeof(protocol::P_DECFLOAT16));

   //---------------------------------------
   break;
  }//ibp_fb040_sql_decfloat16

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_decfloat34:
  {
   if(pXSQLVAR->sqllen!=sizeof(isc_api::t_ibp_fb040_decfloat34))
   {
    //ERROR - [BUG CHECK] incorrect xvar length;
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_decfloat34",
      pXSQLVAR->sqllen);
   }//if

   //---------------------------------------
   cbResult=xdr::get_size__p_decfloat34();

   assert(cbResult==sizeof(protocol::P_DECFLOAT34));

   //---------------------------------------
   break;
  }//ibp_fb040_sql_decfloat34

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
 assert_s(sizeof(protocol::P_SHORT)==sizeof(*pXSQLVAR->sqlind));

 cbResult+=xdr::get_size__p_short();

 //-------------------------------------------------------------
 return cbResult;
}//Helper__Calc_XSQLDA_MAX_XDR_SIZE - XSQLVAR_V1

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
