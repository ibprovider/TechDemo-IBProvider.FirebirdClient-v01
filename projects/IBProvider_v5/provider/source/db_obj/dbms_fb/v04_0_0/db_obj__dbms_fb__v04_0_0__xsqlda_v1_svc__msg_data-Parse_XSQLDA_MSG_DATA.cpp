////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v04_0_0
//! \file    db_obj__dbms_fb__v04_0_0__xsqlda_v1_svc__msg_data-Parse_XSQLDA_MSG_DATA.cpp
//! \brief   XSQLDA_V1 service for working with message data.
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v04_0_0/db_obj__dbms_fb__v04_0_0__xsqlda_v1_svc__msg_data.h"
#include "source/db_obj/isc_base/helpers/xsqlda/isc_api_hlp__xsqlda__error_utils.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v04_0_0{
////////////////////////////////////////////////////////////////////////////////
//class fb_v04_0_0__xsqlda_v1_svc__msg_data

void fb_v04_0_0__xsqlda_v1_svc__msg_data::Parse_XSQLDA_MSG_DATA
                                           (const msg_data_descrs_type&     MsgDescrs,
                                            size_t                    const cbMsgData,
                                            const void*               const pMsgData,
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
  //ERROR - ���������������� ��������� pXSQLDA � MSG-������. ������ ���������� ���������.

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__isc_api__fb4_0,
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
     ibp_subsystem__isc_api__fb4_0,
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
void fb_v04_0_0__xsqlda_v1_svc__msg_data::Helper__Parse_XSQLDA_MSG_DATA
                                           (const msg_data_descr_type&       MsgDescr,
                                            size_t                     const DEBUG_CODE(cbMsgData),
                                            const void*                const pvMsgData,
                                            const isc_api::XSQLVAR_V1* const pXSQLVAR)
{
 CHECK_READ_PTR(pvMsgData,cbMsgData);

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__Parse_XSQLDA_MSG_DATA";

 //��������������� �������� �� ��������������� ���������
 assert(MsgDescr.m_msg_value_block_offset<=cbMsgData);
 assert(MsgDescr.m_msg_value_block_size<=(cbMsgData-MsgDescr.m_msg_value_block_offset));
 assert(MsgDescr.m_msg_sqlind_offset<cbMsgData);

 //-----------------------------------------
 const isc_api::XSQLVAR_V1::sqltype_type xvar_sqltype=pXSQLVAR->get_typeID();

 if(xvar_sqltype!=MsgDescr.m_xvar_sqltype)
 {
  //ERROR - ��������������� ����� � XSQLVAR � MSG-������

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__bug_check__other_sqltype_of_xvar_2,
    xvar_sqltype,
    MsgDescr.m_xvar_sqltype);
 }//if

 //-----------------------------------------
 const auto* const pMsgData=reinterpret_cast<const unsigned char*>(pvMsgData);

 assert_s(sizeof(*pMsgData)==1);

 //----------------------------------------- ������ ��������� ��������� ������
 assert(sizeof(db_obj::t_dbvalue__i2)<=(cbMsgData-MsgDescr.m_msg_sqlind_offset));

 assert((MsgDescr.m_msg_sqlind_offset%isc_api::ibp_isc_type_align__short)==0);
 assert((reinterpret_cast<size_t>(pMsgData+MsgDescr.m_msg_sqlind_offset)%isc_api::ibp_isc_type_align__short)==0);

 bool IsNull=false;

 switch(const db_obj::t_dbvalue__i2 xsqvarIndicator
         =(*reinterpret_cast<const db_obj::t_dbvalue__i2*>(pMsgData+MsgDescr.m_msg_sqlind_offset)))
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
   //ERROR - XSQLVAR �� ������������ NULL-��������

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_isc__bug_check__xvar_not_supports_the_storing_of_null_state_of_value_1,
     pXSQLVAR->sqltype);
  }//if

  if(pXSQLVAR->sqlind==nullptr)
  {
   //ERROR - ������� ��������� �� ��������� NULL-��������

   isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
    (pXSQLVAR->sqltype);
  }//if

  //� ��� pXSQLVAR - ��������� �� ���������
  // ������� �������� set_value_null_state__std �� ���������� ...

  (*pXSQLVAR->sqlind)=-1;
 }
 else
 {
  assert(!IsNull);

  if(pXSQLVAR->get_value_may_be_null())
  {
   if(pXSQLVAR->sqlind==nullptr)
   {
    //ERROR - ������� ��������� �� ��������� NULL-��������

    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
     (pXSQLVAR->sqltype);
   }//if

   //� ��� pXSQLVAR - ��������� �� ���������
   // ������� �������� set_value_null_state__std �� ���������� ...

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
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_varying",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   assert(MsgDescr.m_msg_value_block_size>=sizeof(isc_api::isc_varchar_size_type));

   const size_t c_expected_sqllen
    =MsgDescr.m_msg_value_block_size-sizeof(isc_api::isc_varchar_size_type);

   if(xvar_sqllen!=c_expected_sqllen)
   {
    //ERROR - ��������������� ������� ������� XSQLVAR � MSG-������

    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlLen
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
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_text",
      pXSQLVAR->sqllen);
   }//if

   const size_t xvar_sqllen=static_cast<size_t>(pXSQLVAR->sqllen);

   if(xvar_sqllen!=MsgDescr.m_msg_value_block_size)
   {
    //ERROR - ��������������� ������� ������� XSQLVAR � MSG-������

    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlLen
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
   typedef db_obj::t_dbvalue__i2 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__short;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_short",
      pXSQLVAR->sqllen);
   }//if

   if(pXSQLVAR->sqlscale!=MsgDescr.m_xvar_sqlscale)
   {
    //ERROR - ��������������� ��������� � XSQLVAR � MSG-������

    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
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
   typedef db_obj::t_dbvalue__i4 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__long;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_long",
      pXSQLVAR->sqllen);
   }//if

   if(pXSQLVAR->sqlscale!=MsgDescr.m_xvar_sqlscale)
   {
    //ERROR - ��������������� ��������� � XSQLVAR � MSG-������

    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
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
   typedef db_obj::t_dbvalue__i8 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__int64;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_int64",
      pXSQLVAR->sqllen);
   }//if

   if(pXSQLVAR->sqlscale!=MsgDescr.m_xvar_sqlscale)
   {
    //ERROR - ��������������� ��������� � XSQLVAR � MSG-������

    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
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
   typedef db_obj::DB_IBARRAYID value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__quad;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_array",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=db_obj::__null_ib_array_id;
   }
   else
   {
    //����������� P_BID � DB_IBARRAYID

    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_array

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_blob:
  {
   typedef db_obj::DB_IBBLOBID value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__quad;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_blob",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))=db_obj::__null_ib_blob_id;
   }
   else
   {
    //����������� P_BID � DB_IBBLOBID

    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_isc_sql_blob

  //------------------------------------------------------------
  case isc_api::ibp_isc_sql_float:
  {
   typedef db_obj::t_dbvalue__r4 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__float;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_float",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
   typedef db_obj::t_dbvalue__r8 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_isc_type_align__double;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_double",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_time",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_type_date",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_timestamp",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
  case isc_api::ibp_fb030_sql_boolean:
  {
   typedef isc_api::t_ibp_fb030_bool value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_fb030_type_align__bool;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_boolean",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
  }//ibp_fb030_sql_boolean

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_int128:
  {
   typedef isc_api::t_ibp_fb040_int128 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_fb040_type_align__int128;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_int128",
      pXSQLVAR->sqllen);
   }//if

   assert_hint(pXSQLVAR->sqllen==sizeof(value_type));

   if(pXSQLVAR->sqlscale!=MsgDescr.m_xvar_sqlscale)
   {
    //ERROR - ��������������� ��������� � XSQLVAR � MSG-������

    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
     (L"sql_int128",
      pXSQLVAR->sqlscale,
      MsgDescr.m_xvar_sqlscale);
   }//if

   assert_hint(pXSQLVAR->sqlscale==MsgDescr.m_xvar_sqlscale);

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
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =isc_api::__null__fb040_int128;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_fb040_sql_int128

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_decfloat16:
  {
   typedef isc_api::t_ibp_fb040_decfloat16 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_fb040_type_align__decfloat16;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_decfloat16",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =isc_api::__null__fb040_decfloat16;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_fb040_sql_decfloat16

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_decfloat34:
  {
   typedef isc_api::t_ibp_fb040_decfloat34 value_type;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_fb040_type_align__decfloat34;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_decfloat34",
      pXSQLVAR->sqllen);
   }//if

   //��������� �������� ��� �� �������

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
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =isc_api::__null__fb040_decfloat34;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_fb040_sql_decfloat34

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_timestamp_with_tz:
  {
   using value_type=isc_api::t_ibp_fb040_timestamp_with_tz;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_fb040_type_align__timestamp_with_tz;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_timestamp_with_tz",
      pXSQLVAR->sqllen);
   }//if

   //the change of scale does not matter

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
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =isc_api::__null__fb040_timestamp_with_tz;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_fb040_sql_timestamp_with_tz

  //------------------------------------------------------------
  case isc_api::ibp_fb040_sql_time_with_tz:
  {
   using value_type=isc_api::t_ibp_fb040_time_with_tz;

#ifndef NDEBUG
   const size_t c_align=isc_api::ibp_fb040_type_align__time_with_tz;
#endif

   //---------------------------------------
   if(pXSQLVAR->sqllen!=sizeof(value_type))
   {
    //ERROR - incorrect xvar sqllength
    isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
     (L"sql_time_with_tz",
      pXSQLVAR->sqllen);
   }//if

   //the change of scale does not matter

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
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =isc_api::__null__fb040_time_with_tz;
   }
   else
   {
    (*reinterpret_cast<value_type*>(pXSQLVAR->sqldata))
      =(*reinterpret_cast<const value_type*>(pMsgData+MsgDescr.m_msg_value_block_offset));
   }//else

   break;
  }//ibp_fb040_sql_time_with_tz

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
}/*nms v04_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
