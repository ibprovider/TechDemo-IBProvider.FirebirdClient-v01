////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_info_buffer_v1_builder.cpp
//! \brief   Information buffer builder.
//! \author  Kovalenko Dmitry
//! \date    24.03.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_info_buffer_v1_builder.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/isc_base/isc_integer_to_portable_format.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_info_buffer_v1_builder

t_isc_info_buffer_v1_builder::t_isc_info_buffer_v1_builder()
{
}//t_isc_info_buffer_v1_builder

//------------------------------------------------------------------------
t_isc_info_buffer_v1_builder::~t_isc_info_buffer_v1_builder()
{
}//~t_isc_info_buffer_v1_builder

//interface --------------------------------------------------------------
const t_isc_info_buffer_v1_builder::buffer_type&
 t_isc_info_buffer_v1_builder::buffer()const
{
 return m_buffer;
}//buffer - const

//------------------------------------------------------------------------
t_isc_info_buffer_v1_builder::buffer_type&
 t_isc_info_buffer_v1_builder::buffer()
{
 return m_buffer;
}//buffer

//------------------------------------------------------------------------
void t_isc_info_buffer_v1_builder::append__Int
                                           (byte_type const tagID,
                                            long_type const v)
{
 assert_s(sizeof(tagID)==1);
 assert_s(sizeof(tag_size_type)==2);
 assert_s(sizeof(v)>0);
 assert(structure::can_numeric_cast<tag_size_type>(sizeof(v)));

 //----------------------------------------- 1. TAG
 m_buffer.push_back(tagID);

 //----------------------------------------- 2. LENGTH=sizeof(v)
 this->helper__push_length(/*dataSize*/sizeof(v));

 //----------------------------------------- 3. DATA
 {
  isc_base::isc_integer_to_portable_format::tag_buffer<sizeof(v)> data;

  isc_base::isc_integer_to_portable_format::exec(&data,v);

  m_buffer.write(data.data,_LCPI_DIM_(data.data));
 }//local
}//append__Int

//------------------------------------------------------------------------
void t_isc_info_buffer_v1_builder::append__END()
{
 m_buffer.push_back(isc_api::ibp_isc_info_end);
}//append__END

//------------------------------------------------------------------------
void t_isc_info_buffer_v1_builder::append__TRUNCATED()
{
 m_buffer.push_back(isc_api::ibp_isc_info_truncated);
}//append__TRUNCATED

//helper methods ---------------------------------------------------------
void t_isc_info_buffer_v1_builder::helper__push_length(tag_size_type const valueSize)
{
 isc_base::isc_integer_to_portable_format::tag_buffer<sizeof(tag_size_type)> data;

 isc_base::isc_integer_to_portable_format::exec(&data,valueSize);

 m_buffer.write(data.data,_LCPI_DIM_(data.data));
}//helper__push_length

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
