////////////////////////////////////////////////////////////////////////////////
//! \ingroup ib_base_api
//! \file    isc_api__array_sdl__writer_funcs.cc
//! \brief   InterBase. Утилиты для создания буфера с описанием дескриптора массива
//! \author  Kovalenko Dmitry
//! \date    26.07.2011
#ifndef _isc_api__array_sdl__writer_funcs_CC_
#define _isc_api__array_sdl__writer_funcs_CC_

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_api__array_sdl__writer_funcs

template<class TBuffer>
RELEASE_CODE(inline)
void t_isc_api__array_sdl__writer_funcs<TBuffer>::stuff_byte_s
                                           (buffer_type& buffer,
                                            int    const value)
{
 assert(structure::can_numeric_cast<signed char>(value) ||
        structure::can_numeric_cast<unsigned char>(value));

 buffer.put_byte(static_cast<byte_type>((value)&0xFF));
}//stuff_byte_s - int

//------------------------------------------------------------------------
template<class TBuffer>
RELEASE_CODE(inline)
void t_isc_api__array_sdl__writer_funcs<TBuffer>::stuff_byte_s
                                           (buffer_type& buffer,
                                            size_t const value)
{
 assert(structure::can_numeric_cast<unsigned char>(value));

 buffer.put_byte(static_cast<byte_type>((value)&0xFF));
}//stuff_byte_s - size_t

//------------------------------------------------------------------------
template<class TBuffer>
RELEASE_CODE(inline)
void t_isc_api__array_sdl__writer_funcs<TBuffer>::stuff_word_s
                                           (buffer_type& buffer,
                                            int    const value)
{
 assert(structure::can_numeric_cast<signed __int16>(value) ||
        structure::can_numeric_cast<unsigned __int16>(value));

 buffer.put_byte(static_cast<byte_type>((value    )&0xFF));
 buffer.put_byte(static_cast<byte_type>((value>>8 )&0xFF));
}//stuff_word_s

//------------------------------------------------------------------------
template<class TBuffer>
void t_isc_api__array_sdl__writer_funcs<TBuffer>::stuff_string
                                           (buffer_type&       buffer,
                                            int          const sdl,
                                            str_box_type const str)
{
 CHECK_READ_TYPED_PTR(str.ptr,str.len);

 if(!structure::can_numeric_cast<byte_type>(str.len))
 {
  //ERROR - string too long for write to SDL buffer
  t_ibp_error exc(E_FAIL,ibp_mce_array__create_sdl__too_long_str_2);

  exc<<str.len<<structure::t_numeric_limits<byte_type>::max_value();

  exc.raise_me();
 }//if

 self_type::stuff_byte_s(buffer,sdl);
 self_type::stuff_byte_s(buffer,str.len);

 buffer.put_bytes(str.ptr,str.len);
}//stuff_string

//------------------------------------------------------------------------
template<class TBuffer>
void t_isc_api__array_sdl__writer_funcs<TBuffer>::stuff_literal
                                          (buffer_type& buffer,
                                           int    const value)
{
 assert_s(sizeof(value)==4);

 if(value>=-128 && value<=127)
 {
  self_type::stuff_byte_s(buffer,isc_api::ibp_isc_sdl_tiny_integer);

  buffer.put_byte(static_cast<byte_type>((value)&0xFF));
 }
 else
 if(value>=-32768 && value<=32767)
 {
  self_type::stuff_byte_s(buffer,isc_api::ibp_isc_sdl_short_integer);

  buffer.put_byte(static_cast<byte_type>((value    )&0xFF));
  buffer.put_byte(static_cast<byte_type>((value>>8 )&0xFF));
 }
 else
 {
  self_type::stuff_byte_s(buffer,isc_api::ibp_isc_sdl_long_integer);

  buffer.put_byte(static_cast<byte_type>((value    )&0xFF));
  buffer.put_byte(static_cast<byte_type>((value>>8 )&0xFF));
  buffer.put_byte(static_cast<byte_type>((value>>16)&0xFF));
  buffer.put_byte(static_cast<byte_type>((value>>24)&0xFF));
 }//else
}//stuff_literal

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
