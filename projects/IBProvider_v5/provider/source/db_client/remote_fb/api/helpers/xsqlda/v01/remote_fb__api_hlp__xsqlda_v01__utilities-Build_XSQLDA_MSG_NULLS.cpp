////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_v01__utilities-Build_XSQLDA_MSG_NULLS.cpp
//! \brief   Utilities for processing XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    10.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/remote_fb__api_hlp__xsqlda__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"
#include <structure/t_zero.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_NULLS
                                           (const isc_api::XSQLDA_V1* const pXSQLDA,
                                            msg_nulls_buffer_type&          Nulls)
{
 assert_s(sizeof(msg_nulls_buffer_type::value_type)==1);

 //-----------------------------------------
 if(pXSQLDA==nullptr)
 {
  Nulls.alloc(0);
  return;
 }//if

 //-----------------------------------------
 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);
 assert(pXSQLDA->sqld==0 || pXSQLDA->sqld>0);
 assert(pXSQLDA->sqld<=pXSQLDA->sqln);

 assert_s(CHAR_BIT==8);

 {
  const size_t ResultBufferLength
   =((pXSQLDA->sqld/8) + (((pXSQLDA->sqld%8)!=0)?1:0));

  Nulls.alloc(ResultBufferLength); //throw
 }//local

 std::fill(Nulls.buffer(),Nulls.buffer_end(),structure::zero);

 const isc_api::XSQLVAR_V1*        pXVar=pXSQLDA->sqlvar;
 const isc_api::XSQLVAR_V1* const _eXVar=pXVar+pXSQLDA->sqld;

 msg_nulls_buffer_type::value_type NullMask=0x01;

 size_t NullIndex=0;

 try // catch
 {
  for(;pXVar!=_eXVar;++pXVar)
  {
   assert(NullIndex<Nulls.size());

   assert(NullMask==0x01 ||
          NullMask==0x02 ||
          NullMask==0x04 ||
          NullMask==0x08 ||
          NullMask==0x10 ||
          NullMask==0x20 ||
          NullMask==0x40 ||
          NullMask==0x80);

   if(pXVar->get_value_may_be_null())
   {
    if(pXVar->sqlind==nullptr)
    {
     //ERROR - incorrect data in XSQLVAR structure. null pointer to sql indicator.

     helpers::RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
      (pXVar->sqltype);
    }//if

    if(pXVar->get_value_is_null__std()) //throw
    {
     //устанавливаем флаг null-значения
     assert(NullIndex<Nulls.size());

     Nulls[NullIndex]|=NullMask;
    }//if
   }//if

   if(NullMask!=0x80)
   {
    NullMask=(NullMask<<1);
   }
   else
   {
    NullMask=0x01;

    ++NullIndex;
   }//else
  }//for pXVar
 }
 catch(const std::exception& e)
 {
  IBP_ErrorUtils::Throw__Error
   (e,
    E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_isc__failed_to_process_the_xsqlvar_1,
    (pXVar-pXSQLDA->sqlvar));
 }//catch
}//Build_XSQLDA_MSG_NULLS

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
