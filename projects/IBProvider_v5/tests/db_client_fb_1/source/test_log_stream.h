////////////////////////////////////////////////////////////////////////////////
//IBProvider test. Class for log stream
//                                                 Kovalenko Dmitry. 01.03.2009
#ifndef _test_log_stream_H_
#define _test_log_stream_H_

#include "source/test_base.h"
#include <structure/test_obj/t_tso_log.h>
#include <fstream>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class Allocator>
class TTSO_Basic_LogStream_ToFile;

template<class Allocator>
class TTSO_Basic_LogStream;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_LogStream_ToFile

template<class Allocator>
class TTSO_Basic_LogStream_ToFile
 :public structure::t_basic_smart_interface_impl__dynamic
   <structure::tso_obj::t_log_stream,Allocator>
{
 private:
  typedef TTSO_Basic_LogStream_ToFile<Allocator>       self_type;

  TTSO_Basic_LogStream_ToFile(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef structure::tso_obj::t_log_stream::char_type  char_type;

 public:
  TTSO_Basic_LogStream_ToFile(const std::string& LogFilePath);

  virtual ~TTSO_Basic_LogStream_ToFile();

  //interface ------------------------------------------------------------
  virtual void out(const char_type* s) COMP_W000004_OVERRIDE;

 private:
  //temporary buffer for string conversion
  std::string m_tmp_buffer;

  std::ofstream m_log_file;
};//class TTSO_Basic_LogStream_ToFile

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef TTSO_Basic_LogStream_ToFile
 <TTSO_MemoryAllocator>                              TTSO_LogStream_ToFile;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_Basic_LogStream

template<class Allocator>
class TTSO_Basic_LogStream:public TTSO_Basic_LogStream_ToFile<Allocator>
{
 private:
  typedef TTSO_Basic_LogStream<Allocator>            self_type;
  typedef TTSO_Basic_LogStream_ToFile<Allocator>     inherited;

  TTSO_Basic_LogStream(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef typename inherited::char_type              char_type;

 public:
  TTSO_Basic_LogStream(UINT ConsoleCP,const std::string& LogFilePath);

  virtual ~TTSO_Basic_LogStream();

  //interface ------------------------------------------------------------
  virtual void out(const char_type* s) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  const UINT m_ConsoleCP;

  //temporary buffer for string conversion
  std::string m_tmp_buffer;
};//class TTSO_Basic_LogStream

////////////////////////////////////////////////////////////////////////////////
//typedef

typedef TTSO_Basic_LogStream<TTSO_MemoryAllocator> TTSO_LogStream;

typedef TTSO_Basic_LogStream<TSYS_MemoryAllocator> TSYS_LogStream;

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/

////////////////////////////////////////////////////////////////////////////////
#include "source/test_log_stream.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
