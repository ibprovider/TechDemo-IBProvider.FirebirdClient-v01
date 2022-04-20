////////////////////////////////////////////////////////////////////////////////
//Utilities for work with pointers
//                                              Kovalenko Dmitry. 14.01.2009
#ifndef _t_pointer_cast_H_
#define _t_pointer_cast_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename T1,typename T2>
inline void reinterpret_ptr_cast(T1** const pptr1,
                                 T2*  const ptr2)
{
 assert(pptr1);

 (*pptr1)=reinterpret_cast<T1*>(ptr2);
}//reinterpret_ptr_cast

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
