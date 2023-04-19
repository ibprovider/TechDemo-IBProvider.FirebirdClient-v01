////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__blr_reader_v1.h
//! \brief   The class for reading a BLR buffer [v1].
//! \author  Kovalenko Dmitry
//! \date    14.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__blr_reader_v1.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__BlrReader_v1

void RemoteFB__BlrReader_v1::helper__throw_bug_check__cur__001__eof()
{
 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (L"RemoteFB__BlrReader_v1::cur",
   L"#001",
   me_bug_check__unexpected_end_of_buffer_0);
}//helper__throw_bug_check__cur__001__eof

//------------------------------------------------------------------------
void RemoteFB__BlrReader_v1::helper__throw_bug_check__read__001__eof()
{
 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (L"RemoteFB__BlrReader_v1::cur",
   L"#001",
   me_bug_check__unexpected_end_of_buffer_0);
}//helper__throw_bug_check__read__001__eof

//------------------------------------------------------------------------
void RemoteFB__BlrReader_v1::helper__throw_bug_check__next__001__eof()
{
 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (L"RemoteFB__BlrReader_v1::cur",
   L"#001",
   me_bug_check__unexpected_end_of_buffer_0);
}//helper__throw_bug_check__next__001__eof

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
