////////////////////////////////////////////////////////////////////////////////
//Generic negative one value
//                                                 Kovalenko Dmitry. 15.04.2009
#ifndef _t_negative_one_H_
#define _t_negative_one_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma hdrstop
#endif

#include <structure/t_numeric_initializator.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_negative_one

typedef t_numeric_initializator<-1> t_negative_one;

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
inline bool is_negative_one<unsigned short>(unsigned short x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - unsigned short

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<unsigned int>(unsigned int x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - unsigned int

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<unsigned __int64>(unsigned __int64 x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - unsigned __int64

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<signed char>(signed char x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - signed char

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<signed short>(signed short x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - signed short

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<signed int>(signed int x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - signed int

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<signed __int64>(signed __int64 x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - signed __int64

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<signed long>(signed long x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - signed long

//------------------------------------------------------------------------
template<>
inline bool is_negative_one<unsigned long>(unsigned long x)
{
 return structure::negative_one.eq(x);
}//is_negative_one - unsigned long

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
}//namespace structure
#endif