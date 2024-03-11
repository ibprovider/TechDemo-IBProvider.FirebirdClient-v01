////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_integer_to_portable_format.h
//! \brief   Класс для упаковки чисел в транспортный формат.
//! \author  Kovalenko Dmitry
//! \date    29.10.2014.
#ifndef _isc_integer_to_portable_format_H_
#define _isc_integer_to_portable_format_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class isc_integer_to_portable_format

/// <summary>
///  Класс для упаковки чисел в транспортный формат.
/// </summary>
class isc_integer_to_portable_format
{
 public:
  typedef unsigned __int8                   byte_type;
  typedef unsigned __int16                  ushort_type;

  typedef signed __int16                    short_type;

  typedef unsigned __int32                  ui4_type;

  typedef long                              long_type;

 public:
  template<size_t N>
  struct tag_buffer
  {
   byte_type   data[N];
  };//class tag_buffer

 public:
  template<size_t N,typename TNumeric>
  static void exec(tag_buffer<N>* buffer,TNumeric value)=delete;
};//class isc_integer_to_portable_format

////////////////////////////////////////////////////////////////////////////////
//class isc_integer_to_portable_format

template<>
inline
void isc_integer_to_portable_format::exec<1,isc_integer_to_portable_format::byte_type>
                                           (tag_buffer<1>* const buffer,
                                            byte_type      const value)
{
 assert(buffer!=nullptr);

 buffer->data[0]=value;
}//exec<1,byte_type>

//------------------------------------------------------------------------
template<>
inline
void isc_integer_to_portable_format::exec<2,isc_integer_to_portable_format::ushort_type>
                                           (tag_buffer<2>* const buffer,
                                            ushort_type          value)
{
 assert_s(sizeof(ushort_type)==2);
 assert_s(sizeof(byte_type)==1);

 //Алгоритм рассчитан исключительно на 8-битные байты (char).
 #if(CHAR_BIT!=8)
  #error "Unsupport numbers of bits in byte"
 #endif

 buffer->data[0]=(byte_type)(value);

 buffer->data[1]=(byte_type)(value>>8);
}//exec<2,ushort_type>

//------------------------------------------------------------------------
template<>
inline
void isc_integer_to_portable_format::exec<2,isc_integer_to_portable_format::short_type>
                                           (tag_buffer<2>* const buffer,
                                            short_type          value)
{
 assert_s(sizeof(short_type)==2);
 assert_s(sizeof(byte_type)==1);

 //Алгоритм рассчитан исключительно на 8-битные байты (char).
 #if(CHAR_BIT!=8)
  #error "Unsupport numbers of bits in byte"
 #endif

 buffer->data[0]=(byte_type)(value);

 buffer->data[1]=(byte_type)(value>>8);
}//exec<2,short_type>

//------------------------------------------------------------------------
template<>
inline
void isc_integer_to_portable_format::exec<4,isc_integer_to_portable_format::ui4_type>
                                           (tag_buffer<4>* const buffer,
                                            ui4_type       const value)
{
 assert_s(sizeof(ui4_type)==4);
 assert_s(sizeof(byte_type)==1);

 //Алгоритм рассчитан исключительно на 8-битные байты (char).
 #if(CHAR_BIT!=8)
  #error "Unsupport numbers of bits in byte"
 #endif

 buffer->data[0]=(byte_type)(value);

 buffer->data[1]=(byte_type)(value>>8);

 buffer->data[2]=(byte_type)(value>>16);

 buffer->data[3]=(byte_type)(value>>24);
}//exec<4,ui4_type>

//------------------------------------------------------------------------
template<>
inline
void isc_integer_to_portable_format::exec<4,isc_integer_to_portable_format::long_type>
                                           (tag_buffer<4>* const buffer,
                                            long_type            value)
{
 assert_s(sizeof(long_type)==4);
 assert_s(sizeof(byte_type)==1);

 //Алгоритм рассчитан исключительно на 8-битные байты (char).
 #if(CHAR_BIT!=8)
  #error "Unsupport numbers of bits in byte"
 #endif

 buffer->data[0]=(byte_type)(value);

 buffer->data[1]=(byte_type)(value>>8);

 buffer->data[2]=(byte_type)(value>>16);

 buffer->data[3]=(byte_type)(value>>24);
}//exec<4,long_type>

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif