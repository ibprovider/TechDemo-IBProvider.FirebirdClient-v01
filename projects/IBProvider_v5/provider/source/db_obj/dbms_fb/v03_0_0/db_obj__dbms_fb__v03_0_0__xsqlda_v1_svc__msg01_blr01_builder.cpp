////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg01_blr01_builder.cpp
//! \brief   XSQLDA_V1 service for building MSG BLR01 [V01].
//! \author  Kovalenko Dmitry
//! \date    22.08.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg01_blr01_builder.h"
#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__factories.h"
#include "source/db_obj/isc_base/helpers/xsqlda/isc_api_hlp__xsqlda__error_utils.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_object_ptr create_xsqlda_v1_svc__msg01_blr01_builder()
{
 return fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::create();
}//create_xsqlda_v1_svc__msg01_blr01_builder

////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder

fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder
 fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::sm_Instance;

//------------------------------------------------------------------------
fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder()
{
}//fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder

//------------------------------------------------------------------------
fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::~fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder()
{
}//~fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder

//------------------------------------------------------------------------
db_obj::t_db_object_ptr
 fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::create()
{
 return lib::structure::not_null_ptr(&sm_Instance);
}//create

//t_isc_xsqlda_v1_svc__msg01_blr01_builder interface ---------------------------
void fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::Build_XSQLDA_MSG_BLR
                             (const isc_api::XSQLDA_V1* const pXSQLDA,
                              msg_blr_buffer_type&            BlrBuffer)
{
 if(pXSQLDA==nullptr)
 {
  BlrBuffer.alloc(0);
  return;
 }//if

 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 if(pXSQLDA->sqld==0)
 {
  BlrBuffer.alloc(0);
  return;
 }//if

 BlrBuffer.alloc(Helper__Build_XSQLDA_MSG_BLR__CalcBufSize(pXSQLDA));

 Helper__Build_XSQLDA_MSG_BLR__FillBuf(pXSQLDA,BlrBuffer);
}//Build_XSQLDA_MSG_BLR

//------------------------------------------------------------------------
size_t fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::Helper__Build_XSQLDA_MSG_BLR__CalcBufSize
                                           (const isc_api::XSQLDA_V1* const pXSQLDA)
{
 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 //-----------------------------------------
 //вычисл€ем размер буфера под BLR

 // blr_version5         // 1
 // blr_begin            // 2
 // blr_message          // 3
 // 0                    // 4
 // par_count [2 bytes]  // 5 6
 // ...                  //
 // blr_end              // 7
 // blr_eoc              // 8

 size_t szBlr=8;

 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 for(;pXVar!=_eXVar;++pXVar)
 {
  switch(pXVar->get_typeID())
  {
   // {byte_with_data_type,word_with_data_size}+{byte_with_ind_type,byte_with_ind_scale}
   case isc_api::ibp_isc_sql_varying:
   case isc_api::ibp_isc_sql_text:
   case isc_api::ibp_fb025_sql_null:
    szBlr+=3+2;
    break;

   // {byte_with_data_type,byte_with_data_scale}+{byte_with_ind_type,byte_with_ind_scale}
   case isc_api::ibp_isc_sql_short:
   case isc_api::ibp_isc_sql_long:
   case isc_api::ibp_isc_sql_int64:
   case isc_api::ibp_isc_sql_blob:
   case isc_api::ibp_isc_sql_array:
    szBlr+=2+2;
    break;

   // {byte_with_data_type}+{byte_with_ind_type,byte_with_ind_scale}
   case isc_api::ibp_isc_sql_float:
   case isc_api::ibp_isc_sql_double:
   case isc_api::ibp_isc_sql_type_time:
   case isc_api::ibp_isc_sql_type_date:
   case isc_api::ibp_isc_sql_timestamp:
   case isc_api::ibp_fb030_sql_boolean:
    szBlr+=1+2;
    break;

   default:
   {
    //ERROR - unexpected sqltypeID

    IBP_ErrorUtils::Throw__Error
     (DB_E_NOTSUPPORTED,
      ibp_subsystem__isc_api__fb3_0,
      ibp_mce_dbobj__ie_data_with_unk_sql_type_2,
      (pXVar-pXSQLDA->sqlvar),
      pXVar->sqltype);
   }//default
  }//switch
 }//for pXVar

 return szBlr;
}//Helper__Build_XSQLDA_MSG_BLR__CalcBufSize

//------------------------------------------------------------------------
void fb_v03_0_0__xsqlda_v1_svc__msg01_blr01_builder::Helper__Build_XSQLDA_MSG_BLR__FillBuf
                                           (const isc_api::XSQLDA_V1* const pXSQLDA,
                                            msg_blr_buffer_type&            BlrBuffer)
{
 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 using byte_type=msg_blr_buffer_type::value_type;

 assert_s(sizeof(byte_type)==1);

 const size_t cPars=2*static_cast<size_t>(pXSQLDA->sqld);

 assert(structure::can_numeric_cast<unsigned __int16>(cPars));

 byte_type*              p=BlrBuffer.buffer();
#ifndef NDEBUG
 const byte_type* const _e=BlrBuffer.buffer_end();
#endif

#define PUSH_STUFF(v)                                                   \
 {                                                                      \
  assert(p<_e);                                                         \
  (*p)=static_cast<byte_type>(v);                                       \
  ++p;                                                                  \
 }

#define PUSH_STUFF_BYTE(v)                                              \
 {                                                                      \
  assert(structure::can_numeric_cast<byte_type>((long)v));              \
  PUSH_STUFF(v);                                                        \
 }

#define PUSH_STUFF_WORD(v)                                              \
 {                                                                      \
  assert(structure::can_numeric_cast<unsigned __int16>(v));             \
  PUSH_STUFF(v&255);                                                    \
  PUSH_STUFF((v>>8)&255);                                               \
 }

 //---------------------------------------
 PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_version5);     // 1
 PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_begin);        // 2
 PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_message);      // 3
 PUSH_STUFF_BYTE(0);  //message number?              // 4
 PUSH_STUFF_WORD(cPars);                             // 5 6

 //---------------------------------------
 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 for(;pXVar!=_eXVar;++pXVar)
 {
  try
  {
   const auto xvar_sqllen=pXVar->sqllen;

   switch(pXVar->get_typeID())
   {
    case isc_api::ibp_isc_sql_varying:
    {
     if(!structure::can_numeric_cast<size_t>(xvar_sqllen))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      assert(pXVar->sqllen<0);

      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_varying",
        xvar_sqllen);
     }//if

     assert(xvar_sqllen==0 || xvar_sqllen>0);

     if(isc_api::ibp_isc_max_varchar_length<xvar_sqllen)
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_varying",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__varying)
     PUSH_STUFF_WORD(xvar_sqllen)
     break;
    }//ibp_isc_sql_varying

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_text:
    {
     if(!structure::can_numeric_cast<size_t>(xvar_sqllen))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      assert(pXVar->sqllen<0);

      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_text",
        xvar_sqllen);
     }//if

     assert(xvar_sqllen==0 || xvar_sqllen>0);

     if(isc_api::ibp_isc_max_char_length<xvar_sqllen)
     {
      //ERROR - [BUG CHECK] incorrect xvar length;

      //[2015-05-13] максимальное значение XSQLVAR::sqllen совпадает с ibp_isc_max_char_length
      assert(false);

      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_text",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__text)
     PUSH_STUFF_WORD(xvar_sqllen)
     break;
    }//ibp_isc_sql_text

    //-------------------------------------------------------------------
    case isc_api::ibp_fb025_sql_null:
    {
     if(xvar_sqllen!=0)
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_null",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__text)
     PUSH_STUFF_WORD(0)
     break;
    }//ibp_fb025_sql_null

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_short:
    {
     if(xvar_sqllen!=sizeof(db_obj::t_dbvalue__i2))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_short",
        xvar_sqllen);
     }//if

     if(pXVar->sqlscale>0 || pXVar->sqlscale<-db_obj::dbprecision__isc_numeric_on_smallint)
     {
      //ERROR - incorrect sqlscale of xvar
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlScale
       (L"sql_short",
        pXVar->sqlscale);
     }//if

     assert(structure::can_numeric_cast<signed __int8>(pXVar->sqlscale));

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__short)
     PUSH_STUFF(pXVar->sqlscale)
     break;
    }//ibp_isc_sql_short

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_long:
    {
     if(xvar_sqllen!=sizeof(db_obj::t_dbvalue__i4))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_long",
        xvar_sqllen);
     }//if

     if(pXVar->sqlscale>0 || pXVar->sqlscale<-db_obj::dbprecision__isc_numeric_on_integer)
     {
      //ERROR - incorrect sqlscale of xvar
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlScale
       (L"sql_long",
        pXVar->sqlscale);
     }//if

     assert(structure::can_numeric_cast<signed __int8>(pXVar->sqlscale));

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__long)
     PUSH_STUFF(pXVar->sqlscale)
     break;
    }//ibp_isc_sql_long

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_int64:
    {
     if(xvar_sqllen!=sizeof(db_obj::t_dbvalue__i8))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_int64",
        xvar_sqllen);
     }//if

     if(pXVar->sqlscale>0 || pXVar->sqlscale<-db_obj::dbprecision__isc_numeric_on_int64)
     {
      //ERROR - incorrect sqlscale of xvar
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlScale
       (L"sql_int64",
        pXVar->sqlscale);
     }//if

     assert(structure::can_numeric_cast<signed __int8>(pXVar->sqlscale));

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__int64)
     PUSH_STUFF(pXVar->sqlscale)
     break;
    }//ibp_isc_sql_int64

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_blob:
    {
     if(xvar_sqllen!=sizeof(db_obj::DB_IBBLOBID))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_blob",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__quad)
     PUSH_STUFF_BYTE(0) //scale
     break;
    }//ibp_isc_sql_blob

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_array:
    {
     if(xvar_sqllen!=sizeof(db_obj::DB_IBARRAYID))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_array",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__quad)
     PUSH_STUFF_BYTE(0) //scale
     break;
    }//ibp_isc_sql_array

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_float:
    {
     if(xvar_sqllen!=sizeof(db_obj::t_dbvalue__r4))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_float",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__float)
     break;
    }//ibp_isc_sql_float

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_double:
    {
     if(xvar_sqllen!=sizeof(db_obj::t_dbvalue__r8))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_double",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__double)
     break;
    }//ibp_isc_sql_double

    //-------------------------------------------------------------------
    case isc_api::ibp_isc_sql_type_time:
    {
     if(xvar_sqllen!=sizeof(isc_api::t_ibp_isc_time))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_type_time",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__sql_time)
     break;
    }//ibp_isc_sql_type_time

    case isc_api::ibp_isc_sql_type_date:
    {
     if(xvar_sqllen!=sizeof(isc_api::t_ibp_isc_date))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_type_date",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__sql_date)
     break;
    }//ibp_isc_sql_type_date

    case isc_api::ibp_isc_sql_timestamp:
    {
     if(xvar_sqllen!=sizeof(isc_api::t_ibp_isc_timestamp))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_timestamp",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__timestamp)
     break;
    }//ibp_isc_sql_timestamp

    //-------------------------------------------------------------------
    case isc_api::ibp_fb030_sql_boolean:
    {
     if(xvar_sqllen!=sizeof(isc_api::t_ibp_fb030_bool))
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"sql_boolean",
        xvar_sqllen);
     }//if

     PUSH_STUFF_BYTE(isc_api::ibp_fb030_blr_dtype__bool)
     break;
    }//ibp_fb030_sql_boolean

    //-------------------------------------------------------------------
    default:
    {
     //ERROR - [BUG CHECK] unknown xvar sqltype;

     //[2015-05-13]
     // ћы не должны сюда попадать в принципе.
     // Ќеизвестные типы данных отлавливаютс€ на уровне Helper__Build_XSQLDA_BLR__CalcBufSize
     assert(false);

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__bug_check__unknown_sqltype_in_xvar_1,
       pXVar->sqltype);
    }//default
   }//switch

   //null flag
   PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_dtype__short)
   PUSH_STUFF(0) //scale
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__isc_api__fb3_0,
     ibp_mce_isc__failed_to_process_the_xsqlvar_1,
     pXVar-pXSQLDA->sqlvar);
  }//catch
 }//for pXVar

 PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_end)
 PUSH_STUFF_BYTE(isc_api::ibp_isc_blr_eoc)

#undef PUSH_STUFF_WORD
#undef PUSH_STUFF_BYTE
#undef PUSH_STUFF

 assert(p==BlrBuffer.buffer_end());
}//Helper__Build_XSQLDA_MSG_BLR__FillBuf

////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
