////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_msg_data_element_descr.cpp
//! \brief   The descriptor of message data element.
//! \author  Kovalenko Dmitry
//! \date    19.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_msg_data_element_descr.h"
#include <structure/t_negative_one.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////

t_isc_msg_data_element_descr::t_isc_msg_data_element_descr()
 :m_msg_value_block_size  (structure::negative_one)
 ,m_msg_value_block_offset(structure::negative_one)
 ,m_msg_sqlind_offset     (structure::negative_one)
 ,m_msg_blrtype           (structure::negative_one)
 ,m_xvar_sqltype          (0)
 ,m_xvar_sqlscale         (structure::negative_one)
{
}

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
