////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_v01__utilities-Alloc_XSQLDA_MSG_NULLS.cpp
//! \brief   Utilities for processing XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    10.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include <lcpi/lib/structure/t_zero.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Alloc_XSQLDA_MSG_NULLS
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

 std::fill(Nulls.buffer(),Nulls.buffer_end(),lib::structure::zero);
}//Alloc_XSQLDA_MSG_NULLS - XSQLDA_V1

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Alloc_XSQLDA_MSG_NULLS
                                           (const msg_data_descrs_view_type& DataDescrs,
                                            msg_nulls_buffer_type&           Nulls)
{
 assert_s(sizeof(msg_nulls_buffer_type::value_type)==1);

 //-----------------------------------------
 const size_t sqld=DataDescrs.size();

 assert_s(CHAR_BIT==8);

 {
  const size_t ResultBufferLength
   =((sqld/8) + (((sqld%8)!=0)?1:0));

  Nulls.alloc(ResultBufferLength); //throw
 }//local

 std::fill(Nulls.buffer(),Nulls.buffer_end(),lib::structure::zero);
}//Alloc_XSQLDA_MSG_NULLS - DataDescrs

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
