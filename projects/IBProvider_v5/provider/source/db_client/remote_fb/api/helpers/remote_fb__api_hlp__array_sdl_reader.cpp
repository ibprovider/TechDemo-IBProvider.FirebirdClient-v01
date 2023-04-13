////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__array_sdl_reader.cpp
//! \brief   Класс для обработки буфера с SDL-описанием массива.
//! \author  Kovalenko Dmitry
//! \date    24.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__array_sdl_reader.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__ArraySdlReader

RemoteFB__API_HLP__ArraySdlReader::RemoteFB__API_HLP__ArraySdlReader
                                           (size_t           const szSDL,
                                            const byte_type* const pSDL)
 :m_beg(pSDL)
 ,m_end(pSDL+szSDL)
 ,m_ptr(pSDL)
{;}

//interface --------------------------------------------------------------
size_t RemoteFB__API_HLP__ArraySdlReader::current_offset()const
{
 assert(m_ptr>=m_beg);
 assert(m_ptr<=m_end);

 return static_cast<size_t>(m_ptr-m_beg);
}//current_offset

//------------------------------------------------------------------------
RemoteFB__API_HLP__ArraySdlReader::byte_type
 RemoteFB__API_HLP__ArraySdlReader::read_byte
                                           (const wchar_t* const check_place,
                                            const wchar_t* const check_point)
{
 assert(check_place);
 assert(check_point);

 assert(m_ptr>=m_beg);
 assert(m_ptr<=m_end);

 if(m_ptr==m_end)
 {
  //ERROR - Invalid SDL. Unexpected end of data.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
   (check_place,
    check_point);
 }//if

 const byte_type resultValue=*m_ptr;

 ++m_ptr;

 return resultValue;
}//read_byte

//------------------------------------------------------------------------
RemoteFB__API_HLP__ArraySdlReader::value_ui2_type
 RemoteFB__API_HLP__ArraySdlReader::read_ui2(const wchar_t* const check_place,
                                             const wchar_t* const check_point)
{
 assert(check_place);
 assert(check_point);

 assert(m_ptr>=m_beg);
 assert(m_ptr<=m_end);

 if((m_end-m_ptr)<2)
 {
  //ERROR - Invalid SDL. Unexpected end of data.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
   (check_place,
    check_point);
 }//if

 value_ui2_type resultValue=(value_ui2_type(m_ptr[0]))
                           +(value_ui2_type(m_ptr[1])<<8);
 m_ptr+=2;

 return static_cast<value_ui2_type>(resultValue);
}//read_ui2

//------------------------------------------------------------------------
RemoteFB__API_HLP__ArraySdlReader::value_i1_type
 RemoteFB__API_HLP__ArraySdlReader::read_i1(const wchar_t* const check_place,
                                            const wchar_t* const check_point)
{
 assert(check_place);
 assert(check_point);

 assert(m_ptr>=m_beg);
 assert(m_ptr<=m_end);

 if(m_ptr==m_end)
 {
  //ERROR - Invalid SDL. Unexpected end of data.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
   (check_place,
    check_point);
 }//if

 const value_i1_type resultValue=static_cast<value_i1_type>(*m_ptr);

 ++m_ptr;

 return resultValue;
}//read_i1

//------------------------------------------------------------------------
RemoteFB__API_HLP__ArraySdlReader::value_i2_type
 RemoteFB__API_HLP__ArraySdlReader::read_i2(const wchar_t* const check_place,
                                            const wchar_t* const check_point)
{
 assert(check_place);
 assert(check_point);

 assert(m_ptr>=m_beg);
 assert(m_ptr<=m_end);

 if((m_end-m_ptr)<2)
 {
  //ERROR - Invalid SDL. Unexpected end of data.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
   (check_place,
    check_point);
 }//if

 value_ui2_type resultValue=(value_ui2_type(m_ptr[0]))
                           +(value_ui2_type(m_ptr[1])<<8);
 m_ptr+=2;

 return static_cast<value_i2_type>(resultValue);
}//read_i2

//------------------------------------------------------------------------
RemoteFB__API_HLP__ArraySdlReader::value_i4_type
 RemoteFB__API_HLP__ArraySdlReader::read_i4(const wchar_t* const check_place,
                                            const wchar_t* const check_point)
{
 assert(check_place);
 assert(check_point);

 assert(m_ptr>=m_beg);
 assert(m_ptr<=m_end);

 if((m_end-m_ptr)<4)
 {
  //ERROR - Invalid SDL. Unexpected end of data.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
   (check_place,
    check_point);
 }//if

 value_ui4_type resultValue=(value_ui4_type(m_ptr[0]))
                           +(value_ui4_type(m_ptr[1])<<8)
                           +(value_ui4_type(m_ptr[2])<<16)
                           +(value_ui4_type(m_ptr[3])<<24);
 m_ptr+=4;

 return static_cast<value_i4_type>(resultValue);
}//read_i4

//------------------------------------------------------------------------
std::string
 RemoteFB__API_HLP__ArraySdlReader::read_string
                                           (const wchar_t* const check_place,
                                            const wchar_t* const check_point1,
                                            const wchar_t* const check_point2)
{
 assert(check_place);
 assert(check_point1);
 assert(check_point2);

 assert(m_ptr>=m_beg);
 assert(m_ptr<m_end);

 assert(m_ptr>=m_beg);
 assert(m_ptr<=m_end);

 const byte_type* ptr=m_ptr;

 if(ptr==m_end)
 {
  //ERROR - Invalid SDL. Unexpected end of data.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
   (check_place,
    check_point1);
 }//if

 const byte_type n=*ptr;

 ++ptr;

 size_t bufferTailSize=static_cast<size_t>(m_end-ptr);

 if(bufferTailSize<n)
 {
  //ERROR - Invalid SDL. Too large string data.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__len_of_str_data_exceed_the_size_of_buffer_tail
   (check_place,
    check_point2,
    n,
    bufferTailSize);
 }//if

 m_ptr=ptr+n;

 return std::string(reinterpret_cast<const char*>(ptr),n); //throw [out of memory]
}//read_string

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
