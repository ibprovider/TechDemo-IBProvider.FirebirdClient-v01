////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 25.10.2022.
#ifndef _cpp_public_lcpi_lib_structure__t_debug_H_
#define _cpp_public_lcpi_lib_structure__t_debug_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
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
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
