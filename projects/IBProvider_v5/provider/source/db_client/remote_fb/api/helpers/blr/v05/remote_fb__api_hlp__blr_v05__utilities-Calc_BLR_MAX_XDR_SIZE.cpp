////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__blr_v05__utilities-Calc_BLR_MAX_XDR_SIZE.cpp
//! \brief   Utilities for work with BLR (v05).
//! \author  Kovalenko Dmitry
//! \date    18.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/blr/v05/remote_fb__api_hlp__blr_v05__utilities.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__info.h"
#include "source/db_client/remote_fb/remote_fb__blr_reader_v1.h"
#include "source/db_obj/isc_base/helpers/xsqlda/isc_api_hlp__xsqlda__error_utils.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/ibp_memory_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__BLR_V05__Utilities

size_t RemoteFB__API_HLP__BLR_V05__Utilities::Calc_BLR_MAX_XDR_SIZE
                                           (const IBP_BufferView<const byte_type>& blr)
{
 if(blr.empty())
  return 0;

 //-----------------------------------------------------------------------
 typedef transmission::RemoteFB__XDR__Info xdr;

 RemoteFB__BlrReader_v1 blr_reader(blr.size(),blr.data());

 //-----------------------------------------------------------------------
 #define MSG_BLR__SKIP_BYTE(value)                    \
 {                                                    \
  assert(blr_reader.cur()==(value));                  \
  blr_reader.next();                                  \
 }

 #define MSG_BLR__SKIP_TAG(tag)                       \
  MSG_BLR__SKIP_BYTE(isc_api::ibp_isc_blr_##tag)

 //-----------------------------------------------------------------------
 MSG_BLR__SKIP_TAG(version5);
 MSG_BLR__SKIP_TAG(begin);
 MSG_BLR__SKIP_TAG(message);
 MSG_BLR__SKIP_BYTE(0)  //message number?

 const size_t cPars=blr_reader.read_word();

 assert((cPars%2)==0);

 size_t cbResult=0;

 for(size_t iElement=0;iElement!=cPars;++iElement)
 {
  try
  {
   size_t currentElementSize=0;

   switch(const protocol::P_UCHAR typeID=blr_reader.read())
   {
    case isc_api::ibp_isc_blr_dtype__varying:
    {
     const size_t sqllen=blr_reader.read_word();

     //----
     if(isc_api::ibp_isc_max_varchar_length<sqllen)
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"isc_blr_dtype__varying",
        sqllen);
     }//if

     //----
     currentElementSize =xdr::get_size__p_short(); //throw

     currentElementSize+=xdr::get_size__opaque(sqllen); //throw

     break;
    }//ibp_isc_blr_dtype__varying

    case isc_api::ibp_isc_blr_dtype__text:
    {
     const size_t sqllen=blr_reader.read_word();

     //----
     if(isc_api::ibp_isc_max_char_length<sqllen)
     {
      //ERROR - [BUG CHECK] incorrect xvar length;
      isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
       (L"isc_blr_dtype__text",
        sqllen);
     }//if

     //----
     currentElementSize=xdr::get_size__opaque(sqllen); //throw

     break;
    }//case ibp_isc_blr_dtype__text

    case isc_api::ibp_isc_blr_dtype__short:
    {
#ifndef NDEBUG
     signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

     assert(s==0 || s<0);
     assert(s>=-db_obj::dbprecision__isc_numeric_on_smallint);
#endif

     //----
     blr_reader.next(); //sqlscale

     //----
     currentElementSize=xdr::get_size__p_short();

     break;
    }//ibp_isc_blr_dtype__short

    case isc_api::ibp_isc_blr_dtype__long:
    {
#ifndef NDEBUG
     signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

     assert(s==0 || s<0);
     assert(s>=-db_obj::dbprecision__isc_numeric_on_integer);
#endif

     //----
     blr_reader.next(); //sqlscale

     //----
     currentElementSize=xdr::get_size__p_long();

     break;
    }//ibp_isc_blr_dtype__long

    case isc_api::ibp_isc_blr_dtype__int64:
    {
#ifndef NDEBUG
     signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

     assert(s==0 || s<0);
     assert(s>=-db_obj::dbprecision__isc_numeric_on_int64);
#endif

     //----
     blr_reader.next(); //sqlscale

     //----
     currentElementSize=xdr::get_size__p_int64();

     break;
    }//ibp_isc_blr_dtype__int64

    case isc_api::ibp_isc_blr_dtype__float:
    {
     currentElementSize=xdr::get_size__p_float();

     break;
    }//ibp_isc_blr_dtype__float

    case isc_api::ibp_isc_blr_dtype__double:
    {
     currentElementSize=xdr::get_size__p_double();

     break;
    }//ibp_isc_blr_dtype__double

    case isc_api::ibp_isc_blr_dtype__sql_time:
    {
     currentElementSize=xdr::get_size__p_ulong_as_p_long();

     break;
    }//ibp_isc_blr_dtype__sql_time

    case isc_api::ibp_isc_blr_dtype__sql_date:
    {
     currentElementSize=xdr::get_size__p_long();

     break;
    }//ibp_isc_blr_dtype__sql_date

    case isc_api::ibp_isc_blr_dtype__timestamp:
    {
     currentElementSize=xdr::get_size__p_long();

     currentElementSize+=xdr::get_size__p_ulong_as_p_long();

     break;
    }//ibp_isc_blr_dtype__timestamp

    case isc_api::ibp_isc_blr_dtype__quad:
    {
     blr_reader.next(); //sqlscale

     //----
     currentElementSize=xdr::get_size__p_bid();

     break;
    }//ibp_isc_blr_dtype__quad

    case isc_api::ibp_fb030_blr_dtype__bool:
    {
     currentElementSize=xdr::get_size__opaque(sizeof(isc_api::t_ibp_fb030_bool));

     break;
    }//ibp_fb030_blr_dtype__bool

    case isc_api::ibp_fb040_blr_dtype__int128:
    {
#ifndef NDEBUG
     signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

     assert(s==0 || s<0);
     assert(s>=-db_obj::dbprecision__fb040_numeric_on_int128);
#endif

     //----
     blr_reader.next(); //sqlscale [throw]

     //----
     currentElementSize=xdr::get_size__p_int128();

     assert(currentElementSize==sizeof(protocol::P_INT128));

     break;
    }//ibp_fb040_blr_dtype__int128

    case isc_api::ibp_fb040_blr_dtype__decfloat16:
    {
     currentElementSize=xdr::get_size__p_decfloat16();

     assert(currentElementSize==sizeof(protocol::P_DECFLOAT16));

     break;
    }//ibp_fb040_blr_dtype__decfloat16

    case isc_api::ibp_fb040_blr_dtype__decfloat34:
    {
     currentElementSize=xdr::get_size__p_decfloat34();

     assert(currentElementSize==sizeof(protocol::P_DECFLOAT34));

     break;
    }//ibp_fb040_blr_dtype__decfloat34

    case isc_api::ibp_fb040_blr_dtype__timestamp_with_tz:
    {
     currentElementSize=xdr::get_size__fb040_timestamp_with_tz();

     break;
    }//ibp_fb040_blr_dtype__timestamp_with_tz

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"typeID: "<<int(typeID));

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__unk_blr_data_type_1,
       typeID);
    }//default
   }//switch

   cbResult=IBP_Memory_Utils::AddMemLength(cbResult,currentElementSize); //throw
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb,
     ibp_mce_remote__encode_packet__xdr__error_in_element_of_msg_data_buffer_1,
     iElement);
  }//catch
 }//for[ever]

 MSG_BLR__SKIP_TAG(end);
 MSG_BLR__SKIP_TAG(eoc);

 assert(blr_reader.debug__eof());

 //-----------------------------------------------------------------------
 #undef MSG_BLR__SKIP_TAG
 #undef MSG_BLR__SKIP_BYTE

 //-----------------------------------------------------------------------
 return cbResult;
}//Calc_BLR_MAX_XDR_SIZE

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
