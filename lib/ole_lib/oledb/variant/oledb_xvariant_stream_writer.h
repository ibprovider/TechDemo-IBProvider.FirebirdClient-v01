////////////////////////////////////////////////////////////////////////////////
//Implementation of DBVARIANT_STREAM_WRITER interface
//                                                 Kovalenko Dmitry. 07.02.2010.
#ifndef _oledb_xvariant_stream_writer_H_
#define _oledb_xvariant_stream_writer_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <ole_lib/oledb/variant/oledb_variant_stream_writer.h>
#include <ole_lib/oledb/oledb_common.h>
#include <structure/t_tmp_seg_buffer.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class basic_dbvariant_stream_writer

template<typename T,class Allocator,size_t FixBufSize>
class basic_dbvariant_stream_writer:public DBVARIANT_STREAM_WRITER<T>
{
 private:
  typedef basic_dbvariant_stream_writer<T,Allocator,FixBufSize>   self_type;

  basic_dbvariant_stream_writer(const self_type&);
  self_type& operator = (const self_type&);

 private: //internal typedefs --------------------------------------------
  typedef DBVARIANT_STREAM_WRITER__ITEM_TYPE_SELECTOR<T>          item_type_selector;

 public: //typedefs ------------------------------------------------------
  typedef Allocator                                               allocator_type;
  typedef typename item_type_selector::result_type                item_type;
  typedef structure::t_tmp_seg_buffer<item_type,
                                      FixBufSize,
                                      allocator_type>             buffer_type;
 public:
  buffer_type m_buffer;

  basic_dbvariant_stream_writer();
 ~basic_dbvariant_stream_writer();

  //DBVARIANT_BYTES_WRITER interface -------------------------------------
  virtual void write(const T* ptr,size_t size) COMP_W000004_OVERRIDE_FINAL;//abstract
};//class basic_dbvariant_stream_writer

typedef basic_dbvariant_stream_writer<void,TOLEDBMemoryAllocator,8196>
         TDBVariantBytesWriter;

typedef basic_dbvariant_stream_writer<wchar_t,TOLEDBMemoryAllocator,8196>
         TDBVariantWCharsWriter;

typedef basic_dbvariant_stream_writer<char,TOLEDBMemoryAllocator,8196>
         TDBVariantCharsWriter;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/oledb_xvariant_stream_writer.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
