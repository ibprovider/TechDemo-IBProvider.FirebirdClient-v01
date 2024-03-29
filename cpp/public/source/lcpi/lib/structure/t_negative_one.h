////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 15.04.2009.
#ifndef _cpp_public_lcpi_lib_structure__t_negative_one_H_
#define _cpp_public_lcpi_lib_structure__t_negative_one_H_

#include <lcpi/lib/structure/t_numeric_initializator.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//type t_negative_one

using t_negative_one=t_numeric_initializator<-1>;

////////////////////////////////////////////////////////////////////////////////

static const t_negative_one negative_one;

////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool is_negative_one(T x);

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<unsigned char>(unsigned char x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - unsigned char

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<std::uint16_t>(std::uint16_t x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - std::uint16_t

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<std::uint32_t>(std::uint32_t x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - std::uint32_t

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<std::uint64_t>(std::uint64_t x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - std::uint64_t

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<signed char>(signed char x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - signed char

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<std::int16_t>(std::int16_t x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - std::int16_t

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<signed int>(std::int32_t x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - std::int32_t

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<std::int64_t>(std::int64_t x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - std::int64_t

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

template<>
inline bool is_negative_one<signed long>(signed long x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - signed long

#endif

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

template<>
inline bool is_negative_one<unsigned long>(unsigned long x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - unsigned long

#endif

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<float>(float x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - float

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<double>(double x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - double

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
