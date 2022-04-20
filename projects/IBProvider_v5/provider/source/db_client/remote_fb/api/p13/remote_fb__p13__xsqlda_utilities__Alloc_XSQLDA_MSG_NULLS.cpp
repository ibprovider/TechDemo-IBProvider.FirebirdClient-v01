////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__xsqlda_utilities__Alloc_XSQLDA_MSG_NULLS.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    21.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"
#include <structure/t_zero.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__XSQLDA_Utilities

void RemoteFB__P13__XSQLDA_Utilities::Alloc_XSQLDA_MSG_NULLS
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
}//Alloc_XSQLDA_MSG_NULLS

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
