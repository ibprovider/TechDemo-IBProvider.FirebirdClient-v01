////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api__array_sdl__writer_funcs.h
//! \brief   [ISC API] Утилиты для создания буфера с описанием дескриптора массива
//! \author  Kovalenko Dmitry
//! \date    26.07.2011
#ifndef _isc_api__array_sdl__writer_funcs_H_
#define _isc_api__array_sdl__writer_funcs_H_

#include "source/db_obj/isc_base/isc_api.h" //ibp_isc_sdl_xxxx
#include <structure/t_const_str_box.h>
#include <structure/t_numeric_cast.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_api__array_sdl__writer_funcs

// Требования к TBuffer
//  - void put_byte(byte_type x)
//  - void put_bytes(const char* s,size_type n)
template<class TBuffer>
class t_isc_api__array_sdl__writer_funcs
{
 private:
  typedef t_isc_api__array_sdl__writer_funcs<TBuffer>   self_type;

 public: //typedefs ------------------------------------------------------
  typedef TBuffer                                       buffer_type;

  typedef unsigned char                                 byte_type;

  typedef structure::t_const_str_box                    str_box_type;

 public:
  static void stuff_byte_s (buffer_type& buffer,int    value);
  static void stuff_byte_s (buffer_type& buffer,size_t value);

  static void stuff_word_s (buffer_type& buffer,int value);

  static void stuff_string (buffer_type& buffer,
                            int          sdl,
                            str_box_type str);

  static void stuff_literal(buffer_type& buffer,
                            int          value);
};//class t_isc_api__array_sdl__writer_funcs

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_obj/isc_base/isc_api__array_sdl__writer_funcs.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
