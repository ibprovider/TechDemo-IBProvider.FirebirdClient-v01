////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_utils
//! \file    ibp_numeric_cast.h
//! \brief   Утилиты для преобразования чисел
//! \author  Kovalenko Dmitry
//! \date    04.04.2007
#ifndef _ibp_numeric_cast_H_
#define _ibp_numeric_cast_H_

//#include <structure/t_common.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
inline ToType ibp_numeric_cast(FromType x,const wchar_t* source,const wchar_t* x_name);

template<typename ToType,typename FromType>
inline void ibp_numeric_cast(ToType* pTarget,FromType x,const wchar_t* source,const wchar_t* x_name);

template<typename ToType,typename FromType>
inline ToType ibp_size_cast(FromType x,const wchar_t* source,const wchar_t* x_name);

template<typename ToType,typename FromType>
inline void ibp_size_cast(ToType* pTarget,FromType x,const wchar_t* source,const wchar_t* x_name);

////////////////////////////////////////////////////////////////////////////////

template<typename T1,typename T2>
inline bool ibp_can_numeric_add(T1 result,T2 delta);

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/ibp_numeric_cast.cc"
////////////////////////////////////////////////////////////////////////////////
#endif