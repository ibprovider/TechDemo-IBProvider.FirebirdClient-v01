////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_info_buffer_v1_builder.h
//! \brief   Information buffer builder (v1).
//! \author  Kovalenko Dmitry
//! \date    24.03.2023
#ifndef _isc_info_buffer_v1_builder_H_
#define _isc_info_buffer_v1_builder_H_

#include "source/db_obj/db_memory.h"
#include <structure/t_tmp_seg_buffer.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_info_buffer_v1_builder

class t_isc_info_buffer_v1_builder
{
 private:
  using self_type=t_isc_info_buffer_v1_builder;

  t_isc_info_buffer_v1_builder(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  using byte_type
   =unsigned char;

  using long_type
   =long;

  using tag_id_type
   =byte_type;

  using tag_size_type
   =unsigned __int16;

  using allocator_type
   =db_obj::t_db_memory_allocator;

  using buffer_type
   =structure::t_tmp_seg_buffer<byte_type,128,allocator_type>;

 public: //---------------------------------------------------------------
  explicit t_isc_info_buffer_v1_builder();

 ~t_isc_info_buffer_v1_builder();

  //interface ------------------------------------------------------------
  const buffer_type& buffer() const;

  buffer_type& buffer();

  void append__Int(byte_type tagID,long_type v);

  void append__END();

  void append__TRUNCATED();

 private:
  void helper__push_length(tag_size_type valueSize);

 private:
  buffer_type m_buffer;
};//class t_isc_info_buffer_v1_builder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
