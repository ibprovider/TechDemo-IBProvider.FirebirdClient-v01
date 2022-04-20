////////////////////////////////////////////////////////////////////////////////
//OLEDB Library. Forward declartions for OLEDB-Variant classes
//                                                Dmitry Kovalenko. 27.02.2006.
#ifndef _oledb_variant_fwrd_H_
#define _oledb_variant_fwrd_H_

#include <ole_lib/oledb/oledb_common.h> //TOLEDBMemoryAllocator

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//declarations

struct DBVARIANT;

////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct DBVARIANT_STREAM_WRITER;

//------------------------------------------------------------------------

typedef DBVARIANT_STREAM_WRITER<void> DBVARIANT_BYTES_WRITER;

////////////////////////////////////////////////////////////////////////////////

template<class Allocator=TOLEDBMemoryAllocator>
class basic_dbvariant;

template<class DBVariant>
class basic_dbvariant_converter;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
