////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 11.10.2019
#ifndef _cpp_public_lcpi_lib_structure_utilities__equal_numeric_H_
#define _cpp_public_lcpi_lib_structure_utilities__equal_numeric_H_

#include <lcpi/lib/structure/t_numeric_limits.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////

template<typename T1,typename T2>
bool equal_numeric__signed__unsigned(T1 const n1,T2 const n2)
{
 assert_s(t_numeric_limits<T1>::is_signed);
 assert_s(!t_numeric_limits<T2>::is_signed);

 if(n1<0)
  return false;

 typedef typename t_numeric_limits<T1>::unsigned_numeric_type UT1;

 if(static_cast<UT1>(n1)!=n2)
  return false;

 return true;
}//equal_numeric__signed__unsigned

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////

template<typename T1,typename T2>
bool equal_numeric(T1 n1,T2 n2);

////////////////////////////////////////////////////////////////////////////////
//signed __int32

template<>
inline bool equal_numeric(signed __int32 n1,unsigned __int32 n2)
{
 return detail::equal_numeric__signed__unsigned(n1,n2);
}//equal_numeric

//------------------------------------------------------------------------
template<>
inline bool equal_numeric(signed __int32 n1,unsigned __int64 n2)
{
 return detail::equal_numeric__signed__unsigned(n1,n2);
}//equal_numeric

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
