////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__log_stream_H_
#define _test_fw_set01__log_stream_H_

#include <structure/test_obj/t_tso_log.h>
#include <structure/t_smart_object.h>
#include <fstream>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class Allocator>
class Basic_LogStream_ToFile;

template<class Allocator>
class Basic_LogStream;

////////////////////////////////////////////////////////////////////////////////
//class Basic_LogStream_ToFile

template<class Allocator>
class Basic_LogStream_ToFile
 :public structure::t_basic_smart_interface_impl__dynamic<structure::tso_obj::t_log_stream,Allocator>
{
 private:
  using self_type=Basic_LogStream_ToFile<Allocator>;

  Basic_LogStream_ToFile(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 protected:
  virtual ~Basic_LogStream_ToFile();

 public:
  using char_type
   =structure::tso_obj::t_log_stream::char_type;

 public:
  explicit Basic_LogStream_ToFile(const std::string& LogFilePath);

  //interface ------------------------------------------------------------
  virtual void out(const char_type* s) LCPI_CPP_CFG__METHOD__OVERRIDE;

 private:
  //temporary buffer for string conversion
  std::string m_tmp_buffer;

  std::ofstream m_log_file;
};//class Basic_LogStream_ToFile

////////////////////////////////////////////////////////////////////////////////
//class Basic_LogStream

template<class Allocator>
class Basic_LogStream
 :public Basic_LogStream_ToFile<Allocator>
{
 private:
  using self_type=Basic_LogStream<Allocator>;
  using inherited=Basic_LogStream_ToFile<Allocator>;

  Basic_LogStream(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using char_type
   =typename inherited::char_type;

 public:
  Basic_LogStream(UINT ConsoleCP,const std::string& LogFilePath);

  virtual ~Basic_LogStream();

  //interface ------------------------------------------------------------
  virtual void out(const char_type* s) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  const UINT m_ConsoleCP;

  //temporary buffer for string conversion
  std::string m_tmp_buffer;
};//class Basic_LogStream

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/test_obj/fw/set01/test_fw_set01__log_stream.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
