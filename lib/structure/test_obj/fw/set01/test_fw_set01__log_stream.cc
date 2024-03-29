////////////////////////////////////////////////////////////////////////////////
#ifndef _tso_fw_set01__log_stream_CC_
#define _tso_fw_set01__log_stream_CC_

#include <structure/t_str_formatter.h>
#include <structure/t_negative_one.h>
#include <iostream>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class Basic_LogStream_ToFile

template<class Allocator>
Basic_LogStream_ToFile<Allocator>::Basic_LogStream_ToFile
                                           (const std::string& LogFilePath)
 :m_log_file(LogFilePath.c_str())
{
 if(!m_log_file)
 {
  structure::str_formatter fmsg("Can't open log file [%1]");

  fmsg<<LogFilePath;

  throw std::runtime_error(fmsg);
 }//if
}//Basic_LogStream

//------------------------------------------------------------------------
template<class Allocator>
Basic_LogStream_ToFile<Allocator>::~Basic_LogStream_ToFile()
{
}

//interface --------------------------------------------------------------
template<class Allocator>
void Basic_LogStream_ToFile<Allocator>::out(const char_type* const s)
{
 structure::tstr_to_tstr
  (&m_tmp_buffer,
   s,
   structure::negative_one,
   nullptr,
   CP_ACP);

 m_log_file<<m_tmp_buffer;

 m_log_file.flush();
}//out

////////////////////////////////////////////////////////////////////////////////
//class Basic_LogStream

template<class Allocator>
Basic_LogStream<Allocator>::Basic_LogStream(UINT const         ConsoleCP,
                                            const std::string& LogFilePath)
 :inherited(LogFilePath)
 ,m_ConsoleCP(ConsoleCP)
{
}

//------------------------------------------------------------------------
template<class Allocator>
Basic_LogStream<Allocator>::~Basic_LogStream()
{
}

//interface --------------------------------------------------------------
template<class Allocator>
void Basic_LogStream<Allocator>::out(const char_type* const s)
{
 structure::tstr_to_tstr
  (&m_tmp_buffer,
   s,
   structure::negative_one,
   nullptr,
   m_ConsoleCP);

 std::cout<<m_tmp_buffer;

 return inherited::out(s);
}//out

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
