////////////////////////////////////////////////////////////////////////////////
#ifndef _tso_fw_set01__log_stream_CC_
#define _tso_fw_set01__log_stream_CC_

#include <structure/t_str_formatter.h>
#include <structure/t_str_cvt_traits__utf8.h>
#include <iostream>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traits>
void write_log_message_in_stream
                        (std::basic_ostream<charT,traits>&       stream,
                         structure::t_basic_const_str_box<charT> s)
{
 const auto c_max_block
  =(std::numeric_limits<std::streamsize>::max)();

 assert(c_max_block>0);

 const auto c_max_block_u
  =static_cast<typename std::make_unsigned<std::streamsize>::type>(c_max_block);

 auto sz=s.size();

 auto p=s.data();

 while(sz!=0)
 {
  std::streamsize n;

  if(sz<c_max_block_u)
   n=sz;
  else
   n=c_max_block_u;

  assert(n>0);

  stream.write(p,n);

  if(stream.fail())
   throw std::runtime_error("[write_log_message_in_stream] Writing in stream failed.");

  sz-=(size_t)n;

  p+=(size_t)n;
 }//if
}//write_log_message_in_stream

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

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
 std::string utf8_str;

 t_str_cvt_traits__utf8::tstr_to_tstr
  (&utf8_str,
   s);

 this->internal__out(utf8_str);
}//out

//------------------------------------------------------------------------
template<class Allocator>
void Basic_LogStream_ToFile<Allocator>::internal__out(t_const_str_box const s)
{
 detail::write_log_message_in_stream(m_log_file,s);

 m_log_file.flush();
}//internal__out

////////////////////////////////////////////////////////////////////////////////
//class Basic_LogStream

template<class Allocator>
Basic_LogStream<Allocator>::Basic_LogStream(const std::string& LogFilePath)
 :inherited(LogFilePath)
{
#if _WIN32
 {
  const auto consoleCP=::GetConsoleOutputCP();

  if(consoleCP!=CP_UTF8)
   throw std::runtime_error("Windows console was not configured for using UTF8.");
 }
#endif
}//Basic_LogStream

//------------------------------------------------------------------------
template<class Allocator>
Basic_LogStream<Allocator>::~Basic_LogStream()
{
}

//interface --------------------------------------------------------------
template<class Allocator>
void Basic_LogStream<Allocator>::internal__out(t_const_str_box const s)
{
 detail::write_log_message_in_stream(std::cout,s);

 inherited::internal__out(s);
}//internal__out

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
