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
inline bool is_zero<unsigned short>(unsigned short x)
{
 return structure::zero.eq(x);
}//is_zero - unsigned short

//------------------------------------------------------------------------
template<>
inline bool is_zero<unsigned int>(unsigned int x)
{
 return structure::zero.eq(x);
}//is_zero - unsigned int

//------------------------------------------------------------------------
template<>
inline bool is_zero<unsigned __int64>(unsigned __int64 x)
{
 return structure::zero.eq(x);
}//is_zero - unsigned __int64

//------------------------------------------------------------------------
template<>
inline bool is_zero<signed char>(signed char x)
{
 return structure::zero.eq(x);
}//is_zero - signed char

//------------------------------------------------------------------------
template<>
inline bool is_zero<signed short>(signed short x)
{
 return structure::zero.eq(x);
}//is_zero - signed short

//------------------------------------------------------------------------
template<>
inline bool is_zero<signed int>(signed int x)
{
 return structure::zero.eq(x);
}//is_zero - signed int

//------------------------------------------------------------------------
template<>
inline bool is_zero<signed __int64>(signed __int64 x)
{
 return structure::zero.eq(x);
}//is_zero - signed __int64

//------------------------------------------------------------------------
template<>
inline bool is_zero<signed long>(signed long x)
{
 return structure::zero.eq(x);
}//is_zero - signed long

//------------------------------------------------------------------------
template<>
inline bool is_zero<unsigned long>(unsigned long x)
{
 return structure::zero.eq(x);
}//is_zero - unsigned long

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
