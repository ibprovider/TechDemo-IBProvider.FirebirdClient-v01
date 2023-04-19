////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__msg_v1_utilities.cpp
//! \brief   Helpers for MSG-classes [v1].
//! \author  Kovalenko Dmitry
//! \date    18.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__msg_v1_utilities.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#ifndef NDEBUG
# include "source/db_client/remote_fb/api/helpers/blr/v05/remote_fb__api_hlp__blr_v05__utilities.h"
#endif

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__Msg_v1__Utilities

size_t RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg(const RemoteFB__InMsg_v1* const pInMsg)
{
 size_t const cValues
  =self_type::Helper__TestMsg
    (pInMsg,
     L"pInMsg");

 return cValues;
}//TestMsg

//------------------------------------------------------------------------
size_t RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg(const RemoteFB__OutMsg_v1* const pOutMsg)
{
 size_t const cValues
  =self_type::Helper__TestMsg
    (pOutMsg,
     L"pOutMsg");

 return cValues;
}//TestMsg

//------------------------------------------------------------------------
void RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg(const RemoteFB__OutMsg_v1* const pOutMsg,
                                                   size_t                     const minSQLD,
                                                   t_ibp_subsystem_id         const subsystemID)
{
 size_t const cValues
  =self_type::Helper__TestMsg
    (pOutMsg,
     L"pOutMsg");

 if(cValues<minSQLD)
 {
  //
  // [2023-04-15] Let's use the error message of XSQLDA error. Ok?
  //
  RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
   (subsystemID,
    L"pOutMsg",
    cValues);
 }//if
}//TestMsg

//------------------------------------------------------------------------
template<class TMSG>
size_t RemoteFB__API_HLP__Msg_v1__Utilities::Helper__TestMsg
                              (const TMSG*    const pMsg,
                               const wchar_t* const pMsgSign)
{
 assert(pMsgSign!=nullptr);

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__Msg_v1__Utilities::Helper__TestMsg";

 if(pMsg==nullptr)
  return 0;

#ifndef NDEBUG
 RemoteFB__API_HLP__BLR_V05__Utilities::Debug__CHECK_BLR
  (pMsg->blr,
   pMsg->descrs,
   pMsg->data,
   pMsg->data_align);
#endif

 if(!pMsg->descrs.empty() && pMsg->descrs.data()==nullptr)
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#001",
    L"[%1] has a null ptr to descrs. The number of descrs is [%2]",
    pMsgSign,
    pMsg->descrs.size());
 }//if

 if(!pMsg->blr.empty() && pMsg->blr.data()==nullptr)
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#002",
    L"[%1] has a null ptr to blr. The size of blr is [%2]",
    pMsgSign,
    pMsg->blr.size());
 }//if

 if(!pMsg->data.empty() && pMsg->data.data()==nullptr)
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#003",
    L"[%1] has a null ptr to data. The size of data is [%2]",
    pMsgSign,
    pMsg->data.size());
 }//if

 if(pMsg->descrs.empty())
 {
  //no elements

  if(!pMsg->blr.empty())
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#004",
     L"[%1] has an unexpected blr [size: %2]",
     pMsgSign,
     pMsg->blr.size());
  }//if

  if(!pMsg->data.empty())
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#005",
     L"[%1] has an unexpected data [size: %2]",
     pMsgSign,
     pMsg->data.size());
  }//if
 }
 else
 {
  assert(!pMsg->descrs.empty());

  if(pMsg->blr.empty())
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#006",
     L"[%1] has no blr. The number of descrs is: %2",
     pMsgSign,
     pMsg->descrs.size());
  }//if

  if(pMsg->data.empty())
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#007",
     L"[%1] has no data. The number of descrs is: %2",
     pMsgSign,
     pMsg->descrs.size());
  }//if
 }//else

 return pMsg->descrs.size();
}//Helper__TestMsg

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
