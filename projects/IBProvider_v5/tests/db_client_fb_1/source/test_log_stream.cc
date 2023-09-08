////////////////////////////////////////////////////////////////////////////////
#ifndef _test_log_stream_CC_
#define _test_log_stream_CC_

#include <structure/t_negative_one.h>
#include <iostream>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_Basic_LogStream_ToFile

template<class Allocator>
TTSO_Basic_LogStream_ToFile<Allocator>::TTSO_Basic_LogStream_ToFile
                                           (const std::string& LogFilePath)
 :m_log_file(LogFilePath.c_str())
{
 if(!m_log_file)
 {
  structure::str_formatter fmsg("Can't open log file [%1]");

  fmsg<<LogFilePath;

  throw std::runtime_error(fmsg);
 }//if
}//TTSO_Basic_LogStream_ToFile

//------------------------------------------------------------------------
template<class Allocator>
TTSO_Basic_LogStream_ToFile<Allocator>::~TTSO_Basic_LogStream_ToFile()
{;}

//interface --------------------------------------------------------------
template<class Allocator>
void TTSO_Basic_LogStream_ToFile<Allocator>::out(const char_type* const s)
{
 structure::tstr_to_tstr(&m_tmp_buffer,
                         s,
                         structure::negative_one,
                         nullptr,
                         CP_ACP);

 m_log_file<<m_tmp_buffer;

 m_log_file.flush();
}//out

////////////////////////////////////////////////////////////////////////////////
//class TTSO_Basic_LogStream

template<class Allocator>
TTSO_Basic_LogStream<Allocator>::TTSO_Basic_LogStream
                                           (UINT const         ConsoleCP,
                                            const std::string& LogFilePath)
 :inherited(LogFilePath)
 ,m_ConsoleCP(ConsoleCP)
{;}

//------------------------------------------------------------------------
template<class Allocator>
TTSO_Basic_LogStream<Allocator>::~TTSO_Basic_LogStream()
{;}

//interface --------------------------------------------------------------
template<class Allocator>
void TTSO_Basic_LogStream<Allocator>::out(const char_type* const s)
{
 structure::tstr_to_tstr(&m_tmp_buffer,
                         s,
                         structure::negative_one,
                         nullptr,
                         m_ConsoleCP);

 std::cout<<m_tmp_buffer;

 return inherited::out(s);
}//out

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif