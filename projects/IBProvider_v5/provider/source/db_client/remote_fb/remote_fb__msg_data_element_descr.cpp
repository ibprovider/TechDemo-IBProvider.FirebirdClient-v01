////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__msg_data_element_descr.cpp
//! \brief   Описатель элемента MSG-буфера с данными.
//! \author  Kovalenko Dmitry
//! \date    18.05.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
#include <structure/t_negative_one.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__MsgDataElementDescr

RemoteFB__MsgDataElementDescr::RemoteFB__MsgDataElementDescr()
 :m_msg_value_block_size  (structure::negative_one)
 ,m_msg_value_block_offset(structure::negative_one)
 ,m_msg_sqlind_offset     (structure::negative_one)
 ,m_msg_blrtype           (structure::negative_one)
 ,m_xvar_sqltype          (0)
 ,m_xvar_sqlscale         (structure::negative_one)
{;}

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
