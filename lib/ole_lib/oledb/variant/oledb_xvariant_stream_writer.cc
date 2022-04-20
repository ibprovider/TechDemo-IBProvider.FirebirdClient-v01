////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_xvariant_stream_writer_CC_
#define _oledb_xvariant_stream_writer_CC_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class basic_dbvariant_stream_writer

template<typename T,class Allocator,size_t FixBufSize>
basic_dbvariant_stream_writer<T,Allocator,FixBufSize>::basic_dbvariant_stream_writer()
{;}

//------------------------------------------------------------------------
template<typename T,class Allocator,size_t FixBufSize>
basic_dbvariant_stream_writer<T,Allocator,FixBufSize>::~basic_dbvariant_stream_writer()
{;}

//------------------------------------------------------------------------
template<typename T,class Allocator,size_t FixBufSize>
void basic_dbvariant_stream_writer<T,Allocator,FixBufSize>::write
                                           (const T* const ptr,
                                            size_t   const size)
{
 CHECK_READ_TYPED_PTR(reinterpret_cast<const item_type*>(ptr),size);

 m_buffer.write(reinterpret_cast<const item_type*>(ptr),size);
}//write

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
