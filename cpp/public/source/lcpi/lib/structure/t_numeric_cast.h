////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 29.03.2007.
#ifndef _cpp_public_lcpi_lib_structure__t_numeric_cast_H_
#define _cpp_public_lcpi_lib_structure__t_numeric_cast_H_

#include <lcpi/lib/structure/t_numeric_limits.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
inline bool can_numeric_cast(FromType x);

template<typename ToType,typename FromType>
inline bool can_numeric_cast(ToType* pdest,FromType x);

template<typename ToType,typename FromType>
inline ToType static_numeric_cast(FromType x);

template<typename ToType,typename FromType>
inline void static_numeric_cast(ToType* pdest,FromType x);

template<typename ToType,typename FromType>
ToType verified_numeric_cast(FromType x,const char* err_source);

template<typename ToType,typename FromType>
void verified_numeric_cast(ToType* pdest,FromType x,const char* err_source);

template<typename ToType,typename FromType>
ToType verified_length_cast(FromType x,const char* err_source);

template<typename ToType,typename FromType>
void verified_length_cast(ToType* pdest,FromType x,const char* err_source);

////////////////////////////////////////////////////////////////////////////////

template<typename FromType>
typename structure::t_numeric_limits<FromType>::unsigned_numeric_type
 remove_numeric_sign(FromType x);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/t_numeric_cast.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
