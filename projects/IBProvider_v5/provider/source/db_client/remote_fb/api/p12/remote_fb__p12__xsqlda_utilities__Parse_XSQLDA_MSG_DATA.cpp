////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__xsqlda_utilities__Parse_XSQLDA_MSG_DATA.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    18.05.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__p12__xsqlda_utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/remote_fb__api_hlp__xsqlda__error_utils.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__XSQLDA_Utilities

void RemoteFB__P12__XSQLDA_Utilities::Parse_XSQLDA_MSG_DATA
                                           (const msg_data_descrs_type&     MsgDescrs,
                                            size_t                    const cbMsgData,
                                            const byte_type*          const pMsgData,
                                            const isc_api::XSQLDA_V1* const pXSQLDA)
{
 CHECK_READ_PTR(pMsgData,cbMsgData);

 size_t nXVars=0;

 if(pXSQLDA!=nullptr)
 {
  assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
  assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
  assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
  assert(pXSQLDA->sqld<=pXSQLDA->sqln);

  nXVars=static_cast<size_t>(pXSQLDA->sqld);
 }//if

 if(nXVars!=MsgDescrs.size())
 {
  //ERROR - рассогласованная структура pXSQLDA и MSG-буфера. Разное количество элементов.

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_isc__bug_check__other_count_of_xvars_2,
    nXVars,
    MsgDescrs.size());
 }//if

 if(nXVars==0)
  return;

 assert(pXSQLDA!=nullptr);
 assert(cbMsgData>0);

 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 msg_data_descrs_type::const_iterator pMsgDescr(MsgDescrs.begin());

#ifndef NDEBUG
 size_t  debug__offset=0;
#endif

 for(;pXVar!=_eXVar;++pXVar,++pMsgDescr)
 {
  assert(pMsgDescr!=MsgDescrs.end());

  assert(debug__offset<=pMsgDescr->m_msg_value_block_offset);
  assert((pMsgDescr->m_msg_value_block_offset+pMsgDescr->m_msg_value_block_size)<=pMsgDescr->m_msg_sqlind_offset);

  try
  {
   Helper__Parse_XSQLDA_MSG_DATA
    (*pMsgDescr,
     cbMsgData,
     pMsgData,
     pXVar);
  }
  catch(const std::exception& e)
  {
   assert(pXVar>=pXSQLDA->sqlvar);

   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_isc__failed_to_parse_element_of_msg_buf_with_data_1,
     (pXVar-pXSQLDA->sqlvar));
  }//catch

 #ifndef NDEBUG
  debug__offset =pMsgDescr->m_msg_sqlind_offset;
  debug__offset+=sizeof(db_obj::t_dbvalue__i2);
 #endif
 }//for pXVar

 assert(debug__offset==cbMsgData);
}//Parse_XSQLDA_MSG_DATA

//------------------------------------------------------------------------
void RemoteFB__P12__XSQLDA_Utilities::Helper__Parse_XSQLDA_MSG_DATA
                                           (const msg_data_descr_type&       MsgDescr,
                                            size_t                     const DEBUG_CODE(cbMsgData),
                                            const byte_type*           const pMsgData,
                                            const isc_api::XSQLVAR_V1* const pXSQLVAR)
{
 CHECK_READ_PTR(pMsgData,cbMsgData);

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12__XSQLDA_Utilities::Helper__Parse_XSQLDA_MSG_DATA";

 //предварительная проверка на согласованность состояния
 assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
 assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));
 assert(MsgDescr.m_msg_sqlind_offset<cbMsgData);

 //-----------------------------------------
 const isc_api::XSQLVAR_V1::sqltype_type xvar_sqltype=pXSQLVAR->get_typeID();

 if(xvar_sqltype!=MsgDescr.m_xvar_sqltype)
 {
  //ERROR - рассогласование типов в XSQLVAR и MSG-буфере

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__bug_check__other_sqltype_of_xvar_2,
    xvar_sqltype,
    MsgDescr.m_xvar_sqltype);
 }//if

 //----------------------------------------- Читаем индикатор состояния данных
 assert(sizeof(protocol::P_SHORT)<=(cbMsgData-MsgDescr.m_msg_sqlind_offset));

 assert((MsgDescr.m_msg_sqlind_offset%isc_api::ibp_isc_type_align__short)==0);
 assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_sqlind_offset)%isc_api::ibp_isc_type_align__short)==0);

 bool IsNull=false;

 switch(const protocol::P_SHORT xsqvarIndicator
         =(*reinterpret_cast<const protocol::P_SHORT*>(pMsgData+MsgDescr.m_msg_sqlind_offset)))
 {
  case 0:
   break;

  case -1:
   IsNull=true;
   break;

  default:
  {
   assert_msg(false,"xsqvarIndicator: "<<xsqvarIndicator);

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_isc__bug_check__unknown_value_of_xsqlvar_indicator_3,
     c_bugcheck_src,
     L"#001",
     xsqvarIndicator);
  }//default
 }//switch xsqvarIndicator

 if(IsNull)
 {
  if(!pXSQLVAR->get_value_may_be_null())
  {
   //ERROR - XSQLVAR не поддерживает NULL-значения

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_isc__bug_check__xvar_not_supports_the_storing_of_null_state_of_value_1,
     pXSQLVAR->sqltype);
  }//if

  if(pXSQLVAR->sqlind==nullptr)
  {
   //ERROR - нулевой указатель на индикатор NULL-значения

   helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
    (pXSQLVAR->sqltype);
  }//if

  //у нас pXSQLVAR - указатель на константу
  // поэтому вызывать set_value_null_state__std не получается ...

  (*pXSQLVAR->sqlind)=-1;
 }
 else
 {
  assert(!IsNull);

  if(pXSQLVAR->get_value_may_be_null())
  {
   if(pXSQLVAR->sqlind==nullptr)
   {
    //ERROR - нулевой указатель на индикатор NULL-значения

    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
     (pXSQLVAR->sqltype);
   }//if

   //у нас pXSQLVAR - указатель на константу
   // поэтому вызывать set_value_null_state__std не получается ...

   (*pXSQLVAR->sqlind)=0;
  }//if
 }//else

 switch(xvar_sqltype)
 {
  case isc_api::ibp_isc_sql_varying:
  {
   if(!structure::can_numeric_cast<size_t>(pXSQLVAR->sqllen))
   {
    assert(pXSQLVAR->sqllen<0);

    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_varying",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   assert(MsgDescr.m_msg_value_block_size>=sizeof(isc_api::isc_varchar_size_type));

   const size_t c_expected_sqllen
    =MsgDescr.m_msg_value_block_size-sizeof(isc_api::isc_varchar_size_type);

   if(xvar_sqllen!=c_expected_sqllen)
   {
    //ERROR - рассогласование размера буферов XSQLVAR и MSG-буфере

    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlLen
     (L"sql_varying",
      xvar_sqllen,
      c_expected_sqllen);
   }//if

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);

   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%isc_api::ibp_isc_type_align__varying)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%isc_api::ibp_isc_type_align__varying)==0);

   //---------------------------------------
   CHECK_WRITE_PTR(pXSQLVAR->sqldata,xvar_sqllen);

   if(IsNull)
   {
    (*reinterpret_cast<isc_api::isc_varchar_size_type*>(pXSQLVAR->sqldata))
     =0;

    memset(const_cast<char*>(pXSQLVAR->sqldata)+sizeof(isc_api::isc_varchar_size_type),
           0,
           xvar_sqllen);
   }
   else
   {
    const isc_api::isc_varchar_size_type varchar_length
     =*reinterpret_cast<const isc_api::isc_varchar_size_type*>(pMsgData+MsgDescr.m_msg_value_block_offset);

    if(!structure::can_numeric_cast<size_t>(varchar_length))
    {
     //ERROR - incorrect varchar length

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__bug_check__incorrect_varchar_data_length_1,
       varchar_length);
    }//if

    if(c_expected_sqllen<static_cast<size_t>(varchar_length))
    {
     //ERROR - incorrect varchar length

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__bug_check__varchar_data_length_is_greater_than_buffer_size_2,
       varchar_length,
       c_expected_sqllen);
    }//if

    assert(static_cast<size_t>(varchar_length)<=xvar_sqllen);

    (*reinterpret_cast<isc_api::isc_varchar_size_type*>(pXSQLVAR->sqldata))
     =varchar_length;

    memcpy(const_cast<char*>(pXSQLVAR->sqldata)+sizeof(isc_api::isc_varchar_size_type),
           pMsgData+MsgDescr.m_msg_value_block_offset+sizeof(isc_api::isc_varchar_size_type),
           varchar_length);

    memset(const_cast<char*>(pXSQLVAR->sqldata)+sizeof(isc_api::isc_varchar_size_type)+varchar_length,
           0,
           xvar_sqllen-varchar_length);
   }//else

   break;
  }//ibp_isc_sql_varying

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_text:
  {
   if(!structure::can_numeric_cast<size_t>(pXSQLVAR->sqllen))
   {
    assert(pXSQLVAR->sqllen<0);

    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_text",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   if(xvar_sqllen!=MsgDescr.m_msg_value_block_size)
   {
    //ERROR - рассогласование размера буферов XSQLVAR и MSG-буфере

    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlLen
     (L"sql_text",
      xvar_sqllen,
      MsgDescr.m_msg_value_block_size);
   }//if

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);

   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   //---------------------------------------
   CHECK_WRITE_PTR(pXSQLVAR->sqldata,xvar_sqllen);

   assert(xvar_sqllen==MsgDescr.m_msg_value_block_size);

   if(IsNull)
   {
    memset(pXSQLVAR->sqldata,0,xvar_sqllen);
   }
   else
   {
    memcpy(pXSQLVAR->sqldata,pMsgData+MsgDescr.m_msg_value_block_offset,xvar_sqllen);
   }//else

   break;
  }//ibp_isc_sql_text

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_short:
  {
   typedef protocol::P_SHORT value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__short;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_short",
      pXSQLVAR->sqllen);
   }//if

   if(pXSQLVAR->sqlscale!=MsgDescr.m_xvar_sqlscale)
   {
    //ERROR - рассогласование масштабов в XSQLVAR и MSG-буфере

    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
     (L"sql_short",
      pXSQLVAR->sqlscale,
      MsgDescr.m_xvar_sqlscale);
   }//if

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=0;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_short

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_long:
  {
   typedef protocol::P_LONG value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__long;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_long",
      pXSQLVAR->sqllen);
   }//if

   if(pXSQLVAR->sqlscale!=MsgDescr.m_xvar_sqlscale)
   {
    //ERROR - рассогласование масштабов в XSQLVAR и MSG-буфере

    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
     (L"sql_long",
      pXSQLVAR->sqlscale,
      MsgDescr.m_xvar_sqlscale);
   }//if

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=0;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_long

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_int64:
  {
   typedef protocol::P_INT64 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__int64;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_int64",
      pXSQLVAR->sqllen);
   }//if

   if(pXSQLVAR->sqlscale!=MsgDescr.m_xvar_sqlscale)
   {
    //ERROR - рассогласование масштабов в XSQLVAR и MSG-буфере

    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
     (L"sql_int64",
      pXSQLVAR->sqlscale,
      MsgDescr.m_xvar_sqlscale);
   }//if

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=0;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_int64

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_array:
  {
   typedef protocol::P_BID value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__quad;
#endif

   //---------------------------------------
   assert_s(sizeof(db_obj::DB_IBARRAYID)==sizeof(protocol::P_BID));

   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_array",
      pXSQLVAR->sqllen);
   }//if

   //изменения масштаба нас не волнуют

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=protocol::__null_bid;
   }
   else
   {
    //копирование P_BID в DB_IBARRAYID

    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_array

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_blob:
  {
   typedef protocol::P_BID value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__quad;
#endif

   //---------------------------------------
   assert_s(sizeof(db_obj::DB_IBBLOBID)==sizeof(protocol::P_BID));

   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_blob",
      pXSQLVAR->sqllen);
   }//if

   //изменения масштаба нас не волнуют

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=protocol::__null_bid;
   }
   else
   {
    //копирование P_BID в DB_IBBLOBID

    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_blob

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_float:
  {
   typedef protocol::P_FLOAT value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__float;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_float",
      pXSQLVAR->sqllen);
   }//if

   //изменения масштаба нас не волнуют

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=0;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_float

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_double:
  {
   typedef protocol::P_DOUBLE value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__double;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_double",
      pXSQLVAR->sqllen);
   }//if

   //изменения масштаба нас не волнуют

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=0;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_double

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_type_time:
  {
   typedef isc_api::t_ibp_isc_time value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__time;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_time",
      pXSQLVAR->sqllen);
   }//if

   //изменения масштаба нас не волнуют

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=0;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_type_time

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_type_date:
  {
   typedef isc_api::t_ibp_isc_date value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__date;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_date",
      pXSQLVAR->sqllen);
   }//if

   //изменения масштаба нас не волнуют

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=0;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_type_date

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_timestamp:
  {
   typedef isc_api::t_ibp_isc_timestamp value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__timestamp;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_timestamp",
      pXSQLVAR->sqllen);
   }//if

   //изменения масштаба нас не волнуют

   //---------------------------------------
   assert(MsgDescr.m_msg_value_block_size==sizeof(value_type));

   assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
   assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));

   assert((MsgDescr.m_msg_value_block_offset%c_align)==0);

   assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_value_block_offset)%c_align)==0);

   //---------------------------------------
   assert(pXSQLVAR->sqldata!=nullptr);

   CHECK_WRITE_PTR(pXSQLVAR->sqldata,sizeof(value_type));

   if(IsNull)
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=isc_api::__null__isc_timestamp;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
     =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_timestamp

  //------------------------------------------------------------
  default:
  {
   //ERROR - [BUG CHECK] unexpected sqltypeID

   assert_msg(false,"sqltype: "<<pXSQLVAR->sqltype);

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_isc__bug_check__unknown_sqltype_in_xvar_1,
     pXSQLVAR->sqltype);
  }//default
 }//switch
}//Helper__Parse_XSQLDA_MSG_DATA

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
