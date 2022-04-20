////////////////////////////////////////////////////////////////////////////////
//Structures for debug and verification code
//                                                  Kovalenko Dmitry. 26.03.2009
#ifndef _t_debug_H_
#define _t_debug_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//Settings
//
// __STLS_DEBUG_MODE (def/ndef)
//  - enable/disable addition code for create debug and verification code

////////////////////////////////////////////////////////////////////////////////

#ifdef __STLS_DEBUG_MODE
# define __STLS_SYSTEM_SECTION              public
#else
# define __STLS_SYSTEM_SECTION              private
#endif

////////////////////////////////////////////////////////////////////////////////

inline void check_valid_pointer(void*  const DEBUG_CODE(ptr),
                                size_t const DEBUG_CODE(sz))
{
 CHECK_READ_WRITE_PTR(ptr,sz);
}//check_valid_pointer

//------------------------------------------------------------------------
inline void check_valid_pointer(const void* const DEBUG_CODE(ptr),
                                size_t const      DEBUG_CODE(sz))
{
 CHECK_READ_PTR(ptr,sz);
}//check_valid_pointer

//------------------------------------------------------------------------
#ifndef NDEBUG
# define __STLS_CHECK_VALID_POINTER(ptr,sz) check_valid_pointer(ptr,sz);
#else
# define __STLS_CHECK_VALID_POINTER(ptr,sz)
#endif
////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
