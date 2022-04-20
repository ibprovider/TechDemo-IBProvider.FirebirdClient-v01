////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Components. Stream writer.
//                                                 Kovalenko Dmitry. 07.09.2012.
#ifndef _oledb_variant_stream_writer_H_
#define _oledb_variant_stream_writer_H_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT_STREAM_WRITER

template<typename T>
struct COMP_CONF_DECLSPEC_NOVTABLE DBVARIANT_STREAM_WRITER
{
 public:
  virtual void write(const T* ptr,size_t size)=0;
};//struct DBVARIANT_STREAM_WRITER

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT_STREAM_WRITER__ITEM_TYPE_SELECTOR

template<typename T>
struct DBVARIANT_STREAM_WRITER__ITEM_TYPE_SELECTOR
{
 public:
  typedef T             result_type;
};//struct DBVARIANT_STREAM_WRITER__ITEM_TYPE_SELECTOR

//------------------------------------------------------------------------
template<>
struct DBVARIANT_STREAM_WRITER__ITEM_TYPE_SELECTOR<void>
{
 public:
  typedef unsigned char result_type;
};//struct DBVARIANT_STREAM_WRITER__ITEM_TYPE_SELECTOR

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
