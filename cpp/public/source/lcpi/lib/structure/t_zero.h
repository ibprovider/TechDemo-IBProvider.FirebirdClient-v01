////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 10.08.2015.
#ifndef _cpp_public_lcpi_lib_structure__t_zero_H_
#define _cpp_public_lcpi_lib_structure__t_zero_H_

#include <lcpi/lib/structure/t_numeric_initializator.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_zero

typedef t_numeric_initializator<0> t_zero;

static const t_zero zero;

////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool is_zero(T x);

//------------------------------------------------------------------------
template<>
inline bool is_zero<unsigned char>(unsigned char x)
{
 return structure::zero.eq(x);
}//is_zero - unsigned char

//------------------------------------------------------------------------
template<>
inline bool is_zero<std::uint16_t>(std::uint16_t x)
{
 return structure::zero.eq(x);
}//is_zero - std::uint16_t

//------------------------------------------------------------------------
template<>
inline bool is_zero<std::uint32_t>(std::uint32_t x)
{
 return structure::zero.eq(x);
}//is_zero - std::uint32_t

//------------------------------------------------------------------------
template<>
inline bool is_zero<std::uint64_t>(std::uint64_t x)
{
 return structure::zero.eq(x);
}//is_zero - std::uint64_t

//------------------------------------------------------------------------
template<>
inline bool is_zero<signed char>(signed char x)
{
 return structure::zero.eq(x);
}//is_zero - signed char

//------------------------------------------------------------------------
template<>
inline bool is_zero<std::int16_t>(std::int16_t x)
{
 return structure::zero.eq(x);
}//is_zero - std::int16_t

//------------------------------------------------------------------------
template<>
inline bool is_zero<std::int32_t>(std::int32_t x)
{
 return structure::zero.eq(x);
}//is_zero - std::int32_t

//------------------------------------------------------------------------
template<>
inline bool is_zero<std::int64_t>(std::int64_t x)
{
 return structure::zero.eq(x);
}//is_zero - std::int64_t

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

template<>
inline bool is_zero<signed long>(signed long x)
{
 return structure::zero.eq(x);
}//is_zero - signed long

#endif

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

template<>
inline bool is_zero<unsigned long>(unsigned long x)
{
 return structure::zero.eq(x);
}//is_zero - unsigned long

#endif

//------------------------------------------------------------------------
template<>
inline bool is_zero<float>(float x)
{
 return structure::zero.eq(x);
}//is_zero - float

//------------------------------------------------------------------------
template<>
inline bool is_zero<double>(double x)
{
 return structure::zero.eq(x);
}//is_zero - double

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
