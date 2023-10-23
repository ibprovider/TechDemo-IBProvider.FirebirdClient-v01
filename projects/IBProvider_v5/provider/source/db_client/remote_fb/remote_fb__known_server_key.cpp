////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__known_server_key.cpp
//! \brief   Type of known by server key, received from it by client.
//! \author  Kovalenko Dmitry
//! \date    15.08.2016.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__known_server_key.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__KnownServerKey

RemoteFB__KnownServerKey::RemoteFB__KnownServerKey(const wstr_box_type&   _wstrType,
                                                   const wstr_range_type& _wstrPlugin)
 :wstrType   (_wstrType.make_str())
 ,wstrPlugin (_wstrPlugin.first,_wstrPlugin.last)
{;}

//------------------------------------------------------------------------
RemoteFB__KnownServerKey::~RemoteFB__KnownServerKey()
{;}

//------------------------------------------------------------------------
RemoteFB__KnownServerKey::self_ptr
 RemoteFB__KnownServerKey::Create(const wstr_box_type&   _wstrType,
                                  const wstr_range_type& _wstrPlugin)
{
 return lib::structure::not_null_ptr
          (new self_type
            (_wstrType,
             _wstrPlugin));
}//Create

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
