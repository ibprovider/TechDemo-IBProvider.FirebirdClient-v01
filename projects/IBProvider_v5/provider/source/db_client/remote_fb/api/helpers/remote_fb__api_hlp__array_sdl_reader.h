////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__array_sdl_reader.h
//! \brief   Класс для обработки буфера с SDL-описанием массива.
//! \author  Kovalenko Dmitry
//! \date    24.09.2016
#ifndef _remote_fb__api_hlp__array_sdl_reader_H_
#define _remote_fb__api_hlp__array_sdl_reader_H_

#include <structure/t_common.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__ArraySdlReader

/// <summary>
///  Класс для обработки буфера с SDL-описанием массива.
/// </summary>
class RemoteFB__API_HLP__ArraySdlReader LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__API_HLP__ArraySdlReader;

  RemoteFB__API_HLP__ArraySdlReader(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using byte_type=unsigned char;

  using value_i1_type=signed __int8;
  using value_i2_type=signed __int16;
  using value_i4_type=signed __int32;

  using value_ui2_type=unsigned __int16;
  using value_ui4_type=unsigned __int32;

 public:
  RemoteFB__API_HLP__ArraySdlReader(size_t           const szSDL,
                                    const byte_type* const pSDL);

  //interface -------------------------------------------------------------
  size_t current_offset()const;

  byte_type read_byte(const wchar_t* check_place,
                      const wchar_t* check_point);

  value_ui2_type read_ui2(const wchar_t* check_place,
                          const wchar_t* check_point);

  value_i1_type read_i1(const wchar_t* check_place,
                        const wchar_t* check_point);

  value_i2_type read_i2(const wchar_t* check_place,
                        const wchar_t* check_point);

  value_i4_type read_i4(const wchar_t* check_place,
                        const wchar_t* check_point);

  std::string read_string(const wchar_t* check_place,
                          const wchar_t* check_point1,
                          const wchar_t* check_point2);

 private:
  const byte_type* const m_beg;
  const byte_type* const m_end;

  const byte_type*       m_ptr;
};//class RemoteFB__API_HLP__ArraySdlReader

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
